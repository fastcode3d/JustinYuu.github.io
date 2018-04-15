---
layout: post
title: "Programming Assignment of Discrete Mathematics Chapter 3"
description: "my own source codes of Programming Assignment in Discrete Mathematics "
categories: [Discrete-Mathematics]
tags: [C]
redirect_from:
  - /2018/04/15/
---

# Programming Assignment of Discrete Mathematics Chapter 3


### Qusetion

Given a random 6*6 relation matrix, and design four algorithms to judge whether this matrix is symmetric,antisymmetric,transitive or reflexive or not.

### My solution

Using four functions to judge. The algorithm is literally easy.
	
### Source code

	{% highlight ruby %}
    #include <stdio.h>
    #include <stdbool.h>
    #define LEN 6
    bool isSymmetric(const int (*a)[LEN]);
    bool isReflexive(const int (*a)[LEN]);
    bool isTransitive(const int (*a)[LEN]);
    bool isAntiSymmetric(const int (*a)[LEN]);
    int main(void)
    {
        int re_matr[LEN][LEN]={
				{1,1,1,1,1,1},
				{1,1,1,1,1,1},
				{1,1,1,1,1,1},
				{1,1,1,1,1,1},
				{1,1,1,1,1,1},
				{1,1,1,1,1,1}
				};
        printf("Bonjour!\n");
        printf("Is this relation matrix symmetric?\n");
        if(isSymmetric(re_matr))
            printf("Yes!\n");
        else
            printf("No!\n");

        printf("Is this relation matrix reflexive?\n");
        if(isReflexive(re_matr))
            printf("Yes!\n");
        else
            printf("No!\n");

        printf("Is this relation matrix transitive?\n");
        if(isTransitive(re_matr))
            printf("Yes!\n");
        else
            printf("No!\n");

        printf("Is this relation matrix antisymmetric?\n");
        if(isAntiSymmetric(re_matr))
            printf("Yes!\n");
        else
            printf("No!\n");
        printf("Au Revoir!");
        return 0;
    }
    bool isSymmetric(const int (*a)[LEN])
    {
        for(int i=0;i<LEN;i++)
        {
            for(int j=0;j<LEN;j++)
            {
                if(a[i][j]!=a[j][i])
                    return false;
            }
        }
            return true;
    }
    bool isReflexive(const int (*a)[LEN])
    {
        for(int i=0;i<LEN;i++)
        {
            if(a[i][i]!=1)
                return false;
        }
        return true;
    }
    bool isTransitive(const int (*a)[LEN])
    {
        int temp[LEN][LEN];
        for(int i=0;i<LEN;i++)
        {
            for(int j=0;j<LEN;j++)
            {
                temp[i][j]=0;
                for(int k=0;k<=LEN;k++)
                    temp[i][j]+=a[i][k]*a[k][j];
            }
        }
        for(int i=0;i<LEN;i++)
        {
            for(int j=0;j<LEN;j++)
            {
                if(temp[i][j]==0 && a[i][j]!=0)
                    return false;
            }
        }
        return true;
    }
    bool isAntiSymmetric(const int (*a)[LEN])
    {
        for(int i=0;i<LEN;i++)
        {
            for(int j=0;j<LEN;j++)
            {
                if(i!=j && a[i][j]==1 && a[j][i]==1)
                    return false;
            }
        }
        return true;
    }
	  {%endhighlight%}


### Introspection
	
Literally, this algorithm is relatively easy,thus there is few improving method. The only improvement I could find is to improve
function isTransitive(),we could use *plus* operation instead of *multiply* operation , which has lower time complexity.

---
If you find any fault in this blog , any method connecting with me is available and welcomed.
