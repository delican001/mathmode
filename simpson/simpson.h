#ifndef SIMPSON_H
#define SIMPSON_H
#include <vector>
#include <matrix.h>
#include <gauss.h>

class Simpson
{
public:

    Simpson() {}
    Simpson(double left, double right, int steps);
    ~Simpson();
    std::vector<std::vector<double>> Approx();
    double solve();
    double solve(double left,double right, int steps);
    double func(double x);
    double _left;
    double _right;
    int _steps;
    std::vector<double> getVector();
private:
};
#endif // SIMPSON_H
