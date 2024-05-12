using System;

namespace lab1._1
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
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.port_managementDataSet = new lab1._1.port_managementDataSet();
            this.portmanagementDataSetBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.dataGridView2 = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.port_managementDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.portmanagementDataSetBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.AutoGenerateColumns = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.DataSource = this.portmanagementDataSetBindingSource;
            this.dataGridView1.Location = new System.Drawing.Point(144, 74);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 51;
            this.dataGridView1.RowTemplate.Height = 24;
            this.dataGridView1.Size = new System.Drawing.Size(503, 150);
            this.dataGridView1.TabIndex = 0;
            // 
            // port_managementDataSet
            // 
            this.port_managementDataSet.DataSetName = "port_managementDataSet";
            this.port_managementDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // portmanagementDataSetBindingSource
            // 
            this.portmanagementDataSetBindingSource.DataSource = this.port_managementDataSet;
            this.portmanagementDataSetBindingSource.Position = 0;
            // 
            // dataGridView2
            // 
            this.dataGridView2.AutoGenerateColumns = false;
            this.dataGridView2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView2.DataSource = this.portmanagementDataSetBindingSource;
            this.dataGridView2.Location = new System.Drawing.Point(144, 314);
            this.dataGridView2.Name = "dataGridView2";
            this.dataGridView2.RowHeadersWidth = 51;
            this.dataGridView2.RowTemplate.Height = 24;
            this.dataGridView2.Size = new System.Drawing.Size(541, 150);
            this.dataGridView2.TabIndex = 1;
            // 
            // Form1
            // 
            this.ClientSize = new System.Drawing.Size(1184, 578);
            this.Controls.Add(this.dataGridView2);
            this.Controls.Add(this.dataGridView1);
            this.Name = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.port_managementDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.portmanagementDataSetBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).EndInit();
            this.ResumeLayout(false);

        }
        #endregion

        private System.Windows.Forms.DataGridView campionate_dataGridView;
        private System.Windows.Forms.DataGridView cluburi_dataGridView;
        private port_managementDataSet campionateDataSet;
        private System.Windows.Forms.BindingSource campionateBindingSource;
        private port_managementDataSetTableAdapters.ShipTableAdapter campionateTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn idDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn datainfiintareDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn nrechipeDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn taraDataGridViewTextBoxColumn;
        private port_managementDataSetTableAdapters.PassengerTableAdapter cluburiDataSet;
        private System.Windows.Forms.BindingSource cluburiBindingSource;
        private port_managementDataSetTableAdapters.PassengerTableAdapter cluburiTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn idDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn numeDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn presedinteDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn antrenorDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn datafondariiDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn bugetDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn stadionDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn idcampionatDataGridViewTextBoxColumn;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DateTimePicker dataFondarii_dateTimePicker;
        private System.Windows.Forms.TextBox stadion_textBox;
        private System.Windows.Forms.TextBox antrenor_textBox;
        private System.Windows.Forms.TextBox presedinte_textBox;
        private System.Windows.Forms.TextBox nume_textBox;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.NumericUpDown buget_numericUpDown;
        private System.Windows.Forms.Button adaugaClub_button;
        private System.Windows.Forms.Button stergeClub_button;
        private System.Windows.Forms.Button actualizeazaClub_button;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.BindingSource portmanagementDataSetBindingSource;
        private port_managementDataSet port_managementDataSet;
        private System.Windows.Forms.DataGridView dataGridView2;
    }
}

