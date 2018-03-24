---
layout: post
title: "CPP Programming Assignment Chapter8"
description: "my own source codes of Programming Assignment in C Premer Plus "
categories: [C-Primer-Plus]
tags: [C]
redirect_from:
  - /2018/03/24/
---
# CPP Programming Assignment Chapter8


	{% highlight ruby %}
	8.1.c
    #include <stdio.h>
    int main(void)
    {
        long num;
        int ch;
        while((ch=getchar())!= EOF)
        {
            num++;
        }
        printf("There are %ld characters in the text.\n",num);
    }
    {% endhighlight %}

---
	{% highlight ruby %}
	8.2.c
    #include <stdio.h>
    int main(void)
    {
        int ch;
        printf("Please input the text: \n");
        while((ch=getchar())!= EOF)
        {
            if(ch=='\n')
                printf("\\n %d\n",ch);
            else if(ch=='\t')
                printf("\\t %d\n",ch);
            else
            {
                putchar(ch);
                printf(" %d\n",ch);
            }
        }
    }
    {% endhighlight %}
	
---
	{% highlight ruby %}
	8.3.
    #include <stdio.h>
    int main(void)
    {
        int ch;
        printf("Please input the text: \n");
        while((ch=getchar())!= EOF)
        {
            if(ch=='\n')
                printf("\\n %d\n",ch);
            else if(ch=='\t')
                printf("\\t %d\n",ch);
            else
            {
                putchar(ch);
                printf(" %d\n",ch);
            }
        }
    }
    {% endhighlight %}
	
---
	{% highlight ruby %}
	8.4.c
    #include <stdio.h>
    #include <ctype.h>
    int main(void)
    {
        int ch;
        int n_t=0;
        int n_c=0;
        double n=0;
        printf("Please input the text:\n");
        while((ch=getchar())!= EOF)
        {
            if(islower(ch))
                n_t++;
            else if(isupper(ch))
                n_t++;
            else if((ch == '\n')||(ch == '\t')||(ch == ' '))
                n_c++;
        }
        n=n_t/n_c;
        if((n == 0.0)||(n == 1.0))
            printf("There are %.1f characters per word.\n",n);
        else
            printf("There are %.1f characters per word.\n",n);
        return 0;
    }
    {% endhighlight %}
	
---
	{% highlight ruby %}
	8.5.c
    #include <stdio.h>
    #include <ctype.h>
    int main(void)
    {
        int high = 100;
        int low = 1;
        int guess = (high + low) / 2;
        char response;
        printf("Pick an integer from 1 to 100.I will try to guess ");
        printf("it.\nRespond with a y if my guess is right and with");
        printf("\nan h if it is higher,a l if it is lower.\n");
        printf("Uh...is your number %d?\n", guess);
        while ((response=getchar()) != 'y')
        {
            if(response == '\n')
                continue;
            if(response != 'h' && response != 'l')
            {
                printf("Sorry ,I can't understand\nPlease input again!\n");
                continue;
            }
            else if (response == 'h')
            high = guess -1;
            else if (response == 'l')
            low = guess +1;
            guess = (high + low)/2;
           printf("Well , is %d your number?\n",guess);

        }
        printf("I knew I could do it!\n");
        return 0;
    }
	{% endhighlight %}

---
	{% highlight ruby %}
	8.6.c
    #include <stdio.h>
    char get_first(void)
    {
        char ch;
            while ((ch = getchar())!= '\n')
            {
                if ((ch ==' ')||(ch == '\t'))
                    {
                        continue;
                    }
                else
                    break;
            }
        return ch;
    }
    int main(void)
    {
        char ch;
        printf("Please input a word:\n");
        ch = get_first();
        putchar(ch);
        return 0;
    }
	{% endhighlight %}

---
	{% highlight ruby %}
	8.7.c
    #include <stdio.h>
    #include <ctype.h>
    char get_choice(void);
    char get_first(void);
    float get_num();
    int main(void)
    {
        int choice;
        float b;
        float a;
        void count(void);
        while ( (choice = get_choice()) != 'q')
        {
            switch (choice)
            {
                case 'a' :
                    printf("Enter first number:");
                    a = get_num();
                    printf("Enter second number:");
                    b = get_num();
                    printf("%.2f+%.2f=%.2f\n",a,b,a+b);
                    break;
                case 's' :
                    printf("Enter first number:");
                    a = get_num();
                    printf("Enter second number:");
                    b = get_num();
                    printf("%.2f+%.2f=%.2f\n",a,b,a-b);
                    break;
                case 'm' :
                    printf("Enter first number:");
                    a = get_num();
                    printf("Enter second number:");
                    b = get_num();
                    printf("%.2f+%.2f=%.2f\n",a,b,a*b);
                    break;
                case 'd' :
                    printf("Enter first number:");
                    a = get_num();
                    printf("Enter second number:");
                    b = get_num();
                    while (b == 0)
                        {
                            printf("Enter a number other than 0: ");
                            b = get_num();
                        }
                    printf("%.2f+%.2f=%.2f\n",a,b,a/b);
                    break;
                default  :  printf("Program error!\n");
                    break;
            }
        }
        printf("Bye.\n");

        return 0;
    }

    char get_choice(void)
    {
        int ch;

        printf("Enter the operation of your choice:\n");
        printf("a. add           s. subtract\n");
        printf("m. multiply      d.divide\n");
        printf("q.quit\n");
        ch = get_first();
        while (  ch != 'a' && ch != 's' && ch != 'q' && ch != 'm' && ch != 'd' )
        {
            printf("Please respond with a, s, m, d or q.\n");
            ch = get_first();
        }

        return ch;
    }

    char get_first(void)
    {
        int ch;

        ch = getchar();
        while (isspace(ch))
            ch = getchar();
        while (getchar() != '\n')
            continue;
        return ch;
    }

    float get_num()
    {
        float input;
        char ch;
        while(!scanf("%f",&input))
            {
                while((ch=getchar())!='\n')
                putchar(ch);
                printf(" is not a float number\nPlease enter a number, such as 2.15, -1.78E8, or  3:");
            }
        return input;
    }
    {% endhighlight %}
	
---

  If you find there are faults in the source codes, any method connecting with me is welcomed.
