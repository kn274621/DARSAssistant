#include "dars.h"

using namespace std;

Dars::Dars()
{
}

void Dars::importBA(istream &ins, ostream &outs)
{
    string tmp;

    /// pid
    ins.ignore(100, '\n');    
    ins.ignore(100, '\n');
    ins >> tmp;
    outs << tmp << endl;
    student.setPID(tmp);

    /// student name
    ins.ignore(100, '\n');
    getline(ins, tmp, '.');
    outs << pascal(tmp) << endl;
    student.setName(pascal(tmp));

    /// catalog year
    ins.ignore(10, ':');
    ins >> tmp;
    outs << tmp << endl;
    student.setCatalogYear(tmp);

    /// college
    ins.ignore(300, '\n');
    ins.ignore(100, '\n');
    ins.ignore(100, '\n');
    ins.ignore(200, '\n');
    ins.ignore(10, ' ');
    getline(ins, tmp, '|');
    outs << tmp << endl;
    student.setCollege(tmp);
}

string Dars::pascal(string &str)
{
    bool newWord = false;
    int wordLength = 1;
    str[0] = toupper(str[0]);
    for (size_t i = 1; i < str.length(); i++)
    {
        if (newWord == false)
        {
            str[i] = tolower(str[i]);
            wordLength++;
        }
        else
        {
            str[i] = toupper(str[i]);
            newWord = false;
            wordLength++;
        }

        if (str[i] == ' ')
        {
            newWord = true;
            if (wordLength <= 4)
            {
                str[i - wordLength + 1] = tolower(str[i - wordLength + 1]);
            }
            wordLength = 0;
        }
    }
    return str;
}