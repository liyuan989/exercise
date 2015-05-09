/*
把字符串转换成整数
*/

#include <assert.h>
#include <stdint.h>
#include <stdio.h>

int stringToInt(const char* str)
{
    if (str == NULL)
    {
        return 0;
    }
    while (*str != '\0' && *str == ' ')
    {
        ++str;
    }
    if (*str == '\0')
    {
        return 0;
    }
    int sign = 1;
    if (*str == '-')
    {
        sign = -1;
        ++str;
    }
    else if (*str == '+')
    {
        ++str;
    }
    int64_t val = 0;
    while ('0' <= *str && *str <= '9')
    {
        val = 10 * val + (*str - '0') * sign;
        if (val > 0x7fffffff || val < -0x8000000)
        {
            return 0;
        }
        ++str;
    }
    return static_cast<int>(val);
}

int main(int argc, char* argv[])
{
    assert(stringToInt("0") == 0);
    assert(stringToInt(NULL) == 0);
    assert(stringToInt("a") == 0);
    assert(stringToInt("ad123") == 0);
    assert(stringToInt("  ds") == 0);
    assert(stringToInt("  ds 12") == 0);
    assert(stringToInt("-123") == -123);
    assert(stringToInt("1232") == 1232);
    assert(stringToInt("+123") == 123);
    assert(stringToInt("   245") == 245);
    assert(stringToInt("   -234") == -234);
    assert(stringToInt("  - 234") == 0);
    assert(stringToInt("   +234") == 234);
    assert(stringToInt("   + 456") == 0);
    assert(stringToInt("123\00043") == 123);
    assert(stringToInt("121111111111111111111111111") == 0);
    assert(stringToInt("-2323232323232323232323232323") == 0);
    printf("all test cas passed!\n");
    return 0;
}
