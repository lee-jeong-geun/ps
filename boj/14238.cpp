#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int Count[5], Slength, rflag, memo[4][4][51][51][51], idx;
char S[55], route[55], result[55];

/*
올바른 순열은 완전탐색을 이용하여 찾을 수 있다.
하지만 길이가 최대 50이므로 3 ^ 20을 가뿐히 넘으므로 완전탐색을 이용하면 안되고 메모이제이션을 해야 한다.
잘보면 전값이 f고 전전값이 ff고 A가 x개 남아있고 B가 y개 남아있고 C가 z개 남아있을때 해당 순열을 완성 못했으면 
이 순열은 절대 완성 못하는 순열이다. 따라서 배열에다 ff, f, x, y, z값을 이용하여 메모이제이션후 탐색하다
해당 값이 걸리면 더 확인 하지 않고 리턴해주면 된다.
*/

int func(int ff, int f, int A, int B, int C, int depth)
{
    //완성 시켰을 경우
    if(A == 0 && B == 0 && C == 0)
    {
        //결과 저장
        if(rflag == 0)
        {
            rflag = 1;
            for(int i = 0; i < depth; i++)
            {
                result[i] = route[i];
            }
            idx = depth;
        }
        return 1;
    }
    int &ret = memo[ff][f][A][B][C];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    //B가 남아있고 전 값이 B가 아닌 경우
    if(B != 0 && f != 2)
    {
        route[depth] = 'B';
        ret = func(f, 2, A, B - 1, C, depth + 1);
    }
    //C가 남아있고 전 값과 전전 값이 C가 아닌경우
    if(C != 0 && ff != 3 && f != 3)
    {
        route[depth] = 'C';
        ret = func(f, 3, A, B, C - 1, depth + 1);
    }
    //A가 남아있는 경우
    if(A != 0)
    {
        route[depth] = 'A';
        ret = func(f, 1, A - 1, B, C, depth + 1);
    }
    return ret;
}

int main()
{
    scanf("%s", S);
    Slength = strlen(S);
    for(int i = 0; i < Slength; i++)
    {
        Count[S[i] - 'A']++;
    }
    memset(memo, -1, sizeof memo);
    func(0, 0, Count[0], Count[1], Count[2], 0);
    if(rflag == 0)
    {
        printf("-1");
        return 0;
    }
    for(int i = 0; i < idx; i++)
    {
        printf("%c", result[i]);
    }
}