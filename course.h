#ifndef COURSE_H
#define COURSE_H

#include <iostream>

class Course
{
public:
    Course(const std::string &n = "", const std::string &code = "", const std::string &g = "", const double &creds = 0, const bool isComp = false);

    // getters

    // setters

private:
    std::string courseName;
    std::string courseCode;
    std::string grade;
    double credits;
    bool isComplete;
};

#endif