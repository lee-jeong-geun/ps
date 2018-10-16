#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int chk[10], change[30], Slength, result;
char S[2505];

/*
우선 c r o a k 순으로 배열을 구성한다.
c를 받으면 c의 인덱스에 카운트를 하는 방식으로 만들면 된다.
그 후 문자열을 순차적으로 탐색 하면서 해당 문자의 인덱스에 카운트를 더해 주는데 
r을 더해 줄때 r + 1이 c보다 많으면 안된다.
올바른 울음 소리는 c r o a k 순으로 나오기 때문에 r이 c보다 많다는 건 올바르지 않는 울음소리가 입력
되었다는 뜻이다. o a k도 이런 식으로 자기 앞의 문자의 개수를 확인 해준다.
그래서 k를 탐색 했을땐 c r o a k 전부다 개수를 하나씩 줄여준다.
몇마리 인지 확인 하는것은 c를 탐색 할때마다 c의 개수를 최대값이랑 비교 하면서 갱신 해주면 된다.
다 탐색을 하고 c r o a k 개수가 하나도 없을 경우 올바른 울음소리다.
*/

int main()
{
    //각각의 문자를 인덱스 매칭 시켜줌
    change['c' - 'a'] = 0;
    change['r' - 'a'] = 1;
    change['o' - 'a'] = 2;
    change['a' - 'a'] = 3;
    change['k' - 'a'] = 4;
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        result = 0;
        memset(chk, 0, sizeof chk);
        scanf("%s", S);
        Slength = strlen(S);
        for(int i = 0; i < Slength; i++)
        {
            //c를 제외한 나머지 문자일 경우 자기보다 순서가 하나 높은 문자 개수 확인
            if(S[i] != 'c' && chk[change[S[i] - 'a'] - 1] < chk[change[S[i] - 'a']] + 1)
            {
                result = -1;
                break;
            }
            //해당 문자 카운트
            chk[change[S[i] - 'a']]++;
            //c일 경우 최대값 확인 후 갱신
            if(S[i] == 'c')
            {
                result = max(result, chk[change[S[i] - 'a']]);
            }
            //k일 경우 전부다 한개 줄여줌
            if(S[i] == 'k')
            {
                for(int j = 0; j < 5; j++)
                {
                    chk[j]--;
                }
            }
        }
        //개수가 하나라도 남아있으면 x
        for(int i = 0; i < 5; i++)
        {
            if(chk[i] > 0)
            {
                result = -1;
            }
        }
        printf("#%d %d\n", testcase, result);
    }
}