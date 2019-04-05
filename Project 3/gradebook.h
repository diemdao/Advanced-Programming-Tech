/* gradebook.h Copyright 2019
 * Written by Diem Dao, CSCE 240
 */
#ifndef _HW3_GRADEBOOK_H_  // NOLINT , nolint so you don't have to write all the directory before like /home/diem/textbook/cs240/hw3/gradebook.h << nolint will not
#define _HW3_GRADEBOOK_H_  // NOLINT

#include <cmath>
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
  /* Adds a new grade to the gradebook instance, increasing size by 1.
   */
  void Add(double grade);


  /* Returns the grade at the supplied index. When that index is out of range, a
   * value of NAN (from cmath) is returned.
   */
  double Get(size_t index) const;


  /* Adds two GradeBook instances together and returns their join as a new
   * object.
   * Order is maintained by adding the calling instance's grades to the new
   * Gradebook instance, followed by the parameter GradeBook's instances.
   */
  const GradeBook Add(const GradeBook& that) const;


  /* Returns the average of all grades stored in GradeBook instance, or NAN(from
   * cmath) if the the GradeBook instance is empty.
   */
  double GetGPA() const;


  /* Returns the max grade in the GradeBook or NAN if the calling instance is
   * empty.
   */
  double GetMax() const;


  /* Returns the number of grades currently stored by the GradeBook.
   */
  const size_t GetSize() const;


  /* Returns true when two GradeBook instances have the same average grade
   * value; returns false otherwise. An empty instance is treated as having an
   * average grade value of -infinity.
   * Equality should be true if the grades are within 0.00001 of each other.
   */
  bool Equals(const GradeBook& that) const;


  /* Returns true when the calling instance has a smaller grade average than the
   * paramter instance's average. If they are even, it compares their max
   * grades. An empty instance is treated as having an average grade value of
   * -infinity.
   */
  bool LessThan(const GradeBook& that) const;

 private:
  vector<double> grades_vector_;
};


#endif  // NOLINT
