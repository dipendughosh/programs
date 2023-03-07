%----------- READ THE IMAGE AND DISPLAY IT ------------%
img = imread('coins.png');
h_im = imshow(img);

%-------FIND REGION OF INTEREST(ROI): CREATE MASK & APPLY FILTER ------%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%---------- ROI OF POINT SHAPE -----------%
e1 = impoint(gca,100,100);
BW1 = createMask(e1,h_im);
figure, imshow(BW1);
H = fspecial('unsharp');
J1 = roifilt2(H,img,BW1);
figure, imshow(J1);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%---------- ROI OF LINE SHAPE -----------%
e2 = imline(gca,[100 150;170 150]);
BW2 = createMask(e2,h_im);
figure, imshow(BW2);
H = fspecial('unsharp');
J2 = roifilt2(H,img,BW2);
figure, imshow(J2);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%---------- ROI OF RECTANGLE SHAPE -----------%
e3 = imrect(gca,[10 10 100 100]);
BW3 = createMask(e3,h_im);
figure, imshow(BW3);
H = fspecial('unsharp');
J3 = roifilt2(H,img,BW3);
figure, imshow(J3);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%---------- ROI OF POLYGON SHAPE -----------%
c = [222 272 300 270 221 194];
r = [21 21 75 121 121 75];
e4 = impoly(gca,[67 47;67 97;121 125;167 95;167 46;121 19]);
BW4 = createMask(e4,h_im);
figure, imshow(BW4);
H = fspecial('unsharp');
J4 = roifilt2(H,img,BW4);
figure, imshow(J4);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%---------- ROI OF ELLIPSE SHAPE -----------%
e5 = imellipse(gca,[38 30 150 100]);
BW5 = createMask(e5,h_im);
figure, imshow(BW5);
H = fspecial('unsharp');
J5 = roifilt2(H,img,BW5);
figure, imshow(J5);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%---------- ROI OF FREEHAND SHAPE -----------%
e6 = imfreehand(gca);
% ---- wait on interactive freehand selection window-----%
pos=wait(e6);
%------double click to resume opertion after selection---%
BW6 = createMask(e6,h_im);
figure, imshow(BW6);
H = fspecial('unsharp');
J6 = roifilt2(H,img,BW6);
figure, imshow(J6);

