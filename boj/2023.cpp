#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int N;

/*
각각의 자리를 나눠서 해당 수가 소수인지를 판단 하면 된다.
소수를 판단할 때는 2부터 그 수까지 하면 너무 느리기 때문에
그 수의 루트 값을 구하고 그 루트 값 까지 판단 하면 된다.
*/

//소수 판별
int primechk(int a)
{
    int sqr;
    sqr = sqrt(a);
    for(int i = 2; i <= sqr; i++)
    {
        if(a % i == 0)
        {
            return 1;
        }
    }
    return 0;
}

void func(int depth, int hap)
{
    //N자리 만큼 구하면 출력후 리턴
    if(depth == N)
    {
        printf("%d\n", hap);
        return;
    }
    for(int i = 1; i <= 9; i++)
    {
        //1자리 일때 1은 소수가 아니므로 패스
        if(depth == 0 && i == 1)
        {
            continue;
        }
        int prime;
        prime = hap;
        prime *= 10;
        prime += i;
        if(primechk(prime) == 0)
        {
            func(depth + 1, prime);
        }
    }
}

int main()
{
    scanf("%d", &N);
    func(0, 0);
}