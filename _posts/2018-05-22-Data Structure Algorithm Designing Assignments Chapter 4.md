---
layout: post
title: Data Structure Algorithm Designing Assignments Chapter 4
description: "my own source codes of Algorithm Designing Assignment in Data Structure"
categories: [Data-Structure]
tags: [C]
redirect_from:
  - /2018/05/22/
---
# Data Structure Algorithm Designing Assignments Chapter 4

	
---

    {% highlight ruby %}
 	4.10.c
    #include <stdio.h>
    #include "SequenceString.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    Status Algo_4_10(SString T,SString S);
    int main(void)
    {
        char *s = "Justin";
        SString S,T;
        printf("S = ");
        StrAssign_Sq(T,s);
        StrPrint_Sq(T);
        printf("\n");
        printf("T = ");
        Algo_4_10(T,S);
        StrPrint_Sq(S);
        printf("\n");
    }

    Status Algo_4_10(SString T,SString S)
    {
        int i;
        for(i=T[0];i>=1;i--)
            S[T[0]-i+1] = T[i];
        S[0] = T[0];
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

    {% highlight ruby %}

    {% endhighlight %}
    
---

If you find there are faults in the source codes, any method connecting with me is welcomed.
