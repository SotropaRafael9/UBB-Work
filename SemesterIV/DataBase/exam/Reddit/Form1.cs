using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Reddit
{
    public partial class Form1 : Form
    {
        SqlConnection sqlConnection = new SqlConnection("Data Source=DESKTOP-IG95M02;Initial Catalog=sem_2023_2024;Integrated Security=true");
        SqlDataAdapter daBoards, daTasks;
        DataSet ds = new DataSet();
        BindingSource bsBoards = new BindingSource();
        BindingSource bsTasks = new BindingSource();
        SqlCommandBuilder scb;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            daTasks.Update(ds, "Tasks");
        }

        private void buttonNext_Click(object sender, EventArgs e)
        {
            bsTasks.MoveNext();
            dgvUser.ClearSelection();
            dgvUser.Rows[bsTasks.Position].Selected = true;
        }

        private void buttonConnect_Click(object sender, EventArgs e)
        {
            string boardCommand = "Select * From User";
            daBoards = new SqlDataAdapter(boardCommand, sqlConnection);

            string taskCommand = "Select * From Comments";
            daTasks = new SqlDataAdapter(taskCommand, sqlConnection);

            scb = new SqlCommandBuilder(daTasks);

            daBoards1.Fill(ds, "Boards");
            daTasks1.Fill(ds, "Tasks");

            DataRelation dataRelation = new DataRelation("FK_Boards_Tasks", ds.Tables["Boards"].Columns["bid"], ds.Tables["Tasks"].Columns["bid"]);
            ds.Relations.Add(dataRelation);



            bsBoards1.DataSource = ds;
            bsBoards1.DataMember = "Boards";

            bsTasks1.DataSource = bsBoards;
            bsTasks1.DataMember = "FK_Boards_Tasks";

            dgvComments1.DataSource = bsBoards;
            dgvUser1.DataSource = bsTasks;

            dgvComments1.ReadOnly = true;
            dgvComments1.AllowUserToAddRows = false;
            dgvComments1.AllowUserToDeleteRows = false;

            //textBoxTaskName.DataBindings.Add("Text", bsTasks, "tname");

        }
    }
}
