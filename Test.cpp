#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "solver.hpp"
#include <complex>
#include <math.h>
#include <vector>
#include <iostream>
#include <string>
#include <stdbool.h>

using namespace std;
using namespace solver;

// TEST_CASE("basic checks 1:")
// {
//     RealVariable x;
//     CHECK(solve((x ^ 2) == 16) == 4);
//     CHECK(solve((x ^ 2) == 9) == 3);
//     CHECK(solve(x + 5 == 12) == 7);
//     CHECK(solve(-2 * x + 3 == 5) == -1);
//     CHECK((solve((x ^ 2) + 2 * x + 4.0 == 20 + 6.0 * x / 2 - x) == 4 || solve((x ^ 2) + 2 * x + 4.0 == 20 + 6.0 * x / 2 - x) == -4));
//     CHECK(solve(2 * x - 4.0 == 10.0) == 7);
//     CHECK((solve((x ^ 2) + 2 * x - 24) == -6 || solve((x ^ 2) + 2 * x - 24) == 4));
//     CHECK((solve((x ^ 2) - 5 * x - 24 == 0) == 8 || solve((x ^ 2) - 5 * x - 24 == 0) == -3));
//     CHECK((solve((x ^ 2) - 2 * x - 9 * x + 16 + 2 == 0) == 9 || solve((x ^ 2) - 2 * x - 9 * x + 16 + 2 == 0) == 2));
//     CHECK((solve((x ^ 2) + 12 * x + 32 == 0) == -4 || solve((x ^ 2) + 12 * x + 32) == -8));
// }

TEST_CASE("complex checks: 2:")
{
    ComplexVariable y;
    CHECK((solve((y ^ 2) == 16) == std::complex<double>(4, 0) || solve((y ^ 2) == 16) == std::complex<double>(-4, 0)));
    CHECK((solve((y ^ 2) == -16) == std::complex<double>(0, -4.0) || solve((y ^ 2) == -16) == std::complex<double>(0, 4.0)));
    CHECK((solve((y ^ 2) + 2 * y + 4 == 20 + 6 * y / 2 - y) == std::complex<double>(4, 0) || solve((y ^ 2) + 2 * y + 4 == 20 + 6 * y / 2 - y) == std::complex<double>(-4, 0)));
    CHECK(solve(-4.0 == 6.0i + 2 * y) == std::complex<double>(-2, -3));
    CHECK(solve(y + 2i == 8) == std::complex<double>(8, -2));
    CHECK(solve(2.0 == 6i + 2 * y) == std::complex<double>(1, -3));
}

TEST_CASE("3")
{

    ComplexVariable z;
    CHECK((solve((z ^ 2) == 9) == std::complex<double>(3, 0) || solve((z ^ 2) == 9) == std::complex<double>(-3, 0)));
    CHECK((solve((z ^ 2) == -9) == std::complex<double>(0, 3) || solve((z ^ 2) == -9) == std::complex<double>(0, -3)));
    CHECK((solve((z ^ 2) == 25) == std::complex<double>(5, 0) || solve((z ^ 2) == 25) == std::complex<double>(-5, 0)));
    CHECK((solve((z ^ 2) == -25) == std::complex<double>(0, 5) || solve((z ^ 2) == -25) == std::complex<double>(0, -5)));
    CHECK((solve((z ^ 2) == 36) == std::complex<double>(6, 0) || solve((z ^ 2) == 36) == std::complex<double>(-6, 0)));
    CHECK((solve((z ^ 2) == -36) == std::complex<double>(0, 6) || solve((z ^ 2) == -36) == std::complex<double>(0, -6)));
}

