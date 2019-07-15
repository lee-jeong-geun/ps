#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int> arr[300005];
int N, S, memo[300005], maxHeight[300005];

/*
규칙을 잘 보면 그림들을 최대한 많이 노출 시키는게 이득이다. 따라서 그림들을 높이 순으로 정렬을 하고
맨앞의 그림부터 시작해서 다음 그림으로 이동하면서 가격을 갱신해준다.
갱신 방법은 i번째 그림에 대해서 i - 1그림에 i를 추가 했을 때 보이는 부분이 S이상이라면 i번째 가격을
더하면 되고 그게 안된다면 i - 1까지의 가격과 i - 1을 제거하고 i보다 작은 그림들 중 i를 추가 했을 때
보이는 부분이 S이상인 그림의 최대 높이 까지의 가격 + i가격 둘중 큰값으로 갱신해 주면 된다.
이때 i보다 작은 그림들중 높이 차가 S이상인 최대 높이 그림을 빠르게 찾아야 하는데
이분탐색을 이용 하거나 미리 구하는 방법이 있다.
i번째 그림보다 작은 그림들중 높이 차가 S이상인 최대 높이의 그림은 i - 1번째 그림에 저장된 최대 높이
인덱스 다음부터 보면 된다. 그 이유는 그 인덱스 앞 그림들은 어차피 높이 차가 S이상이다.
그래서 가장 높은 그림을 찾으려면 당연히 그 인덱스 뒤에 있는 그림들을 봐야 한다.
이렇게 하면 O(N)으로 최대 가격을 구할 수 있다.
*/

int main()
{
    scanf("%d %d", &N, &S);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }
    //높이 순으로 정렬
    sort(arr + 1, arr + N + 1);
    //높이차가 S이상인 그림들중 가장 높은 그림 찾기
    for(int i = 1; i <= N; i++)
    {
        for(int j = maxHeight[i - 1]; j < i; j++)
        {
            if(arr[j].first + S > arr[i].first)
                break;
            maxHeight[i] = j;
        }
    }
    maxHeight[1] = 1;
    memo[1] = arr[1].second;
    for(int i = 2; i <= N; i++)
    {
        //높이차가 S이상이라면 i번째 그림의 가격 추가하고 i그림의 높이로 갱신
        if(arr[maxHeight[i - 1]].first + S <= arr[i].first)
        {
            memo[i] = memo[i - 1] + arr[i].second;
            maxHeight[i] = i;
        }
        else
        {
            //이전까지의 최대가격 or i번째 그림과 높이차가 S미만인 그림을 빼고 i그림을 추가한 가격
            memo[i] = max(memo[i - 1], memo[maxHeight[i]] + arr[i].second);
            //이전까지의 최대가격이 더 크다면 높이도 이전까지의 최대 높이로 갱신
            if(memo[i] == memo[i - 1])
                maxHeight[i] = maxHeight[i - 1];
            //그게 아니라면 i번째 그림의 높이로 갱신
            else
                maxHeight[i] = i;
        }
    }
    printf("%d", memo[N]);
}