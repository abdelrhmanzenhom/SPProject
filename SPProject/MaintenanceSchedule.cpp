#include "MaintenanceSchedule.h"
#include "Parts.h"
using namespace Motor_Vehicle_Service_Win;

#pragma region Tasks

// Check validity of each cell (not a number, wl gaw dah)

// save and read from files, what we could do with multiple values is use , or enclosings {}

// store it in an array

#pragma endregion

#pragma region Update Functions

Void MaintenanceSchedule::addButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->Rows->Count > 0)
	{
		for (int i = 0; i < 7; i++)
		{
			if (dataGridView1->Rows[dataGridView1->Rows->Count - 1]->Cells[i]->Value == nullptr)
			{
				MessageBox::Show("Please fill in missing data.", "Missing Cell Data");
				return;
			}
		}
		dataGridView1->Rows->Add();
	}
	else
	{
		dataGridView1->Rows->Add();
	}
}

Void MaintenanceSchedule::deleteButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->Rows->Count == 0)
	{
		MessageBox::Show("No rows to be deleted.", "No Rows Exist");
		return;
	}
	dataGridView1->Rows->RemoveAt(dataGridView1->CurrentCell->RowIndex);
}


Void MaintenanceSchedule::returnButton_Click(System::Object^ sender, System::EventArgs^ e)
{

}

#pragma endregion

#pragma region Cell Styling
bool MaintenanceSchedule::IsTheSameCellValue(int column, int row)
{
	DataGridViewCell^ cell1 = dataGridView1[column, row];
	DataGridViewCell^ cell2 = dataGridView1[column, row - 1];
	if (cell1->Value == nullptr || cell2->Value == nullptr)
	{
		return false;
	}

	return cell1->Value->ToString()->ToLower() == cell2->Value->ToString()->ToLower();
}
Void MaintenanceSchedule::dataGridView1_CellPainting(System::Object^ sender, DataGridViewCellPaintingEventArgs^ e)
{
	if (e->RowIndex == -1 || e->RowIndex == 0 && dataGridView1->Rows->Count == 1)
		return;
	e->AdvancedBorderStyle->Bottom = DataGridViewAdvancedCellBorderStyle::None;
	if (e->RowIndex < 1 || e->ColumnIndex < 0)
		return;

	if (IsTheSameCellValue(e->ColumnIndex, e->RowIndex) && e->ColumnIndex == 0)
	{
		e->AdvancedBorderStyle->Top = DataGridViewAdvancedCellBorderStyle::None;
	}
	else
	{
		e->AdvancedBorderStyle->Top = dataGridView1->AdvancedCellBorderStyle->Top;
	}

	if (e->RowIndex == (dataGridView1->Rows->Count - 1))
	{
		e->AdvancedBorderStyle->Bottom = dataGridView1->AdvancedCellBorderStyle->Bottom;
	}

}

