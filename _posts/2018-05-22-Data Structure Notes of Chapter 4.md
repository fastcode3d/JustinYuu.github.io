---
layout: post
title: Data Structure Notes of Chapter 4
description: "my thoughts and notes when learning Data Structure"
categories: [Data-Structure]
tags: [C]
redirect_from:
  - /2018/05/22/
---
# Data Structure Notes of Chapter 4

This chapter introduces the ADT of string, which could make strings more functional and easier to operate. 

In this article, I will put the source codes of Blockchain String(often regarded as Chunk), Heap String and the most familiar Sequence String. These three strings are the most commonly used implementations of strings, and each of them has its pros and cons.

---

	{%highlight ruby%}
	SequenceString.h
    #ifndef SEQUENCESTRING_H
    #define SEQUENCESTRING_H

    #include <stdio.h>
    #include <string.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    #define MAXSTRLEN 255

    typedef unsigned char SString[MAXSTRLEN+1];

    Status StrAssign(SString T,const char *chars);

    void StrCopy(SString T, SString S);

    Status StrEmpty_Sq(SString S);

    int StrCompare_Sq(SString S,SString T);

    int StrLength_Sq(SString S);

    void ClearString_Sq(SString S);

    Status Concat_Sq(SString T,SString S1,SString S2);

    Status SubString_Sq(SString Sub,SString S,int pos,int len);

    int Index_Sq_1(SString S,SString T,int pos);

    int Index_Sq_2(SString S,SString T,int pos);

    Status Replace_Sq(SString S,SString T,SString V);

    Status StrInsert_Sq(SString S,int pos,SString T);

    Status StrDelete_Sq(SString S,int pos,int len);

    void DestroyString_Sq(SString S);

    void StrPrint_Sq(SString S);


    #endif // SEQUENCESTRING_H
	{%endhighlight%}

---

	{%highlight ruby%}
	SequenceString.c
    #ifndef SEQUENCESTRING_C
    #define SEQUENCESTRING_C

    #include "SequenceString.h"

    Status StrAssign_Sq(SString T,const char *chars)
    {
        int i,len;
        len = strlen(chars);

        if(len>MAXSTRLEN)
            return ERROR;
        else
        {
            T[0] = len;
            for(i=1;i<=len;i++)
                T[i] = chars[i-1];
            return OK;
        }
    }
    void StrCopy_Sq(SString T,SString S)
    {
        int i;
        for(i=0;i<S[0];i++)
            T[i]=S[i];
    }
    Status StrEmpty_Sq(SString S)
    {
        if(S[0]==0)
            return TRUE;
        else
            return FALSE;
    }

    int StrCompare_Sq(SString S,SString T)
    {
        int i = 1;
        while(i<=S[0] && i<=T[0])
        {
            if(S[i]==T[i])
                i++;
            else
                return S[i]-T[i];
        }
        return S[0] - T[0];
    }

    int StrLength_Sq(SString S)
    {
        return S[0];
    }

    void ClearString_Sq(SString S)
    {
        S[0] = 0;
    }

    void DestroyString_Sq(SString S)
    {

    }

    Status Concat_Sq(SString T,SString S1,SString S2)
    {
        int i;
        for(i=1;i<=S1[0];i++)
            T[i] = S1[i];

        if(S1[0]+S2[0]<=MAXSTRLEN)
        {
            for(i=1;i<=S2[0];i++)
                T[S1[0]+i] = S2[i];

            T[0] = S1[0] + S2[0];
            return OK;
        }
        else
        {
            for(i=1;S1[0]+i<=MAXSTRLEN;i++)
                T[S1[0]+i] =S2[i];
            T[0] = MAXSTRLEN;
            return ERROR;
        }
    }

    Status SubString_Sq(SString Sub,SString S,int pos,int len)
    {
        int i;
        if(pos<1 || pos>S[0] || len<0 || pos+len-1>S[0])
            return ERROR;
        for(i=1;i<=len;i++)
            Sub[i] = S[pos+i-1];
        Sub[0] = len;
        return OK;
    }

    int Index_Sq_1(SString S,SString T,int pos)
    {
        int s,t;
        SString Sub;

        if(pos>0)
        {
            s = StrLength_Sq(S);
            t = StrLength_Sq(T);
            if(s && t)
            {
                while(pos+t-1<=s)
                {
                    SubString_Sq(Sub,S,pos,t);
                    if(!StrCompare_Sq(Sub,T))
                        return pos;
                    pos++;
                }
            }
        }
        return 0;
    }

    int Index_Sq_2(SString S,SString T,int pos)
    {
        int i = pos;
        int j = 1;
        if(pos<1)
            return 0;
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
            return i-T[0];
        else
            return 0;
    }

    Status Replace_Sq(SString S,SString T,SString V)
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
        if(i==0)
            return OK;
        else
            return ERROR;
    }

    Status StrInsert_Sq(SString S,int pos,SString T)
    {
        int i;
        if(pos<1||pos>S[0]+1 || S[0]+T[0]>MAXSTRLEN)
            return ERROR;
        for(i=S[0];i>=pos;i--)
            S[i+T[0]] = S[i];
        for(i=pos;i<=pos+T[0]-1;i++)
            S[i] = T[i-pos+1];
        S[0] += T[0];
        return OK;
    }
    Status StrDelete_Sq(SString S,int pos,int len)
    {
        int i;
        if(pos<1 || pos+len-1>S[0] || len<0)
            return ERROR;
        for(i=pos+len;i<=S[0];i++)
            S[i-len] = S[i];
        S[0] -= len;
        return OK;
    }

    void StrPrint_Sq(SString S)
    {
        int i;
        for(i=1;i<=S[0];i++)
            printf("%c",S[i]);
    }

    #endif // SEQUENCESTRING_C
	{%endhighlight%}

