#include "UserVehicle.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Motor_Vehicle_Service_Win;


// Define a custom form to display the table
ref class TableForm : public Form {
private:
    System::Windows::Forms::Button^ Okbutton;

public:
    TableForm(std::vector<std::string> headers, std::vector<std::vector<std::string>> data) {
        InitializeComponent(headers, data);
        this->BackColor = System::Drawing::Color::White; // Set background color to white
    }

private:
    void InitializeComponent(std::vector<std::string> headers, std::vector<std::vector<std::string>> data) {
        this->Okbutton = (gcnew System::Windows::Forms::Button());
        // Set up form properties
        this->Text = "Service Details";
        this->Size = System::Drawing::Size(400, 400); // Increase form height to accommodate the button
        //this->Icon = gcnew System::Drawing::Icon("C:/Users/Dell/OneDrive/Desktop/Motor Vehicle Service.ico");

        // Create a DataGridView to display the table
        DataGridView^ dataGridView = gcnew DataGridView();
        dataGridView->Size = System::Drawing::Size(400, 300);
        dataGridView->BackgroundColor = System::Drawing::Color::AliceBlue; // Set background color
        dataGridView->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle; // Set border style
        dataGridView->GridColor = System::Drawing::Color::Black; // Set grid color
        dataGridView->ReadOnly = true;

        //dataGridView->Dock = DockStyle::Fill;
        dataGridView->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

        // Add columns to the DataGridView
        for (int i = 0; i < headers.size(); i++) {
            dataGridView->Columns->Add(gcnew DataGridViewTextBoxColumn());
            dataGridView->Columns[i]->HeaderText = gcnew String(headers[i].c_str());
        }

        // Add rows to the DataGridView
        for (int i = 0; i < data.size() - 1; i++) {
            array<String^>^ row = gcnew array<String^>(data[i].size());
            for (int j = 0; j < data[i].size(); j++) {
                row[j] = gcnew String(data[i][j].c_str());
            }
            dataGridView->Rows->Add(row);
        }
        array<String^>^ row = gcnew array<String^>(data[data.size() - 1].size());
        for (int j = 0; j < data[data.size() - 1].size(); j++) {
            row[j] = gcnew String(data[data.size() - 1][j].c_str());
        }
        dataGridView->Rows->Add(row);

        // Change background color of the last row
        if (dataGridView->Rows->Count > 0) {
            int lastIndex = dataGridView->Rows->Count - 2;
            dataGridView->Rows[lastIndex - 1]->DefaultCellStyle->BackColor = System::Drawing::Color::YellowGreen;
            dataGridView->Rows[lastIndex]->DefaultCellStyle->BackColor = System::Drawing::Color::LightBlue;
            dataGridView->Rows[lastIndex + 1]->DefaultCellStyle->BackColor = System::Drawing::Color::Black;
        }

        // Add the DataGridView to the form
        this->Controls->Add(dataGridView);

        // Set the location and properties of the "OK" button
        this->Okbutton->Location = System::Drawing::Point(150, 320);
        this->Okbutton->Size = System::Drawing::Size(100, 30);
        this->Okbutton->Text = L"OK";
        this->Okbutton->Click += gcnew System::EventHandler(this, &TableForm::OkButton_Click);

        // Add the "OK" button to the form
        this->Controls->Add(Okbutton);
    }

    // Event handler for the "OK" button click
    void OkButton_Click(Object^ sender, EventArgs^ e) {
        this->Close(); // Close the form
    }
};


