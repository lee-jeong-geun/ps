#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int t;
char word[200005];

/*
주어진 문자열에 one, two가 있는지 확인하는 문제다.
그 이유는 ooooooneeeeee라면 n만 제거하면 되고 onnnne는 애초에 안되는 문자열이기 때문에
one, two 가운데만 제거하는 방법으로 가면 되는데 twone처럼 two와 one이 붙어있는 경우가 있다.
이때는 o를 제거해주면 된다.
*/

int main()
{
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++)
    {
        vec.clear();
        scanf("%s", word);
        int length;
        length = strlen(word);
        for(int i = 0; i < length; i++)
        {
            //one확인
            if(i + 2 < length && word[i] == 'o' && word[i + 1] == 'n' && word[i + 2] == 'e')
                vec.push_back(i + 1);
            //two확인
            if(i + 2 < length && word[i] == 't' && word[i + 1] == 'w' && word[i + 2] == 'o')
            {
                //two면서one인 경우는 twone
                if(i + 4 < length && word[i + 3] == 'n' && word[i + 4] == 'e')
                    vec.push_back(i + 2);
                else
                    vec.push_back(i + 1);
                i += 2;
            }
        }
        printf("%d\n", vec.size());
        for(int i = 0; i < vec.size(); i++)
        {
            printf("%d ", vec[i] + 1);
        }
        printf("\n");
    }
}