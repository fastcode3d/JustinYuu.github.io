---
layout: post
title: "Programming Assignment of Discrete Mathematics Chapter 4"
description: "my own source codes of Programming Assignment in Discrete Mathematics "
categories: [Discrete-Mathematics]
tags: [C]
redirect_from:
  - /2018/05/06/
---

# Programming Assignment of Discrete Mathematics Chapter 4


### Qusetion

(1)According to the given set and the given partial order relation, find the important elements of set ,which includes the largest element, the smallest element, the maximum element, and the minimum element.

(2)Divide X by using X's equivalence relation R .

### My solution

(1) The default equivanlence relation is <=, build the relation matrix of R and get the answer via relation matrix.

(2) The default equivanlence relation is mod(3), and the method is the same as quetion 1.
	
### Source code


		{% highlight ruby %}
		findelement.c
		#include <stdio.h>
		#include <stdbool.h>
		#define LEN 10
		void getRelationMatrix(int (*a)[LEN],int *b);
		int getAbsMaxEle(int (*a)[LEN], int *b);
		int getAbsMinEle(int (*a)[LEN], int *b);
		int getLocMaxEle(int (*a)[LEN], int *b);
		int getLocMinEle(int (*a)[LEN], int *b);
		int main(void)
		{
			int a[LEN][LEN];
			int b[LEN];
			int i;
			printf("Please input 10 numbers:\n");
			for(i=0;i<LEN;i++)
				scanf("%d",&b[i]);
			//int b[LEN]={1,2,3,4,5};
			//int a[LEN][LEN]={{1,0,0,0,0},{1,1,0,0,0},{1,1,1,0,0},{1,1,1,1,0},{1,1,1,1,1}};
			getRelationMatrix(a,b);
			printf("The absolute maximum number is %d.\n",getAbsMaxEle(a,b));
			printf("The absolute minimum number is %d.\n",getAbsMinEle(a,b));
			printf("The local maximum number is %d.\n",getLocMaxEle(a,b));
			printf("The local minimum number is %d.\n",getLocMinEle(a,b));
			return 0;
		}
		void getRelationMatrix(int (*a)[LEN],int *b)
		{
			int i,j;
			for(i=0;i<LEN;i++)
			{
				for(j=0;j<LEN;j++)
				{
					if(b[i]<=b[j])
						a[j][i]=1;
					else
						a[j][i]=0;
				}
			}
		}
		int getAbsMaxEle(int (*a)[LEN],int *b)
		{
			int i,j,Max;
			for(i=0;i<LEN;i++)
			{
				bool AbsMaxBlog = true;
				for(j=0;j<LEN;j++)
				{
					if(a[i][j]!=1)
					{
						AbsMaxBlog = false;
						break;
					}
				}
				if(AbsMaxBlog)
				{
					Max=b[i];
					break;
				}
			}
			return Max;
		}
		int getAbsMinEle(int (*a)[LEN],int * b)
		{
			int i,j,Min;
			for(i=0;i<LEN;i++)
			{
				bool AbsMinBlog = true;
				for(j=0;j<LEN;j++)
				{
					if(a[j][i]!=1)
					{
						AbsMinBlog = false;
						break;
					}
				}
				if(AbsMinBlog)
				{
					Min=b[i];
					break;
				}
			}
			return Min;
		}
		int getLocMaxEle(int (*a)[LEN],int *b)
		{
			int i,j,Max;
			for(i=0;i<LEN;i++)
			{
				bool LocMaxBlog = true;
				for(j=0;j<LEN;j++)
				{
					if(a[j][i]==1 && j!=i)
					{
						LocMaxBlog = false;
						break;
					}
				}
				if(LocMaxBlog)
				{
					Max=b[i];
					break;
				}
			}
			return Max;
		}
		int getLocMinEle(int (*a)[LEN],int *b)
		{
			int i,j,Min;
			for(i=0;i<LEN;i++)
			{
				bool LocMinBlog = true;
				for(j=0;j<LEN;j++)
				{
					if(a[i][j]==1 && j!=i)
					{
						LocMinBlog = false;
						break;
					}
				}
				if(LocMinBlog)
				{
					Min=b[i];
					break;
				}
			}
			return Min;
		}
	  {%endhighlight%}
	  
---

		{%highlight ruby%}
		equivalenceclass.c
        #include <stdio.h>
        #include <stdbool.h>
        #define LEN 8
        void getRelationMatrix(int (*a)[LEN],int *b);
        void getEquivalenceClass(int (*a)[LEN],int *b);
        void printRelation(int *b);
        int main(void)
        {
            int a[LEN][LEN];
            int b[LEN];
            int i;
            printf("Please input %d numbers:\n",LEN);
            for(i=0;i<LEN;i++)
                scanf("%d",&b[i]);
            getRelationMatrix(a,b);
            getEquivalenceClass(a,b);
            return 0;
        }
        void getRelationMatrix(int (*a)[LEN],int *b)
        {
            int i,j;
            for(i=0;i<LEN;i++)
            {
                for(j=0;j<LEN;j++)
                {
                    if((b[i]%3)==(b[j]%3))
                        a[j][i]=1;
                    else
                        a[j][i]=0;
                }
            }
        }
        void getEquivalenceClass(int (*a)[LEN],int *b)
        {
            int i,j;
            for(i=0;i<LEN;i++)
            {
                int temp[LEN]={0};
                for(j=0;j<LEN;j++)
                {
                    if(b[j]==0)
                        continue;
                    if(a[i][j]==1)
                    {
                        temp[j]=b[j];
                        b[j]=0;
                    }
                }
                printRelation(temp);
            }
        }
        void printRelation(int *b)
        {
            for(int i=0;i<LEN;i++)
            {
                if(b[i]!=0)
                    printf("%d ",b[i]);
            }
             printf("\n");
        }
		{%endhighlight%}

### Introspection
	
Using linklist instead of array will make this algorithm easier and more effective

---
If you find any fault in this blog , any method connecting with me is available and welcomed.
