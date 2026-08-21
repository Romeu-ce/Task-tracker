#pragma once
int get_number_of_tasks(int t);
int get_number_of_compl_tasks(int t);
int add_new_task(void);
void open_project_list(void);
void open_project(int trueChoise);
int add_new_proj(void);
void delete_project(void);
int run_exit_sequence(void);
void delete_task(int Proj);
void mark_task(int Proj);
void change_task(int Proj);
void go_back(void);