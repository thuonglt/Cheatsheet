#include<bits/stdc++.h>

class fraction {

private:

    long long gcd(long long int a, long long int b)
    {
      if (b == 0)
        return a;
      return gcd(b, a % b);
    }
public:
    long long base;
    long long div;

    fraction() {
        base = 0;
        div = 1;
    }

    fraction(long long a) {
        base = a;
        div = 1;
    }

    fraction operator +(fraction a) {
        fraction c;
        c.div = this->div * a.div;
        c.base = this->div * a.base + this->base * a.div;
        long long g= gcd(c.div, c.base);
        c.div /= g;
        c.base /= g;
        return c;
    }

    fraction operator -(fraction a) {
        fraction c;
        c.div = this->div * a.div;
        c.base = this->base * a.div - this->div * a.base;
        long long g= gcd(c.div, c.base);
        c.div /= g;
        c.base /= g;
        return c;
    }

    fraction operator *(fraction a) {
        fraction c;
        c.div = this->div * a.div;
        c.base = this->base * a.base;
        long long g = gcd(c.div, c.base);
        c.div /= g;
        c.base /= g;
        return c;
    }

    fraction operator /(fraction a) {
        fraction c;
        c.div = this->div * a.base;
        c.base = this->base * a.div;
        long long g = gcd(c.div, c.base);
        c.div /= g;
        c.base /= g;
        return c;
    }

    bool operator == (fraction a) {
        return (this->div * a.base == this->base * a.div);
    }

    bool operator < (fraction a) {
        return (this->base * a.div < this->div * a.base) && this->base * a .base > 0;
    }

    bool operator > (fraction a) {
        return (this->base * a.div > this->div * a.base) && this->base * a .base > 0;
    }

    bool operator >= (fraction a) {
        return *this > a || *this == a;
    }

    bool operator <= (fraction a) {
        return *this < a || *this == a;
    }

};
