#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char s[5005], Str[15];
int arr[5005], chk[10005];
int K;

/*
k번째 substring을 찾으면 된다.
모든 substring을 찾는것은 문자열이 최대 5000개나 되므로 시간이 많이 걸린다.
K가 5까지라서 답은 앞부분에 있다. 정렬 후 중복 확인을 하면서 substring 하나씩 카운트 하면서
답을 출력하면 된다. 중복 확인은 해시를 통해서 하였다.
*/

int Hash(char *str)
{
    long long hap = 37;
    int length;
    length = strlen(str);
    for(int i = 0; i < length; i++)
    {
        hap = (hap * 1234731 + str[i] - 'a') % 10001;
    }
    return hap;
}

bool comp(int t, int u)
{
    //문자가 같을 경우 뒤에 문자까지 생각해서 substring이 빠른쪽이 앞쪽으로 가도록 비교
    if(s[t] == s[u])
    {
        for(int i = 1; i < 5; i++)
        {
            if(s[t + i] == s[u + i])
            {
                continue;
            }
            return s[t + i] < s[u + i];
        }
    }
    return s[t] < s[u];
}

int main()
{
    int length;
    scanf("%s %d", s, &K);
    length = strlen(s);
    s[length] = 100;
    for(int i = 0; i < length; i++)
    {
        arr[i] = i;
    }
    sort(arr, arr + length, comp);
    int count = 0, sidx = 0;
    for(int i = 0; i < length; i++)
    {
        if(count == K)
        {
            printf("%s", Str);
            break;
        }
        //해당 substring이 문자열 범위인지 확인
        if(arr[i] + count < length)
        {
            Str[sidx++] = s[arr[i] + count];
            Str[sidx] = 0;
            //중복 확인
            if(chk[Hash(Str)] == 1)
            {
                K++;
            }
            chk[Hash(Str)] = 1;
            count++;
            i--;
        }
        //범위 밖이라면 다른 substring 시작 부분으로 이동
        else
        {
            K -= count;
            count = 0;
            sidx = 0;
        }
    }
}