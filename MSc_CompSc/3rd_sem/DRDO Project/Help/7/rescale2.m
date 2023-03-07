%*************************************************************************%
%******************      Author: Vlachos Marios         ******************%
%******************   Designed by: Vlachos Marios       ******************%
%****************** Electrical and Computer Engineer    ******************%
%******************          PhD Student                ******************%
%******************   University of Patras, Greece      ******************%
%******************          8 November 2005            ******************%
%*************** email: mvlachos@george.wcl2.ee.upatras.gr ***************%
%*************************************************************************%

function [err]=rescale2(scale,I,I_transform);

[M N]=size(I);

% Apply transformation with various scale parameters until the correlation 
% between the base and the aligned image is acceptable  
%**************************************************************************
u=scale(1);
dx=scale(2);
dy=scale(3);

Trotation=[cos(u) sin(u) 0; -sin(u) cos(u) 0; 0 0 1;];
Ttranslation=[1 0 0; 0 1 0; dx dy 1;];
T=Trotation*Ttranslation;

Tform=maketform('affine',T);
I_aligned=imtransform(I_transform,Tform,'Xdata',[1 N],'Ydata',[1 M]);
%**************************************************************************

% Find the correlation between the base and the aligned images
%**************************************************************************
err=-abs(corr2(I_aligned,I));
%**************************************************************************

end
