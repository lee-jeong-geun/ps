#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, Z, W, Card[2005], result;

/*
X가 먼저 시작 하기 때문에 두 카드의 차이를 크게 만들어야 한다.
카드를 다 뽑을때까지 서로 계속 뽑아야 하므로 덱의 앞부분을 뽑는 것은
의미가 없다. 그 이유는 덱의 앞부분이나 중간 부분에 있는 카드를 뽑을 경우
Y는 무조건 차이를 좁히기 위해 해당 카드 뒤쪽에 있는 차이가 얼마 없는 카드를 뽑을 것이다.
따라서 중간에 있는 카드를 뽑는 것은 무의미 하다. 나올수 있는 경우는 2가지 밖에 없다.
하나는 X가 맨끝 카드를 뽑아서 그 카드와 W의 차이를 생각하는 것이고 두번째는
맨끝에서 한칸 앞인 카드를 뽑아서 Y를 맨끝 카드를 뽑게 만드는 것이다.

*/

int abs(int num)
{
    return num > 0 ? num : -num;
}

int main()
{
    scanf("%d %d %d", &N, &Z, &W);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &Card[i]);
    }
    result = abs(Card[N - 1] - W);
    if(N > 1)
    {
        result = max(result, abs(Card[N - 1] - Card[N - 2]));
    }
    printf("%d", result);
}