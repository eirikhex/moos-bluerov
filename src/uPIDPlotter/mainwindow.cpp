#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //plotMap["desired"] = 0;
    //plotMap["current"] = 2;



}


void MainWindow::forceReplot()
{
    ui->plot->replot();
}

void MainWindow::makePlot(QCustomPlot *plot)
{

    plot->legend->setVisible(true);
    plot->clearGraphs();

    Qt::GlobalColor colors [10] ={Qt::blue, Qt::red, Qt::cyan,Qt::black, Qt::darkGray,Qt::green, Qt::magenta, Qt::yellow, Qt::darkRed, Qt::darkYellow};


    for (int num = 0; num < plotNames.size(); ++num) {

        QString name = QString::fromStdString( plotNames[num]).remove(" ");


        int gNum = num*2;

        // Make the line
        plot->addGraph(); // Add line
        plot->graph(gNum)->setPen(QPen(colors[num]));
        plot->graph(gNum)->setName(name);

        // Make the dot
        plot->addGraph(); // Add dot
        plot->graph(gNum+1)->setPen(QPen(colors[num]));
        plot->graph(gNum+1)->setLineStyle(QCPGraph::lsNone);
        plot->graph(gNum+1)->setScatterStyle(QCPScatterStyle::ssDisc);
        plot->graph(gNum+1)->removeFromLegend();

        // Update PlotMap
        plotMap[plotNames[num]] = gNum;
    }


    plot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    plot->xAxis->setDateTimeFormat("hh:mm:ss");
    plot->xAxis->setAutoTickStep(false);
    plot->xAxis->setTickStep(2);
    plot->axisRect()->setupFullAxesBox();

    connect(plot->xAxis, SIGNAL(rangeChanged(QCPRange)), plot->xAxis2, SLOT(setRange(QCPRange)));
    connect(plot->yAxis, SIGNAL(rangeChanged(QCPRange)), plot->yAxis2, SLOT(setRange(QCPRange)));

    plot->replot();
    statusBar()->clearMessage();
    /*

    plot->addGraph(); // blue line
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->graph(0)->setName("blue line");
    plot->graph(0)->setBrush(QBrush(QColor(240, 255, 200)));
    plot->graph(0)->setAntialiasedFill(false);

    plot->addGraph(); // blue dot
    plot->graph(1)->setPen(QPen(Qt::blue));
    plot->graph(1)->setLineStyle(QCPGraph::lsNone);
    plot->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);

    plot->addGraph(); // red line
    plot->graph(2)->setPen(QPen(Qt::red));
    plot->graph(0)->setChannelFillGraph(plot->graph(1));

    plot->addGraph(); // red dot
    plot->graph(3)->setPen(QPen(Qt::red));
    plot->graph(3)->setLineStyle(QCPGraph::lsNone);
    plot->graph(3)->setScatterStyle(QCPScatterStyle::ssDisc);

    plot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    plot->xAxis->setDateTimeFormat("hh:mm:ss");
    plot->xAxis->setAutoTickStep(false);
    plot->xAxis->setTickStep(2);
    plot->axisRect()->setupFullAxesBox();

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(plot->xAxis, SIGNAL(rangeChanged(QCPRange)), plot->xAxis2, SLOT(setRange(QCPRange)));
    connect(plot->yAxis, SIGNAL(rangeChanged(QCPRange)), plot->yAxis2, SLOT(setRange(QCPRange)));
    */

}

void MainWindow::realtimeDataSlot(std::string key,std::pair<double,double> PlotData)
{

    int plotNumber = plotMap[key];
    // Adding data points to the line
    ui->plot->graph(plotNumber)->addData(PlotData.first,PlotData.second );

    // Moving the leading dot on the line
    ui->plot->graph(plotNumber+1)->clearData();
    ui->plot->graph(plotNumber+1)->addData(PlotData.first,PlotData.second);

    // remove data of lines that's outside visible range:
    ui->plot->graph(plotNumber)->removeDataBefore(PlotData.first-20);

    //ui->plot->graph(plotNumber)->rescaleValueAxis();
    updateRange();

    // make key axis range scroll with the data (at a constant range size of 8):
    ui->plot->xAxis->setRange(PlotData.first+0.25, 20, Qt::AlignRight);


}

void MainWindow::addPlots(std::vector<std::string> names)
{
    plotNames = names;
    makePlot(ui->plot);
}

void MainWindow::updateRange()
{
    //TODO: for all plots
    bool foundRange = false;
    QCPRange range = ui->plot->graph(0)->getValueRange(foundRange);
    int nplots = plotMap.size();
    if(nplots >1){
        for(int i=2;i<nplots*2; i+=2){
            range.expand(ui->plot->graph(i)->getValueRange(foundRange));
        }
    }

    range.expand(range + 0.25);
    range.expand(range - 0.25);
    ui->plot->yAxis->setRange(range);

}

void MainWindow::replot()
{
    ui->plot->replot();
}


MainWindow::~MainWindow()
{
    delete ui;
}
