---
layout: post
title: "CPP Programming Assignment Chapter4"
description: "my own source codes of Programming Assignment in C Primer Plus "
categories: [C-Primer-Plus]
tags: [C]
redirect_from:
  - /2018/03/22/
---
# CPP Programming Assignment Chapter4

    {% highlight ruby %}
	4.1.c
    #include <stdio.h>
	int main(void)
	{
	    char first[15],last[15];
	    printf("Please input your name:\n");
	    scanf("%s %s", &first, &last);
	    printf("Your name is %s,%s\nd", last, first);
	    return 0;
	}
	    {% endhighlight %}
	
---

    {% highlight ruby %}
	4.2.c
	#include <stdio.h>
	#include <string.h>
	int main(void)
	{
	    char name[40];
	    printf("Please input your first name:\n");
	    scanf("%s", name);
	    printf("Your first name is \"%s\"\n", name);
	    printf("Your first name is \"%+20s\"\n", name);
	    printf("Your first name is \"%-20s\"\n", name);
	    printf("Your first name is \"%*s\"", strlen(name)+3,name);
	    return 0;
	}
	{% endhighlight %}

---

    {% highlight ruby %}
	4.3.c
	#include <stdio.h>
	int main(void)
	{
    	float length;
    	printf("Please input the length: \n");
    	scanf("%f" , &length);
    	printf("The input is %.1f or %1.1e.\n", length, length);
    	printf("The input is %+.3f or %1.3E.\n", length, length);
    	return 0;
	}
	{% endhighlight %}
		
---

    {% highlight ruby %}
	4.4.c
	#include <stdio.h>
	int main(void)
	{
	    float height;
	    char name[40];
	    printf("Please input your name:\n");
	    scanf("%s", name);
	    printf("Please input your height in centimeters:\n");
	    scanf("%f", &height);
	    height = height * 0.01;
	    printf("%s, you are %.2f meters tall", name, height);
	    return 0;
	}
	{% endhighlight %}
		
---

    {% highlight ruby %}
	4.5.c
	#include <stdio.h>
	int main(void)
	{
	    float megabytes;
	    float bps;
	    float time;
	    printf("Please input your download megabits per second: \n");
	    scanf("%f", &bps);
	    printf("Please input the megabytes of the file: \n");
	    scanf("%f", &megabytes);
	    time = megabytes * 8 / bps;
	    printf("At %.2f megabits per second, a file of %.2f megabytes\ndownloads in %.2f seconds.", bps, megabytes, time);
	   	return 0;
	}
	{% endhighlight %}
		
---

    {% highlight ruby %}
	4.6.c
	#include <stdio.h>
	#include <string.h>
	int main(void)
	{
	    char fname[40];
	    char lname[40];
	    int fnamenum;
	    int lnamenum;
	    printf("Please input your first name:\n");
	    scanf("%s", fname);
	    fnamenum = strlen(fname);
	    printf("Please input your last name:\n");
	    scanf("%s", lname);
	    lnamenum = strlen(lname);
	    printf("%s %s\n", fname, lname);
	    printf("%*d %*d\n",fnamenum,fnamenum,lnamenum,lnamenum);
	    printf("%s %s\n", fname, lname);
	    printf("%-*d %-*d\n",fnamenum,fnamenum,lnamenum,lnamenum);
	    return 0;
	}
	{% endhighlight %}
				
---

    {% highlight ruby %}
	4.7.c
	#include <stdio.h>
	#include <float.h>
	int main(void)
	{
	    float ot_f = 1.0/ 3.0;
	    double ot_d = 1.0 / 3.0;
	    printf("%-20.6f,%-20.6f\n", ot_f, ot_d);
	    printf("%-20.12f,%-20.12f\n", ot_f, ot_d);
	    printf("%-20.16f,%-20.16f\n", ot_f, ot_d);
	    printf("FLT_DIG: %f\n", FLT_DIG);
	    printf("DBL_DIG: %f\n", DBL_DIG);
	    return 0;
	}
	{% endhighlight %}
		
---

    {% highlight ruby %}
	4.8.c
	#include <stdio.h>
	#include <string.h>
	#define GALLON_L 3.785
	int main(void)
	{
	    float miles;
	    float gallons;
	    float km;
	    float litre;
	    float mperg;
	    float lper100km;
	    const float MILE_KM = 1.609;
	    printf("Please input the miles: \n");
	    scanf("%f",&miles);
	    printf("Please input the use of gallons: \n");
	    scanf("%f",&gallons);
	    mperg = miles/gallons;
	    printf("You drive %.1f miles per gallon.\n",mperg);
	    litre = gallons * GALLON_L;
	    km = miles * MILE_KM;
	    lper100km=litre/100/km;
	    printf("You use %.1fL gasoline per 100km\n",lper100km);
	    return 0;
	}
	{% endhighlight %}
		
---
  If you find there are faults in the source codes, any method connecting with me is welcomed.
	
