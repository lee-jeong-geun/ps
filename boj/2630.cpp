#include <cstdio>
#include <iostream>
using namespace std;
int N, zone[135][135], Count[5];

void func(int startx, int endx, int starty, int endy)
{
    int temp, flag = 0;
    temp = zone[starty][startx];
    for(int i = starty; i <= endy; i++)
    {
        for(int j = startx; j <= endx; j++)
        {
            if(temp != zone[i][j])
            {
                flag = 1;
                break;
            }
        }
    }
    if(flag == 1)
    {
        int midx, midy;
        midx = (startx + endx) / 2;
        midy = (starty + endy) / 2;
        func(startx, midx, starty, midy);
        func(midx + 1, endx, starty, midy);
        func(startx, midx, midy + 1, endy);
        func(midx + 1, endx, midy + 1, endy);
    }
    else
    {
        Count[temp]++;
    }
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &zone[i][j]);
        }
    }
    func(0, N - 1, 0, N - 1);
    printf("%d\n%d", Count[0], Count[1]);
}