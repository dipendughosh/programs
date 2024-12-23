/*
 * SoundTester.java
 *
 * Created on 31 August 2006, 14:47
 */

package demos.sound;

import java.util.*;
import java.net.*;
import game.assets.SoundAssetAssembly;

/**
 *
 * @author  phanna
 */
public class SoundTester extends javax.swing.JFrame implements Runnable {
    
    SoundAssetAssembly assembly;
    int assemblySize;
    int numStarts;
    int startPeriodms;
    boolean randomiseStarts;        
        
    /** Creates new form SoundTester */
    public SoundTester() {
        initComponents();
    }
    
    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    // <editor-fold defaultstate="collapsed" desc=" Generated Code ">//GEN-BEGIN:initComponents
    private void initComponents() {
        jScrollPane1 = new javax.swing.JScrollPane();
        outputTextPane = new javax.swing.JTextArea();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        clipAssemblySizeSpinner = new javax.swing.JSpinner();
        numClipStartsSpinner = new javax.swing.JSpinner();
        periodBetweenStartsSpinner = new javax.swing.JSpinner();
        randomiseStartPeriodCheckbox = new javax.swing.JCheckBox();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        outputTextPane.setColumns(20);
        outputTextPane.setEditable(false);
        outputTextPane.setFont(new java.awt.Font("Courier", 0, 16));
        outputTextPane.setRows(5);
        jScrollPane1.setViewportView(outputTextPane);

        jLabel1.setText("Clip Assembly Size");

        jLabel2.setText("Number of clip starts");

        jLabel3.setText("Period between clip starts (ms)");

        randomiseStartPeriodCheckbox.setText("Randomise clip start period");
        randomiseStartPeriodCheckbox.setBorder(javax.swing.BorderFactory.createEmptyBorder(0, 0, 0, 0));
        randomiseStartPeriodCheckbox.setMargin(new java.awt.Insets(0, 0, 0, 0));

        jButton1.setText("Start");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jButton2.setText("Exit");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        org.jdesktop.layout.GroupLayout layout = new org.jdesktop.layout.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(org.jdesktop.layout.GroupLayout.TRAILING, layout.createSequentialGroup()
                .addContainerGap()
                .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.TRAILING)
                    .add(org.jdesktop.layout.GroupLayout.LEADING, jScrollPane1, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 396, Short.MAX_VALUE)
                    .add(layout.createSequentialGroup()
                        .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
                            .add(jLabel1)
                            .add(jLabel2)
                            .add(jLabel3))
                        .add(26, 26, 26)
                        .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.TRAILING, false)
                            .add(org.jdesktop.layout.GroupLayout.LEADING, periodBetweenStartsSpinner)
                            .add(org.jdesktop.layout.GroupLayout.LEADING, numClipStartsSpinner)
                            .add(org.jdesktop.layout.GroupLayout.LEADING, clipAssemblySizeSpinner, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 69, Short.MAX_VALUE))
                        .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED)
                        .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.TRAILING)
                            .add(org.jdesktop.layout.GroupLayout.LEADING, randomiseStartPeriodCheckbox)
                            .add(jButton1, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 147, Short.MAX_VALUE)
                            .add(jButton2, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 147, Short.MAX_VALUE))))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(layout.createSequentialGroup()
                .addContainerGap()
                .add(jScrollPane1, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, 404, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED)
                .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
                    .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.BASELINE)
                        .add(jLabel1)
                        .add(clipAssemblySizeSpinner, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE))
                    .add(randomiseStartPeriodCheckbox))
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED)
                .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.BASELINE)
                    .add(jLabel2)
                    .add(numClipStartsSpinner, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
                    .add(jButton1))
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED)
                .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.BASELINE)
                    .add(jLabel3)
                    .add(periodBetweenStartsSpinner, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
                    .add(jButton2))
                .addContainerGap(org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
        System.exit(0);
    }//GEN-LAST:event_jButton2ActionPerformed

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
    
        assemblySize = (Integer)this.clipAssemblySizeSpinner.getValue();
        numStarts  = (Integer)this.numClipStartsSpinner.getValue();
        startPeriodms = (Integer)this.periodBetweenStartsSpinner.getValue();
        randomiseStarts = this.randomiseStartPeriodCheckbox.isSelected();        
        
        URL soundURL = getClass().getResource( "sounds/laser.wav" );
        assembly = new SoundAssetAssembly( "TestAssembly", soundURL, assemblySize );
        
        Thread newProcess = new Thread( this );
        newProcess.start();
    }//GEN-LAST:event_jButton1ActionPerformed
    
    public void run()
    {
        this.outputTextPane.setText( "" );
        
        for( int idx = 0; idx < numStarts; idx++ )
        {
            try
            {
                int clipIdx = assembly.play();            
                if( clipIdx != -1 )
                    this.outputTextPane.append( "\nStarted clip " + clipIdx );
                else
                    this.outputTextPane.append( "\nClip start ignored."  );                    
                
                if( randomiseStarts )
                    Thread.sleep( (new Random()).nextInt( startPeriodms ) );
                else
                    Thread.sleep( startPeriodms );
            }
            catch( InterruptedException e )
            {}
        }        
    }
    
    
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new SoundTester().setVisible(true);
            }
        });
    }
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JSpinner clipAssemblySizeSpinner;
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JSpinner numClipStartsSpinner;
    private javax.swing.JTextArea outputTextPane;
    private javax.swing.JSpinner periodBetweenStartsSpinner;
    private javax.swing.JCheckBox randomiseStartPeriodCheckbox;
    // End of variables declaration//GEN-END:variables
 
    
}
