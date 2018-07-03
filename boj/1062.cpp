#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int N, K, result, chk[30], bitCount[55], alpa[30], aidx;

/*
a, c, i, n, t를 제외한 나머지의 문자들을 이용하여 조합 탐색을 하면 된다.
문자열들을 입력받을때 저 위에 문자들을 제거한 후 중복들을 제거해주는 전처리 후에
a = 0번째 비트, b = 1번째 비트   <----- 이런 방식으로
각 문자열들의 비트 값들을 배열에 저장한다.
이렇게 하면 조합 탐색을 할 때 문자열 전체를 보지 않고 비트 값만으로 O(1)만에 일치 여부를 확인 할 수 있기 때문에
훨씬 빨라진다.
*/

void func(int key, int depth, int idx)
{
    if(depth == 0)
    {
        int count = 0;
        for(int i = 0; i < N; i++)
        {
            //일치 여부 확인
            if((bitCount[i] & key) == bitCount[i])
            {
                count++;
            }
        }
        result = max(result, count);
        return;
    }
    for(int i = idx + 1; i < aidx; i++)
    {
        func(key | (1 << alpa[i]), depth - 1, i);
    }
}

int main()
{
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
    {
        int length;
        char temp[25];
        string ttemp;
        scanf("%s", temp);
        length = strlen(temp);
        //anta, tica 제외
        for(int j = 4; j < length - 4; j++)
        {
            ttemp.push_back(temp[j]);
        }
        //정렬 해야 중복 확인 수월
        sort(ttemp.begin(), ttemp.end());
        length = ttemp.size();
        for(int j = 0; j < length; j++)
        {
            //이 문자들은 제외
            if(ttemp[j] == 'a' || ttemp[j] == 'c' || ttemp[j] == 'i' || ttemp[j] == 'n' || ttemp[j] == 't')
            {
                continue;
            }
            //중복 아닐시
            if(ttemp[j] != ttemp[j + 1])
            {
                if(chk[ttemp[j] - 'a'] == 0)
                {
                    chk[ttemp[j] - 'a'] = 1;
                    alpa[aidx++] = ttemp[j] - 'a';
                }
                bitCount[i] = bitCount[i] | (1 << (ttemp[j] - 'a'));
            }
        }
    }
    //탐색 해야 할 문자보다 K값이 큰 경우
    //탐색 해야 할 문자만 보면 됨
    if(K - 5 > aidx)
    {
        func(0, aidx, -1);
    }
    else
    {
        if(K - 5 >= 0)
        {
            func(0, K - 5, -1);
        }
    }
    printf("%d", result);
}