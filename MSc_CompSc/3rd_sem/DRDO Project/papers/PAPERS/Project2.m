% AUTOMATIC FOURIER - BASED IMAGE REGISTRATION

%--------------------------------------------------------------------------

% THE ALGORITHM :-

    % (1)   Read in Source (I1) - the image to register against
    % (2)   Read in Template (I2) - the image to register
    % (3)   Computer the FFT of I1, shifting it to center on zero frequency
    % (4)   Computer the FFT of I2, shifting it to center on zero frequency
    % (5)   Convolve the magnitude of (3) with a high pass filter
    % (6)   Convolve the magnitude of (4) with a high pass filter
    % (7)   Transform (5) into log polar space
    % (8)   Transform (6) into log polar space
    % (9)   Take the FFT of (7)
    % (10)  Take the FFT of (8)
    % (11)  Compute phase correlation of (9) and (10)
    % (12)  Find the location (x,y) in (11) of the peak of the phase correlation
    % (13)  Compute angle and scale from (12)
    % (14)  Apply inverse scale and rotate I2 by - angle from (13)
    % (15)  Apply inverse scale and rotate I2 by - (angle + 180) from (13)
    % (16)  Take the FFT of (14)
    % (17)  Take the FFT of (15)
    % (18)  Compute phase correlation of (3) and (16)
    % (19)  Compute phase correlation of (3) and (17)
    % (20)  Find the location (x,y) in (18) of the peak of the phase correlation
    % (21)  Find the location (x,y) in (19) of the peak of the phase correlation
    % (22)  If phase peak in (20) > phase peak in (21),
    %              (x,y) from (20) is the translation and angle is the rotation
    %       Else (x,y) from (21) is the translation and (angle + 180) is the rotation:
    
%--------------------------------------------------------------------------

% SIGNIFICANT LIBRARY FUNCTIONS USED :-

    % rgb2gray() : TO CONVERT AN RGB IMAGE TO ITS GRAY-SCALE COUNTERPART
    % size()     : TO FIND THE DIMENSIONS
    % imresize() : TO RESIZE AN IMAGE
    % imrotate() : TO ROTATE AN IMAGE
    % fft2()     : TO COMPUTE THE 2D FFT
    % fftshift() : To REARRANGE THE OUTPUT OF fft2() BY SHIFTING THE ZERO FREQUENCY COMPONENT TO THE CENTER OF THE ARRAY 
    % abs()      : TO COMPUTE THE ABSOLUTE VALUE
    % conj()     : TO COMPUTE THE COMPLEX CONJUGATE
    % ifft2()    : INVERSE fft2()
    % ifftshift(): INVERSE fftshift() 
    % fspecial() : TO CREATE A PREDEFINED 2D FILTER
    % filter2()  : TO APPLY 2D DIGITAL FILTER ON A SIGNAL
    % sin()      : TO COMPUTE THE SINE OF AN ANGLE
    % cos()      : TO COMPUTE THE COSINE OF AN ANGLE
    % real()     : TO EXTRACT THE REAL PART OF A NUMBER
    % round()    : TO ROUND OFF VALUE TO THE NEAREST INTEGER
    % imshow()   : DISPLAY IMAGE
    
%--------------------------------------------------------------------------
%--------------------------------------------------------------------------

% THE CODE :-

clc;
clear;
close all;

%--------------------------------------------------------------------------

% READ IMAGES AND GRAYSCALE CONVERSION

Source = imread('Tajmahal.jpg');
Template = imrotate(Source, 10, 'bicubic');
%Template = imread('unreg_liss3_HP.bmp');

if (size(size(Source), 2) == 3)
    Source = rgb2gray(Source);
end

if (size(size(Template), 2) == 3)
    Template = rgb2gray(Template);
end

figure; subplot(1, 2, 1); imshow(Source); title('BASE IMAGE');
        subplot(1, 2, 2); imshow(Template); title('TEMPLATE IMAGE');
        
%--------------------------------------------------------------------------

% HISTOGRAM EQUILIZATION

X = histeq(Source); Source = X;
Y = histeq(Template); Template = Y;

