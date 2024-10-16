#include "dars.h"


using namespace std;

Dars::Dars()
{
}

void Dars::import(istream &ins, ostream &outs)
{
    char c;
    string tmp;
    while (ins.peek() != '_')
    {
        ins.get(c);
        outs << c;
    }
    ins.ignore(300, '\n');
    outs << endl;
    getline(ins, tmp, '|');
    outs << tmp;
}