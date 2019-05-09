/* median.cc Copyright 2019
 * Written by Diem Dao, CSCE 240
 */
#include <median.h>

namespace csce240 {

/* Stores data (datum) such than the median may be determined.
 */
  void Median::Collect(double datum) {
    v_.push_back(datum);
    cout << "testing median collect: " << endl;
    for (unsigned int i = 0; i < v_.size(); ++i)
      cout << v_[i] << " ";
    cout << endl;
  }

  /* Calculates the median of the data (datum) from the Collect method.
   */
  double Median::Calculate() const {
  // median will get the middle one
  // so check if the size is even or odd
  // if it's odd then one middle
  // if (n%2 == 1) then set it to median
  // else it's even then 2 middle they calculate it by divide by 2
  // for(int (size/2)-1; i < (size/2)+1; i++) then do calculation
  // get those 2 value and divide by 2
  // total += v_[i] , inside loop
  // outside loop median = total/2;

    double total = 0.0;
    double median = 0.0;
    unsigned int sizeV = v_.size();
    cout << "Median value testing" << endl;
    // {34, 54, 99, 102, 43};
    // so 34, 43, 54, 99, 102
    // so you have to put them in order first before pick out the middle

    // sorting
    // sort(v_.begin(), v_.end());

    // sort by using arr because can't use vector double to sort
    // create an array and put it in
    // int n = v_.size();
    int arr[sizeV];
    for (unsigned int i = 0; i < sizeV; ++i) {
      arr[i] = v_[i];
    }
    cout << "New array: " << endl;
    for (unsigned int i = 0; i < sizeV; ++i) {
      cout << arr[i] << " ";
    }
    cout << endl;

    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr + n);

    cout << "Sorted array: " << endl;
    for (int i = 0; i < n; ++i) {
      cout << arr[i] << " ";
    }
    cout << endl;

    if (n%2 == 1) {  // if the size is an odd number
      double theMiddle = n/2;  // something like 1.5, if array size is 3
      // round that number up
      int getMiddle = static_cast<int>(theMiddle);
      median = arr[getMiddle];
      cout << "Median value: " << median << endl;
      return median;
    } else {  // if the size is an even number
        int start = (n/2)-1;
        unsigned stop = (n/2)+1;
        for (unsigned int i = start; i < stop; i++) {
        total += arr[i];
        }
        median = total/2;
        cout << "Median value: " << median << endl;
        return median;
    }
}

}  // namespace csce240
