#include <bits/stdc++.h>
using namespace std;
int N, chk[30], result;

/*
문자의 존재 여부만 파악하면 되기 때문에 문자를 비트로 표현하고
완전탐색을 돌면서 비트값이 (1 << 26) - 1 되는지 확인하면 된다.
*/

void func(int depth, int state)
{
    if(depth == N)
    {
        if(state == (1 << 26) - 1)
            result++;
        return;
    }
    func(depth + 1, state | chk[depth]);
    func(depth + 1, state);
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        for(int j = 0; j < word.size(); j++)
        {
            chk[i] |= (1 << (word[j] - 'a'));
        }
    }
    func(0, 0);
    printf("%d", result);
}