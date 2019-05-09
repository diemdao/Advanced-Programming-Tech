/* gradebook.cc Copyright 2019
 * Written by Diem Dao, CSCE 240
 */
#include "../hw4/gradebook.h"

void GradeBook::Add(double grade) {
  grades_.push_back(grade);
}
double GradeBook::Get(size_t index) const {
  return index < grades_.size() ? grades_[index] : NAN;
}
const size_t GradeBook::GetSize() const {
  return grades_.size();
}

/* Returns the average of all grades stored in GradeBook instance, or NAN(from
 * cmath) if the the GradeBook instance is empty.
 */
double GradeBook::GetGPA() const {
  if (grades_.empty()) {
    return NAN;
  }
  double total = 0.0, average = 0.0;
  for (unsigned int i = 0 ; i < GetSize(); ++i) {
    total += grades_[i];
  }
  average = total/GetSize();
  return average;
}

/* Returns the max grade in the GradeBook or NAN if the calling instance is
 * empty.
 */
double GradeBook::GetMax() const {
  if (grades_.empty()) {
    return NAN;
  }
  double max_score = 0.0;
  for (unsigned int i = 0 ; i < GetSize(); ++i) {
    double storing_grade = grades_[i];
    if (max_score < storing_grade) {
      max_score = storing_grade;
    }
  }
  return max_score;
}

  /* Returns a new GradeBook instance with the floating point parameter
   * appended, increasing size by 1.
   *
   * Note: This is a very expensive operator (O(n) time) for what should be
   * near-constant process. Would be better implemented as operator+= which
   * requires Chapter 10.
   */
  const GradeBook GradeBook::operator+(double rhs) const {
  // need to return a GradeBook object, take in double and add
  GradeBook a;
  for (size_t i = 0; i < GetSize(); ++i) {
  a.Add(Get(i));
  // cout << "first a :" << i << endl;
  }
  a.Add(rhs);
  return a;
  }

  /* Adds two GradeBook instances together and returns their join as a new
   * object.
   * Order is maintained by adding the calling instance's grades to the new
   * Gradebook instance, followed by the parameter GradeBook's instances.
   */
  const GradeBook GradeBook::operator+(const GradeBook& rhs) const {
  GradeBook a;
    for (size_t i = 0 ; i < GetSize(); ++i) {
      a.Add(Get(i));
      // cout << "first a :" << i << endl; //  to see what is going on
    }
    //  add the 2 grades two gradebooks to one
    for (size_t i = 0; i < rhs.GetSize(); ++i) {
      a.Add(rhs.Get(i));
     // cout << "second a: " << i << endl; //  to see what is going on
    }
    return a;
  }

  /* Returns true when two GradeBook instances have the same average grade
   * value; returns false otherwise. An empty instance is treated as having an
   * average grade value of -infinity.
   * Equality should be true if the grades' average are within 0.00001 of each
   * other.
   */
  bool GradeBook::operator==(const GradeBook& rhs) const {
  // cout << "that.GetGPA: " << that.GetGPA() << endl;
    if (grades_.empty()) {
      return -INFINITY;
    }
    double total = 0.0;
    double average = 0.0;
    for (size_t i = 0 ; i < GetSize(); ++i) {
      total += grades_[i];
    }
    average = total/GetSize();
    if (average == rhs.GetGPA()) {
      return true;
    }
    // cout << "rhs.GetGPA: " << rhs.GetGPA() << endl;

    return false;
  }

  /* Returns true when the double parameter is equal to the average of all the
   * grades stored in calling GradeBook instance. Treat average as -INFINITY if
   * calling instance is empty.
   * Equality should be true if the grade's instance are within 0.00001 of
   * floating point parameter.
   */
  bool GradeBook::operator==(double rhs) const {
  if (grades_.empty()) {
      return -INFINITY;
    }
    double total = 0.0;
    double average = 0.0;
    for (size_t i = 0 ; i < GetSize(); ++i) {
      total += grades_[i];
    }
    average = total/GetSize();
    // cout << "rhs value" << rhs << endl;
    // cout << "average: " << rhs << endl;
    if (average == rhs) {
      return true;
    }
    return false;
  }

  /* Returns true when the calling instance has a smaller grade average than the
   * paramter instance's average. If they are even, it compares their max
   * grades. An empty instance is treated as having an average grade value of
   * -infinity.
   */
  bool GradeBook::operator<(const GradeBook& rhs) const {
  // cout << "that.GetGPA: " << that.GetGPA() << endl;
    if (grades_.empty()) {
      return -INFINITY;
    }

    double max_score = 0.0;
      for (unsigned int i = 0 ; i < GetSize(); ++i) {
        double storing_grade = grades_[i];
        if (max_score < storing_grade) {
          max_score = storing_grade;
        }
      }

    double total = 0.0;
    double average = 0.0;
    for (unsigned int i = 0 ; i < GetSize(); ++i) {
      total += grades_[i];
    }
    average = total/GetSize();

    if (average < rhs.GetGPA()) {
      // cout << "Average in LessEquals: " << average << endl;
      // cout << "rhs.GetGPA in LessEquals: " << rhs.GetGPA() << endl;
      return true;
    } else if (average == rhs.GetGPA()) {
      if (max_score < rhs.GetMax()) {
        // cout << "MAX in LessEquals: " << max_score << endl;
        return true;
      } else {
        return false;
      }
    }
    return false;
  }

  /* Returns true when the calling instance has a smaller grade average than the
   * floating point parameter. 
   */
  bool GradeBook::operator<(double rhs) const {
  // cout << "that.GetGPA: " << that.GetGPA() << endl;
    if (grades_.empty()) {
      return -INFINITY;
    }
    double total = 0.0;
    double average = 0.0;
    for (unsigned int i = 0 ; i < GetSize(); ++i) {
      total += grades_[i];
    }
    average = total/GetSize();

    if (average < rhs) {
      // cout << " LessEquals(double rhs): " << average << endl;
      return true;
    }
    return false;
  }

// ------these below are functions

/* Returns a new GradeBook instance with the floating point parameter
 * appended.
 *
 * Note: This is a very expensive operator (O(n) time) for what should be
 * near-constant process. Would be better implemented as operator+= which
 * requires Chapter 10.
 */
const GradeBook operator+(double lhs, const GradeBook& rhs) {
GradeBook a;
for (size_t i = 0; i < rhs.GetSize(); ++i) {
a.Add(rhs.Get(i));
}
a.Add(lhs);
// cout << "lhs value: " << lhs << endl;
return a;
}

/* Returns true when the double parameter is equal to the average of all the
 * grades stored in the GradeBook instance. Treat average as -INFINITY if
 * either GradeBook instance is empty.
 * Equality should be true if the grade's instance are within 0.00001 of
 * floating point parameter.
 */
bool operator==(double lhs, const GradeBook& rhs) {
if (lhs == rhs.GetGPA()) {
// cout << "lhs value: " << lhs << endl;
// cout  << "compare value" << rhs.GetGPA() << endl;
return true;
}
if (lhs + 0.0001 == rhs.GetGPA()) {
return true;
}
if (lhs - 0.0001 == rhs.GetGPA()) {
return true;
} else {
return false;
}
}

/* Returns true when the floating point parameter is less than the grade average
 * of the GradeBook parameter.
 */
bool operator<(double lhs, const GradeBook& rhs) {
if (lhs < rhs.GetGPA()) {
// cout << "lhs value: " << lhs << endl;
// cout  << "compare value" << rhs.GetGPA() << endl;
return true;
} else {
return false;
}
}
