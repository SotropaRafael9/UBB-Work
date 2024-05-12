using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab2
{
    public partial class Form1 : Form
    {
        private DataGridView masterDataGridView = new DataGridView();
        private BindingSource masterBindingSource = new BindingSource();
        private DataGridView detailsDataGridView = new DataGridView();
        private BindingSource detailsBindingSource = new BindingSource();
        private String connection;
        private String master;
        private String details;
        private String foreignKey;
        private String primaryKey;

        SplitContainer tablesSplitContainer = new SplitContainer();
        FlowLayoutPanel verticalPanel = new FlowLayoutPanel();
        SplitContainer mainSplitContainer = new SplitContainer();

        private Button addButton;
        private Button updateButton;
        private Button deleteButton;
        private Label[] labels;
        private TextBox[] textBoxes;
        /*MessageBox.Show(connection + "\n" + master + "\n" + details + "\n" + foreignKey);*/

        public Form1()
        {
            connection = ConfigurationManager.AppSettings.Get("DBConnection");
            master = ConfigurationManager.AppSettings.Get("Master");
            primaryKey = ConfigurationManager.AppSettings.Get("MasterPK");
            details = ConfigurationManager.AppSettings.Get("Details");
            foreignKey = ConfigurationManager.AppSettings.Get("ForeignKey");
            

            masterDataGridView.Dock = DockStyle.Fill;
            masterDataGridView.RowHeaderMouseClick += new DataGridViewCellMouseEventHandler(masterRowClick);
            detailsDataGridView.Dock = DockStyle.Fill;

            tablesSplitContainer.Dock = DockStyle.Fill;
            tablesSplitContainer.Orientation = Orientation.Horizontal;
            tablesSplitContainer.Panel1.Controls.Add(masterDataGridView);
            tablesSplitContainer.Panel2.Controls.Add(detailsDataGridView);

            verticalPanel.Dock = DockStyle.Fill;
            verticalPanel.FlowDirection = FlowDirection.TopDown;
            verticalPanel.Visible = false;
            createCrudForm(verticalPanel, connection, details);

            mainSplitContainer.Dock = DockStyle.Fill;
            mainSplitContainer.Orientation = Orientation.Vertical;
            mainSplitContainer.Panel1.Controls.Add(tablesSplitContainer);
            mainSplitContainer.SplitterDistance = 300;
            mainSplitContainer.Panel2.Controls.Add(verticalPanel);


            this.Controls.Add(mainSplitContainer);
            this.Load += new EventHandler(Form1_Load);
            this.Width = 800;
            this.Height = 600;
            this.Text = "Lab2 - master/details";
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            masterDataGridView.DataSource = masterBindingSource;
            detailsDataGridView.DataSource = detailsBindingSource;
            GetData();

            masterDataGridView.AutoResizeColumns();

            detailsDataGridView.AutoSizeColumnsMode =
                DataGridViewAutoSizeColumnsMode.AllCells;
        }

        private void masterRowClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            verticalPanel.Visible = true;
            // foreign key
            textBoxes[textBoxes.Length - 1].ReadOnly = true;
            textBoxes[textBoxes.Length - 1].Text = masterDataGridView.SelectedRows[0].Cells[0].Value.ToString();
        }


        private void GetData()
        {
            SqlConnection sql = new SqlConnection(connection);

            DataSet data = new DataSet();
            data.Locale = System.Globalization.CultureInfo.InvariantCulture;

            SqlDataAdapter masterDataAdapter = new SqlDataAdapter("select * from " + master, sql);
            masterDataAdapter.Fill(data, master);

            SqlDataAdapter detailsDataAdapter = new SqlDataAdapter("select * from " + details, sql);
            detailsDataAdapter.Fill(data, details);

            DataRelation relation = new DataRelation("FK_" + master + "_" + details,
                data.Tables[master].Columns["id_ship"],
                data.Tables[details].Columns[foreignKey]);
            data.Relations.Add(relation);

            masterBindingSource.DataSource = data;
            masterBindingSource.DataMember = master;

            detailsBindingSource.DataSource = masterBindingSource;
            detailsBindingSource.DataMember = "FK_" + master + "_" + details;
        }

        private void createCrudForm(FlowLayoutPanel verticalPanel, string connectionString, string details)
        {
            string countQuery = $"SELECT COUNT(*) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = '{details}'";
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                SqlCommand command = new SqlCommand(countQuery, connection);
                connection.Open();
                SqlDataReader reader = command.ExecuteReader();
                if (reader.Read())
                {
                    int numberOfColumns = (int)reader[0];
                    labels = new Label[numberOfColumns];
                    textBoxes = new TextBox[numberOfColumns];
                }
            }

            string query = $"SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = '{details}'";
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                SqlCommand command = new SqlCommand(query, connection);
                connection.Open();
                SqlDataReader reader = command.ExecuteReader();
                int i = 0;

                while (reader.Read())
                {
                    if (reader["COLUMN_NAME"].ToString() != "id")
                    {
                        string columnName = reader["COLUMN_NAME"].ToString();

                        Label label = new Label();
                        label.Text = columnName;
                        label.AutoSize = true;
                        labels[i] = label;

                        TextBox textBox = new TextBox();
                        textBox.Name = "textBox_" + columnName;
                        textBox.Dock = DockStyle.Top;
                        textBoxes[i] = textBox;

                        verticalPanel.Controls.Add(label);
                        verticalPanel.Controls.Add(textBox);
                        i++;
                    }
                }
            }
            addButton = new Button();
            addButton.Text = "Add";
            addButton.Click += new EventHandler(AddButton_Click);

            updateButton = new Button();
            updateButton.Text = "Update";
            updateButton.Click += new EventHandler(UpdateButton_Click);

            deleteButton = new Button();
            deleteButton.Text = "Delete";
            deleteButton.Click += new EventHandler(DeleteButton_Click);

            verticalPanel.Controls.Add(addButton);
            verticalPanel.Controls.Add(updateButton);
            verticalPanel.Controls.Add(deleteButton);
        }

        private void AddButton_Click(object sender, EventArgs e)
        {
            if (masterDataGridView.SelectedRows.Count > 0) // if a master row is selected
            {
                String columns = "";
                String parameters = "";
                foreach (Label label in labels) //
                {
                    columns += label.Text + ", ";
                    parameters += "@" + label.Text + ", ";
                }
                columns.Trim();
                columns = columns.Remove(columns.Length - 2); 
                parameters.Trim(); 
                parameters = parameters.Remove(parameters.Length - 2); // remove the last comma and space
                String query = "INSERT INTO " + details + " (" + columns + ") VALUES (" + parameters + ")";
                using (SqlConnection connection = new SqlConnection(this.connection)) 
                {
                    SqlCommand command = new SqlCommand(query, connection);
                    connection.Open();
                    int i = 0;
                    // add parameters into the query
                    foreach (TextBox textBox in textBoxes)
                    {
                        if (labels[i].Text.Contains("data"))
                        {
                            DateTime date;
                            DateTime.TryParseExact(textBox.Text, "dd/mm/yyyy", CultureInfo.InvariantCulture, DateTimeStyles.None, out date);
                            command.Parameters.AddWithValue("@" + labels[i].Text, date);
                        }
                        else
                            command.Parameters.AddWithValue("@" + labels[i].Text, textBox.Text);
                        i++;
                    }
                    MessageBox.Show(query);
                    int rowsAffected = command.ExecuteNonQuery();
                    MessageBox.Show("Rows affected: " + rowsAffected);
                    GetData();
                }
            }
            else
                MessageBox.Show("Please select a master row");
        }

        private void UpdateButton_Click(object sender, EventArgs e)
        {
            // if a master row and a details row are selected
            if (masterDataGridView.SelectedRows.Count > 0 && detailsDataGridView.SelectedRows.Count > 0) 
            {
                String set = "";
                // create the set part of the query
                foreach (Label label in labels)
                {
                    set += label.Text + " = @" + label.Text + ", ";
                }
                set.Trim();
                set = set.Remove(set.Length - 2); // remove the last comma and space
                String query = "UPDATE " + details + " SET " + set + " WHERE id_ship = @id";
                
                using (SqlConnection connection = new SqlConnection(this.connection))
                {
                    SqlCommand command = new SqlCommand(query, connection);
                    connection.Open();
                    int i = 0;
                    // add parameters into the query
                    foreach (TextBox textBox in textBoxes)
                    {
                        command.Parameters.AddWithValue("@" + labels[i].Text, textBox.Text);
                        i++;
                    }
                    command.Parameters.AddWithValue("@id", detailsDataGridView.SelectedRows[0].Cells[0].Value);
                    MessageBox.Show(query);

                    int rowsAffected = command.ExecuteNonQuery();
                    MessageBox.Show("Rows affected: " + rowsAffected);
                    GetData();
                }
            }
            else
                MessageBox.Show("Please select a master and a detail row");
        }

        private void DeleteButton_Click(object sender, EventArgs e)
        {
            // if is selected
            if (detailsDataGridView.SelectedRows.Count > 0)
            {
                // get the id of the selected row
                int id = (int)detailsDataGridView.SelectedRows[0].Cells[0].Value;
                String query = "DELETE FROM " + details + " WHERE id_ship = @id";
                using (SqlConnection connection = new SqlConnection(this.connection))
                {
                    SqlCommand command = new SqlCommand(query, connection);
                    connection.Open();
                    command.Parameters.AddWithValue("@id", id);
                    int rowsAffected = command.ExecuteNonQuery();
                    MessageBox.Show("Rows affected: " + rowsAffected);
                    GetData();
                }
            }
            else
                MessageBox.Show("Please select a detail row!");
        }
    }
}
