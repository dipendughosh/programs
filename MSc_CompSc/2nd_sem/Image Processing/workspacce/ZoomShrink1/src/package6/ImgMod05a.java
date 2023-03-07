package package6;

import java.awt.*;
import java.io.*;
import javax.imageio.*;
import java.awt.image.*;

class ImgMod05a{
  BufferedImage rawBufferedImage;
  BufferedImage processedImage;
  static String theImgFile = "ImgMod05Test.jpg";
  MediaTracker tracker;

  //-----------------------------------------------------//

  public static void main(String[] args){
    //Instantiate an object of this class.
    ImgMod05a obj = new ImgMod05a();
  }//end main
  //-------------------------------------------//

  public ImgMod05a(){//constructor
    //Get an image from the specified image file.
    rawBufferedImage = getTheImage();

    //Process the image.
    processedImage = processImg(rawBufferedImage);
    
    //Write the modified image into a JPEG file named
    // junk.jpg.
    writeJpegFile(processedImage);

  }//end ImgMod05a constructor
  //=====================================================//

  public BufferedImage processImg(BufferedImage theImage){

    //Use the LookupOp class from the Java 2D API to
    // invert all of the color values in the pixels.  The
    // alpha value is not modified.

    //Create the data for the lookup table.
    short[] lookupData = new short[256];
    for (int cnt = 0; cnt < 256; cnt++){
      lookupData[cnt] = (short)(255-cnt);
    }//end for loop
    
    //Create the lookup table
    ShortLookupTable lookupTable = 
                        new ShortLookupTable(0,lookupData);

    //Create the filter object.
    BufferedImageOp thresholdOp = 
                            new LookupOp(lookupTable,null);

    //Apply the filter to the incoming image and return
    // a reference to the resulting BufferedImage object.
    return thresholdOp.filter(theImage, null);
  }//end processImg
  //=====================================================//

  //Write the contents of a BufferedImage object to a JPEG
  // file named junk.jpg.
  void writeJpegFile(BufferedImage img){
    try{
      //Get a file output stream.
      FileOutputStream outStream = 
                          new FileOutputStream("junk.jpg");
      //Call the write method of the ImageIO class to write
      // the contents of the BufferedImage object to an
      // output file in JPEG format.
      ImageIO.write(img,"jpeg",outStream);
      outStream.close();
    }catch (Exception e) {
      e.printStackTrace();
    }//end catch
  }//end writeJpegFile
  //-----------------------------------------------------//
  
  //This method reads an image from a specified image file,
  // writes it into a BufferedImage object, and returns a
  // reference to the BufferedImage object.
  //The name of the image file is contained in an instance
  // variable of type String named theImgFile.
  BufferedImage getTheImage(){
    Image rawImage = Toolkit.getDefaultToolkit().
                                      getImage(theImgFile);

    //Use a MediaTracker object to block until the image is
    // loaded or ten seconds has elapsed.  Terminate and
    // display an error message if ten seconds elapse
    // without the image having been loaded.  Note that the
    // constructor for the MediaTracker requires the
    // specification of a Component "on which the images
    // will eventually be drawn" even if there is no
    // intention for the program to actually display the 
    // image.  It is useful to have a media tracker with a
    // timeout even if the image won't be drawn by the
    // program.  Also, the media tracker is needed to delay
    // execution until the image is fully loaded.
    tracker = new MediaTracker(new Frame());
    tracker.addImage(rawImage,1);

    try{
      if(!tracker.waitForID(1,10000)){
        System.out.println("Timeout or Load error.");
        System.exit(1);
      }//end if
    }catch(InterruptedException e){
      e.printStackTrace();
      System.exit(1);
    }//end catch

    //Make certain that the file was successfully loaded.
    if((tracker.statusAll(false)
                             & MediaTracker.ERRORED
                             & MediaTracker.ABORTED) != 0){
      System.out.println("Load errored or aborted");
      System.exit(1);
    }//end if

    //Create an empty BufferedImage object.  Note that the
    // specified image type is critical to the correct
    // operation of the image-processing method. The method
    // may work correctly for other image types, but has
    // been tested only for TYPE_INT_RGB.  The
    // parameters to the getWidth and getHeight methods are
    // references to ImageObserver objects, or references
    // to "an object waiting for the image to be loaded."

    BufferedImage buffImage = new BufferedImage(
                              rawImage.getWidth(null),
                              rawImage.getHeight(null),
                              BufferedImage.TYPE_INT_RGB);

    // Draw Image into BufferedImage
    Graphics g = buffImage.getGraphics();
    g.drawImage(rawImage, 0, 0, null);

    return buffImage;
  }//end getTheImage
  //-----------------------------------------------------//
}//end ImgMod05a.java class
//=======================================================//
