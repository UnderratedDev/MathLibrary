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
    void init_values();
    // function to zero the matrix
    void zero_values();

    /*
     * error checks
     */
    // check if x is out of bounds
    void check_x(int x) const;
    // check if y is out of bounds
    void check_y(int y) const;
    // check if x or y are out of bounds
    void check_xy(int x, int y) const;

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
    void set_value(int x, int y, double val);
    // set the values of a column to a specific value
    void set_col_values(int x, double val);
    // set the values of a row to a specific value
    void set_row_values(int y, double val);

    /*
     * getters
     */
    // get columns
    int get_cols() const;
    // get rows
    int get_rows() const;
    // get value in matrix
    double get_value(int x, int y) const;

    /*
     * operator overloading
     */
    // overload <<, output
    friend std::ostream& operator<<(std::ostream& os, const Matrix &m);
};

#endif //MATHLIBRARY_MATRIX_H
