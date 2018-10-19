#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[1005], result;

/*
추 N개를 이용해서 만들 수 있는 최대 수는 처음부터 끝까지 다 더한 값이다.
추를 오름 차순으로 정렬 후 arr[0]부터 arr[i]까지 만들 수 있는 최대 수는 arr[0] + arr[1] + ... + arr[i]가 된다.
이것은 1, 2, ..., arr[0] + .... + arr[i]까지 만들 수 있다는 의미이다.
이제 여기에서 i + 1번째 수를 더했을때 만들 수 있는 수들은 1, 2, ...., arr[0] + ... + arr[i]와
arr[i + 1], arr[i + 1] + 1, arr[i + 1] + 2, ... arr[0] + arr[1] + .... + arr[i] + arr[i + 1]이 된다.
arr[i + 1]이 arr[0]부터 arr[i]까지 더한 값보다 크다면 더한값과 arr[i + 1]사이에 공백이 생긴다. 따라서
각각의 인덱스의 값을 확인 하면서 다 더한값보다 큰 값이 나오게 되면 다 더한값 + 1이 정답이 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + N);
    for(int i = 0; i < N; i++)
    {
        //공백 발생
        if(result + 1 < arr[i])
        {
            break;
        }
        result += arr[i];
    }
    printf("%d", result + 1);
}