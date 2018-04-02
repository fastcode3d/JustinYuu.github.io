---
layout: post
title: "CPP Programming Assignment Chapter14"
description: "my own source codes of Programming Assignment in C Primer Plus "
categories: [C-Primer-Plus]
tags: [C]
redirect_from:
  - /2018/04/02/
---
# CPP Programming Assignment Chapter14


	{% highlight ruby %}
	14.2.c
    #include <stdio.h>
    #include <string.h>
    typedef struct MONTH_INFO
    {
        char month[4];
        int month_days;
        int month_number;
    } ST_MONTH_INFO;
    #define N_MONTH  12
    const ST_MONTH_INFO info[N_MONTH] = {
        {"Jan", 31, 1},
        {"Feb", 28, 2},
        {"Mar", 31, 3},
        {"Apr", 30, 4},
        {"May", 31, 5},
        {"Jun", 30, 6},
        {"Jul", 31, 7},
        {"Aug", 31, 8},
        {"Sep", 30, 9},
        {"Oct", 31, 10},
        {"Nov", 30, 11},
        {"Dec", 31, 12}
    };
    int main(void)
    {
        char month[4];
        int days = 0;
        int total_days = 0;
        _Bool find = 0;
        int i = 0;

        while (find == 0)
        {
            total_days = 0;
            printf("Enter the abbreviation of month:");
            fgets(month, 4, stdin);

            for (i = 0; i < N_MONTH; i++)
            {
                total_days += info[i].month_days;
                if (strcmp(month, info[i].month) == 0)
                {
                    find = 1;
                    break;
                }
            }

            if (find == 1)
                printf("There are %d days till %s\n", total_days, month);
            else
                printf("The month of abbreviation is not found! Enter again.\n");
        }

        find = 0;
        while (find == 0)
        {
            printf("Enter the days of month:");
            scanf("%d", &days);
            if (days < info[i].month_days)
            {
                total_days += days;
                find = 1;
                printf("There %d days till %s %d\n", total_days, month, days);
            }
            else
                printf("The day of month is not found! Enter again.\n");
        }

        return;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	14.4.c
    #include <stdio.h>
    #define LEN 20
    struct name{
        char first[LEN];
        char middle[LEN];
        char last[LEN];
    };
    struct info{
        char id[LEN];
        struct name NAME;
    };
    int main(void)
    {
        struct info list[5] =
        {
            {
                {"302039823"},
                {"Dribble","Mascot","Flossie"}
            },
            {
                {"11223344"},
                {"Justin","X","Yu"}
            },
            {
                {"11223344"},
                {"Justin","X","Yu"}
            },
            {
                {"11223344"},
                {"Justin","X","Yu"}
            },
            {
                {"11223344"},
                {"Justin","X","Yu"}
            }
        };
        for(int i=0;i<5;i++)
        {
         printf("%s, %s %c. -- %s\n",list[i].NAME.first,list[i].NAME.last,list[i].NAME.middle[0],list[i].id);
        }
        return 0;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	14.5.c
    #include <stdio.h>
    #define LEN 20
    #define CSIZE 4
    struct name{
        char first[LEN];
        char last[LEN];
    };
    struct student{
        struct name NAME;
        float grade[3];
        float average;
    };
    void getscore(struct student ar[],int num);
    void getaverage(struct student ar[],int num);
    void print_mes(struct student ar[],int num);
    void print_ave(struct student ar[],int num);
    int main(void)
    {
        struct student list[CSIZE]={
            {"Justin", "Yu"},
            {"Zhihao","Dong"},
            {"Xuerui", "Gong"},
            {"Shaofei", "Wang"}
        };
        getscore(list,CSIZE);
        getaverage(list,CSIZE);
        print_mes(list,CSIZE);
        print_ave(list,CSIZE);
        return 0;
    }
    void getscore(struct student ar[],int num)
    {
        int i,j;
        for(int i=0;i<num;i++)
        {
            printf("Please enter %s %s's 3 scores: ",ar[i].NAME.first,ar[i].NAME.last);
            for(j=0;j<3;j++)
            {
                while(scanf("%f",&ar[i].grade[j])!=1)
                {
                    scanf("%*s");
                    puts("Invalid input!");
                }
            }
        }
    }
    void getaverage(struct student ar[],int num)
    {
        int i,j;
        float total;
        for(i=0;i<num;i++)
        {
            for(total=0,j=0;j<3;j++)
                total +=ar[i].grade[j];
            ar[i].average = total / 3;
        }
    }
    void print_mes(struct student ar[],int num)
    {
        int i,j;
        for(i=0;i<num;i++)
        {
            printf("%-10s %-10s ",ar[i].NAME.first,ar[i].NAME.last);
            for(j=0;j<3;j++)
                printf("%6.1f ",ar[i].grade[j]);
            printf(" Average is %6.1f.\n",ar[i].average);
        }
    }
    void print_ave(struct student ar[],int num)
    {
        int i,j;
        float sum;
        printf("\nThe average of whole class:\n");
        for(i=0;i<3;i++)
            for(sum=0,j=0;j<num;j++)
                sum += ar[j].grade[i];
        printf("%6.2f ",sum / num);
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	14.8.c
    #include <stdio.h>
    #define LEN 20
    #define FSIZE 12
    struct flight{
        int id;
        int isBook;
        char first[LEN];
        char last[LEN];
    };
    int get_emptynum(struct flight ar[],int num);
    void show_empty(struct flight ar[],int num);
    void show_seats(struct flight ar[],int num);
    void assign_seat(struct flight  ar[],int num);
    void delete_seat(struct flight ar[],int num);
    int main(void)
    {
        char choice;
        struct flight list[FSIZE]=
        {
            {1,0,"NULL","NULL"},
            {2,0,"NULL","NULL"},
            {3,1,"Justin","Yu"},
            {4,1,"Shaofei","Wang"},
            {5,0,"NULL","NULL"},
            {6,1,"Zhihao","Dong"},
            {7,0,"NULL","NULL"},
            {8,0,"NULL","NULL"},
            {9,0,"NULL","NULL"},
            {10,0,"NULL","NULL"},
            {11,0,"NULL","NULL"},
            {12,1,"Xuerui","Gong"}
        };
        printf("To choose a function,enter its letter label:\n");
        printf("a) Show number of empty seats\n");
        printf("b) Show list of empty seats\n");
        printf("c) Show alphabetical of seats\n");
        printf("d) Assign a customer to a seat assignment\n");
        printf("e) Delete a seat assignment\n");
        printf("f) Quit\n");
        while((choice=getchar())!='f')
        {
            while(getchar()!='\n')
                continue;
            switch(choice)
            {
                case'a':printf("There are %d empty seat.\n",
                               get_emptynum(list,FSIZE));
                               break;
                case'b':show_empty(list,FSIZE);
                        break;
                case'c':show_seats(list,FSIZE);
                        break;
                case'd':assign_seat(list,FSIZE);
                        break;
                case'e':delete_seat(list,FSIZE);
                        break;
                default:puts("Invalid choice!");
                        break;
            }
        }
        printf("Goodbye!\n");
        return 0;
    }
    int get_emptynum(struct flight ar[],int num)
    {
        int count=0;
        for(int i=0;i<num;i++)
        {
            if(ar[i].isBook==0)
                count++;
        }
        return count;
    }
    void show_empty(struct flight ar[],int num)
    {
        for(int i=0;i<num;i++)
        {
            if(ar[i].isBook==0)
                printf("%d ",ar[i].id);
        }
        printf("\n");
    }
    void show_seats(struct flight ar[],int num)
    {
        for(int i=0;i<num;i++)
        {
            printf("%d ",ar[i].id);
        }
        printf("\n");
    }
    void assign_seat(struct flight ar[],int num)
    {
        int choose;
        printf("Please choose your seat id:\n");
        if(scanf("%d",&choose)==1 && ar[choose-1].isBook == 0)
        {
            ar[choose].isBook = 1;
            printf("Booking success!\n");
        }
        else
            printf("The seat you choose cannot booked!\n");
        while(getchar()!='\n')
            continue;
    }
    void delete_seat(struct flight ar[],int num)
    {
        int choose;
        printf("Please choose your seat id:\n");
        if(scanf("%d",&choose)==1 && ar[choose-1].isBook == 1)
        {
            ar[choose].isBook = 0;
            printf("Booking success!\n");
        }
        else
            printf("The seat you choose hasn't been booked!\n");
        while(getchar()!='\n')
            continue;
    }

	{% endhighlight %}
	
---

	{% highlight ruby %}
	14.10.c
    #include <stdio.h>
    void fun_1(void);
    void fun_2(void);
    void fun_3(void);
    void fun_4(void);
    int main(void)
    {
        char ch;
        void (*pf[4])(void)={fun_1,fun_2,fun_3,fun_4}; //The only point of this function.
        printf("Here is the menu:\n");
        printf("a) Run function 1.\n");
        printf("b) Run function 2.\n");
        printf("c) Run function 3.\n");
        printf("d) Run function 4.\n");
        printf("q) Quit.\n");
        printf("Enter your choice: \n");
        while((ch=getchar())!= 'q')
        {
            while(getchar()!='\n')
                continue;
            switch(ch)
            {
                case'a':fun_1();
                        break;
                case'b':fun_2();
                        break;
                case'c':fun_3();
                        break;
                case'd':fun_4();
                        break;
                default:
                        printf("Invalid choice!\n");
                        break;
            }
        }
        printf("Bye!");
        return 0;
    }
    void fun_1(void)
    {
        printf("This is function 1.\n");
    }
    void fun_2(void)
    {
        printf("This is function 2.\n");
    }
    void fun_3(void)
    {
        printf("This is function 3.\n");
    }
    void fun_4(void)
    {
        printf("This is function 4.\n");
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	14.11.c
    #include <stdio.h>
    #include <math.h>
    double mul2(double x);
    double mul1(double x);
    void transform(double *source, double *target, int num, double (*fun)(double));
    int main(void)
    {
        double source[100];
        double target[100];

        for (int i = 0; i < 100; i++)
        {
            source[i] = i;
        }

        printf("Use sqr:\n");
        transform(source, target, 100, sqrt);
        for (int i = 0; i < 100; i++)
        {
            printf("%5.2f ", target[i]);
            if ((i + 1) % 10 == 0)
            {
                printf("\n");
            }
        }

        printf("Use sin:\n");
        transform(source, target, 100, sin);
        for (int i = 0; i < 100; i++)
        {
            printf("%5.2f ", target[i]);
            if ((i + 1) % 10 == 0)
            {
                printf("\n");
            }
        }

        printf("Use mul2:\n");
        transform(source, target, 100, mul2);
        for (int i = 0; i < 100; i++)
        {
            printf("%10.1f ", target[i]);
            if ((i + 1) % 10 == 0)
            {
                printf("\n");
            }
        }

        printf("Use mul1:\n");
        transform(source, target, 100, mul1);
        for (int i = 0; i < 100; i++)
        {
            printf("%10.1f ", target[i]);
            if ((i + 1) % 10 == 0)
            {
                printf("\n");
            }
        }
    }
    double mul2(double x)
    {
        return (x * 2.0);
    }
    double mul1(double x)
    {
        return (x * x);
    }
    void transform(double *source, double *target, int num, double (*fun)(double))
    {
        for (int i = 0; i < num; i++)
        {
            target[i] = fun(source[i]);
        }
    }
	{% endhighlight %}
	
---

  If you find there are faults in the source codes, any method connecting with me is welcomed.
