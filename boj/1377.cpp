#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int num;
    int idx;
}Data;
Data Number[500005];
int N, result;

/*
문제에서 나온 소스 그대로 제출하면 시간초과다. 버블 정렬은 N^2 시간복잡도를 가지는데 N은 500000이기
때문에 버블정렬 말고 NlogN 시간복잡도를 가진 퀵정렬을 이용하였다.
이 문제는 정렬을 몇번 하였는지 카운트 하는 문제다.
정렬을 한번 하면 작은 수는 왼쪽으로 한칸 이동하는 반면 큰수는 정렬을 완료할때까지 오른쪽으로 이동한다.
그래서 왼쪽으로 이동한 값의 최댓값을 찾고 출력을 해주었다.
단 중복된값들이 나오기 때문에 stable하게 정렬을 해야한다.
unstable하게 정렬을 해서 순서가 뒤엉켜 버린다면 결과값이 달라지기 때문이다.
따라서 퀵소트에 comp함수를 만들어서 중복된 값끼리 정렬할 경우 input 순서가 작은것이 앞으로
가게끔 해주었다.
*/

int max(int a, int b)
{
    return a > b ? a : b;
}

bool comp(Data t, Data u)
{
    //값이 같을시 input순서로 오름차순
    if(t.num == u.num)
    {
        return t.idx < u.idx;
    }
    return t.num < u.num;
}

//퀵정렬
void sort(int left, int right)
{
    int leftidx, rightidx;
    Data pivot;
    pivot = Number[(left + right) / 2];
    leftidx = left;
    rightidx = right;
    while(leftidx <= rightidx)
    {
        while(comp(Number[leftidx], pivot))
        {
            leftidx++;
        }
        while(comp(pivot, Number[rightidx]))
        {
            rightidx--;
        }
        if(leftidx <= rightidx)
        {
            Data temp;
            temp = Number[leftidx];
            Number[leftidx] = Number[rightidx];
            Number[rightidx] = temp;
            leftidx++;
            rightidx--;
        }
    }
    if(leftidx < right)
    {
        sort(leftidx, right);
    }
    if(left < rightidx)
    {
        sort(left, rightidx);
    }
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int n;
        scanf("%d", &n);
        Number[i].num = n;
        Number[i].idx = i;
    }
    sort(0, N - 1);
    for(int i = 0 ; i < N; i++)
    {
        //기존의 idx값과 정렬후 idx값의 차이의 최댓값 갱신
        result = max(result, Number[i].idx - i);
    }
    //문제는 1부터 시작이라 + 1을 해줌
    printf("%d", result + 1);
}