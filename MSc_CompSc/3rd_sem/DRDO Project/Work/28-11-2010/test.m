orthophoto = imread('c:\image\base.jpg');
iptsetpref('ImshowAxesVisible','on')
figure, imshow(orthophoto)
unregistered = imread('c:\image\input.jpg');
figure, imshow(unregistered)
[xyinput_out, xybase_out]=cpselect(unregistered, orthophoto,'Wait', true);
mytform = cp2tform(xyinput_out, xybase_out, 'projective');
[registered2 xdata ydata] = imtransform(unregistered, mytform,'FillValues', 255);
figure; imshow(orthophoto,gray(256))
hold on
h = imshow(registered2, 'XData', xdata, 'YData', ydata);
set(h, 'AlphaData', 0.6)
ylim = get(gca, 'YLim');
set(gca, 'YLim', [0.5 ylim(2)])