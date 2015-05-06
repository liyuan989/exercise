/*
在字符串中找出第一个只出现一次的字符。如输入
abaccdeff，则输出b。
*/

#include <string.h>
#include <stdio.h>

char getFirstOneChar(char* str)
{
    if (str == NULL || *str == '\0')
    {
        return '\0';
    }
    int array[256];
    memset(array, 0, sizeof(array));
    int len = strlen(str);
    for (int i = 0; i < len; ++i)
    {
        ++array[str[i] - '0'];
    }
    for (int i = 0; i < len; ++i)
    {
        if (array[str[i] - '0'] == 1)
        {
            return str[i];
        }
    }
    return '\0';
}

int main(int argc, char* argv[])
{
    char str[] = "abaccdeff";
    printf("%c\n", getFirstOneChar(str));
    return 0;
}
