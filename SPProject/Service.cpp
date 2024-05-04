#include "Service.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace Motor_Vehicle_Service_Win;

Void Service::addButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataGridView1->Rows->Add();
}

Void Service::deleteButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->Rows->Count > 0)
		dataGridView1->Rows->RemoveAt(dataGridView1->CurrentCell->RowIndex);
	else
		MessageBox::Show("No rows to be deleted.", "No Rows Exist");
}

Void Service::dataGridView1_CellValueChanged(System::Object^ sender, DataGridViewCellEventArgs^ e)
{
	double value;
	if (dataGridView1->Rows->Count > 0)
	{
		System::Object^ cell = dataGridView1->Rows[e->RowIndex]->Cells[1]->Value;
		if (cell != nullptr)
		{
			String^ text = dataGridView1->Rows[e->RowIndex]->Cells[1]->Value->ToString();
			Double::TryParse(text, value);
			if (e->ColumnIndex == 1 && (!Double::TryParse(text, value) || value <= 0))
			{
				MessageBox::Show("Please enter a positive numerical value.", "Price Error");
				dataGridView1->Rows[e->RowIndex]->Cells[1]->Value = nullptr;
			}
		}
		else
		{
			return;
		}
	}
}

Void Service::searchBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (dataGridView1->RowCount == 0)
	{
		MessageBox::Show("There's no data to be searched for.", "No Data Error");
		return;
	}

	if (e->KeyChar == (char)13)
	{
		dataGridView1->ClearSelection();
		String^ query = searchBox->Text;
		if (query->Equals(""))
		{
			MessageBox::Show("Please provide with a query.", "No Search Query Provided");
			return;
		}
		bool valueResult = false;
		for (int i = 0; i < dataGridView1->RowCount; i++)
		{
			for (int j = 0; j < dataGridView1->ColumnCount; j++)
			{
				if (dataGridView1->Rows[i]->Cells[j]->Value != nullptr &&
					dataGridView1->Rows[i]->Cells[j]->Value->ToString()->ToLower()->
					Contains(query->ToLower()))
				{
					dataGridView1->Rows[i]->Cells[j]->Selected = true;
					valueResult = true;
					break;
				}
			}

		}
		if (!valueResult)
		{
			MessageBox::Show("Unable to find: " + searchBox->Text, "Not Found");
			return;
		}
	}
}

#pragma region File Handling

int Service::GetNumberOfLines()
{
	{
		std::ifstream my_file(SERVICE_FILE);
		if (!my_file)
			return -1;
		int numOfRows = 0;
		std::string line;

		while (std::getline(my_file, line))
		{
			numOfRows++;
		}
		return numOfRows;
	}
}

void Service::DeleteFileContent(const std::string& filename)
{
	{
		std::ofstream file(filename, std::ofstream::trunc);
		if (!file.is_open()) {
			return;
		}
		file.close();
	}
}

void Service::SaveServicesInFile(ServiceStruct servicesArray[], int size, const std::string& filename)
{

	std::ofstream input;
	input.open(filename, std::ofstream::app);

	for (int i = 0; i < size; i++)
	{
		input << servicesArray[i].name << "\t";
		input << servicesArray[i].price << "\t";
		input << std::endl;
	}
	input.close();
}

void Service::ReadServiceFromFile(int numOfRows)
{
	std::ifstream my_file(SERVICE_FILE);
	if (!my_file)
		return;
	std::string line;


	servicesArray = new ServiceStruct[numOfRows];
	int index = 0;
	char* column;
	while (std::getline(my_file, line))
	{
		char* row = new char[line.size() + 1];
		std::strcpy(row, line.c_str());

		char* column = std::strtok(row, "\t");
		servicesArray[index].name = column;

		column = std::strtok(nullptr, "\t");
		servicesArray[index].price = std::stod(column);

		delete[] row; // Don't forget to free the memory
		index++;
	}
	// close the file
	my_file.close();
}
#pragma endregion

bool Service::FillServicesArray(int numOfServiceRows)
{

	double value;
	servicesArray = new ServiceStruct[numOfServiceRows];
	for (int i = 0; i < numOfServiceRows; i++)
	{
		if (dataGridView1->Rows[i]->Cells[0]->Value == nullptr ||
			dataGridView1->Rows[i]->Cells[1]->Value == nullptr)
		{
			MessageBox::Show("Please fill in missing data.", "Missing Cell Data");
			return false;
		}

		String^ name = dataGridView1->Rows[i]->Cells[0]->Value->ToString();
		Double::TryParse(dataGridView1->Rows[i]->Cells[1]->Value->ToString(), value);

		servicesArray[i].name = marshal_as<std::string>(name);
		servicesArray[i].price = value;
	}
	return true;
}
Void Service::Service_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	int numOfRows = dataGridView1->Rows->Count;
	if (numOfRows == 0)
	{
		DeleteFileContent(SERVICE_FILE);
		return;
	}
	bool isSuccessful = FillServicesArray(numOfRows);
	if (!isSuccessful)
	{
		e->Cancel = true;
	}
	DeleteFileContent(SERVICE_FILE);
	SaveServicesInFile(servicesArray, numOfRows, SERVICE_FILE);
}
Void Service::Service_Load(System::Object^ sender, System::EventArgs^ e)
{
	dataGridView1->AutoGenerateColumns = false;
	numOfServiceRows = GetNumberOfLines();
	ReadServiceFromFile(numOfServiceRows);
	for (int i = 0; i < numOfServiceRows; i++)
	{
		dataGridView1->Rows->Add();

		String^ name = marshal_as<System::String^>(servicesArray[i].name);

		dataGridView1->Rows[i]->Cells[0]->Value = name;
		dataGridView1->Rows[i]->Cells[1]->Value = servicesArray[i].price;
	}
}