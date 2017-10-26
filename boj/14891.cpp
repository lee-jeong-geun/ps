#include <cstdio>
#include <iostream>
using namespace std;
int K, Num, Turn, chain[5][15], turnchk[5], result;

void turn(int n, int flag)
{
    int temp[15], change;
    change = (8 + flag) % 8;
    for(int i = 0; i < 8; i++)
    {
        temp[(i + change) % 8] = chain[n][i];
    }
    for(int i = 0; i < 8; i++)
    {
        chain[n][i] = temp[i];
    }
}

void func()
{
    int left, right;
    right = Num;
    left = Num;
    turnchk[Num] = Turn;
    while(right != 3)
    {
        if(chain[right][2] != chain[right + 1][6])
        {
            turnchk[right + 1] = turnchk[right] * -1;
            right++;
        }
        else
        {
            break;
        }
    }
    while(left != 0)
    {
        if(chain[left][6] != chain[left - 1][2])
        {
            turnchk[left - 1] = turnchk[left] * -1;
            left--;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            scanf("%1d", &chain[i][j]);
        }
    }
    scanf("%d", &K);
    for(int i = 0; i < K; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            turnchk[j] = 0;
        }
        scanf("%d %d", &Num, &Turn);
        Num--;
        func();
        for(int j = 0; j < 4; j++)
        {
            if(turnchk[j] != 0)
            {
                turn(j, turnchk[j]);
            }
        }
    }
    for(int i = 0; i < 4; i++)
    {
        if(chain[i][0] == 1)
        {
            result += (1 << i);
        }
    }
    printf("%d", result);
}