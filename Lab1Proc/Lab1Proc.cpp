#include <iostream>
#include <fstream>
#include "container.h"

using namespace std;

namespace nature {
	// Сигнатуры требуемых внешних функций
	void Init(container& c);
	void Clear(container& c);
	void InContainer(container& c, ifstream& ifst);
	void OutContainer(container& c, ofstream& ofst);
	void OutOnlyTrees(container& c, ofstream& ofst);
}
using namespace nature;

int main(int argc, char* argv[])
{
	if (argc != 3) {
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		return 0;
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	if (!ifst)
	{
		cout << "file doesn't exist" << endl;
		return 0;
	}
	cout << "Start" << endl;
	container c;
	Init(c);
	InContainer(c, ifst);
	ofst << "Filled container. " << endl;
	OutOnlyTrees(c, ofst);
	Clear(c);
	ofst << "Empty container. " << endl;
	//OutContainer(c, ofst);
	cout << "Stop" << endl;
	return 0;
}
