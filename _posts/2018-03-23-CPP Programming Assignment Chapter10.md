---
layout: post
title: "CPP Programming Assignment Chapter10"
description: "my own source codes of Programming Assignment in C Primer Plus "
categories: [C-Primer-Plus]
tags: [C]
redirect_from:
  - /2018/03/23/
---
# CPP Programming Assignment Chapter10


	{% highlight ruby %}
	10.1.c
	#include <stdio.h>
    #define MONTHS 12
    #define YEARS   5
    int main(void)
    {
        const float rain[YEARS][MONTHS] =
        {
            {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
            {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
            {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
            {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
            {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
        };
        int year, month;
        float subtot, total;

        printf(" YEAR    RAINFALL  (inches)\n");
        for (year = 0, total = 0; year < YEARS; year++)
        {
            for (month = 0, subtot = 0; month < MONTHS; month++)
                subtot += *(*(rain + year) + month);
            printf("%5d %15.1f\n", 2010 + year, subtot);
            total += subtot;
        }
        printf("\nThe yearly average is %.1f inches.\n\n",
               total/YEARS);
        printf("MONTHLY AVERAGES:\n\n");
        printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct ");
        printf(" Nov  Dec\n");

        for (month = 0; month < MONTHS; month++)
        {
            for (year = 0, subtot =0; year < YEARS; year++)
                subtot += *(*(rain + year) + month);
            printf("%4.1f ", subtot/YEARS);
        }
        printf("\n");

        return 0;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	10.2.c
	#include <stdio.h>
    void copy_arr(double a[],double b[],int length);
    void copy_ptr(double *a,double *b,int length);
    void copy_ptrs(double *a,double *b,double *c);
    int main(void)
    {
        double source[5] = {1.1,2.2,3.3,4.4,5.5};
        double target1[5];
        double target2[5];
        double target3[5];
        for(int i=0;i<5;i++)
        {
            printf("%.1f ",source[i]);
        }
        printf("\n");
        copy_arr(target1,source,5);
        copy_ptr(target2,source,5);
        copy_ptrs(target3,source,source+5);
        return 0;
    }
    void copy_arr(double a[],double b[], int length)
    {
        for(int i=0;i<length;i++)
        {
            a[i]=b[i];
            printf("%.1f ",a[i]);
        }
        printf("\n");
    }
    void copy_ptr(double *a,double *b,int length)
    {
        for(int i=0;i<length;i++)
        {
            *a=*b;
            printf("%.1f ",*a);
            a++;
            b++;
        }
        printf("\n");
    }
    void copy_ptrs(double *a,double *b, double *c)
    {
        while(b<c)
        {
            *a=*b;
            printf("%.1f ",*a);
            b++;
            a++;
        }
        printf("\n");
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	10.3.c
    #include <stdio.h>
    int max(int *a,int length)
    {
        int i,m;
        m=0;
        for(i=0;i<length;i++)
        {
            if(*a>=m)
            {
                m=*a;
                *a++;
            }
        }
        return m;
    }
    int main(void)
    {
        int S[5]={1,2,3,4,10};
        printf("The maximum of those numbers is %d",max(S,5));
        return 0;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	10.4.c
    #include <stdio.h>
    int index(double *a,int length);
    int main(void)
    {
        double S[5]={1.0,2.2,3.4,4.1,10.0};
        printf("The maximum's index is %d",index(S,5));
        return 0;
    }
    int index(double *a,int length)
    {
        int n=-1;
        int m=0;
        for(int i=0;i<length;i++)
        {
            if (*a>=m)
            {
                m=*a;
                *a++;
                n++;
            }
        }
        return n;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	10.5.c
    #include <stdio.h>
    double subtract(double *r,int n);
    int main(void)
    {
        double S[5]={2.0,12.2,13.4,4.1,10.0};
        printf("Maximum subtracts minimum is %.1f",subtract(S,5));
        return 0;
    }
    double subtract(double *r,int n)
    {
        double max=0;
        double min=*r;
        for(int i=0;i<n;i++)
        {
            if(*r>=max)
            {
                max=*r;
                *r++;
            }
            else if(*r<=min)
            {
                min=*r;
                *r++;
            }
        }
        return (max - min);
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	10.6.c
    #include <stdio.h>
    void LGD_sort(double *a,int length);
    int main(void)
    {
        double S[6]={1.0,2.0,6.8,3.0,4.0,5.0};
        LGD_sort(S,6);
        for(int i=0;i<6;i++)
            printf("%.1f ",S[i]);
        return 0;
    }
    void LGD_sort(double *a,int length)
    {
        double temp;
        for(int i=0;i<length/2;i++)
        {
            temp=*(a+i);
            *(a+i)=*(a+length-1-i);
            *(a+length-1-i)=temp;
        }
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	10.7.c
    #include <stdio.h>
    #define ROWS 3
    #define COLS 2
    void copy_ptr(double ar[][COLS],double a[][COLS],int n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<COLS;j++)
            {
                ar[i][j] = a [i][j];
                printf("%.1f ",ar[i][j]);
            }
            printf("\n");
        }

        printf("\n");
    }
    int main(void)
    {
        double S[ROWS][COLS]={
			      {2,4},
			      {6,8},
			      {5,7}
				    };
        double T[ROWS][COLS];
        copy_ptr(T,S,ROWS);
        return 0;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	10.8.c
    #include <stdio.h>
    #define ROWS 3
    #define COLS 2
    void copy_ptr(double *a,double *b,int n)
    {
        for(int i=0;i<n;i++)
        {
            *a=*b;
            printf("%.1f ",*a);
            a++;
            b++;
        }
        printf("\n");
    }
    int main(void)
    {
        double S[7]={1.0,2.0,3,4,5,6,7};
        double T[3];
        copy_ptr(T,S+3,3);
        return 0;
    }
	{% endhighlight %}
	
---

	{% highlight ruby%}
	10.9.c
    #include <stdio.h>
    void copy_arr(int rows,int cols,double ar[rows][cols],double ar_copy[rows][cols]);
    void show_arr(int rows,int cols,double ar[rows][cols]);
    int main()
    {
        int a=3;
        int b=5;
        double copy[a][b];
        double source[3][5] =
        {
            {1,2,3,4,5},
            {6,7,8,9,10},
            {11,12,13,14,15}
        };
        printf("The original array is below:\n");
        show_arr(3,5,source);
        copy_arr(3,5,source,copy);
        printf("The copied array is below:\n");
        show_arr(3,5,copy);
    }
    void copy_arr(int rows, int cols,double ar[rows][cols],double ar_copy[rows][cols])
    {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
                ar_copy[i][j]=ar[i][j];
        }
    }
    void show_arr(int rows,int cols,double ar[rows][cols])
    {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
                printf("%5.1f ",ar[i][j]);
            printf("\n");
        }
        printf("\n");
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	10.10.c
    #include <stdio.h>
    void arplus(int ar1[],int ar2[],int ar3[],int n);
    int main(void)
    {
        int ar1[]={2,4,5,8};
        int ar2[]={1,0,4,6};
        int ar3[4];
        arplus(ar1,ar2,ar3,4);
        return 0;
    }
    void arplus(int ar1[],int ar2[],int ar3[],int n)
    {
        for(int i=0;i<n;i++)
        {
            ar3[i]=ar1[i]+ar2[i];
            printf("%d ",ar3[i]);
        }
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	10.11.c
    #include <stdio.h>
    void show_arr(int ar[][5],int rows);
    void doublearr(int ar[][5],int rows);
    int main(void)
    {
        int source[3][5]=
        {
            {1,2,3,4,5},
            {6,7,8,9,10},
            {11,12,13,14,15}
        };
        printf("The original array is below:\n");
        show_arr(source,3);
        printf("The doubled array is below:\n");
        doublearr(source,3);
        show_arr(source,3);
        return 0;
    }
    void show_arr(int ar[][5],int rows)
    {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<5;j++)
                printf("%d ",ar[i][j]);
            printf("\n");
        }
    }
    void doublearr(int ar[][5],int rows)
    {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<5;j++)
                ar[i][j]*=2;
        }
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	10.13.c
    #include <stdio.h>
    void savearr(double arr[][5],int rows);
    void avearr(double arr[][5],int rows);
    double aveall(double arr[][5],int rows);
    double findmax(double arr[][5],int rows);
    void showarr(double arr[][5],int rows);
    int main(void)
    {
        double s[3][5];
        showarr(s,3);
        return 0;
    }
    void savearr(double arr[][5],int rows)
    {
        for(int i=0;i<rows;i++)
        {
            printf("Please input 5 (double)numbers:\n");
            for(int j=0;j<5;j++)
                scanf("%lf",&arr[i][j]);
        }
    }
    void avearr(double arr[][5],int rows)
    {
        double total;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<5;j++)
                    total+=arr[i][j];
            printf("The average of the %d group is %.3f.\n",i+1,total/5);
            total = 0;
        }
    }
    double aveall(double arr[][5],int rows)
    {
        double total;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<5;j++)
                total+=arr[i][j];
            //printf("The average of whole array is %.3f.\n",total/(5*rows));
        }
        return total/(5*rows);
    }
    double findmax(double arr[][5],int rows)
    {
        int max=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<5;j++)
                {
                    if(max<=arr[i][j])
                        max = arr[i][j];
                }
        }
        return max;
    }
    void showarr(double arr[][5],int rows)
    {
        savearr(arr,rows);
        printf("The number you input is:\n");
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<5;j++)
                    printf("%.2f ",arr[i][j]);
            printf("\n");
        }
        avearr(arr,rows);
        printf("The average of the total group is %.3f.\n",aveall(arr,rows));
        printf("The maximum number of the total group is %.2f.\n",findmax(arr,rows));
    }
	{% endhighlight %}
	
---
  If you find there are faults in the source codes, any method connecting with me is welcomed.
