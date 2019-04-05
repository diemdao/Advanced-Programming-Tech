/* parse_scores.cc copyright 2019
 * written by Diem Dao, CSCE240-003
 */
#include "parse_scores.h"

int check_array(const std::string values[], int size) {
    int index = 1;
    if (size != 0) {
        while (index < size) {
            if (index < size) {
                int id = stoi(values[index]);  // at index 1
                index++;  // next index
                if (index < size) {
                    int number_of_grades = stoi(values[index]);  // at index 2
                    index++;  // at index 3 then add 1
                    if (index + number_of_grades-1 < size) {
                        for (int j = 0; j < number_of_grades; ++j) {
                            double grade = stod(values[index]);
                            index++;
                            if (index > size) {
                                return -10;
                            }
                        }
                    } else {
                        return -10;
                    }
                } else {
                    return -10;
                }
            } else {
                return -10;
            }
        }
    } else {
        return -10;
    }
    return 0;
}

/* Description:
 *   Parses the values array to determine how many grades are present for a
 *   student selected by the id parameter and returns that value.
 * Preconditions:
 * - Parameter values has at least parameter size elements.
 * Parameters:
 * - id: the id of the student for which number of grades is returned
 * - values: a series of string input representing students and grades
 * - size: number of elements in values array
 * Returns:
 * - The number of grades for student with parameter id when student id is
 *     found.
 * - Integer -1 when a match for parameter id is not found in student ids
 * - Integer -10 when the format is corrupt i.e. 1 1234 3 99.7 82.1
 */
int get_num_grades(int id, const std::string values[], int size) {
    // Testing get_num_grades with corrupt format
    int check = check_array(values, size);
    if (check == -10) {
    return -10;
    }
    // Testing get_num_grades
    for (int i = 0; i < size; ++i) {  // loop through every index
        if (stoi(values[i]) == id) {  // at index 1, if id match
            int track_index = i + 1;  // go to index 2 to track numberOfGrades
            int number_of_grades = stoi(values[track_index]);  // get the values
            track_index++;  // at index of the first grade
            for (int j = 0; j < number_of_grades; ++j) {
                // this make it keep track of the index when if loop each grades
                track_index++;
            }
            return number_of_grades;
        }
    }
    // Testing id
    return -1;
}

/* Description:
 *   Parses the values array to get all grades for a student matching parameter
 *   id
 * Preconditions:
 * - Parameter values has at least parameter size elements
 * - Parameter grades is large enough to hold all grades for requested student
 * Postconditions:
 * - Parameter grades has the floating point representation of the corresponding
 *     grades for student matching parameter id
 * Parameters:
 * - id: the id of the student for which number of grades is returned
 * - values: a series of string input representing students and grades
 * - size: number of elements in values array
 * - grades: an input parameter into which the floating point representation of
 *     student's grades are stored
 * Returns:
 * - Number of grades parsed
 * - Integer -10 if format corrupt i.e. 2 1234 1 99.2 2345
 * - Integer -1 if id not found
 */
int get_grades(int id, const std::string values[], int size, double grades[]) {
    // testing format corrupt
    int check = check_array(values, size);
    if (check == -10) {
    return -10;
    }
    // Testing
    for (int i = 0; i < size; ++i) {  // loop through every index
        if (stoi(values[i]) == id) {  // at index 1, if id match
            int track_index = i + 1;  // go to index 2 to track numberOfGrades
            int number_of_grades = stoi(values[track_index]);  // get the values
            track_index++;  // at index of the first grade
            for (int j = 0; j < number_of_grades; ++j) {
                grades[j] = stod(values[track_index]);  // put in grades
                // this make it keep track of the index when if loop each grades
                track_index++;
            }
            return number_of_grades;
        }
    }

     return -1;
}

/* Description:
 *   Extracts a single grade for a given student and given grade index.
 * Preconditions:
 * - Parameter values has at least parameter size elements.
 * Parameters:
 * - id: the id of the student for which number of grades is returned
 * - grade_index: index of the grade to be returned for matching student
 * - values: a series of string input representing students and grades
 * - size: number of elements in values array
 * Returns:
 * - Grade selected
 * - Integer -1 when student is not found
 * - Integer -2 when grade_index is not found
 * - Integer -10 when values format is corrupt
 */
