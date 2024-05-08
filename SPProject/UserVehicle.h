#pragma once
#include "Service.h"
#include "Parts.h"
#include "MaintenanceSchedule.h"
#include "Tax.h"
#include <stdexcept> // Include the <stdexcept> header for std::invalid_argument
#include <vector>
#include <algorithm> // for std::remove
#include <string>
#include <sstream>
#include <iomanip>
#include <Windows.h>
#include <iostream> // Include the <iostream> header for input/output
#include <cctype> // For toupper function

public struct UserVehicleStruct
{
	std::string model;
	int year;
	int mileage;
	std::string unit;
	int months;
};

namespace Motor_Vehicle_Service_Win {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class UserVehicle : public System::Windows::Forms::Form
	{
	public:

		UserVehicle(void)
		{
			InitializeComponent();
			//Array of textboxes
			textBoxArray[0] = textBox1;
			textBoxArray[1] = textBox2;
			textBoxArray[2] = textBox3;
			textBoxArray[3] = textBox4;

			labelArray[0] = label2;
			labelArray[1] = label3;
			labelArray[2] = label4;
			labelArray[3] = label5;
			//this->Icon = gcnew System::Drawing::Icon("C:/Users/Dell/OneDrive/Desktop/Motor Vehicle Service.ico");

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UserVehicle()
		{
			if (components)
			{
				delete components;
			}
		}
	public: Parts^ partsInstance;
	public:	Service^ serviceInstance;
	public: MaintenanceSchedule^ maintenanceScheduleInstance;
	public: Tax^ taxInstance;
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ button1;
	private: array<TextBox^>^ textBoxArray = gcnew array<TextBox^>(4);
	private: array<Label^>^ labelArray = gcnew array<Label^>(4);
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ Outbutt;


	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->Outbutt = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(212, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Vehicle Details";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 67);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Model";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 110);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Year";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(10, 153);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 17);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Mileage";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(10, 239);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 17);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Months";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(85, 64);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(155, 24);
			this->textBox1->TabIndex = 5;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(85, 106);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(155, 24);
			this->textBox2->TabIndex = 6;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(85, 148);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(155, 24);
			this->textBox3->TabIndex = 7;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(85, 234);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(155, 24);
			this->textBox4->TabIndex = 8;
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Location = System::Drawing::Point(214, 301);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 33);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Enter";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UserVehicle::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"KM", L"Mile" });
			this->comboBox1->Location = System::Drawing::Point(85, 190);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(155, 24);
			this->comboBox1->TabIndex = 10;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(10, 196);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(32, 17);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Unit";
			// 
			// Outbutt
			// 
			this->Outbutt->Location = System::Drawing::Point(215, 357);
			this->Outbutt->Name = L"Outbutt";
			this->Outbutt->Size = System::Drawing::Size(74, 32);
			this->Outbutt->TabIndex = 12;
			this->Outbutt->Text = L"LogOut";
			this->Outbutt->UseVisualStyleBackColor = true;
			this->Outbutt->Click += gcnew System::EventHandler(this, &UserVehicle::Outbutt_Click);
			// 
			// UserVehicle
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(508, 421);
			this->Controls->Add(this->Outbutt);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"UserVehicle";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: bool dataValidation(bool, bool, bool);
	private: System::Void Outbutt_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};

}