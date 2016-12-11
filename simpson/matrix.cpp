#include <matrix.h>


Matrix::Matrix()
{
}

Matrix::Matrix(int lines, int columns):
    _lines{lines},
    _columns{columns}
{
    _matrix.resize(lines);
    for (int i = 0; i < lines; ++i) {
        _matrix[i].resize(columns, 0);
    }
}

Matrix::Matrix(vector<vector<double>> matrix) :
    _matrix{ matrix },
    _lines{(int)matrix.size()},
    _columns{(int)matrix.size()}
{}

Matrix::Matrix(const Matrix& matrix) {
    _matrix = matrix._matrix;
    _columns = matrix._columns;
    _lines = matrix._lines;
}


vector<double> Matrix::operator[](int index)
{
    if (index < 0) {
        index += _columns;
    }

    if (index < 0) {
        throw exception();
    }

    if (index >= _columns) {
        throw exception();
    }

    return (_matrix[index]);
}

int Matrix::columns() const
{
    return _columns;
}

int Matrix::lines() const
{
    return _lines;
}

vector <double> Matrix::back()
{
    return _matrix.back();
}
