#ifndef DARS_H
#define DARS_H

#include <iostream>
#include "student.h"

class Dars
{
public:
    Dars();
    void importBA(std::istream &ins, std::ostream &outs);

    

private:
    Student student;
    std::string pascal(std::string &str);
};

#endif


