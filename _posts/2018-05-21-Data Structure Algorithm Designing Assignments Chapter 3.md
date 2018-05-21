---
layout: post
title: Data Structure Algorithm Designing Assignments Chapter 3
description: "my own source codes of Algorithm Designing Assignment in Data Structure"
categories: [Data-Structure]
tags: [C]
redirect_from:
  - /2018/04/11/
---
# Data Structure Algorithm Designing Assignments Chapter 3

    {% highlight ruby %}
	3.15.c
    #include <stdio.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    #define N 100
    typedef int SElemType;
    typedef enum{Left,Right}StackName;
    typedef struct
    {
        SElemType s[N];
        int t[2];
    }TWStack;
    void Inistack_3_15(TWStack *S);
    Status Push_3_15(TWStack *S,StackName name,SElemType x);
    Status Pop_3_15(TWStack *S,StackName name,SElemType *x);
    void Output_3_15(TWStack S,StackName name);
    int main(void)
    {
        printf("I don't want to debug literally :(\n");
        return 0;
    }
    void Inistack_3_15(TWStack *S)
    {
        (*S).t[Left] = -1;
        (*S).t[Right] = N;
    }
    Status Push_3_15(TWStack *S,StackName name,SElemType x)
    {
        if((*S).t[Left]+1 == (*S).t[Right])
            return ERROR;
        switch(name)
        {
        case Left:
            (*S).t[name]++;
            break;

        case Right:
            (*S).t[name]--;
            break;
        }
        (*S).s[(*S).t[name]] = x;
        return OK;
    }
    Status Pop_3_15(TWStack *S,StackName name,SElemType *x)
    {
        switch(name)
        {
        case Left:
            if((*S).t[name] == -1)
                return ERROR;
            *x = (*S).s[(*S).t[name]];
            (*S).t[name]--;
            break;

        case Right:
            if((*S).t[name] == N)
                return ERROR;
            *x = (*S).s[(*S).t[name]];
            (*S).t[name]++;
            break;
        }
    }
    void Output_3_15(TWStack S,StackName name)
    {
        int i;
        switch(name)
        {
        case Left:
            for(i = 0;i<S.t[name];i++)
                printf("%d ",S.s[i]);
            break;

        case Right:
            for(i=N-1;i>=S.t[name];i--)
                printf("%d ",S.s[i]);
            break;
        }
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	3.16.c
    #include <stdio.h>
    #include "SequenceStack.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    Status Algo_3_16(char *En,char Con[]);
    int main(void)
    {
        printf("I don't want to debug literally :(\n");
        return 0;
    }
    Status Algo_3_16(char *En,char Con[])
    {
        int i,j;
        SqStack S;
        SElemType_Sq e;
        InitStack_Sq(&S);
        i = j =0;
        while(En[j])
        {
            if(En[i]=='H')
            {
                Push_Sq(&S,En[i]);
                Con[j++] = 'I';
            }
            if(En[i]=='S')
            {
                Push_Sq(&S,En[i]);
                Con[j++] = 'I';
                Con[j++] = 'O';
            }
            i++;
        }
        while(!StackEmpty_Sq(S))
        {
            Pop_Sq(&S,&e);
            Con[j++]='O';
        }
        Con[j]='\0';
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	3.17.c
    #include <stdio.h>
    #include "SequenceStack.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    Status Algo_3_17(char *s);
    int main(void)
    {

    }
    Status Algo_3_17(char *s)
    {
        SqStack S;
        SElemType_Sq e;
        int i;

        InitStack_Sq(&S);
        i=0;

        while(s[i]!='@'&&s[i]!='&')
        {
            Push_Sq(&S,s[i]);
            i++;
        }
        if(s[i]!='@')
        {
            i++;
            while(!StackEmpty_Sq(S)&& s[i]!='@')
            {
                Pop_Sq(&S,&e);
                if(s[i]!=e)
                    return ERROR;
                i++;
            }
        }
        if(StackEmpty_Sq(S)&&s[i]=='@')
            return OK;
        else
            return ERROR;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	3.18.c
    #include <stdio.h>
    #include "SequenceStack.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    Status Algo_3_18(char *s);
    int main(void)
    {
        char *s = "1*(2+3*(+6/(2+4)))";
        if(Algo_3_18(s))
            printf("Match.\n");
        else
            printf("Not Match.\n");
        return 0;
    }
    Status Algo_3_18(char *s)
    {
        SqStack S;
        SElemType_Sq e;
        int i;
        InitStack_Sq(&S);
        i = 0;
        while(s[i])
        {
            if(s[i]=='(')
                Push_Sq(&S,s[i]);
            else if(s[i]==')')
            {
                if(StackEmpty_Sq(S))
                    return ERROR;
                Pop_Sq(&S,&e);
            }
            i++;
        }
        if(StackEmpty_Sq(S))
            return OK;
        else
            return ERROR;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	3.19.c
    #include <stdio.h>
    #include "SequenceStack.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    Status Algo_3_19(char *s);
    Status match_3_19(char a,char b);
    int main(void)
    {
        char *s = "1+{2+[3*(2+3)*5]}";
        if(Algo_3_19(s))
            printf("Match.\n");
        else
            printf("Not Match.\n");
        return 0;
    }

    Status Algo_3_19(char *s)
    {
        SqStack S;
        SElemType_Sq e;
        int i;
        InitStack_Sq(&S);
        i=0;
        while(s[i])
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
                Push_Sq(&S,s[i]);
            if(s[i]==')'||s[i]==']'||s[i]=='}')
            {
                if(StackEmpty_Sq(S))
                    return ERROR;
                Pop_Sq(&S,&e);
                if(!match_3_19(e,s[i]))
                    return ERROR;
            }
            i++;
        }
        if(StackEmpty_Sq(S))
            return OK;
        else
            return ERROR;
    }
    Status match_3_19(char a,char b)
    {
        switch(a)
        {
        case '(':
            if(b!=')')
                return ERROR;
            break;
        case '[':
            if(b!=']')
                return ERROR;
            break;
        case '{':
            if(b!='}')
                return ERROR;
            break;
        default:
            return ERROR;
        }
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	3.20.c
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    #define SLEEPTIME 2
    #define ROW 10
    #define COL 17

    typedef enum{East,South,West,North}Direction;
    typedef enum{Color_1,Color_2,Color_3}Color;
    typedef struct
    {
        int x;
        int y;
        int di;
    }SElemType;

    void Algo_3_20(int g[][COL],SElemType start);
    void InitGrap(int g[][COL],SElemType *start);
    void PaintGrap(int g[][COL]);
    void ShowGrap(int g[][COL]);
    Status Pass(SElemType e,int g[][COL]);
    void Mark(SElemType *e,int g[][COL]);
    Status NextPos(SElemType *e);
    Status IsCross(SElemType e);

    int main(void)
    {
        int g[ROW][COL];
        SElemType start;
        InitGrap(g,&start);
        PaintGrap(g);
        Algo_3_20(g,start);
        return 0;
    }

    void Algo_3_20(int g[][COL],SElemType start)
    {
        SElemType e;
        SElemType stack[10000];
        int top = -1;
        e = start;
        do
        {
            if(Pass(e,g))
            {
                Mark(&e,g);
                ShowGrap(g);
                stack[++top] = e;
                NextPos(&e);
            }
            else
            {
                if(top!=-1)
                {
                    e = stack[top--];
                    while(e.di==North && top!=-1)
                        e=stack[top--];
                    if(e.di<North)
                    {
                        e.di++;
                        stack[++top] = e;
                        NextPos(&e);
                    }
                }
            }
        }while(top!= -1);

    }

    void InitGrap(int g[][COL],SElemType *start)
    {
        int i,j;
        int a[ROW][COL]={
                        {0,0,0,1,0,1,0,1,0,1,0,0,1,1,1,0,1},
                        {0,0,0,1,0,1,0,1,0,1,0,0,1,1,1,0,1},
                        {2,0,0,1,0,1,2,1,0,1,2,0,1,1,1,0,1},
                        {0,0,0,2,0,1,0,1,0,1,0,0,1,1,1,0,1},
                        {0,2,0,1,0,1,2,1,0,1,0,0,1,1,1,0,1},
                        {2,0,0,1,0,1,0,1,0,1,0,0,1,1,1,0,1},
                        {0,0,0,1,0,1,2,1,0,1,2,0,1,1,1,0,1},
                        {2,2,0,1,0,1,0,2,0,1,0,0,1,1,1,0,1},
                        {0,0,0,1,0,1,0,1,0,1,2,0,1,1,1,0,1},
                        {0,0,0,1,0,1,0,1,0,1,0,0,1,1,1,0,1}
                        };
        for(i=0;i<ROW;i++)
        {
            for(j=0;j<COL;j++)
                g[i][j]=a[i][j];
        }
        (*start).x = 9;
        (*start).y = 8;
        (*start).di = East;
    }
    void PaintGrap(int g[][COL])
    {
        int i,j;
        for(i=0;i<ROW;i++)
        {
            for(j=0;j<COL;j++)
            {
                if(g[i][j]==Color_1)
                    printf("*");
                if(g[i][j]==Color_2)
                    printf(" ");
                if(g[i][j]==Color_3)
                    printf("^");
            }
        }
    }
    void ShowGrap(int g[][COL])
    {
        //Wait(SLEEPTIME);
        system("cls");
        PaintGrap(g);
    }
    Status Pass(SElemType e,int g[][COL])
    {
        int x = e.x;
        int y = e.y;
        if(g[x][y]==1)
            return YES;
        else
            return NO;
    }
    void Mark(SElemType *e,int g[][COL])
    {
        int x = (*e).x;
        int y = (*e).y;
        (*e).di = East;
        g[x][y]=2;
    }
    Status NextPos(SElemType *e)
    {
        SElemType tmp;
        tmp = *e;
        switch(tmp.di)
        {
            case East:(tmp.y)++;
                break;
            case South:(tmp.x)++;
                break;
            case West:(tmp.y)--;
                break;
            case North:(tmp.x)--;
                break;
            default:
                return FALSE;
        }
        if(IsCross(tmp))
        {
            ++(*e).di;
            NextPos(e);
        }
        else
            *e = tmp;
        return TRUE;
    }
    Status IsCross(SElemType e)
    {
        int x = e.x;
        int y = e.y;
        if(x<0||y<0||x>ROW-1||y>COL-1)
            return YES;
        else
            return NO;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	3.21.c
    #include <stdio.h>
    #include <ctype.h>
    #include "SequenceStack.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    #define LEN 80

    Status Algo_3_21(char *s,char c[]);
    int Priority(char a,char b);
    int main(void)
    {
        char c[LEN];
        char *s = "a+b*c-d";
        printf("The expression is: ");
        puts(s);
        printf("\n");
        printf("The RPN of this expression is:");
        Algo_3_21(s,c);
        puts(c);
        return 0;
    }

    Status Algo_3_21(char *s,char c[])
    {
        SqStack S;
        SElemType_Sq e;
        int i,j;

        InitStack_Sq(&S);
        j = i = 0;

        while(s[i]!='\0')
        {
            if(isalpha(s[i]))
                c[j++]=s[i];
            else
            {
                while(!StackEmpty_Sq(S))
                {
                    GetTop_Sq(S,&e);
                    if(Priority(e,s[i]))
                    {
                        Pop_Sq(&S,&e);
                        c[j++]=e;
                    }
                    else
                        break;
                }
                Push_Sq(&S,s[i]);
            }
            i++;
        }
        while(!StackEmpty_Sq(S))
        {
            Pop_Sq(&S,&e);
            c[j++]=e;
        }
        c[j]='\0';
    }
    int Priority(char a,char b)
    {
        switch(a)
        {
        case '*':
        case '/':
            return 1;
            break;

        case '+':
        case '-':
            if(b == '*'|| b == '/')
                return 0;
            else
                return 1;
            break;
        }
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	3.22.c
    #include <stdio.h>
    #include <ctype.h>
    #include "SequenceStack.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    Status Algo_3_22(char *s,SElemType_Sq *result);
    char Operate(char a,char c,char b);
    int main(void)
    {
        char *s = "123*+4-";
        SElemType_Sq result;
        printf("The expression is: ");
        puts(s);
        printf("\n");
        printf("The result of this expression is:");
        Algo_3_22(s,&result);
        printf("%d.\n",result-48);
        return 0;
    }

    Status Algo_3_22(char *s,SElemType_Sq *result)
    {
        SqStack S;
        SElemType_Sq e1,e2;
        int i;

        InitStack_Sq(&S);
        i = 0;

        while(s[i])
        {
            if(isdigit(s[i]))
                Push_Sq(&S,s[i]);
            else
            {
                Pop_Sq(&S,&e2);
                Pop_Sq(&S,&e1);
                Push_Sq(&S,Operate(e1,s[i],e2));
            }
            i++;
        }
        Pop_Sq(&S,result);
        if(!StackEmpty_Sq(S))
            return ERROR;
        else
            return OK;
    }

    char Operate(char a,char c,char b)
    {
        switch(c)
        {
        case '+':
            return (a-48)+(b-48)+48;
            break;
        case '-':
            return (a-48)-(b-48)+48;
            break;
        case '*':
            return (a-48)*(b-48)+48;
            break;
        case '/':
            return (a-48)/(b-48)+48;
            break;
        }
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	3.23.c
    #include <stdio.h>
    #include <ctype.h>
    #include "SequenceStack.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    char Operate(char a,char c,char b);
    Status Algo_3_23(char *s,SElemType_Sq *result);
    int main(void)
    {
        char *s = "123*+4-";
        SElemType_Sq result;
        printf("The expression is: ");
        puts(s);
        printf("\n");
        if(Algo_3_23(s,&result)==OK)
            printf("The expression is a correct NPR.\n");
        else if (Algo_3_23(s,&result)==ERROR)
            printf("The expression is not a correct NPR.\n");
        return 0;
    }
    Status Algo_3_23(char *s,SElemType_Sq *result)
    {
        SqStack S;
        SElemType_Sq e1,e2;
        int i;

        InitStack_Sq(&S);
        i = 0;

        while(s[i])
        {
            if(isdigit(s[i]))
                Push_Sq(&S,s[i]);
            else
            {
                if(StackEmpty_Sq(S))
                    return ERROR;
                Pop_Sq(&S,&e2);
                if(StackEmpty_Sq(S))
                    return ERROR;
                Pop_Sq(&S,&e1);
                Push_Sq(&S,Operate(e1,s[i],e2));
            }
            i++;
        }
        Pop_Sq(&S,result);
        if(!StackEmpty_Sq(S))
            return ERROR;
        else
            return OK;
    }
    char Operate(char a,char c,char b)
    {
        switch(c)
        {
        case '+':
            return (a-48)+(b-48)+48;
            break;
        case '-':
            return (a-48)-(b-48)+48;
            break;
        case '*':
            return (a-48)*(b-48)+48;
            break;
        case '/':
            return (a-48)/(b-48)+48;
            break;
        }
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	3.24.c
    #include <stdio.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    int Algo_3_24(int m,int n);
    int main(void)
    {
        int m,n;
        m=5;
        n=2;
        printf("g(%d,%d) = %d\n",m,n,Algo_3_24(m,n));
        printf("\n");
        return 0;
    }

    int Algo_3_24(int m,int n)
    {
        if(m<0||n<0)
            exit(ERROR);
        if(m==0)
            return 0;
        else
            return Algo_3_24(m-1,2*n)+n;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	3.25.c
    #include <stdio.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    int Algo_3_25(int n);
    int main(void)
    {
        int n;
        n=10;
        printf("F(%d) = %d\n",n,Algo_3_25(n));
        printf("\n");
        return 0;
    }

    int Algo_3_25(int n)
    {
        if(n<0)
            exit(ERROR);
        if(n==0)
            return 1;
        else
            return Algo_3_25(n/2)*n;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	3.26.c
    #include <stdio.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    float Algo_3_26(float A,float p,float e);
    int main(void)
    {
        float A=50;
        float p=1;
        float e=0.000001;
        printf("sqrt(50) = %f\n",Algo_3_26(A,p,e));
        printf("\n");
        return 0;
    }

    float Algo_3_26(float A,float p,float e)
    {
        if(A<0.0)
            exit(ERROR);
        if(abs(p*p-A)<e)
            return p;
        else
            return Algo_3_26(A,(p+A/p)/2,e);
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	3.27.c
    #include <stdio.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    typedef struct
    {
        int mval;
        int nval;
    }Stack;
    int Algo_3_27_1(int m,int n);
    int Algo_3_27_2(int m,int n);

    int main(void)
    {
        int m=3;
        int n=2;
        printf("Hello!\n");
        printf("The answer is: %d.\n",Algo_3_27_1(m,n));
        printf("The answer is: %d.\n",Algo_3_27_2(m,n));
        return 0;
    }
    int Algo_3_27_1(int m,int n)
    {
        int akm;
        if(m==0)
            akm = n+1;
        else if(n==0)
            akm = Algo_3_27_1(m-1,1);
        else
            akm = Algo_3_27_1(m-1,Algo_3_27_1(m,n-1));
        return akm;
    }

    int Algo_3_27_2(int m,int n)
    {
        Stack s[1000];
        int top=0;
        s[top].mval=m;
        s[top].nval=n;
        do
        {
            while(s[top].mval)
            {
                while(s[top].nval)
                {
                    top++;
                    s[top].mval=s[top-1].mval;
                    s[top].nval=s[top-1].nval-1;
                }
                s[top].mval--;
                s[top].nval=1;
            }
            if(top>0)
            {
                top--;
                s[top].mval--;
                s[top].nval=s[top+1].nval+1;
            }
        }while(top!=0||s[top].mval!=0);
        return s[top].nval+1;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	3.28.c
    #include <stdio.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    typedef int QElemType;
    typedef struct QNode
    {
        QElemType data;
        struct QNode *next;
    }QNode;
    typedef QNode* QueuePtr;

    typedef struct
    {
        QueuePtr rear;
    }LinkQueue;

    Status InitQueue_3_28(LinkQueue *Q);
    Status EnQueue_3_28(LinkQueue *Q,QElemType e);
    Status DeQueue_3_28(LinkQueue *Q,QElemType *e);
    void Output_3_28(LinkQueue Q);

    int main(void)
    {
        LinkQueue Q;
        int i;
        QElemType e;
        InitQueue_3_28(&Q);
        for(i=1;i<=5;i++)
        {
            EnQueue_3_28(&Q,i);
            Output_3_28(Q);
            printf("\n");
        }
        printf("\n\n");
        for(i=1;i<=5;i++)
        {
            DeQueue_3_28(&Q,&e);
            Output_3_28(Q);
            printf("\n");
        }
        printf("\n");
        return 0;
    }

    Status InitQueue_3_28(LinkQueue *Q)
    {
        (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
        if(!(*Q).rear)
            exit(OVERFLOW);
        (*Q).rear->next = (*Q).rear;
        return OK;
    }

    Status EnQueue_3_28(LinkQueue *Q,QElemType e)
    {
        QueuePtr p;
        p = (QueuePtr)malloc(sizeof(QNode));
        if(!p)
            exit(OVERFLOW);
        p->data = e;
        p->next = (*Q).rear->next;
        (*Q).rear->next = p;
        (*Q).rear = p;
        return OK;
    }

    Status DeQueue_3_28(LinkQueue *Q,QElemType *e)
    {
        QueuePtr h,p;
        h = (*Q).rear->next;
        if(h->next == (*Q).rear->next)
            return ERROR;
        p=h->next;
        *e = p->data;
        h->next = p->next;
        if(p == (*Q).rear)
            (*Q).rear = h;
        free(p);
        return OK;
    }

    void Output_3_28(LinkQueue Q)
    {
        QueuePtr p;
        for(p=Q.rear->next->next;p!=Q.rear->next;p=p->next)
            printf("%d ",p->data);
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	3.29.c
    #include <stdio.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    // SequenceQueue
    #define MAXQSIZE 100

    typedef int QElemType;
    typedef struct
    {
        QElemType *base;
        int front;
        int rear;
        int tag;
    }SqQueue;

    Status InitQueue_3_29(SqQueue *Q);
    Status EnQueue_3_29(SqQueue *Q,QElemType e);
    Status DeQueue_3_29(SqQueue *Q,QElemType *e);
    void Output_3_29(SqQueue Q);
    int main(void)
    {
        return 0;
    }

    Status InitQueue_3_29(SqQueue *Q)
    {
        (*Q).base = (QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
        if(!(*Q).base)
            exit(OVERFLOW);
        (*Q).tag=0;
        (*Q).front = (*Q).rear = 0;
        return OK;
    }

    Status EnQueue_3_29(SqQueue *Q,QElemType e)
    {
        if((*Q).rear == (*Q).front && (*Q).tag == 1)
            return ERROR;
        (*Q).base[(*Q).rear] = e;
        (*Q).rear = ((*Q).rear+1)%MAXQSIZE;
        if((*Q).rear = (*Q).front)
            (*Q).tag = 1;
        return OK;
    }

    Status DeQueue_3_29(SqQueue *Q,QElemType *e)
    {
        if((*Q).rear == (*Q).front && (*Q).tag == 0)
            return ERROR;
        *e = (*Q).base[(*Q).front];
        (*Q).front = ((*Q).front+1)%MAXQSIZE;
        if((*Q).rear == (*Q).front)
            (*Q).tag = 0;
        return OK;
    }
    void Output_3_29(SqQueue Q)
    {
        int i;
        for(i=Q.front;i!=Q.rear;i=(i+1)%MAXQSIZE)
            printf("%d ",Q.base[i]);
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	3.30.c
    #include <stdio.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    // SequenceQueue
    #define MAXQSIZE 5

    typedef int QElemType;
    typedef struct
    {
        QElemType *base;
        int rear;
        int length;
    }SqQueue;

    Status InitQueue_3_30(SqQueue *Q);
    Status EnQueue_3_30(SqQueue *Q,QElemType e);
    Status DeQueue_3_30(SqQueue *Q,QElemType *e);
    void Output_3_30(SqQueue Q);
    int main(void)
    {
        return 0;
    }

    Status InitQueue_3_30(SqQueue *Q)
    {
        (*Q).base = (QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
        if(!(*Q).base)
            exit(OVERFLOW);
        (*Q).length = 0;
        (*Q).rear = 0;
        return OK;
    }

    Status EnQueue_3_30(SqQueue *Q,QElemType e)
    {
        if((*Q).length == MAXQSIZE)
            return ERROR;
        (*Q).base[(*Q).rear] = e;
        (*Q).rear = ((*Q).rear+1)%MAXQSIZE;
        (*Q).length++;
        return OK;
    }

    Status DeQueue_3_30(SqQueue *Q,QElemType *e)
    {
        int head;
        head = ((*Q).rear + MAXQSIZE - (*Q).length)%MAXQSIZE;
        if(!(*Q).length)
            return ERROR;
        *e = (*Q).base[head];
        (*Q).length--;
        return OK;
    }
    void Output_3_30(SqQueue Q)
    {
        int i,head;
        head = (Q.rear - Q.length +MAXQSIZE)%MAXQSIZE;
        for(i=head;i<=Q.length;head=(head+1)%MAXQSIZE,i++)
            printf("%d ",Q.base[head]);
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	3.31.c
    #include <stdio.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    #include "3.30.c"
    #include "SequenceStack.c"

    Status Algo_3_31(char c[])
    {
        SqStack S;
        SqQueue Q;
        SElemType_Sq e1;
        QElemType e2;
        int i;

        InitQueue_3_30(&Q);
        InitStack_Sq(&S);

        for(i=0;c[i]!='@';i++)
        {
            EnQueue_3_30(&Q,c[i]);
            Push_Sq(&S,c[i]);
        }
        while(!StackEmpty_Sq(S)&&!Q.length)
        {
            Pop_Sq(&S,&e1);
            DeQueue_3_30(&Q,&e2);
            if(e1!=e2)
                return ERROR;
        }
        if(StackEmpty_Sq(S)&&Q.length==0)
            return OK;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	3.32.c
    #include <stdio.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    #include "3.30.c"
    #include "SequenceStack.c"

    #define MAX 100000

    Status Algo_3_32(int k,int fib[],int *n)
    {
        int i,sum;
        SqQueue Q;
        QElemType e;

        if(k<2)
            return ERROR;
        InitQueue_3_30(&Q);
        for(i=0;i<=k-2;i++)
            EnQueue_3_30(&Q,0);
        EnQueue_3_30(&Q,1);
        for(i=0;i<=k-1;i++)
            fib[i]=Q.base[i];
        *n = k-2;
        do
        {
            (*n)++;
            for(int j=0;j<Q.length;j++)
                sum+=Q.base[j];
            fib[(*n)+1]=sum;
            Q.base[Q.rear] = sum;
            Q.rear = (Q.rear+1)%MAXQSIZE;
        }while(sum<=MAX);
        return OK;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	3.33.c
    #include <stdio.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    Status EnQueue_3_33(CSqQueue *Q,QElemType_CSq e)
    {
        int a,b;
        a = (*Q).base[(*Q).front];
        b = (*Q).base[((*Q).rear-1+MAXQSIZE)%MAXQSIZE];
        if(((*Q).rear+1)%MAXQSIZE==(*Q).front)
            return ERROR;
        if(QueueEmpty_CSq(*Q)||e>=(a+b)/2)
        {
            (*Q).base[(*Q).rear] = e;
            (*Q).rear = ((*Q).rear+1)%MAXQSIZE;
        }
        else
        {
            (*Q).front = ((*Q).front-1+MAXQSIZE)%MAXQSIZE;
            (*Q).base[(*Q).front] = e;
        }
        return OK;
    }
    Status DeQueue_3_33(CSqQueue *Q, QElemType_CSq *e)
    {
        if(DeQueue_CSq(Q,e))
            return OK;
        else
            return ERROR;
    }
    void PrintElem(QElemType_CSq e)
    {
        printf("%d ",e);
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	3.34.c
    #include <stdio.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    Status Algo_3_34(char *En,char Con[])
    {
        int i,j;
        LinkQueue Q;
        QElemType e;
        InitQueue(&Q);
        i = j =0;
        while(En[i])
        {
            if(En[i]=='P')
                Con[j++]='L';
            if(En[i]=='S')
            {
                EnQueue_3_34(&Q,En[i],0);
                Con[j++]='E';
            }
            if(En[i]=='H')
            {
                EnQueue_3_34(&Q,En[i],1);
                Con[j++]='A';
            }
            i++;
        }
        while(!QueueEmpty(Q))
        {
            DeQueue(&Q,&e);
            Con[j++] = 'D';
        }
        Con[j]='\0';
    }
    Status EnQueue_3_34(LinkQueue *Q,QElemType e,int di)
    {
        QueuePtr p;
        p = (QueuePtr)malloc(sizeof(QNode));
        if(!p)
            exit(OVERFLOW);
        p->data = e;
        if(di==0)
        {
            p->next = (*Q).front->next;
            (*Q).front->next = p;
        }
        if(di==1)
        {
            p->next = (*Q).rear->next;
            (*Q).rear->next = p;
            (*Q).rear = p;
        }
        return OK;
    }
    {% endhighlight %}

---

If you find there are faults in the source codes, any method connecting with me is welcomed.
