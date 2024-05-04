//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <string>
//using namespace std;
//
//string partFile = "parts.txt";
//string serviceFile = "service.txt";
//
//struct Part {
//    string name;
//    vector<int> cost;
//    vector<string> model;
//
//    void putToFile() {
//        ofstream input;
//        input.open(partFile, ofstream::app);
//
//
//        input << name << "\t";
//        for (size_t i = 0; i < cost.size() - 1; ++i) {
//            input << cost[i] << "@";
//
//        }
//        input << cost[cost.size() - 1];
//        input << "\t";
//        for (size_t i = 0; i < model.size() - 1; ++i) {
//            input << model[i] << "@";
//
//        }
//        input << model[model.size() - 1];
//        input << endl;
//        input.close();
//    }
//};
//
//struct Service {
//    string name;
//    int cost;
//
//    void putToFile() {
//        ofstream input;
//        input.open(serviceFile, ofstream::app);
//        input << name << "\t";
//        input << cost;
//        input << endl;
//        input.close();
//    }
//};