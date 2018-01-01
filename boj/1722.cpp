#include <cstdio>
#include <iostream>
using namespace std;
int N, Q, Number[25], chk[25], result[25];
long long K, Fac;

/*
k번째 순열을 구하는것은 처음부터 끝까지 brute force하게 탐색을 하게 되면 20!이기 때문에
무조건 시간초과가 난다. 그래서 x번째 자리에서 i번째 수를 선택하게 되면 그 다음의 가짓수들이 몇개
인지를 파악해서 k가 그 가짓수보다 크면 x번째 i번째 수를 선택해도 k번째를 만들지 못하기 떄문에
스킵하는 방식으로 하였다.
예를 들어 숫자가 4개일 경우 4!이니까 첫번째 자리수에서 1을 고르면 그 다음에 나올 가짓수들은 6개 뿐이다.
k가 8이라면 첫번째에서 1을 고른 경우는 볼필요가 없다.
이렇게 매번 재귀를 타면서 경우의 수를 줄여 나간다.
몇 번째 수열인지 구하는것은 위와 같은방식으로 구한다.
*/

//팩토리얼 계산
long long fac(int depth)
{
    if(depth == 1)
    {
        return 1;
    }
    return fac(depth - 1) * depth;
}

//depth == x번째, count == 해당 순열이 몇 번째인지 저장
void func(int depth, long long count)
{
    if(depth == N)
    {
        //순열 출력
        if(Q == 1)
        {
            for(int i = 0; i < depth; i++)
            {
                printf("%d ", result[i]);
            }
        }
        //몇 번째 인지 출력
        else
        {
            printf("%lld", count);
        }
        return;
    }
    //경우의 수를 더하기 위한 변수
    long long hap = 0;
    for(int i = 1; i <= N; i++)
    {   
        if(chk[i] == 0)
        {
            //x번쨰 자리에서 i번째 수를 골랐을경우 나올수 있는 모든 경우의 수
            hap += Fac / (N - depth);
            //k번쨰 순열 구하기
            if(Q == 1)
            {
                //k번쨰 순열을 구할수 있다면
                if(K <= count + hap)
                {
                    chk[i] = 1;
                    result[depth] = i;
                    hap -= Fac / (N - depth);
                    Fac /= (N - depth);
                    func(depth + 1, count + hap);
                    break;
                }
            }
            //몇 번째 순열인지 구하기
            else
            {
                if(Number[depth] == i)
                {
                    chk[i] = 1;
                    hap -= Fac / (N - depth);
                    Fac /= (N - depth);
                    func(depth + 1, count + hap);
                    break;
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &Q);
    Fac = fac(N);
    if(Q == 1)
    {
        scanf("%lld", &K);
        func(0, 0);
    }
    else
    {
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &Number[i]);
        }
        func(0, 1);
    }
}