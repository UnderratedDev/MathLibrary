//
// Created by Yudhvir Raj on 2018-07-14.
//
// Matrix.cpp

#include "Matrix.h"

// init the values in the matrix
void Matrix::initValues() {
    this->values = new double*[this->cols];
    for (int x = 0; x < this->cols; ++x) {
        this->values[x] = new double[this->rows];
        this->setColValues(x, 0.0);
    }
}

void Matrix::zeroValues() {
    for(int x = 0; x < this->cols; ++x)
        for(int y = 0; y < this->rows; ++y)
            this->values[x][y] = 0.0;
}

/*
 * setters
 */
// set value in matrix
void Matrix::setValue(int x, int y, double val) {
    this->values[x][y] = val;
}

// set the values of a column to a specific value
void Matrix::setColValues(int x, double val) {
    for(int y = 0; y < this->rows; ++y)
        this->values[x][y] = val;
}

// set the values of a row to a specific value
void Matrix::setRowValues(int y, double val) {
    for(int x = 0; x < this->cols; ++x)
        this->values[x][y] = val;
}

/*
 * getters
 */
// get the columns
int Matrix::getCols() const {
    return this->cols;
}

// get the rows
int Matrix::getRows() const {
    return this->rows;
}

// get value in matrix
double Matrix::getValue(int x, int y) const {
    return this->values[x][y];
}

/*
 * constructor
 */
// constructor for Matrix
Matrix::Matrix(int cols, int rows): cols(cols), rows(rows) {
    this->initValues();
}

// create a matrix
Matrix Matrix::create(int cols, int rows) {
    if (cols < 1 || rows < 1) {
        // return Matrix(cols, rows);
        throw std::logic_error("Matrix must have at least 1 column and 1 row");
    }
    return Matrix(cols, rows);
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
std::ostream & operator<<(std::ostream &os, const Matrix &m) {
    int cols = m.getCols(), rows = m.getRows();
    os << "columns: " << cols << ", rows: " << rows << std::endl;
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x)
            os << m.getValue(x, y);
        os << std::endl;
    }
    return os;
}