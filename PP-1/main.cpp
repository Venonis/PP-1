#include "task.h"
#include <iostream>

using namespace std;

int main() {
	int x;
	cin >> x;
	cout << "\n\n";

	switch (x) {
	case 2:
		task2();
		break;
	case 3:
		task3();
		break;
	case 4:
		task4();
		break;
	case 5:
		task5();
		break;
	case 6:
		task6();
		break;
	case 7:
		task7();
		break;
	case 8:
		task8();
		break;
	case 9:
		task9();
		break;
	case 10:
		task10();
		break;
	case 11:
		task11();
		break;
	case 12:
		task12();
		break;
	default: 
		main();
	}
	return 0;
}