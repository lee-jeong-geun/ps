#include <cstdio>
#include <iostream>
using namespace std;
int N, Tree[100005], Segment[100005], GCD, result;

/*
가로수의 구간들을 구해서 그 구간들의 최대공약수를 구하고 최대공약수로 각 구간들의 값을 나눈후
-1 해준걸 다 더했다.
*/

//최대공약수 구하는 함수
int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    gcd(b, a % b);
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &Tree[i]);
        if(i != 0)
        {
            //구간들을 구함
            Segment[i - 1] = Tree[i] - Tree[i - 1];
        }
    }
    GCD = gcd(Segment[0], Segment[1]);
    for(int i = 2; i < N - 1; i++)
    {
        //구간들의 최대공약수를 구함
        GCD = gcd(GCD, Segment[i]);
    }
    for(int i = 0; i < N - 1; i++)
    {
        result += (Segment[i] / GCD) - 1;
    }
    printf("%d", result);
}