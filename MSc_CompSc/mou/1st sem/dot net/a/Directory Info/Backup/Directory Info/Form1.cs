using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Directory_Info
{
    public partial class Form1 : Form
    {
        // private TextBox textBox1;
        // private Button button1;
        // private ListBox listBox1;
        private Container componemts = null;

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            System.IO.DirectoryInfo dir = new System.IO.DirectoryInfo(textBox1.Text);
            foreach (System.IO.FileInfo files in dir.GetFiles("*.*"))
            {
                listBox1.Items.Add(files.Name);
            }
        }


        private void Form1_Load(object sender, EventArgs e)
        {
            /*comboBox1.Items.Add("only image files");
            comboBox1.Items.Add("only text files");
            comboBox1.Items.Add("all Files");

            comboBox1.Enabled.Equals(false);
            if (textBox1.s.Enabled.Equals(true))
            {
                comboBox1.Enabled.Equals(true);

            }*/
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            /*if (comboBox1.SelectedIndex.Equals(0))
            {
                System.IO.DirectoryInfo dir = new System.IO.DirectoryInfo(textBox1.Text);
                foreach (System.IO.FileInfo files in dir.GetFiles("*.jpg"))
                {

                    listBox1.Items.Add(files.Name);
                }
            }
            else if (comboBox1.SelectedIndex.Equals(1))
            {
                System.IO.DirectoryInfo dir = new System.IO.DirectoryInfo(textBox1.Text);
                foreach (System.IO.FileInfo files in dir.GetFiles("*.txt"))
                {

                    listBox1.Items.Add(files.Name);
                }
            }
            else if (comboBox1.SelectedIndex.Equals(2))
            {
                System.IO.DirectoryInfo dir = new System.IO.DirectoryInfo(textBox1.Text);
                foreach (System.IO.FileInfo files in dir.GetFiles("*.*"))
                {

                    listBox1.Items.Add(files.Name);
                }
            }*/

        }

    }
}