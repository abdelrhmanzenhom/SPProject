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
	if (dataGridView1->Rows->Count != 0)
	{
		endIndex++;
	}
	dataGridView1->Rows->Add();
}

Void MaintenanceSchedule::deleteButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->Rows->Count == 0)
	{
		MessageBox::Show("No rows to be deleted.", "No Rows Exist");
		return;
	}
	if (itemCounter > 0)
	{
		HandleDeletionInDictionary(dataGridView1->CurrentCell->RowIndex);
	}
	dataGridView1->Rows->RemoveAt(dataGridView1->CurrentCell->RowIndex);
}

int MaintenanceSchedule::FindKey(int index)
{
	for each (int key in indicesDictionary->Keys)
	{
		if ((index > key && index < indicesDictionary[key]) ||
			(index == indicesDictionary[key]) ||
			(index == key))
			{
				return key;
			}
	}
	return -1;
}

Void MaintenanceSchedule::HandleDeletionInDictionary(int index)
{
	// Creating another dictionary and filling it to 
	// avoid manipulation while reading exception
	Dictionary<int, int>^ temp = gcnew Dictionary<int, int>();
	for each (int key in indicesDictionary->Keys)
	{
		temp->Add(key, indicesDictionary[key]);
	}

	int keyIndex = FindKey(index);
	indicesDictionary[keyIndex]--;
	for each (int key in temp->Keys)
	{
		if (key > temp[keyIndex])
		{
			indicesDictionary->Remove(key);
			if (!(temp[key] - 1 < key - 1))
			{
				indicesDictionary->Add(key - 1, temp[key] - 1);
			}
		}
	}
	temp->Clear();
}

Void MaintenanceSchedule::returnButton_Click(System::Object^ sender, System::EventArgs^ e)
{

}

Void MaintenanceSchedule::addItemButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	int numOfRows = dataGridView1->Rows->Count;
	int numOfItems = indicesDictionary->Count;
	if (numOfRows == 0 && numOfItems == 0)
	{
		MessageBox::Show("Cannot create item, because there are no rows available", "No Rows Exist");
		return;
	}

	int itemBegin = 0;
	// Get Biggest End Index
	if (itemCounter != 0)
	{
		itemBegin = indicesDictionary[0];
		for each (int end in indicesDictionary->Values)
		{
			if (end > itemBegin)
			{
				itemBegin = end;
			}
		}

		if (!(numOfRows - 1 > itemBegin))
		{
			MessageBox::Show("Cannot create item, because there are no rows available", "No Rows Exist");
			return;
		}
		itemBegin++;
	}
	

	if (dataGridView1->Rows[itemBegin]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[itemBegin]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[itemBegin]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[itemBegin]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[itemBegin]->Cells[4]->Value == nullptr ||
		dataGridView1->Rows[itemBegin]->Cells[5]->Value == nullptr ||
		dataGridView1->Rows[itemBegin]->Cells[6]->Value == nullptr)
	{
		MessageBox::Show("Please fill in missing data.", "Missing Cell Data");
		return;
	}
	int year, mileage, months;

	
	if ((!Int32::TryParse(dataGridView1->Rows[itemBegin]->Cells[2]->Value->ToString(), mileage) || (mileage <= 0)))
	{
		String^ errorMessage = "Mileage can only be positive values" + mileage;
		MessageBox::Show(errorMessage, "Invalid Data Range");
		return;
	}
	if ((!Int32::TryParse(dataGridView1->Rows[itemBegin]->Cells[4]->Value->ToString(), months) || (months < 1 || months > 12)))
	{
		String^ errorMessage = "Months can only be 1 to 12 months" + months;
		MessageBox::Show(errorMessage, "Invalid Data Range");
		return;
	}
	// If item has more than one row
	bool isRowEmpty = true;
	int numberOfMileageValues = 1;
	if (itemBegin != numOfRows - 1)
	{
		for (int i = itemBegin + 1; i < numOfRows; i++)
		{
			// check if row content is empty
			for (int j = 0; j < 7; j++)
			{
				if (dataGridView1->Rows[i]->Cells[j]->Value != nullptr)
				{
					isRowEmpty = false;
				}

			}
			
			if (isRowEmpty)
			{
				MessageBox::Show("Please fill in empty row.", "Missing Row Data");
				return;
			}
			isRowEmpty = true;

			// replace it with empty string to consider two rows of same cell as one
			for (int j = 0; j < 7; j++)
			{
				if (dataGridView1->Rows[i]->Cells[j]->Value == nullptr)
				{
					dataGridView1->Rows[i]->Cells[j]->Value = "";
				}
				
			}
			if ((!Int32::TryParse(dataGridView1->Rows[i]->Cells[1]->Value->ToString(), year) || (year < 1884 || year > 2024)))
			{
				String^ errorMessage = "Year can only contain values from 1884 to 2024";
				MessageBox::Show(errorMessage, "Invalid Data Range");
				return;
			}
			if (!(dataGridView1->Rows[i]->Cells[2]->Value->ToString() == "") ||
				!(dataGridView1->Rows[i]->Cells[3]->Value->ToString() == "") ||
				!(dataGridView1->Rows[i]->Cells[4]->Value->ToString() == ""))
			{
				numberOfMileageValues++;
			}
			if (numberOfMileageValues > 1)
			{
				MessageBox::Show("Cannot create item, because there are two rows containing "
					"values of mileage/unit/months in the same item", "Not Allowed Behaviour");
				return;
			}
		}
	}

	indicesDictionary[itemBegin] = numOfRows - 1;
	
	
	String^ s = "Start:" + itemBegin + "End:" + (numOfRows - itemBegin - 1);
	MessageBox::Show(s);

	startIndex = endIndex + 1;
	itemCounter++;
	MessageBox::Show("Successful");
}

