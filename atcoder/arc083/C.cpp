#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int A, B, C, D, E, F, water, sugar;
double result;

/*
A, B, C, D번 조작을 통해서 설탕의 농도가 최대 몇인지 구해야 한다.
각 조작마다 연산횟수가 얼마 되지 않으므로 완전탐색을 이용하여 구하면 된다.
*/

int main()
{
    scanf("%d %d %d %d %d %d", &A, &B, &C, &D, &E, &F);
    for(int k = 0; A * k * 100 < F; k++)
    {
        for(int l = 0; A * k * 100 + B * l * 100 < F; l++)
        {
            int minWater;
            //min(비커 용량 - 넣은 물, 넣은 물 * 녹을수 있는 설탕 양)
            minWater = min(F - A * k * 100 - B * l * 100, (A * k + B * l) * E);
            for(int i = 0; i * C <= minWater; i++)
            {
                for(int j = 0; i * C + j * D <= minWater; j++)
                {
                    if(i == 0 && j == 0)
                    {
                        continue;
                    }
                    int tempWater, tempSugar;
                    tempWater = (A * k + B * l) * 100;
                    tempSugar = i * C + j * D;
                    if(result < (double)tempSugar * 100 / (tempWater + tempSugar))
                    {
                        result = (double)tempSugar * 100 / (tempWater + tempSugar);
                        water = tempWater;
                        sugar = tempSugar;
                    }
                }
            }
        }
    }
    //비커는 비어있으면 안됨
    if(result == 0)
    {
        water = A * 100;
    }
    printf("%d %d", water + sugar, sugar);
}