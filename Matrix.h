//
// Created by Yudhvir Raj on 2018-07-14.
//
// Matrix.h

#ifndef MATHLIBRARY_MATRIX_H
#define MATHLIBRARY_MATRIX_H

#include <iostream>
#include <stdexcept>
/*
 * represents a Matrix
 */
class Matrix {
private:
    /*
     * constructor
     */
    // constructor for Matrix
    Matrix(int cols, int rows);

    /*
     * properties
     */
    // columns of matrix
    int cols;
    // rows of matrix
    int rows;
    // values of matrix
    double **values;

    /*
     * methods
     */
    /*
     * helper functions
     */
    // function to initialise the default values
    void initValues();
    // function to zero the matrix
    void zeroValues();

public:
    /*
     * destructor
     */
    // delete a Matrix object
    ~Matrix();

    /*
     * static functions
     */
    // named constructor
    static Matrix create(int cols, int rows);

    /*
     * setters
     */
    // set the value in the matrix
    void setValue(int x, int y, double val);
    // set the values of a column to a specific value
    void setColValues(int x, double val);
    // set the values of a row to a specific value
    void setRowValues(int y, double val);

    /*
     * getters
     */
    // get columns
    int getCols() const;
    // get rows
    int getRows() const;
    // get value in matrix
    double getValue(int x, int y) const;

    /*
     * operator overloading
     */
    // overload <<, output
    friend std::ostream& operator<<(std::ostream& os, const Matrix &m);
};

#endif //MATHLIBRARY_MATRIX_H
