#ifndef DEGREEPLAN_H
#define DEGREEPLAN_H

#include <iostream>
#include <vector>
#include "course.h"

class DegreePlan
{
public:
    // constructors
    DegreePlan(const std::string &n = "", const std::string &t = "", const std::string &c = "")
        : planName(n), planType(t), planCode(c) {}

    // getters

    // setters
    void setDegreeName(const std::string &n) { planName = n; }

private:
    std::string planName;
    std::string planType;
    std::string planCode;
    std::vector<Course> requiredCourses;
    std::vector<Course> electiveCourses;
};

#endif