---

	{%highlight ruby%}
	HeapString.h
    #ifndef HEAPSTRING_H
    #define HEAPSTRING_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    typedef struct
    {
        char *ch;
        int length;
    }HString;

    void InitString_H(HString *S);

    Status StrAssign_H(HString *T,char *chars);

    Status StrCopy_H(HString *T,HString S);

    Status StrEmpty_H(HString S);

    Status StrCompare_H(HString S,HString T);

    int StrLength_H(HString S);

    Status ClearString_H(HString *S);

    Status Concat_H(HString *T,HString S1,HString S2);

    Status SubString_H(HString *Sub,HString S,int pos,int len);

    int Index_H(HString S,HString T,int pos);

    Status Replace_H(HString *S,HString T,HString V);

    Status StrInsert_H(HString *S,int pos,HString T);

    Status StrDelete_H(HString *S,int pos,int len);

    void DestroyString_H(HString *S);

    void StrPrint_H(HString S);

    #endif // HEAPSTRING_H
	{%endhighlight%}

---

	{%highlight ruby%}
	HeapString.c
    #ifndef HEAPSTRING_C
    #define HEAPSTRING_C

    #include "HeapString.h"

    void InitString_H(HString *S)
    {
        (*S).ch = NULL;
        (*S).length = 0;
    }

    Status StrAssign_H(HString *T,char *chars)
    {
        int i,j;
        InitString_H(T);
        i = strlen(chars);
        if(!i)
            return ERROR;
        else
        {
            (*T).ch = (char*)malloc(i*sizeof(char));
            if(!((*T).ch))
                exit(OVERFLOW);
            for(j=0;j<i;j++)
                (*T).ch[j]=chars[j];
            (*T).length = i;
        }
        return OK;
    }

    Status StrCopy_H(HString *T,HString S)
    {
        int i;
        InitString_H(T);
        if(StrEmpty_H(S))
            return ERROR;
        (*T).ch = (char*)malloc(S.length*sizeof(char));
        if(!(*T).ch)
            exit(OVERFLOW);
        for(i=0;i<S.length;i++)
            (*T).ch[i] = S.ch[i];
        (*T).length = S.length;
        return OK;
    }

    Status StrEmpty_H(HString S)
    {
        if(S.length==0 && S.ch == NULL)
            return TRUE;
        else
            return FALSE;
    }

    Status StrCompare_H(HString S,HString T)
    {
        int i;
        for(i=0;i<S.length&&i<T.length;i++)
        {
            if(S.ch[i]!= T.ch[i])
                return S.ch[i]-T.ch[i];
        }
        return S.length - T.length;
    }

    int StrLength_H(HString S)
    {
        if(StrEmpty_H(S))
            return 0;
        else
            return S.length;
    }

    Status ClearString_H(HString *S)
    {
        if((*S).ch)
        {
            free((*S).ch);
            (*S).ch = NULL;
        }
        (*S).length = 0;
        return OK;
    }

    Status Concat_H(HString *T,HString S1,HString S2)
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

    Status SubString_H(HString *Sub,HString S,int pos,int len)
    {
        int i;
        InitString_H(Sub);
        if(StrEmpty_H(S))
            return ERROR;
        if(pos<1||pos>S.length||len<0||pos+len-1>S.length)
            return ERROR;
        if(len)
        {
            (*Sub).ch = (char*)malloc(len*sizeof(char));
            if(!(*Sub).ch)
                exit(OVERFLOW);
            for(i=0;i<len;i++)
                (*Sub).ch[i]=S.ch[i+pos-1];
            (*Sub).length = len;
        }
        return OK;
    }

    int Index_H(HString S,HString T,int pos)
    {
        int s,t,i;
        HString Sub;
        InitString_H(&Sub);
        if(pos>0)
        {
            s = S.length;
            t = T.length;
            i = pos;
            while(i+t-1<=s)
            {
                SubString_H(&Sub,S,i,t);
                if(StrCompare_H(Sub,T))
                    i++;
                else
                    return i;
            }
        }
        return 0;
    }

    Status Replace_H(HString *S,HString T,HString V)
    {
        int i;
        if(StrEmpty_H(T))
            return ERROR;
        i = Index_H(*S,T,1);
        while(i!=0)
        {
            StrDelete_H(S,i,StrLength_H(T));
            StrInsert_H(S,i,V);
            i+=StrLength_H(V);
            i = Index_H(*S,T,i);
        }
        return OK;
    }

    Status StrInsert_H(HString *S,int pos,HString T)
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
            for(i=(*S).length-1;i>=pos-1;i--)
                (*S).ch[i+T.length]=(*S).ch[i];
            for(i=0;i<T.length;i++)
                (*S).ch[pos-1+i] = T.ch[i];
            (*S).length += T.length;
        }
        return OK;
    }

    Status StrDelete_H(HString *S,int pos,int len)
    {
        int i;
        if(StrEmpty_H(*S))
            return ERROR;
        if(pos<1||pos+len-1>(*S).length||len<0)
            return ERROR;
        for(i=pos-1;i+len<=(*S).length;i++)
            (*S).ch[i]=(*S).ch[i+len];
        (*S).length -=len;
        (*S).ch = (char*)realloc((*S).ch,(*S).length*sizeof(char));
        return OK;
    }

    void DestroyString_H(HString *S)
    {

    }

    void StrPrint_H(HString S)
    {
        int i;
        if(StrEmpty_H(S))
            printf("S is empty!");
        for(i=0;i<S.length;i++)
            printf("%c",S.ch[i]);
    }

    #endif // HEAPSTRING_C
	{%endhighlight%}

