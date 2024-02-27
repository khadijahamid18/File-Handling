#include <iostream> 
#include <fstream>
#include <string>

using namespace std;

class Student
{
private:
    int id;
    float marks;

    friend istream &operator>>(istream &, Student &);
    friend ostream &operator<<(ostream &, const Student &);

public:
    Student(int id = 0, float marks = 0.0f);

    void addStudent(ofstream &outFile)
{
    outFile << id << " " << marks << endl;
    cout << "Data written to file (student.dat)." << endl;
}

void displayAllStudents(ifstream &inFile)
{
    int id;
    float marks;
    while (inFile >> id >> marks)
    {
        cout << "ID: " << id << ", Marks: " << marks << endl;
    }
}
  
    bool findStudent(ifstream &inFile)
{
    int searchId;
    cout << "Enter ID to search: ";
    cin >> searchId;

    int id;
    float marks;
    while (inFile >> id >> marks )
    {
        if (id == searchId)
        {
            cout << "Student found: ID : " << id << ", Marks : " << marks << endl;
            return true;
        }
    }

    cout << "Student not found." << endl;
    return false;
}
  

void deleteStudent(ifstream &inFile)
{
    string tempFileName = "temp.dat";
    ofstream tempFile(tempFileName);
    int deleteId;
    cout << "Enter ID to delete: ";
    cin >> deleteId;

    int id;
    float marks;
    bool deleted = false;
    while (inFile >> id )
    {
        if (id == deleteId)
        {
            
            cout<<deleteId ; 

            deleted = true;
        }
        else
        {
            tempFile << id << " " << marks << endl;
        }
    }

    inFile.close();
    tempFile.close();

    remove("student.dat");
    rename(tempFileName.c_str(), "student.dat");

    if (deleted)
    {
        cout << "Student with ID " << deleteId << " deleted." << endl;
    }
    else
    {
        cout << "Student not found." << endl;
    }
}
};

Student::Student(int id, float marks) : id(id), marks(marks) {}

istream &operator>>(istream &in, Student &s)
{
    cout << "Enter ID: ";
    in >> s.id;
    cout << "Enter Marks: ";
    in >> s.marks;
    return in;
}

ostream &operator<<(ostream &out, const Student &s)
{
    out << "ID: " << s.id << ", Marks: " << s.marks;
    return out;
}



int main()
{
    ofstream outFile("student.dat", ios::app);
    if (!outFile)
    {
        cerr << "Error opening file." << endl;
        return 1;
    }

    while (true)
    {
        cout << "\nMenu:\n"
                  << "1. Add Student\n"
                  << "2. Find Student\n"
                  << "3. Delete Student\n"
                  << "4. Display All Students\n"
                  << "5. Quit\n";

        int choice;
        cin >> choice;

        ifstream inFile("student.dat");
        if (!inFile && (choice != 1))
        {
            cerr << "File not found or empty. Please add a student first." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            Student student;
            cin >> student;
            student.addStudent(outFile);
            break;
        }
        case 2:
        {
            Student student;
            student.findStudent(inFile);
            break;
        }
        case 3:
        {
            Student student;
            student.deleteStudent(inFile);
            break;
        }
         case 4:
        {
            Student student;
            student.displayAllStudents(inFile);
            break;
        }
        default : 
        {
        break;
        }
        return 0;
        }
    }
}