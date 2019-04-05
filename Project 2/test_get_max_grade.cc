/* parse_scores.cc copyright 2019
 * written by Diem Dao, CSCE240-003
 */
#include "parse_scores.h"

#include <cassert>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

std::string kValues[] = {
  "2",
  "1234", "3", "98.7", "87.92", "77.32",
  "2345", "4", "93.1", "90.23", "81.21", "89.33" };
int kSize = 12;


bool TestGetMaxGrade();
bool TestGetMaxGradeNoStudents();  // true when returns -1 when no student exist
bool TestGetMaxGradeNoGrades();  // true when returns -2 when no grades exist
bool TestGetMaxGradeFormatCorrupt();  // true when returns -10 for corrupt format


int main(int argc, char* argv[]) {
  int passed = 0;

  cout << "Testing get_max_grade" << endl;
  if (TestGetMaxGrade())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }

  cout << "Testing get_max_grade with no students exist" << endl;
  if (TestGetMaxGradeNoStudents())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }

  cout << "Testing get_max_grade with no grades exist" << endl;
  if (TestGetMaxGradeNoGrades())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }

  cout << "Testing get_max_grade with format corrupt" << endl;
  if (TestGetMaxGradeFormatCorrupt())
    cout << "  PASSED" << endl;
  else {
    cout << "  FAILED" << endl;
    passed = 1;
  }

  return passed;
}


bool TestGetMaxGrade() {  // true when max grade found
  int expected_max_grade = 98.7;
  int actual_max_grade = get_max_grade(kValues, kSize);
  if (expected_max_grade != actual_max_grade) {
    cout << "\tExpected max grade: " << expected_max_grade
        << ", Actual max grade: " << actual_max_grade << endl;
    return false;
  }

  return true;
}


bool TestGetMaxGradeNoStudents() {  // true when returns -1 when no student exist
  int expected = -1;
  std::string values[] = { "0" };
  int actual = get_max_grade(values, 1);
  if (expected != actual) {
    cout << "\tExpected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}


bool TestGetMaxGradeNoGrades() {  // true when returns -2 when no grades exist
  int expected = -2;
  std::string values[] = { "2", "1234", "0", "2345", "0" };
  int actual = get_max_grade(values, 5);
  if (expected != actual) {
    cout << "\tExpected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}


bool TestGetMaxGradeFormatCorrupt() {
  double expected = -10;
  double actual = get_max_grade(kValues, kSize-2);
  if (expected != actual) {
    cout << "\tExpected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}
