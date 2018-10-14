#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, K, password[155], idx;
char box[2][35];

/*
숫자는 최대 28개 까지 나오므로 오른쪽으로 쉬프트 하는 횟수는 27번까지 가능하다.
그리고 각각의 수들을 모두 확인 해야 하고 수 전체를 쉬프트 해야 하므로
경우의수는 27 * 28 * 28 정도가 나오게 된다. 그리고 나올수 있는 수의 종류는
28 * 4개이다. 따라서 완전탐색으로 충분히 해결 할 수 있다.
*/

//16진수를 10진수로 바꿈
int chToint(char word)
{
    if(word >= '0' && word <= '9')
    {
        return word - '0';
    }
    return word - 'A' + 10;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        idx = 0;
        scanf("%d %d", &N, &K);
        for(int i = 0; i < N; i++)
        {
            scanf(" %c", &box[0][i]);
        }
        for(int i = 0; i < N - 1; i++)
        {
            int count = 0, hap = 0;
            //4곳의 수를 확인
            for(int j = 0; j < N; j++)
            {
                count++;
                hap *= 16;
                hap += chToint(box[i % 2][j]);
                //한쪽을 전부 확인 했을 경우
                if(count == N / 4)
                {
                    password[idx++] = hap;
                    hap = 0;
                    count = 0;
                }
            }
            //오른쪽으로 쉬프트
            for(int j = 0; j < N; j++)
            {
                box[(i + 1) % 2][(j + 1) % N] = box[i % 2][j];
            }
        }
        sort(password, password + idx, greater<int>());
        password[idx] = -1;
        int count = 0;
        //정렬 후 중복 제거 하면서 결과 확인
        for(int i = 0; i < idx; i++)
        {
            if(password[i] != password[i + 1])
            {
                count++;
            }
            if(count == K)
            {
                printf("#%d %d\n", testcase, password[i]);
                break;
            }
        }
    }
}