---
layout: post
title: "Programming Assignment of Discrete Mathematics Chapter 2"
description: "my own source codes of Programming Assignment in Discrete Mathematics "
categories: [Discrete Mathematics]
tags: [C]
redirect_from:
  - /2018/03/24/
---

# Programming Assignment of Discrete Mathematics Chapter 2


### Qusetion

1、	实现算法： 集合的交 并 差。
2、	集合A表示上课的学生，B为男生集合，C为女生集合，D为考试合格的同学。编程实现：
输入集合A B C D (用两位学号表示) 。
求出：没来上课的男生
     考试不及格的女生。
     没来上课且考试不及格的男生

### My solution

	{% highlight ruby %}
	student.cpp
    #include <stdio.h>
    #include <iostream>
    #include <set>
    int FindIntersaction(int a[],int b[],int len_a,int len_b);
    int FindUnion(int a[],int b[],int c[],int len_a,int len_b);
    int FindDeference(int a[],int b[],int len_a,int len_b);
    int main(void)
    {
        int a,b,c,d;
        int H[100]={0};
        int len_a,len_b,len_c,len_d;
        printf("Please input the number of students who came to class:\n");
        scanf("%d",&len_a);
        int A[len_a];
        printf("Please input those students' ID:\n");
        for(int i=0;i<len_a;i++)
        {
            scanf("%d",&A[i]);
        }
        printf("Please input the number of boys in the class:\n");
        scanf("%d",&len_b);
        int B[len_b];
        printf("Please input those students' ID:\n");
        for(int j=0;j<len_b;j++)
        {
            scanf("%d",&B[j]);
        }
        printf("Please input the number of girls in the class:\n");
        scanf("%d",&len_c);
        int C[len_c];
        printf("Please input those students' ID:\n");
        for(int k=0;k<len_c;k++)
        {
            scanf("%d",&C[k]);
        }
        printf("Please input the number of students who passed the exam:\n");
        scanf("%d",&len_d);
        int D[len_d];
        printf("Please input those students' ID:\n");
        for(int l=0;l<len_d;l++)
        {
            scanf("%d",&D[l]);
        }
        printf("The IDs of boys who didn't comes to class are(is): ");
        a=FindDeference(B,A,len_b,len_a);
        printf("The IDs of girls who didn't pass the exam are(is): ");
        b=FindDeference(C,D,len_c,len_d);
        printf("The IDs of boys who didn't pass the exam and didn't came to class are(is): ");
        c=FindUnion(A,D,H,len_a,len_d);
        d=FindDeference(B,H,len_b,c);

    }
    int FindIntersaction(int a[],int b[],int len_a , int len_b)
    {

        int c[len_a+len_b];
        int k=0;
        for(int i=0;i<len_a;i++)
        {
            for(int j=0;j<len_b;j++)
            {
                if(a[i]==b[j])
                {
                    c[k]=a[i];
                    k++;
                    break;
                }
            }
        }
        for(int n=0;n<(len_a+len_b);n++)
        {
            if(c[n]!=0)
                printf("%d ",c[n]);
        }
        printf("\n");
        return k;
    }
    int FindUnion(int a[],int b[],int c[],int len_a, int len_b)
    {
        int n;
        for(int i=0;i<len_a;i++)
        {
            c[i]=a[i];
            bool bFind = false;
            for(int j=0;j<len_b;j++)
            {
                if(a[i]==b[j])
                {
                    bFind = true;
                    break;
                }
            }
            if(!bFind)
            {
                c[len_b+n]=a[i];
                n++;
            }
        }
        /*for(int m=0;m<(len_a+len_b);m++)
        {
            if(c[m]!=0)
            printf("%d ",c[m]);
        }
        printf("\n");*/ //The output of function FindUnion().
        return n;
    }
    int FindDeference(int a[],int b[],int len_a,int len_b)
    {
        int n;
        for(int i=0;i<len_b;i++)
        {
            for(int j=0;j<len_a;j++)
            {
                if(a[j]==b[i])
                {
                    a[j]=0;
                    break;
                }
            }
        }
        for(int m=0;m<len_a;m++)
        {
            if(a[m]!=0)
            {
                printf("%d ",a[m]);
                n++;
            }
        }
        printf("\n");
        return n;
    }

	  {%endhighlight%}


### Reflection

This algorithm will call the count() function for each letter, which costs a lot. Besides, the circulation uses lots of *if* ,which literally ugly to read.

---
If you find any fault in this blog , any method connecting with me is available and welcomed.
