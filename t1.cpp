#include "iostream"
#include "fstream"
#include "string"
#include "stdio.h"

using namespace std;

int arrayToFile(string fileName, int *arr, int size)
{
	ofstream outf("fileName.dat", ios::binary);

	if (!outf)
	{
		cerr << "File creation failed!!";
		exit(0);
	}

	outf.write(reinterpret_cast<char*>(arr), sizeof(int) * size);

	outf.close();
}

int fileToArray(string fileName, int* arr, int size)
{
	ifstream inf("fileName.dat", ios::binary);

	if (!inf)
	{
		cerr << "File creation failed!!";
		exit(0);
	}

	inf.read(reinterpret_cast<char*>(arr), sizeof(int) * size);

	inf.close();
}

int main()
{
	const string fileName = "data.dat";
	int dataWrite[5] = {1, 2, 3, 4, 5};

	//int dataSize = sizeof(dataWrite) / sizeof(int);

	//const int size = dataSize;

	int dataRead[5];

	arrayToFile(fileName , dataWrite, 5);

	fileToArray(fileName, dataRead, 5);

	for (int i = 0; i < 5; i++)
	{
		cout << dataWrite[i] << endl;
	}
	return 0;
}