#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> vec;
set<int> s1, s2;
int n, k;

/*
주어진 괄호들을 ()이모양으로 k - 1개 배치하고 나머지는 ((())) 이런 모양으로 배치하면 된다.
()이모양으로 배치하기 위해서는 (를 가진 괄호들중 가장 앞에 있는 괄호를 맨앞으로 옮기면 된다.
이때 2개의 경우를 나눠서 생각해야 하는데 하나는 (괄호가 애초에 맨 앞에 있어서 옮길 필요가 없는경우고
나머지는 (괄호 앞에 )괄호가 존재하는 경우다. 2번째 경우는 (를 맨앞에 보내면 당연하게 바로 뒤에는 )괄호가
있기 때문에 () 모양이 완성된다. 하지만 앞의 경우는 (뒤에 (가 있을수 있기 때문에 () 모양이 완성되어있는지
확인하기 어렵다. 따라서 앞의 경우라면 )괄호를 맨앞으로 보내고 (괄호를 맨앞으로 보내면 자연스럽게 ()모양이
만들어 진다. ()모양을 k - 1개 만든다면 이제 남은건 (())이 모양이다.
이것은 그냥 (모양을 계속 앞으로 배치시켜주면 자연스럽게 (())모양이 완성되는데 그 이유는 
(의 개수와 )의 개수가 동일하기 때문이다.
*/

int main()
{
    int t;
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++)
    {
        //(의 위치 저장
        s1.clear();
        //)의 위치 저장
        s2.clear();
        vec.clear();
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++)
        {
            char word;
            scanf(" %c", &word);
            if(word == '(')
                s1.insert(i);
            else
                s2.insert(i);
        }
        //Cur는 (괄호를 어디 위치로 이동시켜야 하는지 나타내는 변수
        int Cur = 0, count = 0;
        while(s1.size() > 0)
        {
            int start;
            start = *s1.begin();
            s1.erase(start);
            //(괄호를 Cur까지 이동시키면서 바로 앞의 )괄호와 위치 스왑
            for(int i = start - 1; i >= Cur; i--)
            {
                s2.erase(i);
                s2.insert(i + 1);
            }
            //Cur와 start가 다르다는것은 (위치를 Cur까지 이동 시켰다는 뜻
            if(Cur != start)
                vec.push_back({Cur, start});
            //그게 아니라는것은 애초에 (괄호가 Cur위치에 있는 경우
            //즉 (괄호 이동x
            else
            {
                start = *s2.begin();
                //)괄호를 Cur까지 이동시킴
                for(int i = start - 1; i >= Cur; i--)
                {
                    s1.erase(i);
                    s1.insert(i + 1);
                }
                vec.push_back({Cur, start});
                s2.erase(start);
                s2.insert(Cur);
                continue;
            }
            // k - 1개 까지는 () 모양으로 완성 시킴
            if(count + 1 < k)
            {
                s2.erase(Cur + 1);
                Cur++;
                count++;
            }
            Cur++;
        }
        printf("%d\n", vec.size());
        for(int i = 0; i < vec.size(); i++)
        {
            printf("%d %d\n", vec[i].first + 1, vec[i].second + 1);
        }
    }
}