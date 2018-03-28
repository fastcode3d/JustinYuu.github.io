---
layout: post
title: "CPP Programming Assignment Chapter12"
description: "my own source codes of Programming Assignment in C Primer Plus "
categories: [C-Primer-Plus]
tags: [C]
redirect_from:
  - /2018/03/28/
---
# CPP Programming Assignment Chapter12


	{% highlight ruby %}
	12.1.c
	#include <stdio.h>
    int critic(int units);
    int main(void)
    {
        int units;

        printf("How many pounds to a firkin of butter\n");
        scanf("%d",&units);
        while(units != 56)
            units=critic(units);
        printf("You must have looked it up!\n");
        return 0;
    }
    int critic(int units)
    {
        printf("No luck, my friend. Try again.\n");
        scanf("%d",&units);
        return units;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	12.4.c
    #include <stdio.h>
    int count = 0;
    int num_call();
    int main(void)
    {
        int i;
        for(i=0;i<10;i++)
        {
            i=num_call();
            printf("%d",i);
        }
        return 0;
    }
    int num_call()
    {
        count++;
        return count;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	12.5.c
    #include <stdio.h>
    #include <stdlib.h>
    #define SIZE 100
    void stint(int arr[],int num);
    void print(const int arr[],int num);
    int main(void)
    {
        int i;
        int arr[SIZE];
        for(i=0;i<SIZE;i++)
            arr[i] = rand()%10 +1;
        puts("initial array.");
        print(arr,SIZE);
        stint(arr,SIZE);
        puts("\nsorted array.");
        print(arr,SIZE);
        return 0;
    }
    void stint(int arr[],int num)
    {
        int temp;
        int top,seek;
        for(top = 0;top<num-1;top++)
            for(seek=top+1;seek<num;seek++)
                if(arr[seek]>arr[top])
                {
                    temp = arr[seek];
                    arr[seek]=arr[top];
                    arr[top]=temp;
                }
    }
    void print(const int arr[],int num)
    {
        int index;
        for(index = 0;index<num;index++)
        {
            printf("%2d ",arr[index]);
            if(index % 10 == 9)
                putchar('\n');
        }
        if(index % 10 !=0)
            putchar('\n');
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	12.6.c
    #include <stdio.h>
    #include <stdlib.h>
    #define SIZE 1000
    void print(const int arr[],int num);
    int main(void)
    {
        int arr[SIZE];
        srand(10);
        for(int i=0;i<SIZE;i++)
        {
            arr[i] = rand() % 10;
        }
        print(arr,SIZE);
        return 0;
    }
    void print(const int arr[],int num)
    {
        int sta[10]={0};
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(arr[i] == j)
                    sta[j]++;
            }
        }
        for(int k=0;k<10;k++)
            printf("%d = %2d \n",k,sta[k]);
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	12.7.c
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    int rollem(int);

    int main(void)
    {
        int dice,count,roll;
        int sides;
        int set,sets;
        srand((unsigned int)time(0));
        printf("Enter the number of sets,enter q to quit");
        while(scanf("%d",&sets) == 1)
        {
            printf("How many sides and how many dices?  ");
            if(scanf("%d %d",&sides,&dice) != 2)
            {
                puts("not integers -- terminating input loop.");
                break;
            }
            printf("Here are %d sets of %d %d-sided throws.\n",sets,dice,sides);
            for (set=0;set<sets;set++)
            {
                for(roll = 0,count = 0;count < dice;count++)
                    roll += rollem(sides);
                printf("%4d ",roll);
                if(set % 15 == 14)
                    putchar('\n');
            }
            if (set % 15  != 0)
                putchar('\n');
            printf("How many sets? Enter q to quit: ");
        }
        puts("Good Fortune To You!\n");
        return 0;
    }
    int rollem(int sides)
    {
        int roll;
        roll = rand() % sides + 1;
        return roll;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	12.8.c
    #include <stdio.h>
    #include <stdlib.h>
    int * make_array(int elem,int val);
    void show_array(const int ar [],int n);
    int main(void)
    {
        int *pa;
        int size;
        int value;
        printf("Enter the number of elements: ");
        while(scanf("%d",&size)==1 && size > 0)
        {
            printf("Enter the initialization value: ");
            scanf("%d",&value);
            pa = make_array(size,value);
            if(pa)
            {
                show_array(pa,size);
                free(pa);
            }
            printf("Enter the number of elements (<1 to quit): ");
        }
        printf("Done.\n");
        return 0;
    }
    int * make_array(int elem,int val)
    {
        int * res;
        int i=0;
        res = (int *) malloc( elem * sizeof(int));
        while(i<elem)
        {
            res[i]=val;
            i++;
        }
        return res;
    }
    void show_array(const int ar [],int n)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",ar[j]);
            if((j+1)%8 == 0&& (j>0))
                printf("\n");
        }
        printf("\n");
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	12.9.c
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #define LEN 80
    void show_array(const char* ar[],int n);
    int main(void)
    {
        char temp[LEN];
        int size;
        int len;
        char **pa;
        printf("How many words do you wish to enter? ");
        scanf("%d",&size);
        pa = (char **)malloc(size * sizeof(char*));
        printf("Enter %d words now:\n",size);
        for(int i=0;i<size;i++)
        {
            scanf("%s",temp);
            len=strlen(temp);
            pa[i]=(char *)malloc((len+1) * sizeof(char));   /* do not forget to copy '\0' */
            strncpy(pa[i],temp,len+1);
        }
        printf("Here are your words:\n");
        for(int j=0;j<size;j++)
        {
            puts(pa[j]);
        }
        for (int i = 0; i < size; i++)
        {
            free(pa[i]);
        }
        free(pa);
        return 0;
    }
	{% endhighlight %}
	
---
  If you find there are faults in the source codes, any method connecting with me is welcomed.
