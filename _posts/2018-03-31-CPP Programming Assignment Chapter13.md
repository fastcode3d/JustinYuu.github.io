---
layout: post
title: "CPP Programming Assignment Chapter13"
description: "my own source codes of Programming Assignment in C Primer Plus "
categories: [C-Primer-Plus]
tags: [C]
redirect_from:
  - /2018/03/31/
---
# CPP Programming Assignment Chapter13


	{% highlight ruby %}
	13.1.c
    #include <stdio.h>
    #include <stdlib.h> // exit() prototype
    #define LEN 80

    int main()
    {
        int ch;         // place to store each character as read
        FILE *fp;       // "file pointer"
        unsigned long count = 0;
        char name[LEN];
        printf("Please input the filename");
        scanf_s("%s",name,LEN);

        if ((fp = fopen(name, "r")) == NULL)
        {
            printf("Can't open %s\n", name);
            exit(EXIT_FAILURE);
        }
        while ((ch = getc(fp)) != EOF)
        {
            putc(ch,stdout);  // same as putchar(ch);
            count++;
        }
        fclose(fp);
        printf("File %s has %lu characters\n", name, count);

        return 0;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	13.2.c
    #include <stdio.h>
    #include <stdlib.h>
    int main(void)
    {
        FILE *fp1;
        FILE *fp2;
        char *file1 = "data1.dat";
        char *file2 = "data2.dat";
        int ch = 0;
        if((fp1=fopen(file1,"rb"))==NULL)
        {
            printf("Can't open%s\n",file1);
        }
        if((fp2=fopen(file2,"rb"))==NULL)
        {
            printf("Can't open%s\n",file2);
        }
        while ((ch = fgetc(fp1))!=EOF)
        {
            fputs(ch,fp2);
        }
        fclose(fp1);
        fclose(fp2);
        return 0;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	13.3.c
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #define LEN 80
    int main(void)
    {
        FILE *fp;
        int ch = 0;
        char name[LEN];
        printf("Enter the filename:\n");
        scanf_s("%s",name,LEN);
        if ((fp = fopen(name, "r")) == NULL)
        {
            printf("Can't open %s\n", name);
            exit(EXIT_FAILURE);
        }
        while ((ch = fgetc(fp)) != EOF)
        {
            ch = toupper(ch);
            fputc(ch, fp);
        }
        fclose(fp);
        return 0;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	13.4.c
    #include <stdio.h>
    #include <stdlib.h>
    #define LEN 256
    int main(int argc, char **argv)
    {
        FILE *fp;
        char name[LEN];
        for(int i=0;i<argc;i++)
        {
            if((fp=fopen(argv[i],"r"))==NULL)
            {
                printf("Can't open file %s",argv[i]);
            }
            printf("%s:\n",argv[i]);
            while(fgets(name,LEN,fp)!=NULL)
            {
                fputs(name,stdout);
            }
            printf("\n");
        }
        printf("Done!\n");
        return 0;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	13.5.c
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define BUFFSIZE 4096
    #define SLEN 81
    void append(FILE *source, FILE *dest)
    {
        size_t bytes;
        static char temp[BUFFSIZE];

        while ((bytes = fread(temp, sizeof(char), BUFFSIZE, source)) > 0)
        {
            fwrite(temp, sizeof(char), bytes, dest);
        }
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
    int main(int argc, char **argv)
    {
        FILE *fa, *fs;
        int files = 0;
        int ch;

        if (argc <3)
        {
            printf("Usage: %s dest_file source1_file ...\n", argv[0]);
            return 0;
        }

        if ((fa = fopen(argv[1], "a+")) == NULL)
        {
            fprintf(stderr, "Can't open %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        if (setvbuf(fa, NULL, _IOFBF, BUFFSIZE) != 0)
        {
            fputs("Can't create output buffer\n", stderr);
            exit(EXIT_FAILURE);
        }
        for (int i = 2; i < argc; i++)
        {
            if (strcmp(argv[1], argv[i]) == 0)
            {
                fputs("Can't append file to itself\n", stderr);
            }
            else if ((fs = fopen(argv[i], "r")) == NULL)
            {
                fprintf(stderr, "Can't open %s\n", argv[i]);
            }
            else
            {
                if (setvbuf(fs, NULL, _IOFBF, BUFFSIZE) != 0)
                {
                    fputs("Can't create input buffer\n", stderr);
                    continue;
                }
                append(fs, fa);
                if (ferror(fs) != 0)
                {
                    fprintf(stderr, "Error in reading file %s.\n", argv[i]);
                }
                if (ferror(fa) != 0)
                {
                    fprintf(stderr, "Error in writing file %s.n", argv[1]);
                }
                fclose(fs);
                files++;
                printf("File %s appended.\n", argv[i]);
            }
        }

        printf("Done appending. %d files appended.\n", files);
        rewind(fa);
        printf("%s contents:\n", argv[1]);
        while ((ch = getc(fa)) != EOF)
        {
            putchar(ch);
        }
        puts("Done displaying!\n");
        fclose(fa);

        return 0;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	13.6.c
    #define LEN 40
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
    int main(void)
    {
        FILE *in, *out;
        int ch;
        char out_file[LEN];
        char in_file[LEN];
        int count = 0;

        printf("Enter the file name:");
        gets_s(in_file, LEN);

        if ((in = fopen(in_file, "r")) == NULL)
        {
            fprintf(stderr, "I couldn't open the file\"%s\"", in_file);
            exit(EXIT_FAILURE);
        }

        strncpy(out_file, in_file, LEN-5);
        out_file[LEN - 5] = '\0';
        strcat(out_file, ".red");

        if ((out = fopen(out_file, "w")) == NULL)
        {
            fprintf(stderr, "Can't creat output file.\n");
            exit(3);
        }

        while ((ch = getc(in)) != EOF)
        {
            if (count++ % 3 == 0)
                putc(ch, out);
        }

        if (fclose(in) != 0 || fclose(out) != 0)
        {
            fprintf(stderr, "Error in closing files\n");
        }
        return 0;
    }
	{% endhighlight %}
	
---

	{% highlight ruby %}
	13.7.c
    #include <stdio.h>
    #include <stdlib.h>
    #define LEN 80
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
    int main(void)
    {
        FILE *fp1,*fp2;
        char name1[LEN];
        char name2[LEN];
        char buf1[LEN]={0};
        char buf2[LEN]={0};

        printf("Enter the first file name: ");
        gets_s(name1,LEN);
        printf("Enter the second file name: ");
        gets_s(name2,LEN);
        if ((fp1 = fopen(name1, "r")) == NULL)
        {
            printf("Can't open %s\n", name1);
        }
        if ((fp2 = fopen(name2, "r")) == NULL)
        {
            printf("Can't open %s\n", name2);
        }

        while ((feof(file1) == 0)||(feof(file2)==0))
        {
            if(fgets(buf1,LEN,name1)!=NULL)
            {
                int length =strlen(buf1);
                fputs(buf1,stdout);
            }
            if(fgets(buf2,LEN,name2)!=NULL)
            {
                fputs(buf2,stdout);
            }
        }
        return 0;
    }
	{% endhighlight %}
	
---

	{%highlight ruby%}
	13.8.c
    #include <stdio.h>
    #include <stdlib.h>
    #define LEN 80
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
    int main(int argc,char **argv)
    {
        FILE *fp;
        char find = 0;
        char ch = 0;
        char input[LEN]={0};
        int count = 0;
        if(argc<2)
        {
            printf("Usage:%s<character>[file_name1 ....]",argv[0]);
            return 0;
        }
        find = argv[1][0];
        if(argc == 2)
        {
            printf("Enter the string: ");
            gets_s(input,256);
            int length = strlen(input);
            for(int i=0;i<length;i++)
            {
                if(find == input[i])
                count++;
            }
        printf("In string \"%s\",%c have appeared %d time!\n",input ,find,count);
        }
        else
        {
            for (int i=2;i<argc;i++)
            {
                count=0;
                if((fp = fopen(argv[i],"r"))==NULL)
                {
                    printf("Can't open %s\n",argv[i]);
                    continue;
                }
                while ((ch = fgetc(fp))!=EOF)
                {
                    if(ch==find)
                        count++;
                }
                printf("In file %s,%c have appeared %d time!\n",argv[i],find,count);
            }
        }
    }
	{% endhighlight %}
	
---

	{%highlight ruby%}
	13.10.c
    #include <stdio.h>
    #include <stdlib.h>
    #define LEN 80
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
    int main(void)
    {
        char name[LEN];
        char s[LEN];
        FILE *fp;
        int loc = 0;
        printf("Enter the file name: \n");
        s_gets(name,LEN);
        if ((fp = fopen( name, "r")) == NULL)
        {
            fprintf(stderr, "I couldn't open the file\"%s\"", name);
            exit(EXIT_FAILURE);
        }
        while(1)
        {
            printf("Enter the location of letter in the file :(<0 to terminate):");
            if(fscanf(stdin,"%d",&loc)!=1||loc<0)
                break;
            fseek(fp,loc,SEEK_SET);
            fputs(loc,stdout);
            printf("%s",loc);
        }
        puts("Done!");
        fclose(fp);
        return 0;
    }

	{% endhighlight %}
	
---

	{%highlight ruby%}
	13.11.c
    #include <stdio.h>
    #include <stdlib.h>
    #define LEN 256
    int main(int argc,char **argv)
    {
        FILE *fp;
        char line[LEN];
        if(argc!=3)
        {
            printf("Usage:%s<character>[file_name1 ....]",argv[0]);
            exit(EXIT_FAILURE);
        }
        if((fp=fopen(argv[2],"r"))==NULL)
        {
            printf("Can't open file %s.\n",argv[2]);
        }
        while((fgets(line,LEN,fp))!=NULL)
        {
            if(strstr(line,argv[1])!=NULL)
                fputs(line,stdout);
        }
        return 0;
    }

	{% endhighlight %}
	
---

  If you find there are faults in the source codes, any method connecting with me is welcomed.
