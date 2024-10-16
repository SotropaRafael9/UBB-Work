namespace Reddit
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
            this.daTasks1 = new System.Windows.Forms.DataGridView();
            this.redditDataSet1BindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.redditDataSet1 = new Reddit.RedditDataSet();
            this.daBoards1 = new System.Windows.Forms.DataGridView();
            this.redditDataSet1BindingSource1 = new System.Windows.Forms.BindingSource(this.components);
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.daTasks1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.redditDataSet1BindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.redditDataSet1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.daBoards1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.redditDataSet1BindingSource1)).BeginInit();
            this.SuspendLayout();
            // 
            // daTasks1
            // 
            this.daTasks1.AutoGenerateColumns = false;
            this.daTasks1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.daTasks1.DataSource = this.redditDataSet1BindingSource;
            this.daTasks1.Location = new System.Drawing.Point(68, 100);
            this.daTasks1.Name = "daTasks1";
            this.daTasks1.RowHeadersWidth = 51;
            this.daTasks1.RowTemplate.Height = 24;
            this.daTasks1.Size = new System.Drawing.Size(240, 150);
            this.daTasks1.TabIndex = 0;
            // 
            // redditDataSet1BindingSource
            // 
            this.redditDataSet1BindingSource.DataSource = this.redditDataSet1;
            this.redditDataSet1BindingSource.Position = 0;
            // 
            // redditDataSet1
            // 
            this.redditDataSet1.DataSetName = "RedditDataSet";
            this.redditDataSet1.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // daBoards1
            // 
            this.daBoards1.AutoGenerateColumns = false;
            this.daBoards1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.daBoards1.DataSource = this.redditDataSet1BindingSource1;
            this.daBoards1.Location = new System.Drawing.Point(480, 100);
            this.daBoards1.Name = "daBoards1";
            this.daBoards1.RowHeadersWidth = 51;
            this.daBoards1.RowTemplate.Height = 24;
            this.daBoards1.Size = new System.Drawing.Size(240, 150);
            this.daBoards1.TabIndex = 1;
            // 
            // redditDataSet1BindingSource1
            // 
            this.redditDataSet1BindingSource1.DataSource = this.redditDataSet1;
            this.redditDataSet1BindingSource1.Position = 0;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(68, 323);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 2;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(313, 323);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 3;
            this.button2.Text = "button2";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.ClientSize = new System.Drawing.Size(961, 581);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.daBoards1);
            this.Controls.Add(this.daTasks1);
            this.Name = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.daTasks1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.redditDataSet1BindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.redditDataSet1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.daBoards1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.redditDataSet1BindingSource1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dgvUser;
        private System.Windows.Forms.BindingSource redditDataSetBindingSource;
        private RedditDataSet redditDataSet;
        private System.Windows.Forms.DataGridView dgvComments;
        private System.Windows.Forms.Button SaveBtn;
        private System.Windows.Forms.DataGridView daTasks1;
        private System.Windows.Forms.BindingSource redditDataSet1BindingSource;
        private RedditDataSet redditDataSet1;
        private System.Windows.Forms.DataGridView daBoards1;
        private System.Windows.Forms.BindingSource redditDataSet1BindingSource1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
    }
}

