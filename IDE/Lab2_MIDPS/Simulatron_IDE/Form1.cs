using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Media;
using System.Windows;
using System.Speech.Synthesis;

namespace Simulatron_IDE
{
    public partial class Form1 : Form
    {
        SpeechSynthesizer synthesizer = new SpeechSynthesizer();  
        

        public Form1()
        {                       

            InitializeComponent();
            synthesizer.Volume = 100;  
            synthesizer.Rate   = 0;     
            synthesizer.SpeakAsync("Welcome to Simulatron! Be ready for a new mission!");
               
        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }
    
        int i = 0;
        int sec;

        private void timer1_Tick(object sender, EventArgs e)
        {
            i++;
            
        }

        private void get_info_Click(object sender, EventArgs e)
        {
          
            Random rand = new Random();
            int r = rand.Next(-1, 5);


            string[] images_URL = {"https://raw.githubusercontent.com/TUM-FAF/FAF-121-Gusan-Gina/master/IDE/Lab2_MIDPS/images/12196WotW_alien.jpg",
                                   "https://raw.githubusercontent.com/TUM-FAF/FAF-121-Gusan-Gina/master/IDE/Lab2_MIDPS/images/Alien%20Grey.jpg",
                                   "https://raw.githubusercontent.com/TUM-FAF/FAF-121-Gusan-Gina/master/IDE/Lab2_MIDPS/images/alien.jpg",
                                   "https://raw.githubusercontent.com/TUM-FAF/FAF-121-Gusan-Gina/master/IDE/Lab2_MIDPS/images/aliens.jpg",
                                   "https://raw.githubusercontent.com/TUM-FAF/FAF-121-Gusan-Gina/master/IDE/Lab2_MIDPS/images/all_1.jpg",
                                   "https://raw.githubusercontent.com/TUM-FAF/FAF-121-Gusan-Gina/master/IDE/Lab2_MIDPS/images/monsters-vs-aliens-characters-flipbook-16x9-thumb.jpg"
                                  };

            string[] name = { "DURRAN", "EPHIMIS", "HUNKAL", "KILLET", "LUMPOR", "NADRIN" };
            string[] second = { "5", "3", "7", "11", "9" };

                if ((r >= 0) & (r <= 4))
                {
                    i = i + 1;

                    detected.Text = "Enemy " + name[r].ToString() + " detected";
                    picture.ImageLocation = images_URL[r];
                    nr.Text = i.ToString();

                    sec = int.Parse(second[r].ToString());
                    timer1.Start();

                }

                else
                {
                    detected.Text = "No enemy detected";
                    picture.Image = null;
                }
                
                nr.Text = i.ToString();
                
        }

      
        private void info_Click(object sender, EventArgs e)
        {

        }


        private void timer1_Tick_1(object sender, EventArgs e)
        {
            if (sec == 0)
            {
                timer1.Stop();
                picture.Image = null;
                detected.Text = "No enemy detected";
                synthesizer.SpeakAsync("You've lost the enemy! Try again!");
                MessageBox.Show("You've lost the enemy!", "Try again!", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }


            if (sec > 0)
            {
                sec -= 1;
                timer_show.Text = sec.ToString();
            }

        }

        private void reset_Click(object sender, EventArgs e)
        {
            picture.Image = null;
            nr.Text = "0";
            captured.Text = "0";
            detected.Text = "No enemy detected";
            i_captured = 0;
            i = 0;
            timer1.Stop();          
                   
        }


        int i_captured = 0;

        private void button2_Click(object sender, EventArgs e)
        {

           if (picture.Image == null)
            {
                synthesizer.SpeakAsync("Everything is clear!");
                MessageBox.Show("Everything is clear!", "No danger", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                timer1.Stop();
                timer_show.Text = "  ";

                i_captured++;

                captured.Text = i_captured.ToString();
                picture.Image = null;
                detected.Text = "No enemy detected";

                synthesizer.SpeakAsync("The enemy is captured! Great job!");
                MessageBox.Show("The enemy is captured!", "Great job!", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }

        }

        private void detected_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }   
    }
}
