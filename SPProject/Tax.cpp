#include "User.h"
#define TAX_FILE "tax.txt"
using namespace Motor_Vehicle_Service_Win;

int Tax::CheckValidityOfTax()
{
	int value;
	if (!Int32::TryParse(taxBox->Text, value) || value < 0)
	{
		MessageBox::Show("Please enter a numeric non-negative integer number");
		return -1;
	}
	return value;
}
#pragma region Buttons

Void Tax::updateButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	int value = CheckValidityOfTax();
	if (value == -1)
	{
		return;
	}
	tax = value;
	DeleteFileContent(TAX_FILE);
	SaveTaxInFile(TAX_FILE);
	MessageBox::Show("Tax updated successfully.", "Tax Update");
}

Void Tax::returnButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

#pragma endregion

#pragma region Form Behaviours

Void Tax::Tax_Load(System::Object^ sender, System::EventArgs^ e)
{
	ReadTaxFromFile();
	taxBox->Text = tax.ToString();
	// To remove selection
	taxBox->Select(0, 0);
}
#pragma endregion

#pragma region Files

void Tax::SaveTaxInFile(const std::string& filename)
{
	std::ofstream input;
	input.open(filename, std::ofstream::app);
	input << tax;
	input.close();
}

void Tax::DeleteFileContent(const std::string& filename)
{
	std::ofstream file(filename, std::ofstream::trunc);
	if (!file.is_open()) {
		return;
	}
	file.close();
}

void Tax::ReadTaxFromFile()
{
	std::ifstream my_file(TAX_FILE);
	if (!my_file)
		return;
	std::string line;
	while (std::getline(my_file, line))
	{
		tax = std::stoi(line);
	}
	my_file.close();
}
#pragma endregion
