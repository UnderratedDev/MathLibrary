//
// Created by Yudhvir Raj on 2018-07-14.
//
// Matrix.cpp

#include "Matrix.h"

/*
 * helper methods
 */
// init the values in the matrix
void Matrix::init_values() {
    this->values = new double*[this->rows];
    for (int y = 0; y < this->rows; ++y) {
        this->values[y] = new double[this->cols];
        this->set_row_values(y, 0.0);
    }
}

// init the values in the matrix to zero
void Matrix::zero_values() {
    for(int y = 0; y < this->rows; ++y)
        for(int x = 0; x < this->cols; ++x)
            this->values[y][x] = 0.0;
}

// check if x if out of bounds
void Matrix::check_x(int x) const {
    if(x < 0 || x >= this->cols)
        throw std::logic_error("x must be non-negative and less than the number of columns");
}

// check if y is out of bounds
void Matrix::check_y(int y) const  {
    if(y < 0 || y >= this->rows)
        throw std::logic_error("y must be non-negative and less than the number of rows");
}

// check if x or y are out of bounds
void Matrix::check_xy(int x, int y) const  {
    if(x < 0 || x >= this->cols || y < 0 || y >= this->rows)
        throw std::logic_error("x and y must be non negative values and less than the columns and rows");
}

// check same dimensions of two matrices
void Matrix::check_dimension(const Matrix &b) const {
    if (this->cols != b.get_cols() || this->rows != b.get_rows())
        throw std::logic_error("dimensions of both matrices must be the same");
}

// check if columns or rows are non negative
void Matrix::check_non_negative(int cols, int rows) {
    if (cols < 1 || rows < 1)
        throw std::logic_error("Matrix must have at least 1 column and 1 row");
}

/*
 * setters
 */
// set value in the matrix
void Matrix::set_value(int x, int y, double val) {
    this->check_xy(x, y);
    this->values[y][x] = val;
}

// set values in the matrix
void Matrix::set_values(double **values) {
    this->values = values;
}

// set the values of a column to a specific value
void Matrix::set_col_values(int x, double val) {
    this->check_x(x);
    for(int y = 0; y < this->rows; ++y)
        this->values[y][x] = val;
}

// set the values of a row to a specific value
void Matrix::set_row_values(int y, double val) {
    this->check_y(y);
    for(int x = 0; x < this->cols; ++x)
        this->values[y][x] = val;
}

// set the values of the matrix to a specific value
void Matrix::set_matrix_values(double val) {
    for (int x = 0; x < this->cols; ++x)
        this->set_col_values(x, val);
}

// set the values of the matrix to populated array
void Matrix::set_matrix(double **values, int cols, int rows) {
    this->cols = cols;
    this->rows = rows;
    this->values = values;
}

/*
 * getters
 */
// get the columns
int Matrix::get_cols() const {
    return this->cols;
}

// get the rows
int Matrix::get_rows() const {
    return this->rows;
}

// get value in matrix
double Matrix::get_value(int x, int y) const {
    this->check_xy(x, y);
    return this->values[y][x];
}

/*
 * constructor
 */
// constructor for Matrix
Matrix::Matrix(int cols, int rows): cols(cols), rows(rows) {
    this->init_values();
}

// create a matrix
Matrix Matrix::create(int cols, int rows) {
    Matrix::check_non_negative(cols, rows);
    return Matrix(cols, rows);
}

// create a matrix with values
Matrix Matrix::set(double **values, int cols, int rows) {
    Matrix::check_non_negative(cols, rows);
    Matrix m = Matrix(cols, rows);
    m.set_values(values);
    return m;
}
/*
 * destructor
 */
// delete a matrix
Matrix::~Matrix() {
    delete this->values;
    this->values = nullptr;
}

/*
 * operator overloading
 */
// overload +, add
Matrix Matrix::operator+(const Matrix &m) const {
    this->check_dimension(m);
    Matrix a = Matrix::create(this->cols, this->rows);
    for(int x = 0; x < this->cols; ++x)
        for(int y = 0; y < this->rows; ++y)
            a.set_value(x, y, this->get_value(x, y) + m.get_value(x, y));
    return a;
}

// overload -, subtract
Matrix Matrix::operator-(const Matrix &m) const {
    this->check_dimension(m);
    Matrix a = Matrix::create(this->cols, this->rows);
    for(int x = 0; x < this->cols; ++x)
        for(int y = 0; y < this->rows; ++y)
            a.set_value(x, y, this->get_value(x, y) - m.get_value(x, y));
    return a;
}

// overload <<, output
std::ostream & operator<<(std::ostream &os, const Matrix &m) {
    int cols = m.get_cols(), rows = m.get_rows();
    os << "columns: " << cols << ", rows: " << rows << std::endl;
    for (int y = 0; y < rows; ++y) {
        os << '|';
        for (int x = 0; x < cols; ++x)
            os << m.get_value(x, y) << '|';
        os << std::endl;
    }
    return os;
}