---

	{%highlight ruby%}
	BlockChainString.h
    #ifndef BLOCKCHAINSTRING_H
    #define BLOCKCHAINSTRING_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    #define CHUNKSIZE 3

    typedef struct Chunk
    {
        char ch[CHUNKSIZE];
        struct Chunk *next;
    }Chunk;
    typedef struct{
        Chunk *head,*tail;
        int curlen;
    }LString;

    void InitString_L(LString *T);

    Status StrAssign_L(LString *T,char *chars);

    Status StrCopy_L(LString *T,LString S);

    Status StrEmpty_L(LString S);

    int StrCompare_L(LString S,LString T);

    int StrLength_L(LString S);

    void ClearString_L(LString *S);

    void Concat_L(LString *T,LString S1,LString S2);

    Status SubString_L(LString *Sub,LString S,int pos,int len);

    int Index_L(LString S,LString T,int pos);

    Status Replace_L(LString *S,LString T,LString V);

    Status StrInsert_L(LString *S,int pos,LString T);

    Status StrDelete_L(LString *S,int pos, int len);

    void DestroyString_L(LString *S);

    void StrPrint_L(LString S);

    Status GetChar_L(LString S,char *c,int i);


    #endif // BLOCKCHAINSTRING_H
	{%endhighlight%}

