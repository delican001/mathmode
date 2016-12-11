#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <gauss.h>
#include <simpson.h>
#include <cmath>
#include <QVector>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


double fi(double x)
{
    if (x!=0)
    return x/(4+x*x*x*x);
    else return 0;
}
double solve(double left,double right, int steps)
{
    double h =((right-left))/(2*steps);
    double solution=0;
    vector<double> temp;
    temp.resize(steps*2+1);
    solution+=fi(left);
    for (int i=1;i<steps*2+1;i++)
    {
        if (i%2!=0)
        {temp[i]=fi(left+h*(i));
        solution+=4*fi(left+h*(i));
        }
        else
        {temp[i]=fi(left+h*(i));
        solution+=2*fi(left+h*(i));
        }
    }
    solution+=fi(right);
    solution=solution*h/3;
    return solution;
}

MainWindow::~MainWindow()
{
    delete ui;

}
double func(double x)
{
    return atan(x*x)/4;
}

void MainWindow::on_pushButton_clicked()
{


    double qwe = solve(0,5,5);

    ui->widget->addGraph();
    ui->widget->addGraph();
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    double left=0;
    double right=5;
    int steps =1500;
    double h=(right-left)/(2*steps);
    QVector<double>x;
    QVector<double>y;
    QVector<double> x1;
    QVector<double> y1;
    x.resize(steps);
    y.resize(steps);
    x1.resize(steps);
    y1.resize(steps);
    for (int i=0;i<steps;i++)
    {
        x[i]=left+h*i;
        if (i==0)
        {
            y[i]=solve(left+h*i,left+h*(i+1),10);
        }
        else
        {y[i]=y[i-1]+solve(left+h*i,left+h*(i+1),10);}
        x1[i]=left+h*i;
        y1[i]=func(x1[i]);
    }
    double min=y1[0],max=y1[0];
    for (int i=0;i<steps;i++)
    {
        if (y1[i]>max)
            max=y1[i];
        if (y1[i]<min)
            min=y1[i];
    }
    ui->widget->xAxis->setRange(left,right);
    ui->widget->yAxis->setRange(min,max);
    ui->widget->graph(0)->setData(x1,y1);
    ui->widget->graph(1)->setData(x,y);
    ui->widget->graph(1)->setPen(QColor(255,0,0));
    ui->widget->replot();




}
