#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<pair<int, int>, int> piii;
vector<piii> vec[5];
int n;

/*
규칙을 잘 보면 < > < > 이 부등호는 a < b 라는 규칙을 이용한다면 a1 < b1 > a2 < b2, .... 
즉 (a1 < b1), (a2 < b2) a가 b보다 작은 쌍들을 따로 모은 후 쌍들의 순서를 잘 배치해주면 최대한 길게 배치
할 수 있다. 잘 배치해주는 조건은 a1 < b1 && a2 < b2 일때 b1 다음에 오는 a2는 b1보다 작아야 되는 조건이지만
잘 보면 a1은 b1보다 작고 또 a2도 b1보다 작다. a2를 a1보다 작은 값으로 배치하면 연결 시킬 수 있다.
즉 (a, b)에서 a를 기준으로 정렬 시키면 손쉽게 연결 시킬 수있다. 반대 부등호 조건도 비슷하게 역정렬을 하여서
< > < >와 > < > <의 개수를 비교해서 더 긴것을 출력 시키면 된다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        //< > < >
        if(a < b)
            vec[0].push_back({{a, b}, i + 1});
        //> < > <
        else
            vec[1].push_back({{a, b}, i + 1});
    }
    sort(vec[0].begin(), vec[0].end());
    sort(vec[1].begin(), vec[1].end());
    if(vec[0].size() > vec[1].size())
    {
        printf("%d\n", vec[0].size());
        for(int i = vec[0].size() - 1; i >= 0; i--)
        {
            printf("%d ", vec[0][i].second);
        }
    }
    else
    {
        printf("%d\n", vec[1].size());
        for(int i = 0; i < vec[1].size(); i++)
        {
            printf("%d ", vec[1][i].second);
        }
    }
}