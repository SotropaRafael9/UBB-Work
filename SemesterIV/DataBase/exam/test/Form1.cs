using System;
using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace SemesterProjectApp
{
    public partial class Form1 : Form
    {
        private const string ConnectionString = "DESKTOP-4O0PI57\\SQLEXPRESS"; // Replace with your actual connection string

        private SqlDataAdapter dataAdapter;
        private DataTable tasksTable;
        private BindingSource tasksBindingSource;

        public Form1()
        {
            InitializeComponent();
        }

       

        private void Form1_Load(object sender, EventArgs e)
        {
            // Initialize data adapter and data table
            dataAdapter = new SqlDataAdapter("SELECT * FROM Task", ConnectionString);
            tasksTable = new DataTable();
            dataAdapter.Fill(tasksTable);

            // Set up binding source
            tasksBindingSource = new BindingSource();
            tasksBindingSource.DataSource = tasksTable;

            // Bind DataGridViews
            dgvMembers1.DataSource = tasksBindingSource;
            dgvTasks.DataSource = tasksBindingSource;

            // Set up event handlers
            dgvMembers1.SelectionChanged += DgvMembers_SelectionChanged;
            btnSaveChanges.Click += BtnSaveChanges_Click;
        }

        private void DgvMembers_SelectionChanged(object sender, EventArgs e)
        {
            // Filter tasks based on selected member
            if (dgvMembers1.CurrentRow != null)
            {
                int memberId = Convert.ToInt32(dgvMembers1.CurrentRow.Cells["MemberID"].Value);
                tasksBindingSource.Filter = $"MemberID = {memberId}";
            }
        }

        private void BtnSaveChanges_Click(object sender, EventArgs e)
        {
            // Save changes to the database
            try
            {
                SqlCommandBuilder builder = new SqlCommandBuilder(dataAdapter);
                dataAdapter.Update(tasksTable);
                MessageBox.Show("Changes saved successfully!");
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Error saving changes: {ex.Message}");
            }
        }

        private void Form1_Load_1(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'projectsDataSet1.Task' table. You can move, or remove it, as needed.
            this.taskTableAdapter1.Fill(this.projectsDataSet1.Task);
            // TODO: This line of code loads data into the 'projectsDataSet1.StudentMember' table. You can move, or remove it, as needed.
            this.studentMemberTableAdapter1.Fill(this.projectsDataSet1.StudentMember);

        }
    }
}
