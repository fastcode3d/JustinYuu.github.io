---
layout: post
title: Data Structure Algorithm Designing Assignments Chapter 1
description: "my own source codes of Algorithm Designing Assignment in Data Structure"
categories: [Data-Structure]
tags: [C]
redirect_from:
  - /2018/04/11/
---
# Data Structure Algorithm Designing Assignments Chapter 1

    {% highlight ruby %}
    1.16.c
    #include <stdio.h>
    int main(void)
    {
        int a=0;
        int b=0,c=0;
        int temp;
        printf("Please input three numbers:\n");
        while(scanf("%d %d %d",&a,&b,&c)==3)
        {
            if(a<b)
            {
                temp = b;
                b = a;
                a = temp;
            }
            if(b<c)
            {
                temp = c;
                c = b;
                b = temp;
            }
            if(a<b)
            {
                temp = b;
                b = a;
                a = temp;
            }
            printf("%d %d %d\n",a,b,c);
            return 0;
        }
    }
    {% endhighlight %}
---

    {% highlight ruby %}
    1.17.c
    #include <stdio.h>
    #include <stdlib.h>
    #define OVERFLOW -2
    int Fibonacci(int k,int m);
    int main(void)
    {
        int n=Fibonacci(1,10);
        printf("%d",n);
        return 0;
    }
    int Fibonacci(int k,int m)
    {
        int *a=NULL;
        a=(int*)malloc((m)*sizeof(int));
        if(k<1||m<0)
            exit(OVERFLOW);
        int i,j;
        for(i=0;i<k;i++)
        {
            if(i<k-1)
                a[i]=0;
            else
                a[i]=1;
        }
        for(i=k;i<=m;i++)
        {
            for(j=i-1,a[i]=0;j>=i-k;j--)
                a[i]+=a[j];
        }
        return a[m];
    }
     {% endhighlight %}
     
---

    {% highlight ruby %}
    1.18.c
    #include <stdio.h>
    typedef enum{A,B,C,D,E} SchoolName;
    typedef enum{Female,Male}SexType;
    typedef struct{
        char event[3];
        SexType sex;
        SchoolName school;
        int score;
    }Component;
    typedef struct{
        int MaleSum;
        int FemaleSum;
        int TotalSum;
    }Sum;
    Sum SumScore(SchoolName sn,Component a[],int n)
    {
        Sum temp;
        temp.MaleSum = 0;
        temp.FemaleSum = 0;
        temp.TotalSum = 0;
        int i;
        for(i=0;i<n;i++)
        {
            if(a[i].school==sn)
            {
                if(a[i].sex==Male)
                    temp.MaleSum+=a[i].score;
                if(a[i].sex==Female)
                    temp.FemaleSum+=a[i].score;
            }
        }
        temp.TotalSum = temp.MaleSum + temp.FemaleSum;
        return temp;
    }
     {% endhighlight %}
     
---

    {% highlight ruby %}
    1.19.c
    #include <stdio.h>
    #include <limits.h>
    #include <stdlib.h>
    #define arrsize 20
    #define maxint INT_MAX
    #define OK 1
    #define OVERFLOW -2
    #define ERROR 0
    typedef int Status;
    Status cal(int i,int *a);
    int main(void)
    {
        int i,a[arrsize];
        i = 6;
        if(cal(i,a)==OK)
            printf("i=%d,a[i-1]=%d\n",i,a[i-1]);
        return 0;
    }
    Status cal(int i,int *a)
    {
        if(i<1||i>arrsize)
            exit(ERROR);
        for(int j=1;j<=i;j++)
        {
            if(j==1)
                a[j-1]=2;
            else
            {
                if(maxint/(2*j)<a[j-2])
                    exit(OVERFLOW);
                a[j-1]=2*j*a[j-2];
            }
        }
        return(OK);
    }
      {% endhighlight %}
      
---

    {% highlight ruby %}
    1.20.c
    #include <stdio.h>
    int calpoly(int *a,int i,double x,int n)
    {
        if(i>0)
            return a[n-i]+calpoly(a,i-1,x,n)*x;
        else
            return a[n];
    }
      {% endhighlight %}
      
---


  If you find there are faults in the source codes, any method connecting with me is welcomed.
