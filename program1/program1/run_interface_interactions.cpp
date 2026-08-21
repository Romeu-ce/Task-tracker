#include<iostream>
#include<fstream>
//#include <windows.h>
#include <nlohmann/json.hpp>
#include "SomeFunctions.h"

int interface(void) {
    //SetConsoleOutputCP(437);
    char full = (char)219;   // █
    char bright = (char)178; // ▓
    char medium = (char)177; // ▒
    char dark = (char)176;   // ░

    int option = 0;

 
    std::cout << std::string(50, full)<< '\n';
    std::cout<< "Hi, this is your task manager"<< "\n" << "chose opthion"<<"\n";
    std::cout << "1 Open list of projects"<< "\n"<< "2 Exit"<< "\n";
    std::cin >> option;
   

    switch (option) {
    case 1:
        open_project_list();
        break;
    case 2:
        run_exit_sequence();
        break;
    }
    

	return 0;
}