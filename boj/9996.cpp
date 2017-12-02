#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int N, Plength;
char p[105], File[105];

int main()
{
    scanf("%d", &N);
    scanf("%s", p);
    Plength = strlen(p);
    for(int Filei = 0; Filei < N; Filei++)
    {
        int Flength, Fidx = 0, flag = 0;
        scanf("%s", File);
        Flength = strlen(File);
        for(int i = 0; i < Plength; i++)
        {
            if(p[i] == '*')
            {
                int temp;
                temp = Flength - (Plength - 1 - i);
                if(temp < Fidx)
                {
                    flag = 1;
                    break;
                }
                Fidx = temp;
            }
            else
            {
                if(p[i] != File[Fidx])
                {
                    flag = 1;
                    break;
                }
                Fidx++;
            }
        }
        if(flag == 1)
        {
            printf("NE\n");
        }
        else
        {
            printf("DA\n");
        }
    }
}