/* matrix.cc Copyright 2019
 * Written by Diem Dao, CSCE 240
 */
#include <matrix.h>

// default constructor
Matrix::Matrix() : m_(nullptr), rows_(0), cols_(0) {}

Matrix::Matrix(unsigned int rows, unsigned int cols) :
    rows_(rows), cols_(cols) {
  assert(rows > 0);  // assert preconditions are true
  assert(cols > 0);  // assert preconditions are true

  m_ = new double *[rows_];  // create array of double pointers
  for (unsigned int i = 0; i < rows_; ++i)
    m_[i] = new double[cols_];  // create array of doubles
}

  /* Copy Constructor: 2 Points
   *   Performs deep copy.
   */
Matrix::Matrix(const Matrix& that) {
// copy of that object, and have to have the same value
  m_ = new double *[that.rows_];
  rows_ = that.rows_;
  cols_ = that.cols_;
  for (unsigned int i = 0; i < rows_; ++i) {
    m_[i] = new double[cols_];
    // m_[i] = that.m_[i];
    // cout << "testing deepcopy: " << m_[i] << endl;
    // deep copy of each row
  }
  for (unsigned int i = 0; i < rows_; ++i) {
    for (unsigned int j = 0; j < cols_; ++j) {
      m_[i][j] = that.m_[i][j];
    }
  }
  // cols_ = that.cols_;
}

/* Destructor: Required For Any Points
 *   Cleans up memory to avoid leaks
 */
Matrix::~Matrix() {
  if (m_) {
    for (unsigned int i = 0; i < rows_; ++i)
       delete [] m_[i];
    delete [] m_;
  }
}

  /* Accessor: 1 Point
   *   Precondition(s):
   *   - Parameter row is less than rows in matrix
   *   - Parameter col is less than cols in matrix
   *   Does what you would expect.
   */
double Matrix::Get(unsigned int row, unsigned int col) const {
// get and return a value
// Precondition(s)
  assert(row < rows_);
  assert(col < cols_);
// cout << "Get method testing: " << m_[row][col] << endl;
// take in the indexes from the parameter and return that value
  return m_[row][col];
}

/* Assignment Op: 2 Points
   *   Precondition(s):
   *   - lhs rows must equal rhs rows
   *   - lhs cols must equal rhs cols
   *   Performs deep copy.
   */
const Matrix& Matrix::operator=(const Matrix& rhs) {
  if (this == &rhs)
    return *this;
  if (m_) {
    for (unsigned int i = 0; i < rows_; ++i)
      delete [] m_[i];
    delete [] m_;
  }

  m_ = new double*[rhs.rows_];
  // Precondition(s)
  rows_ = rhs.rows_;
  cols_ = rhs.cols_;
  for (unsigned int i = 0; i < rows_; ++i) {
    m_[i] = new double[cols_];
  }
  for (unsigned int i = 0; i < rows_; ++i) {
    for (unsigned int j = 0; j < cols_; ++j) {
      // cout << "testing operetor= before assign: " << rhs.m_[i][j] << endl;
      m_[i][j] = rhs.m_[i][j];
      // cout << "testing operetor= after assign: " << m_[i][j] << endl;
    }
  }
  return *this;
}

  /* Times Equals Op: 2 Points
   *   Returns calling object with matrix scaled by rhs.
   */
const Matrix& Matrix::operator*=(double rhs) {
// create a new matrix with the same row and col
// cout << "remember the test multiple the value by 2" << endl;
    for (unsigned int i = 0; i < rows_ ; ++i) {
      for (unsigned int j = 0; j < cols_; ++j) {
        // cout << "testing op*= before assign: " << m_[i][j] << endl;
        m_[i][j] = m_[i][j]*rhs;
        // cout << "testing op*= after assign: " << m_[i][j] << endl;
      }
    }
  return *this;
}


  /* Add Op: 2 points
   *   Returns the sum of calling object's matrix and rhs's matrix as a new
   *   object.
   * Precondition(s):
   *   - lhs rows must equal rhs rows
   *   - lhs cols must equal rhs cols
   */
const Matrix Matrix::operator+(const Matrix& rhs) const {
// return an entire matrix because it doesn't use the Matrix&
// so create a new object
  Matrix newM(rhs.rows_, rhs.cols_);
  for (unsigned int i = 0; i < rows_ ; ++i) {
    for (unsigned int j = 0; j < cols_; ++j) {
    // cout << "At index: " << i << ", " << j << endl;
    // cout << "First m: " << m_[i][j] << endl;
    // cout << "rhs m: " << rhs.m_[i][j] << endl;
      newM.m_[i][j] = m_[i][j] + rhs.m_[i][j];
    // cout << "Result : " << a_.m_[i][j] << endl << endl;
    }
  }
  return newM;
}

