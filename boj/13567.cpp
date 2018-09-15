#include <cstdio>
#include <iostream>
using namespace std;
int M, n, sx, sy, dir = 1, result;
int arrA[4] = {0, 1, 0, -1};
int arrB[4] = {1, 0, -1, 0};

/*
주어진 조건에 맞게 구현하면 된다.
*/

int main()
{
    scanf("%d %d", &M, &n);
    for(int i = 0; i < n; i++)
    {
        char op[7];
        int d;
        scanf("%s %d", op, &d);
        if(op[0] == 'M')
        {
            sx += arrA[dir] * d;
            sy += arrB[dir] * d;
        }
        //방향 바꾸기
        else
        {
            if(d == 0)
                dir = (dir + 3) % 4;
            else
                dir = (dir + 1) % 4;
        }
        if(sx < 0 || sx > M || sy < 0 || sy > M)
        {
            result = -1;
        }
    }
    if(result == -1)
        printf("-1");
    else
        printf("%d %d", sx, sy);
}