package Viewer;

/**
    *************************************************************************************
    * File: RGBEncoder.java                Date: 21/11/2004           Version: 1.01         *
    *-----------------------------------------------------------------------------------*
    * This program is released under the GNU General Public License 2.00.                 
    * Details of GNU GPL at http://www.opensource.org/licenses/gpl-license.php              
    * You must agree to this license before using, copying or modifying this code.                                  
    *
    * Redistribution and use in source and binary forms, with or without
    * modification, are permitted provided that the following conditions
    * are met:
    *
    * 1. Redistributions of source code must retain the above copyright
    *    notice, this list of conditions and the following disclaimer.
    * 2. The source can be used and modified by individual/organizations, 
    *     ONLY IF the source will not be used 
    *    for commercial purposes or incorporated into commercial applications.
    *
    * --------------------------------- WARRANTY --------------------------------- 
    * THIS SOFTWARE IS PROVIDED BY THE AUTHOR "AS IS" AND ANY EXPRESS OR IMPLIED 
    * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
    * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
    * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
    * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
    * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
    * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
    * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
    * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
    * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
    *
    * --------------------------------- CONTACT --------------------------------- 
    * This project was written in a burning hurry, so it is not a model of efficient
    * nor even good code.
    * Please send comments, bug reports, improvements to: hoptrandinh@yahoo.com  

    * @Author: this source come from http://java.sun.com/
    * @Edited by Tran Dinh Hop, 6 Nov 2004
    * @Please visit http://www.freewebs.com/DigitZone for updated version
*/
import java.awt.image.*;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.File;


public class Bitmap {

	protected static FileInputStream in;
	protected static FileOutputStream out;

	public void Bitmap(){// throws IOException {
	}

	public static BufferedImage decode(String filename)throws IOException {
		File myFile = new File (filename);
		if(!myFile.isFile()) return null;//Make sure that the string is a file.

		try{
		  in = new FileInputStream (myFile);
		}catch(FileNotFoundException ioe){}

		BitmapInfo bm = new BitmapInfo();

		readHeader(bm);
		loadImage(bm);
		int []data = new int[bm.height * bm.width];

		for(int i=0; i<bm.height; i++){
            //copy the image data into a single dim array
			System.arraycopy(getPixelRow(bm), 0, data, i*bm.width, bm.width);
		}

		ColorModel cModel = ColorModel.getRGBdefault();
		DataBufferInt intBuf = new DataBufferInt(data, (bm.width * bm.height));
		SampleModel sModel = cModel.createCompatibleSampleModel(bm.width, bm.height);

		// create our raster
		WritableRaster raster = Raster.createWritableRaster(sModel, intBuf, null);

		// now create and return our buffered image
		try{in.close();
		}catch(IOException ioe){}
		return new BufferedImage(cModel, raster, false, null);

	}

