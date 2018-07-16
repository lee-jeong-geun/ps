#include <cstdio>
#include <iostream>
using namespace std;
int K, N, result, Count;
unsigned int A[5000015];

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        A[0] = 1983;
        A[1] = A[0] * 214013 + 2531011;
        A[0] = 1984;
        Count = 0;
        result = 0;
        scanf("%d %d", &K, &N);
        int l, r, hap = 0;
        l = -1;
        r = 0;
        hap = A[0];
        while(Count <= N)
        {
            if(hap < K)
            {
                Count++;
                r = (r + 1) % 5000003;
                A[(r + 1) % 5000003] = A[r] * 214013 + 2531011;
                A[r] = A[r] % 10000 + 1;
                hap += A[r];
            }
            else
            {
                if(hap == K)
                {
                    result++;
                }
                l = (l + 1) % 5000003;
                hap -= A[l];
            }
        }
        printf("%d\n", result);
    }
}