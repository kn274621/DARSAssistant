#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include "degreeProgram.h"

class Student
{
public:
    // constructor
    Student();



private:
    std::string name;
    std::string pid;
    std::string catalogYear;
    std::string college;
    std::vector<DegreeProgram> majors;
    std::vector<DegreeProgram> minors;
    std::vector<DegreeProgram> certificates;
    std::vector<DegreeProgram> honors;
};

#endif