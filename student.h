#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include "degreePlan.h"

class Student
{
public:
    // default constructor, itializes all strings to "" and every vector with one default DegreeProgram object
    Student(const std::string &n = "", const std::string &p = "", const std::string &y = "", const std::string &c = "", const std::string &d = "")
        : name(n), pid(p), catalogYear(y), college(c), degreeTrack(d) {}

    // getters
    DegreePlan getMajor(const int &i) { return majors[i]; }
    DegreePlan getMinor(const int &i) { return minors[i]; }
    DegreePlan getCertificate(const int &i) { return certificates[i]; }
    DegreePlan getHonor(const int &i) { return honors[i]; }

    // setters
    void setName(const std::string &n) { name = n; }
    void setPID(const std::string &p) { pid = p; }
    void setCatalogYear(const std::string &y) { catalogYear = y; }
    void setCollege(const std::string &c) { college = c; }
    void setDegreeTrack(const std::string &d) { degreeTrack = d; }

    void addMajor(const DegreePlan &d = DegreePlan()) { majors.push_back(d); }
    void addMinor(const DegreePlan &d = DegreePlan()) { minors.push_back(d); }
    void addCertificate(const DegreePlan &d = DegreePlan()) { certificates.push_back(d); }
    void addHonor(const DegreePlan &d = DegreePlan()) { honors.push_back(d); }

private:
    std::string name;
    std::string pid;
    std::string catalogYear;
    std::string college;
    std::string degreeTrack;
    std::vector<DegreePlan> majors;
    std::vector<DegreePlan> minors;
    std::vector<DegreePlan> certificates;
    std::vector<DegreePlan> honors;
};

#endif