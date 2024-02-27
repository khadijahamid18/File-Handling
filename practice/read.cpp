#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    system("cls");
    ifstream inf("fileWrite.txt");

    if (!inf)
    {
        cerr << "File opening failed";
        exit(0);
    }

    string str;
    while (getline(inf, str))
    {
        cout << str << endl;
    }
    
    inf.close();
    

    return 0;
}