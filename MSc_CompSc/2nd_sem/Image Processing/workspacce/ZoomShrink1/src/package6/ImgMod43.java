package package6;

import java.awt.image.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.awt.color.ColorSpace;

class ImgMod43 extends Frame implements ImgIntfc05{
  //Primary container used to construct the GUI.
  JTabbedPane tabbedPane = new JTabbedPane();
  
  //Components used to construct the ColorConvertOp page
  // in the JTabbedPane.
  // Components that require local access only are defined
  // locally.  Others are defined here as instance
  // variables.
  Panel colorConvertPage = new Panel();
  CheckboxGroup buttonGroup = new CheckboxGroup();
  Checkbox CS_CIEXYZ = 
              new Checkbox("CS_CIEXYZ",buttonGroup,false);
  Checkbox CS_GRAY = 
                 new Checkbox("CS_GRAY",buttonGroup,true);
  Checkbox CS_LINEAR_RGB = 
          new Checkbox("CS_LINEAR_RGB",buttonGroup,false);

  //Components used to construct the RescaleOp page in
  // the JTabbedPane. Components that require local access
  // only are defined locally.  Others are defined here as
  // instance variables.
  Panel colorRescalePage = new Panel();
  TextField redScaleField = new TextField("1.0");
  TextField redOffsetField = new TextField("0.0");
  TextField greenScaleField = new TextField("1.0");
  TextField greenOffsetField = new TextField("0.0");
  TextField blueScaleField = new TextField("1.0");
  TextField blueOffsetField = new TextField("0.0");
  
  //The following Label is used to notify of data entry
  // errors.
  String okMessage = "No data entry errors detected.";
  Label errorMsg = new Label(okMessage);
  //-----------------------------------------------------//
  
  //This is the primary constructor.  It calls other
  // methods to separate the construction of the GUI into
  // easily understandable units.  Each method that it
  // calls constructs one page in the tabbed pane.
  ImgMod43(){//constructor
  
    //Construct the pages and add them to the tabbed pane.
    constructColorConvertPage();
    tabbedPane.add(colorConvertPage);
    
    constructColorRescalePage();
    tabbedPane.add(colorRescalePage);
  
    add(tabbedPane);//Add tabbedPane to the Frame.

    setTitle("Copyright 2007, R.G.Baldwin");
    setBounds(555,0,470,300);
    setVisible(true);

    //Define a WindowListener to terminate the program.
    addWindowListener(
      new WindowAdapter(){
        public void windowClosing(WindowEvent e){
          System.exit(1);
        }//end windowClosing
      }//end windowAdapter
    );//end addWindowListener
  }//end constructor
  //-----------------------------------------------------//
  
  //This method constructs the page in the tabbed pane
  // that shows ColorConvertOp on the tab.  This method is
  // called from the primary constructor.
  void constructColorConvertPage(){
    colorConvertPage.setName("ColorConvertOp");//Tab label
    colorConvertPage.setLayout(new BorderLayout());
    
    //Create and add the instructional text to the page.
    // This text appears in a disabled text area at the
    // top of the page in the tabbed pane.
    String text ="COLOR TYPE CONVERSION\n"
      + "This page illustrates the use of the "
      + "ColorConvertOp filter class.\n\n"
      + "Select the appropriate radio button below, and "
      + "click the Replot button to cause the program to "
      + "convert the ColorSpace to the type indicated by "
      + "the radio button.\n\n"
      + "Note that changing the type of the ColorSpace "
      + "causes the later attempt to write the processed "
      + "image into an output jpg file in ImgMod05 to "
      + "fail.  In two cases, that code throws an "
      + "exception.  In the third case, the output file "
      + "doesn't contain a valid copy of the processed "
      + "image.";
      
    //Note:  The number of columns specified for the
    // following TextArea is immaterial because the
    // TextArea object is placed in the NORTH location of
    // a BorderLayout.
    TextArea textArea = new TextArea(text,10,1,
                                TextArea.SCROLLBARS_NONE);
    colorConvertPage.add(textArea,BorderLayout.NORTH);
    textArea.setEnabled(false);

    //Construct the control panel and add it to the page.
    Panel controlPanel = new Panel();
    controlPanel.add(CS_CIEXYZ);
    controlPanel.add(CS_GRAY);
    controlPanel.add(CS_LINEAR_RGB);
    colorConvertPage.add(
                        controlPanel,BorderLayout.CENTER);
  }//end constructColorConvertPage
  //-----------------------------------------------------//

  //This method processes the image according to the
  // controls located on the page in the tabbed pane that
  // shows ColorConvertOp on the tab.
  //This method uses the ColorConvertOp filter class to
  // process the image and to convert it to the
  // ColorSpace type indicated by a radio button selected
  // by the user.  This method illustrates only three of
  // the many ColorSpace types defined in the ColorSpace
  // class.
  //This method is called from within the switch statement
  // in the method named processImg, which is the primary
  // image processing method in this program.
  BufferedImage processColorConvertPage(
                                  BufferedImage theImage){
    //Examine the radio buttons.  Cause the ColorSpace of
    // the image to be converted to the type indicated
    // by the radio button.
    int colorSpaceType;
    if(CS_CIEXYZ.getState() == true){
      colorSpaceType = ColorSpace.CS_CIEXYZ;
    }else if(CS_GRAY.getState() == true){
      colorSpaceType = ColorSpace.CS_GRAY;
    }else{//CS_LINEAR_RGB must be selected
      colorSpaceType = ColorSpace.CS_LINEAR_RGB;
    }//end else

    //Create the filter object.
    ColorConvertOp filterObj = new ColorConvertOp(
             ColorSpace.getInstance(colorSpaceType),null);
    
    //Apply the filter and return the result.
    return filterObj.filter(theImage,null);

  }//end processColorConvertPage
  //-----------------------------------------------------//
  
