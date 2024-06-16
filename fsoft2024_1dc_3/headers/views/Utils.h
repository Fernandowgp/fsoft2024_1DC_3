//
// Created by Luís on 26/05/2024.
//

#ifndef FSOFT2024_1DC_3_UTILS_H
#define FSOFT2024_1DC_3_UTILS_H

#include <string>
using namespace std;
class Utils {
public:
    static int getNumber(const string&  label);
    static unsigned int getUInt(const string& label);
    static float getFloat(const string& label);
    static string getString(const string&  label);
    static bool stringIsNumber(string& s);
    static bool getBool(const string &label);
};


#endif //FSOFT2024_1DC_3_UTILS_H
