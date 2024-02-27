#include <iostream>
#include <string>
#include <fstream>
#include<stdio.h>

using namespace std;

class Student
{
    int id;
    float marks;
    // overload stream extraction operator to get data of a student from user
    friend istream &operator>>(istream &, Student &);
    // overload stream insertion operator to display the data of a student
    friend ostream &operator<<(ostream &, const Student &);

public:
    // constructor
    Student(int id = 0, float marks = 0.0f);

    void addStudent(ofstream& outputFile)
    {
        outputFile.write(reinterpret_cast<char*>(this), sizeof(Student));
        cout << "Student data added successfully" << endl;
    }

    void displayStudent(ifstream& inputFile) 
    {
        if(!inputFile)
        {
            cerr << "File opening failed" << endl;
        }
        inputFile.read(reinterpret_cast<char*>(this), sizeof(Student));
    }

    void findStudent(ifstream& inputFile) 
    {
        bool check = false;

        if(!inputFile)
        {
            cerr << "File opening failed" << endl;
        }

        while (!inputFile.eof())
        {
            inputFile.seekg(0, ios::beg);
            inputFile.read(reinterpret_cast<char*>(this), sizeof(Student));
        }   
    }
    
};


int main()
{
    system("cls");
    ofstream file("student.dat");

    Student object(1, 1.1f), obj2(2, 2.2f);

    return 0;
}