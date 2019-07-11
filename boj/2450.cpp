#include <cstdio>
#include <iostream>
using namespace std;
int N, arr[100005], Count[5], result = 987654321;
int op[6][3] = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};

/*
나올 수 있는 모양은 {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, 등등 총 6가지이다.
따라서 각 모양으로 배치하고 몇개를 스왑 해야할 지 찾으면 된다.
{1, 3}, {3, 1}처럼 1과 3을 바꾸면 되는 경우와 {1, 2}, {2, 3}, {3, 1}처럼 1, 2를 바꾸고 1, 3을 바꿔야 하는
경우가 있다. {1, 2}, {2, 3}, {3, 1}이나 {1, 3}, {2, 1}, {3, 2}가 몇개 존재하는지 찾고 전체 스왑해야할
개수에서 뺀걸 / 2 해주면 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        //각 숫자 등장 카운트
        Count[arr[i]]++;
    }
    for(int i = 0; i < 6; i++)
    {
        int idx = 0, Min1, Min2, hap = 0, count[4][4] = {0};
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < Count[op[i][j]]; k++)
            {
                //다르면 카운트
                if(arr[idx] != op[i][j])
                {
                    hap++;
                    count[arr[idx]][op[i][j]]++;
                }
                idx++;
            }
        }
        //{1, 2}, {2, 3}, {3, 1}이 몇개 등장 하는지 확인
        //최소 등장이 1이상이라면 이러한 패턴이 1개이상 이라는 뜻
        Min1 = min(count[1][2], min(count[2][3], count[3][1]));
        //{1, 3}, {2, 1}, {3, 2}등장 확인
        Min2 = min(count[1][3], min(count[2][1], count[3][2]));
        if(Min1 < Min2)
            swap(Min1, Min2);
        hap = (Min1 - Min2) * 2 + (hap - (Min1 - Min2) * 3) / 2;
        result = min(result, hap);
    }
    printf("%d", result);
}