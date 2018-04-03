---
layout: post
title: "CPP Programming Assignment Chapter15"
description: "my own source codes of Programming Assignment in C Primer Plus "
categories: [C-Primer-Plus]
tags: [C]
redirect_from:
  - /2018/04/03/
---
# CPP Programming Assignment Chapter15


	{% highlight ruby %}
	15.1.c
    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include <stdbool.h>
    #define LEN 80
    int toint(char *ar);
    char *s_gets(char *st, int n);
    int main(void)
    {
        char twice[LEN];
        printf("Please enter the string :\n");
        s_gets(twice,LEN);
        printf("The number you entered is %d.\n",toint(twice));
        return 0;
    }
    int toint(char *ar)
    {
        int value=0;
        int i=strlen(ar);
        int j=0;
        while(i > 0 || j <strlen(ar))
        {
            value += ((int)pow(2,j) * (int)(ar[i-1]-'0'));
            i--;
            j++;
        }
        return value;
    }
    char *s_gets(char *st, int n)
    {
        char *ret_val;
        char *find;

        ret_val = fgets(st, n, stdin);
        if (ret_val)
        {
            find = strchr(st, '\n');
            if (find)
            {
                *find = '\0';
            }
            else
            {
                while (getchar() != '\n')
                {
                    continue;
                }
            }
        }
        return ret_val;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	15.2.c
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>
    #define LEN 80
    char *s_gets(char *st, int n);
    bool check(char *ar);
    char* adverse(char *ar1,char *temp);
    char* and(char *ar1,char *ar2,char *temp);
    char* or(char *ar1,char *ar2,char *temp);
    int main(void)
    {
        char a[LEN]={0};
        char b[LEN]={0};
        char c[LEN]={0};
        printf("Please input the binary numbers:\n");
        s_gets(a,LEN);
        while(!check(a))
        {
            printf("A binary number contains just 0s and 1s!.\n");
            printf("Please input again:\n");
            s_gets(a,LEN);
        }
        printf("Please input another binary numbers:\n");
        s_gets(b,LEN);
        while(!check(b))
        {
            printf("A binary number contains just 0s and 1s!.\n");
            printf("Please input again:\n");
            s_gets(b,LEN);
        }
        printf("The ~ operation:\n");
        adverse(a,c);
        printf("%s\n",c);
        adverse(b,c);
        printf("%s\n",c);
        printf("The & operation:\n");
        and(a,b,c);
        printf("%s\n",c);
        printf("The | operation:\n");
        or(a,b,c);
        printf("%s\n",c);
        puts("Done!");
        return 0;
    }
    bool check(char *ar)
    {
        bool res = true;
        while(res && *ar!='\0')
        {
            if(*ar != '0' && *ar != '1')
                res = false;
            ++ar;
        }
        return res;
    }
    char* adverse(char *ar1,char *temp)
    {
        while(*ar1!='\0')
        {
            if(*ar1 == '1')
                *temp = '0';
            else
                *temp = '1';
            ++ar1;
            ++temp;
        }
        return temp;
    }
    char* and(char *ar1,char *ar2,char *temp)
    {
        while ( *ar1 != '\0' && *ar2 != '\0')
        {
            if(*ar1 == '1' && *ar2 == '1')
                *temp = '1';
            else
                *temp = '0';
            ++ar1;
            ++ar2;
            ++temp;
        }
        return temp;
    }
    char* or(char *ar1,char *ar2,char *temp)
    {
        while ( *ar1 != '\0' && *ar2 != '\0')
        {
            if(*ar1 == '0' && *ar2 == '0')
                *temp = '0';
            else
                *temp = '1';
            ++ar1;
            ++ar2;
            ++temp;
        }
        return temp;
    }
    char *s_gets(char *st, int n)
    {
        char *ret_val;
        char *find;

        ret_val = fgets(st, n, stdin);
        if (ret_val)
        {
            find = strchr(st, '\n');
            if (find)
            {
                *find = '\0';
            }
            else
            {
                while (getchar() != '\n')
                {
                    continue;
                }
            }
        }
        return ret_val;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	15.3.c
    #include <stdio.h>
    #define LEN 80
    int getvalue(int n);
    int main(void)
    {
        int num;
        printf("Enter a number.\n");
        while(scanf("%d",&num) == 1)
            printf("The number of opened bits is %d.\nEnter next number(q to quit):",getvalue(num));
        return 0;
    }
    int getvalue(int n)
    {
        int i=0;
        while(n>=1)
        {
            if(n%2 == 1)
                i++;
            n=n/2;
        }
        return i;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	15.4.c
    #include <stdio.h>
    #define LEN 80
    int isOpen(int val,int pos);
    int main(void)
    {
        int val;
        int pos;
        printf("Enter your number and the position.\n");
        while(scanf("%d %d",&val,&pos) == 2)
        {
            if(isOpen(val,pos)==1 || isOpen(val,pos)==0)
                printf("The position you selected of this number is %d.\nEnter next value and position(q to quit):",isOpen(val,pos));
            else
                printf("Invalid position! Please input the value and position again!(q to quit):");
        }
        return 0;
    }
    int isOpen(int val,int pos)
    {
        int i=1;
        char temp[LEN];
        while(val>=1)
        {
            if(val%2 == 1)
                temp[i]=1;
            else
                temp[i]=0;
            i++;
            val=val/2;
        }
        if(i-pos>0)
            {
            if(temp[i-pos]==1)
                return 1;
            else
                return 0;
            }
        else
            return -1;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	15.5.c
    #include <stdio.h>
    #include <limits.h>
    #define LEN 80
    unsigned rotate_1(unsigned int, unsigned int);
    char * itobs(int,char*);
    int main(void)
    {
        unsigned int val;
        unsigned int rot;
        unsigned int places;
        char bstr1[CHAR_BIT * sizeof(int)+1];
        char bstr2[CHAR_BIT * sizeof(int)+1];
        printf("Enter a integer(q to quit): ");
        while(scanf("%ud",&val))
        {
            printf("Enter the number of bits to be rotated.\n");
            if(scanf("%ul",&places)!=1)
                break;
            rot = rotate_1(val,places);
            itobs(val,bstr1);
            itobs(rot,bstr2);
            printf("%u rotated is %u.\n",val,rot);
            printf("%s rotated is %s.\n",bstr1,bstr2);
            printf("Next value: ");
        }
        puts("Done");
        return 0;
    }
    unsigned int rotate_1(unsigned int n,unsigned int b)
    {
        static const int size = CHAR_BIT *  sizeof(int);
        unsigned int overflow;

        b%=size;
        overflow = n>> (size-b);
        return (n<<b)|overflow;
    }

    char * itobs(int n,char * ps)
    {
        int i;
        const static int size = CHAR_BIT * sizeof(int);
        for(i = size-1;i>=0;i--,n>>=1)
            ps[i] = (01 & n) +'0';
        ps[size] = '\0';
        return ps;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	15.7.c
    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>
    #define ID_MASK     0xFF
    #define SIZE_MASK   0x7F00
    #define LEFT        0x00000
    #define CENTER      0x08000
    #define RIGHT       0x10000
    #define ALIGN_MASK  0x18000
    #define REGULAR     0x00000
    #define BOLD        0x20000
    #define ITALIC      0x40000
    #define UNDERLINE   0x80000
    #define STYLE_MASK  0xE0000
    #define SIZE_SHIFT  8
    typedef unsigned long font;
    char do_menu(font * f);
    char get_choice(const char *);
    void show_menu(void);
    void show_font(font f);
    void eatline(void);
    void get_id(font * f);
    void get_size(font * f);
    void get_align(font * f);
    int main(void)
    {
        font sample = 1 | (12 <<SIZE_SHIFT) | LEFT | ITALIC;
        while (do_menu(&sample) != 'q')
            continue;
        puts("Bye!");
        return 0;
    }
     char do_menu(font * f)
     {
         char response;
         show_font(*f);
         show_menu();
         response = get_choice("fsabiuq");
         switch(response)
         {
             case 'f' : get_id(f);
                        break;
             case 's' : get_size(f);
                        break;
             case 'a' : get_align(f);
                        break;
             case 'b' : *f ^= BOLD;
                        break;
             case 'i' : *f ^= ITALIC;
                        break;
             case 'u' : *f ^= UNDERLINE;
                        break;
             case 'q' : break;
             default  : fprintf(stderr, "menu problem\n");
          }
          return response;
    }
     char get_choice(const char * str)
    {
        char ch;
        ch = getchar();
        ch = tolower(ch);
        eatline();
        while (strchr(str, ch) == NULL)
        {
            printf("Please enter one of the following: %s\n",str);
            ch = tolower(getchar());
            eatline();
        }
        return ch;
    }
     void eatline(void)
     {
         while (getchar() != '\n')
            continue;
     }
    void show_menu(void)
    {
        puts("f)change font    s)change size    a)change alignment");
        puts("b)toggle bold    i)toggle italic  u)toggle underline");
        puts("q)quit");
    }
     void show_font(font f)
     {
         printf("\n%4s %4s %9s %3s %3s %3s\n","ID", "SIZE", "ALIGNMENT", "B", "I", "U");
         printf("%4lu %4lu", f & ID_MASK, (f & SIZE_MASK) >> SIZE_SHIFT);
         switch(f & ALIGN_MASK)
         {
             case LEFT   : printf("%7s", "left"); break;
             case RIGHT  : printf("%7s", "right"); break;
             case CENTER : printf("%7s", "center"); break;
             default     : printf("%7s", "unknown"); break;
        }
        printf("%8s %3s %3s\n\n", (f & BOLD) == BOLD? "on" : "off",(f & ITALIC) == ITALIC ? "on" : "off",(f & UNDERLINE) == UNDERLINE ? "on" : "off");
    }
     void get_id(font * f)
     {
         int id;
         printf("Enter font ID (0-255): ");
         scanf("%d", &id);     id = id & ID_MASK;     *f |= id;     eatline();
    }
     void get_size(font * f)
     {
         int size;
         printf("Enter font size (0-127): ");
         scanf("%d", &size);     *f |= (size << SIZE_SHIFT) & SIZE_MASK;     eatline();
    }
     void get_align(font * f)
     {
         puts("Select alignment:");
         puts("l)left   c)center   r)right");
         switch (get_choice("lcr"))
         {
             case 'l' : *f &= ~ALIGN_MASK; *f |= LEFT; break;
             case 'c' : *f &= ~ALIGN_MASK; *f |= CENTER; break;
             case 'r' : *f &= ~ALIGN_MASK; *f |= RIGHT; break;
             default  : fprintf(stderr, "alignment problem\n");
         }
    }
    // This exercise is quite difficult for me. Thus I copied the answer from <<C Primer Plus Sixth Edition Programming Exercise Selected Answers>>.
	{% endhighlight %}
	
---

  If you find there are faults in the source codes, any method connecting with me is welcomed.
