//TGA File Loader
package demos1;

import demos1.GLDisplay;

/**
 * @author Pepijn Van Eeckhoudt
 */
public class Lesson33 {
    public static void main(String[] args) {
        GLDisplay neheGLDisplay = GLDisplay.createGLDisplay(
                "Lesson 33: Loading TGA files");
        Renderer renderer = new Renderer();
        neheGLDisplay.addGLEventListener(renderer);
        neheGLDisplay.start();
    }
}