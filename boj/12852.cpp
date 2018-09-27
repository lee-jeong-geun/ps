#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int N, chk[1000005], tarr[105], result[105], idx = 987654321;

/*
문제에 주어진대로 연산을 하면 되는데 각 연산의 결과값을 만드는 최소 연산수를 배열에 저장한다.
*/

void func(int depth, int num)
{
    //현재 값의 연산수보다 더 작은 값이 있는경우
    if(chk[num] <= depth)
    {
        return;
    }
    //기저 사례
    if(num == 0 || idx < depth)
    {
        //1로 만들었을때 연산값이 더 작은경우
        if(idx > depth)
        {
            //출력 배열에 연산과정 저장
            for(int i = 0; i < depth; i++)
            {
                result[i] = tarr[i];
            }
            idx = depth;
        }
        return;
    }
    //현재 연산 횟수 저장
    chk[num] = depth;
    tarr[depth] = num;
    if(num % 3 == 0)
    {
        func(depth + 1, num / 3);
    }
    if(num % 2 == 0)
    {
        func(depth + 1, num / 2);
    }
    func(depth + 1, num - 1);
}

int main()
{
    memset(chk, 0x3f, sizeof chk);
    scanf("%d", &N);
    func(0, N);
    printf("%d\n", idx - 1);
    for(int i = 0; i < idx; i++)
    {
        printf("%d ", result[i]);
    }
}