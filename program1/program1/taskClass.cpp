#include<iostream>
void AddTask(Task& task1, int ID, char name1[], char description1[]);

class Project {
    int ProjectID;
    char ProjectName[30];
    char ProjectGoal[50];
    int NumberOfTasks;
    int completion_ofthe_project;
};

class Task {
public:
    int taskID;
    char taskName[20];
    char description[100];
    bool completion;
};

int main() {
    int ID;
    char name1[20];
    char description1[100];
    Task task1;

 
    return 0;
}

void AddTask(Task& task1,int ID,char name1[], char description1[]) {
    task1.taskID = ID;
    strcpy(task1.taskName, name1);
    strcpy(task1.description, description1);
};