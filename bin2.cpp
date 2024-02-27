#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Record
{
private:
    int id;
    char name[50];
    float salary;

public:
    // Constructors
    Record() : id(0), salary(0.0)
    {
        memset(name, 0, sizeof(name));
    }

    Record(int _id, const char *_name, float _salary) : id(_id), salary(_salary)
    {
        strncpy(name, _name, sizeof(name) - 1);
    }

    // Member functions
    void display()
    {
        cout << "ID: " << id << ", Name: " << name << ", Salary: " << salary << endl;
    }

    // Getter functions
    int getId() const
    {
        return id;
    }

    // Function to read/write records to a binary file
    void writeToFile(fstream &file) const
    {
        file.write(reinterpret_cast<const char *>(this), sizeof(Record));
    }

    void readFromFile(fstream &file)
    {
        file.read(reinterpret_cast<char *>(this), sizeof(Record));
    }

    // Function to update a record
    void updateRecord(const char *_name, float _salary)
    {
        strncpy(name, _name, sizeof(name) - 1);
        salary = _salary;
    }
};

int main()
{
    const char *fileName = "records.dat";

    // Example usage
    Record record1(1, "Alice", 50000.5);
    Record record2(2, "Bob", 60000.75);
    Record updatedRecord(2, "Bob Updated", 65000.0);

    // Writing records to the file
    fstream file(fileName, ios::binary | ios::out);
    record1.writeToFile(file);
    record2.writeToFile(file);
    file.close();

    // Displaying records before update
    cout << "Records before update:" << endl;
    file.open(fileName, ios::binary | ios::in);
    Record tempRecord;
    while (file)
    {
        tempRecord.readFromFile(file);
        if (file.eof())
        {
            break;
        }
        tempRecord.display();
    }
    file.close();

    // Updating a record
    file.open(fileName, ios::binary | ios::in | ios::out);
    // while (file)
    // {
    //     tempRecord.readFromFile(file);
    //     if (tempRecord.getId() == updatedRecord.getId())
    //     {
    //         // Update the record
    //         tempRecord.updateRecord(updatedRecord);
    //         file.seekp(-sizeof(Record), ios::cur);
    //         tempRecord.writeToFile(file);
    //         break;
    //     }
    // }
    // file.close();

    // Displaying records after update
    cout << "\nRecords after update:" << endl;
    file.open(fileName, ios::binary | ios::in);
    while (file)
    {
        tempRecord.readFromFile(file);
        if (file.eof())
        {
            break;
        }
        tempRecord.display();
    }
    file.close();

    return 0;
}