	protected static int readB(){
		try {	int rv = in.read();
			return rv;
		}catch(IOException ioe){ return -1;}
	}
	protected static int read2B(){
		try { int rv = (in.read() + (in.read()<<8));
			return rv;
		}catch(IOException ioe){ return -1;}
	}
	protected static int read4B(){
		try {int rv = (in.read() + (in.read()<<8) + (in.read()<<16) + (in.read()<<24));
			return rv;
		}catch(IOException ioe){ return -1;}
	}
	protected static int[] readBArr(int size){
		try {	byte [] read = new byte[size];
				int  [] rv   = new int[size];
				in.read(read);
				for(int i=0; i< read.length; i++) rv[i] = (int)read[i];
				return rv;
		}catch(IOException ioe){ return new int[] {-1};}
	}
	/**
	 * Read the header of the bitmap.
	 * Store information in the BitmapInfo object bm.
	 */
	protected static void readHeader(BitmapInfo bm){// throws IOException {
		int width=0,height=0,planes=0,bitsPerPixel=1,compression=0;
        int  sizeImage=0,xPelsPerMeter,yPelsPerMeter;
		int clrUsed=0,mapEntrySize=0, rowWidth;
		boolean windows = false;

		int type = read2B();//0->2
		if (type != 0x4d42) // 'BM'
			System.err.println("The image is not a bitmap");
        //else Valid Bitmap
		read4B();//2->6
		read4B();//6->10

		int offsetBit = read4B();//10 -> 14

        //fileHeader, we have now read 14 bytes, which is the size of the fileHeader
        //infoHeader may be 12 bytes (OS/2), 40 bytes (Windows). 64 bytes (OS/2 2.x)
		int headerSize = read4B();//0->4
		if( headerSize < 12 || headerSize > 64)
            System.err.println("Error in bitmap infoHeader");
		switch (headerSize){
			case 12 :	width = read2B();//4->6
					 	height= read2B();//6->8
					 	planes= read2B();//8->10
						bitsPerPixel =  read2B();
						switch(bitsPerPixel){
							case 1:
							case 2:
							case 4:
							case 8:
									mapEntrySize = 3;
									break;
							case 24: break; //RGB image
							default: System.err.println("Error: bad bits_per_pixel");
						}
						if (planes != 1) System.err.println("Error: Bad planes");
						break;
			case 40 :	windows = true;
			case 64 :	width 			= read4B();//4->8
				 		height			= read4B();//8->12
				 		planes			= read2B();//12->14
						bitsPerPixel	= read2B();//14->16
						compression		= read4B();//16->20
						sizeImage		= read4B();//20->24
						xPelsPerMeter	= read4B();//24->28
						yPelsPerMeter	= read4B();//28->32
						clrUsed			= read4B();//32->36
						switch(bitsPerPixel){
							case 1 :
							case 2 :
							case 4 :
							case 8 : mapEntrySize =4;
									 break;
							case 24: mapEntrySize =mapEntrySize; break; //RGB image
							default: System.err.println("Error: Bad number of bits_per_pixel");
						}
						if (planes != 1) System.err.println("Error: Bad planes");
						break;
			default : System.err.println("Error: Bad Bitmap Header");
		}
		int pad = offsetBit  - (headerSize + 14);//Distance to the bitmap data.

		/* Read the colormap, if any */
		if (mapEntrySize > 0) {
			if (clrUsed <= 0)	clrUsed = 1 << bitsPerPixel;   /* assume it's 256 */
			else if (clrUsed > 256)	System.err.println("Error: Bad Colour Map");
			/* and read it from the file */
			readColourMap(bm, (int) clrUsed, mapEntrySize);
			pad -= clrUsed * mapEntrySize;
		}

		/* Skip any remaining pad bytes */
		if (pad < 0){             /* incorrect offsetBits value? */
				System.err.println("Error: Bad Bitmap Header");
		}
		while (--pad >= 0) {
			readB();
		}

		/* Compute row width in file, including padding to 4-byte boundary */
		if (bitsPerPixel == 24)
			rowWidth = (int) (width * 3);
		else if (bitsPerPixel == 8)
			rowWidth = (int) width;
		else
			rowWidth = (int) width + 3 * 8;    /* extra for safety */

		while ((rowWidth & 3) != 0) rowWidth++;
			bm.rowWidth = rowWidth;
		bm.width	= (int) width;
		bm.height	= (int) height;
		bm.bitsPerPixel = bitsPerPixel;
		bm.compression	= compression;
		bm.imageSize	= sizeImage;
		bm.windows		= windows;

		return;
	}

	/*
	 * This method loads the image into whole_image during the first call on
	 * get_pixel_rows.  The get_pixel_rows pointer is then adjusted to call
	 * get_8bit_row or get_24bit_row on subsequent calls.
	 */
	protected static void loadImage(BitmapInfo bm){
		int pixelsPerByte=1, bit_mask=0, bit_shift, bitsPerPixel;
		int num_cols;

		/* Allocate space for inversion array, prepare for preload pass */
		bm.wholeImage = new int [bm.height][bm.rowWidth];
		bm.sourceRow = bm.height;
		bitsPerPixel = bm.bitsPerPixel;   /* local copy for faster access */
		/* get data into whole_image buffer */
		switch(bm.compression) {
		case 0:
				num_cols = bm.rowWidth;
		/* this is for the case where there are multiple pixels stored per byte */
				if (bitsPerPixel < 8) {
					bit_mask = (1 << bitsPerPixel) - 1;
					pixelsPerByte = 8 / bitsPerPixel;
					num_cols = bm.width / pixelsPerByte;

					/* make sure we round up */
					if ((bm.width % pixelsPerByte) != 0)
						num_cols++;
					 while ((num_cols & 3) != 0) num_cols++;
				}
				/* Read the data into a virtual array in input-file row order. */
				int row=0,col=0,c;
				int []data = readBArr(bm.rowWidth*bm.height);
				for(int i = 0; i < bm.height*num_cols; i++) {
					c = data[i];
					/* extract, so that one byte has only one pixel */
					 if (bitsPerPixel < 8) {
						bit_shift = 8 - bitsPerPixel;
						for(int j=0;j<pixelsPerByte;i++) {
							if(col < bm.rowWidth)
								bm.wholeImage[row][col++] = (int) ( (c >> bit_shift) & bit_mask );
							else{
								col=0; row++;
								if(row == bm.height) return;
								bm.wholeImage[row][col++] = (int) ( (c >> bit_shift) & bit_mask );
							}
							bit_shift -= bitsPerPixel;
						}
					 }
					 else
						bm.wholeImage[row][col++] = c;
					if( col == bm.rowWidth ) {
						row++;	col=0;
					}
				}
				break;
		case 1:
		case 2:
			extractRLEData(bm);
			break;
		}
	}

