#include <cstdio>
#include <iostream>
using namespace std;
char Word[20005][55];
int N;

/*
N이 20000개나 되므로 O(N^2)정렬을 사용하지 못한다.
O(NlogN)정렬인 퀵정렬을 이용하여 각 단어의 길이를 오름차순으로, 길이가 같으면 사전순으로 정렬을 
하였다.
*/

int strlen(char *str)
{
    int len = 0;
    while(*str != 0)
    {
        len++;
        str++;
    }
    return len;
}

int strcmp(char *str1, char *str2)
{
    while(*str1 != 0 || *str2 != 0)
    {
        if(*str1 > *str2)
        {
            return 1;
        }
        else if(*str1 < *str2)
        {
            return -1;
        }
        str1++;
        str2++;
    }
    return 0;
}

void strcpy(char *str1, char *str2)
{
    while(*str2 != 0)
    {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = 0;
}

//정렬 조건
bool comp(char *str1, char *str2)
{
    int len1, len2;
    len1 = strlen(str1);
    len2 = strlen(str2);
    //길이가 같으면
    if(len1 == len2)
    {
        int temp;
        temp = strcmp(str1, str2);
        //사전순 정렬
        if(temp == 1 || temp == 0)
        {
            return 0;
        }
        return 1;
    }
    return len1 < len2;
}

//퀵 정렬
void sort(char word[][55], int left, int right)
{
    char pivot[55];
    int leftidx, rightidx;
    leftidx = left;
    rightidx = right;
    strcpy(pivot, word[(left + right) / 2]);
    while(leftidx <= rightidx)
    {
        while(comp(word[leftidx], pivot))
        {
            leftidx++;
        }
        while(comp(pivot, word[rightidx]))
        {
            rightidx--;
        }
        if(leftidx <= rightidx)
        {
            char temp[55];
            strcpy(temp, word[leftidx]);
            strcpy(word[leftidx], word[rightidx]);
            strcpy(word[rightidx], temp);
            leftidx++;
            rightidx--;
        }
    }
    if(left < rightidx)
    {
        sort(word, left, rightidx);
    }
    if(leftidx < right)
    {
        sort(word, leftidx, right);
    }
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%s", Word[i]);
    }
    sort(Word, 0, N - 1);
    for(int i = 0; i < N; i++)
    {
        if(i != 0 && strcmp(Word[i], Word[i - 1]) == 0)
        {
            continue;
        }
        printf("%s\n", Word[i]);
    }
}