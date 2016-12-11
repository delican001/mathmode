#ifndef MATRIX_H
#define MATRIX_H
using namespace std;
#include <vector>
class Matrix
{
public:
    Matrix();
    Matrix(int lines, int columns);
        Matrix(vector<vector<double> > matrix);
        Matrix(const Matrix& matrix);
        ~Matrix();

        vector<double> operator[] (int index);
        int columns() const;
        int lines() const;
        vector<double> back();
    private:
        vector<vector<double> > _matrix;
        int _columns;
        int _lines;
};
#endif // MATRIX_H