TEST_CASE("4:")
{

    ComplexVariable y;
    CHECK(solve((y ^ 2) == 4) == std::complex<double>(2, 0));
    // CHECK(solve((y ^ 2) == 4) == std::complex<double>(-2, 0));
    CHECK(solve((y ^ 2) == -4) == std::complex<double>(0, 2));
    // CHECK(solve((y ^ 2) == -4) == std::complex<double>(0, -2));
    CHECK(solve((y ^ 2) == 1) == std::complex<double>(1, 0));
    // CHECK(solve((y ^ 2) == 1) == std::complex<double>(-1, 0));
    CHECK(solve((y ^ 2) == -1) == std::complex<double>(0, 1));
    // CHECK(solve((y ^ 2) == -1) == std::complex<double>(0, -1));
    CHECK(solve((y ^ 2) == 49) == std::complex<double>(7, 0));
    // CHECK(solve((y ^ 2) == 49) == std::complex<double>(-7, 0));
    CHECK(solve((y ^ 2) == -49) == std::complex<double>(0, 7));
    // CHECK(solve((y ^ 2) == -49) == std::complex<double>(0, -7));
}

TEST_CASE("6:")
{
    ComplexVariable y;

    CHECK(solve(-10.0 == 6.0i + 2 * y) == std::complex<double>(-5, -3));
    CHECK(solve(-10.0 - 6.0i == 2 * y) == std::complex<double>(-5, -3));
    CHECK(solve(-10.0 - 6.0i - 2 * y == 0) == std::complex<double>(-5, -3));
    CHECK(solve(6 == 6i + 2 * y) == std::complex<double>(3, -3));
}
// TEST_CASE("5:")
// {
//     RealVariable x;
//     // CHECK((solve((x ^ 2) - 5 * x == 45) == 9.65891 || solve((x ^ 2) - 5 * x == 45) == -4.65891));
//     // CHECK((solve((x ^ 2) == 5 * x + 45) == 9.65891 || solve((x ^ 2) == 5 * x + 45) == -4.65891));
//     // CHECK((solve((x ^ 2) - 5 * x - 45 == 0) == 9.65891 || solve((x ^ 2) - 5 * x - 45 == 0) == -4.65891));
//     CHECK((solve((x ^ 2) - x - 2 == 0) == 2.0 || solve((x ^ 2) - x - 2 == 0) == -1.0));
//     CHECK((solve((x ^ 2) - x == 2) == 2.0 || solve((x ^ 2) - x == 2) == -1.0));
//     CHECK((solve((x ^ 2) == x + 2) == -1.0 || solve((x ^ 2) == x + 2) == 2.0));
//     // CHECK(solve((x ^ 2) + (x ^ 2) + 2 * x + 8 * x + 6 + 1) == -0.8416876048);
// }
//  CHECK(solve(-6.0 - 6i == 2 * y) == std::complex<double>(-3, -3));
//     CHECK(solve(-6.0 + 2i == 6i + 2.0 * y) == std::complex<double>(-3, -2));
//     CHECK(solve(-2 * y - 6.0 + 2i == 6i) == std::complex<double>(-3, -2));
    // CHECK(solve(-6.0 + 2i - 6i == 2 * y) == std::complex<double>(-3, -2));
//     CHECK(solve(3 + y == 6i) == std::complex<double>(-3, 6));
//     CHECK(solve(3 == 6i - y) == std::complex<double>(-3, 6));
// }

TEST_CASE("7:")
{

    ComplexVariable y;

    CHECK(solve((y ^ 2) - 5.0 == -30.0) == std::complex<double>(0, 5));
    // CHECK(solve((y ^ 2) - 5.0 == -30.0) == std::complex<double>(0, -5));
    // CHECK(solve((y ^ 2) - 10.0 == -35.0) == std::complex<double>(0, 5));
    // CHECK(solve((y ^ 2) - 9.0 == -58.0) == std::complex<double>(0, -7));
    CHECK(solve((y ^ 2) - 9.0 == -58.0) == std::complex<double>(0, 7));
    // CHECK(solve((y ^ 2) - 3.0 - 6.0 == -58.0) == std::complex<double>(0, -7));
    CHECK(solve((y ^ 2) - 3.0 - 6.0 == -58.0) == std::complex<double>(0, 7));
    CHECK(solve(y - 9.0i == -58) == std::complex<double>(-58, 9));
    CHECK(solve(y - 6.0i - 3.0i == -58) == std::complex<double>(-58, 9));
    CHECK(solve(y - 8.0i - 1.0i == -58) == std::complex<double>(-58, 9));
}

