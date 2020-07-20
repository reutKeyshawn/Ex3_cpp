#ifndef SOLVER_A_MASTER_SOLVER_HPP
#define SOLVER_A_MASTER_SOLVER_HPP
#include <iostream>
#include <unordered_map>
#include <complex>
using namespace std;

namespace solver
{

    class RealVariable
    {
    public:
        unordered_map<int, double> umap;
        RealVariable()

        {
            umap = {{0, 0},
                    {1, 1},
                    {2, 0}};
        }
    };

    //right
    RealVariable operator-(double num, const RealVariable &x);
    RealVariable operator+(double num, const RealVariable &x);
    RealVariable operator*(double num, const RealVariable &x);
    //left
    RealVariable operator+(const RealVariable &x, double num);
    RealVariable operator-(const RealVariable &x, double num);
    RealVariable operator*(const RealVariable &x, double num);
    RealVariable operator/(const RealVariable &x, double num);
    RealVariable operator^(const RealVariable &x, const int num);

    //both
    RealVariable operator+(const RealVariable &x1, const RealVariable &x);
    RealVariable operator-(const RealVariable &x1, const RealVariable &x);
    RealVariable operator*(const RealVariable &x, const RealVariable &y);
    RealVariable operator/(const RealVariable &x1, const RealVariable &x);
    //relevant for solve function
    RealVariable operator==(double num, const RealVariable &x);
    RealVariable operator==(const RealVariable &x, double num);
    RealVariable operator==(const RealVariable &x1, const RealVariable &x);

    class ComplexVariable
    {
    public:
        unordered_map<int, std::complex<double>> umap;
        ComplexVariable()

        {
            umap = {{0, complex<double>(0, 0)},
                    {1, complex<double>(1, 0)},
                    {2, complex<double>(0, 0)}};
        }
    };

    //right
    ComplexVariable operator-(const complex<double> num, const ComplexVariable &x);
    ComplexVariable operator+(const complex<double> num, const ComplexVariable &x);
    ComplexVariable operator*(const complex<double> num, const ComplexVariable &x);
    //left
    ComplexVariable operator+(const ComplexVariable &x, const complex<double> num);
    ComplexVariable operator-(const ComplexVariable &x, const complex<double> num);
    ComplexVariable operator*(const ComplexVariable &x, const complex<double> num);
    ComplexVariable operator/(const ComplexVariable &x, const complex<double> num);
    ComplexVariable operator^(const ComplexVariable &x, const int num);

    //both
    ComplexVariable operator+(const ComplexVariable &x1, const ComplexVariable &x);
    ComplexVariable operator-(const ComplexVariable &x1, const ComplexVariable &x);
    ComplexVariable operator*(const ComplexVariable &x, const ComplexVariable &y);
    ComplexVariable operator/(const ComplexVariable &x1, const ComplexVariable &x);
    //relevant for solve function
    ComplexVariable operator==(const complex<double> num, const ComplexVariable &x);
    ComplexVariable operator==(const ComplexVariable &x, const complex<double> num);
    ComplexVariable operator==(const ComplexVariable &x1, const ComplexVariable &x);
    std::complex<double> solve(const ComplexVariable &e);

    complex<double> solve(const ComplexVariable &e);
    double solve(const RealVariable &e);

}; // namespace solver
#endif
