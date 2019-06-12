#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> vec;
int n;
int arrX[2] = {1, 0};
int arrY[2] = {0, 1};

/*
규칙을 잘 찾다보면 행+1, 열+1, 행+1, 열+1 이거나 열+1, 행+1, 열+1, 행+1을 반복한다.
이것들을 출력하면 된다.
*/

int main()
{
    scanf("%d", &n);
    vec.push_back({1, 1});
    int x, y;
    x = 1;
    y = 1;
    for(int i = 2; i <= n; i++)
    {
        vec.push_back({y + arrY[i % 2], x + arrX[i % 2]});
        x = x + arrX[i % 2];
        y = y + arrY[i % 2];
    }
    printf("%d\n", max(vec[n - 1].first, vec[n - 1].second));
    for(int i = 0; i < n; i++)
    {
        printf("%d %d\n", vec[i].second, vec[i].first);
    }
}