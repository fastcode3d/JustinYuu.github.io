---
layout: post
title: "CPP Programming Assignment Chapter9"
description: "my own source codes of Programming Assignment in C Primer Plus "
categories: [C-Primer-Plus]
tags: [C]
redirect_from:
  - /2018/03/23/
---
# CPP Programming Assignment 9

	{% highlight ruby %}
	9.1.c
    #include <stdio.h>
    double min(double x,double y);
    int main(void)
    {
        double t1;
        double t2;
        double min_num;
        printf("Please input two numbers: ");
        while(scanf("%lf %lf",&t1,&t2)==2)
        {
            printf("The minimum is %f.\n",min(t1,t2));
            printf("Next two values(q to quit): ");
        }
    }
    double min(double x,double y)
    {
        if(x<=y)
            return x;
        else
            return y;
    }
	{% endhighlight %}

---

	{% highlight ruby %}
	9.2.c
    #include <stdio.h>
    void chline(char ch,int i,int j);
    int main(void)
    {
        char ch;
        int x;
        int y;
        printf("Please input the characters you want to print, the rows and columns:");
        while(scanf("%c %d %d" ,&ch,&x,&y) == 3)
            chline(ch,x,y);
        return 0;
    }
    void chline(char ch,int i,int j)
    {
        for(int m=0;m<j;m++)
        {
            for(int n=0;n<i;n++)
                printf("%c ",ch);
            printf("\n");
        }
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	9.3.c
    #include <stdio.h>
    void chLineRow(char ch,int c,int r)
    {
        int col,row;
        fot(row=0;row<r;row++)
        {
            for(col=0;col<c,col++)
                putchar(ch);
            putchar('\n');
        }
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	9.4.c
    #include <stdio.h>
    double calculate(double q,double p)
    {
        double n;
        n = 1.0/((1.0/q + 1.0/p) /2.0);
        return n;
    }
    int main(void)
    {
        double x;
        double y;
        printf("Please input two numbers: \n");
        while(scanf("%lf %lf",&x,&y)==2)
            printf("%f",calculate(x,y));
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	9.5.c
	#include <stdio.h>
    void larger_of(double *a,double *b)
    {
        *a=*b=(*a > *b) ? *a:*b;
    }
    int main(void)
    {
        double x;
        double y;
        printf("Please input two numbers:\n");
        while(scanf("%lf %lf",&x,&y)==2)
        {
            larger_of(&x,&y);
            printf("%f %f\n",x,y);
            printf("Next two numbers: \n");
        }
        printf("Bye!");
        return 0;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	9.6.c
	#include <stdio.h>
    void sort(double *p1,double *p2,double *p3)
    {
        double temp;
        if(*p1>*p2)
        {
            temp = *p2;
            *p2 = *p1;
            *p1 = temp;
        }
        if(*p2>*p3)
        {
            temp = *p3;
            *p3 = *p2;
            *p2 = temp;
        }
        }
        if(*p1>*p2)
        {
            temp = *p2;
            *p2 = *p1;
            *p1 = temp;
        }
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	9.7.c
    #include <stdio.h>
    #include <ctype.h>
    int position(char ch)
    {
        int pos;
        if(!isalpha(ch))
            pos = -1;
        else
            {
                tolower(ch);
                pos = ch-96;
            }
        return pos;
    }
    int main(void)
    {
        char ch;
        printf("Please input the text:");
        while((ch=getchar())!='\n')
            {
                if(position(ch)!=-1)
                    printf("%c is a letter, which position in alphabet is %d.\n",ch,position(ch));
                else
                    printf("%c is not a letter.\n");
            }
        return 0;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	9.8.c
    #include <stdio.h>
    double power(double n, int p);
    int main(void)
    {
        double x, xpow;
        int exp;

        printf("Enter a number and the  integer power");
        printf(" to which\nthe number will be raised. Enter q");
        printf(" to quit.\n");
        while (scanf("%lf%d", &x, &exp) == 2)
        {
            xpow = power(x,exp);   // function call
            printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
            printf("Enter next pair of numbers or q to quit.\n");
        }
        printf("Hope you enjoyed this power trip -- bye!\n");

        return 0;
    }

    double power(double n, int p)  // function definition
    {
        double pow = 1;
        int i;
        if(n==0)
            if(p == 0)
                pow = 1;
            else
                pow = 0;
        else
        {
            if(p>0)
            {
                for (i = 1; i <= p; i++)
                pow *= n;
            }
            else if(p<0)
            {
                for (i=1;i<=-p;i++)
                pow *= (1/n);
            }
            else
                pow = 1;
        }
        return pow;                // return the value of pow
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	9.9.c
    #include <stdio.h>
    double power(double n, int p);
    int main(void)
    {
        double x, xpow;
        int exp;

        printf("Enter a number and the  integer power");
        printf(" to which\nthe number will be raised. Enter q");
        printf(" to quit.\n");
        while (scanf("%lf%d", &x, &exp) == 2)
        {
            xpow = power(x,exp);   // function call
            printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
            printf("Enter next pair of numbers or q to quit.\n");
        }
        printf("Hope you enjoyed this power trip -- bye!\n");

        return 0;
    }

    double power(double n, int p)  // function definition
    {
        double pow = 1;
        int i;
        if(n==0)
            if(p == 0)
                pow = 1;
            else
                pow = 0;
        else
        {
            if(p>0)
            {
                for (i = 1; i <= p; i++)
                pow = n*power(n,p-1);
            }
            else if(p<0)
            {
                for (i=1;i<=(-p);i++)
                pow = power(1/n,-p);
            }
            else
                pow = 1;
        }
        return pow;                // return the value of pow
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	9.11.c
    #include <stdio.h>
    long long fibonacci_iteration(int n) {
        int i = 2;
        long long num = 0;
        if(n < 3) {
            return 1;
        }
        long long fib_minusone = 1;
        long long fib_minustwo = 0;
        for(i=2;i <=n;i++) {
            num = fib_minusone + fib_minustwo;
            fib_minustwo = fib_minusone;
            fib_minusone = num;
        }
        return num;
    }
    int main(void)
    {
        int n;
        printf("Please input the number:\n");
        while(scanf("%d",&n)==1)
            printf("The %dth Fibonacci number is %lld.\n",n,fibonacci_iteration(n));
        return 0;
    }
	{% endhighlight %}
	
---
  If you find there are faults in the source codes, any method connecting with me is welcomed.
