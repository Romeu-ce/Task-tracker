#include<iostream>
#include<fstream>
#include "interface.h"
#include <nlohmann/json.hpp>
#include <limits>
#include "SomeFunctions.h"

class Task {
public:
    int completion;
    std::string description;
    int taskID;
    std::string taskName;
   
    Task(int completion, std::string description, int taskID, std::string taskName)
        : completion(completion), description(description), taskID(taskID), taskName(taskName) {
    };
    
};
namespace nlohmann {
    template<>
    struct adl_serializer<Task> {
        static void to_json(nlohmann::json& j, const Task& t) {
            j = nlohmann::json{
                {"completion", t.completion},
                { "description" , t.description },
                {"taskID" , t.taskID},
                {"taskName" , t.taskName}
            };
        };
        static void from_json(const nlohmann::json& j, Task& t) {
            try {
                t.completion = j.at("completion").get<int>();
                t.description = j.at("description").get<std::string>();
                t.taskID = j.at("taskID").get<int>();
                t.taskName = j.at("taskName").get<std::string>();
            }

            catch (const std::exception& e) {
                std::cout << "Invalid json format" << e.what() << std::endl;
            }

        };
    };
};
    void class_to_json(int Proj) {
        int a = 0, d = 0;
        std::string b = "";
        std::string c = "";
        std::cin.ignore();
        std::cout << "adding new task, please write data" << '\n';
        std::cout << "name of the task: ";
        std::getline(std::cin, c);
        std::cout << std::endl;
        std::cout << "description of the task: ";
        std::getline(std::cin, b);
        std::cout << std::endl;
        std::cout << "completion status[0]->incomplete,[1]->complete: ";
        std::cin >> a;
        std::cout << std::endl;
        std::cout << "task ID(any number): ";
        std::cin >> d;
        std::cout << std::endl;

        std::ifstream jsonRead("./userdata.json");
        nlohmann::json data = nlohmann::json::parse(jsonRead);

        Task new_task(a, c, d, b);
        nlohmann::json j_class = new_task;
        data[Proj]["Tasks"].push_back(j_class);
        


        std::ofstream jsonWrite("./userdata.json");
        jsonWrite << data;
        jsonRead.close();
        jsonWrite.close();
        open_project(Proj);
    };

