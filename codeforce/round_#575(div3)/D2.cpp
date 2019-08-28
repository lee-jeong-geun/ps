#include <bits/stdc++.h>
using namespace std;
int N, K, chk[30], result, flag[5], Count[5];
char word[200005];

/*
규칙을 잘보면 RGBRGBRGB or GBRGBRGBR or BRGBRGBRG 이 3가지의 경우만 나타난다.
그리고 GBRG, BRGB는 RGB로 시작 했을때 RGBR에서 오른쪽을 이동한 값들이다.
이런 규칙을 이용하여 R, G, B로 시작한 경우를 나누고 각 경우에서 계속 오른쪽으로 이동하면서
몇번 바꿔야하는지 개수를 세면 된다. RGBRGBR에서 GBRGBRG로 오른쪽 한번 이동한 경우는
RGBRGBR의 첫번째 R이 교환하는 경우라면 GBRGBRG로 바꿨을때 교환 카운트를 1 감소 시키고
GBRGBRG에서 마지막 G가 교환하는 경우라면 교환 카운트를 1 증가 시킨다.
*/

int main()
{
    int q;
    scanf("%d", &q);
    chk['G' - 'A'] = 1;
    chk['B' - 'A'] = 2;
    for(int tc = 0; tc < q; tc++)
    {
        scanf("%d %d %s", &N, &K, word);
        for(int i = 0; i < 3; i++)
        {
            flag[i] = i;
            Count[i] = 0;
        }
        for(int i = 0; i < K; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                //교환해야 하는 경우라면 카운트 증가
                if(chk[word[i] - 'A'] != flag[j] % 3)
                    Count[j]++;
                //flag에는 몇번째 단어인지 저장
                flag[j]++;
            }
        }
        result = min(Count[0], min(Count[1], Count[2]));
        for(int i = K; i < N; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                //오른쪽으로 이동하기 전에 맨 앞의 단어를 교환하는 경우
                if(chk[word[i - K] - 'A'] != (flag[j] - K) % 3)
                    Count[j]--;
                //오른쪽으로 이동한 후 맨 뒤의 단어를 교환하는 경우
                if(chk[word[i] - 'A'] != flag[j] % 3)
                    Count[j]++;
                flag[j]++;
                result = min(result, Count[j]);
            }
        }
        printf("%d\n", result);
    }
}