Void MaintenanceSchedule::deleteItemButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (itemCounter == 0)
	{
		if (dataGridView1->Rows->Count == 0)
		{
			MessageBox::Show("Cannot delete item, because there are no items available", "No Items Exist");
			return;
		}
	}

	int startIndexToBeDeleted = FindKey(dataGridView1->CurrentCell->RowIndex);

	if (dataGridView1->Rows->Count == 0 || 
		startIndexToBeDeleted == -1)
	{
		MessageBox::Show("Cannot delete item, because there are no items available", "No Items Exist");
		return;
	}
	int numOfDeletions = indicesDictionary[startIndexToBeDeleted] - startIndexToBeDeleted + 1;
	for (int i = 0; i < numOfDeletions; i++)
	{
		deleteButton_Click(sender, e);
	}

	indicesDictionary->Remove(startIndexToBeDeleted);
	itemCounter--;
}
#pragma endregion

#pragma region Cell Styling

Void MaintenanceSchedule::dataGridView1_CellPainting(System::Object^ sender, DataGridViewCellPaintingEventArgs^ e)
{
	if (e->RowIndex == -1 || e->RowIndex == 0 && dataGridView1->Rows->Count == 1)
		return;
	e->AdvancedBorderStyle->Bottom = DataGridViewAdvancedCellBorderStyle::None;
	if (e->RowIndex < 1 || e->ColumnIndex < 0)
		return;

	if (dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value == "")
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
	if (dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value == "")
	{
		e->CellStyle->ForeColor = Color::Transparent;
		e->CellStyle->SelectionForeColor = Color::Transparent;
		e->FormattingApplied = true;
	}
}
#pragma endregion

Void MaintenanceSchedule::MaintenanceSchedule_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	if (itemCounter == 0 || dataGridView1->Rows->Count == 0)
	{
		DeleteFileContent(MAINTENANCE_FILE);
		return;
	}
	maintenanceArray = new MaintenanceStruct[itemCounter];
	List<String^>^ modelList = gcnew List<String^>();
	List<String^>^ yearList = gcnew List<String^>();
	List<String^>^ partList = gcnew List<String^>();
	List<String^>^ serviceList = gcnew List<String^>();
	int mileage, months;
	std::string unit;
	// Read from table
	int currentItem = 0;
	String^ S = "" + dataGridView1->Rows->Count + "-" + itemCounter;
	MessageBox::Show(S);
	for each (int key in indicesDictionary->Keys)
	{
		for (int i = key; i <= indicesDictionary[key]; i++)
		{
			DataGridViewRow^ row = dataGridView1->Rows[i];
			if (!row->Cells[0]->Value->ToString()->Equals(""))
			{
				modelList->Add(row->Cells[0]->Value->ToString());
			}

			if (!row->Cells[1]->Value->ToString()->Equals(""))
			{
				yearList->Add(row->Cells[1]->Value->ToString());
			}

			if (!(row->Cells[2]->Value->ToString()->Equals("")) &&
				!(row->Cells[3]->Value->ToString()->Equals("")) &&
				!(row->Cells[4]->Value->ToString()->Equals("")))
			{
				Int32::TryParse(row->Cells[2]->Value->ToString(), mileage);
				Int32::TryParse(row->Cells[4]->Value->ToString(), months);
				unit = marshal_as<std::string>(row->Cells[3]->Value->ToString());
			}

			if (!row->Cells[5]->Value->ToString()->Equals(""))
			{
				partList->Add(row->Cells[5]->Value->ToString());
			}

			if (!row->Cells[6]->Value->ToString()->Equals(""))
			{
				serviceList->Add(row->Cells[6]->Value->ToString());
			}
		}

		// Fill current item in the array

		maintenanceArray[currentItem].mileage = mileage;
		maintenanceArray[currentItem].months = months;
		maintenanceArray[currentItem].unit = unit;
		maintenanceArray[currentItem].models = new std::string[modelList->Count];
		maintenanceArray[currentItem].years = new int[yearList->Count];
		maintenanceArray[currentItem].part = new std::string[partList->Count];
		maintenanceArray[currentItem].service = new std::string[serviceList->Count];
		maintenanceArray[currentItem].size[0] = modelList->Count;
		maintenanceArray[currentItem].size[1] = yearList->Count;
		maintenanceArray[currentItem].size[2] = partList->Count;
		maintenanceArray[currentItem].size[3] = serviceList->Count;
		for (int i = 0; i < modelList->Count; i++)
		{
			maintenanceArray[currentItem].models[i] = marshal_as<std::string>(modelList[i]);
			MessageBox::Show(modelList[i]);

		}

		for (int i = 0; i < yearList->Count; i++)
		{
			int value;
			Int32::TryParse(yearList[i], value);
			maintenanceArray[currentItem].years[i] = value;
			MessageBox::Show(yearList[i]);

		}

		for (int i = 0; i < partList->Count; i++)
		{
			maintenanceArray[currentItem].part[i] = marshal_as<std::string>(partList[i]);
			MessageBox::Show(partList[i]);

		}

		for (int i = 0; i < serviceList->Count; i++)
		{
			maintenanceArray[currentItem].service[i] = marshal_as<std::string>(serviceList[i]);
			MessageBox::Show(serviceList[i]);
		}
		currentItem++;
	}
	SaveMaintenanceInFile(maintenanceArray, itemCounter, MAINTENANCE_FILE);
}