bool UserVehicle::dataValidation(bool isDataFilled, bool isDataTypeCorrect, bool isDataValueCorrect) {
    /*
    * Data validation check based on
    *  - Emptiness/Nulls
    *  - Numeric values
    *  - Possible values for each data
    */
    int value;
    String^ errorMessage;
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
    if (isDataFilled && isDataTypeCorrect && isDataValueCorrect) {
        return true;
    }
    return false;
}
// Function to split a string based on a delimiter
std::vector<std::string> split(const std::string& str) {
    // Create a temporary copy of the string
    std::string modelsCopy = str;

    // Define a vector to store the individual strings
    std::vector<std::string> modelList;

    // Split the temporary copy using the comma delimiter
    size_t pos = 0;
    std::string token;
    while ((pos = modelsCopy.find(", ")) != std::string::npos) {
        token = modelsCopy.substr(0, pos);
        modelList.push_back(token);
        modelsCopy.erase(0, pos + 2); // Move past the delimiter and space
    }
    // Add the last substring
    modelList.push_back(modelsCopy);
    return modelList;
}
std::string toLowercase(const std::string& s) {
    std::string result;
    for (char c : s) {
        result += std::tolower(c);
    }
    return result;
}
std::string toUpperCase(const std::string& s) {
    std::string result;
    for (char c : s) {
        result += std::toupper(c);
    }
    return result;
}
void partsToUpper(PartStruct* partsArray, int size_of_partsArray) {
    // Iterate through each element of partsArray
    for (int i = 0; i < size_of_partsArray; ++i) // size_of_partsArray should be the size of partsArray
    {
        // Convert name to uppercase
        std::transform(partsArray[i].name.begin(), partsArray[i].name.end(), partsArray[i].name.begin(), ::toupper);

        // Convert models to uppercase
        std::transform(partsArray[i].models.begin(), partsArray[i].models.end(), partsArray[i].models.begin(), ::toupper);
    }
}
void servicesToUpper(ServiceStruct* servicesArray, int size_of_servicesArray) {
    // Iterate through each element of servicesArray
    for (int i = 0; i < size_of_servicesArray; ++i) // size_of_servicesArray should be the size of servicesArray
    {
        // Convert name to uppercase
        std::transform(servicesArray[i].name.begin(), servicesArray[i].name.end(), servicesArray[i].name.begin(), ::toupper);
    }

}
void maintenancesToUpper(MaintenanceStruct* maintenanceArray, int size_of_maintenanceArray) {
    // Iterate through each element of maintenanceArray
    for (int i = 0; i < size_of_maintenanceArray; ++i) // size_of_maintenanceArray should be the size of maintenanceArray
    {
        // Convert models to uppercase
        std::transform(maintenanceArray[i].models.begin(), maintenanceArray[i].models.end(), maintenanceArray[i].models.begin(), ::toupper);

        // Convert part to uppercase
        std::transform(maintenanceArray[i].part.begin(), maintenanceArray[i].part.end(), maintenanceArray[i].part.begin(), ::toupper);

        // Convert service to uppercase
        std::transform(maintenanceArray[i].service.begin(), maintenanceArray[i].service.end(), maintenanceArray[i].service.begin(), ::toupper);
    }
}
void userServices(std::vector<std::vector<std::string>>& partsAndServices, double& taxPrice, double& totalPrice, UserVehicleStruct userVehicle, PartStruct* parts, ServiceStruct* services, MaintenanceStruct* maintenances, double tax, int partsSize, int servicesSize, int maintenancesSize) {
    for (int i = 0; i < maintenancesSize; i++) {
        std::vector<std::string> models = split(maintenances[i].models);
        if (std::find(models.begin(), models.end(), userVehicle.model) != models.end() &&
            maintenances[i].years == userVehicle.year &&
            maintenances[i].mileage == userVehicle.mileage &&
            maintenances[i].unit == userVehicle.unit &&
            maintenances[i].months == userVehicle.months) {

            // Search for parts
            for (int j = 0; j < partsSize; j++) {
                std::vector<std::string> partmodels = split(parts[j].models);
                std::vector<std::string> partsPair;
                if (maintenances[i].part == parts[j].name && (std::find(partmodels.begin(), partmodels.end(), userVehicle.model) != partmodels.end() || parts[j].models == "ALL")) {
                    partsPair.push_back(parts[j].name);
                    partsPair.push_back(std::to_string(parts[j].cost));
                    partsAndServices.push_back(partsPair);
                }
            }
        }
    }
    for (int i = 0; i < maintenancesSize; i++) {
        std::vector<std::string> models = split(maintenances[i].models);
        if (std::find(models.begin(), models.end(), userVehicle.model) != models.end() &&
            maintenances[i].years == userVehicle.year &&
            maintenances[i].mileage == userVehicle.mileage &&
            maintenances[i].unit == userVehicle.unit &&
            maintenances[i].months == userVehicle.months) {

            // Search for services
            for (int k = 0; k < servicesSize; k++) {
                std::vector<std::string> ServicePair;
                if (maintenances[i].service == services[k].name) {
                    ServicePair.push_back(services[k].name);
                    ServicePair.push_back(std::to_string(services[k].price));
                    partsAndServices.push_back(ServicePair);
                }
            }
        }
    }
    partsAndServices.erase(std::unique(partsAndServices.begin(), partsAndServices.end()), partsAndServices.end());

    // Calculate tax
    for (const auto& row : partsAndServices) {
        taxPrice += std::stoi(row[1]);
    }
    taxPrice = taxPrice * tax / 100;
    // Add "Tax" row to data
    std::vector<std::string> taxRow = { "Tax", std::to_string(taxPrice) };
    partsAndServices.push_back(taxRow);


    // Calculate total price
    for (const auto& row : partsAndServices) {
        totalPrice += std::stod(row[1]);
    }
    // Add "Total" row to data
    std::vector<std::string> totalRow = { "Total", std::to_string(totalPrice) };
    partsAndServices.push_back(totalRow);

}

