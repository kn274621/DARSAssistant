#include "dars.h"

using namespace std;

Dars::Dars()
{
}

void Dars::importBA(istream &ins, ostream &outs)
{
    char c;
    string tmp;

    ins.ignore(27);
    getline(ins, tmp);

    /**while (ins.peek() != '_')
    {
        ins.get(c);
        outs << c;
    }
    ins.ignore(300, '\n');
    outs << endl;
    getline(ins, tmp, '|');
    outs << tmp;*/
}