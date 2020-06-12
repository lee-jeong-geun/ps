#include <bits/stdc++.h>
using namespace std;
vector<int> result;
int K, arr[5] = {4, 7};

/*
4와 7로 이루어진 수를 작은 순으로 만들면 4, 7, 44, 47, 74, 77, ... 이 되는데
이걸 트리로 그려 보면 완전 이진 트리 모양이 된다. 따라서 K 번째 작은 수는 루트로 이동하면서
4 or 7을 적고 다 한 다음 반대로 출력 하면 된다.
*/

int main()
{
    scanf("%d", &K);
    K++;
    while(K != 1)
    {
        result.push_back(arr[K % 2]);
        K /= 2;
    }
    for(int i = result.size() - 1; i >= 0; i--)
    {
        printf("%d", result[i]);
    }
}