figure; subplot(1, 2, 1); imshow(Source); title('HISTOGRAM EQUALIZED SOURCE IMAGE');
        subplot(1, 2, 2); imshow(Template); title('HISTOGRAM EQUALIZED TEMPLATE IMAGE');

%--------------------------------------------------------------------------

% RESIZE IMAGES - PHASE I - IMAGES TO BE OF THE SAME SIZE

if ((size(Source, 1) > size(Template, 1)) || (size(Source, 2) > size(Template, 2)))
    X = imresize(Template, [size(Source, 1) size(Source, 2)]);
    Template = X;
else
    X = imresize(Source, [size(Template, 1) size(Template, 2)]);
    Source = X;
end

%--------------------------------------------------------------------------

% RESIZE IMAGES - PHASE II - IMAGES TO BE SQUARE

if (size(Source, 1) > size(Source, 2))
    X = imresize(Source, [size(Source, 1) size(Source, 1)]);
    Y = imresize(Template, [size(Template, 1) size(Template, 1)]); 
    Source = X;
    Template = Y;
else
    if (size(Source, 2) > size(Source, 1))
        X = imresize(Source, [size(Source, 2) size(Source, 2)]);
        Y = imresize(Template, [size(Template, 2) size(Template, 2)]);
        Source = X;
        Template = Y;
    end
end

figure; subplot(1, 2, 1); imshow(Source); title('RESIZED SOURCE IMAGE');
        subplot(1, 2, 2); imshow(Template); title('RESIZED TEMPLATE IMAGE');
        
%--------------------------------------------------------------------------

% WINDOWING

Wlp = kaiser(size(Source, 1));          % Some 1D window
Wlq = kaiser(size(Source, 2));
W = Wlp(:) * Wlq(:).';

Source_Windowed = W .* double(Source);
Template_Windowed = W .* double(Template);

%--------------------------------------------------------------------------

% EDGE DETECTION

Source_Edge = edge(Source_Windowed, 'canny');
Template_Edge = edge(Template_Windowed, 'canny');

figure; subplot(1, 2, 1); imshow(Source_Edge); title('EDGES OF SOURCE IMAGE');
        subplot(1, 2, 2); imshow(Template_Edge); title('EDGES OF TEMPLATE IMAGE');

%--------------------------------------------------------------------------

% COMPUTATION OF THE FOURIER TRANSFORMS AND THE CORRESPONDING ABSOLUTE
% VALUES OF THE IMAGES

Source_Fft = fftshift(fft2(Source_Edge));
Template_Fft = fftshift(fft2(Template_Edge));

Source_Abs = abs(Source_Fft);
Template_Abs = abs(Template_Fft);

%--------------------------------------------------------------------------

% IMAGE FILTERING - HIGH PASS FILTERING

Filter = fspecial('log');           % HIGH PASS LAPLACIAN OF GAUSSIAN FILTER

Source_Filter = filter2(Filter, Source_Abs);
Template_Filter = filter2(Filter, Template_Abs);

% Res_Ht = 1 / (size(Source_Fft, 1) - 1);
% Res_Wd = 1 / (size(Source_Fft, 2) - 1);
% 
% Eta = cos(pi * (-0.5:Res_Ht:0.5));
% Neta = cos(pi * (-0.5:Res_Wd:0.5));
% X = Eta' * Neta;
% 
% H = (1.0-X) .* (2.0-X); 
% 
% Source_Filter = H .* Source_Abs;
% Template_Filter = H .* Template_Abs;
% 
% figure; subplot(1, 2, 1); imshow(Source_Filter);
%         subplot(1, 2, 2); imshow(Template_Filter);
        
%--------------------------------------------------------------------------

% RECTANGULAR TO LOG - POLAR COORDINATE CONVERSION

Dim = size(Source_Filter, 1);

Dtheta = (2.0 * pi / Dim);   % STEPS OF THE ANGLE
Base = exp(log(Dim) / Dim);     % LOG - POLAR CONVERSION BASE

