#include "course.h"

using namespace std;

Course::Course(const std::string &n, const std::string &code, const std::string &g, const double &creds, const bool isComp)
    : courseName(n), courseCode(code), grade(g), credits(creds), isComplete(isComp) {}
