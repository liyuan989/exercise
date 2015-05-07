/*
题目一：

输入一个英文句子，翻转句子中单词的顺序，单单词内字符的顺序不变。
为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student."，
则输出"student. a am I"。
*/

#include <string.h>
#include <stdio.h>

void swap(char* a, char* b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverseMemory(char* start, char* end)
{
    --end;
    while (start < end)
    {
        swap(start, end);
        ++start;
        --end;
    }
}

void reverseSentence(char* str, int size)
{
    if (str == NULL || size <= 0)
    {
        return;
    }
    reverseMemory(str, str + size);
    char* start = str;
    while (*start == ' ')
    {
        ++start;
    }
    char* end = start;
    while (end < str + size)
    {
        while (*end != ' ' && end < str + size)
        {
            ++end;
        }
        reverseMemory(start, end);
        while (*end == ' ' && end < str + size)
        {
            ++end;
        }
        start = end;
    }
}

/*
问题二：

字符串的左旋转操作是把字符串前面的若干个字符转移到
字符串的尾部。请定义一个函数实现字符串的左旋转操作的功能。
比如输入字符串abcdefg和数字2，该函数将返回左旋转2位得到的
结果cdefgab。
*/

void leftRotateString(char* str, int n)
{
    if (str == NULL || *str == '\0' || n <= 0)
    {
        return;
    }
    int size = strlen(str);
    if (n > size)
    {
        return;
    }
    reverseMemory(str, str + size);
    reverseMemory(str, str + size - n);
    reverseMemory(str + size - n, str + size);
}

int main(int argc, char* argv[])
{
    char str1[] = "I am a student.";
    reverseSentence(str1, strlen(str1));
    printf("%s\n", str1);

    char str2[] = "abcdefg";
    leftRotateString(str2, 2);
    printf("%s\n", str2);
    return 0;
}
