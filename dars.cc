#include "dars.h"

using namespace std;

void Dars::importBA(istream &ins, ostream &outs)
{
    string tmp, data, plan;
    bool isFound = false;

    /// SECTION: HEADER
    // pid
    ins.ignore(100, '\n');
    ins.ignore(100, '\n');
    ins >> data;
    outs << data << endl;
    student.setPID(data);

    // student name
    ins.ignore(100, '\n');
    getline(ins, data, '.');
    outs << pascal(data) << endl;
    student.setName(pascal(data));

    /// SECTION: STUDENT INFO
    // college - ex. College of...
    while (!isFound)
    {
        if (tmp.find("COLLEGE: ") != string::npos)
        {
            // eliminate leading and trailing characters
            if (tmp.size() >= 11)
            {
                data = tmp.substr(tmp.find("COLLEGE: ") + 9);
                data = data.substr(0, data.find(" |"));
            }
            outs << data << endl;
            student.setCollege(data);
            isFound = true;
        }
        else
            getline(ins, tmp);
    }

    // degree program type ("plan") - ex. major, minor, honors, certificate
    isFound = false;
    while (!isFound)
    {
        if (tmp.find("PLAN: ") != string::npos)
        {
            // eliminate leading and trailing characters
            if (tmp.size() >= 11)
            {
                data = tmp.substr(tmp.find("PLAN: ") + 6);
                data = data.substr(0, data.find(" CODE"));
            }
            outs << data << endl;
            plan = data;
            isFound = true;

            if (plan == "Major")
                student.addMajor();
            else if (plan == "Minor")
                student.addMinor();
            else if (plan == "Certificate")
                student.addCertificate();
            else if (plan == "Honor")
                student.addHonor();
        }
        else
            getline(ins, tmp);
    }

    // catalog year - ex 2022-23
    isFound = false;
    while (!isFound)
    {
        if (tmp.find("CATALOG: ") != string::npos)
        {
            // eliminate leading and trailing characters
            if (tmp.size() >= 11)
            {
                tmp = tmp.substr(tmp.find("CATALOG: ") + 9);
                tmp = tmp.substr(0, tmp.find(" |"));
            }
            outs << tmp << endl;
            student.setCatalogYear(tmp);
            isFound = true;
        }
        else
            getline(ins, tmp);
    }

    // degree track - ex. Biological Sciences, Soc Pre-Law
    getline(ins, tmp, '|');
    tmp.pop_back();
    if (tmp[0] == ' ')
        tmp = tmp.erase(0, 1);
    outs << tmp << endl;
    student.setDegreeTrack(tmp);

    // bachelors degree ("degree") - ex. Bachelor of Science
    // NOTE: only listed on the DARS for MAJORS, hence if statement
    if (plan == "Major")
    {
        isFound = false;
        while (!isFound)
        {
            if (tmp.find("DEGREE: ") != string::npos)
            {
                // eliminate leading and trailing characters
                if (tmp.size() >= 10)
                {
                    tmp = tmp.substr(tmp.find("DEGREE: ") + 8);
                    tmp = tmp.substr(0, tmp.find(" |"));
                }
                outs << tmp << endl;
                student.getMajor(0).setDegreeName(tmp);
                isFound = true;
            }

            else
                getline(ins, tmp);
        }
    }

    /// SECTION: OTHER DECLARED PROGRAM(S)
    // must check if there are other programs, if not, we will continue to the next section
    isFound = false;
    while (!isFound)
    {
        if (tmp.find("OTHER DECLARED PROGRAM(s)") != string::npos)
        {
            getline(ins, tmp);
            getline(ins, tmp);
            
            if(tmp.find("MAJOR"))
            {

            }
            if(tmp.find("MINOR")){

            }
            if(tmp.find("CERT."))
            {

            }
            if(tmp.find("HONOR"))
            {

            }
            
            // eliminate leading and trailing characters
            if (tmp.size() >= 5)
                tmp = tmp.erase(0, 5);
            
            outs << tmp << endl;
            // student.getMajor(0).setDegreeName(tmp);
            isFound = true;
        }
        else if (tmp.find("Transcripted hours") != string::npos)
        {
            isFound = true;
        }
        else
            getline(ins, tmp);
    }
}

string Dars::pascal(string &str)
{
    bool newWord = false;
    int wordLength = 1;
    str[0] = toupper(str[0]);
    for (size_t i = 1; i < str.length(); i++)
    {
        if (newWord == false)
        {
            str[i] = tolower(str[i]);
            wordLength++;
        }
        else
        {
            str[i] = toupper(str[i]);
            newWord = false;
            wordLength++;
        }

        if (str[i] == ' ')
        {
            newWord = true;
            if (wordLength <= 4)
            {
                str[i - wordLength + 1] = tolower(str[i - wordLength + 1]);
            }
            wordLength = 0;
        }
    }
    return str;
}