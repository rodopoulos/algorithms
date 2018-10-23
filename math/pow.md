# Insights and Precautions with Exponentiation

Quite often, we need to use the mathematical function power. It takes two arguments, a base $a$ and an exponent $e$, and it must returns the power of base $b$ rased to the power of exponent $e$, i.e., $b^e$.

In C language, you can include the `math.h` header and it should give to you the `pow` function. Here is its prototype:

```c
double pow (double base, double exponent);
```

Well, if you are not working with floating points numbers and know the hassles to work with them, the `double` type definition should caused an itchiness in you ear. As a remark, here are the overloaded prototype for `pow` function in C++ `math` library.

```c++
double pow (double base, double exponent);
float pow (float base, float exponent);
long double pow (long double base, long double exponent);
double pow (Type1 base, Type2 exponent);
```

Note that if 