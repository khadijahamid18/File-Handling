#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    system("cls");
    fstream inf("binaryFile.dat");

    if (!inf)
    {
        cerr << "File creation failed";
        exit(0);
    }

    int temp = 4;

    inf.read(reinterpret_cast<char *>(&temp), sizeof(int));

    cout << "Data is read from the file" << endl;

    inf.close();

    return 0;
}