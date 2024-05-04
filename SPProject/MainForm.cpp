#include "UserVehicle.h"
#include "Parts.h"
#include "Service.h"
#include "Tax.h"
#include "MaintenanceSchedule.h"
#include "User.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Motor_Vehicle_Service_Win;

[STAThreadAttribute]

void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Motor_Vehicle_Service_Win::UserVehicle form;
	Motor_Vehicle_Service_Win::Tax tax;
	Motor_Vehicle_Service_Win::Parts part;
	Motor_Vehicle_Service_Win::Service service;
	Motor_Vehicle_Service_Win::MaintenanceSchedule maintenanceSchedule;
	Motor_Vehicle_Service_Win::User user;
	//part->Show();
	//Application::Run(% form);
	//Application::Run(% service);
	//Application::Run(% part);
	//Application::Run(% tax);
	Application::Run(% user);
}