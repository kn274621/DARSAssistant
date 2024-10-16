#ifndef PROGRAMS_H
#define PROGRAMS_H

#include <iostream>

class Programs
{
public:
    Programs();
    std::string const get(std::string prog);

    private:
    std::string major, minor, honor, cert, graduation;
};

#endif