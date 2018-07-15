//
// Created by Yudhvir Raj on 2018-07-14.
//

#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    Matrix m = Matrix::create(3, 2);
    cout << m << endl;
    m.set_value(0, 0, 10);
    cout << m;
}