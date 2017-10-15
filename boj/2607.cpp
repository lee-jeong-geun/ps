#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, Alength, Blength, Achk[30], Bchk[30], result;
char StrA[15], StrB[15];

void Bcount()
{
    memset(Bchk, 0, sizeof Bchk);
    for(int i = 0; i < Blength; i++)
    {
        Bchk[StrB[i] - 'A']++;
    }
}

int allchk()
{
    for(int i = 0; i < 26; i++)
    {
        if(Achk[i] != Bchk[i])
        {
            return 0;
        }
    }
    return 1;
}

int partchk()
{
    int count = 0, partcount = 0;
    for(int i = 0; i < 26; i++)
    {
        if(Achk[i] != Bchk[i])
        {
            count++;
            partcount = max(Achk[i], Bchk[i]) - min(Achk[i], Bchk[i]);
        }
    }
    if(count == 1 && partcount == 1)
    {
        return 1;
    }
    return 0;
}

int changechk()
{
    int count = 0, hap = 0;
    for(int i = 0; i < 26; i++)
    {
        if(Achk[i] != Bchk[i])
        {
            count++;
            hap += max(Achk[i], Bchk[i]) - min(Achk[i], Bchk[i]);
        }
    }
    if(count == 2 && hap == 2 && Alength == Blength)
    {
        return 1;
    }
    return 0;
}

int main()
{
    scanf("%d %s", &N, StrA);
    Alength = strlen(StrA);
    for(int i = 0; i < Alength; i++)
    {
        Achk[StrA[i] - 'A']++;
    }
    for(int i = 0; i < N - 1; i++)
    {
        scanf("%s", StrB);
        Blength = strlen(StrB);
        Bcount();
        if(allchk() == 1 || part
        chk() == 1 || changechk() == 1)
        {
            result++;
        }
    }
    printf("%d", result);
}