for i = 1:Dim
    for j = 1:Dim
        R = Base ^ i - 1;
        Theta = j * Dtheta;
        x = round(R * cos(Theta) + Dim / 2.0);
        y = round(R * sin(Theta) + Dim / 2.0); 
        if (x > 0) && (y > 0) && (x <= Dim) && (y <= Dim)
           Source_Polar(i, j) = Source_Filter(x, y);
           Template_Polar(i, j) = Template_Filter(x, y);
        end
    end
end

figure; subplot(1, 2, 1); imshow(Source_Polar); title('LOG - POLAR BASE IMAGE');
        subplot(1, 2, 2); imshow(Template_Polar); title('LOG - POLAR TEMPLATE IMAGE'); 
        
%--------------------------------------------------------------------------

% EVALUATION OF THE FOURIER TRANSFORMS OF THE LOG - POLAR IMAGES

Source_Polar_Fft = fft2(Source_Polar);
Template_Polar_Fft = fft2(Template_Polar);

figure; subplot(1, 2, 1); imshow(Source_Polar_Fft); title('FFT OF LOG - POLAR BASE IMAGE');
        subplot(1, 2, 2); imshow(Template_Polar_Fft); title('FFT OF LOG - POLAR TEMPLATE IMAGE');
        
%--------------------------------------------------------------------------

% EVALUATION OF THE CROSS - POWER SPECTRUM OF THE SOURCE AND THE TEMPLATE
% IMAGES [NORMALIZED CORRELATION]

R1 = ((Source_Polar_Fft .* conj(Template_Polar_Fft)) / (abs(Source_Polar_Fft .* conj(Template_Polar_Fft))));
Theta_Phase = real(ifft2(R1));

Peaks = max(Theta_Phase);
figure;
plot(Peaks);

%--------------------------------------------------------------------------

% LOCATING THE VALUE OF THE PEAK AND THE SCALE AND ROTATION PARAMETERS

[Peak, Theta_Y] = max(max(Theta_Phase));

for i=1:Dim
    if Theta_Phase(i, Theta_Y) == Peak
        Theta_X = i;
        break;
    end
end

 Scale = Base ^ Theta_X;
 Theta = (180 * ((Theta_Y - 1) / size(Theta_Phase, 2)) / pi);
 
 %Theta = Theta - 30;
 
 %-------------------------------------------------------------------------
 
 % INVERSE SCALING AND ROTATION OF THE TEMPLATE IMAGE
 
 if(1/Scale < 0.05)
    Scale = 1.0;
 else
     Scale = 1/Scale;
 end
 
 Template_Scale = imresize(Template, Scale, 'bicubic');
 
 Template_Rotate = imrotate(Template_Scale, -Theta, 'bicubic');
  
 Template_Rotate1 = imrotate(Template_Scale, -(Theta+180), 'bicubic');
  
 %-------------------------------------------------------------------------
 
 % RESIZE SOURCE AND TEMPLATE_ROTATE IMAGES - PHASE I - IMAGES TO BE OF THE SAME SIZE

if ((size(Source, 1) > size(Template_Rotate, 1)) || (size(Source, 2) > size(Template_Rotate, 2)))
    X = imresize(Template_Rotate, [size(Source, 1) size(Source, 2)]);
    Template_Rotate = X;
else
    X = imresize(Source, [size(Template_Rotate, 1) size(Template_Rotate, 2)]);
    Source = X;
end

if ((size(Source, 1) > size(Template_Rotate1, 1)) || (size(Source, 2) > size(Template_Rotate1, 2)))
    X = imresize(Template_Rotate1, [size(Source, 1) size(Source, 2)]);
    Template_Rotate1 = X;
else
    X = imresize(Source, [size(Template_Rotate1, 1) size(Template_Rotate1, 2)]);
    Source = X;
end

%--------------------------------------------------------------------------

% RESIZE SOURCE AND TEMPLATE_ROTATE IMAGES - PHASE II - IMAGES TO BE SQUARE

if (size(Source, 1) > size(Source, 2))
    X = imresize(Source, [size(Source, 1) size(Source, 1)]);
    Y = imresize(Template_Rotate, [size(Template_Rotate, 1) size(Template_Rotate, 1)]); 
    Z = imresize(Template_Rotate1, [size(Template_Rotate1, 1) size(Template_Rotate1, 1)]);
    Source = X;
    Template_Rotate = Y;
    Template_Rotate1 = Z;
