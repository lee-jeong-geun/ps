#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, Count[5][5], result, chk[5], route[5], rNum[5];
int wordToInt[30];
char intToWord[5] = "RGB";

/*
같은 문자가 나와야 하는 조건은 현재 인덱스로부터 +3에 나와야 한다.
종류는 총 3가지이므로 세종류를 하나의 구간으로 보면 각각의 구간에는 전부 다른 종류의 문자만 존재한다.
따라서 모든 문자들을 하나의 구간으로 압축시켜서 각각의 문자들이 위치해 있는 인덱스에 개수를 저장한다.
그리고 각 구간은 RGB RBG GRB GBR BRG BGR의 모양으로만 존재가 가능하다.
각각의 모양일때 일치되는 문자들을 카운트 후 제일 많이 일치되는 모양으로 출력 하면 된다.
*/

//'R', 'G', 'B' 문자로 순열 만드는 함수
void func(int depth)
{
    if(depth == 3)
    {
        int hap = 0;
        //일치되는 문자들 카운트
        for(int i = 0; i < 3; i++)
        {
            hap += Count[route[i]][i];
        }
        if(result < hap)
        {
            result = hap;
            //출력 할 모양 저장
            for(int i = 0; i < 3; i++)
            {
                rNum[i] = route[i];
            }
        }
    }
    for(int i = 0; i < 3; i++)
    {
        if(chk[i] == 0)
        {
            route[depth] = i;
            chk[i] = 1;
            func(depth + 1);
            chk[i] = 0;
        }
    }
}

int main()
{
    wordToInt['R' - 'A'] = 0;
    wordToInt['G' - 'A'] = 1;
    wordToInt['B' - 'A'] = 2;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        char word;
        scanf(" %c", &word);
        //각각의 문자들이 존재하는 인덱스에 개수 저장
        Count[wordToInt[word- 'A']][i % 3]++;
    }
    func(0);
    printf("%d\n", n - result);
    for(int i = 0; i < n; i++)
    {
        printf("%c", intToWord[rNum[i % 3]]);
    }    
}