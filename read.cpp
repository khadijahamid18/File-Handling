#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    system("cls");

    ifstream inf("write.txt");

    if (!inf)
    {
        cerr << "File opening failed";
        exit(0);
    }

    string line;

    while (getline(inf, line))
    {
        cout << line << endl;
    }

    inf.close();

    return 0;
}


// in this you cannot get full data 

// #include <iostream>
// #include <fstream>
// using namespace std;

// int main()
// {
//     ifstream infile;
//     infile.open("write.txt", ios::in); 

//     if (infile.is_open())
//     {
//         // Variables to store data read from the file
//         string stringValue;
//         int intValue;

//         // Read data from the file using >>
//         infile >> stringValue >> intValue;

//         // Output the read values
//         cout << "String Value: " << stringValue << endl;
//         cout << "Integer Value: " << intValue << endl;

//         infile.close();
//     }
//     else
//     {
//         cout << "Error: Unable to open the file." << endl;
//     }

//     return 0;
// }
