#include <cstdio>
#include <iostream>
using namespace std;
int n, idx;
char result[55];

/*
주어진 조건에 맞게 구현하면 된다.
*/

int main()
{
    int count = 0, next = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        char word;
        scanf(" %c", &word);
        count++;
        if(count == next)
        {
            result[idx++] = word;
            count = 0;
            next++;
        }
    }
    result[idx] = 0;
    printf("%s", result);
}