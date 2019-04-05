/* gradebook.cc Copyright 2019
 * Written by Diem Dao, CSCE 240
 */

#include "../hw3/gradebook.h" //should be something like this

  /* Adds a new grade to the gradebook instance, increasing size by 1.
   */
  void GradeBook::Add(double grade) {
    grades_vector_.push_back(grade);  //  push in the grade to the vector
    // cout <<"G "<< endl; //to see what is going on
    // // to see what is going on
    // for(unsigned int i = 0; i < grades_vector_.size(); ++i){
    //   cout << grades_vector_[i] << " ";
    // }
  }

  /* Returns the grade at the supplied index. When that index is out of range, a
   * value of NAN (from cmath) is returned.
   */
  double GradeBook::Get(size_t index) const {
    if (grades_vector_.empty()) {
      return NAN;
    }
    return grades_vector_.at(index);
  }


  /* Adds two GradeBook instances together and returns their join as a new
   * object.
   * Order is maintained by adding the calling instance's grades to the new
   * Gradebook instance, followed by the parameter GradeBook's instances.
   */
  const GradeBook GradeBook::Add(const GradeBook& that) const {
    //  remember passing in a class object
    GradeBook a;  //  new object variable called a
    //  assigned the grades to a
      
      //    for (unsigned int i = 0 ; i < static_cast<int>(GetSize()); ++i) { //we can do this for safer, because will need this number to be positive and round up to the number
      //or this >> for (size_t int i = 0 ; i < GetSize(); ++i)
    for (unsigned int i = 0 ; i < GetSize(); ++i) { //unsigned for positive number and make the file safer
      a.Add(grades_vector_[i]);
      //  cout << "first a :" << i << endl; //to see what is going on
    }
      
      
    //  add the 2 grades two gradebooks to one
    for (unsigned int i = 0; i < that.GetSize(); ++i) {
      a.Add(that.Get(i));
      //  cout << "second a: " << i << endl; //to see what is going on
    }
    return a;
  }


  /* Returns the average of all grades stored in GradeBook instance, or NAN(from
   * cmath) if the the GradeBook instance is empty.
   */
  double GradeBook::GetGPA() const {
    if (grades_vector_.empty()) {
      return NAN;
    }

    double total = 0.0;
    double average = 0.0;
    for (unsigned int i = 0 ; i < GetSize(); ++i) {
      total += grades_vector_[i];
    }
    average = total/GetSize();
    return average;
  }


  /* Returns the max grade in the GradeBook or NAN if the calling instance is
   * empty.
   */
  double GradeBook::GetMax() const {
    if (grades_vector_.empty()) {
      return NAN;
    }

    double max_score = 0.0;
    for (unsigned int i = 0 ; i < GetSize(); ++i) {
      double storing_grade = grades_vector_[i];
      if (max_score < storing_grade) {
        max_score = storing_grade;
      }
    }
    return max_score;
  }


  /* Returns the number of grades currently stored by the GradeBook.
   */
  const size_t GradeBook::GetSize() const {
    return grades_vector_.size();
  }


  /* Returns true when two GradeBook instances have the same average grade
   * value; returns false otherwise. An empty instance is treated as having an
   * average grade value of -infinity.
   * Equality should be true if the grades are within 0.00001 of each other.
   */
  bool GradeBook::Equals(const GradeBook& that) const {
    if (grades_vector_.empty()) {
      return NAN;
    }

    double total = 0.0;
    double average = 0.0;
    for (unsigned int i = 0 ; i < GetSize(); ++i) {
      total += grades_vector_[i];
    }
    average = total/GetSize();
    if (average == that.GetGPA()) {
      return true;
    }

    return false;
  }


  /* Returns true when the calling instance has a smaller grade average than the
   * paramter instance's average. If they are even, it compares their max
   * grades. An empty instance is treated as having an average grade value of
   * -infinity.
   */
  bool GradeBook::LessThan(const GradeBook& that) const {
    if (grades_vector_.empty()) {
      return NAN;
    }

    double max_score = 0.0;
      for (unsigned int i = 0 ; i < GetSize(); ++i) {
        double storing_grade = grades_vector_[i];
        if (max_score < storing_grade) {
          max_score = storing_grade;
        }
      }

    double total = 0.0;
    double average = 0.0;
    for (unsigned int i = 0 ; i < GetSize(); ++i) {
      total += grades_vector_[i];
    }
    average = total/GetSize();
    if (average < that.GetGPA()) {
      return true;
    } else if (average == that.GetGPA()) {
      if (max_score < that.GetMax()) {
        return true;
      } else {
        return false;
      }
    }

    return false;
}
