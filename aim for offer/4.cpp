/*
请实现一个函数，把字符串中的每个空格替换成「%20」。
例如输入「We are happy.」，则输出「We%20are%20happy.」。
*/

#include <string.h>
#include <assert.h>
#include <stdio.h>

void replaceBlank(char* str, int length)
{
    if (str == NULL || length <= 0)
    {
        return;
    }
    int nblank = 0;
    int original_size = 0;
    for (char* p = str; *p != '\0'; ++p, ++original_size)
    {
        if (*p == ' ')
        {
            ++nblank;
        }
    }
    int size = original_size + nblank * 2 + 1;
    if (length < size)
    {
        return;
    }

    char* p_origin = str + original_size;
    char* p_end = str + size - 1;
    while (p_origin != p_end)
    {
        if (*p_origin == ' ')
        {
            --p_origin;
            *(p_end--) = '0';
            *(p_end--) = '2';
            *(p_end--) = '%';
        }
        else
        {
            *p_end = *p_origin;
            --p_origin;
            --p_end;
        }
    }
}

int main(int argc, char* argv[])
{
    {
        char str[100] = "We are happy.";
        replaceBlank(str, 100);
        assert(strcmp(str, "We%20are%20happy.") == 0);
        printf("%s\n", str);
    }

    {
        char str[100] = "We are happy.";
        replaceBlank(str, 0);
        assert(strcmp(str, "We are happy.") == 0);
        printf("%s\n", str);
    }

    {
        char str[100] = "We are happy.";
        replaceBlank(NULL, 100);
        assert(strcmp(str, "We are happy.") == 0);
        printf("%s\n", str);
    }

    {
        char str[] = "happy";
        replaceBlank(str, sizeof(str));
        assert(strcmp(str, "happy") == 0);
        printf("%s\n", str);
    }

    {
        char str[2] = " ";
        replaceBlank(str, 2);
        assert(strcmp(str, " ") == 0);
        printf("%s\n", str);
    }
    return 0;
}
