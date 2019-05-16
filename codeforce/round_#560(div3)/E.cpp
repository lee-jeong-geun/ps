#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
long long A[200005], B[200005], result;

/*
l, r의 모든 조합을 구하고 B배열의 순서를 바꿔서 f(l, r)의 합을 최소화 시켜야 한다.
A배열은 가만히 있으므로 식을 구하다 보면 계수들이 구해지는데 큰계수들에는 B배열의 작은 원소를
대입 시킨다. 즉 A배열에 계수들을 저장하고 정렬 후 B배열을 그 반대로 정렬시켜서 매칭 시킨 후 합을 구하면
된다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &A[i]);
        //계수 저장
        A[i] = A[i] * (n - i) * (i + 1);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &B[i]);
    }
    sort(A, A + n);
    //내림차순으로 정렬
    sort(B, B + n, greater<int>());
    for(int i = 0; i < n; i++)
    {
        //모든 합 구하기
        result = (result + A[i] % 998244353 * B[i]) % 998244353;
    }
    printf("%lld", result);
}