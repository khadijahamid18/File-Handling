#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    system("cls");
    const char * file = "fileWrite.txt";

    if (remove(file) == 0)
    {
        cout << "File deleted successfully" << endl;
    }
    else
    {
        cout << "Error deleting the file" << endl;
    }
    
    
    

    return 0;
}