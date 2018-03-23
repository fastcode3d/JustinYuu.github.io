---
layout: post
title: "CPP Programming Assignment Chapter7"
description: "my own source codes of Programming Assignment in C Premier Plus "
categories: [C-Primer-Plus]
tags: [C]
redirect_from:
  - /2018/03/23/
---
#CPP Programming Assignment Chapter7

    7.1.c
    #include <stdio.h>
    int main(void)
    {
        char ch;
        int space_n;
        int line_n;
        int else_n;
        printf("Please insert your sentence: ");
        while((ch = getchar()) != '#')
        {
            if (ch == ' ')
                space_n++;
            else if (ch == '\n')
                line_n++;
            else
                else_n++;
        }
        printf("There are %d spaces , %d lines and %d other characters in the sentence you input.\n", space_n, line_n, else_n);
        return 0;
    }
	
---
	7.2.c
	#include <stdio.h>
    int main(void)
    {
        char ch;
        int ch_num = 1;
        printf("Please input some characters, # to stop.\n");
        while((ch = getchar()) != '#')
        {
            if(ch_num % 9 != 0)
            {
                ch_num++;
                printf("%c- %d ",ch, ch);
            }
            else
            {	printf("\n");
                ch_num++;
            }
        }
        return 0;
    }
	
---
	7.3.c
	#include <stdio.h>
    int main(void)
    {
        int num;
        int odd_num=0;
        int even_num=0;
        float odd_avg=0;
        float even_avg=0;
        printf("Please input the first number, 0 to stop.\n");
        while(scanf("%d", &num) == 1)
        {
            if (num == 0)
            {
                printf("Bye!\n");
                break;
            }

            if(num % 2 == 0)
            {
                even_num++;
                even_avg += num;
            }
            else
            {	
                odd_num++;
                odd_avg +=num;
            }
            printf("Enter next numbers ,0 to stop.\n");
        }
        if ((even_num !=0) && (odd_num !=0))
            {
                even_avg = even_avg / even_num;
                odd_avg = odd_avg / odd_num;
            }
        else if (even_num == 0)
        {
            even_avg = 0;
        }
        else if (odd_num ==0)
        {
            odd_avg = 0;
        }
        
        printf("There are %d even numbers, the average of even numbers is %f.\nAnd There are %d odd numbers, whose average is %f.\n", even_num,even_avg,odd_num,odd_avg);
        return 0;
    }
	
---
	7.4.c
	#include <stdio.h>
    #define  EMCLA '!'
    #define  STOP '.'
    int main(void)
    {
        char ch;
        int ch_num = 0;
        printf("Please input some characters, # to stop.\n");
        while((ch = getchar()) != '#')
        {
            if(ch == STOP)
            {
                ch = EMCLA;
                ch_num++;
                putchar(ch);
            }
            else if (ch == '!')
            {	
                ch_num++;
                putchar(ch);
                putchar(ch);
            }
            else
                putchar(ch);
        }
        if(ch_num == 1)
            printf("\nThere are %d change.\n", ch_num);
        else
            printf("\nThere are %d changes.\n", ch_num);
        return 0;
    }
	
---
	7.6.c
	#include <stdio.h>
    int main(void)
    {
        char ch;
        char ch1;
        int ch_num = 0;
        printf("Please input the sentence, # to quit.\n");
        while((ch = getchar()) != '#')
        {
            if(ch == 'e')
            {
                ch1 = getchar();
                if (ch1 == 'i')
                {
                    ch_num++;
                }
            }
        }
        printf("There are %d \'ei\'' in the sentence.\n" ,ch_num);
        return 0;
    }
	
---
	7.7.c
    #include <stdio.h>
    #define BASIC_SAL 10.00
    #define OVERTIME_SAL 15.00
    #define TAXRATE1 0.15
    #define TAXRATE2 0.20
    #define TAXRATE3 0.25
    int main(void)
    {
        float time;
        float salary;
        printf("Please input your work time in hours:\n");
        scanf("%f", &time);
        if (time<=30)
            salary = time * BASIC_SAL *(1-TAXRATE1);
        else if ((time<=40) && (time >30))
            salary = 300*(1-TAXRATE1)+ (time - 30)*BASIC_SAL*(1-TAXRATE2);
        else if ((time>40)&& (time<=130/3))
            salary = 300*(1-TAXRATE1)+100*(1-TAXRATE2)+(time - 40)*OVERTIME_SAL*(1-TAXRATE2);
        else if (time>130/3)
            salary = 300*(1-TAXRATE1)+150*(1-TAXRATE2)+OVERTIME_SAL*(time-130/3)*(1-TAXRATE3);
        printf("Your salary is $%.2f\n", salary);
        return 0;
    }
	
---
	7.8.c
	#include <stdio.h>
    #include <stdbool.h>
    int main(void)
    {
        unsigned long num;
        unsigned long div;
        bool isPrime;

        printf("Please enter an positive integer for analysis; ");
        printf("Enter other to quit.\n");
        while (scanf("%lu",&num) == 1)
        {
            if(num <= 0)
                break;
            else 
                for (div = 2,isPrime = true;(div * div) <= num; div++)
                {
                    if (num % div == 0)
                        isPrime = false;
                }
                if(isPrime)
                    printf("%lu is prime.\n", num);
                else
                    printf("%lu is not a prime\n", num);
                printf("Please enter another integer for analysis; ");
                printf("Enter q to quit.\n");
        }
        printf("Bye!");
        return 0;
	}
	
---
  If you find there are faults in the source codes, any method connecting with me is welcomed.	
		
		
