#include <iostream>
#include <fstream>

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
        name[0] = '\0';
    }

    Record(int _id, const char *_name, float _salary) : id(_id), salary(_salary)
    {
        int i = 0;
        while (_name[i] != '\0' && i < 49)
        {
            name[i] = _name[i];
            i++;
        }
        name[i] = '\0';
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
    void updateRecord(int _id, const char *_name, float _salary) 
    {
        id = _id;
        int i = 0;
        while (_name[i] != '\0' && i < 49)
        {
            name[i] = _name[i];
            i++;
        }
        name[i] = '\0';
        salary = _salary;
    }
};

int main()
{
    const char *fileName = "records.dat";

    // Example usage
    Record record1(1, "Alice", 50000.5);
    Record record2(2, "Bob", 60000.75);
    Record updatedRecord;

    // Writing records to the file
    fstream file(fileName, ios::binary | ios::out);
    record1.writeToFile(file);
    record2.writeToFile(file);
    file.close();

    // Displaying records before update
    cout << "Records before update:" << endl;
    file.open(fileName, ios::binary | ios::in);
    Record tempRecord;
    while (file.read(reinterpret_cast<char *>(&tempRecord), sizeof(Record)))
    {
        tempRecord.display();
    }
    file.close();

    // Updating a record
    int idToUpdate = 2;
    const char *newName = "Bob Updated";
    float newSalary = 65000.0;

    file.open(fileName, ios::binary | ios::in | ios::out);
    while (file.read(reinterpret_cast<char *>(&tempRecord), sizeof(Record)))
    {
        if (tempRecord.getId() == idToUpdate)
        {
            // Update the record
            updatedRecord.updateRecord(idToUpdate, newName, newSalary);
            file.seekp(-sizeof(Record), ios::cur);
            updatedRecord.writeToFile(file);
            break;
        }
    }
    file.close();

    // Displaying records after update
    cout << "\nRecords after update:" << endl;
    file.open(fileName, ios::binary | ios::in);
    while (file.read(reinterpret_cast<char *>(&tempRecord), sizeof(Record)))
    {
        tempRecord.display();
    }
    file.close();

    return 0;
}

//  DELETING A FILE

// #include <cstdio> // Include the necessary header for the remove() function

// int main() {
//     const char* fileName = "example.bin";

//     // Check if the file exists before attempting to delete it
//     if (remove(fileName) != 0) {
//         perror("Error deleting file"); // Print an error message if deletion fails
//     } else {
//         cout << "File successfully deleted" << endl;
//     }

//     return 0;
// }
