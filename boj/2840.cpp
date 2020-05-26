#include <bits/stdc++.h>
using namespace std;
int N, K, Cur, chk[30], flag;
char result[30];

/*
조건에 맞게 구현하면 된다.
예외 체크를 잘 해야 한다.
*/

int main()
{
    scanf("%d %d", &N, &K);
    memset(chk, -1, sizeof chk);
    for(int i = 0; i < K; i++)
    {
        int num;
        char word;
        scanf("%d %c", &num, &word);
        Cur = (Cur + num) % N;
        //처음 나온 글자거나 이미 나왔지만 같은 위치인 경우
        if(result[Cur] == 0 && chk[word - 'A'] == -1 || chk[word - 'A'] == Cur)
        {
            chk[word - 'A'] = Cur;
            result[Cur] = word;
        }
        else
        {
            chk[word - 'A'] = 987654321;
            flag = 1;
        }
    }
    if(flag == 1)
    {
        printf("!");
        return 0;
    }
    for(int i = 0; i < N; i++)
    {
        if(result[Cur] == 0)
            printf("?");
        else
            printf("%c", result[Cur]);
        Cur = (Cur + N - 1) % N;
    }
}