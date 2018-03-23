---
layout: post
title: "CPP Programming Assignment Chapter2"
description: "my own source codes of Programming Assignment in C Premier Plus "
categories: [C-Primer-Plus]
tags: [C]
redirect_from:
  - /2018/03/22/
---
#CPP Programming Assignment Chapter2

As there is no programming assignment in Chapter 1 ,thus I post my programming assignments from chapter 2.

{% highlight ruby %}
    2.1.c
    #include <stdio.h>
    int main(void)
    {
        printf("Justin Yu\n");
        printf("Justin\nYu\n");
        printf("Justin ");
        printf("Yu");
        return 0;
    }
    {% highlight ruby %}
 
----------------------------------------------------- 
    
    2.2.c
    #include <stdio.h>
    int main(void)
    {
        printf("My name is Justin Yu.\n");
        printf("My address is Road Wenhui 300#.");
        return 0;
    }
    
----------------------------------------------------- 
    2.3.c
    #include <stdio.h>
    int main(void)
    {
        int age,day;
        day = age * 365;
        age = 20;
        printf("My age is %d years old, which is %d days",age,day);
        return 0;
    }
    
----------------------------------------------------- 
    2.4.c
    #include <stdio.h>
    void jolly(void);
    void deny(void);
    int main(void)
    {
        jolly();
        jolly();
        jolly();
        deny();
        return 0;
    }
    void jolly(void)
    {
        printf("For he's a jolly good fellow!\n");
    }
    void deny(void)
    {
        printf("Which nobody can deny!\n");
    }
    
--------------------------------------------------------
    2.5.c
    #include <stdio.h>
    void br(void);
    void ic(void);
    int main(void)
    {
        br();
        printf(", ");
        ic();
        printf("\n");
        ic();
        printf(",\n");
        br();
        return 0;
    }
    void br(void)
    {
        printf("Brazil, Russia");
    }
    void ic(void)
    {
        printf("India, China");
    }
    
---------------------------------------------------------
    2.6.c
    #include <stdio.h>
    int main(void)
    {
        int toes;
        toes = 10;
        printf("toes is %d\ntoes' square is %d\ntoes' cube is %d ",toes,toes * toes,toes * toes * toes);
        return 0;
    }
    
---------------------------------------------------------------
    2.7.c
    #include <stdio.h>
    void smile(void);
    int main(void)
    {
        smile();
        smile();
        smile();
        printf("\n");
        smile();
        smile();
        printf("\n");
        smile();
        return 0;
    }
    void smile(void)
    {
        printf("Smile!");
    }
    
----------------------------------------------------------------
    2.8.c
    #include <stdio.h>
    void one_three(void);
    void two(void);
    int main(void)
    {
        printf("starting now:\n");
        one_three();
        two();
        printf("three\ndone!\n");
        return 0;
    }
    void one_three(void)
    {
        printf("one\n");
    }
    void two(void)
    {
        printf("two\n");
    }
    
----------------------------------------------------------------

  If you find there are faults in the source codes, any method connecting with me is welcomed.