// TEST_CASE("8:")
// {

//     RealVariable x;

//     CHECK(solve(x * x == 0) == 0);
//     CHECK(solve(x * 2 == 2) == 1);
//     CHECK(solve(x * 4 == 2) == 0.5);
//     CHECK(solve(x * 2 == 4) == 2);
//     CHECK(solve(2 * x + 3 == 9) == 3);
//     CHECK(solve(x * x == 16) == 4.0);
//     // CHECK(solve(x * x == 16) == -4.0);
//     CHECK(solve(8 * x == 24) == 3);
//     CHECK(solve(6 * x == 36) == 6);
//     CHECK(solve(12 * x == 144) == 12);
//     CHECK(solve(10 * x == 100) == 10);
//     CHECK(solve(3 * x == 9) == 3);
// }

TEST_CASE("9:")
{

    ComplexVariable y1;
    RealVariable x1;

    CHECK(solve(2 * y1 - 6i - 3i == -20) == std::complex<double>(-10, 4.5));
    CHECK(solve(2 * y1 - 9i == -20) == std::complex<double>(-10, 4.5));
    // CHECK(solve(2 * y1 - 6i == 3i - 20) == std::complex<double>(-10, 4.5));
    CHECK(solve(-6i - 3i == -2 * y1 - 20) == std::complex<double>(-10, 4.5));
    CHECK(solve(2 * y1 - 6i - 3i == -20) == std::complex<double>(-10, 4.5));
    CHECK(solve(2 * y1 - 6i - 3i + 20 == 0) == std::complex<double>(-10, 4.5));

    CHECK(solve(2 * y1 - 6i - 3i == -20) == std::complex<double>(-10, 4.5));
    CHECK(solve(2 * y1 - 9i == -20) == std::complex<double>(-10, 4.5));
    // CHECK(solve(2 * y1 - 6i == 3i - 20) == std::complex<double>(-10, 4.5));
    CHECK(solve(-6i - 3i == -2 * y1 - 20) == std::complex<double>(-10, 4.5));
    CHECK(solve(2 * y1 - 6i - 3i == -20) == std::complex<double>(-10, 4.5));
    CHECK(solve(2 * y1 - 6i - 3i + 20 == 0) == std::complex<double>(-10, 4.5));
    CHECK(solve((y1 ^ 2) - 5.0 == -30.0) == std::complex<double>(0, 5));
    CHECK(solve(-2 * y1 - 6.0 + 2i == 6i) == std::complex<double>(-3, -2));
    CHECK(solve((y1 ^ 2) == 16) == std::complex<double>(4, 0));
    // CHECK(solve((y1 ^ 2) == 16) == std::complex<double>(-4, 0));
    CHECK(solve((y1 ^ 2) == 16) == std::complex<double>(4, 0));
    // CHECK(solve((y1 ^ 2) == -16) == std::complex<double>(-4, 0));
    CHECK(solve(-6.0 - 6i == 2 * y1) == std::complex<double>(-3, -3));
    CHECK(solve(-6.0 + 2i == 6i + 2 * y1) == std::complex<double>(-3, -2));
    CHECK(solve(-2 * y1 - 6.0 + 2i == 6i) == std::complex<double>(-3, -2));
    CHECK(solve(-6.0 + 2i - 6i == 2 * y1) == std::complex<double>(-3, -2));
    CHECK(solve(3 + y1 == 6i) == std::complex<double>(-3, 6));
    CHECK(solve(3 == 6i - y1) == std::complex<double>(-3, 6));
}

// TEST_CASE("Test complicated examples:")
// {

//     RealVariable x;
//     CHECK(solve(((x ^ 2) ^ 1) == 0) == 0);
//     CHECK(solve(((x + 2) ^ 2) == 0));
// }

