/*****************************************************************/
/*    NAME: Eirik Hexeberg Henriksen                             */
/*    ORGN: NTNU                                                 */
/*    FILE: MatrixParse.h                                        */
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

#ifndef MATRIXPARSE
#define MATRIXPARSE

#include <Eigen/Core>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
#include <cstdlib>

std::string matrixToMOOSString(Eigen::MatrixXd mat);
Eigen::MatrixXd MOOSStringToMatrix(std::string moos_string);
std::vector<double> MOOSStringToDVector(std::string moos_string);
std::pair<int, int> parseMatrix(std::string str, std::vector<double>& num);
double str2dbl(std::string str);





#endif // MATRIXPARSE

