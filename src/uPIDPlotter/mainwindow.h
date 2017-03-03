#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "common.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow( QWidget *parent = 0);
    ~MainWindow();
    void forceReplot();
    void updateRange();

public slots:
    void realtimeDataSlot(std::string key, std::pair<double, double> PlotData);
    void addPlots(std::vector<std::string> names);
    void replot();

protected:
    QMap<std::string, int> plotMap;
    std::pair<double,double> yRange;
    void makePlot(QCustomPlot *plot);
    std::vector<std::string> plotNames;


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
