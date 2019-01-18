#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int result, pos[5], flag[5];
char s[500005], seq[10];

/*
온전한 모양의 아코디언은 [::]이다. 가장 긴 아코디언의 길이를 찾는 것이기 때문에
가장 길다는것은 [:와 :]의 길이가 가장 길때 이다. 따라서 가장 작은[의 인덱스와
[보다 크면서 가장 작은:를 찾고 또 가장 큰 ]를 찾고 ]보다 작으면서 가장 큰 :를 찾으면 된다.
이제 |모양은 : :의 사이에 있는 것들을 찾아주면 된다.[::] + |의 개수를 더해주면 가장 긴 아코디언이 된다.
*/

int main()
{
    scanf("%s", s);
    int length = strlen(s);
    for(int i = 0; i < length; i++)
    {
        if(s[i] == '[' && flag[0] == 0)
        {
            flag[0] = 1;
            pos[0] = i;
        }
        if(s[i] == ':' && flag[0] == 1)
        {
            flag[1] = 1;
            pos[1] = i;
            break;
        }
    }
    for(int i = length - 1; i > pos[1]; i--)
    {
        if(s[i] == ']' && flag[3] == 0)
        {
            flag[3] = 1;
            pos[3] = i;
        }
        if(s[i] == ':' && flag[3] == 1)
        {
            flag[2] = 1;
            pos[2] = i;
            break;
        }
    }
    //:  : 사이에 있는 |모양들
    for(int i = pos[1]; i < pos[2]; i++)
    {
        if(s[i] == '|')
        {
            result++;
        }
    }
    //모양이 제대로 안나오는 경우
    for(int i = 0; i < 4; i++)
    {
        if(flag[i] == 0)
        {
            printf("-1");
            return 0;
        }
    }
    printf("%d", 4 + result);
}