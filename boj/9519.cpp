#include <bits/stdc++.h>
using namespace std;
int X, Count = 1, Length;
char word[1005];

/*
사이클을 찾아야 한다. 두 번째 문자가 다시 두 번째로 오는 경우가 사이클이므로 사이클 횟수를
구한 후 주어진 문자열을 사이클의 초기로 돌리면 된다.
*/

int main()
{
    scanf("%d %s", &X, word);
    Length = strlen(word);
    int start = 1;
    while(start != Length - 1)
    {
        Count++;
        if(start <= (Length - 1) / 2)
            start = (start - 1) * 2 + 2;
        else
            start = (Length - start - 1) * 2 + 1;            
    }
    X %= Count;
    string temp, ttemp;
    temp = word;
    for(int i = X; i < Count; i++)
    {
        int l, r;
        ttemp = "";
        l = 1;
        r = temp.size() - 1;
        while(l <= r)
        {
            ttemp += temp[r--];
            if(l <= r)
                ttemp += temp[l++];
        }
        temp = word[0] + ttemp;
    }
    for(int i = 0; i < temp.size(); i++)
    {
        printf("%c", temp[i]);
    }
}