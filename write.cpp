#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    system("cls");

    ofstream outf("write.txt");

    if (!outf)
    {
        cerr << "File creation failed";
        exit(0);
    }

    outf << "Hello people" << endl;
    outf << "It's Khadija" << endl;
    outf << "Learning to write in a file" << endl;
    outf << "PLz pray" << endl;

    cout << "OK" << endl;
    outf.close();

    return 0;
}



// #include <iostream>
// #include <fstream>
// using namespace std;

// int main()
// {
//     system("cls");
    
//     ofstream outfile;
//     outfile.open("filename.txt", ios::out);

//     if (outfile.is_open())
//     {
//         outfile << "Hello, World!" << endl;
//         outfile << 42 << endl;
//         outfile.close();
//         cout << "Data written to the file successfully." << endl;
//     }
//     else
//     {
//         cout << "Error: Unable to open the file." << endl;
//     }

//     return 0;
// }
