#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char str[205], result[205];
int k, Count[5];

/*
지팡이는 continue or remove이고 눈은 continue or remove or plus다.
알파벳들과 지팡이, 눈을 카운트 한 후 k보다 작으면 눈을 이용해서 plus, k보다 크면 지팡이와 눈을 이용해서
remove 시켜야 한다. 어차피 개수만 맞춰주면 되기 때문에 k보다 모자랄땐 알파벳을 제외한 남은
개수만큼 눈 하나를 이용하여 개수를 늘려주면 된다.
*/

int main()
{
    int length = 0, length2 = 0;
    scanf("%s %d", str, &k);
    length = strlen(str);
    for(int i = 0; i < length; i++)
    {
        if(str[i] == '?')
        {
            Count[0]++;
        }
        else if(str[i] == '*')
        {
            Count[1]++;
        }
        else
        {
            length2++;
        }
    }
    //k보다 작을때 눈이 하나도 없으면 불가능
    //k보다 클때 지팡이, 눈 개수를 알파벳 개수에서 빼도 k보다 많은 경우 불가능
    if(length2 < k && Count[1] == 0 || length2 > k && length2 - Count[0] - Count[1] > k)
    {
        printf("Impossible");
        return 0;
    }
    int idx = 0;
    //눈을 이용하여 개수를 늘림
    if(length2 < k)
    {
        for(int i = 0; i < length; i++)
        {
            //알파벳인 경우
            if(str[i] != '?' && str[i] != '*')
            {
                result[idx++] = str[i];
            }
            //눈인 경우
            else if(str[i] == '*')
            {
                //모자란 개수만큼 늘림
                for(int j = 0; j < k - length2; j++)
                {
                    result[idx] = result[idx - 1];
                    idx++;
                }
                length2 = k;
            }
        }
    }
    else
    {
        for(int i = 0; i < length; i++)
        {
            if(str[i] != '?' && str[i] != '*')
            {
                result[idx++] = str[i];
            }
            //지워야 하는 경우
            else if((str[i] == '?' || str[i] == '*') && length2 > k)
            {
                idx--;
                length2--;
            }
        }
    }
    result[idx] = 0;
    printf("%s", result);
}