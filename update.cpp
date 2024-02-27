// #include <iostream>
// #include <fstream>

// using namespace std;

// int main()
// {
//     system("cls");

//     fstream file;
//     file.open("write.txt", ios ::in | ios ::out);

//     if (file.is_open())
//     {
//         string data;

//         // read data from the file
//         file >> data;

//         // modifying data
//         data += "Updated";

//         // move the pointer to the begining of the file
//         file.seekp(0);

//         // write the updated data into the file
//         file << data;

//         file.close();
//     }
//     else
//     {
//         cout << "Error in opening the file";
//         exit(0);
//     }

//     return 0;
// }

#include <iostream>
#include <fstream>
#include<string>

using namespace std;

int main()
{
    fstream file;
    file.open("filename.txt", ios::in | ios::out);

    if (file.is_open())
    {
        // Read data from the file
        string data;
        getline(file, data);

        // Modify the data (for example, append something to it)
        data += "Khadija here";

        // Clear the existing content in the file
        file.close();
        file.open("filename.txt", ios::out | ios::trunc);

        // Write the updated data back to the file
        file << data;

        // Close the file
        file.close();

        cout << "File updated successfully." << endl;
    }
    else
    {
        cout << "Error: Unable to open the file." << endl;
    }

    return 0;
}
