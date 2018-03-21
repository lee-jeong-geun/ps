#include <cstdio>
#include <iostream>
using namespace std;
int n, Number[1000005], Left[1000005], Right[1000005], Query[1000005], result;

/*
두 수열이 주어졌을때 첫 번째 수열을 뒤집거나 왼쪽 혹은 오른쪽으로 밀어서 두 번째 수열을
만들수 있는지 확인 하는 문제이다. 뒤집든 밀든 수열 중간에 있는 수들의 위치가 바뀌는게 아니라서
곧 첫 번째 수열을 원으로 만들고 시계 방향으로 탐색하거나 반시계 방향으로 탐색을 해서 두 번째 수열을 만들 수 있는지
확인 하면 된다.
*/

void func()
{
    for(int i = 0; i < n - 1; i++)
    {
        //두 번째 수열의 수들을 첫 번째 수열에 매칭 시켜서 연속인지 확인 함
        if(Left[Query[i]] != Query[i + 1] && Right[Query[i]] != Query[i + 1])
        {
            result = 1;
            return;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &Number[i]);
    }
    //원형으로 만듬
    Number[0] = Number[n];
    Number[n + 1] = Number[1];
    for(int i = 1; i <= n; i++)
    {
        //첫 번째 수열의 왼쪽 오른쪽 수를 저장함
        Left[Number[i]] = Number[i - 1];
        Right[Number[i]] = Number[i + 1];
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &Query[i]);
    }
    func();
    if(result == 0)
    {
        printf("good puzzle");
    }
    else
    {
        printf("bad puzzle");
    }
}