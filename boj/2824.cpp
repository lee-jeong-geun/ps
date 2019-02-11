#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
map<int, int> m;
long long result = 1;
int N, M, flag;

/*
A와 B의 최대 공약수는 소인수 분해를 했을때 겹치는 소수들의 곱이다.
따라서 N개의 수를 모두 소인수 분해를 해서 map에 저장 후 M개의 수를 소인수 분해 하면서
겹치는 소수들을 결과에 곱해주면 된다. 소인수 분해를 할 때 수가 너무 크므로 루트까지만 구해주면 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int num, Sqrt;
        scanf("%d", &num);
        Sqrt = sqrt(num);
        for(int j = 2; j <= Sqrt; j++)
        {
            //소수
            if(num % j == 0)
            {
                m[j]++;
                num /= j;
                j--;
            }
        }
        if(num != 1)
        {
            m[num]++;
        }
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++)
    {
        int num, Sqrt;
        scanf("%d", &num);
        Sqrt = sqrt(num);
        for(int j = 2; j <= Sqrt; j++)
        {
            //소수
            if(num % j == 0)
            {
                //해당 소수가 A에 존재
                if(m[j] > 0)
                {
                    m[j]--;
                    if(result * j >= 1000000000)
                    {
                        flag = 1;
                    }
                    //9자리만 출력 해야 하므로 9자리가 넘어가는 수들은 무의미
                    result = (result * j) % 1000000000;
                }
                num /= j;
                j--;
            }
        }
        if(num != 1 && m[num] > 0)
        {
            m[num]--;
            if(result * num >= 1000000000)
            {
                flag = 1;
            }
            result = (result * num) % 1000000000;
        }
    }
    //9자리가 넘어간 경우
    if(flag == 1)
    {
        printf("%09lld", result);
        return 0;
    }
    printf("%lld", result);
}