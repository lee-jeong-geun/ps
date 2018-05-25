#include <cstdio>
#include <iostream>
using namespace std;
int N, A, B, chk[15], flag;

/*
A에 해당하는 수들을 for문으로 처음 부터 끝까지 탐색하는 O(N)의 방법으로는 시간초과가 난다.
따라서 0부터 9까지의 수들의 순열을 만들어서 B에 해당하는 수를 구하면 된다.
*/

//B가 만들어 질수 있는지 확인
bool chknum(int num)
{
    int temp, rflag = 0, count = 0;
    temp = num;
    while(temp != 0)
    {
        if(chk[temp % 10] == 1)
        {
            rflag = 1;
            break;
        }
        chk[temp % 10] = 1;
        temp /= 10;
        count++;
    }
    while(rflag == 1 && num != 0)
    {
        if(count == 0)
        {
            break;
        }
        chk[num % 10] = 0;
        num /= 10;
        count--;
    }
    return !rflag;
}

//순열 만드는 재귀 함수
void func(int depth, int num)
{
    if(depth == 9 || flag == 1 || num >= N)
    {
        return;
    }
    if(chknum(N - num) == 1)
    {
        flag = 1;
        A = num;
        B = N - num;
        return;
    }
    for(int i = 0; i < 10; i++)
    {
        if(chk[i] == 0)
        {
            chk[i] = 1;
            func(depth + 1, num * 10 + i);
            chk[i] = 0;
        }
    }
}

int main()
{
    scanf("%d", &N);
    for(int i = 1; i < 10; i++)
    {
        chk[i] = 1;
        func(0, i);
        chk[i] = 0;
    }
    if(B == 0)
    {
        printf("-1");
    }
    else
    {
        printf("%d + %d", A, B);
    }
}