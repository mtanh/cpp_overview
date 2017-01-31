#include "rational.h"

namespace Math
{
  Rational::Rational(const Numerator& n,
                     const Denominator &d)
    : numerator(n)
    , denominator(d)
  {
  }

  Rational::~Rational()
  {
  }
}


