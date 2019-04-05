/* test_get_ids.cc copyright 2019
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

bool TestGetIds();
bool TestGetIdsCorrupt();


int main(int argc, char* argv[]) {
    int passed = 0;
    
    //test get_ids
    cout << "Testing get_ids" << endl;
    if (TestGetIds())
        cout << "  PASSED" << endl;
    else {
        cout << "  FAILED" << endl;
        passed = 1;
    }
    
    cout << "Test get_ids with corrupt format" << endl;
    if (TestGetIdsCorrupt())
        cout << "  PASSED" << endl;
    else {
        cout << "  FAILED" << endl;
        passed = 1;
    }
    
    return passed;
}


bool TestGetIds(){
    bool passed = true;
    int expected_return = 2;
    int actual_return;
    int expected_ids[] = {1234, 2345};
    int actual_ids[2];
    
    actual_return = get_student_ids(kValues, kSize, actual_ids);
    
    if (expected_return != actual_return){
        cout << "Excepted return:" << expected_return
            << ", Actual return: " << actual_return << endl;
        passed = false;
    }
    for (int i = 0; i < actual_return; ++i) {
        if(expected_ids[i] != actual_ids[i]){
            cout << "Excepted id[" << i << "]:" << expected_ids[i]
                << ", Actual id[" << i << "]:" << actual_ids[i] << endl;
            passed = false;
        }
    }
    return passed;
}

bool TestGetIdsCorrupt(){
    int actual_ids[4];
    int expected_return = -10;
    int actual_return = get_student_ids(kValues, kSize -2, actual_ids);
    if (expected_return != actual_return){
        cout << "\tExpected return: " << expected_return
        << ", Actual return: " << actual_return << endl;
        return false;
    }
    
    return true;
}
