#include <iostream>
#include <fstream>
#include "Program.h"
using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Incorrect command line! Waited: command in_file out_file" << endl;
		exit(1);
	}

	ifstream inFileStream(argv[1]);
	ofstream outFileStream(argv[2]);

	cout << "Start" << endl;
	container c;

	c.inContainer(inFileStream);
	cout << "Filled container. " << endl;

	c.outContainer(outFileStream);

	c.clearContainer();
	cout << "Empty container. " << endl;
	c.outContainer(outFileStream);

	cout << "Stop" << endl;
	system("pause");
	return 0;
}
