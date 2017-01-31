#ifndef RATIONAL_H
#define RATIONAL_H

namespace Math
{
  typedef struct Numerator
  {
    int numerator;

    explicit Numerator(int _numerator)
      : numerator(_numerator)
    {
    }
  } Numerator;

  typedef struct Denominator
  {
    int denominator;

    explicit Denominator(int _denominator)
      : denominator(_denominator)
    {
    }
  } Denominator;

  class Rational
  {
  public:
    explicit Rational(const Numerator& n,
                      const Denominator &d);
    ~Rational();

    Numerator getNumerator() const { return numerator; }
    Denominator getDenominator() const { return denominator; }

  private:
    Numerator numerator;
    Denominator denominator;
  };
}

#endif // RATIONAL_H
