#include <bits/stdc++.h>
using namespace std;
int n, Count[15], Length[100005];
long long Num[100005][13], result, mod = 998244353;

/*
규칙을 잘 보면 주어진 수 ai에 대해서 a(1 ~ n)까지의 값들중 ai의 길이보다 긴 수들은
ai가 모두 두칸씩 띄엄 띄엄 나타나게 된다. 예를 들어 a1 = 123, a2 = 4567, a3 = 45915일 때
a1은 모두 a2, a3 사이에 들어가게 된다. a1보다 작은 길이의 수에 대해서는 작은 길이의 수의 개수 만큼은
a1이 사이에 들어가지만 그 이상은 모두 붙어져서 나오게 된다. 따라서 각각의 주어진 수들에 대해
길이를 카운트하고 어떤 수 ai에 대해 ai를 길이 1 ~ 10까지 수들과 매칭 시켰을 때 나오는 수를 구한 후
그 수에 해당 길이의 개수를 곱해주면 된다. 이 방법은 ai가 앞에 나오는 경우를 구하는 것이였고
ai가 뒤에 나오는 경우는 앞에 방법에서 구한 수 /10을 해주면 된다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int num, count = 0;
        scanf("%d", &num);
        Num[i][11] = num;
        while(num > 0)
        {
            count++;
            Num[i][count] = num % 10;
            num /= 10;
        }
        Length[i] = count;
        Count[count]++;
    }
    for(int i = 0; i < n; i++)
    {
        int idx = 0;
        //tNum[15]은 ai가 1 ~ 10까지 길이를 가진 수와 매칭 했을 때 나오는 수를 저장하는 배열
        unsigned long long temp = 0, ten = 10, tNum[15];
        //1 ~ ai의 길이까지 수들과 매칭 했을 때 나오는 수를 구함
        for(int j = 1; j <= Length[i]; j++)
        {
            temp += Num[i][j] * ten / 10 * ten;
            tNum[j] = Num[i][11] / ten * ten * ten + temp;
            ten *= 10;
        }
        //ai가 앞에 나오는 경우
        for(int j = 1; j <= 10; j++)
        {
            if(idx < Length[i])
                idx++;
            result = (result + tNum[idx] % mod * Count[j] % mod) % mod;
        }
        idx = 1;
        //ai가 뒤에 나오는 경우
        for(int j = 1; j <= 10; j++)
        {
            if(idx < Length[i])
                idx++;
            result = (result + tNum[idx] / 10 % mod * Count[j] % mod) % mod;
        }
    }
    printf("%lld", result);
}