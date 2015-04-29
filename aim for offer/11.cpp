/*
实现函数double power(double base, int exponent)，求base
的exponent次方。不得使用库函数，同时不需要考虑大数问题。
*/

#include <stdexcept>
#include <stdio.h>
#include <assert.h>

bool equalZero(double base)
{
    if (-0.00000001 < base && base < 0.00000001)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double doPowerWithUnsigedExponent(double base, unsigned int exponent)
{
    double result = base;
    for (unsigned int i = 1; i < exponent; ++i)
    {
        result *= base;
    }
    return result;
}

double doPowerWithUnsignedExponentEfficient(double base, unsigned int exponent)
{
    if (exponent == 1)
    {
        return base;
    }

    double val = doPowerWithUnsignedExponentEfficient(base, exponent >> 1);
    double result = val * val;
    if (exponent & 1)
    {
        result *= val;
    }
    return result;
}

double power(double base, int exponent)
{
    if (base == 0)
    {
        return 0.0;
    }

    if (exponent == 0)
    {
        return 1.0;
    }
    else if (exponent > 0)
    {
        return doPowerWithUnsignedExponentEfficient(base, static_cast<unsigned int>(exponent));
    }
    else
    {
        if (equalZero(base))
        {
            throw std::logic_error("Ivalid input");
        }
        unsigned int uexponent = static_cast<unsigned int>(-exponent);
        return 1 / doPowerWithUnsignedExponentEfficient(base, uexponent);
    }
}

int main(int argc, char* argv[])
{
    double base[4] = {10.0, 0.0, -10.0, 0.0000000001};
    int exponent[3] = {2, 0, -2};

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            try
            {
                printf("%f\n", power(base[i], exponent[j]));
            }
            catch(const std::logic_error& e)
            {
                printf("catch a except: %s\n", e.what());
            }
        }
    }
    return 0;
}
