#include "UserVehicle.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace Motor_Vehicle_Service_Win;

Void UserVehicle::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	// Reading user input
	String^ model = textBox1->Text;
	String^ year = textBox2->Text;
	String^ mileage = textBox3->Text;
	String^ months = textBox4->Text;

	// flags for data validation
	bool isDataFilled = true;
	bool isDataTypeCorrect = true;
	bool isDataValueCorrect = true;
	int value;
	String^ errorMessage;

	/*
	* Data validation check based on
	*  - Emptiness/Nulls
	*  - Numeric values
	*  - Possible values for each data
	*/
	for (int i = 0; i < 4; i++)
	{
		if (String::IsNullOrEmpty(textBoxArray[i]->Text))
		{
			MessageBox::Show("Please fill in the missing data.");
			isDataFilled = false;
			break;
		}
		if (!Int32::TryParse(textBoxArray[i]->Text, value) && (i != 0))
		{
			errorMessage = labelArray[i]->Text + " can only contain numeric values";
			MessageBox::Show(errorMessage, "Invalid Data Type");
			isDataTypeCorrect = false;
			break;
		}
		else if (Int32::TryParse(textBoxArray[i]->Text, value) && i != 0)
		{
			if (i == 1 && (value < 1884 || value > 2024))
			{
				errorMessage = labelArray[i]->Text + " can only contain values from 1884 to 2024";
				MessageBox::Show(errorMessage, "Invalid Data Range");
				isDataValueCorrect = false;
				break;
			}

			if (i == 2 && (value <= 0))
			{
				errorMessage = labelArray[i]->Text + " can only contain positive values";
				MessageBox::Show(errorMessage, "Invalid Data Range");
				isDataValueCorrect = false;
				break;
			}

			if (i == 3 && (value < 1 || value > 12))
			{
				errorMessage = labelArray[i]->Text + " can only contain values from 1 to 12";
				MessageBox::Show(errorMessage, "Invalid Data Range");
				isDataValueCorrect = false;
				break;
			}
		}
	}

}