#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    system("cls");
    ofstream outf("fileWrite.txt");
    string data;

    if (!outf)
    {
        cerr << "File creation failed";
        exit(0);
    }

    cout << "File created successfully!" << endl;

    cout << "Enter the data to write in a file" << endl;
    getline(cin, data);
    outf << data << endl;
    cout << "Data is written in the file" << endl;
    outf << "13" << endl;

    outf.close();
    

    return 0;
}