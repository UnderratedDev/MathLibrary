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
    void check_x(int) const;
    // check if y is out of bounds
    void check_y(int) const;
    // check if x or y are out of bounds
    void check_xy(int, int) const;
    // check same dimensions of two matrices
    void check_dimension(const Matrix &) const;
    // check if columns or rows are non negative
    static void check_non_negative(int, int);

public:
    /*
     * destructor
     */
    // delete a Matrix object
    ~Matrix();

    /*
     * static functions
     */
    // named constructor, create new Matrix
    static Matrix create(int, int);
    // named constructor, create new matrix with values
    static Matrix set(double**, int, int);

    /*
     * setters
     */
    // set the value in the matrix
    void set_value(int, int, double);
    // set the values in the matrix
    void set_values(double**);
    // set the values of a column to a specific value
    void set_col_values(int, double);
    // set the values of a row to a specific value
    void set_row_values(int, double);
    // set the values of the matrix to a specific value
    void set_matrix_values(double);
    // set the values of the matrix to populated array
    void set_matrix(double**, int, int);

    /*
     * getters
     */
    // get columns
    int get_cols() const;
    // get rows
    int get_rows() const;
    // get value in matrix
    double get_value(int, int) const;

    /*
     * operator overloading
     */
    // overload +, add
    Matrix operator+(const Matrix &) const;
    // overload -, subtract
    Matrix operator-(const Matrix &) const;
    // overload <<, output
    friend std::ostream& operator<<(std::ostream& os, const Matrix &m);
};

#endif //MATHLIBRARY_MATRIX_H
