#include<iostream>
#include<fstream>
#include "interface.h"
#include <nlohmann/json.hpp>
#include <limits>
#include "SomeFunctions.h"


int get_the_amount_of_proj(void) {
	std::ifstream readFile("./userdata.json");
	nlohmann::json data;
	readFile >> data;
	int theAmounOfProj = static_cast<int>(data.size());
	return theAmounOfProj;

}

int get_number_of_tasks(int t) {
	int ProjNum = t;
	std::ifstream readFile("./userdata.json");
	nlohmann::json jsonData = nlohmann::json::parse(readFile);
	int numOfTasks = static_cast<int>(jsonData[ProjNum]["Tasks"].size());
	readFile.close();
	
	return numOfTasks;
}

int get_number_of_compl_tasks(int t) {   //change void to int (sequential number of an project)
	int ProjNum = t;
	std::ifstream readFile("./userdata.json");
	nlohmann::json jsonData = nlohmann::json::parse(readFile);
	int k =0, index =0;
	 int numOfTasks = static_cast<int>(jsonData[ProjNum]["Tasks"].size());  ///i`m looking only for one project
		for (int i = 1;i <= numOfTasks;i++) {
			k += jsonData[ProjNum]["Tasks"][index]["completion"].get<int>();
			index++;
		};
	// readFile.close();
	return k;
};

int add_new_task(int a) {
	class_to_json(a);
	int g=0;
	return 0;
};

void open_project_list(void) {
	std::ifstream lookForProj("./userdata.json");
	nlohmann::json jsonData = nlohmann::json::parse(lookForProj);  //////
	int k = 0, index = 0, choise=0, trueChoise = 1;
	std::cout << "List of projects"<< std::endl;

	int temp =get_the_amount_of_proj();
	for (int j = 1; j <= temp; j++) {
		std::cout << j << "   ";
		std::cout << jsonData[index]["ProjectName"].get<std::string>() << '\n'
		 << "The goal:" << jsonData[index]["ProjectGoal"].get<std::string>() << '\n'
		 << "completion ";	//put here the progress bar function
		Progress_barr(index);
		index++;
		std::cout <<  std::endl;
	}
	std::cout << "Choose an option" << "\n"<< "1 open an project , " << "2 add new project , " << "3 delete project , " << "4 go back" << std::endl;

	int option = 0;
	std::cin >> option;
	switch (option) {
	case 1:
		std::cout << "chose what project to open, enter a number" << std::endl;
		std::cin >> choise;
		trueChoise = trueChoise - choise;
		trueChoise = (trueChoise < 0) ? -trueChoise : trueChoise;
		open_project(trueChoise);
		break;
	case 2:
		add_new_proj();
		break;
	case 3:
		delete_project();
		break;
	case 4:
		go_back();
		break;
	};
};
int add_new_proj(void) {
	class_to_json_proj();
	return 0;
};
void delete_project(void) {
	int k = 0, trueChoise=1;
	std::cout << "Chose project to delete: ";
	std::cin >> k;
	trueChoise = trueChoise - k;
	trueChoise = (trueChoise < 0) ? -trueChoise : trueChoise;
	std::ifstream openJson("./userdata.json");
	nlohmann::json jsonData = nlohmann::json::parse(openJson);
	jsonData.erase(jsonData.begin() + trueChoise);
	std::ofstream inJson("./userdata.json");
	inJson << jsonData.dump(4);
	inJson.close();
	std::cout << "Project has been deleted" << std::endl;
	open_project_list();
};

void open_project(int trueChoise) {
	std::ifstream openJson("./userdata.json");
	nlohmann::json jsonData = nlohmann::json::parse(openJson);
	int temp = get_the_amount_of_proj();
	int  choise2 =0;
	int b = 0;
	int tasksAmount = get_number_of_tasks(trueChoise);
	for (int i = 1; i <= tasksAmount; i++) {
		std::cout << i << " Task name: " << jsonData[trueChoise]["Tasks"][b]["taskName"].get<std::string>() << '\n'
			<< "Description: " << jsonData[trueChoise]["Tasks"][b]["description"].get<std::string>() << '\n'
			<< "Completion" << jsonData[trueChoise]["Tasks"][b]["completion"] << std::endl;
		b++;
	}
	
	std::cout << "Chose an option" << "\n" << "1 mark task , " << "2 add new task , " << "3 delete task , " <<"4 change task " << "5 go back" << std::endl;
	std::cin >> choise2;
	switch (choise2) {
	case 1:
		mark_task(trueChoise);
		break;
	case 2:
		add_new_task(trueChoise);
		break;
	case 3:
		delete_task(trueChoise);
		break;
	case 4:
		change_task(trueChoise);
		break;
	case 5:
		go_back();
		break;
	}

};

void go_back(void) {
	interface();
};
int run_exit_sequence(void) {
	return 0;
};

void mark_task(int Proj) {
	std::ifstream json("./userdata.json");
	nlohmann::json jsonData = nlohmann::json::parse(json);
	int mark=0, task=0, trueChoise= 1;
	std::cout << "chose a task:";
	std::cin >> task;
	std::cout << "put a mark [1]->complete , [0]->incomplete :";
	std::cin >> mark;

	trueChoise = trueChoise- task;
	trueChoise = (trueChoise < 0) ? -trueChoise : trueChoise;
	jsonData[Proj]["Tasks"][trueChoise]["completion"] = mark;

	std::ofstream jsons("./userdata.json");
	jsons << jsonData.dump(4);
};


void change_task(int Proj) {
	std::ifstream json("./userdata.json");
	nlohmann::json jsonData = nlohmann::json::parse(json);
	int mark = 0, task = 0, trueChoise = 1;
	std::string line;
	std::cout << "chose a task:";
	std::cin >> task;
	std::cout << "what data to change, name[0],description[1]";
	std::cin >> mark;
	trueChoise = trueChoise - task;
	trueChoise= (trueChoise < 0) ? -trueChoise :trueChoise;
	switch (mark) {
	case 0:
		std::cout << "type new data: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, line);
		jsonData[Proj]["Tasks"][trueChoise]["taskName"] = line;
		std::cout << std::endl;
		break;
	case 1:
		std::cout << "type new data: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, line);
		jsonData[Proj]["Tasks"][trueChoise]["completion"] = line;
		std::cout << std::endl;
	}

	std::ofstream jsonO("./userdata.json");
	jsonO << jsonData.dump(4);
	jsonO.close();
	json.close();
	open_project_list();

}


void delete_task(int Proj) {
	int k = 0, trueChoise = 1;
	std::cout << "Chose task to delete: ";
	std::cin >> k;
	trueChoise = trueChoise - k;
	trueChoise = (trueChoise < 0) ? -trueChoise : trueChoise;
	std::ifstream openJson("./userdata.json");
	nlohmann::json jsonData = nlohmann::json::parse(openJson);
	jsonData[Proj]["Tasks"][trueChoise].erase(jsonData[Proj]["Tasks"][trueChoise].begin() + trueChoise);
	std::ofstream inJson("./userdata.json");
	inJson << jsonData.dump(4);
	inJson.close();
	std::cout << "Project has been deleted" << std::endl;
	open_project(Proj);

};
