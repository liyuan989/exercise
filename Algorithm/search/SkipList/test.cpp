#include "SkipList.h"

#include <time.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    {
        printf("The SkipList one:\n");
        SkipList<int> list;
        for (int i = 0; i < 10; ++i)
        {
            list.insert(i);
        }
        list.print();
        printf("level: %zd\n", list.level());
        printf("size: %zd\n", list.size());
        SkipList<int>::iterator it = list.find(9);
        if (it != list.end())
        {
            printf("find out: %d\n", *it);
        }
        printf("iteration:\n");
        for (SkipList<int>::iterator iter = list.begin(); iter != list.end(); ++iter)
        {
            printf("%d ", *iter);
        }
        printf("\n");
    }
    printf("----------------------\n");
    {
        printf("The SkipList two:\n");
        SkipList<int> list;
        list.setInsertSrand(time(NULL));
        for (int i = 0; i < 10; ++i)
        {
            list.insert(i);
        }
        list.print();
        printf("level:%zd\n", list.level());
        printf("size:%zd\n", list.size());
        SkipList<int>::iterator it = list.find(9);
        if (it != list.end())
        {
            printf("find out:%d\n", *it);
        }
        printf("iteration:\n");
        for (SkipList<int>::iterator iter = list.begin(); iter != list.end(); ++iter)
        {
            printf("%d ", *iter);
        }
        printf("\n");
    }
    return 0;
}
