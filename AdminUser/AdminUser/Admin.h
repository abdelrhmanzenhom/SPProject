#include<string>
#include <msclr\marshal_cppstd.h>
using namespace std;
using namespace System;

class Admin
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
	bool login(std::string s3,std::string s4);
	

};