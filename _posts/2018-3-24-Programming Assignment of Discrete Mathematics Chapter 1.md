---
layout: post
title: "Programming Assignment of Discrete Mathematics Chapter 1"
description: "my own source codes of Programming Assignment in Discrete Mathematics "
categories: [Discrete Mathematics]
tags: [C]
redirect_from:
  - /2018/03/22/
---

# Programming Assignment of Discrete Mathematics Chapter 1

  Though I'm majoring in composite material in the university , I still chose *one* course in computer college , which is *Discrete Mathematics*,being regarded as the fundemental of computer science.
  
  However, this course is very basic and programming assignments in this cource is relatively easy. Anyway, I put the programming assignment in the *[Discrete Mathematics]* category of my blog .
  
## Chapter 1

### Qusetion

 本实验要求大家利用C＋＋语言或JAVA语言，实现统计字符串中各个字母出现的次数。
（字符包括a—z A—z 0--9）

This experiment requires you to use the C++ language or the JAVA language to realize the statistics of number of occurrences of each letter in a character string. (letter to be counted includes A-Z,a-z,0-9)

### My solution

Write a function to count each letter's number of occurrences in the whole character string. And recall this function to count each letter's occurrences.
 
### The source code:
 
 	{% highlight ruby %}
 	count.cpp
	#include <stdio.h>
    #include <string.h>
    int count(char str[],char c)
    {
        int n=0;
        for (int i=0;i<strlen(str);i++){
            if (c==str[i]) n++;
        }
        return n;
    }
    int main(void)
    {
        int n;
        char str[100];
        printf("Please input the sentence: \n");
        gets(str);
        char a='0';
        for(int i=0;i<62;i++)
            {
                if(a>='0' && a<='z')
                {
                    if(a=='Z')
                    {
                        n=count(str,a);
                        if(n!=0)
                        printf("There are %d %c in total.\n",n,a);
                        a=a+7;
                    }
                    else if(a=='9')
                    {
                        n=count(str,a);
                        if(n!=0)
                        printf("There are %d %c in total.\n",n,a);
                        a=a+8;
                    }
                    else if(a >='0'&& a<='z')
                    {
                      n=count(str,a);
                      if(n!=0)
                      printf("There are %d %c in total.\n",n,a);
                      a++;
                    }

                }
                else
                    printf("Ilegal characters!");
            }
        return 0;
    }
	{%endhighlight%}
	
### Reflection

This algorithm will call the count() function for each letter, which costs a lot. Besides, the circulation uses lots of *if* ,which literally ugly to read.

---
If you find any fault in this blog , any method connecting with me is available and welcomed.
