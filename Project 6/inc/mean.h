/* mean.h Copyright 2019
 * Written by Diem Dao, CSCE 240
 */

#ifndef _HW6_MEAN_H_  // NOLINT
#define _HW6_MEAN_H_  // NOLINT

#include <statistic.h>

#include <vector>
using std::vector;
#include <cmath>

namespace csce240 {

/* This class inherits from the Statistic class such that it may be used
 * polymorphically.
 */
class Mean : public Statistic {
 public:
  /* Stores data (datum) such than an average may be calculated.
   * - NOTE: You do not necessarily need to store each datum.
   */
  void Collect(double datum);

  /* Returns the mean of the data (datum) from the Collect method.
   */
  double Calculate() const;

 private:
    vector<double> v_;
};

}  // namespace csce240

#endif  // NOLINT