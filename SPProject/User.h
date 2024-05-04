#pragma once
#include<string>
#include <fstream>
#include "Parts.h"
#include "Service.h"
#include "MaintenanceSchedule.h"
#include "Tax.h"
#include <msclr\marshal_cppstd.h>
using namespace std;
using namespace System;
public struct Admin
{
public:
	int id;
	string 	user_name;
	string	address;
	int phone_Number;
	int autoid();
	Admin();
	Admin(string user_name, string addr);
	void sign_up(System::String^ s1, System::String^ s2);
	bool login(std::string s3, std::string s4);


};
namespace Motor_Vehicle_Service_Win {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// Summary for User
	/// </summary>
	public ref class User : public System::Windows::Forms::Form
	{
	public:
		User(void)
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
		~User()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:










	private: System::Windows::Forms::Panel^ SignUpPanel;
	private: System::Windows::Forms::Panel^ signup;
	private: System::Windows::Forms::Button^ button59;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::TextBox^ user_name_signup;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ pass_signup;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ sign_up;
	private: System::Windows::Forms::Panel^ SignInPanel;
	private: System::Windows::Forms::Panel^ sign;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::TextBox^ use_name_signin;
	private: System::Windows::Forms::TextBox^ pass_signin;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ Signin;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Panel^ HomeAdmin;
	private: System::Windows::Forms::Button^ Changetax;

	private: System::Windows::Forms::Button^ Addschedule;
	private: System::Windows::Forms::Button^ Addservice;
	private: System::Windows::Forms::Button^ Addpart;
	private: System::Windows::Forms::Panel^ Taxpanel;
	private: System::Windows::Forms::Button^ returnButton;
	private: System::Windows::Forms::Button^ updateButton;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ taxBox;
















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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(User::typeid));
			this->SignUpPanel = (gcnew System::Windows::Forms::Panel());
			this->signup = (gcnew System::Windows::Forms::Panel());
			this->button59 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->user_name_signup = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->pass_signup = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->sign_up = (gcnew System::Windows::Forms::Button());
			this->SignInPanel = (gcnew System::Windows::Forms::Panel());
			this->sign = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->use_name_signin = (gcnew System::Windows::Forms::TextBox());
			this->pass_signin = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Signin = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->HomeAdmin = (gcnew System::Windows::Forms::Panel());
			this->Changetax = (gcnew System::Windows::Forms::Button());
			this->Addschedule = (gcnew System::Windows::Forms::Button());
			this->Addservice = (gcnew System::Windows::Forms::Button());
			this->Addpart = (gcnew System::Windows::Forms::Button());
			this->Taxpanel = (gcnew System::Windows::Forms::Panel());
			this->returnButton = (gcnew System::Windows::Forms::Button());
			this->updateButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->taxBox = (gcnew System::Windows::Forms::TextBox());
			this->SignUpPanel->SuspendLayout();
			this->signup->SuspendLayout();
			this->SignInPanel->SuspendLayout();
			this->sign->SuspendLayout();
			this->HomeAdmin->SuspendLayout();
			this->Taxpanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// SignUpPanel
			// 
			this->SignUpPanel->Controls->Add(this->signup);
			this->SignUpPanel->Location = System::Drawing::Point(135, 12);
			this->SignUpPanel->Name = L"SignUpPanel";
			this->SignUpPanel->Size = System::Drawing::Size(1061, 585);
			this->SignUpPanel->TabIndex = 3;
			// 
			// signup
			// 
			this->signup->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"signup.BackgroundImage")));
			this->signup->Controls->Add(this->button59);
			this->signup->Controls->Add(this->button4);
			this->signup->Controls->Add(this->panel7);
			this->signup->Controls->Add(this->user_name_signup);
			this->signup->Controls->Add(this->label8);
			this->signup->Controls->Add(this->panel2);
			this->signup->Controls->Add(this->pass_signup);
			this->signup->Controls->Add(this->label7);
			this->signup->Controls->Add(this->label3);
			this->signup->Controls->Add(this->sign_up);
			this->signup->Location = System::Drawing::Point(15, 23);
			this->signup->Name = L"signup";
			this->signup->Size = System::Drawing::Size(937, 482);
			this->signup->TabIndex = 2;
			// 
			// button59
			// 
			this->button59->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button59->FlatAppearance->BorderSize = 0;
			this->button59->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button59->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button59->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button59->Location = System::Drawing::Point(980, -3);
			this->button59->Name = L"button59";
			this->button59->Size = System::Drawing::Size(18, 18);
			this->button59->TabIndex = 44;
			this->button59->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Black;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F));
			this->button4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button4->Location = System::Drawing::Point(151, 427);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(117, 35);
			this->button4->TabIndex = 43;
			this->button4->Text = L"Sign in";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &User::button4_Click);
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::White;
			this->panel7->Location = System::Drawing::Point(23, 270);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(272, 2);
			this->panel7->TabIndex = 41;
			// 
			// user_name_signup
			// 
			this->user_name_signup->BackColor = System::Drawing::Color::Black;
			this->user_name_signup->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->user_name_signup->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.75F));
			this->user_name_signup->ForeColor = System::Drawing::SystemColors::Window;
			this->user_name_signup->Location = System::Drawing::Point(21, 245);
			this->user_name_signup->Name = L"user_name_signup";
			this->user_name_signup->Size = System::Drawing::Size(271, 24);
			this->user_name_signup->TabIndex = 40;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.75F));
			this->label8->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label8->Location = System::Drawing::Point(22, 222);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(75, 20);
			this->label8->TabIndex = 39;
			this->label8->Text = L"Username";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Location = System::Drawing::Point(23, 335);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(272, 2);
			this->panel2->TabIndex = 38;
			// 
			// pass_signup
			// 
			this->pass_signup->BackColor = System::Drawing::Color::Black;
			this->pass_signup->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pass_signup->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.75F));
			this->pass_signup->ForeColor = System::Drawing::SystemColors::Window;
			this->pass_signup->Location = System::Drawing::Point(23, 308);
			this->pass_signup->Name = L"pass_signup";
			this->pass_signup->PasswordChar = '*';
			this->pass_signup->Size = System::Drawing::Size(271, 24);
			this->pass_signup->TabIndex = 37;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.75F));
			this->label7->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label7->Location = System::Drawing::Point(20, 288);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(72, 20);
			this->label7->TabIndex = 36;
			this->label7->Text = L"password";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->ImageKey = L"(none)";
			this->label3->Location = System::Drawing::Point(17, 173);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 17);
			this->label3->TabIndex = 27;
			this->label3->Text = L"Sign up";
			// 
			// sign_up
			// 
			this->sign_up->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->sign_up->FlatAppearance->BorderSize = 0;
			this->sign_up->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sign_up->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F));
			this->sign_up->ForeColor = System::Drawing::Color::White;
			this->sign_up->Location = System::Drawing::Point(23, 427);
			this->sign_up->Name = L"sign_up";
			this->sign_up->Size = System::Drawing::Size(117, 35);
			this->sign_up->TabIndex = 42;
			this->sign_up->Text = L"SignUp";
			this->sign_up->UseVisualStyleBackColor = false;
			this->sign_up->Click += gcnew System::EventHandler(this, &User::sign_up_Click);
			// 
			// SignInPanel
			// 
			this->SignInPanel->Controls->Add(this->sign);
			this->SignInPanel->Location = System::Drawing::Point(36, 32);
			this->SignInPanel->Name = L"SignInPanel";
			this->SignInPanel->Size = System::Drawing::Size(1100, 547);
			this->SignInPanel->TabIndex = 46;
			// 
			// sign
			// 
			this->sign->AutoScroll = true;
			this->sign->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sign.BackgroundImage")));
			this->sign->Controls->Add(this->button1);
			this->sign->Controls->Add(this->button3);
			this->sign->Controls->Add(this->panel5);
			this->sign->Controls->Add(this->panel6);
			this->sign->Controls->Add(this->use_name_signin);
			this->sign->Controls->Add(this->pass_signin);
			this->sign->Controls->Add(this->label4);
			this->sign->Controls->Add(this->label5);
			this->sign->Controls->Add(this->Signin);
			this->sign->Controls->Add(this->button5);
			this->sign->Location = System::Drawing::Point(19, 26);
			this->sign->Name = L"sign";
			this->sign->Size = System::Drawing::Size(1207, 634);
			this->sign->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Location = System::Drawing::Point(982, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(18, 18);
			this->button1->TabIndex = 20;
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Black;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F));
			this->button3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button3->Location = System::Drawing::Point(149, 386);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(122, 35);
			this->button3->TabIndex = 18;
			this->button3->Text = L"SignUp";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &User::button3_Click_1);
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::White;
			this->panel5->Location = System::Drawing::Point(21, 352);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(272, 2);
			this->panel5->TabIndex = 16;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::White;
			this->panel6->Location = System::Drawing::Point(22, 291);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(272, 2);
			this->panel6->TabIndex = 15;
			// 
			// use_name_signin
			// 
			this->use_name_signin->BackColor = System::Drawing::Color::Black;
			this->use_name_signin->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->use_name_signin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.75F));
			this->use_name_signin->ForeColor = System::Drawing::SystemColors::Window;
			this->use_name_signin->Location = System::Drawing::Point(23, 266);
			this->use_name_signin->Name = L"use_name_signin";
			this->use_name_signin->Size = System::Drawing::Size(271, 24);
			this->use_name_signin->TabIndex = 14;
			// 
			// pass_signin
			// 
			this->pass_signin->BackColor = System::Drawing::Color::Black;
			this->pass_signin->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pass_signin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.75F));
			this->pass_signin->ForeColor = System::Drawing::SystemColors::Window;
			this->pass_signin->Location = System::Drawing::Point(22, 327);
			this->pass_signin->Name = L"pass_signin";
			this->pass_signin->PasswordChar = '*';
			this->pass_signin->Size = System::Drawing::Size(271, 24);
			this->pass_signin->TabIndex = 19;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.75F));
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label4->Location = System::Drawing::Point(20, 304);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(70, 20);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Password";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.75F));
			this->label5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label5->Location = System::Drawing::Point(20, 246);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(75, 20);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Username";
			// 
			// Signin
			// 
			this->Signin->AutoSize = true;
			this->Signin->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->Signin->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Signin->ImageKey = L"(none)";
			this->Signin->Location = System::Drawing::Point(17, 193);
			this->Signin->Name = L"Signin";
			this->Signin->Size = System::Drawing::Size(48, 17);
			this->Signin->TabIndex = 11;
			this->Signin->Text = L"Sign in";
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F));
			this->button5->ForeColor = System::Drawing::Color::White;
			this->button5->Location = System::Drawing::Point(21, 386);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(122, 35);
			this->button5->TabIndex = 17;
			this->button5->Text = L"Sign In";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &User::button5_Click_1);
			// 
			// HomeAdmin
			// 
			this->HomeAdmin->Controls->Add(this->Changetax);
			this->HomeAdmin->Controls->Add(this->Addschedule);
			this->HomeAdmin->Controls->Add(this->Addservice);
			this->HomeAdmin->Controls->Add(this->Addpart);
			this->HomeAdmin->Location = System::Drawing::Point(9, 14);
			this->HomeAdmin->Name = L"HomeAdmin";
			this->HomeAdmin->Size = System::Drawing::Size(409, 424);
			this->HomeAdmin->TabIndex = 47;
			// 
			// Changetax
			// 
			this->Changetax->Location = System::Drawing::Point(44, 269);
			this->Changetax->Name = L"Changetax";
			this->Changetax->Size = System::Drawing::Size(75, 23);
			this->Changetax->TabIndex = 3;
			this->Changetax->Text = L"tax";
			this->Changetax->UseVisualStyleBackColor = true;
			this->Changetax->Click += gcnew System::EventHandler(this, &User::Changetax_Click);
			// 
			// Addschedule
			// 
			this->Addschedule->Location = System::Drawing::Point(35, 194);
			this->Addschedule->Name = L"Addschedule";
			this->Addschedule->Size = System::Drawing::Size(139, 23);
			this->Addschedule->TabIndex = 2;
			this->Addschedule->Text = L"Maintenance Schedule";
			this->Addschedule->UseVisualStyleBackColor = true;
			this->Addschedule->Click += gcnew System::EventHandler(this, &User::Addschedule_Click);
			// 
			// Addservice
			// 
			this->Addservice->Location = System::Drawing::Point(45, 124);
			this->Addservice->Name = L"Addservice";
			this->Addservice->Size = System::Drawing::Size(75, 23);
			this->Addservice->TabIndex = 1;
			this->Addservice->Text = L"services";
			this->Addservice->UseVisualStyleBackColor = true;
			this->Addservice->Click += gcnew System::EventHandler(this, &User::Addservice_Click);
			// 
			// Addpart
			// 
			this->Addpart->Location = System::Drawing::Point(60, 48);
			this->Addpart->Name = L"Addpart";
			this->Addpart->Size = System::Drawing::Size(75, 23);
			this->Addpart->TabIndex = 0;
			this->Addpart->Text = L"parts";
			this->Addpart->UseVisualStyleBackColor = true;
			this->Addpart->Click += gcnew System::EventHandler(this, &User::Addpart_Click);
			// 
			// Taxpanel
			// 
			this->Taxpanel->Controls->Add(this->returnButton);
			this->Taxpanel->Controls->Add(this->updateButton);
			this->Taxpanel->Controls->Add(this->label2);
			this->Taxpanel->Controls->Add(this->label1);
			this->Taxpanel->Controls->Add(this->taxBox);
			this->Taxpanel->Location = System::Drawing::Point(526, 4);
			this->Taxpanel->Name = L"Taxpanel";
			this->Taxpanel->Size = System::Drawing::Size(382, 378);
			this->Taxpanel->TabIndex = 48;
			// 
			// returnButton
			// 
			this->returnButton->Location = System::Drawing::Point(140, 160);
			this->returnButton->Name = L"returnButton";
			this->returnButton->Size = System::Drawing::Size(120, 23);
			this->returnButton->TabIndex = 9;
			this->returnButton->Text = L"Go Back";
			this->returnButton->UseVisualStyleBackColor = true;
			// 
			// updateButton
			// 
			this->updateButton->Location = System::Drawing::Point(140, 116);
			this->updateButton->Name = L"updateButton";
			this->updateButton->Size = System::Drawing::Size(120, 23);
			this->updateButton->TabIndex = 8;
			this->updateButton->Text = L"Update";
			this->updateButton->UseVisualStyleBackColor = true;
			this->updateButton->Click += gcnew System::EventHandler(this, &User::updateButton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(271, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(22, 17);
			this->label2->TabIndex = 7;
			this->label2->Text = L"%";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(47, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 17);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Tax Percentage";
			// 
			// taxBox
			// 
			this->taxBox->Location = System::Drawing::Point(160, 28);
			this->taxBox->Name = L"taxBox";
			this->taxBox->Size = System::Drawing::Size(88, 24);
			this->taxBox->TabIndex = 5;
			// 
			// User
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1226, 604);
			this->Controls->Add(this->Taxpanel);
			this->Controls->Add(this->HomeAdmin);
			this->Controls->Add(this->SignInPanel);
			this->Controls->Add(this->SignUpPanel);
			this->Name = L"User";
			this->Text = L"User";
			this->SignUpPanel->ResumeLayout(false);
			this->signup->ResumeLayout(false);
			this->signup->PerformLayout();
			this->SignInPanel->ResumeLayout(false);
			this->sign->ResumeLayout(false);
			this->sign->PerformLayout();
			this->HomeAdmin->ResumeLayout(false);
			this->Taxpanel->ResumeLayout(false);
			this->Taxpanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	

}
private: System::Void sign_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
SignInPanel->BringToFront();
}
private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e) {
	SignUpPanel->BringToFront();
}
private: System::Void sign_up_Click(System::Object^ sender, System::EventArgs^ e) {
	Admin admin;

	System::String^ name = user_name_signup->Text->Trim();
	System::String^ password = pass_signup->Text;

	std::string name2 = msclr::interop::marshal_as<std::string>(name);
	std::string password2 = msclr::interop::marshal_as<std::string>(password);

	if (name == "" || password == "")
	{
		MessageBox::Show("You must fill all fields", "Error");
	}
	else
	{

		bool usernameExists = false;
		int id;
		std::string n, p;
		std::ifstream input("log.txt");
		while (input >> n >> p >> id)
		{
			if (n == name2)
			{
				usernameExists = true;
				break;
			}
		}
		input.close();

		if (usernameExists)
		{
			MessageBox::Show("This username is already taken", "Error");
		}
		else
		{
			admin.sign_up(name, password);
			SignInPanel->BringToFront();
		}

	}
}
private: System::Void button5_Click_1(System::Object^ sender, System::EventArgs^ e) {
	Admin admin;
	System::String^ name = use_name_signin->Text->Trim();
	System::String^ password = pass_signin->Text;
	string signinname = msclr::interop::marshal_as<std::string>(name);
	string signinpass = msclr::interop::marshal_as<std::string>(password);

	if (signinname == "" || signinpass == "")
	{
		MessageBox::Show("You must fill all fields", "Error");
	}
	else
	{

		if (admin.login(signinname, signinpass))
		{
			MessageBox::Show("Login success", "Error");

			panel5->BringToFront();

		}
		else
		{
			MessageBox::Show("user name or password are wrong", "Error");

		}
	}
}
private: System::Void Addpart_Click(System::Object^ sender, System::EventArgs^ e) {
	Motor_Vehicle_Service_Win::Parts^ partsForm = gcnew Motor_Vehicle_Service_Win::Parts();

	// Display the Parts form
	partsForm->Show();
}
private: System::Void Addservice_Click(System::Object^ sender, System::EventArgs^ e) {
	Motor_Vehicle_Service_Win::Service^ serviceForm = gcnew Motor_Vehicle_Service_Win::Service();

	// Display the Parts form
	serviceForm->Show();
}
private: System::Void Addschedule_Click(System::Object^ sender, System::EventArgs^ e) {

	Motor_Vehicle_Service_Win::MaintenanceSchedule^ scheduleForm = gcnew Motor_Vehicle_Service_Win::MaintenanceSchedule();

	// Display the Parts form
	scheduleForm->Show();
}
private: System::Void Changetax_Click(System::Object^ sender, System::EventArgs^ e) {
	Motor_Vehicle_Service_Win::Tax^ taxForm = gcnew Motor_Vehicle_Service_Win::Tax();

	// Display the Parts form
	taxForm->Show();
}
private: System::Void updateButton_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
