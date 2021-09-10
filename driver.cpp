#include <iostream>
#include <string.h>

using namespace std;

int getArg(int argc, char* argv[]) {
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

	cout << "Hello\n";

	getArg(argc, argv);

	return 0;

}
