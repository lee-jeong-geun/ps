#include <bits/stdc++.h>
using namespace std;
int N, K, angle[365];

/*
주어진 각도기를 이용하여 만들 수 있는 모든 각을 다 만들고
abs(0~360 - 외친각)이 존재하는지 찾으면 된다.
*/

int main()
{
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
    {
        int num, chk[365] = {0}, temp;
        scanf("%d", &num);
        temp = num;
        while(chk[temp] == 0)
        {
            chk[temp] = 1;
            angle[temp] = 1;
            temp = (temp + num) % 360;
        }
    }
    for(int i = 0; i < K; i++)
    {
        int num, flag = 0;
        scanf("%d", &num);
        for(int j = 0; j < 360; j++)
        {
            if(angle[j] == 0)
                continue;
            if(angle[abs(j - num)] == 1)
                flag = 1;
        }
        if(flag == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
}