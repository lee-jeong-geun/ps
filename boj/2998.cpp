#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char two[115], eight[8][5] = {{"000"}, {"100"}, {"010"}, {"110"}, {"001"}, {"101"}, {"011"}, {"111"}};
int result[105];
int Length, idx;

void change()
{
    char temp[105];
    for(int i = 0; i < Length; i++)
    {
        temp[i] = two[Length - i - 1];
    }
    while(Length % 3 != 0)
    {
        temp[Length] = '0';
        Length++;
    }
    temp[Length] = '\0';
    strcpy(two, temp);
}

int main()
{
    scanf("%s", two);
    Length = strlen(two);
    change();
    int tidx = 0;
    char temp[5];
    for(int i = 0; i < Length; i++)
    {
        temp[tidx++] = two[i];
        if(i % 3 == 2)
        {
            temp[tidx] = '\0';
            for(int j = 0; j < 8; j++)
            {
                if(strcmp(temp, eight[j]) == 0)
                {
                    result[idx++] = j;
                    break;
                }
            }
            tidx = 0;
        }
        
    }
    for(int i = idx - 1; i >= 0; i--)
    {
        printf("%d", result[i]);
    }
}