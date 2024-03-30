#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "Part.h"
#include "Service.h"
using namespace std;
class FileManager {
private:
    string partsFile = "parts.txt";
    string servicesFile = "services.txt";
    string taxesFile = "taxes.txt";
    string maintenanceScheduleFile = "maintenance_schedule.txt";

public:
    void saveParts(Part parts[], int size) {}
    void saveServices(Service services[], int size) {}
}