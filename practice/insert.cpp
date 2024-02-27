#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    system("cls");
    fstream file("FileWrite.txt", ios::out | ios::app);

    if (file.is_open())
    {
        file << "Khadija here" << endl;
        file << "Alhamdullilah for everything" << endl;

        cout << "Data inserted successfully" << endl;
    }
    else
    {
        cerr << "File opening failed" << endl;
    }

    file.close();

    return 0;
}