void MaintenanceSchedule::SaveMaintenanceInFile(MaintenanceStruct maintenanceArray[], int size, const std::string& filename)
{
	DeleteFileContent(MAINTENANCE_FILE);
	std::ofstream input;
	input.open(filename, std::ofstream::app);
	for (int i = 0; i < itemCounter; i++)
	{
		// models
		input << maintenanceArray[i].models[0];
		if (maintenanceArray[i].size[0] != 1)
		{
			for (int j = 1; j < maintenanceArray[i].size[0]; j++)
			{
				input << "-" << maintenanceArray[i].models[j];
			}
		}
		input << "\t";
		
		// years
		input << maintenanceArray[i].years[0];
		if (maintenanceArray[i].size[1] != 1)
		{
			for (int j = 1; j < maintenanceArray[i].size[1]; j++)
			{
				input << "-" << maintenanceArray[i].years[j];
			}
		}
		input << "\t";

		// mileage, unit, months
		input << maintenanceArray[i].mileage << "-" << maintenanceArray[i].unit << "-" << maintenanceArray[i].months;
		input << "\t";

		
		// parts
		input << maintenanceArray[i].part[0];
		if (maintenanceArray[i].size[2] != 1)
		{
			for (int j = 1; j < maintenanceArray[i].size[2]; j++)
			{
				input << "-" << maintenanceArray[i].part[j];
			}
		}
		input << "\t";

		// services
		input << maintenanceArray[i].service[0];
		if (maintenanceArray[i].size[3] != 1)
		{
			for (int j = 1; j < maintenanceArray[i].size[3]; j++)
			{
				input << "-" << maintenanceArray[i].service[j];
			}
		}
		input << "\t";

		input << maintenanceArray[i].size[0] << "-" << maintenanceArray[i].size[1] << "-" << maintenanceArray[i].size[2] << "-" << maintenanceArray[i].size[3];
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
	std::ifstream my_file(SERVICE_FILE);
	if (!my_file)
		return;

	maintenanceArray = new MaintenanceStruct[numOfRows];
	std::ifstream input(MAINTENANCE_FILE);
	std::string line;
	int currentItem = 0;
	while (std::getline(input, line)) {
		std::istringstream iss(line);
		std::string field;

		List<String^>^ models = gcnew List<String^>();
		List<String^>^ years = gcnew List<String^>();
		List<String^>^ mileagePerMonths = gcnew List<String^>();
		List<String^>^ parts = gcnew List<String^>();
		List<String^>^ services = gcnew List<String^>();
		List<String^>^ sizes = gcnew List<String^>();
		
		// Parse models
		std::getline(iss, field, '\t');
		std::istringstream modelsStream(field);
		std::string model;
		while (std::getline(modelsStream, model, '-')) {
			models->Add(marshal_as<String^>(model));
		}

		// Parse years
		std::getline(iss, field, '\t');
		std::istringstream yearsStream(field);
		while (std::getline(yearsStream, field, '-')) {
			years->Add(marshal_as<String^>(field));
		}

		// Parse mileage, unit, months
		std::getline(iss, field, '\t');
		std::istringstream mileageStream(field);
		while (std::getline(mileageStream, field, '-')) {
			mileagePerMonths->Add(marshal_as<String^>(field));
		}

		// Parse part
		std::getline(iss, field, '\t');
		std::istringstream partStream(field);
		while (std::getline(partStream, field, '-')) {
			parts->Add(marshal_as<String^>(field));
		}

		// Parse service
		std::getline(iss, field, '\t');
		std::istringstream serviceStream(field);
		while (std::getline(serviceStream, field, '-')) {
			services->Add(marshal_as<String^>(field));
		}

		// Parse sizes
		std::getline(iss, field);
		std::istringstream sizeStream(field);
		while (std::getline(sizeStream, field, '-')) {
			sizes->Add(marshal_as<String^>(field));
		}

		maintenanceArray[currentItem].models = new std::string[models->Count];
		maintenanceArray[currentItem].years = new int[years->Count];
		maintenanceArray[currentItem].part = new std::string[parts->Count];
		maintenanceArray[currentItem].service = new std::string[services->Count];

		int mileage, months;
		Int32::TryParse(mileagePerMonths[0], mileage);
		Int32::TryParse(mileagePerMonths[2], months);
		maintenanceArray[currentItem].mileage = mileage;
		maintenanceArray[currentItem].unit = marshal_as<std::string>(mileagePerMonths[1]);
		maintenanceArray[currentItem].months = months;

		for (int i = 0; i < 4; i++)
		{
			int value;
			Int32::TryParse(sizes[i], value);
			maintenanceArray[currentItem].size[i] = value;
		}

		for (int i = 0; i < models->Count; i++)
		{
			maintenanceArray[currentItem].models[i] = marshal_as<std::string>(models[i]);
		}

		for (int i = 0; i < years->Count; i++)
		{
			int year;
			Int32::TryParse(years[i], year);
			maintenanceArray[currentItem].years[i] = year;
		}

		for (int i = 0; i < parts->Count; i++)
		{

			maintenanceArray[currentItem].part[i] = marshal_as<std::string>(parts[i]);
		}

		for (int i = 0; i < services->Count; i++)
		{
			maintenanceArray[currentItem].service[i] = marshal_as<std::string>(services[i]);
		}
		currentItem++;
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

Void MaintenanceSchedule::MaintenanceSchedule_Load(System::Object^ sender, System::EventArgs^ e)
{
	int items = GetNumberOfLines();
	ReadMaintenanceFromFile(items);
	int currentRow = 0;
	for (int i = 0; i < items; i++)
	{	
		// get number of rows needed for this item
		int numberOfRowsOfItem;
		int max1 = max(maintenanceArray->size[0], maintenanceArray->size[1]);
		int max2 = max(maintenanceArray->size[2], maintenanceArray->size[3]);
		if (max1 >= max2)
		{
			numberOfRowsOfItem = max1;
		}
		else
		{
			numberOfRowsOfItem = max2;
		}

		// add rows based on max number of rows
		for (int j = 0; j < numberOfRowsOfItem; j++)
		{
			dataGridView1->Rows->Add();
		}

		// fill in data
		for (int j = 0; j < maintenanceArray->size[0]; j++)
		{
			dataGridView1->Rows[currentRow+j]->Cells[0]->Value = marshal_as<String^>(maintenanceArray->models[j]);
		}

		for (int j = 0; j < maintenanceArray->size[1]; j++)
		{
			dataGridView1->Rows[currentRow + j]->Cells[1]->Value = maintenanceArray->years[j];
		}
		String^ s = "" + maintenanceArray->mileage;
		MessageBox::Show(s);
		dataGridView1->Rows[currentRow]->Cells[2]->Value = maintenanceArray->mileage;
		dataGridView1->Rows[currentRow]->Cells[3]->Value = marshal_as<String^>(maintenanceArray->unit);
		dataGridView1->Rows[currentRow]->Cells[4]->Value = maintenanceArray->months;

		for (int j = 0; j < maintenanceArray->size[2]; j++)
		{
			dataGridView1->Rows[currentRow + j]->Cells[5]->Value = marshal_as<String^>(maintenanceArray->part[j]);
		}

		for (int j = 0; j < maintenanceArray->size[3]; j++)
		{
			dataGridView1->Rows[currentRow + j]->Cells[6]->Value = marshal_as<String^>(maintenanceArray->service[j]);
		}

		for (int j = 0; j < 7; j++)
		{
			if (dataGridView1->Rows[currentRow]->Cells[j]->Value == nullptr)
			{
				dataGridView1->Rows[currentRow]->Cells[j]->Value = "";
			}
		}
		indicesDictionary[currentRow] = numberOfRowsOfItem - 1;
		currentRow += numberOfRowsOfItem;
	}
}
