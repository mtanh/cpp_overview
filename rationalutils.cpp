#include "rationalutils.h"

namespace Math
{
  const Rational operator*(const Rational& lhs,
                           const Rational& rhs)
  {
    return Rational(Numerator(lhs.getNumerator().numerator*rhs.getNumerator().numerator),
                    Denominator(lhs.getDenominator().denominator*rhs.getDenominator().denominator));
  }
}
