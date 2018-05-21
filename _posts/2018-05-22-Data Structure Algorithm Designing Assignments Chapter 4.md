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
	4.11.c
    #include <stdio.h>
    #include "SequenceString.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    Status Algo_4_11(SString R,SString T,SString S,int a[]);
    int main(void)
    {
        int a[MAXSTRLEN+1];
        char *s = "asdakjfhkasfhkajf";
        char *t = "ssadafslkd";
        SString T,R,S;
        int i;
        StrAssign_Sq(S,s);
        StrAssign_Sq(T,t);
        printf("Hello!\n");
        printf("S = ");
        StrPrint_Sq(S);
        printf("\n");
        printf("T = ");
        StrPrint_Sq(T);
        printf("\n");
        Algo_4_11(R,T,S,a);
        printf("R = ");
        StrPrint_Sq(R);
        printf("\n");
        printf("a = ");
        for(i=0;i<=a[0];i++)
            printf("%d ",a[i]);
        return 0;
    }

    Status Algo_4_11(SString R,SString T,SString S,int a[])
    {
        int i,p;
        SString Tmp;
        StrAssign_Sq(R,"");
        Tmp[0] = 1;
        for(i=1,a[0] = 0;i<=S[0];i++)
        {
            Tmp[1] = S[i];

            p = Index_Sq_1(T,Tmp,1);
            if(!p)
                p = Index_Sq_1(R,Tmp,1);
            if(!p)
            {
                a[0]++;
                a[a[0]]=i;
                StrInsert_Sq(R,a[0],Tmp);
            }
        }
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	4.12.c
    #include <stdio.h>
    #include "SequenceString.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    Status Algo_4_12(SString S,SString T,SString V);
    int main(void)
    {
        char *s = "I am Justin Yu.";
        char *t = "Justin Yu.";
        char *v = "Yu Jiashuo.";
        SString S,T,V;
        StrAssign_Sq(S,s);
        StrAssign_Sq(T,t);
        StrAssign_Sq(V,v);
        printf("S = ");
        StrPrint_Sq(S);
        printf("\n");
        printf("T = ");
        StrPrint_Sq(T);
        printf("\n");
        printf("V = ");
        StrPrint_Sq(V);
        printf("\n\n");
        Algo_4_12(S,T,V);
        printf("S = ");
        StrPrint_Sq(S);
        return 0;
    }

    Status Algo_4_12(SString S,SString T,SString V)
    {
        int i;
        i = Index_Sq_2(S,T,1);
        while(S[0]-T[0]+V[0]<=MAXSTRLEN && i)
        {
            StrDelete_Sq(S,i,T[0]);
            StrInsert_Sq(S,i,V);
            i += V[0];
            i = Index_Sq_2(S,T,i);
        }
        if(i == 0)
            return OK;
        else
            return ERROR;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	4.13.c
    #include <stdio.h>
    #include "SequenceString.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    Status Algo_4_13(SString S,SString T);
    int main(void)
    {
        char *s = "I am Justin Yu.";
        char *t = "Justin Yu.";
        SString S,T;
        StrAssign_Sq(S,s);
        StrAssign_Sq(T,t);
        printf("S = ");
        StrPrint_Sq(S);
        printf("\n");
        printf("T = ");
        StrPrint_Sq(T);
        printf("\n");
        Algo_4_13(S,T);
        printf("S = ");
        StrPrint_Sq(S);
        return 0;
    }
    Status Algo_4_13(SString S,SString T)
    {
        int i;
        for(i=1;i = Index_Sq_1(S,T,1);i++)
            StrDelete_Sq(S,i,T[0]);
        return OK;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	4.14.c
    #include <stdio.h>
    #include "SequenceString.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Chapter3\SequenceStack.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Chapter2\SequenceList.c"

    Status Algo_4_14(SqList S,SString T)
    {
        int i;
        SString e1,e2,tmp;
        SqStack S;
        InitStack_Sq(&S);
        for(i=S.length-1;i>=0;i--)
        {
            tmp[0]=1;
            tmp[1]=P.elem[i];
            if(isalpha(P.elem[i]))
                Push_Sq(&s,tmp);
            else
            {
                Pop_Sq(&S,&e1);
                Pop_Sq(&S,&e2);
                Concat_Sq(e1,e1,e2);
                Concat_Sq(e1,e1,tmp);
                Push_Sq(&S,e1);
            }
        }
        Pop_Sq(&s,&tmp);
        StrCopy_Sq(T,tmp);
        if(S.base == S.top)
            return OK;
        else
            return ERROR;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	4.15.c
    #include <stdio.h>
    #include <string.h>
    #include "SequenceString.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    Status Algo_4_15(SString T,char *chars);
    int main(void)
    {
        SString T;
        char *t = "I am Justin";
        Algo_4_15(T,t);
        StrPrint_Sq(T);
        return 0;
    }

    Status Algo_4_15(SString T,char *chars)
    {
        int i,len;
        len = strlen(chars);
        if(len>MAXSTRLEN)
            return ERROR;
        else
        {
            T[0] = len;
            for(i=1;i<=len;i++)
                T[i]=chars[i-1];
            return OK;
        }
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	4.16.c
    #include <stdio.h>
    #include "SequenceString.c"

    int Algo_4_16(SString S,SString T);
    int main(void)
    {
        SString S,T;
        char *s = "I am Justin Yu";
        char *t = "I am Justin Xu";
        StrAssign_Sq(S,s);
        StrAssign_Sq(T,t);
        printf("%d",Algo_4_16(S,T));
        return 0;
    }

    int Algo_4_16(SString S,SString T)
    {
        int i=0;
        while(i<=S[0]&&i<=T[0])
        {
            if(S[i]==T[i])
                i++;
            else
                return S[i]-T[i];
        }
        return S[0]-T[0];
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	4.17.c
    #include <stdio.h>
    #include "SequenceString.c"

    Status Algo_4_17(SString S,SString T,SString V);
    int main(void)
    {
        return 0;
    }

    Status Algo_4_17(SString S,SString T,SString V)
    {
        int count = 1;
        int i,j,k;
        SString Tmp_beh;

        i = count;
        j = 1;
        while(i>1 && i<=S[0] && j<=T[0])
        {
            if(S[i]==T[j])
            {
                i++;
                j++;
            }
            else
            {
                i = i - (j-1) +1;
                j = 1;
            }
        }
        if(j>T[0] && T[0]!=0)
            count = i - T[0];
        else
            count = 0;

        while(S[0]-T[0]+V[0]<=MAXSTRLEN && count!=0)
        {
            Tmp_beh[0] = S[0]-i+1;
            for(k=1;k<=S[0]-i+1;k++)
                Tmp_beh[k] = S[k+i-1];
            S[0]=S[0] - T[0] + V[0];
            for(k=1;k<=V[0];k++)
                S[k+count-1] = V[k];
            for(k=count+V[0];k<=S[0];k++)
                S[k]=Tmp_beh[k-count-V[0]+1];
            count += V[0];
            i = count;
            j = 1;
            while(i>=1 && i<=S[0] && j<=T[0])
            {
                if(S[i]==T[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    i = i-(j-1) +1;
                    j = 1;
                }
            }
            if(j>T[0]&&T[0]!=0)
                count = i-T[0];
            else
                count = 0;
        }
        if(count = 0)
            return OK;
        else
            return ERROR;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	4.18.c
    #include <stdio.h>
    #include "SequenceString.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    Status Algo_4_18(SString S,int c[]);
    int main(void)
    {
        int c[128]={0};
        SString S;
        int i;
        char *s = "asdjkahdo21iksadkjadfoi1he2#Qsadkjsad[]hd";
        StrAssign_Sq(S,s);
        printf("S = ");
        StrPrint_Sq(S);
        printf("\n");
        Algo_4_18(S,c);
        for(i=1;i<=127;i++)
        {
            if(c[i]!=0)
                printf("%c = %d\n",i,c[i]);
        }
        return 0;
    }

    Status Algo_4_18(SString S,int c[])
    {
        int i;

        for(i = 0; i <= S[0]; i++)
        {
            if(!c[S[i]])
                c[0]++;
            c[S[i]]++;
        }
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	4.19.c
    #include <stdio.h>
    #include "SequenceString.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    Status Algo_4_19(SString R,SString S,SString T,int a[]);

    int main(void)
    {
        int a[MAXSTRLEN+1];
        char *s = "asdakjfhkasfhkajf";
        char *t = "ssadafslkd";
        SString T,R,S;
        int i;
        StrAssign_Sq(S,s);
        StrAssign_Sq(T,t);
        printf("Hello!\n");
        printf("S = ");
        StrPrint_Sq(S);
        printf("\n");
        printf("T = ");
        StrPrint_Sq(T);
        printf("\n");
        Algo_4_19(R,S,T,a);
        printf("R = ");
        StrPrint_Sq(R);
        printf("\n");
        printf("a = ");
        for(i=0;i<=a[0];i++)
            printf("%d ",a[i]);
        return 0;
    }

    Status Algo_4_19(SString R,SString S,SString T,int a[])
    {
        int i,j,k;
        int flag;
        a[0] = 0;
        R[0] = 0;
        for(i=1;i<=S[0];i++)
        {
            flag = 0;
            for(j=1;j<=T[0];j++)
            {
                if(S[i]==T[j])
                    {
                        flag = 1;
                        break;
                    }
            }

            if(!flag)
            {
                for(k=1;k<=R[0];k++)
                {
                    if(S[i]==R[k])
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if(!flag)
            {
                R[0]++;
                a[0]++;
                R[R[0]]=S[i];
                a[a[0]] = i;
            }
        }
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	4.20.c
    #include <stdio.h>
    #include "SequenceString.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    Status Algo_4_20(SString S,SString T);

    int main(void)
    {
        SString S,T;
        char *s = "I am Justin Yu.";
        char *t = " Justin Yu";
        StrAssign_Sq(S,s);
        StrAssign_Sq(T,t);
        printf("S = ");
        StrPrint_Sq(S);
        printf("\n");
        printf("T = ");
        StrPrint_Sq(T);
        printf("\n");
        Algo_4_20(S,T);
        printf("S = ");
        StrPrint_Sq(S);
        return 0;
    }

    Status Algo_4_20(SString S,SString T)
    {
        int i,j,k;
        i=1;
        j=1;
        while(i<=S[0] && j<=T[0])
        {
            if(S[i]==T[j])
            {
                i++;
                j++;
            }
            else
            {
                i = i - (j-1) + 1;
                j = 1;
            }
        }
        if(j>T[0] && T[0])
            i = i-T[0];
        else
            i = 0;
        while(i!=0)
        {
            for(k=i+T[0];k<=S[0];k++)
                S[k-T[0]] = S[k];
            S[0] = S[0] - T[0];
            j = 1;
            while(i<=S[0]&&j<=T[0])
            {
                if(S[i]==T[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    i = i- (j-1) + 1;
                    j = 1;
                }
            }
            if(j>T[0] && T[0]!=0)
                i = i - T[0];
            else
                i = 0;
        }
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	4.21.c
    #include <stdio.h>
    #include <string.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Chapter2\SingleLinkedList.c"

    typedef LElemType_L strElem;
    typedef LNode strNode;
    typedef LinkList String;

    Status StrAssign_4_21(String *S,char *chars);
    Status StrCopy_4_21(String *S,String T);
    int StrCompare_4_21(String S,String T);
    int StrLength_4_21(String S);
    Status Concat_4_21(String *R,String S,String T);
    Status SubString_4_21(String *Sub,String S,int pos,int len);
    void StrPrint_4_21(String S);

    int main(void)
    {
        return 0;
    }

    Status StrAssign_4_21(String *S,char *chars)
    {
        int i,len;
        String s,p;
        len = strlen(chars);
        InitList_L(S);
        for(i=1,p=*S;i<len;i++)
        {
            s = (String)malloc(sizeof(strNode));
            if(!s)
                exit(OVERFLOW);
            s->data = chars[i-1];
            s->next = p->next;
            p->next = s;
            p = p->next;
        }
        return OK;
    }
    Status StrCopy_4_21(String *S,String T)
    {
        String s,p,r;
        InitList_L(S);
        for(r=*S,p=T->next;p;p=p->next)
        {
            s = (String)malloc(sizeof(strNode));
            if(!s)
                exit(OVERFLOW);
            s->data = p->data;
            s->next = r->next;
            r->next = s;
            r = r->next;
        }
        return OK;
    }

    int StrCompare_4_21(String S,String T)
    {
        String p,q;
        if(S && T)
        {
            p = S->next;
            q = T->next;
            while(p&&q)
            {
                if(p->data != q->data)
                    return p->data - q->data;
                p = p->next;
                q = q->next;
            }
            return ListLength_L(S)-ListLength_L(T);
        }
    }

    int StrLength_4_21(String S)
    {
        return ListLength_L(S);
    }

    Status Concat_4_21(String *R,String S,String T)
    {
        String r,p,s;
        if(!S||!T)
            return ERROR;
        InitList_L(R);
        for(r=*R,p=S->next;p;p=p->next)
        {
            s = (String)malloc(sizeof(strNode));
            if(!s)
                exit(OVERFLOW);
            s->data = p->data;
            s->next = r->next;
            r->next = s;
            r = r->next;
        }
    }

    Status SubString_4_21(String*Sub,String S,int pos,int len)
    {
        int i,s1;
        String r,p,s;
        s1 = StrLength_4_21(S);
        if(!S||pos<1||pos>s1||len<0||pos+len-1>s1)
            return ERROR;
        InitList_L(Sub);
        for(i=1,p=S->next;i<pos;i++,p=p->next)
            ;
        for(i=1,r=*Sub;i<=len;i++,p=p->next)
        {
            s = (String)malloc(sizeof(strNode));
            if(!s)
                exit(OVERFLOW);
            s->data = p->data;
            s->next = r->next;
            r->next = s;
            r = r->next;
        }
        return OK;
    }
    void StrPrint_4_21(String S)
    {
        String p;
        for(p = S->next;p;p=p->next)
            printf("%c",p->data);
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	4.22.c
    #include <stdio.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Chapter4\BlockChainString.c"

    Status Algo_4_22(LString S,LString *T,char ch);

    int main(void)
    {
        char *t = "I am Justin";
        char *s = " Yu.";
        char ch = 'n';
        LString T,S;
        StrAssign_L(&T,t);
        StrAssign_L(&S,s);
        printf("T = ");
        StrPrint_L(T);
        printf("\n");
        printf("S = ");
        StrPrint_L(S);
        printf("\n");
        Algo_4_22(S,&T,ch);
        printf("T = ");
        StrPrint_L(T);
        return 0;
    }

    Status Algo_4_22(LString S,LString *T,char ch)
    {
        int i;
        char tmp[2];
        LString Tmp;
        tmp[0]=ch;
        tmp[1]='\0';
        StrAssign_L(&Tmp,tmp);
        i = Index_L((*T),Tmp,1);
        if(i)
            StrInsert_L(T,i+1,S);
        else
            StrInsert_L(T,(*T).curlen+1,S);
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	4.23.c
    #include <stdio.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Chapter3\SequenceStack.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Chapter4\BlockChainString.c"

    Status Algo_4_23(LString T);
    int main(void)
    {
        char *t = "asdfdsa";
        LString T;
        StrAssign_L(&T,t);
        printf("T = ");
        StrPrint_L(T);
        printf("\n");
        Algo_4_23(T)?printf("T is symmetrical"):printf("T is not symmetrical");
        return 0;
    }
    Status Algo_4_23(LString T)
    {
        int i,j,m;
        SqStack S;
        SElemType_Sq e;
        Chunk *p;
        if(!(T.curlen))
            return OK;
        InitStack_Sq(&S);
        m = T.curlen/2;
        for(i=1,p=T.head,j=0;i<=m;i++)
        {
            Push_Sq(&S,p->ch[j]);
            j = (j+1) % CHUNKSIZE;
            if(!j)
                p = p->next;
        }
        if(T.curlen%2)
        {
            i++;
            j = (j+1)%CHUNKSIZE;
            if(!j)
                p = p->next;
        }
        while(!StackEmpty_Sq(S)&&i<=T.curlen)
        {
            Pop_Sq(&S,&e);
            if(e!=p->ch[j])
                return ERROR;
            i++;
            j = (j+1) % CHUNKSIZE;
            if(!j)
                p = p->next;
        }
        if(StackEmpty_Sq(S)&&i>T.curlen)
            return OK;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	4.24.c
    #include <stdio.h>
    #include "HeapString.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    Status Concat_4_24(HString *T,HString S1,HString S2);
    int main(void)
    {
        return 0;
    }
    Status Concat_4_24(HString *T,HString S1,HString S2)
    {
        int i;
        InitString_H(T);
        (*T).length = S1.length + S2.length;
        (*T).ch = (char*)malloc((*T).length*sizeof(char));
        if(!(*T).ch)
            exit(OVERFLOW);
        for(i=0;i<S1.length;i++)
            (*T).ch[i] = S1.ch[i];
        for(i=0;i<S2.length;i++)
            (*T).ch[S1.length+i] = S2.ch[i];
        return OK;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	4.25.c
    #include <stdio.h>
    #include "HeapString.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    Status Replace_4_25(HString *S,HString T,HString V);
    int main(void)
    {
        return 0;
    }
    Status Replace_4_25(HString *S,HString T,HString V)
    {
        int i;
        if(StrEmpty_H(T))
            return ERROR;
        i = Index_H(*S,T,1);
        while(i!=0)
        {
            StrDelete_H(S,i,StrLength_H(T));
            StrInsert_H(S,i,V);
            i+= StrLength_H(V);
            i = Index_H(*S,T,i);
        }
        return OK;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	4.26.c
    #include <stdio.h>
    #include "HeapString.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    Status StrInsert_4_26(HString *S,int pos,HString T);
    int main(void)
    {
        return 0;
    }
    Status StrInsert_4_26(HString *S,int pos,HString T)
    {
        int i;
        if(pos<1||pos>(*S).length+1)
            return ERROR;
        if(StrEmpty_H(T))
            return ERROR;
        else
        {
            (*S).ch = (char*)realloc((*S).ch,((*S).length+T.length)*sizeof(char));
            if(!(*S).ch)
                exit(OVERFLOW);
            for(i = (*S).length-1;i>=pos-1;i--)
                (*S).ch[i+T.length] = (*S).ch[i];
            for(i=0;i<T.length;i++)
                (*S).ch[pos-1+i] = T.ch[i];
            (*S).length += T.length;
        }
        return OK;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	4.27.c
    #include <stdio.h>
    #include "SequenceString.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    int Algo_4_27(SString S,SString T,int pos);
    int main(void)
    {
        char *s = "aaaaaaaaaaaab";
        char *t = "aaaab";
        SString S,T;
        StrAssign_Sq(S,s);
        StrAssign_Sq(T,t);
        printf("S = ");
        StrPrint_Sq(S);
        printf("\n");
        printf("T = ");
        StrPrint_Sq(T);
        printf("\n");
        printf("The index of T in S is: ");
        printf("%d\n",Algo_4_27(S,T,1));
        return 0;
    }

    int Algo_4_27(SString S,SString T,int pos)
    {
        int i =pos;
        int j = 1;
        if(pos<1)
            return 0;
        while(i<=S[0] && j<= T[0])
        {
            if((j!=1&&S[i]==T[j])||(j==1&&S[i]==T[j]&&S[i+T[0]-1]==T[T[0]]))
            {
                i++;
                j++;
            }
            else
            {
                i = i-(j-1)+1;
                j = 1;
            }
        }
        if(j>T[0]&&T[0])
            return i-T[0];
        else
            return 0;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	4.28.c
    #include <stdio.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    typedef struct strLNode
    {
        char chdata;
        struct strLNode *succ;
        struct strLNode *next;
    }strLNode;
    typedef strLNode *LString;

    Status Algo_4_28(LString T);


    int main(void)
    {
        return 0;
    }

    Status Algo_4_28(LString T)
    {
        strLNode *i,*j;
        if(!T||!T->succ)
            return ERROR;
        i = T->succ;
        j = T;
        i->next = T;
        while(i->succ)
        {
            if(j==T||i->chdata==j->chdata)
            {
                i = i->succ;
                j = j->succ;
                i->next = j;
            }
            else
                j = j->next;
        }
        return OK;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	4.29.c
    #include <stdio.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    typedef struct strLNode
    {
        char chdata;
        struct strLNode *succ;
        struct strLNode *next;
    }strLNode;
    typedef strLNode *LString;

    int Algo_4_29(LString S,LString T,int pos);

    int main(void)
    {
        return 0;
    }

    int Algo_4_29(LString S,LString T,int pos)
    {
        int count,m;
        strLNode *i,*j;
        strLNode *p,*q;
        if(pos<!||!S||!S->succ||!T||!T->succ)
            return 0;
        for(count=1;i=S->succ;count<pos;count++,i=i->succ)
            ;
        j = T->succ;
        p = i;
        while(i && j)
        {
            if(j == T|| i->chdata==j->chdata)
            {
                i = i->succ;
                j = j->succ;
            }
            else
            {
                j = j->next;
                if(j==T->succ)
                    p = i;
            }
        }
        if(!j)
        {
            for(count=1,q=S->succ;q!=p;count++,q=q->succ)
                ;
            return count;
        }
        else
            return 0;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	4.30.c
    #include <stdio.h>
    #include "SequenceString.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    Status Algo_4_30(SString S,SString Sub,int *pos);
    int main(void)
    {
        char *s ="abcdeabcabcbcdefbcdefefghefgh";
        SString Sub,S;
        int pos;
        StrAssign_Sq(S,s);
        printf("S = ");
        StrPrint_Sq(S);
        printf("\n");
        printf("Sub = ");
        Algo_4_30(S,Sub,&pos);
        StrPrint_Sq(Sub);
        printf("\n");
        printf("The position is %d",pos);
        return 0;
    }

    Status Algo_4_30(SString S,SString Sub,int *pos)
    {
        int i,j,k,start,end,len;
        if(S[0]<2)
            return ERROR;
        Sub[0]=0;
        for(k=1;k<S[0];k++)
        {
            i=k;
            j=k+1;
            while(j<=S[0]&&S[i]!=S[j])
                j++;
            if(j<=S[0])
            {
                start = i;
                end = j;
                len=0;
                while(j<=S[0]&&S[i]==S[j])
                {
                    i++;
                    j++;
                    len++;
                }
                if(len>Sub[0]&&start+len-1>=end-1)
                {
                    *pos = start;
                    SubString_Sq(Sub,S,start,len);
                }
            }
        }
        if(Sub[0])
            return OK;
        else
            return ERROR;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	4.31.c
    #include <stdio.h>
    #include "SequenceString.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    Status Algo_4_31(SString S,SString T,SString V);

    int main(void)
    {
        SString S,T,V;
        char *s = "I am Justin Yu.";
        char *t = "I am not Justin Yu.";
        StrAssign_Sq(S,s);
        StrAssign_Sq(T,t);
        printf("S = ");
        StrPrint_Sq(S);
        printf("\n");
        printf("T = ");
        StrPrint_Sq(T);
        printf("\n");
        Algo_4_31(S,T,V);
        printf("V = ");
        StrPrint_Sq(V);
        printf("\n");
        return 0;
    }

    Status Algo_4_31(SString S,SString T,SString V)
    {
        int i,j,k,len,pos;
        len = 0;
        pos = -1;
        for(i=1;i<=S[0];i++)
        {
            for(j=1;j<=T[0];j++)
            {
                if(S[i]==T[j])
                {
                    for(k=0;S[i+k]==T[j+k]&&(i+k)<S[0];k++)
                        ;
                    if(len<k)
                    {
                        len = k;
                        pos = i;
                    }
                }
            }
        }
        if(len==-1)
            return ERROR;
        else
            SubString_Sq(V,S,pos,len);
        return OK;
    }
    {% endhighlight %}
    
---

If you find there are faults in the source codes, any method connecting with me is welcomed.
