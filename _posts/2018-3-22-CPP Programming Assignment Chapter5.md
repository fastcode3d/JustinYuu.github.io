---
layout: post
title: "CPP Programming Assignment Chapter5"
description: "my own source codes of Programming Assignment in C Premier Plus "
categories: [C-Primer-Plus]
tags: [C]
redirect_from:
  - /2018/03/22/
---
#CPP Programming Assignment Chapter5

    5.1.c
	#include <stdio.h>
    #define SECPERMIN 60
    int main(void)
    {
        int min;
        int hour;
        int minl;
        printf("Please input time in minutes: \n");
        scanf("%d",&min);
        while(min>0){
            hour = min / SECPERMIN;
            minl = min % SECPERMIN;
            printf("%d minutes equals %d hours %d minutes.\n", min, hour, minl);
            printf("Please input time in minutes: \n");
            scanf("%d",&min);
        }
    }
	
---
	5.2.c
    #include <stdio.h>
    int main(void)
    {
        int integer;
        int i;
        i=0;
        printf("Please input an integer: \n");
        scanf("%d",&integer);
        while(i<11){
        printf("%d ",integer);
        integer++;
        i++;
        }
    }
	
---
	5.3.c
    #include <stdio.h>
    #define DAYPERWEEK 7
    int main(void)
    {
         int day;
        int week;
        int days;
        printf("Please input days: \n");
        scanf("%d",&day);
        while(day>0){
            week = day / DAYPERWEEK;
            days = day % DAYPERWEEK;
            printf("%d days are %d weeks, %d days.\n", day, week, days);
            printf("Please input days: \n");
            scanf("%d",&day);
        }
    }

---
	5.4.c
    #include <stdio.h>
    #define INCHPERFEET 12
    #define CMPERINCH 2.54
    int main(void)
    {
         float cm;
        float inch;
        int feet;
        float inches;
        printf("Enter a height in centimeters: ");
        scanf("%f",&cm);
        while(cm>0){
            inch = cm / CMPERINCH;
            feet = inch / INCHPERFEET;
            inches = inch - feet * INCHPERFEET;
            printf("%5.1f cm = %d feet, %.1f inches.\n", cm
                   , feet, inches);
            printf("Enter a height in centimeters (<=0 to quit): ");
            scanf("%f",&cm);
        }
        printf("bye");
    }

---
	5.7.c
    #include <stdio.h>
    int main(void)
    {
        double num;
        printf("Please input a number: \n");
        scanf("%d",&num);
        cubic(num);
        return 0;
        }
    void cubic(int n)
    {
        printf("The cubic of %d is %d",n,n*n*n);
    }

---
	5.8.c
    #include <stdio.h>
    int main(void)
    {
        int sec;
        int first;
        int mod;
        printf("This program computes moduli. \n");
        printf("Enter an integer to serve as the second operand: ");
        scanf("%d",&sec);
        printf("Now enter the first operand: ");
        scanf("%d",&first);
        while(first>0)
            {
                mod = first % sec;
                printf("%d %% %d is %d\n",first, sec, mod);
                printf("Enter next number for first operand (<= 0 to quit): ");
                scanf("%d",&first);
            }
            printf("Done");
        }

---
	5.9.c
    #include <stdio.h>
    int main(void)
    {
        double tem_f;
        printf("Please input the temperature in Fahrenheit: ");
        scanf("%lf", &tem_f);
        Temperatures(tem_f);
        }
    void Temperatures(int t)
    {
        const float tem_k = 273.16;
        const float tem_c1 = 5.0 / 9.0;
        const float tem_c2 = 32.0;
    }

---
If you find there are faults in the source codes, any method connecting with me is welcomed.
