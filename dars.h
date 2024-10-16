#ifndef DARS_H
#define DARS_H

#include <iostream>
#include "student.h"

class Dars
{
    public:
    Dars();
    void import(std::istream &ins, std::ostream &outs);
    
    private:
        Student student;
};

#endif