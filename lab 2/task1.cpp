#include <iostream>
#include <fstream>
#include "string"
#include "stdio.h"

using namespace std;

int arrayToFile(string fileName, int *array, int size)
{
    ofstream outf(fileName, ios::binary);

    if (!outf)
    {
        cerr << "There is an error in File opening!";
        exit(0);
    }

    cout << "file has been opened to write" << endl;
    outf.write(reinterpret_cast<char *>(array), sizeof(int) * size);
    // outf.write(reinterpret_cast<char*>(array), sizeof(size));
    outf.close();
}

int fileToArray(string fileName, int *array, int size)
{
    ifstream inf("fileName.dat", ios::binary);

    if (!inf)
    {
        cerr << "There is an error in File opening!";
        exit(0);
    }

    cout << "file has been opened to read" << endl;

    inf.read(reinterpret_cast<char *>(array), sizeof(int));
    // inf.read(reinterpret_cast<char*>(array), sizeof(size));
    inf.close();
}

int main()
{
    system("cls");
    string name = "test.dat";

    int arr[] = {1, 5, 3, 8, 2};
    int size = sizeof(arr) / sizeof(int);

    // Writing the file
    arrayToFile(name, arr, size);
    cout << "File has been written" << endl;

    // Reading the file
    fileToArray(name, arr, size);

    cout << "File has been read" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}