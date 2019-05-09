/* statistic.h Copyright 2019
 * Written by Diem Dao, CSCE 240
 */

#ifndef _HW6_STATISTIC_H_  // NOLINT
#define _HW6_STATISTIC_H_  // NOLINT

#include <iostream>
using std::cout;
using std::endl;

namespace csce240 {
/* This is an abstract base class which Statistic classes extend.
 */
class Statistic {
 public:
  /* Not a pure virtual so that children may not override if unused
   */
  virtual ~Statistic() { /* Empty */ }

  /* Defined by children
   */
  virtual void Collect(double) = 0;

  /* Defined by children
   */
  virtual double Calculate() const = 0;
};

}  // namespace csce240


#endif  // NOLINT