	protected static int[] getPixelRow(BitmapInfo bm){
		switch (bm.bitsPerPixel) {
		case 1:
		case 2:
		case 4:
		case 8:
			return getNBitRow(bm);
		case 24:
			return get24BitRow(bm);
		default:
			System.out.println("Error : Bad Bitmap Depth");
			return new int[0];
		}
	}
	/*
	 * Read one row of pixels.
	 * The image has been read into the whole_image array, but is otherwise
	 * unprocessed.  We must read it out in top-to-bottom row order, and if
	 * it is an 8-bit image, we must expand colormapped pixels to 24bit format.
	 */
	protected static int[] getNBitRow(BitmapInfo bm){
	/* This version is for reading 8-bit colormap indexes */
		int t;
		int []data = new int[bm.width];
		int a, r, g, b;

		/* Fetch next row from virtual array */
		bm.sourceRow--;
		int row = bm.sourceRow;
		/* Expand the colormap indexes to real data */
		for (int col = 0; col < bm.width; col++) {
		/* extract components from byte array and store them *
		/* in the int array which is accessible by caller */
			a = (255);
			t = (int)(bm.wholeImage[row][col] & 0xff);

			r = ((int)(bm.colourMap[0][t]) & 0xff);
			g = ((int)(bm.colourMap[1][t]) & 0xff);
			b = ((int)(bm.colourMap[2][t]) & 0xff);

			/* Required to return data in ARGB format */
			data[col] = (a << 24) + (r << 16) + (g << 8) + b;
		}
		return data;
	}
	/*
	 * This version is for reading 24-bit pixels
	 */
	protected static int[] get24BitRow (BitmapInfo bm){
		int []data = new int[bm.width];
		int a, r, g, b;

	   /* Fetch next row from virtual array */
		bm.sourceRow--;
		int row = bm.sourceRow;
	   /* Transfer data.  Note source values are in BGR order
		* (even though Microsoft's own documents say the opposite).
		*/
		for (int col = 0; col < bm.width; col++) {
			/* extract components from byte array and store them *
			/* in the short array which is accessible by caller */
			a = (int)(255);
		if(bm.windows){
			r = ((int)(bm.wholeImage[row][col*3  ])   & 0xff);
			b = ((int)(bm.wholeImage[row][col*3+1]) & 0xff);
			g = ((int)(bm.wholeImage[row][col*3+2]) & 0xff);
		}else{
			r = ((int)(bm.wholeImage[row][col*3+2]) & 0xff);
			g = ((int)(bm.wholeImage[row][col*3+1]) & 0xff);
			b = ((int)(bm.wholeImage[row][col*3  ]) & 0xff);
		}
			/* Required to return data in ARGB format */
			data[col] = (a << 24) + (r << 16) + (g << 8) + b;
		}
		return data;
	}
        