---

	{%highlight ruby%}
	BlockChainString.c
    #ifndef BLOCKCHAINSTRING_C
    #define BLOCKCHAINSTRING_C

    #include "BlockChainString.h"

    void InitString_L(LString *T)
    {
        (*T).head = NULL;
        (*T).tail = NULL;
        (*T).curlen = 0;
    }

    Status StrAssign_L(LString *T,char* chars)
    {
        int len,i,j,k,count;
        Chunk *r;
        InitString_L(T);
        len = strlen(chars);
        if(!len)
            return ERROR;
        i = len / CHUNKSIZE;
        j = len % CHUNKSIZE;
        if(j)
            i++;
        for(k=1;k<=i;k++)
        {
            r = (Chunk*)malloc(sizeof(Chunk));
            if(!r)
                exit(OVERFLOW);
            r->next = NULL;
            if(k==1)
                (*T).head = (*T).tail = r;
            else
            {
                (*T).tail->next = r;
                (*T).tail = r;
            }
            for(count = 0;count<CHUNKSIZE && count+(k-1)*CHUNKSIZE<len;count++)
                (*T).tail->ch[count] = chars[count + (k-1)*CHUNKSIZE];
        }
        while(count<CHUNKSIZE)
        {
            (*T).tail->ch[count] = '\0';
            count++;
        }
        (*T).curlen = len;
        return OK;
    }

    Status StrCopy_L(LString *T,LString S)
    {
        int i;
        Chunk *r,*p;
        InitString_L(T);
        for(p=S.head;p;p=p->next)
        {
            r = (Chunk*)malloc(sizeof(Chunk));
            if(!r)
                exit(OVERFLOW);
            r->next = NULL;
            if(p==S.head)
                (*T).head = (*T).tail = r;
            else
            {
                (*T).tail->next = r;
                (*T).tail = r;
            }
            for(i=0;i<CHUNKSIZE;i++)
            {
                (*r).ch[i] = (*p).ch[i];
            }
        }
        (*T).curlen = S.curlen;
        return OK;
    }

    Status StrEmpty_L(LString S)
    {
        if(S.head ==NULL && S.tail == NULL && S.curlen == 0)
            return OK;
        else
            return ERROR;
    }

    int StrCompare_L(LString S,LString T)
    {
        int i;
        int s = S.curlen;
        int t = T.curlen;
        Chunk *p = S.head;
        Chunk *q = T.head;
        while(p&&q)
        {
            for(i=0;i<CHUNKSIZE;i++)
            {
                if((*p).ch[i]!=(*q).ch[i])
                    return (*p).ch[i]-(*q).ch[i];
            }
            p = p->next;
            q = q->next;
        }
        return s-t;
    }

    int StrLength_L(LString S)
    {
        return S.curlen;
    }

    void ClearString_L(LString *S)
    {
        Chunk *p,*q;
        p = (*S).head;
        while(p)
        {
            q = p->next;
            free(p);
            p = q;
        }
        (*S).head = NULL;
        (*S).tail = NULL;
        (*S).curlen = 0;
    }

    void Concat_L(LString* T,LString S1,LString S2)
    {
        int i,j,k,count;
        Chunk *r,*p,*q;
        InitString_L(T);
        r = (*T).head;
        p = S1.head;
        q = S2.head;
        i = j = k = 0;
        while(p||q)
        {
            if(!r)
            {
                r = (Chunk*)malloc(sizeof(Chunk));
                if(!r)
                    exit(OVERFLOW);
                r->next = NULL;
                if(!(*T).head)
                    (*T).head = (*T).tail = r;
                else
                {
                    (*T).tail->next = r;
                    (*T).tail = r;
                }
            }
            if(p)
            {
                while(p && p->ch[j])
                {
                    r->ch[i] = p->ch[j];
                    i = (i+1) % CHUNKSIZE;
                    j = (j+1) % CHUNKSIZE;
                    if(!j||!(p->ch[j]))
                        p = p->next;
                    if(!i)
                    {
                        r = r->next;
                        break;
                    }
                }
            }
            else
            {
                while(q && q->ch[k])
                {
                    r->ch[i]=q->ch[k];
                    i = (i+1) %CHUNKSIZE;
                    k = (k+1) %CHUNKSIZE;
                    if(!k || !(q->ch[k]))
                        q = q->next;
                    if(!i)
                    {
                        r = r->next;
                        break;
                    }
                }
            }
        }
        (*T).curlen = S1.curlen+S2.curlen;
        count = ((*T).curlen-1)%CHUNKSIZE +1;
        while(count<CHUNKSIZE)
        {
            (*T).tail->ch[count]='\0';
            count++;
        }
    }
    Status SubString_L(LString* Sub,LString S,int pos,int len)
    {
        int i,j,k,count;
        Chunk *r,*p;
        InitString_L(Sub);
        if(StrEmpty_L(S))
            return ERROR;
        if(pos<1 || pos>S.curlen||len<0||pos+len-1>S.curlen)
            return ERROR;
        for(count=1,p=S.head;pos>count*CHUNKSIZE;count++,p=p->next)
            ;
        r = (*Sub).head;
        i = 0;
        j = 0;
        k = (pos % CHUNKSIZE)-1;
        while(i<len)
        {
            if(!r)
            {
                r = (Chunk*)malloc(sizeof(Chunk));
                if(!r)
                {
                    exit(OVERFLOW);
                }
                r->next = NULL;
                if(!(*Sub).head)
                    (*Sub).head = (*Sub).tail = r;
                else
                {
                    (*Sub).tail->next = r;
                    (*Sub).tail = r;
                }
            }
            while(i<len)
            {
                (*r).ch[j] = (*p).ch[k];
                j = (j+1)%CHUNKSIZE;
                k = (k+1)%CHUNKSIZE;
                i++;
                if(!k)
                    p = p->next;
                if(!j)
                {
                    r = r->next;
                    break;
                }
            }
        }
        (*Sub).curlen = len;
        count = ((*Sub).curlen-1) % CHUNKSIZE + 1;
        while(count<CHUNKSIZE)
        {
            (*Sub).tail->ch[count]='\0';
            count++;
        }
        return OK;
    }

    int Index_L(LString S,LString T,int pos)
    {
        int i,s,t;
        LString sub;
        if(pos>0 && pos<=S.curlen)
        {
            s = S.curlen;
            t = T.curlen;
            i = pos;
            while(i+t-1<=s)
            {
                SubString_L(&sub,S,i,t);
                if(StrCompare_L(sub,T)!=0)
                    i++;
                else
                    return i;
            }
        }
        return 0;
    }

    Status Replace_L(LString *S,LString T, LString V)
    {
        int i;
        if(StrEmpty_L(T))
            return ERROR;
        i = Index_L(*S,T,1);
        while(i)
        {
            StrDelete_L(S,i,StrLength_L(T));
            StrInsert_L(S,i,V);
            i += StrLength_L(V);
            i = Index_L(*S,T,i);
        }
        return OK;
    }

    Status StrInsert_L(LString *S,int pos,LString T)
    {
        Chunk *r,*p1,*p2,*q;
        int i,j,k,count;
        LString Tmp;
        if(pos<1||pos>(*S).curlen+1)
            return ERROR;
        InitString_L(&Tmp);
        r = Tmp.head;
        p1 = (*S).head;
        p2 = NULL;
        q = T.head;
        i = j = k = 0;
        count = 1;
        while(p1||p1||q)
        {
            if(!r)
            {
                r = (Chunk*)malloc(sizeof(Chunk));
                if(!r)
                    exit(OVERFLOW);
                r->next = NULL;
                if(!Tmp.head)
                    Tmp.head = Tmp.tail = r;
                else
                {
                    Tmp.tail->next = r;
                    Tmp.tail = r;
                }
            }
            if(p1)
            {
                while(p1 && count<pos)
                {
                    r->ch[i] = p1->ch[j];
                    i = (i+1) % CHUNKSIZE;
                    j = (j+1) % CHUNKSIZE;
                    count++;
                    if(!j||!(p1->ch[j]))
                        p1 = p1->next;
                    if(!i)
                    {
                        r = r->next;
                        break;
                    }
                }
                if(count == pos)
                {
                    p2 = p1;
                    p1 = NULL;
                }
            }
            else if(q)
            {
                while(q && q->ch[k])
                {
                    r->ch[i] = q->ch[k];
                    i = (i+1) % CHUNKSIZE;
                    k = (k+1) % CHUNKSIZE;
                    if(!k||!(q->ch[k]))
                        q = q->next;
                    if(!i)
                    {
                        r = r->next;
                        break;
                    }
                }
            }
            else
            {
                while(p2 && p2->ch[j])
                {
                    r->ch[i]=p2->ch[j];
                    i = (i+1)%CHUNKSIZE;
                    j = (j+1)%CHUNKSIZE;
                    if(!j||!(p2->ch[j]))
                        p2 = p2->next;
                    if(!i)
                    {
                        r = r->next;
                        break;
                    }
                }
            }
        }
        Tmp.curlen = (*S).curlen + T.curlen;
        count = (Tmp.curlen-1)%CHUNKSIZE+1;
        while(count<CHUNKSIZE)
        {
            Tmp.tail->ch[count] = '\0';
            count++;
        }
        ClearString_L(S);
        (*S).curlen = Tmp.curlen;
        (*S).head = Tmp.head;
        (*S).tail = Tmp.tail;
        return OK;
    }
    Status StrDelete_L(LString *S,int pos,int len)
    {
        Chunk *p,*q,*r;
        int count,first,last,m,n;
        if(pos<1||pos>(*S).curlen||len<0||pos+len-1>(*S).curlen)
            return ERROR;
        if(pos==1&&len==(*S).curlen)
            ClearString_L(S);
        first = pos;
        last = pos+len-1;
        for(count = 1,p=(*S).head;first>count*CHUNKSIZE;count++,p=p->next)
            ;
        for(q=p;last>count*CHUNKSIZE;count++,q=q->next)
            ;
        m = (first-1)%CHUNKSIZE;
        n = (last-1)%CHUNKSIZE;
        n = (n+1)%CHUNKSIZE;
        if(!n)
            q = q->next;
        while(q && q->ch[n])
        {
            p->ch[m]=q->ch[n];
            m = (m+1)%CHUNKSIZE;
            n = (n+1)%CHUNKSIZE;
            if(!m)
                p = p->next;
            if(!n)
                q = q->next;
        }
        (*S).curlen -=len;
        for(count=1,(*S).tail=(*S).head;(*S).curlen>count*CHUNKSIZE;count++,(*S).tail=(*S).tail->next)
            ;
        count = ((*S).curlen-1) % CHUNKSIZE +1;
        while(count<CHUNKSIZE)
        {
            (*S).tail->ch[count]='\0';
            count++;
        }
        r = (*S).tail->next;
        while(r)
        {
                (*S).tail->next = r->next;
                free(r);
                r=(*S).tail->next;
        }
        return OK;
    }
    void DestroyString_L(LString *S)
    {

    }

    void StrPrint_L(LString S)
    {
        int i = 0;
        Chunk *p = S.head;
        if(S.head == NULL && S.tail==NULL &&S.curlen == 0)
            printf("S is empty!");
        while(p)
        {
            if((*p).ch[i])
                printf("%c",(*p).ch[i]);
            i = (i+1)%CHUNKSIZE;
            if(!i)
                p = p->next;
        }
    }
    Status GetChar_L(LString S,char *c,int i)
    {
        int m,n,count;
        Chunk *p;
        if(StrEmpty_L(S))
            return ERROR;
        if(i<1||i>S.curlen)
            return ERROR;
        m = i/CHUNKSIZE;
        m = i%CHUNKSIZE;
        if(n)
            m++;
        for(count=1,p=S.head;count<m;count++)
            p=p->next;
        if(n)
            *c = (*p).ch[n-1];
        else
            *c = (*p).ch[CHUNKSIZE-1];
        return OK;
    }

    #endif // BLOCKCHAINSTRING_C
	{%endhighlight%}

---

  If you find there are faults in the source codes, any method connecting with me is welcomed.
