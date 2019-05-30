#include <cstdio>
#include <iostream>
using namespace std;
int H, W, h, w;

/*
H행에서 h행을 제외 하고 W열에서 w열을 제외 했을때 남은 개수를 구하면 된다.
*/

int main()
{
    scanf("%d %d %d %d", &H, &W, &h, &w);
    printf("%d", (H - h) * (W - w));
}