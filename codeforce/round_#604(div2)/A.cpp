#include <bits/stdc++.h>
using namespace std;
string word, alph = "abc";
int resultFlag;

/*
?의 앞뒤 문자를 확인해서 abc중에 들어갈수 있는것을 넣으면 된다.
*/

int main()
{
    int t;
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++)
    {
        resultFlag = 0;
        string temp;
        temp = '?';
        cin >> word;
        temp += word;
        temp += '?';
        for(int i = 1; i < temp.size() - 1; i++)
        {
            if(temp[i] != '?')
                continue;
            for(int j = 0; j < 3; j++)
            {
                //앞도 아니고 뒤도 아닌 문자
                if(temp[i - 1] != alph[j] && temp[i + 1] != alph[j])
                {
                    temp[i] = alph[j];
                    break;
                }
            }
        }
        for(int i = 1; i < temp.size() - 1; i++)
        {
            //하나라도 연속이라면 -1
            if(temp[i - 1] == temp[i])
                resultFlag = 1;
        }
        if(resultFlag == 1)
        {
            printf("-1\n");
            continue;
        }
        for(int i = 1; i < temp.size() - 1; i++)
        {
            printf("%c", temp[i]);
        }
        printf("\n");
    }
}