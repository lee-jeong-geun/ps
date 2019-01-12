#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int Length, L, R, result = 987654321, Sum[100005], idx;
char S[100005];

/*
두개의 화살표를 이용하는데 각각 왼쪽과 오른쪽에 둔다.
왼쪽 화살표는 맨 왼쪽부터 연속한 부분의 마지막에 두고
오른쪽 화살표는 맨 오른쪽부터 연속한 부분의 마지막에 둔다.
이제 화살표가 가장 긴것을 전체 길이 - 반대쪽 화살표 길이로 결과값중에 더 작은 값을 저장하고
길이가 짧은쪽의 화살표를 다음 연속한 부분의 끝으로 이동 시킨다.
이걸 계속 반복하면 왼쪽 화살표와 오른쪽 화살표를 더한게 전체 길이가 되는데 이때
길이가 더 긴것과 결과값에 저장된 값중에 짧은 값을 출력하면 된다.
*/

int main()
{
    scanf("%s", S);
    Length = strlen(S);
    int count = 1;
    //연속인 것들을 개수로 축소 시킴
    for(int i = 0; i < Length; i++)
    {
        if(S[i] == S[i + 1])
        {
            count++;
        }
        else
        {
            Sum[idx++] = count;
            count = 1;
        }
    }
    //왼쪽 오른쪽 화살표
    L = Sum[0];
    R = Sum[idx - 1];
    int sl, sr;
    sl = 1;
    sr = idx - 2;
    //왼쪽 오른쪽 값이 전체 길이보다 작으면 계속 실행
    while(L + R < Length)
    {
        //오른쪽이 더 긴경우 
        if(L < R)
        {
            //왼쪽 화살표까지 스왑을 시킴
            result = min(result, Length - L);
            //왼쪽 화살표를 더 연속된 부분까지 이동
            L += Sum[sl++];
        }
        //위와 동일
        else
        {
            result = min(result, Length - R);
            R += Sum[sr--];
        }
    }
    printf("%d", min(result, max(L, R)));
}