package package5;

public class Test5 {

}
public static void main(String args[]) throws Exception {
    mjpegGrabber gb = new mjpegGrabber("http://192.168.2.5/now.jpg");
    gb.connect();
    BufferedImage im = gb.readJPEG();
    gb.disconnect();

    ImageIO.write(im, "png", new File("E:\\01.png"));
    BufferedImage im2 = null, im3 = null, im4 = null, imm = null;
    long time = System.currentTimeMillis();
    im2 = resize1(im);
    System.out.println("im2: " + (System.currentTimeMillis() - time));
    ImageIO.write(im2, "png", new File("E:\\02.png"));
    time = System.currentTimeMillis();
    im3 = resize2(im);
    System.out.println("im3: " + (System.currentTimeMillis() - time));
    ImageIO.write(im3, "png", new File("E:\\03.png"));
    time = System.currentTimeMillis();
    im4 = resize3(im);
    System.out.println("im4: " + (System.currentTimeMillis() - time));
    ImageIO.write(im4, "png", new File("E:\\04.png"));
}

public static BufferedImage resize1(BufferedImage im) {
    BufferedImage im2 = new BufferedImage(320, 240, BufferedImage.TYPE_INT_RGB);
    Graphics2D destGraphics = im2.createGraphics();
    destGraphics.setRenderingHint(
            RenderingHints.KEY_INTERPOLATION,
            RenderingHints.VALUE_INTERPOLATION_NEAREST_NEIGHBOR);
    destGraphics.drawImage(
            im,
            0, 0, im2.getWidth(), im2.getHeight(),
            0, 0, im.getWidth(), im.getHeight(),
            null);
    return im2;
}

public static BufferedImage resize2(BufferedImage im) {
    BufferedImage im3;
    AffineTransform tx = new AffineTransform();
    tx.scale((double) 320 / im.getWidth(), (double) 240 / im.getHeight());
    AffineTransformOp op = new AffineTransformOp(tx, AffineTransformOp.TYPE_NEAREST_NEIGHBOR);
    im3 = op.filter(im, null);
    return im3;
}

public static BufferedImage resize3(BufferedImage im) {
    Image ima = im.getScaledInstance(320, 240, BufferedImage.SCALE_FAST);
    BufferedImage im4 = new BufferedImage(320, 240, BufferedImage.TYPE_INT_ARGB);
    im4.getGraphics().drawImage(ima, 0, 0, null);
    return im4;
}
