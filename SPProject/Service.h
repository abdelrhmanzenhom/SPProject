#pragma once
#include <iostream>
#include <fstream>
#include <msclr\marshal_cppstd.h>
#define SERVICE_FILE "service.txt"

public struct ServiceStruct
{
	std::string name;
	double price;
};

namespace Motor_Vehicle_Service_Win {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for Service
	/// </summary>
	public ref class Service : public System::Windows::Forms::Form
	{
	public:
		Service(void)
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
		~Service()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ServiceName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ServicePrice;
	private: System::Windows::Forms::Button^ addButton;
	private: System::Windows::Forms::Button^ deleteButton;


	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ searchBox;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ returnButton;

	public: ServiceStruct* servicesArray;
	public: int numOfServiceRows;
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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ServiceName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ServicePrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->searchBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->returnButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ControlLightLight;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->ServiceName,
					this->ServicePrice
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(859, 356);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->AllowUserToAddRowsChanged += gcnew System::EventHandler(this, &Service::addButton_Click);
			this->dataGridView1->AllowUserToDeleteRowsChanged += gcnew System::EventHandler(this, &Service::deleteButton_Click);
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Service::dataGridView1_CellContentClick);
			this->dataGridView1->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Service::dataGridView1_CellValueChanged);
			// 
			// ServiceName
			// 
			this->ServiceName->HeaderText = L"Name";
			this->ServiceName->MinimumWidth = 6;
			this->ServiceName->Name = L"ServiceName";
			// 
			// ServicePrice
			// 
			this->ServicePrice->HeaderText = L"Price";
			this->ServicePrice->MinimumWidth = 6;
			this->ServicePrice->Name = L"ServicePrice";
			// 
			// addButton
			// 
			this->addButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->addButton->Location = System::Drawing::Point(317, 13);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(66, 23);
			this->addButton->TabIndex = 1;
			this->addButton->Text = L"Add";
			this->addButton->UseVisualStyleBackColor = true;
			this->addButton->Click += gcnew System::EventHandler(this, &Service::addButton_Click);
			// 
			// deleteButton
			// 
			this->deleteButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->deleteButton->Location = System::Drawing::Point(477, 13);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(66, 23);
			this->deleteButton->TabIndex = 2;
			this->deleteButton->Text = L"Delete";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &Service::deleteButton_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 49);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(859, 356);
			this->panel1->TabIndex = 3;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->searchBox);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(859, 49);
			this->panel2->TabIndex = 4;
			// 
			// searchBox
			// 
			this->searchBox->Location = System::Drawing::Point(76, 12);
			this->searchBox->Name = L"searchBox";
			this->searchBox->Size = System::Drawing::Size(756, 24);
			this->searchBox->TabIndex = 1;
			this->searchBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Service::searchBox_KeyPress);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(19, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Search:";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->returnButton);
			this->panel3->Controls->Add(this->addButton);
			this->panel3->Controls->Add(this->deleteButton);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 405);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(859, 48);
			this->panel3->TabIndex = 4;
			// 
			// returnButton
			// 
			this->returnButton->Location = System::Drawing::Point(10, 13);
			this->returnButton->Name = L"returnButton";
			this->returnButton->Size = System::Drawing::Size(66, 23);
			this->returnButton->TabIndex = 3;
			this->returnButton->Text = L"Go Back";
			this->returnButton->UseVisualStyleBackColor = true;
			this->returnButton->Click += gcnew System::EventHandler(this, &Service::returnButton_Click);
			// 
			// Service
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(859, 453);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel3);
			this->Name = L"Service";
			this->Text = L"Service";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Service::Service_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Service::Service_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: Void addButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: Void dataGridView1_CellValueChanged(System::Object^ sender, DataGridViewCellEventArgs^ e);
	private: Void searchBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	private: void DeleteFileContent(const std::string& filename);
	private: void ReadServiceFromFile(int numOfRows);
	private: void SaveServicesInFile(ServiceStruct servicesArray[], int size, const std::string& filename);
	private: int GetNumberOfLines();
	private: bool FillServicesArray(int numOfServiceRows);
	private: Void Service_Load(System::Object^ sender, System::EventArgs^ e);
	private: Void Service_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void returnButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
