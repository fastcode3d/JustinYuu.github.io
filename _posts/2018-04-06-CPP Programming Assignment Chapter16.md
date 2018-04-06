---
layout: post
title: "CPP Programming Assignment Chapter16"
description: "my own source codes of Programming Assignment in C Primer Plus "
categories: [C-Primer-Plus]
tags: [C]
redirect_from:
  - /2018/04/06/
---
# CPP Programming Assignment Chapter16


	{% highlight ruby %}
	16.1.h
    #ifndef C_16_1_H_INCLUDED
    #define C_16_1_H_INCLUDED

    #define LEN 80
    #define FLEN 60

    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>
    #include <stdbool.h>
    #endif // 16_1_H_INCLUDED
	{% endhighlight %}
	
---

	{% highlight ruby %}
	16.2.c
    #include <stdio.h>
    #define CALCULATE(X,Y) (2.0 * (X) * (Y) / ((X) + (Y)))
    int main(void)
    {
        double x,y,res;
        x = 1.0;
        y = 2.0;
        res = CALCULATE(x,y);
        printf("%g\n",res);
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	16.3.c
    #include <stdio.h>
    #include <math.h>
    struct polar{
        double r;
        double alpha;
    };
    struct rect{
        double x;
        double y;
    };
    struct rect polar_to_rect(const struct polar *pol);
    int main(void)
    {
        struct polar pol={1,60};
        struct rect res;
        res = polar_to_rect(&pol);
        printf("%g %g",res.x,res.y);
    }
    struct rect polar_to_rect(const struct polar *pol)
    {
        const double rad = 3.1415926 / 180.0;
        struct rect res;
        res.x = pol->r * cos(rad * pol->alpha);
        res.y = pol->r * sin(rad * pol->alpha);
        return res;
    };
	{% endhighlight %}	
---

	{% highlight ruby %}
	16.4.c
    #include <stdio.h>
    #include <time.h>

    void delay(int time);

    int main(void)
    {
        int t;

        printf("Please input the time lag,q to quit:\n");
        while (scanf("%d", &t) == 1)
        {
            delay(t);
            printf("time out.\n");
            printf("Please input the time lag,q to quit:\n");
        }

        return 0;
    }

    void delay(int time)
    {
        double i;
        i = (double)clock() / CLOCKS_PER_SEC;
        while ((double)clock() / CLOCKS_PER_SEC - i < time)
            ;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	16.5.c
    #include <stdio.h>
    #include <math.h>
    void printline(int *ar,int len,int time);

    int main(void)
    {
        int ar[10] = {1,2,3,4,5,6,7,8,9,10};
        printline(ar,10,7);
    }
    void printline(int *ar,int len,int time)
    {
        int index;
        int temp;
        for(int i=0;i<time;i++)
        {
            index = rand() % (len - 1);
            printf("%3d",ar[index]);
            temp=ar[index];
            ar[index]=ar[len-1];
            ar[len-1]=temp;
            len--;
        }
        printf("\n");
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	16.6.c
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define NUM 6
    struct names{
        char first[40];
        char last[40];
    };
    void showarray(struct names ar[], int n);
    int mycomp(const void * p1, const void * p2);

    int main(void)
    {
        struct names staff[NUM] ={
            {
			{"yi"},{"Ding"}
			},
            {
			{"er"},{"Wang"}
			},
            {
			{"san"},{"Zhang"}
			},
            {
			{"si"},{"Li"}
			},
            {
			{"wu"},{"Wang"}
			},
            {
			{"liu"},{"Zhao"}
			},
        };
        puts("Random list:");
        showarray(staff, NUM);
        qsort(staff, NUM, sizeof(struct names), mycomp);
        puts("\nSorted list:");
        showarray(staff, NUM);
        return 0;
    }

    void showarray(struct names ar[], int n)
    {
        int index;

        for( index = 0; index < n; index++)
        {
            printf("%s.%s\n", ar[index].last,ar[index].first);
            if (index % 6 == 5)
                putchar('\n');
        }
        if (index % 6 != 0)
            putchar('\n');
    }

    /* sort by increasing value */
    int mycomp(const void * p1, const void * p2)
    {
        const struct names * a1 = (const struct names *) p1;
        const struct names * a2 = (const struct names *) p2;

        int res;
        res = strcmp(a1->last,a2->last);
        if (res != 0)
            return res;
        else
            return strcmp(a1->first,a2->last);
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	16.7.c
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>
    void show_array(const double ar[], int n);
    double * new_d_array(int n, ...);
    int main()
    {
        double * p1;
        double * p2;

        p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
        p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
        show_array(p1, 5);
        show_array(p2, 4);
        free(p1);
        free(p2);

        return 0;
    }

    double * new_d_array(int lim, ...)
    {
        va_list va;
        va_start(va, lim);
        double * p;
        p = (double *)malloc(lim * sizeof(double));
        for (int i = 0; i < lim; i++)
            p[i] = va_arg(va, double);
        va_end(va);

        return  p;
    }

    void show_array(const double ar[], int n)
    {
        int i;
        for (i = 0; i < n; i++)
            printf("%.2f ", ar[i]);
        printf("\n");
    }
	{% endhighlight%}
	
---

  If you find there are faults in the source codes, any method connecting with me is welcomed.
