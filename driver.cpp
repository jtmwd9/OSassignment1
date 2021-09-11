#include <iostream>
#include <string.h>

using namespace std;

int argHandler(int argc, char* argv[]) {
	if (argc > 1) {
		if (strcmp(argv[1], "-h") == 0) {
			cout << "Help\n";
			return -1;
		}else if (strcmp(argv[1], "-t") == 0) {
			cout << "Time\n";
			return 2;
		}else {
			cout << "File\n";
			return 1;
		}
	} else {
		cout << "None\n";
		return 0;
	}

}

int main(int argc, char* argv[]) {

	string fileName;	

	cout << "Hello\n";

	switch(argHandler(argc, argv)) {
		case -1:
			return 0;
		case 0:
			fileName = "testFile.txt";
			break;
		case 1:
			fileName = argv[1];
			break;
		case 2:
			break;
	}
	cout << "No help\n";
	return 0;

}
