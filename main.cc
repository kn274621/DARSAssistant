#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // declare variables for reading/writing to a file
    ifstream fin;
    ofstream fout;
    string filename;

    cout << "|---------------------------------------------------------|\n"
         << "|              Welcome to the DARS Assistant              |\n"
         << "|---------------------------------------------------------|\n";

    fin.open("dars.txt");
    if (fin.fail())
    {
        cout << "|               \033[31mERROR: \"dars.txt\" not found.\033[0m              |\n"
             << "|                                                         |\n"
             << "|  To import your DARS, download a PDF from your Student  |\n"
             << "|   Center, copy ALL text into a file called \"dars.txt\",  |\n"
             << "|              and then relaunch the program.             |\n"
             << "|---------------------------------------------------------|\n";
        exit(1);
    }

    return 0;
}