// TEST_CASE("check throws:")
// {
//     RealVariable y;
//     CHECK_THROWS(solve(y - y == 0) == 0);

//     CHECK_THROWS(solve(((y ^ 2) ^ 2) == 0));
//     CHECK_THROWS(solve((y ^ 4) == 0));
//     CHECK_THROWS(solve(3 * y / 0 == 0));

//     CHECK_THROWS(solve(2 * y - 2 * y + 8 == 0));

//     CHECK_THROWS(solve(4.0 * (y ^ 6) + 8 == 0));

//     CHECK_THROWS(solve(4.0 * y * 9.0 + (y ^ 3) + 8 == 9));

//     CHECK_THROWS(solve(y / 0 + 8.0 == 0));

//     CHECK_THROWS(solve((y ^ 2) / 0 == 2.0 * (y ^ 4)));

//     CHECK_THROWS(solve(4 * y / 0 + 12 == 0));

//     CHECK_THROWS(solve(4 * y - 4 * y + 12 == 0));

//     CHECK_THROWS(solve(4 * (y ^ 6) + 12 == 0));

//     CHECK_THROWS(solve(4 * y * 9 + (y ^ 3) + 12 == 9));

//     CHECK_THROWS(solve(4 * y + y / 0 + 12.0 == 0));

//     CHECK_THROWS(solve(4 * y + 12 == y * 4));

//     CHECK_THROWS(solve(4 * (y ^ 2) + 12 == 8 * (y ^ 2) / 2));

//     CHECK_THROWS(solve(4 * y + 0.0 == 4 * y + 9));

//     CHECK_THROWS(solve(4 * (y ^ 4) * 7 + 12 == 28 * (y ^ 2)));

//     CHECK_THROWS(solve(4 * y - 3 * y / 0 == 0)); //84
// }

// TEST_CASE("more test:")
// {

//     RealVariable x;

//     CHECK(solve(x + 5 == 7) == 2);

//     CHECK(solve(5 + x == 10) == 5);

//     CHECK(solve(2 * x + 3 * x == 20) == 4);

//     CHECK(solve(2 * x - 3 * x == -1) == 1);

//     CHECK(solve(2 * x - 4 * x == 4) == -2);

//     CHECK(solve(5 * x == 10) == 2);

//     CHECK(solve(2 * x - 2 == 0) == 1);

//     CHECK(solve(2 * x - 1 * x == 15) == 15);

//     CHECK(solve(2 * x + 4 * x + 4 * x == 10) == 1);

//     CHECK(solve(5 * x == -5) == -1);

//     CHECK(solve(x - 4 == 10) == 14);

//     CHECK(solve(5 * x - 10 == 10) == 4);
// }

// TEST_CASE("RealVariable - polynomial equations")
// {

//     RealVariable x;

//     CHECK(solve((x ^ 2) == 16) == 4); //second solution

//     CHECK_THROWS(solve((x ^ 3) == 8) == 2);

//     CHECK_THROWS(solve((x ^ 4) == 16) == 2); //second solution

//     CHECK_THROWS(solve((x ^ 3) == 27) == 3);

//     CHECK(solve((x ^ 2) == 64) == 8); //second solution

//     CHECK(solve((((((x ^ 2) + (x ^ 2)) == 128) == 8)))); //second solution

//     CHECK_THROWS(solve((x ^ 3) + (x ^ 3) == 16) == 2);

//     CHECK_THROWS(solve((x ^ 3) + (x ^ 3) == -16) == -2);

//     CHECK_THROWS(solve((x ^ 2) - (x ^ 2) == 0) == 0);

//     (solve(2 * (x ^ 2) - (x ^ 2) - 1 == 0) == 1); //21
// }

// TEST_CASE("RealVariable - throw cases")
// {

//     RealVariable x;

//     CHECK_THROWS(solve((x ^ 2) == -1));

//     CHECK_THROWS(solve(2 * x / x == 10));

//     CHECK_THROWS(solve((x * 2 - 10) / x == 10));

//     CHECK_THROWS(solve(2 * x / x == 3));
// }
