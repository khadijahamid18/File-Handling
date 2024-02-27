#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    system("cls");
    fstream outf("binaryFile.dat");

    if (!outf)
    {
        cerr << "File creation failed";
        exit(0);
    }

    int temp = 4;

    outf.write(reinterpret_cast<char *>(&temp), sizeof(int));

    cout << "Data written in the file" << endl;

    outf.close();

    return 0;
}