// Edit cell content style to handle cells with the same value
Void MaintenanceSchedule::dataGridView1_CellFormatting(System::Object^ sender, System::Windows::Forms::DataGridViewCellFormattingEventArgs^ e)
{
	if (e->RowIndex == 0)
		return;
	if (IsTheSameCellValue(e->ColumnIndex, e->RowIndex) && e->ColumnIndex == 0)
	{
		e->CellStyle->ForeColor = Color::Transparent;
		e->CellStyle->SelectionForeColor = Color::Transparent;

		e->FormattingApplied = true;
	}
}
#pragma endregion
bool MaintenanceSchedule::FillMaintenanceArray(int numOfRows)
{
	int year, mileage, months;
	maintenanceArray = new MaintenanceStruct[numOfRows];
	for (int i = 0; i < numOfRows; i++)
	{
		if (dataGridView1->Rows[i]->Cells[0]->Value == nullptr ||
			dataGridView1->Rows[i]->Cells[1]->Value == nullptr ||
			dataGridView1->Rows[i]->Cells[2]->Value == nullptr ||
			dataGridView1->Rows[i]->Cells[3]->Value == nullptr ||
			dataGridView1->Rows[i]->Cells[4]->Value == nullptr ||
			dataGridView1->Rows[i]->Cells[5]->Value == nullptr ||
			dataGridView1->Rows[i]->Cells[6]->Value == nullptr)
		{
			MessageBox::Show("Please fill in missing data.", "Missing Cell Data");
			return false;
		}

		String^ models = dataGridView1->Rows[i]->Cells[0]->Value->ToString();
		Int32::TryParse(dataGridView1->Rows[i]->Cells[1]->Value->ToString(), year);
		Int32::TryParse(dataGridView1->Rows[i]->Cells[2]->Value->ToString(), mileage);
		String^ unit = dataGridView1->Rows[i]->Cells[3]->Value->ToString();
		Int32::TryParse(dataGridView1->Rows[i]->Cells[4]->Value->ToString(), months);
		String^ part = dataGridView1->Rows[i]->Cells[5]->Value->ToString();
		String^ service = dataGridView1->Rows[i]->Cells[6]->Value->ToString();

		maintenanceArray[i].models = marshal_as<std::string>(models);
		maintenanceArray[i].years = year;
		maintenanceArray[i].mileage = mileage;
		maintenanceArray[i].unit = marshal_as<std::string>(unit);
		maintenanceArray[i].months = months;
		maintenanceArray[i].part = marshal_as<std::string>(part);
		maintenanceArray[i].service = marshal_as<std::string>(service);

	}
	return true;
}
Void MaintenanceSchedule::MaintenanceSchedule_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	int numOfRows = dataGridView1->Rows->Count;
	if (numOfRows == 0)
	{
		DeleteFileContent(MAINTENANCE_FILE);
		return;
	}
	Parts^ partsInstance = gcnew Parts();
	partsInstance->numOfPartRows = partsInstance->GetNumberOfLines();
	partsInstance->ReadPartsFromFile(partsInstance->numOfPartRows);
	Service^ serviceInstance = gcnew Service();
	serviceInstance->numOfServiceRows = serviceInstance->GetNumberOfLines();
	serviceInstance->ReadServiceFromFile(serviceInstance->numOfServiceRows);
	for (int i = 0; i < numOfRows; i++)
	{
		String^ part = dataGridView1->Rows[i]->Cells[5]->Value->ToString();
		String^ service = dataGridView1->Rows[i]->Cells[6]->Value->ToString();
		bool partFlag = false, serviceFlag = false;
		for (int j = 0; j < partsInstance->numOfPartRows; j++)
		{
			String^ partName = marshal_as<String^>(partsInstance->partsArray[j].name);
			if (part->ToUpper() == partName->ToUpper())
			{
				partFlag = true;
			}
		}
		if (!partFlag)
		{
			MessageBox::Show("Part does not exist:" + part, "Part does not exist");
			e->Cancel = true;
		}

		for (int j = 0; j < serviceInstance->numOfServiceRows; j++)
		{
			String^ serviceName = marshal_as<String^>(serviceInstance->servicesArray[j].name);
			if (service->ToUpper() == serviceName->ToUpper())
			{
				serviceFlag = true;
			}
		}
		if (!serviceFlag)
		{
			MessageBox::Show("Service does not exist " + service, "Service does not exist");
			e->Cancel = true;
		}
	}
	bool isSuccessful = FillMaintenanceArray(numOfRows);
	if (!isSuccessful)
	{
		e->Cancel = true;
	}
	DeleteFileContent(MAINTENANCE_FILE);
	SaveMaintenanceInFile(maintenanceArray, numOfRows, MAINTENANCE_FILE);

}

void MaintenanceSchedule::SaveMaintenanceInFile(MaintenanceStruct maintenanceArray[], int size, const std::string& filename)
{
	std::ofstream input;
	input.open(filename, std::ofstream::app);

	for (int i = 0; i < size; i++)
	{
		input << maintenanceArray[i].models << "\t";
		input << maintenanceArray[i].years << "\t";
		input << maintenanceArray[i].mileage << "\t";
		input << maintenanceArray[i].unit << "\t";
		input << maintenanceArray[i].months << "\t";
		input << maintenanceArray[i].part << "\t";
		input << maintenanceArray[i].service << "\t";
		input << std::endl;
	}
	input.close();
}

void MaintenanceSchedule::DeleteFileContent(const std::string& filename)
{
	{
		std::ofstream file(filename, std::ofstream::trunc);
		if (!file.is_open()) {
			return;
		}
		file.close();

	}
}

