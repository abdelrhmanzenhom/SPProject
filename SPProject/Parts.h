#pragma once
#include <iostream>
#include <fstream>
#include <msclr\marshal_cppstd.h>
#include "Service.h"

#define PART_FILE "parts.txt"

public struct PartStruct
{
	std::string name;
	double cost;
	std::string models;
};

namespace Motor_Vehicle_Service_Win {
	using namespace System;
	using namespace msclr::interop;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Parts
	/// </summary>
	public ref class Parts : public System::Windows::Forms::Form
	{
	public:
		Parts(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Parts()
		{
			if (components)
			{
				delete components;
			}
		}
	// Variables
	public: PartStruct* partsArray;
	public: int numOfPartRows;
	private: System::Windows::Forms::Button^ addButton;
		   // Buttons

	private: System::Windows::Forms::Button^ deleteButton;


	// Panels

	private: System::Windows::Forms::Panel^ panel2;

	// DataGridView




	// Text boxes

	// Labels

	private: System::Windows::Forms::Button^ returnButton;
	private: System::Windows::Forms::TextBox^ searchBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PartName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PartPrice;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PartModel;
	private: System::Windows::Forms::Panel^ panel1;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->returnButton = (gcnew System::Windows::Forms::Button());
			this->searchBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->PartName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PartPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PartModel = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// addButton
			// 
			this->addButton->Location = System::Drawing::Point(299, 7);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(82, 32);
			this->addButton->TabIndex = 1;
			this->addButton->Text = L"Add";
			this->addButton->UseVisualStyleBackColor = true;
			this->addButton->Click += gcnew System::EventHandler(this, &Parts::addButton_Click);
			// 
			// deleteButton
			// 
			this->deleteButton->BackColor = System::Drawing::SystemColors::ControlLight;
			this->deleteButton->Location = System::Drawing::Point(478, 7);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(82, 32);
			this->deleteButton->TabIndex = 3;
			this->deleteButton->Text = L"Delete";
			this->deleteButton->UseVisualStyleBackColor = false;
			this->deleteButton->Click += gcnew System::EventHandler(this, &Parts::deleteButton_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->returnButton);
			this->panel2->Controls->Add(this->addButton);
			this->panel2->Controls->Add(this->deleteButton);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 371);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(859, 82);
			this->panel2->TabIndex = 8;
			// 
			// returnButton
			// 
			this->returnButton->Location = System::Drawing::Point(27, 23);
			this->returnButton->Name = L"returnButton";
			this->returnButton->Size = System::Drawing::Size(82, 32);
			this->returnButton->TabIndex = 4;
			this->returnButton->Text = L"Go Back";
			this->returnButton->UseVisualStyleBackColor = true;
			this->returnButton->Click += gcnew System::EventHandler(this, &Parts::returnButton_Click);
			// 
			// searchBox
			// 
			this->searchBox->Location = System::Drawing::Point(70, 12);
			this->searchBox->Name = L"searchBox";
			this->searchBox->Size = System::Drawing::Size(722, 24);
			this->searchBox->TabIndex = 9;
			this->searchBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Parts::searchBox_KeyPress);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(17, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 17);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Search:";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->label1);
			this->panel3->Controls->Add(this->searchBox);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel3->Location = System::Drawing::Point(0, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(859, 46);
			this->panel3->TabIndex = 11;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ControlLightLight;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->PartName,
					this->PartPrice, this->PartModel
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(859, 325);
			this->dataGridView1->TabIndex = 4;
			this->dataGridView1->AllowUserToAddRowsChanged += gcnew System::EventHandler(this, &Parts::addButton_Click);
			this->dataGridView1->AllowUserToDeleteRowsChanged += gcnew System::EventHandler(this, &Parts::deleteButton_Click);
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Parts::dataGridView1_CellContentClick);
			this->dataGridView1->CellFormatting += gcnew System::Windows::Forms::DataGridViewCellFormattingEventHandler(this, &Parts::dataGridView1_CellFormatting);
			this->dataGridView1->CellPainting += gcnew System::Windows::Forms::DataGridViewCellPaintingEventHandler(this, &Parts::dataGridView1_CellPainting);
			this->dataGridView1->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Parts::dataGridView1_CellValueChanged);
			// 
			// PartName
			// 
			this->PartName->HeaderText = L"Name";
			this->PartName->MinimumWidth = 6;
			this->PartName->Name = L"PartName";
			// 
			// PartPrice
			// 
			this->PartPrice->HeaderText = L"Price";
			this->PartPrice->MinimumWidth = 6;
			this->PartPrice->Name = L"PartPrice";
			// 
			// PartModel
			// 
			this->PartModel->HeaderText = L"Model";
			this->PartModel->MinimumWidth = 6;
			this->PartModel->Name = L"PartModel";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 46);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(859, 325);
			this->panel1->TabIndex = 7;
			// 
			// Parts
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(859, 453);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Name = L"Parts";
			this->Text = L"Parts";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Parts::Parts_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Parts::Parts_Load);
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	public: Void addButton_Click(System::Object^ sender, System::EventArgs^ e);
	public: Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e);
	public: Void dataGridView1_CellValueChanged(System::Object^ sender, DataGridViewCellEventArgs^ e);
	
	public: Void dataGridView1_CellPainting(System::Object^ sender, DataGridViewCellPaintingEventArgs^ e);
	public: Void dataGridView1_CellFormatting(System::Object^ sender, System::Windows::Forms::DataGridViewCellFormattingEventArgs^ e);
	
	public: bool IsTheSameCellValue(int column, int row);
	public: Void Parts_Load(System::Object^ sender, System::EventArgs^ e);
	public: Void Parts_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	
	public: int GetNumberOfLines();
	public: bool FillPartsArray(int numOfPartRows);
	public: void DeleteFileContent(const std::string& filename);
	public: void SavePartsInFile(PartStruct partsArray[], int size, const std::string& filename);
	public: void ReadPartsFromFile(int numOfRows);
	
	public: Void searchBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	
	public: Void returnButton_Click(System::Object^ sender, System::EventArgs^ e);
	public: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}
