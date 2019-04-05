/* parse_scores.cc copyright 2019
 * written by Diem Dao, CSCE240-003
 */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  /* The following input
   *
   *   2 1234 3 98.7 87.92 77.32 2345 3 93.1 90.23 81.21
   *
   * would result in the following output.
   */
  int number_of_students, student_id, max_id, number_of_grades = 0;
  double max_score, grade_n = 0.0;
  cin >> number_of_students;
  cout << "{" << endl;
  cout << "  \"students\" : [" << endl;
  // loop through number of students from input
  for (int i = 0; i < number_of_students; ++i) {
    // take in student id
    cin >> student_id;
    // take in number of grades
    cin >> number_of_grades;
    // print out student id
    cout << "    { \"id\" : " << student_id << ", \"grades\" : [ ";
    // loop through number of  grades
    for (int j = 0; j < number_of_grades; ++j) {
      // take in each grade number
      cin >> grade_n;
      // compare to get max score then assign student
      if (max_score < grade_n) {
        max_score = grade_n;
        max_id = student_id;
      }
      // print out the grades
      cout << grade_n;
      // put comma between grades but not the last one
      if (j != number_of_grades-1) {
        cout << ", ";
      }
    }
  // this if statement below is for the comman after "]},"
  // after each student but not the last one
  if (i != number_of_students-1) {
    cout << " ] }," << endl;
  } else {
    cout << " ] }" << endl;
  }
  }
  cout << "\n  ]," << endl;
  cout << "  \"max_id\" : " << max_id << "," << endl;
  cout << "  \"max_score\" : "<< max_score << endl;
  cout << "}";
}


