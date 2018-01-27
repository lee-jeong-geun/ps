
/*
트라이를 이용한 방식과 정렬을 이용한 방식이 있다.
트라이를 이용하는 방식은 트라이에 저장을 하면서 탐색을 할때 현재 문자열이 다른 문자열에 속해
있거나 현재 문자열에 다른 문자열이 속해 있다면 일관성이 없다는 것이다.
정렬을 이용한 방식은 문자열들을 오름차순으로 정렬후 현재 문자열과 다음 문자열의 앞부분은 같고
현재 문자열 길이가 짧은걸 찾는 방식이다.
*/

//트라이 이용
#include <cstdio>
#include <iostream>
using namespace std;
typedef struct node
{
    int flag;
    node *link[15];
    ~node()
    {
        for(int i = 0; i < 10; i++)
        {
            delete 
        }
    }
}Node;

int n, result;
char phone[15];
Node *Root;

//노드 생성
Node* createNode(int flag)
{
    Node *newnode = new Node();
    newnode->flag = flag;
    for(int i = 0; i < 10; i++)
    {
        newnode->link[i] = NULL;
    }
    return newnode;
}

//메모리를 삭제해 주는 재귀 함수(소멸자로 대체 가능)
void initfunc(Node *cur)
{
    for(int i = 0; i < 10; i++)
    {
        if(cur->link[i] != NULL)
        {
            initfunc(cur->link[i]);
            cur->link[i] = NULL;
        } 
    }
    delete cur;
}

//초기화
void init()
{
    if(Root == NULL)
    {
        Root = createNode(-1);
    }
    else
    {
        for(int i = 0; i < 10; i++)
        {
            if(Root->link[i] != NULL)
            {
                initfunc(Root->link[i]);
                Root->link[i] = NULL;
            }
        }
    }
    result = 0;
}

//트라이에 푸쉬
void insertNode(Node *cur, int depth)
{
    //다른 문자열이 현재 문자열에 속해 있는 경우
    if(cur->flag == 1)
    {
        result = 1;
        return;
    }
    //현재 문자열이 마지막이라면 체크
    if(phone[depth] == '\0')
    {
        cur->flag = 1;
        return;
    }
    //노드 생성
    if(cur->link[phone[depth] - '0'] == NULL)
    {
        cur->link[phone[depth] - '0'] = createNode(0);
    }
    //현재 문자열의 문자가 트라이에 존재하는데 현재 문자열의 마지막이라면 일관성X
    else
    {
        if(phone[depth + 1] == '\0')
        {
            result = 1;
            return;
        }
    }
    Node *next;
    next = cur->link[phone[depth] - '0'];
    insertNode(next, depth + 1);
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int testcase = 0; testcase < t; testcase++)
    {
        init();
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%s", phone);
            insertNode(Root, 0);
        }
        if(result == 1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }      
    }
}


//정렬 이용
#include <cstdio>
#include <iostream>
using namespace std;
int n, flag;
char phone[10005][15];

//초기화
void init()
{
  flag = 0;
  for(int i = 0; i < 10005; i++)
  {
    phone[i][0] = '\0';
  }
}

//문자열 길이 구하는 함수
int strlen(char *str1)
{
  int len = 0;
  while(*str1 != 0)
  {
    len++;
    str1++;
  }
  return len;
}

//문자열 비교
int strcmp(char *str1, char *str2)
{
  while(*str1 != 0 || *str2 != 0)
  {
    if(*str1 > *str2)
    {
      return 1;
    }
    else if(*str1 < *str2)
    {
      return -1;
    }
    str1++;
    str2++;
  }
  return 0;
}

//문자열 복사
void strcpy(char *str1, char *str2)
{
  int idx = 0;
  while(*str2 != 0)
  {
    str1[idx] = *str2;
    str2++;
    idx++;
  }
  str1[idx] = '\0';
}

//정렬 비교 함수
bool comp(char *str1, char *str2)
{
  if(strcmp(str1, str2) == 1)
  {
    return 0;
  }
  if(strcmp(str1, str2) == -1)
  {
    return 1;
  }
  return 0;
}

void swap(char *str1, char *str2)
{
  char temp[15];
  strcpy(temp, str1);
  strcpy(str1, str2);
  strcpy(str2, temp);
}

//퀵정렬
void sort(int left, int right)
{
  char pivot[15];
  int leftidx, rightidx;
  leftidx = left;
  rightidx = right;
  strcpy(pivot, phone[(left + right) / 2]);
  while(leftidx <= rightidx)
  {
    while(comp(phone[leftidx], pivot))
    {
      leftidx++;
    }
    while(comp(pivot, phone[rightidx]))
    {
      rightidx--;
    }
    if(leftidx <= rightidx)
    {
      swap(phone[leftidx], phone[rightidx]);
      leftidx++;
      rightidx--;
    }
  }
  if(left < rightidx)
  {
    sort(left, rightidx);
  }
  if(leftidx < right)
  {
    sort(leftidx, right);
  }
}

int main()
{
  int T;
  scanf("%d", &T);
  for(int testcase = 0; testcase < T; testcase++)
  {
    init();
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
      scanf("%s", phone[i]);
    }
    sort(0, n - 1);
    for(int i = 0; i < n - 1; i++)
    {
      int length, count = 0;
      length = strlen(phone[i]);
      for(int j = 0; j < length; j++)
      {
        //현재 문자열의 문자가 다음 문자열의 문자와 같으면 카운트
        if(phone[i][j] == phone[i + 1][j])
        {
          count++;
        }
      }
      카운트한 숫자가 현재 문자열과 같다면 일관성X
      if(count == length)
      {
        flag = 1;
        printf("NO\n");
        break;
      }
    }
    if(flag == 0)
    {
      printf("YES\n");
    }
  }
}