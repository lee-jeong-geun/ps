#include <bits/stdc++.h>
using namespace std;
int n, arr[400005], chk[3000005], numbering[3000005], pCount = 1, Count[3000005];

/*
에라토스 테네스의 체를 이용하여 소수들을 빠르게 구한 후에 
주어진 배열을 내림차순으로 정렬을 하여 하나씩 접근한다.
이때 각각의 수들은 2가지 경우중 한개이다.
첫번째는 소수라면 해당 수가 몇번째 소수인지 나타내는 수가 배열에 존재 한다.
두번째는 소수가 아니라면 해당 수의 약수는 반드시 배열에 존재 한다.
이걸 이용하여 해당 수들은 출력하고 저 조건에 부합하는 쌍의 수를 배열에서 제거하면 된다.
이때 가장 큰 약수를 빠르게 구하는 방법은 에라토스 테네스의 체에서 배수들을 제거 할 때
해당 배수들의 가장 큰 약수는 곧 배수 / 소수 이다.
*/

int main()
{
    for(int i = 2; i < 3000000; i++)
    {
        //소수인경우
        if(chk[i] == 0)
        {
            //해당 소수가 몇번째 인지 저장
            numbering[i] = pCount++;
            for(int j = i + i; j < 3000000; j += i)
            {
                //가장 큰 약수 저장
                if(chk[j] == 0)
                    chk[j] = j / i;
            }
        }
    }
    scanf("%d", &n);
    for(int i = 0; i < n * 2; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n * 2, greater<int>());
    for(int i = 0; i < n * 2; i++)
    {
        //지워야 하는 경우
        if(Count[arr[i]] > 0)
        {
            Count[arr[i]]--;
            continue;
        }
        //소수인 경우
        if(chk[arr[i]] == 0)
        {
            Count[numbering[arr[i]]]++;
            printf("%d ", numbering[arr[i]]);
        }
        else
        {
            Count[chk[arr[i]]]++;
            printf("%d ", arr[i]);
        }
    }
}