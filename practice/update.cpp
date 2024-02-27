#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    system("cls");
    fstream file;
    file.open("fileWrite.txt", ios ::out | ios ::in);

    if (file.is_open())
    {
        string data;
        getline(file, data);

        data += "Updated Data";

        file.seekp(0);

        file.close();

        file.open("fileWrite.txt", ios ::out | ios ::in);

        file << data;

        file.close();

        cout << "File updated successfully" << endl;
    }
    else
    {
        cout << "Error opening the file" << endl;
    }

    return 0;
}