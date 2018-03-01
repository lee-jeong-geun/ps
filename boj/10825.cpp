#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int kor, eng, math;
    char name[15];
}Data;
Data Stu[100005];
int N;

/*
N이 100000개나 되므로 O(N^2) 정렬은 못쓰고 O(NlogN) 정렬을 써야한다.
정렬 조건은 국어점수 내림차순, 영어점수 오름차순, 수학점수 내림차순, 이름 오름차순이다.
*/

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


//정렬 조건
bool comp(Data t, Data u)
{
    //국어 점수 같으면
    if(t.kor == u.kor)
    {
        //영어 점수 같으면
        if(t.eng == u.eng)
        {
            //수학 점수 같으면
            if(t.math == u.math)
            {
                int temp = 0;
                temp = strcmp(t.name, u.name);
                //뒤에 문자가 더 큰 경우
                if(temp == -1)
                {
                    return 1;
                }
                return 0;
            }
            return t.math > u.math;
        }
        return t.eng < u.eng;
    }
    return t.kor > u.kor;
}

//퀵정렬
void sort(Data *arr, int left, int right)
{
    Data pivot;
    int leftidx, rightidx;
    leftidx = left;
    rightidx = right;
    pivot = arr[(left + right) / 2];
    while(leftidx <= rightidx)
    {
        while(comp(arr[leftidx], pivot))
        {
            leftidx++;
        }
        while(comp(pivot, arr[rightidx]))
        {
            rightidx--;
        }
        if(leftidx <= rightidx)
        {
            Data temp;
            temp = arr[leftidx];
            arr[leftidx] = arr[rightidx];
            arr[rightidx] = temp;
            leftidx++;
            rightidx--;
        }
    }
    if(left < rightidx)
    {
        sort(arr, left, rightidx);
    }
    if(leftidx < right)
    {
        sort(arr, leftidx, right);
    }
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%s %d %d %d", Stu[i].name, &Stu[i].kor, &Stu[i].eng, &Stu[i].math);
    }
    sort(Stu, 0, N - 1);
    for(int i = 0; i < N; i++)
    {
        printf("%s\n", Stu[i].name);
    }
}