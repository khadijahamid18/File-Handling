#include <iostream>
#include "string"
#include "fstream"

using namespace std;

int main()
{
    system("cls");
    ifstream inf("student.txt");
    if (!inf)
    {
        cerr << "File creation failed" << endl;
    }
    int rollNumber;
    string firstName;
    string lastName;
    int marks;

    cout << "Roll Number \t Name \t Marks" << endl;
    inf >> rollNumber >> firstName >> lastName >> marks;
    cout << rollNumber <<"\t" << firstName << "\t" << lastName << "\t" << marks << endl;

    while (inf >> rollNumber >> firstName >> lastName >> marks) 
    {
        cout << rollNumber <<"\t" << firstName << "\t" << lastName << "\t" << marks << endl;
    }

    // while (!inf.eof()) 
    // {
    //     cout << rollNumber <<"\t" << firstName << "\t" << lastName << "\t" << marks << endl;
    //     inf >> rollNumber >> firstName >> lastName >> marks;
    // }

    inf.close();

    return 0;
}
