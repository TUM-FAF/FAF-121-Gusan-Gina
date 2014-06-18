namespace Simulatron_IDE
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.picture = new System.Windows.Forms.PictureBox();
            this.nr = new System.Windows.Forms.Label();
            this.timer_show = new System.Windows.Forms.Label();
            this.button2 = new System.Windows.Forms.Button();
            this.get_info = new System.Windows.Forms.Button();
            this.reset = new System.Windows.Forms.Button();
            this.time_destroy = new System.Windows.Forms.Label();
            this.captured = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.detected = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.picture)).BeginInit();
            this.SuspendLayout();
            // 
            // timer1
            // 
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick_1);
            // 
            // picture
            // 
            this.picture.BackColor = System.Drawing.Color.Transparent;
            this.picture.Location = new System.Drawing.Point(167, 29);
            this.picture.Name = "picture";
            this.picture.Size = new System.Drawing.Size(354, 150);
            this.picture.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.picture.TabIndex = 0;
            this.picture.TabStop = false;
            // 
            // nr
            // 
            this.nr.AutoSize = true;
            this.nr.BackColor = System.Drawing.Color.Transparent;
            this.nr.Font = new System.Drawing.Font("Castellar", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.nr.ForeColor = System.Drawing.SystemColors.Highlight;
            this.nr.Location = new System.Drawing.Point(61, 152);
            this.nr.Name = "nr";
            this.nr.Size = new System.Drawing.Size(18, 16);
            this.nr.TabIndex = 4;
            this.nr.Text = "0";
            // 
            // timer_show
            // 
            this.timer_show.AutoSize = true;
            this.timer_show.BackColor = System.Drawing.Color.Transparent;
            this.timer_show.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.timer_show.ForeColor = System.Drawing.SystemColors.Desktop;
            this.timer_show.Location = new System.Drawing.Point(406, 343);
            this.timer_show.Name = "timer_show";
            this.timer_show.Size = new System.Drawing.Size(0, 25);
            this.timer_show.TabIndex = 7;
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.Color.Transparent;
            this.button2.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button2.BackgroundImage")));
            this.button2.FlatAppearance.BorderSize = 0;
            this.button2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.749999F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button2.ForeColor = System.Drawing.SystemColors.Desktop;
            this.button2.Location = new System.Drawing.Point(244, 311);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(51, 48);
            this.button2.TabIndex = 8;
            this.button2.Text = "FIRE";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // get_info
            // 
            this.get_info.BackColor = System.Drawing.SystemColors.ControlLight;
            this.get_info.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.get_info.FlatAppearance.BorderSize = 2;
            this.get_info.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.get_info.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.749999F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.get_info.ForeColor = System.Drawing.SystemColors.Desktop;
            this.get_info.Image = ((System.Drawing.Image)(resources.GetObject("get_info.Image")));
            this.get_info.Location = new System.Drawing.Point(282, 264);
            this.get_info.Name = "get_info";
            this.get_info.Size = new System.Drawing.Size(136, 31);
            this.get_info.TabIndex = 9;
            this.get_info.Text = "FIND ENEMY";
            this.get_info.UseVisualStyleBackColor = false;
            this.get_info.Click += new System.EventHandler(this.get_info_Click);
            // 
            // reset
            // 
            this.reset.BackColor = System.Drawing.Color.Transparent;
            this.reset.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.reset.FlatAppearance.BorderSize = 0;
            this.reset.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.749999F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.reset.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.reset.Image = ((System.Drawing.Image)(resources.GetObject("reset.Image")));
            this.reset.Location = new System.Drawing.Point(309, 311);
            this.reset.Name = "reset";
            this.reset.Size = new System.Drawing.Size(75, 25);
            this.reset.TabIndex = 11;
            this.reset.Text = "RESET";
            this.reset.UseVisualStyleBackColor = false;
            this.reset.Click += new System.EventHandler(this.reset_Click);
            // 
            // time_destroy
            // 
            this.time_destroy.AutoSize = true;
            this.time_destroy.BackColor = System.Drawing.Color.Transparent;
            this.time_destroy.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.749999F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.time_destroy.ForeColor = System.Drawing.SystemColors.InactiveCaptionText;
            this.time_destroy.Location = new System.Drawing.Point(393, 311);
            this.time_destroy.Name = "time_destroy";
            this.time_destroy.Size = new System.Drawing.Size(176, 16);
            this.time_destroy.TabIndex = 16;
            this.time_destroy.Text = "T i m e   to   c a p t u r e :";
            // 
            // captured
            // 
            this.captured.AutoSize = true;
            this.captured.BackColor = System.Drawing.Color.Transparent;
            this.captured.Font = new System.Drawing.Font("Castellar", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.captured.ForeColor = System.Drawing.SystemColors.Highlight;
            this.captured.Location = new System.Drawing.Point(602, 152);
            this.captured.Name = "captured";
            this.captured.Size = new System.Drawing.Size(18, 16);
            this.captured.TabIndex = 21;
            this.captured.Text = "0";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Font = new System.Drawing.Font("Castellar", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.SystemColors.Highlight;
            this.label1.Location = new System.Drawing.Point(3, 139);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(142, 13);
            this.label1.TabIndex = 22;
            this.label1.Text = "Detected enemies:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.Transparent;
            this.label2.Font = new System.Drawing.Font("Castellar", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.SystemColors.Highlight;
            this.label2.Location = new System.Drawing.Point(538, 139);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(147, 13);
            this.label2.TabIndex = 23;
            this.label2.Text = "Distroyed enemies";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // detected
            // 
            this.detected.AutoSize = true;
            this.detected.BackColor = System.Drawing.Color.Transparent;
            this.detected.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.detected.ForeColor = System.Drawing.SystemColors.ControlDark;
            this.detected.Location = new System.Drawing.Point(269, 192);
            this.detected.Name = "detected";
            this.detected.Size = new System.Drawing.Size(158, 16);
            this.detected.TabIndex = 1;
            this.detected.Text = "NO ENEMIES FOUND";
            this.detected.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.detected.Click += new System.EventHandler(this.detected_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(684, 389);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.captured);
            this.Controls.Add(this.time_destroy);
            this.Controls.Add(this.reset);
            this.Controls.Add(this.get_info);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.timer_show);
            this.Controls.Add(this.nr);
            this.Controls.Add(this.detected);
            this.Controls.Add(this.picture);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.MinimumSize = new System.Drawing.Size(695, 372);
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Simulatron";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.picture)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.PictureBox picture;
        private System.Windows.Forms.Label nr;
        private System.Windows.Forms.Label timer_show;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button get_info;
        private System.Windows.Forms.Button reset;
        private System.Windows.Forms.Label time_destroy;
        private System.Windows.Forms.Label captured;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label detected;
    }
}

