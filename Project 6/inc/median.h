/* median.h Copyright 2019
 * Written by Diem Dao, CSCE 240
 */

#ifndef _HW6_MEDIAN_H_  // NOLINT
#define _HW6_MEDIAN_H_  // NOLINT

#include <statistic.h>

#include <vector>
using std::vector;
#include <cmath>
#include <algorithm>
using std::sort;

namespace csce240 {

/* This class inherits from the Statistic class such that it  may be used
 * polymorphically.
 */
class Median : public Statistic {
 public:
  /* Stores data (datum) such than the median may be determined.
   */
  void Collect(double datum);

  /* Calculates the median of the data (datum) from the Collect method.
   */
  double Calculate() const;

 private:
  vector<double> v_;
};

}  // namespace csce240

#endif  // NOLINT