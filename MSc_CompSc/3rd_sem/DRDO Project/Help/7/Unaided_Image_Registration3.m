%*************************************************************************%
%******************      Author: Vlachos Marios         ******************%
%******************   Designed by: Vlachos Marios       ******************%
%****************** Electrical and Computer Engineer    ******************%
%******************          PhD Student                ******************%
%******************   University of Patras, Greece      ******************%
%******************          8 November 2005            ******************%
%*************** email: mvlachos@george.wcl2.ee.upatras.gr ***************%
%*************************************************************************%

clear all; 
close all;
clc;
% Start time
tic;

% Read base image and find its size
%**************************************************************************
I=imread('c:\\images\\reg_liss3_HP.jpg');
%I=imread('I:\\Program\\Programs\\MSc_CompSc\\3rd sem\\DRDO Project\\Help\\7\\P10001.bmp');
I=I(:,:,1);

[M N]=size(I);
%**************************************************************************

% Read transform image 
%**************************************************************************
I_transform=imread('c:\\images\\unreg_liss3_HP.jpg');
%I_transform=imread('I:\\Program\\Programs\\MSc_CompSc\\3rd sem\\DRDO Project\\Help\\7\\P10200.bmp');
I_transform=I_transform(:,:,1);
%**************************************************************************

% Initial conditions (scale parameters)
%**************************************************************************
initial_scale=[pi/12 1 1];
%**************************************************************************

% Find the scale parameters that minimizes the function rescale and display
% the min value of the function
%**************************************************************************
[scale,Fval]=fminsearch('rescale2',initial_scale,[],I,I_transform);
disp(Fval);
%**************************************************************************

% Scale parameters
%**************************************************************************
u=scale(1);
dx=scale(2);
dy=scale(3);
%**************************************************************************

% Construct T matrix for rotation and translation by multiplying the two 
% above matrixs 
%**************************************************************************
Trotation=[cos(u) sin(u) 0; -sin(u) cos(u) 0; 0 0 1;];
Ttranslation=[1 0 0; 0 1 0; dx dy 1;];
T=Trotation*Ttranslation;
%**************************************************************************

% Align the transform image
%**************************************************************************
Tform=maketform('affine',T);
I_aligned=imtransform(I_transform,Tform,'Xdata',[1 N],'Ydata',[1 M]);
%**************************************************************************

% t1 is the time of all process
t1=toc;

% View images on the same figure
%**************************************************************************
subplot(1,3,1); imshow(I);
title('Original Image');
subplot(1,3,2); imshow(I_transform);
title('Transformed Image');
subplot(1,3,3); imshow(I_aligned);
title('Aligned Image');
%**************************************************************************

% View three different figures
%**************************************************************************
figure, imshow(I); title('Original Image');
figure, imshow(I_transform); title('Transformed Image');
figure, imshow(I_aligned); title('Aligned Image');
%**************************************************************************
