import java.awt.*;

/**
 * Component to show the original histogram and resulting histogram.
 */
class HistogramComponent extends javax.swing.JComponent {
    private double[] oldHistogram; // Histogram of image before histogram-equalization
    private double[] newHistogram; // Histogram of image after histogram-equalization

    public HistogramComponent() {
        setPreferredSize(new Dimension(590, 150));
        revalidate();
    }

    public void setHistograms(double[] newHistogram, double[] oldHistogram) {
        this.oldHistogram = oldHistogram;
        this.newHistogram = newHistogram;
    }

    /**
     * Paint the histogram-equalized image and two histograms
     */
    public void paint(Graphics g) {
        drawHistogram(g, "Old Histogram", 15, 5, 125, 1, oldHistogram);
        drawHistogram(g, "New Histogram", 320, 5, 125, 1, newHistogram);
    }

    /**
    * Draw the histogram picture of input histogram
    *
    *@param g  graphics object of current frame
    *       x  the x coordinate of histogram image to be showed
    *       y  the x coordinate of histogram image to be showed
    *       height the height of the histogram image
    *       space  the space between two lines in the histogram.
    */
    public void drawHistogram(Graphics g, String title, int x, int y,
                              int height, int space, double[] inputHistogram) {
        double max = 0;
        if (inputHistogram != null) {
            for (int j = 0; j < 256; j++) {
                if (inputHistogram[j] > max)
                    max = inputHistogram[j];
            }
        }

        // set up font
        g.setFont(new Font("Arial", Font.PLAIN, 11));
        FontMetrics	fm = g.getFontMetrics();
        int	ascent = fm.getAscent();
        int	lineHeight = fm.getHeight();

        // draw title
        int titleWidth = fm.stringWidth(title);
        g.setColor(Color.black);
        g.drawString(title, x + (256*space - titleWidth)/2, y + ascent);
        y += lineHeight;
        height -= lineHeight;

        // draw background
        Rectangle	histRect = new Rectangle(x, y, 256*space, height);
        g.setColor(Color.white);
        g.fillRect(histRect.x, histRect.y, histRect.width, histRect.height);

        // draw bars
        g.setColor(Color.darkGray);
        if (inputHistogram != null) {
            for (int i = 0; i < 256; i++)
                g.drawLine(x + ((i + 1) * space), y + height,
                           x + ((i + 1) * space),
                           y +
                           height - (int) (height * inputHistogram[i] / max));
        }

        // draw vertical label
        String	vLabel = "" + ((double) (int) (max * 1000) / 10) + "%";
        g.setColor(Color.red);
        g.drawString(vLabel, x + 2, y + ascent);

        // draw horizontal labels
        g.setColor(Color.black);
        g.drawString("256", (x + (space * 256)) - 8, y + height + ascent + 2);
        g.drawString("128", (x + (space * 128)) - 8, y + height + ascent + 2);
        g.drawString("  0", (x + (space *   0)) - 8, y + height + ascent + 2);
    }
}