else
    if (size(Source, 2) > size(Source, 1))
        X = imresize(Source, [size(Source, 2) size(Source, 2)]);
        Y = imresize(Template_Rotate, [size(Template_Rotate, 2) size(Template_Rotate, 2)]);
        Z = imresize(Template_Rotate1, [size(Template_Rotate1, 2) size(Template_Rotate1, 2)]);
        Source = X;
        Template_Rotate = Y;
        Template_Rotate1 = Z;
    end
end

figure; subplot(1, 3, 1); imshow(Source); title('BASE IMAGE');
        subplot(1, 3, 2); imshow(Template_Rotate); title('SCALED AND ROTATED (-THETA) TEMPLATE IMAGE');
        subplot(1, 3, 3); imshow(Template_Rotate1); title('SCALED AND ROTATED(-(THETA+180)) TEMPLATE IMAGE');
        
%--------------------------------------------------------------------------

% FOURIER TRANSFORMS ON SOURCE AND TEMPLATE_ROTATE IMAGE

Source_Fft = fftshift(fft2(filter2(Filter, Source)));
Template_Rotate_Fft = fftshift(fft2(filter2(Filter, Template_Rotate)));
Template_Rotate1_Fft = fftshift(fft2(filter2(Filter, Template_Rotate1)));

%--------------------------------------------------------------------------

% CROSS POWER SPECTRUM EVALUATION BETWEEN SOURCE AND TEMPLATE_ROTATE
% IMAGES

R2 = ((Source_Fft .* conj(Template_Rotate_Fft)) ./ (abs(Source_Fft .* conj(Template_Rotate_Fft))));
R2_Inv = real(ifftshift(ifft2(R2)));

R21 = ((Source_Fft .* conj(Template_Rotate1_Fft)) ./ (abs(Source_Fft .* conj(Template_Rotate1_Fft))));
R21_Inv = real(ifftshift(ifft2(R21)));

%--------------------------------------------------------------------------

% SHIFT PARAMETER EVALUATION AND ANGLE AMBIGUITY RESOLUTION

[Peak1, Theta_Y1] = max(max(abs(R2_Inv))); 

for i=1:size(R2_Inv, 1)                  
    if abs(R2_Inv(i, Theta_Y1)) == Peak1
        Theta_X1 = i;
        break
    end
end


[Peak2, Theta_Y2] = max(max(abs(R21_Inv))); 

for i=1:size(R21_Inv, 1)                  
    if abs(R21_Inv(i, Theta_Y2)) == Peak2
        Theta_X2 = i;
        break
    end
end


if Peak1 > Peak2
    display(Peak1);
    Shift_X = Theta_Y1;
    Shift_Y = Theta_X1;
else
    display(Peak2);
    Shift_X = Theta_Y2;
    Shift_Y = Theta_X2;
    Template_Rotate = Template_Rotate1;
    
    if Theta > 180
        Theta = Theta - 180;
    else
        Theta = Theta + 180;
    end
end

%--------------------------------------------------------------------------

% TRANSLATION OF TEMPLATE_ROTATE

Tx = Theta_X - 1;   
Ty = Theta_Y - 1;   
    
if (Theta_X > (size(Source, 1) / 2))
    Tx = Tx - size(Source, 1);
    
    if(Tx < 0)
        Tx = 0;
    end
end
    
if (Theta_Y > (size(Source, 2) / 2))
    Ty = Ty - size(Source, 2);
end

T = [1 0 0; 0 1 0; Tx Ty 1];
Tform = maketform('affine', T);

[Image, Xdata, Ydata] = imtransform(Template_Rotate, Tform);

figure;
subplot(1,2,1);
imshow(Source);
axis on;
axis([0 5000 0 5000]);
title('BASE IMAGE');

subplot(1,2,2);
imshow(Image,'XData',Xdata,'YData',Ydata);
axis on;
axis([0 5000 0 5000]);
title('REGISTERED IMAGE');

%--------------------------------------------------------------------------
 