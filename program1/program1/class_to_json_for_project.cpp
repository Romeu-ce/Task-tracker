#include<iostream>
#include<fstream>
#include "interface.h"
#include <nlohmann/json.hpp>
#include <limits>
#include "SomeFunctions.h"

class Project {
public:
    int NumberOfTasks;
    std::string ProjectGoal;
    int ProjectID;
    std::string ProjectName;
    nlohmann::json Tasks = nlohmann::json::array();
 
    Project(int NumberOfTasks, std::string ProjectGoal, int ProjectID, std::string ProjectName)
        : NumberOfTasks(NumberOfTasks), ProjectGoal(ProjectGoal), ProjectID(ProjectID), ProjectName(ProjectName){
    };

};




namespace nlohmann {
    template<>
    struct adl_serializer<Project> {
        static void to_json(nlohmann::json& j, const Project& t) {
            j = nlohmann::json{
                {"NumberOfTasks", t.NumberOfTasks},
                {"ProjectGoal" , t.ProjectGoal },
                {"ProjectID" , t.ProjectID},
                {"ProjectName" , t.ProjectName},
                {"Tasks" , nlohmann::json::array()}
                
            };
        };
        static void from_json(const nlohmann::json& j, Project& t) {
            try {
                t.NumberOfTasks = j.at("NumberOfTasks").get<int>();
                t.ProjectGoal = j.at("ProjectGoal").get<std::string>();
                t.ProjectID = j.at("ProjectID").get<int>();
                t.ProjectName = j.at("taskNProjectNameame").get<std::string>();
                t.Tasks = j.at("Tasks").get<nlohmann::json>();
            }

            catch (const std::exception& e) {
                std::cout << "Invalid json format" << e.what() << std::endl;
            }

        };
    };
};


void class_to_json_proj() {
    int a = 0, d = 0;
    std::string b = "";
    std::string c = "";
    std::cin.ignore();

    std::cout << "adding new project, please write data";
    std::cout << std::endl;
    std::cout << "name of the project: ";
    std::getline(std::cin, b);
    
    std::cout << "goal of the project: ";
    std::getline(std::cin, c);
    
    std::cout << "how many tasks are planned to be: ";
    std::cin >> a;
    std::cout << std::endl;
    std::cout << "project ID(any number): ";
    std::cin >> d;
    std::cout << std::endl;

    std::ifstream jsonRead("./userdata.json");
    nlohmann::json data = nlohmann::json::parse(jsonRead);

    Project new_project(a, c, d, b);
    nlohmann::json j_class = new_project;
    data.push_back(j_class);



    std::ofstream jsonWrite("./userdata.json");
    jsonWrite << data;
    jsonRead.close();
    jsonWrite.close();
    open_project_list();
};

