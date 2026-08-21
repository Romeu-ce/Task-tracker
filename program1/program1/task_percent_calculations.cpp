
// The SUM of all tasks canNOT be more then 100%, it have to be even and an integer
#include "task_percent_calculations.h"
#include "SomeFunctions.h"
extern int k;

static int setK(int a) {
	k = a;
	return 0;
};


int Tasks_computation(int t) {
	int numberOFtasks = get_number_of_tasks(t);
	int numberOFcomplTasks = get_number_of_compl_tasks(t);
	if (numberOFtasks == 0) {
		numberOFtasks = 1;
	}
	int TrueValue =  (100 * numberOFcomplTasks)/ numberOFtasks;
	
	if (numberOFcomplTasks == numberOFtasks) {
		setK(100);
	}
	else if (TrueValue % 2 == 0) {
		setK(TrueValue);
	}

	else if (TrueValue % 2 != 0) { // i want only even number
		TrueValue = TrueValue - 1;
		setK(TrueValue);
	};

	
	return 0;
}