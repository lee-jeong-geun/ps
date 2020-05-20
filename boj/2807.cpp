#include <bits/stdc++.h>
using namespace std;
int N;
long long arr[5], result, Count[30][30];

/*
단어의 중간은 볼 필요 없이 첫 글자와 마지막 글자만 보면 된다.
첫 글자 26개 마지막 글자 26개 해서 [26][26] 테이블을 만들고 여기에 개수를 저장한다.
이제 정사각형을 찾아야 하는데 나올 수 있는 경우의 수는 26*26*26*26가 된다.
26^4번 돌면서 정사각형을 완성 시킨 다음 개수를 세면 된다.
*/

int main()
{
    scanf("%d", &N);
    int length = 0;
    for(int i = 0; i < N; i++)
    {
        char word[15];
        scanf("%s", word);
        if(length == 0)
            length = strlen(word);
        Count[word[0] - 'A'][word[length - 1] - 'A']++;
    }
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            for(int k = 0; k < 26; k++)
            {
                for(int l = 0; l < 26; l++)
                {
                    arr[0] = Count[i][j]--;
                    arr[1] = Count[i][k]--;
                    arr[2] = Count[j][l]--;
                    arr[3] = Count[k][l]--;
                    result += arr[0] * arr[1] * arr[2] * arr[3];
                    Count[k][l] = arr[3];
                    Count[j][l] = arr[2];
                    Count[i][k] = arr[1];
                    Count[i][j] = arr[0];
                }
            }
        }
    }
    printf("%lld", result);
}