%Read in Base and Unregistered Images
base=imread('I:\\Program\\Programs\\MSc_CompSc\\3rd sem\\DRDO Project\\papers\\PAPERS\\PICTURES\\reg_liss3_HP.jpg');
%base = imread('c:\\images\\back.jpg');
%unregistered = imread('c:\\images\\back.jpg');
unregistered =imread('I:\\Program\\Programs\\MSc_CompSc\\3rd sem\\DRDO Project\\papers\\PAPERS\\PICTURES\\unreg_liss3_HP.jpg');

%Display the Unregistered Image
iptsetpref('ImshowAxesVisible','on')
imshow(unregistered)
text(size(unregistered,2),size(unregistered,1)+30,'Image courtesy of mPower3/Emerge','FontSize',7,'HorizontalAlignment','right');

%Create a TFORM Structure
load westconcordpoints
tform = cp2tform(input_points, base_points, 'projective');

%Transform the Unregistered Image
registered = imtransform(unregistered, tform,'FillValues', 255);

%Display the registered image.
figure; imshow(registered);
hold on

%Overlay Base Image Over Registered Image
h = imshow(base, gray(256));
set(h, 'AlphaData', 0.6)

%Using XData and YData Input Parameters
registered1 = imtransform(unregistered,tform,'FillValues', 255,'XData', [1 size(base,2)],'YData', [1 size(base,1)]);
figure; imshow(registered1)
hold on
h = imshow(base, gray(256));
set(h, 'AlphaData', 0.6)

%Using xdata and ydata Output Values
[registered2 xdata ydata] = imtransform(unregistered, tform,'FillValues', 255);
figure; imshow(registered2, 'XData', xdata, 'YData', ydata)
hold on
h = imshow(base, gray(256));
set(h, 'AlphaData', 0.6)
ylim = get(gca, 'YLim');
set(gca, 'YLim', [0.5 ylim(2)])

