#include <iostream>
#include <windows.h>
#include "task_percent_calculations.h"
int k = 0;

int Progress_barr(int t) {
    SetConsoleOutputCP(437);
    Tasks_computation(t);
    int  sectionsLight = 0, sectionsDark = 0;
    sectionsDark =(100 - k)/2;
    sectionsLight = 50 - sectionsDark;
    char full= (char)219;   // █
    char bright= (char)178; // ▓
    char medium= (char)177; // ▒
    char dark =(char)176;   // ░
    std::cout << "progress [" << k << "%] ";
    for (int j = 0; j < sectionsLight; j++) {
        std::cout << full;
    }
    for (int j = 0; j < sectionsDark; j++) {
        std::cout << dark;
    }
    std::cout << "\n";

    return 0;

}