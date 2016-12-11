#include <simpson.h>

using namespace std;
double Simpson::func(double x)
{
    if (x=0)
        return 0;
                else
    return x/(x*x*x*x+4);
}

Simpson::Simpson(double left,double right, int steps)
{
    _left=left;
    _right=right;
    _steps=steps;
}
double Simpson::solve()
{
    double h =((_right-_left))/(2*_steps);
    double solution=0;
    solution+=func(_left);
    for (int i=1;i<_steps;i++)
        solution+=4*func(_left+h*(2*i-1));
    for (int i=1;i<_steps-1;i++)
        solution+=2*func(_left+h*(2*i));
    solution+=func(_right);
    return solution;
}
double Simpson::solve(double left,double right, int steps)
{
    double h =((right-left))/(2*steps);
    double solution=0;
    solution+=func(left);
    for (int i=1;i<steps;i++)
        solution+=4*func(left+h*(2*i-1));
    for (int i=1;i<steps-1;i++)
        solution+=2*func(left+h*(2*i));
    solution+=func(right);
    return solution;

}
/*
vector<double> Simpson::getVector()
{
    vector<vector<double>> somemat;
         somemat.resize(_steps+1);
         for(int i=0;i<=_steps;i++)
             somemat[i].resize(_steps+1);
         for(int i=0;i<=_steps;i++)
             for(int j=0;j<=_steps;j++)
                 somemat[i][j]=solve(i,j,0);
         vector<double>somevec;
              somevec.resize(_steps+1);
              for(int i=0;i<=_steps;i++)
                  somevec[i]=solve(i,0,1);

         Matrix matrix(somemat);
         Gauss gauss (new Matrix(somemat),somevec);
         vector <double> gausses_solution = gauss.solution();
         return gausses_solution;
}

std::vector<std::vector<double>> Simpson::Approx()
{

    double h =((_right-_left))/(2*_steps);
    vector<vector<double>> semi_sol;
        vector < vector<double> > par_mat(3);
        vector<double> par_vec(3, 0);
        for (int i = 0; i < 3; i++) {
            par_mat[i].resize(3, 0);
        }
    for (int i = 1; i <= _steps; ++i) {
            double x2i2 = _left + (2 * i - 2)*h;
            double x2i1 = _left + (2 * i - 1)*h;
            double x2i = _left + 2 * i*h;
            par_mat[0][0] = x2i2*x2i2;
            par_mat[0][1] = x2i2;
            par_mat[0][2] = 1;
            par_vec[0] = func(x2i2);
            par_mat[1][0] = x2i1*x2i1;
            par_mat[1][1] = x2i1;
            par_mat[1][2] = 1;
            par_vec[1] = func(x2i1);
            par_mat[2][0] = x2i*x2i;
            par_mat[2][1] = x2i;
            par_mat[2][2] = 1;
            par_vec[2] = func(x2i);
            Gauss* gauss = new Gauss(new Matrix(par_mat), par_vec);
            semi_sol.push_back((*gauss)());
            semi_sol.back().push_back(x2i2);
            semi_sol.back().push_back(x2i);
            delete gauss;
            gauss = nullptr;
        }
        return semi_sol;


}
*/