double get_grade(int id,
                 int grade_index, const std::string values[], int size) {
    // testing format corrupt
    int check = check_array(values, size);
    if (check == -10) {
    return -10;
    }

    // testing
    for (int i = 0; i < size; ++i) {  // loop through every index
        if (stoi(values[i]) == id) {  // at index 1, if id match
            int track_index = i + 1;  // go to index 2 to track numberOfGrades
            int number_of_grades = stoi(values[track_index]);  // get the values
            track_index++;  // at index of the first grade
            for (int j = 0; j < number_of_grades; ++j) {
                double grade = stod(values[track_index]);  // assign a grade
                // if the current index match with the grade index
                if (j == grade_index) {
                    return grade;
                }
                // this make it keep track of the index when if loop each grades
                track_index++;
            }
        }
    }

    // testing integer -2 when grade_index is not found
    for (int i = 0; i < size; ++i) {  // loop through every index
        if (stoi(values[i]) == id) {  // at index 1, if id match
            int track_index = i + 1;  // go to index 2 to track numberOfGrades
            int number_of_grades = stoi(values[track_index]);  // get the values
            track_index++;  //  at index of the first grade
            for (int j = 0; j < number_of_grades; ++j) {
                // if the current index match with the grade index
                if (j != grade_index) {
                    return -2;
                }
                // this make it keep track of the index when if loop each grades
                track_index++;
            }
        }
    }

    // testing id
    return -1;
}

/* Description:
 *   Extracts the id of the student with the highest grade.
 * Preconditions:
 * - Parameter values has at least parameter size elements.
 * Parameters:
 * - values: a series of string input representing students and grades
 * - size: number of elements in values array
 * Returns:
 * - The id of the student with the highest grade.
 * - Integer -1 when no students exist
 * - Integer -2 when no grades exist
 * - Integer -10 when the format is corrupt i.e. 1 1234 3 99.7 82.1
 */
int get_max_grade_id(const std::string values[], int size) {
    // Testing integer -10 when the format is corrupt i.e. 1 1234 3 99.7 82.1
    int check = check_array(values, size);
    if (check == -10) {
    return -10;
    }
    // testing id with highest grade
    double max_score = 0;
    int track = 1;
    int max_id = 0;
    for (int i = 0; i < stoi(values[0]); ++i) {  // num of students 2
        int current_id = stoi(values[track]);  // index 1
        int number_of_grades = stoi(values[track+1]);  // index 2
        for (int j = 0; j < number_of_grades; ++j) {  // num of grade
            double grade = stod(values[track+j+2]);
             if (max_score < grade) {
                    max_score = grade;
                    max_id = current_id;
                }
            }
            if (number_of_grades == 0) {
                return -2;
            }
            track += 2 + stoi(values[track+1]);
            return max_id;
        }

    return -1;
}

/* Description:
 *   Extracts the highest grade.
 * Preconditions:
 * - Parameter values has at least parameter size elements.
 * - Grades are nonnegative. Adjust accordingly.
 * Parameters:
 * - values: a series of string input representing students and grades
 * - size: number of elements in values array
 * Returns:
 * - The highest grade found.
 * - Integer -1 when no students exist
 * - Integer -2 when no grades exist
 * - Integer -10 when the format is corrupt i.e. 1 1234 3 99.7 82.1
 */
double get_max_grade(const std::string values[], int size) {
    int check = check_array(values, size);
    if (check == -10) {
    return -10;
    }

    double max_score = 0;
    int track = 1;
    int max_id = 0;
    for (int i = 0; i < stoi(values[0]); ++i) {  // num of students 2
        int current_id = stoi(values[track]);  // index 1
        int number_of_grades = stoi(values[track+1]);  // index 2
        for (int j = 0; j < number_of_grades; ++j) {  // num of grade
            double grade = stod(values[track+j+2]);
             if (max_score < grade) {
                    max_score = grade;
                    // max_id = current_id;
                }
            }
            if (number_of_grades == 0) {
                return -2;
            }
            track += 2 + stoi(values[track+1]);
            return max_score;
        }


    return -1;
}

/* Description:
 *   Parses the values array to extract all student ids. Stores the values in
 *   the parameter ids
 * Preconditions:
 * - Parameter values has at least parameter size elements
 * - Parameter ids is large enough to hold all student id values
 * Postconditions:
 * - Parameter ids has the integer values of the corresponding student ids.
 * Parameters:
 * - values: a series of string input representing students and grades
 * - size: number of elements in values array
 * - ids: an input parameter into which student ids are stored
 * Returns:
 * - Number of grades parsed
 * - Integer -10 if format corrupt i.e. 2 1234 1 99.2 2345
 */
int get_student_ids(const std::string values[], int size, int ids[]) {
    int check = check_array(values, size);
    if (check == -10) {
    return -10;
    }
    return -1;
}




