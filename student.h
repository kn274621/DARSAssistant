#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <list>
#include "programs.h"

class Student
{
public:
    Student();
    std::string get(std::string info)const;
    
private:
    std::string name, pid, advisor, mentor;
    int catelog;
    float gpa;
    Programs program;
};

#endif