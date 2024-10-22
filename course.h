#ifndef COURSE_H
#define COURSE_H

#include <iostream>

class Course
{
public:
    // default constructor, initializes all strings to "", credits to 0, and completed to false
    Course(const std::string &n = "", const std::string &code = "", const std::string &g = "", const double &creds = 0, const bool isComp = false)
        : courseName(n), courseCode(code), grade(g), credits(creds), isComplete(isComp) {}

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