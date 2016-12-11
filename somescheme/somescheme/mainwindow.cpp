#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    QPen pen1(Qt::red);
    scene->addLine(0,90,180,90,pen1);
    scene->addLine(90,0,90,180,pen1);
    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;

}

double MainWindow::_c (int n, int m)
{
    return x[n]+t[n];
}

double MainWindow::func (int n, int m)
{
    return x[n]*x[n]/t[m];
}

void MainWindow::on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint)
{

}

void MainWindow::on_pushButton_clicked()
{
    int gotten_t = ui->horizontalScrollBar->value();

    x.resize(len);
    t.resize(len);
    y.resize(len);
    for (int i=0;i<len;i++)
        y[i].resize(len);
    for (int i=0;i<len;i++)
    {
        x[i]=i;
        t[i]=i;
    }
    for (int i=0;i<len;i++)
    {
        y[0][i]=5;
        y[i][0]=1;
    }
    for(int m=1;m<len-1;m++)
                for(int n=1;n<len;n++)
            {
                    if(_c(n,m)*(t[m+1]-t[m])<=(x[n]-x[n-1]))
                y[m+1][n]=(func(n,m)-_c(n,m)/(x[n]-x[n-1])*(y[m][n]-y[m][n-1]))*(t[m+1]-t[m])+y[m][n];
                    else
                       y[m+1][n-1]=(func(n,m)-_c(n,m)/(x[n]-x[n-1]))*(t[m+1]-t[m])+y[m][n-1];
            }
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    QPen pen(Qt::black);
    QPen pen1(Qt::red);
    scene->addLine(0,90,180,90,pen1);
    scene->addLine(90,0,90,180,pen1);
    int x0,xt,y0,yt=0;
    ui->horizontalScrollBar->setMaximum(t.size()-1);
    int coef=1;
    if (gotten_t<t.size())
    {
    for (int i=0;i<t.size()-1;i++)
        scene->addLine(x[i]*coef,y[gotten_t][i]*coef,x[i+1]*coef,y[gotten_t][i+1]*coef);
    }
    ui->graphicsView->setScene(scene);





}

void MainWindow::on_horizontalScrollBar_sliderMoved(int position)
{    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
     QPen pen(Qt::black);
     QPen pen1(Qt::red);
    int gotten_t = ui->horizontalScrollBar->value();
     scene->addLine(0,90,180,90,pen1);
     scene->addLine(90,0,90,180,pen1);
     ui->horizontalScrollBar->setMaximum(t.size()-1);
    int coef=1;
    if (gotten_t<t.size())
    {
    for (int i=0;i<t.size()-1;i++)
        scene->addLine(x[i]*coef,y[gotten_t][i]*coef,x[i+1]*coef,y[gotten_t][i+1]*coef);
    }
    ui->graphicsView->setScene(scene);
}
