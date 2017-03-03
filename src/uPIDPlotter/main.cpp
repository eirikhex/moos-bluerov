#include <QApplication>
#include <QObject>
#include "upidplotter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType < std::pair<double,double> >("std::pair<double,double>");
    qRegisterMetaType < std::string >("std::string");
    qRegisterMetaType <std::vector<std::string> >("std::vector<std::string>");


    //here we do some command line parsing ...
    MOOS::CommandLineParser P(argc, argv);

    //mission file could be first free parameter
    std::string mission_file = P.GetFreeParameter(0, "Plotter.moos");

    //app name can be the second free parameter
    std::string app_name = P.GetFreeParameter(1, "Plotter");

    PlotterThread thread(app_name, mission_file, argc, argv);

    QObject::connect(&a, SIGNAL(aboutToQuit()), &thread, SLOT(stop()));
    thread.start();

    return a.exec();
}