	protected static void extractRLEData(BitmapInfo bm){// throws IOException {
		int[] out_arr;
		int row=0, col=0;
		int imageSize, i=0, j;
		int xoff, yoff;
		int currByte, byte1, byte2;
		int pixelSize;
		imageSize = bm.imageSize;

		if (bm.compression == 1)	pixelSize = 8;
		else							pixelSize = 4;

		/* load first row */
		out_arr = bm.wholeImage[row];

		/* You already know how many bytes are in the image, so only go through that many. */
		i=0;
		while (i < imageSize) {
			/* RLE encoding is defined by two bytes */
			byte1 = readB();
			byte2 = readB();
			i += 2;

			/* If byte 1 == 0, this is an escape code */
			if (byte1 == 0) {
				/* If escaped, byte 2 == 0 means you are at end of line */
				if (byte2 == 0) {
					col = 0;
					row++;
					out_arr = bm.wholeImage[row];
				 } /* If escaped, byte 2 == 1 means end of bitmap */
				 else if (byte2 == 1) {	return; }
				 /* if escaped, byte 2 == 2 adjusts the current x and y by */
				 /* an offset stored in the next two bytes */
				 else if (byte2 == 2) {
					xoff = (int)readB();
					yoff = (int)readB();
					i += 2;
					col += xoff;
					row += yoff;
					out_arr = bm.wholeImage[row];
				 }
				 /* If escaped, any other value for byte 2 is the number of */
				 /* samples that you should read as pixel values (these pixels */
				 /* are not run-length encoded) */
				 else {
					for (j=0; j < byte2; j++) {
						// Read in the next byte
						currByte = readB();
						i++;
						/* necessary to prevent buffer overrun */
						/* incase image file is corrupt */
						if (col >= bm.width) {	continue;}

						byte data1 = 0, data2 = 0;
						if (pixelSize == 4) {
							out_arr[col++] = (byte) ((currByte >> 4) & 0xf);
							j++;

							if (j < byte2) {
								out_arr[col++] = (byte) (currByte & 0xf);
								col++;
							}
						}
						else {
							out_arr[col++] = (byte) currByte;
						}
					}
					/* The pixels must be word-aligned, so if you read */
					/* an uneven number of bytes, read and ignore a byte */
					/* to get aligned again. */

					/* determine if we need to read another byte */
					if (pixelSize == 4)
					   byte2 >>= 1;

					if ( (byte2 & 1) == 1) {
						readB();
						i++;
					}
				}
			}
			/* If the first byte was not 0, it is the number of samples that */
			/* are encoded by byte 2 */
			else {
				for (j=0; j < byte1; j++) {
					/* necessary to prevent buffer overrun */
					/* incase image file is corrupt */
					if (col >= bm.width) {	continue; }

					if (pixelSize == 4) {
						/* If j is odd, use the upper 4 bits */
						if ((j & 1) == 0)	out_arr[col] = (byte) ((byte2 >> 4) & 0xf);
						else 				out_arr[col] = (byte)  (byte2 & 0xf);
					} else {
						out_arr[col] = (byte) byte2;
					}
					col++;
				}
			}
		}

	}
	/**
	 * Read the colormap from a BMP file
	 *
	 */
	protected static void readColourMap (BitmapInfo bm, int mlen, int mentry)
	{	int i;
		bm.colourMap  = new int[3][mlen];

		switch (mentry) {
			case 3:	 /* BGR format (occurs in OS/2 files) */
				 for (i = 0; i < mlen; i++) {
					bm.colourMap[2][i] = readB();
					bm.colourMap[1][i] = readB();
					bm.colourMap[0][i] = readB();
				 }
				 break;
			case 4:	 /* BGR0 format (occurs in MS Windows files) */
				 readB();readB();readB();readB();//Haven't a clue why these need to be here, but they do.
				 for (i = 0; i < mlen; i++) {
					bm.colourMap[2][i] = readB();
					bm.colourMap[1][i] = readB();
					bm.colourMap[0][i] = readB();
					readB();
				 }
				 break;
					default:System.err.println("Error reading colour map");
				 break;
		}
	}
        
    protected static class BitmapInfo {
    	public int [][]colourMap;	/* BMP colormap (converted to my format) */
    
    	public int [][] wholeImage;	/* Needed to reverse row order */
    	public int sourceRow=0;		/* Current source row number */
    	public int rowWidth=0;		/* Physical width of scanlines in file */
    
    	public int bitsPerPixel=0;	/* remembers 1-, 2-, 4-, 8- or 24-bit format */
    	public int compression=0;		/* remembers 0, 1, 2 compression */
    	public int imageSize=0;		/* bytes of image data in the file */
    	public int height=0;
    	public int width=0;
    	public boolean windows=true;
    	public BitmapInfo() {}
    }
}