  //This method constructs the page in the tabbed pane
  // that shows RescaleOp on the tab.  This method is
  // called from the primary constructor.
  void constructColorRescalePage(){
    colorRescalePage.setName("RescaleOp");//Tab label.
    colorRescalePage.setLayout(new BorderLayout());
    
    //Create and add the instructional text to the page.
    String text = "COLOR RESCALING\n"
      + "This page illustrates the use of the RescaleOp "
      + "filter\n\n"
      + "Enter new scale and offset values for each "
      + "color in the text fields below and then click "
      + "the Replot button.\n\n"
      + "This will cause the color values for each color "
      + "to be multiplied by the scale factor specified "
      + "for that color.  Then the offset value for that "
      + "color will be added to the scaled color values.";
      
    //Note:  The number of columns specified for the
    // following TextArea is immaterial because the
    // TextArea object is placed in the NORTH location of
    // a BorderLayout.
    TextArea textArea = new TextArea(text,9,1,
                                TextArea.SCROLLBARS_NONE);
    colorRescalePage.add(textArea,BorderLayout.NORTH);
    textArea.setEnabled(false);
    
    //Construct the control panel and add it to the page.
    Panel controlPanel = new Panel();
    controlPanel.setLayout(new GridLayout(3,5));
    controlPanel.add(new Label("Red"));
    controlPanel.add(new Label("Scale = "));
    controlPanel.add(redScaleField);
    controlPanel.add(new Label("Offset = "));
    controlPanel.add(redOffsetField);
    
    controlPanel.add(new Label("Green"));
    controlPanel.add(new Label("Scale = "));
    controlPanel.add(greenScaleField);
    controlPanel.add(new Label("Offset = "));
    controlPanel.add(greenOffsetField);
    
    controlPanel.add(new Label("Blue"));
    controlPanel.add(new Label("Scale = "));
    controlPanel.add(blueScaleField);
    controlPanel.add(new Label("Offset = "));
    controlPanel.add(blueOffsetField);
    
    colorRescalePage.add(
                        controlPanel,BorderLayout.CENTER);
    
    //Add the errorMsg label.
    colorRescalePage.add(errorMsg,BorderLayout.SOUTH);
    errorMsg.setBackground(Color.GREEN);
    
  }//end constructColorRescalePage
  //-----------------------------------------------------//

  //This method processes the image according to the
  // controls located on the page in the tabbed pane that
  // shows RescaleOp on the tab.  This method is called
  // from within the switch statement in the method named
  // processImg.  This method uses the scale and offset
  // values specified by the user to modify the red,
  // green, and blue color values.  The new color value
  // for each pixel is the old value multiplied by the
  // scale factor for that color plus the offset value for
  // that color.
  BufferedImage processColorRescalePage(
                                  BufferedImage theImage){
    
    //Reset the error message to the default.
    errorMsg.setText(okMessage);
    errorMsg.setBackground(Color.GREEN);

    //Create the arrays required to contain the scale and
    // offset values.
    float[] scale = new float[3];
    float[] offset = new float[3];
    
    //Populate the scale and offset arrays using data from
    // the text fields.
    try{//Get input value from the text field.
      scale[0] = 
                Float.parseFloat(redScaleField.getText());
      offset[0] = 
               Float.parseFloat(redOffsetField.getText());
      scale[1] = 
              Float.parseFloat(greenScaleField.getText());
      offset[1] = 
             Float.parseFloat(greenOffsetField.getText());
      scale[2] = 
               Float.parseFloat(blueScaleField.getText());
      offset[2] = 
              Float.parseFloat(blueOffsetField.getText());
    }catch(java.lang.NumberFormatException e){
      //Set the error message.
      errorMsg.setText("Bad input data.");
      errorMsg.setBackground(Color.RED);
      
      //Make the output image black.
      scale[0] = 0;
      offset[0] = 0;
      scale[1] = 0;
      offset[1] = 0;
      scale[2] = 0;
      offset[2] = 0;
    }//end catch
    
    //Create the filter object.
    RescaleOp filterObj = 
                         new RescaleOp(scale,offset,null);
    
    //Apply the filter and return the result.
    return filterObj.filter(theImage,null);

  }//end processColorRescalePage
  //-----------------------------------------------------//

  //The following method must be defined to implement the
  // ImgIntfc05 interface.  It is called by the driver
  // program named ImgMod05.
  public BufferedImage processImg(BufferedImage theImage){
    
    BufferedImage outputImage = null;
    
    //Process the page in the tabbed pane that has been
    // selected by the user.
    switch(tabbedPane.getSelectedIndex()){
      case 0:outputImage = 
                        processColorConvertPage(theImage);
             break;
      case 1:outputImage = 
                        processColorRescalePage(theImage);
             break;
    }//end switch

    return outputImage;
  }//end processImg

}//end class ImgMod43
