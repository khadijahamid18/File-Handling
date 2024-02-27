#include "iostream"
#include "fstream"
#include "cstdio"
#include "string"

using namespace std;

class Student {
	int id;
	float marks;
	friend istream& operator >> (istream&, Student&);
	friend ostream& operator << (ostream&, Student&);

public:
	Student(int id = 0, float marks = 0.0f)
	{
		this->id = id;
		this->marks = marks;
	}

	void addStudent(ofstream* ptr)
	{
		ptr->write(reinterpret_cast<char*>(this), sizeof(Student));
	}

	static void displayAllStudent(ifstream* ptr)
	{
		Student temp;
		ptr->read(reinterpret_cast<char*>(&temp), sizeof(temp));
		while (!ptr->eof())
		{
			cout << temp;
			ptr->read(reinterpret_cast<char*>(&temp), sizeof(temp));
		}
	}

	bool findStudent(ifstream* ptr)
	{
		Student temp;
		while (!ptr->eof())
		{
			ptr->read(reinterpret_cast<char*>(&temp), sizeof(temp));
			if (this->id == temp.id && this->marks == temp.marks)
			{
				return true;
			}
		}
		return false;
	}

	void deleteStudent(ifstream* ptr)
	{
		Student tempstd;
		ofstream temp("temp.dat", ios::binary);
		if (!temp)
		{
			cerr << "File creation failed !";
			exit(0);
		}
		cout << "File created Successfully" << endl;
		while (!ptr->eof())
		{
			ptr->read(reinterpret_cast<char*>(&tempstd), sizeof(temp));
			if (tempstd.id == this->id && tempstd.marks == this->marks)
			{
				continue;
			}
			temp.write(reinterpret_cast<char*>(&tempstd), sizeof(temp));
		}
		temp.close();
		ptr->close();
		remove("test.dat");
		rename("temp.dat", "test.dat");
	}

};

istream& operator >> (istream&cin, Student& std)
{
	cout << "Enter Student Id : ";
	cin >> std.id;
	cout << "Enter Student Marks : ";
	cin >> std.marks;
	return cin;
}
ostream& operator << (ostream& cout, Student& std)
{
	cout << "Id : " << std.id << '\t' << "Marks : " << std.marks << endl;
	return cout;
}



int main()
{
	Student s1(1,23),s2(2,34),s3(3,1231),temp;

	ofstream outf("test.dat", ios::binary);
	
	if (!outf)
	{
		cerr << "File creation failed !";
		exit(0);
	}
	cout << "File created Successfully" << endl;

	s1.addStudent(&outf);
	s2.addStudent(&outf);
	s3.addStudent(&outf);
	outf.close();

	ifstream inf("test.dat", ios::binary);

	if (!inf)
	{
		cerr << "File opening failed !";
		exit(0);
	}
	cout << "File opened Successfully" << endl;

	cout << "Status(found/not-found) : " << temp.findStudent(&inf) << endl;
	// Student::displayAllStudent(&inf);
	inf.close();
	// s1.deleteStudent(&inf);
	/*

	ifstream inf1("test.dat", ios::binary);

	if (!inf1)
	{
		cerr << "File opening failed !";
		exit(0);
	}
	cout << "File opened Successfully" << endl;

	Student::displayAllStudent(&inf);

	inf.close();
	
	*/



	return 0;
}