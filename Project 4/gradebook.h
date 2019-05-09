/* gradebook.h Copyright 2019
 * Written by Diem Dao, CSCE 240
 */
#ifndef _HW4_GRADEBOOK_H_  // NOLINT
#define _HW4_GRADEBOOK_H_  // NOLINT

#include <cmath>
#include <stddef.h>
#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <sstream>
using std::stringstream;
#include <string>
using std::string;

class GradeBook {
 public:
  void Add(double);
  double Get(size_t) const;
  const size_t GetSize() const;
  double GetGPA() const;
  double GetMax() const;

  /* Returns a new GradeBook instance with the floating point parameter
   * appended, increasing size by 1.
   *
   * Note: This is a very expensive operator (O(n) time) for what should be
   * near-constant process. Would be better implemented as operator+= which
   * requires Chapter 10.
   */
  const GradeBook operator+(double rhs) const;

  /* Adds two GradeBook instances together and returns their join as a new
   * object.
   * Order is maintained by adding the calling instance's grades to the new
   * Gradebook instance, followed by the parameter GradeBook's instances.
   */
  const GradeBook operator+(const GradeBook& rhs) const;

  /* Returns true when two GradeBook instances have the same average grade
   * value; returns false otherwise. An empty instance is treated as having an
   * average grade value of -infinity.
   * Equality should be true if the grades' average are within 0.00001 of each
   * other.
   */
  bool operator==(const GradeBook& rhs) const;

  /* Returns true when the double parameter is equal to the average of all the
   * grades stored in calling GradeBook instance. Treat average as -INFINITY if
   * calling instance is empty.
   * Equality should be true if the grade's instance are within 0.00001 of
   * floating point parameter.
   */
  bool operator==(double rhs) const;

  /* Returns true when the calling instance has a smaller grade average than the
   * paramter instance's average. If they are even, it compares their max
   * grades. An empty instance is treated as having an average grade value of
   * -infinity.
   */
  bool operator<(const GradeBook& rhs) const;

  /* Returns true when the calling instance has a smaller grade average than the
   * floating point parameter. 
   */
  bool operator<(double rhs) const;

 private:
  std::vector<double> grades_;
};

/* Returns a new GradeBook instance with the floating point parameter
 * appended.
 *
 * Note: This is a very expensive operator (O(n) time) for what should be
 * near-constant process. Would be better implemented as operator+= which
 * requires Chapter 10.
 */
const GradeBook operator+(double lhs, const GradeBook& rhs);

/* Returns true when the double parameter is equal to the average of all the
 * grades stored in the GradeBook instance. Treat average as -INFINITY if
 * either GradeBook instance is empty.
 * Equality should be true if the grade's instance are within 0.00001 of
 * floating point parameter.
 */
bool operator==(double lhs, const GradeBook& rhs);

/* Returns true when the floating point parameter is less than the grade average
 * of the GradeBook parameter.
 */
bool operator<(double lhs, const GradeBook& rhs);

#endif  // NOLINT
