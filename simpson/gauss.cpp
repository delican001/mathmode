#include <gauss.h>
#include <cmath>
Gauss::Gauss(Matrix* matrix, std::vector<double> vec)
{
    _matrix=matrix;
    _vector=vec;

    Gauss::solve();
}

void Gauss::solve()
{
            vector<int> pos;
            vector<double> v;
            v.resize(_matrix->columns());
            vector<vector<double>> t;
            t.resize(Gauss::_matrix->columns());
            for (int i=0;i<_matrix->columns();i++)
                t[i].resize(_matrix->columns());
            for (int i=0;i<_matrix->columns();i++)
                pos.push_back(i);
            for (int k = 0; k < _matrix->columns() - 1; k++) {
                double max = (*_matrix)[k][k];
                int i0 = k;
                int j0 = k;

                for (int i = k; i < (*_matrix).columns(); i++) {
                    for (int j = k; j < (*_matrix).columns(); j++) {
                        if ( fabs((*_matrix)[i][j]) <= fabs(max)) continue;
                        i0 = i;

                        j0 = j;

                    }
                }
                double aa;
                if (k != i0) {
                    for (int i = 0; i < (*_matrix).columns(); i++) {
                        aa = (*_matrix)[k][i];
                        (*_matrix)[k][i] = (*_matrix)[i0][i];
                        (*_matrix)[i0][i] = aa;
                    }
                    aa = _vector[k];
                    _vector[k] = _vector[i0];
                    _vector[i0] = aa;
                }
                if (k != j0) {
                    for (int i = 0; i < (*_matrix).columns(); i++) {
                        aa = (*_matrix)[i][k];
                        (*_matrix)[i][k] = (*_matrix)[i][j0];
                        (*_matrix)[i][j0] = aa;
                    }
                    if (j0 != k) {
                        int temp;
                        temp = pos[j0];
                        pos[j0] = pos[k];
                        pos[k] = temp;
                    }
                    aa = v[k];
                    v[k] = v[j0];
                    v[i0] = aa;
                }
                for (int i = k + 1; i < (*_matrix).columns(); i++) {
                    t[i][k] = (*_matrix)[i][k] / (*_matrix)[k][k];
                    _vector[i] = _vector[i] - t[i][k] * _vector[k];
                    for (int j = k + 1; j < (*_matrix).columns(); j++) {
                        (*_matrix)[i][j] = (*_matrix)[i][j] - t[i][k] * (*_matrix)[k][j];
                    }
                }
            }
            _solution[(*_matrix).columns() - 1] = _vector[(*_matrix).columns() - 1] / (*_matrix)[(*_matrix).columns() - 1][(*_matrix).columns() - 1];
            for (int k = (*_matrix).columns() - 2; k >= 0; k--) {
                double temp = 0;
                for (int j = k + 1; j < (*_matrix).columns(); j++) {
                    temp += (*_matrix)[k][j] * _solution[j];
                }
                _solution[k] = (_vector[k]- temp) / (*_matrix)[k][k];
            }
}
