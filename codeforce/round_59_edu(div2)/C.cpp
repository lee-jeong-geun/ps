#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, k, Num[200005], sortNum[200005];
char op[200005];
long long result;

/*
같은 알파벳은 연속 K번 까지만 눌러야 한다.
따라서 같은 알파벳이 연속인 것들을 한번에 모아서 정렬 후 큰 수 부터 K개를 결과에 더하면 된다.
*/

int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &Num[i]);
    }
    for(int i = 0; i < n; i++)
    {
        scanf(" %c", &op[i]);
    }
    for(int i = 0; i < n; i++)
    {
        int count = 0;
        long long hap = 0;
        for(int j = i; j < n; j++)
        {
            sortNum[count++] = Num[j];
            hap += Num[j];
            //알파벳이 다를 경우
            if(op[j] != op[j + 1])
            {
                //같은 알파벳이 k개가 넘는 경우
                if(count > k)
                {
                    sort(sortNum, sortNum + count);
                    hap = 0;
                    //큰 수 부터 k개를 결과에 더함
                    for(int l = count - 1; l >= count - k; l--)
                    {
                        hap += sortNum[l];
                    }
                }
                result += hap;
                i = j;
                break;
            }
        }
    }
    printf("%lld", result);
}