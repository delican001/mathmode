#ifndef GAUSS_H
#define GAUSS_H
#include <matrix.h>
class Gauss
{
public:
    Gauss()=delete;
    Gauss(Matrix* matrix, std::vector<double> vec);
    ~Gauss(){
     delete _matrix;
        _matrix=nullptr;
    }
    std::vector<double> solution() {return _solution;}
private:
    Matrix* _matrix;
    std::vector<double> _vector;
    std::vector<double> _solution;
    void solve();

};
#endif // GAUSS_H
