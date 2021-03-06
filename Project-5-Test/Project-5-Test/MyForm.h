#pragma once

#include "iostream"
#include <stdio.h>
#include <tchar.h>
#include "PointClass.h"

namespace Project5Test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	int* Points = new int[100]; 
	int i = 0;
	int x = 1;
	int y = 1;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected: 

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(761, 457);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"�����";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(578, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(258, 439);
			this->dataGridView1->TabIndex = 1;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(560, 439);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(848, 492);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->Text = L"Drawing Points";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				delete [] Points;
				Close();
			 }
	private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				x = e->X;
				y = e->Y;
				string pointName;
				string address;

				pointName = "A" + toString(i) + " ";
				address = toString(&Points[i]);

				dataGridView1->RowCount += 1;
				
				dataGridView1[0, dataGridView1->RowCount - 1]->Value = gcnew System::String(pointName.c_str());
				dataGridView1[1, dataGridView1->RowCount - 1]->Value = x;
				dataGridView1[2, dataGridView1->RowCount - 1]->Value = y;
				dataGridView1[3, dataGridView1->RowCount - 1]->Value = gcnew System::String(address.c_str());

				// Drawing:
				//Graphics^ g = CreateGraphics();
				//g->FillRectangle(Brushes::Black, x, y, 1, 1);
				
				//pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);

				pictureBox1->Refresh();

				i += 1;
			 }
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				dataGridView1->ColumnCount = 4;
				dataGridView1->RowCount = 0;

				DataGridViewColumn^ column0 = dataGridView1->Columns[0];
				column0->Width = 40;
				column0->HeaderText = "���";
				DataGridViewColumn^ column1 = dataGridView1->Columns[1];
				column1->Width = 50;
				column1->HeaderText = "x";
				DataGridViewColumn^ column2 = dataGridView1->Columns[2];
				column2->Width = 50;
				column2->HeaderText = "y";
				DataGridViewColumn^ column3 = dataGridView1->Columns[3];
				column3->Width = 90;
				column3->HeaderText = "�����";
			 }
private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 Graphics^ g = e->Graphics;
			 g->FillRectangle(Brushes::Black, x - 1, y - 1, 4, 4);
			 g->DrawString(gcnew System::String(("A" + toString(i)).c_str()), gcnew System::Drawing::Font("Arial", 11), System::Drawing::Brushes::Blue, Point(x, y));
		 }
};
}
