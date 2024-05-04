#pragma once
#include <iostream>
#include <fstream>
#include <msclr\marshal_cppstd.h>

#define TAX_FILE "tax.txt"

namespace Motor_Vehicle_Service_Win {

	using namespace System;
	using namespace msclr::interop;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Tax
	/// </summary>
	public ref class Tax : public System::Windows::Forms::Form
	{
	public:
		Tax(void)
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
		~Tax()
		{
			if (components)
			{
				delete components;
			}
		}






	public: double tax;
	private: System::Windows::Forms::TextBox^ taxBox;
	public:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ updateButton;
	private: System::Windows::Forms::Button^ returnButton;
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
			this->taxBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->updateButton = (gcnew System::Windows::Forms::Button());
			this->returnButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// taxBox
			// 
			this->taxBox->Location = System::Drawing::Point(123, 56);
			this->taxBox->Name = L"taxBox";
			this->taxBox->Size = System::Drawing::Size(88, 24);
			this->taxBox->TabIndex = 0;
			this->taxBox->TextChanged += gcnew System::EventHandler(this, &Tax::taxBox_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 59);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Tax Percentage";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(234, 59);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(22, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"%";
			// 
			// updateButton
			// 
			this->updateButton->Location = System::Drawing::Point(103, 144);
			this->updateButton->Name = L"updateButton";
			this->updateButton->Size = System::Drawing::Size(120, 23);
			this->updateButton->TabIndex = 3;
			this->updateButton->Text = L"Update";
			this->updateButton->UseVisualStyleBackColor = true;
			this->updateButton->Click += gcnew System::EventHandler(this, &Tax::updateButton_Click);
			// 
			// returnButton
			// 
			this->returnButton->Location = System::Drawing::Point(103, 188);
			this->returnButton->Name = L"returnButton";
			this->returnButton->Size = System::Drawing::Size(120, 23);
			this->returnButton->TabIndex = 4;
			this->returnButton->Text = L"Go Back";
			this->returnButton->UseVisualStyleBackColor = true;
			this->returnButton->Click += gcnew System::EventHandler(this, &Tax::returnButton_Click);
			// 
			// Tax
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(326, 272);
			this->Controls->Add(this->returnButton);
			this->Controls->Add(this->updateButton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->taxBox);
			this->Name = L"Tax";
			this->Text = L"Tax";
			this->Load += gcnew System::EventHandler(this, &Tax::Tax_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: int CheckValidityOfTax();
	private: Void updateButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: void SaveTaxInFile(const std::string& filename);
	private: void DeleteFileContent(const std::string& filename);
	private: void ReadTaxFromFile();

	private: Void Tax_Load(System::Object^ sender, System::EventArgs^ e);
	private: Void returnButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void taxBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
