#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, K, Sum[2][2005][2005], alph[30], result;

/*
모든 점을 배열에 다 표현 할 수 없고 또 개수는 10만개라서 규칙을 찾아야 한다.
잘 보면 어떤 점으로 K칸을 고정 시켰을때 K칸 마다 흑과 백이 바뀐다.
즉 K칸에는 흑이라 가정할때 0 ~ K - 1까지는 흑 K ~ 2K - 1까지는 백 또 2K ~ 3K - 1 까지는 흑
이런 규칙이 있기 때문에 우리는 모든 점들을 2K X 2K로 압축 할 수 있다.
압축 후 점들을 일일이 셀수 없기 때문에 부분합을 이용하여 점들의 개수를 빠르게 세어야 한다.
이제 남은것은 고정된 점을 옮기는 것이다. (0,0)에서 흑의 모퉁이로 고정 했다면 이제 (0,1), (0,2)
(1,0), (1,1) 이런식으로 고정된 점을 옮겨서 개수를 세어야 한다.
(흑, 백)    이렇게 시작 했을때 
(백, 흑)

(백, 흑)    이 상태는 위의 상태에서 백과 흑만 바꿨기 때문에 금방 셀 수 있다.
(흑, 백)
*/

int main()
{
    alph['B' - 'A'] = 0;
    alph['W' - 'A'] = 1;
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
    {
        int x, y;
        char c;
        scanf("%d %d %c", &x, &y, &c);
        //좌표 압축
        x = x % (2 * K) + 1;
        y = y % (2 * K) + 1;
        //부분합
        Sum[alph[c - 'A']][y][x]++;
    }
    //모든 배열에 대하여 부분합
    for(int i = 1; i <= 2 * K; i++)
    {
        for(int j = 1; j <= 2 * K; j++)
        {
            for(int k = 0; k < 2; k++)
            {
                Sum[k][i][j] += Sum[k][i - 1][j] + Sum[k][i][j - 1] - Sum[k][i - 1][j - 1];
            }
        }
    }
    //K X K만 돌면 됨
    for(int i = 0; i < K; i++)
    {
        for(int j = 0; j < K; j++)
        {
            //규칙들
            int blackHap = 0, whiteHap = 0, blackHap2 = 0, whiteHap2 = 0;
            blackHap = Sum[0][2 * K - i][2 * K - j] + Sum[0][K - i][K - j] * 2;
            blackHap = blackHap - Sum[0][K - i][2 * K - j] - Sum[0][2 * K - i][K - j];
            blackHap += Sum[0][K - i][2 * K] - Sum[0][K - i][2 * K - j];
            blackHap += Sum[0][2 * K][K - j] - Sum[0][2 * K - i][K - j];
            whiteHap = Sum[1][K - i][2 * K - j] + Sum[1][2 * K - i][K - j];
            whiteHap = whiteHap - Sum[1][K - i][K - j] * 2;
            whiteHap += Sum[1][2 * K - i][2 * K] - Sum[1][K - i][2 * K] - Sum[1][2 * K - i][2 * K - j] + Sum[1][K - i][2 * K - j];
            whiteHap += Sum[1][2 * K][2 * K - j] - Sum[1][2 * K][K - j] - Sum[1][2 * K - i][2 * K - j] + Sum[1][2 * K - i][K - j];
            if(i != 0 && j != 0)
            {
                blackHap = blackHap + Sum[0][2 * K][2 * K] - Sum[0][2 * K - i][2 * K] - Sum[0][2 * K][2 * K - j] + Sum[0][2 * K - i][2 * K - j];
            }

            whiteHap2 = Sum[1][2 * K - i][2 * K - j] + Sum[1][K - i][K - j] * 2;
            whiteHap2 = whiteHap2 - Sum[1][K - i][2 * K - j] - Sum[1][2 * K - i][K - j];
            whiteHap2 += Sum[1][K - i][2 * K] - Sum[1][K - i][2 * K - j];
            whiteHap2 += Sum[1][2 * K][K - j] - Sum[1][2 * K - i][K - j];
            blackHap2 = Sum[0][K - i][2 * K - j] + Sum[0][2 * K - i][K - j];
            blackHap2 = blackHap2 - Sum[0][K - i][K - j] * 2;
            blackHap2 += Sum[0][2 * K - i][2 * K] - Sum[0][K - i][2 * K] - Sum[0][2 * K - i][2 * K - j] + Sum[0][K - i][2 * K - j];
            blackHap2 += Sum[0][2 * K][2 * K - j] - Sum[0][2 * K][K - j] - Sum[0][2 * K - i][2 * K - j] + Sum[0][2 * K - i][K - j];
            if(i != 0 && j != 0)
            {
                whiteHap2 = whiteHap2 + Sum[1][2 * K][2 * K] - Sum[1][2 * K - i][2 * K] - Sum[1][2 * K][2 * K - j] + Sum[1][2 * K - i][2 * K - j];
            }
            result = max(result, max(blackHap + whiteHap, blackHap2 + whiteHap2));
        }
    }
    printf("%d", result);
}