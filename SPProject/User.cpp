#include "User.h"
#include <string>
#include <fstream>
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include <map>
#include <windows.h>
using namespace std;
using namespace System;

Admin::Admin() {}

Admin::Admin(string user_name, string pass) {
    this->user_name = user_name;
    this->password = pass;

}

int Admin::autoid() {
    ifstream f("log.txt");
    int idd = 0;
    string str;
    while (getline(f, str)) {
        idd++;
    }
    f.close();
    return idd + 1;
}

void Admin::sign_up(System::String^ s1, System::String^ s2) {
    std::string username = msclr::interop::marshal_as<std::string>(s1);
    std::string address = msclr::interop::marshal_as<std::string>(s2);


    int id = autoid();

    ofstream save("log.txt", ios::app);
    save << username << " " << address << " " << id << endl;
    save.close();
}
bool Admin::login(string signinname, string signinpass)
{




    bool usernameExists = false;
    int id;
    string n, p;
    ifstream input("log.txt");
    while (input >> n >> p >> id)
    {
        if (n == signinname && p == signinpass)
        {
            usernameExists = true;
            break;
        }
    }
    input.close();




    return usernameExists;
}
