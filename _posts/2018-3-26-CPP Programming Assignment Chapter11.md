---
layout: post
title: "CPP Programming Assignment Chapter11"
description: "my own source codes of Programming Assignment in C Primer Plus "
categories: [C-Primer-Plus]
tags: [C]
redirect_from:
  - /2018/03/26/
---
# CPP Programming Assignment Chapter11


	{% highlight ruby %}
	11.1.c
	#include <stdio.h>
    char * s_get(char *str,int n);
    int main(void)
    {
        int n=9;
        char check;
        char a[10];
        printf("Please input your strings.(no more than 9 words):\n");
        check = s_get(a,n);
        if(check ==0)
            puts("Input failed.");
        else
            puts(a);
        puts("Done.\n");
        return 0;
    }
    char * s_get(char *str,int n)
    {
        int i;
        int ch;
        for(i=0;i<n;i++)
        {
            ch=getchar();
            if  (ch!=EOF)
                str[i]=ch;
            else break;
        }
        if (ch==EOF)
            return NULL;
        else
        {
            str[i]='\0';
            return str;
        }
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	11.2.c
    #include <stdio.h>
    char * s_get(char *str,int n);
    int main(void)
    {
        int n=9;
        char check;
        char a[10];
        printf("Please input your strings.(no more than 9 words):\n");
        check = s_get(a,n);
        if(check ==0)
            puts("Input failed.");
        else
            puts(a);
        puts("Done.\n");
        return 0;
    }
    char * s_get(char *str,int n)
    {
        int i;
        int ch;
        for(i=0;i<n;i++)
        {
            ch=getchar();
            if  (ch!='\n'&&ch!='\t'&&ch!=' ')
                str[i]=ch;
            else
                break;
        }
        if (ch=='\n'||ch=='\t'||ch==' ')
            return NULL;
        else
        {
            str[i]='\0';
            return str;
        }
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	11.3.c
    #include <stdio.h>
    #include <ctype.h>
    #define LEN 10
    char * s_get(char *str);
    int main(void)
    {
        char input[LEN];
        printf("Please input your strings:\n");
        while (s_get(input)!=NULL)
            puts(input);
        puts("Done!\n");
        return 0;

    }
    char * s_get(char *str)
    {
        char *a = str;
        int ch;
        while((ch=getchar()) !=EOF && isspace(ch))
            continue;
        if (ch == EOF)
            return NULL;
        else
            *str++=ch;
        while ((ch=getchar()!=EOF && !isspace(ch)))
            *str++=ch;
        *str = '\0';
        if (ch ==EOF)
            return NULL;
        else
        {
            while (ch != '\n')
                ch = getchar();
            return a;
        }
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	11.5.c
    #include <stdio.h>
    #include <stdbool.h>
    #define LEN 20
    char *findstr(char *a,char c,int n);
    int main(void)
    {
        char str[LEN]="Hello,ChangingWorld!";
        char c='c';
        char res = findstr(str,c,LEN);
        printf("%c %p",res,&res);
        return 0;
    }
    char *findstr(char *a,char c,int n)
    {
        int i;
        bool isFind;
        isFind = false;
        for(i=0;i<n;i++)
        {
            if(*(a+i)==c)
            {
                isFind = true;
                return *(a+i);
                break;
            }
        }
        if (isFind == false)
            return NULL;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	11.6_1.c
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>
    #define LEN 80
    bool is_within(char c ,const char *str);
    char *s_gets(char *st,int n);
    int main(void)
    {
        char input[LEN];
        char ch;
        int found;

        printf("Enter a string: ");
        while (s_gets(input,LEN)&&input[0]!='\0')
        {
            printf("Enter a character: ");
            ch = getchar();
            while (getchar()!='\n')
                continue;
            found = is_within(ch,input);
            if(found ==0)
                printf("%c not found in string.\n",ch);
            else
                printf("%c found in string %s\n",ch,input);
            printf("Next string: ");
        }
        puts("Done!\n");
        return 0;
    }
    bool is_within(char c,const char *str)
    {
        while(*str !=c && *str!='\0')
            str++;
        return *str;
    }
    char *s_gets(char *st,int n)
    {
        char *ret_val;
        char *find;

        ret_val = fgets(st,n,stdin);
        if(ret_val)
        {
            find = strchr(st,'\n');
            if(find)
                *find='\0';
            else
                while(getchar()!='\n')
            continue;
        }
        return ret_val;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	11.6_2.c
    #include <stdio.h>
    #include <stdbool.h>
    #define LEN 80
    bool is_within(char c ,const char *str);
    int main(void)
    {
        char input[LEN]="Hello,World!";
        char ch='c';
        if(is_within(ch,input))
            printf("The character %c is in the string %s.\n",ch,input);
        else
            printf("The character %c is not in the string %s.\n",ch,input);
        return 0;
    }
    bool is_within(char c,const char *str)
    {
        /*while(*str !=c && *str!='\0')
            str++;
        return *str;*/                /*one possible way to build is_within() function.*/
        bool isFind=false;
        for (;*str!='\0';*str++)
            if(*str==c)
            {
                isFind=true;
                break;
            }
        return isFind;                /*another possible way to build is_within() function;*/
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	11.7.c
    #include <stdio.h>
    #include <string.h>
    #define LEN 80
    char *mystrncpy(char *s1,char *s2,int n);
    char *s_gets(char *st,int n);
    int main(void)
    {
        char dest[LEN];
        char souc[LEN];
        int n;
        char * res;

        printf("Enter a string: ");
        s_gets(dest,LEN);
        printf("Enter another string: ");
        s_gets(souc,LEN);
        mystrncpy(dest,souc,n);
        puts(dest);
        puts("Done!\n");
        return 0;
    }
    char * mystrncpy(char *s1,char *s2,int n)
    {
        int s1_length = strlen(s1);
        int s2_length = strlen(s2);
        int copy_length = (s2_length >= n ? n : s2_length);

        for (size_t i = 0; i < copy_length; i++)
        {
            s1[s1_length + i] = s2[i];
        }

        if (s2_length < n)
        {
            s1[s1_length + s2_length] = '\0';
        }
        return s1;
    }
    char *s_gets(char *st,int n)
    {
        char *ret_val;
        char *find;

        ret_val = fgets(st,n,stdin);
        if(ret_val)
        {
            find = strchr(st,'\n');
            if(find)
                *find='\0';
            else
                while(getchar()!='\n')
            continue;
        }
        return ret_val;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	11.8.c
    #include <stdio.h>
    #include <string.h>
    #define LEN 80
    char *string_in(char *a,char *b)
    {
        int m,n;
        int a_len = strlen(a);
        int b_len = strlen(b);
        for(int i=0;i<a_len;i++)
        {
            n=i;
            m=0;
            while(a[n]==b[m])
            {
                n++;
                m++;
                if(m>=b_len)
                {
                    return &a[i];
                }
            }
        }
        return NULL;
    }
    char *s_gets(char *st,int n)
    {
        char *ret_val;
        char *find;

        ret_val = fgets(st,n,stdin);
        if(ret_val)
        {
            find = strchr(st,'\n');
            if(find)
                *find='\0';
            else
                while(getchar()!='\n')
            continue;
        }
        return ret_val;
    }
    int main(void)
    {
        char s1[LEN];
        char s2[LEN];
        char * res;

        printf("Enter a string: ");
        s_gets(s1,LEN);
        printf("Enter another string: ");
        s_gets(s2,LEN);
        res = string_in(s1,s2);
        if(NULL == res)
            printf("%s is not in %s!\n",s2,s1);
        else
            printf("%s is in %s,and the header's address is %p!\n",s2,s1,res);
        puts("Done!\n");
        return 0;
    }
	{% endhighlight %}
	
---

	{% highlight ruby%}
	11.9.c
    #include <stdio.h>
    #include <string.h>
    #define LEN 80
    char *conversion(char *a);
    int main(void)
    {
        char s[LEN]="Hello world!";
        puts(s);
        printf("\n");
        conversion(s);
        puts(s);
        return 0;
    }
    char *conversion(char *a)
    {
        int a_len = strlen(a);
        char b[a_len];
        for(int i=0;i<a_len;i++)
            b[a_len-i-1]=a[i];
        for(int j=0;j<a_len;j++)
            a[j]=b[j];
        return *a;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	11.10.c
    #include <stdio.h>
    #include <string.h>
    #define LEN 80
    char *s_gets(char *st,int n);
    void s_delspa(char *s);
    int main(void)
    {
        char s[LEN];
        printf("Enter a string: \n");
        while(s_gets(s,LEN)&& s[0]!='\0')
        {
        printf("Your string without space is:");
        s_delspa(s);
        puts(s);
        }
        puts("Done!\n");
        return 0;
    }
    void s_delspa(char *s)
    {
        char *pos;
        while(*s)
        {
            if(*s == ' ')
            {
                pos = s;
                do
                {
                    *pos = *(pos +1);
                    pos++;
                }   while( *pos);
            }
            else
                s++;
        }
    }
    char *s_gets(char *st,int n)
    {
        char *ret_val;
        char *find;

        ret_val = fgets(st,n,stdin);
        if(ret_val)
        {
            find = strchr(st,'\n');
            if(find)
                *find='\0';
            else
                while(getchar()!='\n')
            continue;
        }
        return ret_val;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	11.11.c
    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>
    #include <stdbool.h>
    #define LEN 180
    int check_firlen(char* str);
    char *s_gets(char *st,int n);
    void print_str(char *str[10],int str_num);
    void print_byascii(char str[][LEN],int str_num);
    void print_origstr(char str[][LEN],int str_num);
    void print_bylen(char str[][LEN],int str_num);
    void print_byfir(char str[][LEN],int str_num);
    int main(void)
    {
        char str[10][LEN];
        int str_num=0;
        printf("Welcome to the choosing program!\n");
        printf("Now please Enter 10 strings(EOF to quit).\n");
        for(int i=0;i<10;i++)
        {
        s_gets(str[i],LEN);
        if(str[i][0]=='\0')
            break;
        str_num++;
        }
        do
        {
            printf("Menu:\n");
            printf("%-30s\n%-30s\n%-30s\n%-30s\n%-30s\n","a) print original strings.","b) print strings sorted by ASCII code.","c) print strings sorted by length.",
                   "d) print strings sorted by first word.","q) quit");
            char ch=getchar();
            getchar();
            switch(ch)
            {
            case 'a':
                    print_origstr(str,str_num);
                    break;
            case 'b':
                    print_byascii(str,str_num);
                    break;
            case 'c':
                    print_bylen(str,str_num);
                    break;
            case 'd':
                    print_byfir(str,str_num);
                    break;
            case 'q':
                    printf("Done and quit!\n");
                    return 0;
            default:
                    printf("Illegal input! Please input number 0-4.\n");
                    break;
            }
        }   while(1);
    }
    void print_str(char *str[10],int str_num)
    {
        for(int i=0;i< str_num;i++)
        {
            printf("%d: ",i);
            puts(str[i]);
        }
        return;
    }
    void print_origstr(char str[][LEN],int str_num)
    {
        char* str_orig[10];
        bool sort = 0;

        if(sort !=1)
        {
            for(int i=0;i<str_num;i++)
                str_orig[i]=str[i];
            sort = 1;
        }
        printf("The original strings: \n");
        print_str(str_orig,str_num);
    }
    void print_byascii(char str[][LEN],int str_num)
    {
        char* str_ascii[10];
        bool  sort = 0;
        if(sort !=1)
        {
            for(int i=0;i<str_num;i++)
                str_ascii[i]=str[i];
            for(int i=0;i<str_num;i++)
            {
                for(int j=0;j<str_num;j++)
                {
                    int result = strcmp(str_ascii[i],str_ascii[j]);
                    if (result>0)
                    {
                        char* tmp = str_ascii[i];
                        str_ascii[i]=str_ascii[j];
                        str_ascii[j] = tmp;
                    }
                }
            }
            sort = 1;
        }
        printf("The strings printed by ASCII code is: \n");
        print_str(str_ascii,str_num);
    }
    void print_bylen(char str[][LEN],int str_num)
    {
        char* str_bylen[10];
        bool sort = 0;
        if(sort !=1)
        {
            for(int i=0;i<str_num;i++)
                str_bylen[i]=str[i];
            for(int i=0;i<str_num;i++)
            {
                for(int j=0;j<str_num;j++)
                {
                    if(strlen(str_bylen[i])<strlen(str_bylen[j]))
                    {
                        char* tmp = str_bylen[j];
                        str_bylen[j]=str_bylen[i];
                        str_bylen[i]= tmp;
                    }
                }
            }
            sort = 1;
        }
        printf("The string sorted by length is: \n");
        print_str(str_bylen,str_num);
    }
    void print_byfir(char str[][LEN],int str_num)
    {
        char* str_byfir[10];
        bool sort = 0;
        if(sort != 1)
        {
            for(int i=0;i<str_num;i++)
                str_byfir[i]=str[i];
            for(int i=0;i<str_num;i++)
            {
                for(int j=0;j<str_num;j++)
                {
                    if(check_firlen(str_byfir[i]) < check_firlen(str_byfir[j])) 
		    								/*pointer in 2-dimension array*/
                    {
                        char* tmp = str_byfir[j];
                        str_byfir[j]=str_byfir[i];
                        str_byfir[i]= tmp;
                    }
                }
            }
            sort = 1;
        }
        printf("The string sorted by first letter's length is: \n");
        print_str(str_byfir,str_num);
    }
    int check_firlen(char* str)
    {
        int result = 0;
        int str_len = strlen(str);

        for (int i = 0;i<str_len;i++)
        {
                if (isspace(str[i]))
            {
                return i;
            }
        }
        return str_len;
    }
    char *s_gets(char *st,int n)
    {
        char *ret_val;
        char *find;

        ret_val = fgets(st,n,stdin);
        if(ret_val)
        {
            find = strchr(st,'\n');
            if(find)
                *find='\0';
            else
                while(getchar()!='\n')
            continue;
        }
        return ret_val;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	11.12.c
    #include <stdio.h>
    #include <ctype.h>
    #define LEN 80
    char *s_gets(char *st,int n);
    int main(void)
    {
     char str[LEN];
        int str_len = 0;
        int n_word = 0;
        int n_upper = 0;
        int n_lower = 0;
        int n_punch = 0;
        int n_num = 0;
        printf("Enter the string:");
        s_gets(str,LEN);
        str_len = strlen(str);

        for (size_t i = 0; i <= str_len; i++)
        {
            if (isspace(str[i]) || '\0' == str[i])
            {
                n_word++;
            }
            else if (isupper(str[i]))
            {
                n_upper++;
            }
            else if (islower(str[i]))
            {
                n_lower++;
            }
            else if (ispunct(str[i]))
            {
                n_punch++;
            }
            else if (isdigit(str[i]))
            {
                n_num++;
            }
        }

        printf("String %s contains %d word, %d upper character, %d lower character, %d punchation, %d digital!\n", str, n_word,
                n_upper, n_lower, n_punch, n_num);

        return;
    }
    char *s_gets(char *st,int n)
    {
        char *ret_val;
        char *find;

        ret_val = fgets(st,n,stdin);
        if(ret_val)
        {
            find = strchr(st,'\n');
            if(find)
                *find='\0';
            else
                while(getchar()!='\n')
            continue;
        }
        return ret_val;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	11.13.c
	#include <stdio.h>
    int main(int argc, char **argv)
    {
        for (int  i = argc - 1; i > 0; i--)
        {
            printf("%s ", argv[i]);
        }

        return;
    }
	
	{% endhighlight %}
	
---

	{% highlight ruby %}
	11.14.c
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    int main(int argc, char **argv)
    {
        double num,exp,result;
        if (argc != 3)
            printf("Usage: %s number exponent\n",argv[0]);
        else
        {
            num = atof(argv[1]);
            exp = atoi(argv[2]);
            result = pow(num, exp);
            printf("base:%lf, index:%d, result:%lf", num, exp, result);
        }

    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	11.15.c
    #include <stdio.h>
    #include <ctype.h>
    #define LEN 80
    char *s_gets(char *st,int n);
    int atoi_rewrite(char *str);
    int main(void)
    {
        char str[LEN];
        int result = 0;

        printf("Enter a integer number:");
        s_gets(str, LEN);
        result = atoi_rewrite(str);

        printf("string %s to integer %d\n", str, result);
    }
    int atoi_rewrite(char *str)
    {
        int str_len = strlen(str);
        int result = 0;

        for (int i = 0; i < str_len; i++)
        {
            if (!isdigit(str[i]))
            {
                return 0;
            }
            result = result * 10 + (str[i] - '0');
        }
    }
    char *s_gets(char *st,int n)
    {
        char *ret_val;
        char *find;

        ret_val = fgets(st,n,stdin);
        if(ret_val)
        {
            find = strchr(st,'\n');
            if(find)
                *find='\0';
            else
                while(getchar()!='\n')
            continue;
        }
        return ret_val;
    }
	{% endhighlight %}
	
---
  If you find there are faults in the source codes, any method connecting with me is welcomed.
