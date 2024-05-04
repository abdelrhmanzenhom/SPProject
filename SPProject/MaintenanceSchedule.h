#pragma once
#include "Parts.h"
#include "Service.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <msclr\marshal_cppstd.h>
#define MAX_NUM_OF_ITEMS 15
#define MAINTENANCE_FILE "MaintenanceSchedule.txt"


struct MaintenanceStruct
{
	std::string* models;
	int* years;
	int mileage;
	std::string unit;
	int months;
	std::string* part;
	std::string* service;
	int size[4];
};

namespace Motor_Vehicle_Service_Win {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;


	/// <summary>
	/// Summary for MaintenanceSchedule
	/// </summary>
	public ref class MaintenanceSchedule : public System::Windows::Forms::Form
	{
	public:
		MaintenanceSchedule(void)
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
		~MaintenanceSchedule()
		{
			if (components)
			{
				delete components;
			}
		}
	private: int startIndex = 0, endIndex = 0;
	private: int itemCounter = 0;
	private: MaintenanceStruct* maintenanceArray;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ searchBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ returnButton;
	private: System::Windows::Forms::Button^ deleteButton;
	private: System::Windows::Forms::Button^ addButton;
	private: Dictionary<int, int>^ indicesDictionary = gcnew Dictionary<int, int>();



	private: System::Windows::Forms::Button^ deleteItemButton;
	private: System::Windows::Forms::Button^ addItemButton;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ carModel;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ carYear;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ vehicleMileage;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ vehicleUnit;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ vehicleMonths;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ vehicleParts;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ vehicleService;

























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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->searchBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->carModel = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->carYear = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->vehicleMileage = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->vehicleUnit = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->vehicleMonths = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->vehicleParts = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->vehicleService = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->deleteItemButton = (gcnew System::Windows::Forms::Button());
			this->addItemButton = (gcnew System::Windows::Forms::Button());
			this->returnButton = (gcnew System::Windows::Forms::Button());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel1->Controls->Add(this->searchBox);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(982, 52);
			this->panel1->TabIndex = 0;
			// 
			// searchBox
			// 
			this->searchBox->Location = System::Drawing::Point(85, 15);
			this->searchBox->Name = L"searchBox";
			this->searchBox->Size = System::Drawing::Size(866, 22);
			this->searchBox->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Search:";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->dataGridView1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 52);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(982, 318);
			this->panel2->TabIndex = 1;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ControlLightLight;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->carModel,
					this->carYear, this->vehicleMileage, this->vehicleUnit, this->vehicleMonths, this->vehicleParts, this->vehicleService
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(982, 318);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellFormatting += gcnew System::Windows::Forms::DataGridViewCellFormattingEventHandler(this, &MaintenanceSchedule::dataGridView1_CellFormatting);
			this->dataGridView1->CellPainting += gcnew System::Windows::Forms::DataGridViewCellPaintingEventHandler(this, &MaintenanceSchedule::dataGridView1_CellPainting);
			// 
			// carModel
			// 
			this->carModel->HeaderText = L"Model";
			this->carModel->MinimumWidth = 6;
			this->carModel->Name = L"carModel";
			this->carModel->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// carYear
			// 
			this->carYear->HeaderText = L"Year";
			this->carYear->MinimumWidth = 6;
			this->carYear->Name = L"carYear";
			this->carYear->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// vehicleMileage
			// 
			this->vehicleMileage->HeaderText = L"Mileage";
			this->vehicleMileage->MinimumWidth = 6;
			this->vehicleMileage->Name = L"vehicleMileage";
			this->vehicleMileage->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// vehicleUnit
			// 
			this->vehicleUnit->HeaderText = L"Unit";
			this->vehicleUnit->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"KM", L"Mile" });
			this->vehicleUnit->MinimumWidth = 6;
			this->vehicleUnit->Name = L"vehicleUnit";
			// 
			// vehicleMonths
			// 
			this->vehicleMonths->HeaderText = L"Months";
			this->vehicleMonths->MinimumWidth = 6;
			this->vehicleMonths->Name = L"vehicleMonths";
			this->vehicleMonths->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// vehicleParts
			// 
			this->vehicleParts->HeaderText = L"Parts";
			this->vehicleParts->MinimumWidth = 6;
			this->vehicleParts->Name = L"vehicleParts";
			this->vehicleParts->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// vehicleService
			// 
			this->vehicleService->HeaderText = L"Service";
			this->vehicleService->MinimumWidth = 6;
			this->vehicleService->Name = L"vehicleService";
			this->vehicleService->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel3->Controls->Add(this->deleteItemButton);
			this->panel3->Controls->Add(this->addItemButton);
			this->panel3->Controls->Add(this->returnButton);
			this->panel3->Controls->Add(this->deleteButton);
			this->panel3->Controls->Add(this->addButton);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 370);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(982, 83);
			this->panel3->TabIndex = 1;
			// 
			// deleteItemButton
			// 
			this->deleteItemButton->Location = System::Drawing::Point(531, 41);
			this->deleteItemButton->Name = L"deleteItemButton";
			this->deleteItemButton->Size = System::Drawing::Size(105, 30);
			this->deleteItemButton->TabIndex = 4;
			this->deleteItemButton->Text = L"Delete Item";
			this->deleteItemButton->UseVisualStyleBackColor = true;
			this->deleteItemButton->Click += gcnew System::EventHandler(this, &MaintenanceSchedule::deleteItemButton_Click);
			// 
			// addItemButton
			// 
			this->addItemButton->Location = System::Drawing::Point(347, 41);
			this->addItemButton->Name = L"addItemButton";
			this->addItemButton->Size = System::Drawing::Size(105, 30);
			this->addItemButton->TabIndex = 3;
			this->addItemButton->Text = L"Add Item";
			this->addItemButton->UseVisualStyleBackColor = true;
			this->addItemButton->Click += gcnew System::EventHandler(this, &MaintenanceSchedule::addItemButton_Click);
			// 
			// returnButton
			// 
			this->returnButton->Location = System::Drawing::Point(15, 16);
			this->returnButton->Name = L"returnButton";
			this->returnButton->Size = System::Drawing::Size(105, 30);
			this->returnButton->TabIndex = 2;
			this->returnButton->Text = L"Go Back";
			this->returnButton->UseVisualStyleBackColor = true;
			this->returnButton->Click += gcnew System::EventHandler(this, &MaintenanceSchedule::returnButton_Click);
			// 
			// deleteButton
			// 
			this->deleteButton->Location = System::Drawing::Point(531, 5);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(105, 30);
			this->deleteButton->TabIndex = 1;
			this->deleteButton->Text = L"Delete";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &MaintenanceSchedule::deleteButton_Click);
			// 
			// addButton
			// 
			this->addButton->Location = System::Drawing::Point(347, 5);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(105, 30);
			this->addButton->TabIndex = 0;
			this->addButton->Text = L"Add";
			this->addButton->UseVisualStyleBackColor = true;
			this->addButton->Click += gcnew System::EventHandler(this, &MaintenanceSchedule::addButton_Click);
			// 
			// MaintenanceSchedule
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(982, 453);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->Name = L"MaintenanceSchedule";
			this->Text = L"MaintenanceSchedule";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MaintenanceSchedule::MaintenanceSchedule_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MaintenanceSchedule::MaintenanceSchedule_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: Void addItemButton_Click(System::Object^ sender, System::EventArgs^ e);
private: Void deleteItemButton_Click(System::Object^ sender, System::EventArgs^ e);
private: Void addButton_Click(System::Object^ sender, System::EventArgs^ e);
private: Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e);
private: Void returnButton_Click(System::Object^ sender, System::EventArgs^ e);
private: Void HandleDeletionInDictionary(int index);
private: int FindKey(int index);
private: Void dataGridView1_CellPainting(System::Object^ sender, System::Windows::Forms::DataGridViewCellPaintingEventArgs^ e);
private: Void dataGridView1_CellFormatting(System::Object^ sender, System::Windows::Forms::DataGridViewCellFormattingEventArgs^ e);
private: Void MaintenanceSchedule_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
private: void SaveMaintenanceInFile(MaintenanceStruct maintenanceArray[], int size, const std::string& filename);
private: void DeleteFileContent(const std::string& filename);
private: void ReadMaintenanceFromFile(int numOfRows);
private: int GetNumberOfLines();
private: Void MaintenanceSchedule_Load(System::Object^ sender, System::EventArgs^ e);
};
}
