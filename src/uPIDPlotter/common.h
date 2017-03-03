#ifndef COMMON_H
#define COMMON_H
#include <utility>
#include <string>

struct plotconf
{
    std::string MOOSkey, x, y;

    // empty constructor
    plotconf(){}

    // constructor
    plotconf(std::string key, std::string x_val, std::string y_val)
    {
        MOOSkey = key;
        x = x_val;
        y = y_val;
    }
};



#endif // COMMON_H

