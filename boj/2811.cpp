#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, Num[100005], chk[100005], Max, MaxArr[100005], MaxIdx, result;

/*
처음에 최장 우울 기간을 잡지 않고 우울 기간들만 찾은 다음 그 기간들의 2배의 길이를
chk배열에 1로 표시한다. 그다음 최장 우울 기간 후보들을 3배 길이로 했을때 chk배열에 0인 부분들의
최대개수를 찾으면 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &Num[i]);
    }
    int count = 0, idx = 987654321;
    for(int i = 0; i <= N; i++)
    {
        //음수인 경우 개수 늘려줌
        if(Num[i] < 0)
        {
            count++;
            idx = min(idx, i);
        }
        //양수이고 개수가 1이상인 경우
        else if(Num[i] >= 0 && count > 0)
        {
            //개수의 2배를 chk배열에 1로 표시
            for(int j = idx - 1; j >= max(0, idx - count * 2); j--)
            {
                chk[j] = 1;
            }
            //개수가 최대인 경우
            if(Max < count)
            {
                MaxIdx = 0;
                Max = count;
                MaxArr[MaxIdx++] = idx;
            }
            //최대 후보들
            else if(Max == count)
            {
                MaxArr[MaxIdx++] = idx;
            }
            count = 0;
            idx = 987654321;
        }
    }
    int MaxCount = 0;
    count = 0;
    for(int i = 0; i < MaxIdx; i++)
    {
        //3배로 했을때 0의 최대 개수
        for(int j = MaxArr[i] - Max * 2; j >= max(0, MaxArr[i] - Max * 3); j--)
        {
            if(chk[j] == 0)
            {
                count++;
            }
        }
        MaxCount = max(MaxCount, count);
        count = 0;
    }
    for(int i = 0; i < N; i++)
    {
        if(chk[i] == 1)
        {
            result++;
        }
    }
    printf("%d", result + MaxCount);
}