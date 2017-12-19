#include <cstdio>
using namespace std;
typedef struct _data
{
    int num;
    int start;
}Data;
//나룻배 구조체
Data Left[10005], Right[10005];
int M, t, N, Lidx, Ridx, bflag, leftcur, rightcur, Time, result[10005];

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    scanf("%d %d %d", &M, &t, &N);
    for(int i = 0; i < 10003; i++)
    {
        Left[i].start = 987654321;
        Right[i].start = 987654321;
    }
    for(int i = 0; i < N; i++)
    {
        int stime;
        char s[7];
        scanf("%d %s", &stime, s);
        if(s[0] == 'l')
        {
            Left[Lidx].num = i;
            Left[Lidx++].start = stime;
        }
        else
        {
            Right[Ridx].num = i;
            Right[Ridx++].start = stime;
        }
    }
    //나룻배 시뮬레이션
    while(leftcur < Lidx || rightcur < Ridx)
    {
        int bcount = 0;
        //왼쪽 정박장
        if(bflag == 0)
        {
            //대기 인원 있는지 체크 있다면 배에 태울수 있는 만큼 태운다
            while(Left[leftcur].start <= Time)
            {
                if(bcount == M || leftcur >= Lidx)
                {
                    break;
                }
                result[Left[leftcur++].num] = Time + t;
                bcount++;
            }
            //대기 인원 없을때
            if(bcount == 0)
            {
                //다음 손님이 왼쪽 정박장에 더 빨리 도착할 경우
                if(Left[leftcur].start <= Right[rightcur].start)
                {
                    //시간을 더빨리 도착하는 손님의 시간으로 맞춤
                    Time = Left[leftcur].start - t;
                    bflag = !bflag;
                }
                else
                {
                    //손님이 오른쪽 정박장에 더 빨리 도착했을때 시간을 현재시간이랑 도착 시간중에 큰걸로 맞춤
                    Time = max(Time, Right[rightcur].start);
                }
            }
            //배가 강을 타고 이동한 시간 더해준다
            Time += t;
            //왼쪽 정박장에서 오른쪽 정박장으로 바뀜
            bflag = !bflag;
        }
        //오른쪽 정박장 (위에 소스랑 같다)
        else
        {
            while(Right[rightcur].start <= Time)
            {
                if(bcount == M || rightcur >= Ridx)
                {
                    break;
                }
                result[Right[rightcur++].num] = Time + t;
                bcount++;
            }
            if(bcount == 0)
            {
                if(Left[leftcur].start >= Right[rightcur].start)
                {
                    Time = Right[rightcur].start - t;
                    bflag = !bflag;
                }
                else
                {
                    Time = max(Time, Left[leftcur].start);
                }
            }
            Time += t;
            bflag = !bflag;
        }
    }
    for(int i = 0; i < N; i++)
    {
        printf("%d\n", result[i]);
    }
}