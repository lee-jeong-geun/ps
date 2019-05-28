#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long int> vec;
int Count[5], K;
long long arr[5][1005];

/*
모든 순서쌍은 총 1000 * 1000 * 1000이 나오게 되므로 O(1000 ^ 3)은 힘들다.
A + B + C의 합이 큰 순으로 최대 K개를 뽑아야 하는데 잘 보면 상위 K개를 뽑기 위해선 A, B, C의 원소들
중에서 상위권 위주로 뽑아야 한다. 즉 (A, B, C)의 i번째 순서쌍이 K를 넘어가면 절대 상위 K개 안에
들어갈 수 없다. 따라서 상위 K개에 속할 가능성이 있는 순서쌍들을 배열에 넣은 후 정렬하여 K개를 출력하면 된다.
*/

int main()
{
    scanf("%d %d %d %d", &Count[0], &Count[1], &Count[2], &K);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < Count[i]; j++)
        {
            scanf("%lld", &arr[i][j]);
        }
    }
    //내림차순 정렬
    for(int i = 0; i < 3; i++)
    {
        sort(arr[i], arr[i] + Count[i], greater<long long int>());
    }
    for(int i = 0; i < Count[0]; i++)
    {
        for(int j = 0; j < Count[1]; j++)
        {
            for(int k = 0; k < Count[2]; k++)
            {
                //해당 순서쌍이 K를 넘어가면 종료
                if((i + 1) * (j + 1) * (k + 1) > K)
                {
                    break;
                }
                vec.push_back(arr[0][i] + arr[1][j] + arr[2][k]);
            }
        }
    }
    sort(vec.begin(), vec.end(), greater<long long int>());
    for(int i = 0; i < K; i++)
    {
        printf("%lld\n", vec[i]);
    }
}