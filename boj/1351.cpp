#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
map<long long, long long> m;
long long N, P, Q;

/*
입력되는 수가 너무 커서 dp테이블을 배열로 잡을수 없다.
따라서 배열 대신 map에다 저장하면 된다.
*/

long long func(long long Num)
{
    if(m[Num] != 0)
    {
        return m[Num];
    }
    return m[Num] = func(Num / P) + func(Num / Q);
}

int main()
{
    scanf("%lld %lld %lld", &N, &P, &Q);
    m[1] = 2;
    m[0] = 1;
    printf("%lld", func(N));
}