#include <cstdio>
#include <iostream>
using namespace std;
int N, chk[1005], result, Num[5] = {1, 5, 10, 50};

/*
어떤 수를 만드는것에 있어서 순서가 상관없으므로 순서를 강제 하면서 완전탐색을 돌면 된다.
예) IVI = IIV
*/

void func(int depth, int idx,int count)
{
    if(depth == N)
    {
        //처음 등장하는 수
        if(chk[count] == 0)
        {
            chk[count] = 1;
            result++;
        }
        return;
    }
    //순서를 강제
    for(int i = idx; i < 4; i++)
    {
        func(depth + 1, i, count + Num[i]);
    }
    return;
}

int main()
{
    scanf("%d", &N);
    func(0, 0, 0);
    printf("%d", result);
}