Void UserVehicle::button1_Click(System::Object^ sender, System::EventArgs^ e) {
    // Reading user input
    std::string model = marshal_as<std::string>(textBox1->Text);
    std::string year = marshal_as<std::string>(textBox2->Text);
    std::string mileage = marshal_as<std::string>(textBox3->Text);
    std::string months = marshal_as<std::string>(textBox4->Text);
    std::string unit = "KM";
    if (comboBox1->Text != "") {
        unit = marshal_as<std::string>(comboBox1->Text);
    }

    // If all data is filled correctly, create and show the table form
    if (dataValidation(true, true, true)) {
        partsInstance = gcnew Parts(); // Create an instance of the Parts class
        partsInstance->ReadPartsFromFile(partsInstance->GetNumberOfLines());
        serviceInstance = gcnew Service(); // Create an instance of the Service class
        serviceInstance->ReadServiceFromFile(serviceInstance->GetNumberOfLines());
        maintenanceScheduleInstance = gcnew MaintenanceSchedule(); // Create an instance of the MaintenanceSchedule class
        maintenanceScheduleInstance->ReadMaintenanceFromFile(maintenanceScheduleInstance->GetNumberOfLines());
        taxInstance = gcnew Tax(); // Create an instance of the Tax class
        taxInstance->ReadTaxFromFile();



        //parts = new Partss[9];
        //parts[0] = { "Battery", 1000, "MG5, MG6" };
        //parts[2] = { "Wipers", 150, "MG5, MG ZS" };
        //parts[4] = { "Wipers", 160, "MG6" };
        //parts[5] = { "Oil filter", 200, "MG5, MG6, MG ZS" };
        //parts[8] = { "Oil 10K", 900, "All" };

        //services = new Services[2];
        //services[0] = { "Change Oil", 100 };
        //services[1] = { "Change Tyres", 200 };
        //
        //maintenances = new Maintenance[9];
        //maintenances[0] = { "MG5, MG6, MG ZS", 2020, 10000, "KM", 6, "Oil 10K", "Change Oil" };
        //maintenances[1] = { "MG5, MG6", 2021, 10000, "KM", 6, "Oil 10K", "Change Oil" };
        //maintenances[2] = { "MG5, MG6", 2022, 10000, "KM", 6, "Oil 10K", "Change Oil" };
        //maintenances[3] = { "MG5, MG6", 2020, 10000, "KM", 6, "Wipers", "Change Oil" };
        //maintenances[4] = { "MG5, MG6", 2021, 10000, "KM", 6, "Wipers", "Change Oil" };
        //maintenances[5] = { "MG5, MG6", 2022, 10000, "KM", 6, "Wipers", "Change Oil" };
        //maintenances[6] = { "MG5, MG6", 2020, 20000, "KM", 12, "Battery", "Change Tyres" };
        //maintenances[7] = { "MG5, MG6", 2021, 20000, "KM", 12, "Battery", "Change Tyres" };
        //maintenances[8] = { "MG5, MG6", 2022, 20000, "KM", 12, "Battery", "Change Tyres" };

        UserVehicleStruct userVehicle = { toUpperCase(model), std::stoi(year), std::stoi(mileage), unit, std::stoi(months) };

        std::vector<std::vector<std::string>> partsAndServices;
        std::vector<std::string> headers = { "Item", "Price" };
        double taxPrice = 0;
        double totalPrice = 0;

        partsToUpper(partsInstance->partsArray, partsInstance->GetNumberOfLines());
        servicesToUpper(serviceInstance->servicesArray, serviceInstance->GetNumberOfLines());
        maintenancesToUpper(maintenanceScheduleInstance->maintenanceArray, maintenanceScheduleInstance->GetNumberOfLines());
        userServices(partsAndServices, taxPrice, totalPrice, userVehicle, partsInstance->partsArray, serviceInstance->servicesArray, maintenanceScheduleInstance->maintenanceArray, taxInstance->tax, partsInstance->GetNumberOfLines(), serviceInstance->GetNumberOfLines(), maintenanceScheduleInstance->GetNumberOfLines());

        if (totalPrice == 0) {
            MessageBox::Show("Apologies, this service is currently unavailable.");
        }
        else {
            TableForm^ tableForm = gcnew TableForm(headers, partsAndServices);
            tableForm->ShowDialog();
        }
    }
}
