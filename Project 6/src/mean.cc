/* mean.cc Copyright 2019
 * Written by Diem Dao, CSCE 240
 */

#include <mean.h>

namespace csce240 {

  /* Stores data (datum) such than an average may be calculated.
   * - NOTE: You do not necessarily need to store each datum.
   */
  void Mean::Collect(double datum) {
    v_.push_back(datum);
    cout << "testing mean collect: " << endl;
    for (unsigned int i = 0; i < v_.size(); ++i)
      cout << v_[i] << " ";
  }

  /* Returns the mean of the data (datum) from the Collect method.
   */
  double Mean::Calculate() const {
    double total = 0.0;
    double mean = 0.0;
    unsigned int sizeV = v_.size();
    for (unsigned int i = 0; i < sizeV; ++i) {
      total += v_[i];
    }
    mean = total/sizeV;
    cout << "mean: " << mean << endl;

    return mean;
  }

}  // namespace csce240
