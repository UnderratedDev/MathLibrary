//
// Created by Yudhvir Raj on 2018-07-14.
//

#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    Matrix a = Matrix::create(3, 2);
    Matrix b = Matrix::create(3, 2);
    a.set_value(0, 0, 10);
    a.set_value(0, 1, 15);
    b.set_value(0, 0, 2);
    b.set_value(1, 1, 20);
    cout << a << endl;
    cout << b << endl;
    Matrix c = a + b;
    cout << c << endl;
    double **arr = new double*[3];
    double aa[3] = {1, 2, 3};
    double ab[3] = {4, 5, 6};
    arr[0] = aa;
    arr[1] = ab;

    Matrix d = Matrix::set(arr, 3, 2);
    cout << d << endl;
    Matrix e = c + d;
    cout << e << endl;
    cout << e - d << endl;
}