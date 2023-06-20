#include "MathFunctions.h"
#include <iostream>
#include <cmath>

#ifdef USE_MYMATH
#include "mysqrt.h"
#endif


namespace mathfunctions {
double sqrt(double x)
{
#ifdef USE_MYMATH
  std::cout << "USE_MYMATH" << std::endl;
  return detail::mysqrt(x);
#else
  std::cout << "NOT USE_MYMATH" << std::endl;
  return std::sqrt(x);
#endif
}
}
