#ifndef DEGREEPROGRAM_H
#define DEGREEPROGRAM_H

#include <iostream>
#include <vector>
#include "course.h"

class DegreeProgram
{
public:
    // constructors
    DegreeProgram();

    // getters

    // setters


private:
    std::string degreeName;
    std::string degreeType;
    std::vector<Course> requiredCourses;
    std::vector<Course> electiveCourses;
};

#endif