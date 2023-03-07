using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;

namespace quiz
{
	/// <summary>
	/// Summary description for Form1.
	/// </summary>
	public class Form1 : System.Windows.Forms.Form
	{
		private int intResult;
		private int intTry = 0;
		private int intCor = 0;
		System.DateTime currentTime;
		System.DateTime resultTime;

		private System.Windows.Forms.Label lblAnswer;
		private System.Windows.Forms.Label lblFirst;
		private System.Windows.Forms.Label lblSign;
		private System.Windows.Forms.Label lblSecond;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label lblResult;
		private System.Windows.Forms.Button btnFirst;
		private System.Windows.Forms.Button btnSecond;
		private System.Windows.Forms.Button btnThird;
		private System.Windows.Forms.Button btnFourth;
		private System.Windows.Forms.Button btnNext;
		private System.Windows.Forms.Button btnFinish;
		private System.Windows.Forms.MainMenu mainMenu1;
		private System.Windows.Forms.MenuItem menuItem1;
		private System.Windows.Forms.MenuItem menuItem2;
		private System.Windows.Forms.MenuItem menuItem3;
		private System.Windows.Forms.MenuItem menuItem4;
		private System.Windows.Forms.MenuItem menuItem5;
		private System.Windows.Forms.MenuItem menuItem6;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;

		public Form1()
		{
			//
			// Required for Windows Form Designer support
			//
			InitializeComponent();

			//
			// TODO: Add any constructor code after InitializeComponent call
			//
		}

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected override void Dispose( bool disposing )
		{
			if( disposing )
			{
				if (components != null) 
				{
					components.Dispose();
				}
			}
			base.Dispose( disposing );
		}

