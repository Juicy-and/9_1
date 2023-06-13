#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

	void cut_frac(int& numerator_, int& denominator_) {
		int num = 0;
		if (numerator_ < 0)
		{
			numerator_ *= -1;
			num++;
		}
		int nod = NOD(numerator_, denominator_);

		numerator_ /= nod;
		denominator_ /= nod;
		if (num) numerator_ *= -1;
	}
	int NOD(int numerator_, int denominator_) {
		while (numerator_ > 0 && denominator_ > 0) {
			if (numerator_ > denominator_) {
				numerator_ %= denominator_;
			}
			else {
				denominator_ %= numerator_;
			}
		}

		return numerator_ + denominator_;
	}
public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
		cut_frac(numerator_, denominator_);
	}
	double Abs() { return std::sqrt(numerator_ * numerator_ + denominator_ * denominator_); }
	bool operator==(Fraction other) { return Abs() == other.Abs(); }
	bool operator!=(Fraction other) { return !(*this == other); }
	bool operator<(Fraction other) { return other > *this; }
	bool operator>(Fraction other) { return other.Abs() > Abs(); }
	bool operator<=(Fraction other) { return !(*this > other); }
	bool operator>=(Fraction other) { return !(*this < other); }
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(8, 6);
	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}
