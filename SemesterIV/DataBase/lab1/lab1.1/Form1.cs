
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static lab1._1.port_managementDataSet;

namespace lab1._1
{
    public partial class Form1 : Form
    {
        
        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'campionateDataSet.Campionate' table. You can move, or remove it, as needed.
            this.campionateTableAdapter.Fill(this.campionateDataSet.Ship);
            // TODO: This line of code loads data into the 'cluburiDataSet.Cluburi' table. You can move, or remove it, as needed.
            //this.cluburiTableAdapter.Fill(this.cluburiDataSet.Cluburi);
        }

        /*private void updateCluburiDataGridView()
        {
            cluburiDataSet.Cluburi.Clear();
            int idCampionat = int.Parse(campionate_dataGridView.SelectedRows[0].Cells[0].Value.ToString());
            var cluburi = serviceFotbal.findClubsByIdCampionat(idCampionat);
            foreach (var club in cluburi)
            {
                cluburiDataSet.Cluburi.AddCluburiRow(club.Id, club.Nume, club.Presedinte, club.Antrenor, club.DataFondarii, club.Buget, club.Stadion, club.IdCampionat);
            }
        }

        private void campionate_dataGridView_RowHeaderMouseClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            updateCluburiDataGridView();
        }

        private void adaugaClub_button_Click(object sender, EventArgs e)
        {
            if (campionate_dataGridView.SelectedRows.Count > 0)
            {
                String nume = nume_textBox.Text;
                String presedinte = presedinte_textBox.Text;
                String antrenor = antrenor_textBox.Text;
                DateTime dataFondarii = dataFondarii_dateTimePicker.Value;
                int buget = (int)buget_numericUpDown.Value;
                String stadion = stadion_textBox.Text;
                int idCampionat = int.Parse(campionate_dataGridView.SelectedRows[0].Cells[0].Value.ToString());
                serviceFotbal.AddClub(nume, presedinte, antrenor, dataFondarii, buget, stadion, idCampionat);
                updateCluburiDataGridView();
            }
            else
            {
                MessageBox.Show("Selectati un campionat!");
            }
        }

        private void actualizeazaClub_button_Click(object sender, EventArgs e)
        {
            if (campionate_dataGridView.SelectedRows.Count > 0 && cluburi_dataGridView.SelectedRows.Count > 0)
            {
                int idClub = int.Parse(cluburi_dataGridView.SelectedRows[0].Cells[0].Value.ToString());
                String nume = nume_textBox.Text;
                String presedinte = presedinte_textBox.Text;
                String antrenor = antrenor_textBox.Text;
                DateTime dataFondarii = dataFondarii_dateTimePicker.Value;
                int buget = (int)buget_numericUpDown.Value;
                String stadion = stadion_textBox.Text;
                int idCampionat = int.Parse(campionate_dataGridView.SelectedRows[0].Cells[0].Value.ToString());
                serviceFotbal.UpdateClub(idClub, nume, presedinte, antrenor, dataFondarii, buget, stadion, idCampionat);
                updateCluburiDataGridView();
            }
            else
            {
                MessageBox.Show("Selectati un campionat si un club!");
            }
        }

        private void stergeClub_button_Click(object sender, EventArgs e)
        {
            if (cluburi_dataGridView.SelectedRows.Count > 0)
            {
                int idClub = int.Parse(cluburi_dataGridView.SelectedRows[0].Cells[0].Value.ToString());
                serviceFotbal.DeleteClub(idClub);
                updateCluburiDataGridView();
            }
            else
            {
                MessageBox.Show("Selectati un club!");
            }
        }*/
    }
}