		#region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.lblAnswer = new System.Windows.Forms.Label();
			this.lblFirst = new System.Windows.Forms.Label();
			this.lblSign = new System.Windows.Forms.Label();
			this.lblSecond = new System.Windows.Forms.Label();
			this.label1 = new System.Windows.Forms.Label();
			this.lblResult = new System.Windows.Forms.Label();
			this.btnFirst = new System.Windows.Forms.Button();
			this.btnSecond = new System.Windows.Forms.Button();
			this.btnThird = new System.Windows.Forms.Button();
			this.btnFourth = new System.Windows.Forms.Button();
			this.btnNext = new System.Windows.Forms.Button();
			this.btnFinish = new System.Windows.Forms.Button();
			this.mainMenu1 = new System.Windows.Forms.MainMenu();
			this.menuItem3 = new System.Windows.Forms.MenuItem();
			this.menuItem4 = new System.Windows.Forms.MenuItem();
			this.menuItem6 = new System.Windows.Forms.MenuItem();
			this.menuItem5 = new System.Windows.Forms.MenuItem();
			this.menuItem1 = new System.Windows.Forms.MenuItem();
			this.menuItem2 = new System.Windows.Forms.MenuItem();
			this.SuspendLayout();
			// 
			// lblAnswer
			// 
			this.lblAnswer.BackColor = System.Drawing.SystemColors.Control;
			this.lblAnswer.Location = new System.Drawing.Point(144, 208);
			this.lblAnswer.Name = "lblAnswer";
			this.lblAnswer.TabIndex = 0;
			this.lblAnswer.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// lblFirst
			// 
			this.lblFirst.BackColor = System.Drawing.SystemColors.Control;
			this.lblFirst.Location = new System.Drawing.Point(88, 32);
			this.lblFirst.Name = "lblFirst";
			this.lblFirst.Size = new System.Drawing.Size(32, 16);
			this.lblFirst.TabIndex = 1;
			this.lblFirst.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// lblSign
			// 
			this.lblSign.Location = new System.Drawing.Point(130, 32);
			this.lblSign.Name = "lblSign";
			this.lblSign.Size = new System.Drawing.Size(24, 16);
			this.lblSign.TabIndex = 2;
			this.lblSign.Text = "+";
			this.lblSign.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// lblSecond
			// 
			this.lblSecond.Location = new System.Drawing.Point(164, 32);
			this.lblSecond.Name = "lblSecond";
			this.lblSecond.Size = new System.Drawing.Size(64, 16);
			this.lblSecond.TabIndex = 3;
			this.lblSecond.Text = "???";
			this.lblSecond.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(238, 32);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(24, 16);
			this.label1.TabIndex = 4;
			this.label1.Text = "=";
			this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// lblResult
			// 
			this.lblResult.Location = new System.Drawing.Point(272, 32);
			this.lblResult.Name = "lblResult";
			this.lblResult.Size = new System.Drawing.Size(32, 16);
			this.lblResult.TabIndex = 5;
			this.lblResult.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// btnFirst
			// 
			this.btnFirst.Location = new System.Drawing.Point(57, 110);
			this.btnFirst.Name = "btnFirst";
			this.btnFirst.Size = new System.Drawing.Size(56, 24);
			this.btnFirst.TabIndex = 6;
			this.btnFirst.Click += new System.EventHandler(this.btnFirst_Click);
			// 
			// btnSecond
			// 
			this.btnSecond.Location = new System.Drawing.Point(131, 110);
			this.btnSecond.Name = "btnSecond";
			this.btnSecond.Size = new System.Drawing.Size(56, 24);
			this.btnSecond.TabIndex = 7;
			this.btnSecond.Click += new System.EventHandler(this.btnSecond_Click);
			// 
			// btnThird
			// 
			this.btnThird.Location = new System.Drawing.Point(205, 110);
			this.btnThird.Name = "btnThird";
			this.btnThird.Size = new System.Drawing.Size(56, 24);
			this.btnThird.TabIndex = 8;
			this.btnThird.Click += new System.EventHandler(this.btnThird_Click);
			// 
			// btnFourth
			// 
			this.btnFourth.BackColor = System.Drawing.SystemColors.Control;
			this.btnFourth.Location = new System.Drawing.Point(279, 110);
			this.btnFourth.Name = "btnFourth";
			this.btnFourth.Size = new System.Drawing.Size(56, 24);
			this.btnFourth.TabIndex = 9;
			this.btnFourth.Click += new System.EventHandler(this.btnFourth_Click);
			// 
			// btnNext
			// 
			this.btnNext.Location = new System.Drawing.Point(280, 208);
			this.btnNext.Name = "btnNext";
			this.btnNext.TabIndex = 10;
			this.btnNext.Text = "Next  >>";
			this.btnNext.Click += new System.EventHandler(this.btnNext_Click);
			// 
			// btnFinish
			// 
			this.btnFinish.Location = new System.Drawing.Point(24, 208);
			this.btnFinish.Name = "btnFinish";
			this.btnFinish.TabIndex = 11;
			this.btnFinish.Text = "Finish";
			this.btnFinish.Click += new System.EventHandler(this.btnFinish_Click);
			// 
			// mainMenu1
			// 
			this.mainMenu1.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
																					  this.menuItem3,
																					  this.menuItem1});
			// 
			// menuItem3
			// 
			this.menuItem3.Index = 0;
			this.menuItem3.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
																					  this.menuItem4,
																					  this.menuItem6,
																					  this.menuItem5});
			this.menuItem3.Text = "&File";
			// 
			// menuItem4
			// 
			this.menuItem4.Index = 0;
			this.menuItem4.Text = "&New";
			this.menuItem4.Click += new System.EventHandler(this.menuItem4_Click);
			// 
			// menuItem6
			// 
			this.menuItem6.Index = 1;
			this.menuItem6.Text = "-";
			// 
			// menuItem5
			// 
			this.menuItem5.Index = 2;
			this.menuItem5.Text = "E&xit";
			this.menuItem5.Click += new System.EventHandler(this.menuItem5_Click);
			// 
			// menuItem1
			// 
			this.menuItem1.Index = 1;
			this.menuItem1.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
																					  this.menuItem2});
			this.menuItem1.Text = "&About";
			// 
			// menuItem2
			// 
			this.menuItem2.Index = 0;
			this.menuItem2.Text = "About Do The Math";
			this.menuItem2.Click += new System.EventHandler(this.menuItem2_Click);
			// 
			// Form1
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
			this.ClientSize = new System.Drawing.Size(392, 245);
			this.Controls.AddRange(new System.Windows.Forms.Control[] {
																		  this.btnFinish,
																		  this.btnNext,
																		  this.btnFourth,
																		  this.btnThird,
																		  this.btnSecond,
																		  this.btnFirst,
																		  this.lblResult,
																		  this.label1,
																		  this.lblSecond,
																		  this.lblSign,
																		  this.lblFirst,
																		  this.lblAnswer});
			this.Menu = this.mainMenu1;
			this.Name = "Form1";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Do The Math";
			this.Load += new System.EventHandler(this.Form1_Load);
			this.ResumeLayout(false);

		}
		#endregion

		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main() 
		{
			Form1 f = new Form1();
			f.numbers();
			Application.Run(f);


		}

		private void btnFirst_Click(object sender, System.EventArgs e)
		{
			if (int.Parse(btnFirst.Text) == intResult) 
			{
				lblAnswer.BackColor = System.Drawing.Color.Green;
				lblAnswer.Text = "Correct";
				intCor++;
				intTry++;
				disableBtn();
			}
			else 
			{
				lblAnswer.BackColor = System.Drawing.Color.Red;
				lblAnswer.Text = "Incorrect";
				intTry++;
				disableBtn();
			}
		}

		private void btnSecond_Click(object sender, System.EventArgs e)
		{
			if (int.Parse(btnSecond.Text) == intResult) 
			{
				lblAnswer.BackColor = System.Drawing.Color.Green;
				lblAnswer.Text = "Correct";
				intCor++;
				intTry++;
				disableBtn();
			}
			else 
			{
				lblAnswer.BackColor = System.Drawing.Color.Red;
				lblAnswer.Text = "Incorrect";
				intTry++;
				disableBtn();
			}		
		}

		private void btnThird_Click(object sender, System.EventArgs e)
		{
			if (int.Parse(btnThird.Text) == intResult) 
			{
				lblAnswer.BackColor = System.Drawing.Color.Green;
				lblAnswer.Text = "Correct";
				intCor++;
				intTry++;
				disableBtn();
			}
			else 
			{
				lblAnswer.BackColor = System.Drawing.Color.Red;
				lblAnswer.Text = "Incorrect";
				intTry++;
				disableBtn();
			}
		
		}

		private void btnFourth_Click(object sender, System.EventArgs e)
		{
			if (int.Parse(btnFourth.Text) == intResult) 
			{
				lblAnswer.BackColor = System.Drawing.Color.Green;;
				lblAnswer.Text = "Correct";
				intCor++;
				intTry++;
				disableBtn();
			}
			else 
			{
				lblAnswer.BackColor = System.Drawing.Color.Red;
				lblAnswer.Text = "Incorrect";
				intTry++;
				disableBtn();
			}
		}
		public void numbers() 
		{
			enableBtn();

			/* 
			 * this creates a random number 
			 * that determinates the operation
			 * addition, subtraction and multiplication
			 * maybe I'll add something else
			 * in the next version
			 */
			Random sign = new Random();
			int intSign = sign.Next(3);

			switch (intSign) 
			{
				case 0:
					plus();
					break;
				case 1:
					minus();
					break;
				case 2:
					multi();
					break;
				default:
					numbers();
					break;
			}
		}

		private void btnNext_Click(object sender, System.EventArgs e)
		{
			numbers();
		}

		public void plus() 
		{
			lblAnswer.Text = "";
			lblAnswer.BackColor = System.Drawing.Color.FromName("Control");
			lblSign.Text = "+";

			// creates to random numbers between 0 and 100
			Random r = new Random();
			int first = r.Next(100);
			int second = r.Next(100);

			intResult = first + second;
				
			// the result should be less than 100
			// this is made for kids :)
			if (first + second < 100) 
			{
				lblFirst.Text = first.ToString();
				lblSecond.Text = second.ToString();
				
				// creates a random number between 0 and 3
				// this is made so that the button with
				// the right answer always changes place
				int a = r.Next(3);

				switch (a) 
				{
					case 0:
						btnFirst.Text = (first + second).ToString();
						btnSecond.Text = r.Next(100).ToString();
						btnThird.Text = r.Next(100).ToString();
						btnFourth.Text = r.Next(100).ToString();
						break;
					case 1:
						btnFirst.Text = r.Next(100).ToString();
						btnSecond.Text = (first + second).ToString();
						btnThird.Text = r.Next(100).ToString();
						btnFourth.Text = r.Next(100).ToString();
						break;
					case 2:
						btnFirst.Text = r.Next(100).ToString();
						btnSecond.Text = r.Next(100).ToString();
						btnThird.Text = (first + second).ToString();
						btnFourth.Text = r.Next(100).ToString();
						break;
					case 3:
						btnFirst.Text = r.Next(100).ToString();
						btnSecond.Text = r.Next(100).ToString();
						btnThird.Text = r.Next(100).ToString();
						btnFourth.Text = (first + second).ToString();
						break;
						
					default: 
						break;
				}// end switch		
			}//end if
			else 
			{
				// create to new random numbers
				plus();
			}
		
		}// plus()

		public void minus() 
		{
			lblAnswer.Text = "";
			lblAnswer.BackColor = System.Drawing.Color.FromName("Control");
			lblSign.Text = "-";

			Random r = new Random();
			int first = r.Next(100);
			int second = r.Next(100);

			intResult = first - second;
			
			// test if the number is positiv
			// again this is a program for kids :)
			if (first - second > 0) 
			{
				lblFirst.Text = first.ToString();
				lblSecond.Text = second.ToString();
				
				// creates a random number between 0 and 3
				// this is made so that the button with
				// the right answer always changes place
				int a = r.Next(3);

				switch (a) 
				{
					case 0:
						btnFirst.Text = (first - second).ToString();
						btnSecond.Text = r.Next(100).ToString();
						btnThird.Text = r.Next(100).ToString();
						btnFourth.Text = r.Next(100).ToString();
						break;
					case 1:
						btnFirst.Text = r.Next(100).ToString();
						btnSecond.Text = (first - second).ToString();
						btnThird.Text = r.Next(100).ToString();
						btnFourth.Text = r.Next(100).ToString();
						break;
					case 2:
						btnFirst.Text = r.Next(100).ToString();
						btnSecond.Text = r.Next(100).ToString();
						btnThird.Text = (first - second).ToString();
						btnFourth.Text = r.Next(100).ToString();
						break;
					case 3:
						btnFirst.Text = r.Next(100).ToString();
						btnSecond.Text = r.Next(100).ToString();
						btnThird.Text = r.Next(100).ToString();
						btnFourth.Text = (first - second).ToString();
						break;
						
					default: 
						break;
				}// end switch		
			}//end if
			else 
			{
				// create to new numbers
				minus();
			}			
		}

		public void multi() 
		{
			lblAnswer.Text = "";
			lblAnswer.BackColor = System.Drawing.Color.FromName("Control");
			lblSign.Text = "*";

			Random r = new Random();
	
			// creates to random numbers between 0 and 10
			int first = r.Next(10);
			int second = r.Next(10);

			intResult = first * second;
				
			// check if the result is bigger than 100
			// imposible but who knows :)
			if (first * second < 100) 
			{
				lblFirst.Text = first.ToString();
				lblSecond.Text = second.ToString();
				
				// creates a random number between 0 and 3
				// this is made so that the button with
				// the right answer always changes place
				int a = r.Next(3);

				switch (a) 
				{
					case 0:
						btnFirst.Text = (first * second).ToString();
						btnSecond.Text = r.Next(100).ToString();
						btnThird.Text = r.Next(100).ToString();
						btnFourth.Text = r.Next(100).ToString();
						break;
					case 1:
						btnFirst.Text = r.Next(100).ToString();
						btnSecond.Text = (first * second).ToString();
						btnThird.Text = r.Next(100).ToString();
						btnFourth.Text = r.Next(100).ToString();
						break;
					case 2:
						btnFirst.Text = r.Next(100).ToString();
						btnSecond.Text = r.Next(100).ToString();
						btnThird.Text = (first * second).ToString();
						btnFourth.Text = r.Next(100).ToString();
						break;
					case 3:
						btnFirst.Text = r.Next(100).ToString();
						btnSecond.Text = r.Next(100).ToString();
						btnThird.Text = r.Next(100).ToString();
						btnFourth.Text = (first * second).ToString();
						break;
						
					default: 
						break;
				}// end switch		
			}//end if
			else 
			{
				// try some other number
				multi();
			}			
		}


		private void btnFinish_Click(object sender, System.EventArgs e)
		{
			// test to see if we answerd some questions
			if (intTry > 0) 
			{			
				// get the time passed and display a messagebox
				System.DateTime resultTime = System.DateTime.Now;
				Time needed = new Time(resultTime, currentTime);

				String strText = "You have " + intCor.ToString() + 
					" correct out of " + intTry.ToString() + " tries." +
					needed.getElapseTime();

				MessageBox.Show(strText);
			}
			// EJECT !!! EJECT !!! EJECT !!!
			Application.Exit();
		}

		private void disableBtn() {
			
			btnFirst.Enabled = false;
			btnSecond.Enabled = false;
			btnThird.Enabled = false;
			btnFourth.Enabled = false;
			lblResult.Text = intResult.ToString();
			btnNext.Enabled = true;

		}

		private void enableBtn() {

			btnFirst.Enabled = true;
			btnSecond.Enabled = true;
			btnThird.Enabled = true;
			btnFourth.Enabled = true;
			lblResult.Text = "";
			btnNext.Enabled = false;
		
		}

		private void menuItem2_Click(object sender, System.EventArgs e)
		{
			// create a new AboutForm
			// and show it to the people !!!
			AboutForm af = new AboutForm();
			af.Show();

		}

		private void menuItem4_Click(object sender, System.EventArgs e)
		{
			// test to see if we answerd some questions
			if (intTry > 0) 
			{
				// get the time passed and display a messagebox
				resultTime = System.DateTime.Now;
				Time needed = new Time(resultTime, currentTime);

				String strText = "You have " + intCor.ToString() + 
					" correct out of " + intTry.ToString() + " tries." +
					needed.getElapseTime();

				MessageBox.Show(strText);
			}

			intTry = 0;
			intCor = 0;
			numbers();
				
			// reset the timer
			currentTime = System.DateTime.Now;

		}

		private void menuItem5_Click(object sender, System.EventArgs e)
		{
			// no comment for this one here :)
			Application.Exit();
		}

		private void Form1_Load(object sender, System.EventArgs e)
		{
			// start the timer
			currentTime = System.DateTime.Now;
		}

	
	}
	
	public class Time 
	{

		private int Year;
		private int Month;
		private int Date;
		private int Hour;
		private int Minute;
		private int Second;

		string elapse = "You needed ";
	
		public Time(System.DateTime passed, System.DateTime start)
		{
			Year = passed.Year - start.Year;
			Month = passed.Month - start.Month;
			Date = passed.Day - start.Day;
			Hour = passed.Hour - start.Hour;
			Minute = passed.Minute - start.Minute;
			Second = passed.Second - start.Second;

		}
		public string getElapseTime() 
		{
			// returns the time that has passed as a 
			// string "elapse"
			if (Year > 0)
				elapse = elapse + Year.ToString() + " years, ";
			if (Month > 0)
				elapse = elapse + Month.ToString() + " months, ";
			if (Date > 0)
				elapse = elapse + Date.ToString() + " days, ";
			if (Hour > 0)
				elapse = elapse + Hour.ToString() + " hours, ";
			if (Minute > 0)
				elapse = elapse + Minute.ToString() + " minutes, ";
			if (Second > 0)
				elapse = elapse + Second.ToString() + " seconds for the test.";

			return elapse;
		}
	}

}
