#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, Sum[100005], result = 1234567890;

/*
블루레이의 길이로 M개를 만들수 있냐 없냐로  이분탐색을 하면 된다.
단 M개를 만들때 블루레이의 길이를 레슨으로 최대한 채워줘야 한다.
이렇게 채워주면 M개 이하를 만들거나 초과로 만들수 있다.
M개를 넘게 만들었다는건 블루레이 길이를 작게 잡아서 레슨을 많이 못채웠기 때문이다.
따라서 길이를 크게 잡아 M개를 만들게 하면 된다.
반대의 경우에는 어떻게든 M개를 만들수 있기 때문에 길이를 줄여가면서 탐색하면 된다.
*/

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
    {
        int lesson;
        scanf("%d", &lesson);
        Sum[i] = Sum[i - 1] + lesson;
    }
    int l, r;
    l = 0;
    r = 1000000000;
    while(l <= r)
    {
        int mid, count = 0, left, right, flag = 0;
        mid = (l + r) / 2;
        left = 0;
        right = 1;
        //부분합
        while(left <= right && right <= N)
        {
            //left + 1부터 right - 1까지 한개의 블루레이에 포함
            if(Sum[right] - Sum[left] > mid)
            {
                //하나의 레슨이 블루레이 길이보다 큰경우
                //문제의 조건에 위배되므로 종료
                if(right - left == 1)
                {
                    flag = 1;
                    break;
                }
                count++;
                left = right - 1;
                right--;
            }
            right++;
        }
        if(count + 1 <= M && flag == 0)
        {
            result = min(result, mid);
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("%d", result);
}