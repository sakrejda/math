#ifndef STAN_MATH_PRIM_ARR_FUN_COMMON_TYPE_HPP
#define STAN_MATH_PRIM_ARR_FUN_COMMON_TYPE_HPP

#include <stan/math/prim/scal/fun/common_type.hpp>
#include <boost/math/tools/promotion.hpp>
#include <vector>

namespace stan {
  namespace math {
    /**
     * Struct which calculates wider type given two types.
     *
     * <p>This specialization is for vector types.
     *
     * @tparam T1 element type of std::vector<T1>
     * @tparam T2 element type of std::vector<T2>
     */
    template <typename T1, typename T2>
    struct common_type<std::vector<T1>, std::vector<T2> > {
      typedef std::vector<typename common_type<T1, T2>::type> type;
    };

  }
}

#endif
