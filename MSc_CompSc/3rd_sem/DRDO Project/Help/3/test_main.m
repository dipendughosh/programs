clc;clear;close all;
% Input image
%img0=imread('I:\\Program\\Programs\\MSc_CompSc\\3rd sem\\DRDO Project\\papers\\PAPERS\\PICTURES\\reg_liss3_HP.jpg');
img0 = imread('c:\\images\\back.jpg');
a0 = imread('c:\\images\\back.jpg');
%a0 =imread('I:\\Program\\Programs\\MSc_CompSc\\3rd sem\\DRDO Project\\papers\\PAPERS\\PICTURES\\unreg_liss3_HP.jpg');
% Scaling factor
scala  = 0.62;
% Rotation
angolo = 34;
disp('*************************************************');
disp('Original parameters:');
disp('Scaling factor');
disp(scala);
disp('Rotation (degrees)');
disp(angolo);
disp('*************************************************');

a1 = imresize(a0,scala);
a1 = imrotate(a1,angolo);
% Additional translation
%a1 = [zeros(size(a1)) a1];
%a1 = [zeros(size(a1));a1];


[registered,outimage,myscale,myangle,myshift] = register(a0,a1);

disp('Rotation-Scaling-Translation results:');
disp('Scaling factor');
disp(myscale);
disp('Rotation (degrees)');
disp(myangle);
disp('Translation');
disp(myshift);
disp('*************************************************');
figure,imshow(uint8(a0)),title('Target image');pause(0.3);
figure,imshow(uint8(a1)),title('Source image (i.e. the image that has to be registered)');pause(0.3);
figure,imshow(uint8(registered)),title('Registered image');pause(0.3);
disp('');
disp('In order to obtain the complete source code please visit');
disp('http://www.advancedsourcecode.com/imageregistration.asp');
disp('or email me luigi.rosa@tiscali.it');
disp('');

