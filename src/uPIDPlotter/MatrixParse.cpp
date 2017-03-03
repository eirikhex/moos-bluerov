/*****************************************************************/
/*    NAME: Eirik Hexeberg Henriksen                             */
/*    ORGN: NTNU                                                 */
/*    FILE: MatrixParse.cpp                                        */
/*    DATE: Oct 13, 2015                                         */
/*                                                               */
/*    DESCRIPTION:                                               */
/*                  Small library for parsing Eigen-matrices     */
/*                  to and from strings used to send data in     */
/*                  MOOS. Strings have following format:         */
/*                  [ x, y, z; r, q, t; u, v, w]                 */
/*                  (can be of arbitrary size e.g 3x4 4x4 6x6    */
/*                                                               */
/*****************************************************************/


#include "MatrixParse.h"
#include <iostream>
#include <algorithm>
#include <locale>


std::string matrixToMOOSString(Eigen::MatrixXd mat)
{
    // Using Eigen IOFormat to produce string

    Eigen::IOFormat format(Eigen::StreamPrecision, 0, ", ", "; ", "", "", "[", "]");

    std::stringstream ss;
    ss << mat.format(format);
    return(ss.str());
}

std::vector<double> MOOSStringToDVector(std::string moos_string)
{
    std::vector<double> doubleVector;
    parseMatrix(moos_string,doubleVector);

    return(doubleVector);
}


Eigen::MatrixXd MOOSStringToMatrix(std::string moos_string)
{
    std::vector<double> entries;

    std::pair<int,int> size = parseMatrix(moos_string, entries);

    Eigen::MatrixXd mat = Eigen::MatrixXd::Map(&entries[0], size.second,size.first);
    mat.transposeInPlace();
    return(mat);
}


/* extracts the first matrix it finds in the string,
 * and pushes all values in it to a vector. The return value
 * is a pair of detected number of rows and colums in the matrix
 *
 * TODO: error handling, and fail-safes
 */
std::pair<int, int> parseMatrix(std::string moos_string, std::vector<double>& num)
{
    int num_rows =1;
    int num_cols = 1;


    std::string str = moos_string;
    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());



    int startMatrix = str.find('[') + 1;
    int endMatrix = str.find(']') - startMatrix;
    str = str.substr(startMatrix,endMatrix);

    size_t pos, p = 0;
    std::string row, entry;
    while ((pos = str.find(';')) != std::string::npos)
    {
        row = str.substr(0, pos);
        num_rows ++;

        while ((p = row.find(',')) != std::string::npos)
        {
            entry = row.substr(0,p);
            num.push_back(str2dbl(entry));
            row.erase(0, p + 1);
        }
        // get last entry in row
        num.push_back(str2dbl(row));
        str.erase(0, pos + 1);
    }
    // get last row in matrix
    while ((p = str.find(',')) != std::string::npos)
    {
        entry = str.substr(0,p);
        num.push_back(str2dbl(entry));
        str.erase(0, p + 1);
    }
    // get last entry in row
    num.push_back(str2dbl(str));


    num_cols = num.size()/num_rows;

    std::pair <int,int> return_pair = std::make_pair(num_rows,num_cols);

    return return_pair;

}

double str2dbl(std::string str)
{
    double dbl = 0.0;
    std::istringstream istr(str);

    //make sure stream is locale-independent
    istr.imbue(std::locale("C"));
    istr >> dbl;
    return(dbl);
}
