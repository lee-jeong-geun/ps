#include <cstdio>
#include <iostream>
using namespace std;
char x[105], y[105];
int xchk[15], ychk[15], xlength, ylength, flag;
int modeA[2] = {1, -1};
int modeB[2] = {-1, 1};

void init()
{
    for(int i = 0; i < 11; i++)
    {
        xchk[i] = 0;
        ychk[i] = 0;
    }
}

int strlen(char *str)
{
    int len = 0;
    while(*str != 0)
    {
        len++;
        str++;
    }
    return len;
}

//디지털 친구인지 확인 함수
bool fchk()
{
    for(int i = 0; i < 10; i++)
    {
        if(xchk[i] == 0 && ychk[i] != 0 || xchk[i] != 0 && ychk[i] == 0)
        {
            return 0;
        }
    }
    return 1;
}

//해당 idx 와 idx + 1을 바꿔주는 함수
void change(char *str, int *tchk, int idx, int mode)
{
    //bef는 바꾸기 전 값 aft는 바꾼 후 값
    int bef1, bef2, aft1, aft2;
    //mode1은 idx를 -1 idx + 1을 +1 mode2는 mode1 반대
    if(mode == 1)
    {
        if(idx == 0 && str[0] == '1')
        {
            return;
        }
    }
    else
    {
        if(idx == 0 && str[0] == '9')
        {
            return;
        }
    }
    bef1 = str[idx] - '0';
    bef2 = str[idx + 1] - '0';
    //빼기 연산이 있어서 나머지 연산시 답이 틀리는걸 막기 위해서 10을 더해준다
    aft1 = (bef1 + modeA[mode] + 10) % 10;
    aft2 = (bef2 + modeB[mode] + 10) % 10;
    tchk[bef1]--;
    tchk[bef2]--;
    tchk[aft1]++;
    tchk[aft2]++;
    //디지털 친구인지 확인
    if(fchk() == 1)
    {
        flag = 1;
    }
    tchk[aft1]--;
    tchk[aft2]--;
    tchk[bef1]++;
    tchk[bef2]++;
}

int main()
{
    for(int testcase = 0; testcase < 3; testcase++)
    {
        flag = 0;
        init();
        scanf("%s %s", x, y);
        xlength = strlen(x);
        ylength = strlen(y);
        //char형 숫자를 int 값으로 바꿔준 후 해당 숫자의 카운트를 1씩 더해준다. 없으면 0 있으면 1 이상
        //xchk 와 ychk 배열들로 디지털 친구인지 아닌지 확인
        for(int i = 0; i < xlength; i++)
        {
            xchk[x[i] - '0']++;
        }
        for(int i = 0; i < ylength; i++)
        {
            ychk[y[i] - '0']++;
        }
        if(fchk() == 1)
        {
            printf("friends\n");
            continue;
        }
        for(int i = 0; i < xlength - 1; i++)
        {
            change(x, xchk, i, 0);
            change(x, xchk, i, 1);
        }
        for(int i = 0; i < ylength - 1; i++)
        {
            change(y, ychk, i, 0);
            change(y, ychk, i, 1);
        }
        if(flag == 1)
        {
            printf("almost friends\n");
            continue;
        }
        else
        {
            printf("nothing\n");
            continue;
        }
    }
}