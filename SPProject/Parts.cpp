#include "Parts.h"
using namespace Motor_Vehicle_Service_Win;

#pragma region Update Functions

// Add row
Void Parts::addButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->Rows->Count > 0)
	{
		if ((dataGridView1->Rows[dataGridView1->Rows->Count - 1]->Cells[0]->Value == nullptr ||
			dataGridView1->Rows[dataGridView1->Rows->Count - 1]->Cells[1]->Value == nullptr ||
			dataGridView1->Rows[dataGridView1->Rows->Count - 1]->Cells[2]->Value == nullptr))
		{
			MessageBox::Show("Please fill in missing data.", "Missing Cell Data");
		}
		else
		{
			dataGridView1->Rows->Add();
		}
	}
	else
	{
		dataGridView1->Rows->Add();
	}
}

// Delete row
Void Parts::deleteButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->Rows->Count == 0)
	{
		MessageBox::Show("No rows to be deleted.", "No Rows Exist");
		return;
	}
	dataGridView1->Rows->RemoveAt(dataGridView1->CurrentCell->RowIndex);
}

// Edit cell content
Void Parts::dataGridView1_CellValueChanged(System::Object^ sender, DataGridViewCellEventArgs^ e)
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

	for (int i = 0; i < dataGridView1->RowCount; i++)
	{
		DataGridViewCell^ cell1 = dataGridView1[0, i];
		DataGridViewCell^ cell2 = dataGridView1[0, e->RowIndex];
		if ((dataGridView1->Rows[e->RowIndex]->Cells[0]->Value != nullptr &&
			dataGridView1->Rows[e->RowIndex]->Cells[1]->Value != nullptr &&
			dataGridView1->Rows[e->RowIndex]->Cells[2]->Value != nullptr)
			&& (cell1->Value->ToString()->ToLower() == cell2->Value->ToString()->ToLower())
			&& (e->RowIndex != i))
		{

		}
	}
}
#pragma endregion

#pragma region Style Handling

// Edit cell borders style to handle cells with the same value
Void Parts::dataGridView1_CellPainting(System::Object^ sender, DataGridViewCellPaintingEventArgs^ e)
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
Void Parts::dataGridView1_CellFormatting(System::Object^ sender, System::Windows::Forms::DataGridViewCellFormattingEventArgs^ e)
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

#pragma region Form Behaviours

bool Parts::IsTheSameCellValue(int column, int row)
{
	DataGridViewCell^ cell1 = dataGridView1[column, row];
	DataGridViewCell^ cell2 = dataGridView1[column, row - 1];
	if (cell1->Value == nullptr || cell2->Value == nullptr)
	{
		return false;
	}

	return cell1->Value->ToString()->ToLower() == cell2->Value->ToString()->ToLower();
}

bool Parts::FillPartsArray(int numOfPartRows)
{

	double value;
	partsArray = new PartStruct[numOfPartRows];
	for (int i = 0; i < numOfPartRows; i++)
	{
		if (dataGridView1->Rows[i]->Cells[0]->Value == nullptr ||
			dataGridView1->Rows[i]->Cells[1]->Value == nullptr ||
			dataGridView1->Rows[i]->Cells[2]->Value == nullptr)
		{
			MessageBox::Show("Please fill in missing data.", "Missing Cell Data");
			return false;
		}

		String^ name = dataGridView1->Rows[i]->Cells[0]->Value->ToString();
		Double::TryParse(dataGridView1->Rows[i]->Cells[1]->Value->ToString(), value);
		String^ models = dataGridView1->Rows[i]->Cells[2]->Value->ToString();

		partsArray[i].name = marshal_as<std::string>(name);
		partsArray[i].cost = value;
		partsArray[i].models = marshal_as<std::string>(models);
	}
	return true;
}

Void Parts::Parts_Load(System::Object^ sender, System::EventArgs^ e)
{
	dataGridView1->AutoGenerateColumns = false;
	numOfPartRows = GetNumberOfLines();
	ReadPartsFromFile(numOfPartRows);
	for (int i = 0; i < numOfPartRows; i++)
	{
		dataGridView1->Rows->Add();

		String^ name = marshal_as<System::String^>(partsArray[i].name);
		String^ models = marshal_as<System::String^>(partsArray[i].models);

		dataGridView1->Rows[i]->Cells[0]->Value = name;
		dataGridView1->Rows[i]->Cells[1]->Value = partsArray[i].cost;
		dataGridView1->Rows[i]->Cells[2]->Value = models;
	}
}


Void Parts::Parts_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	int numOfRows = dataGridView1->Rows->Count;
	if (numOfRows == 0)
	{
		DeleteFileContent(PART_FILE);
		return;
	}
	bool isSuccessful = FillPartsArray(numOfRows);
	if (!isSuccessful)
	{
		e->Cancel = true;
	}
	DeleteFileContent(PART_FILE);
	SavePartsInFile(partsArray, numOfRows, PART_FILE);
}
#pragma endregion

#pragma region File Handling

int Parts::GetNumberOfLines()
{
	{
		std::ifstream my_file(PART_FILE);
		// check the file for errors
		if (!my_file)
			return -1;
		int numOfRows = 0;
		// store the contents of the file in "line" string
		std::string line;

		// Loop to get number of rows
		while (std::getline(my_file, line))
		{
			numOfRows++;
		}
		return numOfRows;
	}
}

void Parts::DeleteFileContent(const std::string& filename)
{
	{
		std::ofstream file(filename, std::ofstream::trunc);
		if (!file.is_open()) {
			return;
		}
		file.close();

	}
}

void Parts::SavePartsInFile(PartStruct partsArray[], int size, const std::string& filename)
{

	std::ofstream input;
	input.open(filename, std::ofstream::app);

	for (int i = 0; i < size; i++)
	{
		input << partsArray[i].name << "\t";
		input << partsArray[i].cost << "\t";
		input << partsArray[i].models << "\t";
		input << std::endl;
	}
	input.close();
}

void Parts::ReadPartsFromFile(int numOfRows)
{
	std::ifstream my_file(PART_FILE);

	// check the file for errors
	if (!my_file)
		return;
	// store the contents of the file in "line" string
	std::string line;


	partsArray = new PartStruct[numOfRows];
	int index = 0;
	char* column;
	while (std::getline(my_file, line))
	{
		char* row = new char[line.size() + 1];
		std::strcpy(row, line.c_str());

		char* column = std::strtok(row, "\t");
		partsArray[index].name = column;

		column = std::strtok(nullptr, "\t");
		partsArray[index].cost = std::stod(column);

		column = std::strtok(nullptr, "\t");
		partsArray[index].models = column;

		delete[] row; // Don't forget to free the memory
		index++;
	}
	// close the file
	my_file.close();
}
#pragma endregion

#pragma region Search

Void Parts::searchBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
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
#pragma endregion

#pragma region Movement
Void Parts::returnButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

#pragma endregion