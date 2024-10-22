#include <iostream>
#include <fstream>
#include "dars.h"
using namespace std;

int main(int argc, char *argv[]) 
{
    // declare variables for reading/writing to a file
    ifstream fin;
    ofstream fout;
    string filename = argv[1];
    Dars myDars;

    cout << "|---------------------------------------------------------|" << endl
         << "|              Welcome to the DARS Assistant              |" << endl
         << "|---------------------------------------------------------|" << endl;

    fin.open(filename + ".txt");
    if (fin.fail())
    {
        cout << "|               \033[31mERROR: \"dars.txt\" not found.\033[0m              |" << endl
             << "|                                                         |" << endl
             << "|  To import your DARS, download a PDF from your Student  |" << endl
             << "|   Center, copy ALL text into a file called \"dars.txt\",  |" << endl
             << "|              and then relaunch the program.             |" << endl
             << "|---------------------------------------------------------|" << endl;
        exit(1);
    }
    fout.open("output.txt");
    myDars.importBA(fin, fout);
    fout.close();

    return 0;
}
