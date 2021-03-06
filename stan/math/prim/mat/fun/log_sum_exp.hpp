#ifndef STAN_MATH_PRIM_MAT_FUN_LOG_SUM_EXP_HPP
#define STAN_MATH_PRIM_MAT_FUN_LOG_SUM_EXP_HPP

#include <stan/math/prim/scal/fun/log1p.hpp>
#include <stan/math/prim/mat/fun/Eigen.hpp>
#include <boost/math/tools/promotion.hpp>
#include <limits>
#include <vector>

namespace stan {
namespace math {

/**
 * Return the log of the sum of the exponentiated values of the specified
 * matrix of values.  The matrix may be a full matrix, a vector,
 * or a row vector.
 *
 * The function is defined as follows to prevent overflow in exponential
 * calculations.
 *
 * \f$\log \sum_{n=1}^N \exp(x_n) = \max(x) + \log \sum_{n=1}^N \exp(x_n -
 * \max(x))\f$.
 *
 * @param[in] x Matrix of specified values
 * @return The log of the sum of the exponentiated vector values.
 */
template <int R, int C>
double log_sum_exp(const Eigen::Matrix<double, R, C>& x) {
  using std::exp;
  using std::log;
  using std::numeric_limits;
  double max = -numeric_limits<double>::infinity();
  for (int i = 0; i < x.size(); i++)
    if (x(i) > max)
      max = x(i);

  double sum = 0.0;
  for (int i = 0; i < x.size(); i++)
    if (x(i) != -numeric_limits<double>::infinity())
      sum += exp(x(i) - max);

  return max + log(sum);
}

}  // namespace math
}  // namespace stan

#endif