void MaintenanceSchedule::ReadMaintenanceFromFile(int numOfRows)
{
	std::ifstream my_file(MAINTENANCE_FILE);

	// check the file for errors
	if (!my_file)
		return;

	// store the contents of the file in "line" string
	std::string line;

	maintenanceArray = new MaintenanceStruct[numOfRows];
	int index = 0;
	while (std::getline(my_file, line))
	{
		char* row = new char[line.size() + 1];
		std::strcpy(row, line.c_str());

		char* column = std::strtok(row, "\t");
		if (column != nullptr)
			maintenanceArray[index].models = column;

		column = std::strtok(nullptr, "\t");
		if (column != nullptr)
			maintenanceArray[index].years = std::stoi(column);

		column = std::strtok(nullptr, "\t");
		if (column != nullptr)
			maintenanceArray[index].mileage = std::stoi(column);

		column = std::strtok(nullptr, "\t");
		if (column != nullptr)
			maintenanceArray[index].unit = column;

		column = std::strtok(nullptr, "\t");
		if (column != nullptr)
			maintenanceArray[index].months = std::stoi(column);

		column = std::strtok(nullptr, "\t");
		if (column != nullptr)
			maintenanceArray[index].part = column;

		column = std::strtok(nullptr, "\t");
		if (column != nullptr)
			maintenanceArray[index].service = column;

		delete[] row; // Don't forget to free the memory
		index++;
	}
	// close the file
	my_file.close();
}


int MaintenanceSchedule::GetNumberOfLines()
{
	{
		std::ifstream my_file(MAINTENANCE_FILE);
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

Void MaintenanceSchedule::dataGridView1_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	int year, mileage, months;
	if (dataGridView1->Rows->Count > 0)
	{
		System::Object^ cell = dataGridView1->Rows[e->RowIndex]->Cells[1]->Value;
		if (cell != nullptr)
		{
			String^ text = dataGridView1->Rows[e->RowIndex]->Cells[1]->Value->ToString();
			Int32::TryParse(text, year);
			if (e->ColumnIndex == 1 && (!Int32::TryParse(text, year) || (year < 1884 || year > 2024)))
			{
				MessageBox::Show("Please provide a year from 1884 to 2024.", "Year Error");
				dataGridView1->Rows[e->RowIndex]->Cells[1]->Value = nullptr;
			}
		}
		cell = dataGridView1->Rows[e->RowIndex]->Cells[2]->Value;
		if (cell != nullptr)
		{
			String^ text = dataGridView1->Rows[e->RowIndex]->Cells[2]->Value->ToString();
			Int32::TryParse(text, mileage);
			if (e->ColumnIndex == 2 && (!Int32::TryParse(text, mileage) || mileage <= 0))
			{
				MessageBox::Show("Please provide a mileage that's a positive number.", "Mileage Error");
				dataGridView1->Rows[e->RowIndex]->Cells[2]->Value = nullptr;
			}
		}
		cell = dataGridView1->Rows[e->RowIndex]->Cells[1]->Value;
		if (cell != nullptr)
		{
			String^ text = dataGridView1->Rows[e->RowIndex]->Cells[4]->Value->ToString();
			Int32::TryParse(text, months);
			if (e->ColumnIndex == 2 && (!Int32::TryParse(text, mileage) || (months < 1 || months > 12)))
			{
				MessageBox::Show("Please provide a months value that's from 1 to 12.", "Months Error");
				dataGridView1->Rows[e->RowIndex]->Cells[2]->Value = nullptr;
			}
		}
		else
		{
			return;
		}
	}

}
Void MaintenanceSchedule::MaintenanceSchedule_Load(System::Object^ sender, System::EventArgs^ e)
{
	dataGridView1->AutoGenerateColumns = false;
	numOfMaintenanceRows = GetNumberOfLines();
	ReadMaintenanceFromFile(numOfMaintenanceRows);
	for (int i = 0; i < numOfMaintenanceRows; i++)
	{
		dataGridView1->Rows->Add();

		String^ models = marshal_as<System::String^>(maintenanceArray[i].models);
		int year = maintenanceArray[i].years;
		int mileage = maintenanceArray[i].mileage;
		String^ unit = marshal_as<System::String^>(maintenanceArray[i].unit);
		int months = maintenanceArray[i].months;
		String^ part = marshal_as<System::String^>(maintenanceArray[i].part);
		String^ service = marshal_as<System::String^>(maintenanceArray[i].service);

		dataGridView1->Rows[i]->Cells[0]->Value = models;
		dataGridView1->Rows[i]->Cells[1]->Value = year;
		dataGridView1->Rows[i]->Cells[2]->Value = mileage;
		dataGridView1->Rows[i]->Cells[3]->Value = unit;
		dataGridView1->Rows[i]->Cells[4]->Value = months;
		dataGridView1->Rows[i]->Cells[5]->Value = part;
		dataGridView1->Rows[i]->Cells[6]->Value = service;

	}
}

Void MaintenanceSchedule::searchBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
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