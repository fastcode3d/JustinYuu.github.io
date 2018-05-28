---
layout: post
title: Data Structure Notes of Chapter 5
description: "my thoughts and notes when learning Data Structure"
categories: [Data-Structure]
tags: [C]
redirect_from:
  - /2018/05/28/
---
# Data Structure Notes of Chapter 4

This chapter introduces the ADT of Triple Sparce Matrix, Orthogonal List and Generialized List. Here I put source codes and header files of Triple Sparce Matrix and Generialized List.

Triple Sparce Matrix and Orthogonal List can make sparce matrix easier to storge. And Generialized List can reserve data(in any type) more flexible.

The implenment and relative exercises of generialized list mostly apply the thoughts of recursion, which takes large amounts of time to study and understand. 

---

	{%highlight ruby%}
	TripleSparceMatrix.h
    #ifndef TRIPLESPARSEMATRIX_H
    #define TRIPLESPARSEMATRIX_H

    #include <stdio.h>
    #include <stdarg.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Scanf.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    #define MAXSIZE 400

    typedef int MElemType_Tsq;
    typedef struct
    {
        int i,j;
        MElemType_Tsq e;
    }Triple;
    typedef struct
    {
        Triple data[MAXSIZE+1];
        int mu,nu,tu;
    }TSMatrix;

    Status CreateSMatrix_T(FILE *fp,int n,...);

    void DestroySMatrix_T(TSMatrix *M);

    void PrintSMatrix_T(TSMatrix M);

    void CopySMatrix_T(TSMatrix M,TSMatrix *T);

    Status AddSMatrix_T(TSMatrix M,TSMatrix N,TSMatrix *Q);

    Status SubSMatrix_T(TSMatrix M,TSMatrix N,TSMatrix *Q);

    Status MultSMatrix_T(TSMatrix M,TSMatrix N,TSMatrix *Q);

    void TransposeSMatrix_T(TSMatrix M,TSMatrix *T);

    void FastTransposeSMatrix_T(TSMatrix M,TSMatrix *T);

    #endif // TRIPLESPARSEMATRIX_H

	{%endhighlight%}

---

	{%highlight ruby%}
	TripleSparceMatrix.c
    #ifndef TRIPLESPARSEMATRIX_C
    #define TRIPLESPARSEMATRIX_C

    #include "TripleSparseMatrix.h"

    Status CreateSMatrix_T(FILE *fp,int n,...)
    {
        int count,k;
        TSMatrix *M;
        if(n<1)
            return ERROR;
        va_list ap;
        va_start(ap,n);
        for(count = 1;count<=n;count++)
        {
            M = va_arg(ap,TSMatrix*);
            Scanf(fp,"%d%d%d",&((*M).mu),&((*M).nu),&((*M).tu));
            for(k=1;k<=(*M).tu;k++)
                Scanf(fp,"%d%d%d",&((*M).data[k].i),&((*M).data[k].j),&((*M).data[k].e));
        }
        va_end(ap);
        return OK;
    }

    void DestroySMatrix_T(TSMatrix *M)
    {
        (*M).mu = 0;
        (*M).nu = 0;
        (*M).tu = 0;
    }

    void PrintSMatrix_T(TSMatrix M)
    {
        int r,c;
        int k=1;
        for(r=1;r<=M.mu;r++)
        {
            for(c=1;c<=M.nu;c++)
            {
                if(r==M.data[k].i && c==M.data[k].j)
                {
                    printf("%3d ",M.data[k].e);
                    k++;
                }
                else
                    printf("  0 ");
            }
            printf("\n");
        }
    }

    void CopySMatrix_T(TSMatrix M,TSMatrix *T)
    {
        (*T) = M;
    }

    Status AddSMatrix_T(TSMatrix M,TSMatrix N,TSMatrix *Q)
    {
        int m,n,k;
        if(M.mu!=N.mu||M.nu!=N.nu)
        {
            printf("ERROR!\n");
            return ERROR;
        }
        Q->mu = M.mu;
        Q->nu = M.nu;
        Q->tu = 0;
        m = n = k = 1;
        while(m<=M.tu && n<=N.tu)
        {
            if(M.data[m].i<N.data[n].i)
            {
                Q->data[k]=M.data[m];
                m++;
            }
            else if(M.data[m].i > N.data[n].i)
            {
                Q->data[k]=N.data[n];
                n++;
            }
            else
            {
                if(M.data[m].j<N.data[n].j)
                {
                    Q->data[k]=M.data[m];
                    m++;
                }
                else if(M.data[m].j>N.data[n].j)
                {
                    Q->data[k]=N.data[n];
                    n++;
                }
                else
                {
                    if(M.data[m].e+N.data[n].e)
                    {
                        Q->data[k].i = M.data[m].i;
                        Q->data[k].j = M.data[m].j;
                        Q->data[k].e = M.data[m].e+N.data[n].e;
                        m++;
                        n++;
                    }
                    else
                    {
                        m++;
                        n++;
                        continue;
                    }
                }
            }
            k++;
            Q->tu++;
        }
        while(m<=M.tu)
        {
            Q->data[k]=M.data[m];
            m++;
            k++;
            Q->tu++;
        }
        while(n<=N.tu)
        {
            Q->data[k]=N.data[n];
            n++;
            k++;
            Q->tu++;
        }
        return OK;
    }

    Status SubSMatrix_T(TSMatrix M,TSMatrix N,TSMatrix *Q)
    {
        int m,n,k;
        if(M.mu!=N.mu||M.nu!=N.nu)
        {
            printf("ERROR!\n");
            return ERROR;
        }
        Q->mu = M.mu;
        Q->nu = M.nu;
        Q->tu = 0;
        m = n = k = 1;
        while(m<=M.tu && n<=N.tu)
        {
            if(M.data[m].i<N.data[n].i)
            {
                Q->data[k]=M.data[m];
                m++;
            }
            else if(M.data[m].i > N.data[n].i)
            {
                Q->data[k].i = N.data[n].i;
                Q->data[k].j = N.data[n].j;
                Q->data[k].e = -N.data[n].e;
                n++;
            }
            else
            {
                if(M.data[m].j<N.data[n].j)
                {
                    Q->data[k]=M.data[m];
                    m++;
                }
                else if(M.data[m].j>N.data[n].j)
                {
                    Q->data[k].i = N.data[n].i;
                    Q->data[k].j = N.data[n].j;
                    Q->data[k].e = -N.data[n].e;
                    n++;
                }
                else
                {
                    if(M.data[m].e-N.data[n].e)
                    {
                        Q->data[k].i = M.data[m].i;
                        Q->data[k].j = M.data[m].j;
                        Q->data[k].e = M.data[m].e-N.data[m].e;
                        m++;
                        n++;
                    }
                    else
                    {
                        m++;
                        n++;
                        continue;
                    }
                }
            }
            k++;
            Q->tu++;
        }
        while(m<=M.tu)
        {
            Q->data[k]=M.data[m];
            m++;
            k++;
            Q->tu++;
        }
        while(n<=N.tu)
        {
            Q->data[k].i = N.data[n].i;
            Q->data[k].j = N.data[n].j;
            Q->data[k].e = -N.data[n].e;
            n++;
            k++;
            Q->tu++;
        }
        return OK;
    }

    Status MultSMatrix_T(TSMatrix M,TSMatrix N,TSMatrix *Q)
    {
        int m,n,i,j,k;
        MElemType_Tsq c,c1,c2;
        if(M.nu!=N.mu)
        {
            printf("ERROR!");
            return ERROR;
        }
        Q->mu = M.mu;
        Q->nu = N.nu;
        Q->tu = 0;
        if(M.tu*N.tu)
        {
            for(i=1;i<=M.mu;i++)
            {
                for(j=1;j<=N.nu;j++)
                {
                    c=0;
                    for(k=1;k<=M.tu;k++)
                    {
                        c1 = 0;
                        for(m=1;m<=M.tu;m++)
                        {
                            if(M.data[m].i==i && M.data[m].j==k)
                            {
                                c1 = M.data[m].e;
                                break;
                            }
                        }
                        c2 = 0;
                        for(n=1;n<=N.tu;n++)
                        {
                            if(N.data[n].i==k && N.data[n].j==j)
                            {
                                c2 = N.data[n].e;
                                break;
                            }
                        }
                        if(c1 && c2)
                            c += c1*c2;
                    }
                    if(c)
                    {
                        Q->tu++;
                        Q->data[Q->tu].i=i;
                        Q->data[Q->tu].j=j;
                        Q->data[Q->tu].e=c;
                    }
                }
            }
        }
        return OK;
    }

    void TransposeSMatrix_T(TSMatrix M,TSMatrix *T)
    {
        int p,q,col;
        T->mu = M.nu;
        T->nu = M.mu;
        T->tu = M.tu;
        if(T->tu)
        {
            q = 1;
            for(col=1;col<=M.nu;++col)
            {
                for(p=1;p<=M.tu;++p)
                {
                    if(M.data[p].j==col)
                    {
                        T->data[q].i = M.data[p].j;
                        T->data[q].j = M.data[p].i;
                        T->data[q].e = M.data[p].e;
                        ++q;
                    }
                }
            }
        }
    }

    void FastTransposeSMatrix_T(TSMatrix M,TSMatrix *T)
    {
        int col,t,p,q;
        int num[M.nu];
        int copt[M.nu];
        T->mu = M.nu;
        T->nu = M.mu;
        T->tu = M.tu;
        if(T->tu)
        {
            for(col=1;col<=M.nu;++col)
                num[col]=0;
            for(t=1;t<=M.tu;++t)
                num[M.data[t].j]++;
            copt[1]=1;
            for(col=2;col<=M.nu;++col)
                copt[col]=copt[col-1]+num[col-1];
            for(p=1;p<=M.tu;++p)
            {
                col = M.data[p].j;
                q = copt[col];
                T->data[q].i = M.data[p].j;
                T->data[q].j = M.data[p].i;
                T->data[q].e = M.data[p].e;
                ++copt[col];
            }
        }
    }

    #endif // TRIPLESPARSEMATRIX_C
	{%endhighlight%}

---

	{%highlight ruby%}
	GenerializedList-H-T.h
    #ifndef GENERALIZEDLIST_H_T_H
    #define GENERALIZEDLIST_H_T_H

    #include <stdio.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Chapter4\SequenceString.c"

    typedef enum{Head,Tail}Mark;
    typedef enum{Atom,List}ElemTag;
    typedef char AtomType;
    typedef struct GLNode
    {
        union{int mark;};
        ElemTag tag;
        union
        {
            AtomType atom;
            struct
            {
                struct GLNode *hp;
                struct GLNode *tp;
            }ptr;
        }Union;
    }GLNode;
    typedef GLNode* GList;

    void InitGList_GL_H_T(GList *L);

    void sever_GL_H_T_1(SString hstr,SString str);

    void CreateGList_GL_H_T_1(GList *L,SString S);

    void sever_GL_H_T_2(SString hstr,SString str);

    void CreateGList_GL_H_T_2(GList *L,SString S);

    void ClearGList_GL_H_T(GList *L);

    void CopyGList_GL_H_T(GList *T,GList L);

    int GListLength_GL_H_T(GList L);

    int GListDepth_GL_H_T(GList L);

    Status GListEmpty_GL_H_T(GList L);

    GList GetHead_GL_H_T(GList L);

    GList GetTail_GL_H_T(GList L);

    void InsertFirst_GL_H_T(GList *L,GList e);

    void DeleteFirst_GL_H_T(GList *L,GList *e);

    void Traverse_GL_H_T(GList L,void(Visit)(AtomType));

    void Output_GL_H_T(GList L,Mark mark);

    #endif // GENERALIZEDLIST_H_T_H
	{%endhighlight%}

---

	{%highlight ruby%}
	GenerializedList-H-T.c
    #ifndef GENERALIZEDLIST_H_T_C
    #define GENERALIZEDLIST_H_T_C

    #include "GeneralizedList-H-T.h"

    void InitGList_GL_H_T(GList *L)
    {
        *L = NULL;
    }

    void sever_GL_H_T_1(SString hstr,SString str)
    {
        int i,k,n;
        SString ch;

        n = StrLength_Sq(str);
        i = k = 0;
        do
        {
            ++i;
            SubString_Sq(ch,str,i,1);
            if(ch[1]=='(')
                ++k;
            if(ch[1]==')')
                --k;
        }while(i<n && (ch[1]!=','||k!=0));
        if(i<n)
        {
            SubString_Sq(hstr,str,1,i-1);
            SubString_Sq(str,str,i+1,n-i);
        }
        else
        {
            StrCopy_Sq(hstr,str);
            ClearString_Sq(str);
        }
    }

    void CreateGList_GL_H_T_1(GList *L,SString S)
    {
        SString emp,hsub,sub;
        GList p,q;
        StrAssign_Sq(emp,"()");
        if(!StrCompare_Sq(S,emp))
            *L = NULL;
        else
        {
            *L = (GList)malloc(sizeof(GLNode));
            if(!(*L))
                exit(OVERFLOW);
            if(StrLength_Sq(S)==1)
            {
                (*L)->tag = Atom;
                (*L)->Union.atom = S[1];
                (*L)->mark = 0;
            }
            else
            {
                (*L)->tag = List;
                (*L)->mark = 0;
                p = *L;
                SubString_Sq(sub,S,2,StrLength_Sq(S)-2);
                do
                {
                    sever_GL_H_T_1(hsub,sub);
                    CreateGList_GL_H_T_1(&(p->Union.ptr.hp),hsub);
                    q = p;
                    if(!StrEmpty_Sq(sub))
                    {
                        p = (GList)malloc(sizeof(GLNode));
                        if(!p)
                            exit(OVERFLOW);
                        p->tag = List;
                        p->mark = 0;
                        q->Union.ptr.tp = p;
                    }
                }while(!StrEmpty_Sq(sub));
                q->Union.ptr.tp = NULL;
            }
        }
    }

    void sever_GL_H_T_2(SString hstr,SString str)
    {
        int i=1;
        int k=0;
        int n;
        SString tmp;
        SubString_Sq(tmp,str,2,StrLength_Sq(str)-2);
        n = StrLength_Sq(tmp);
        while(i<n && (tmp[i]!=','||k!=0))
        {
            if(tmp[i]=='(')
                k++;
            if(tmp[i]==')')
                k--;
            i++;
        }
        if(i<n)
            SubString_Sq(hstr,tmp,1,i-1);
        else
            StrCopy_Sq(hstr,tmp);
        StrDelete_Sq(str,2,i);
    }

    void CreateGList_GL_H_T_2(GList *L,SString S)
    {
        SString hsub,sub,emp;
        GList p,q;
        StrAssign_Sq(emp,"()");
        if(!StrCompare_Sq(S,emp))
            *L = NULL;
        else
        {
            *L = (GList)malloc(sizeof(GLNode));
            if(StrLength_Sq(S)==1)
            {
                (*L)->tag = Atom;
                (*L)->Union.atom = S[1];
            }
            else
            {
                (*L)->tag = List;
                p = *L;
                StrCopy_Sq(sub,S);
                do
                {
                    sever_GL_H_T_2(hsub,sub);
                    CreateGList_GL_H_T_2(&(p->Union.ptr.hp),hsub);
                    if(StrCompare_Sq(sub,emp))
                    {
                        q = p;
                        p = (GList)malloc(sizeof(GLNode));
                        p->tag = List;
                        q->Union.ptr.tp = p;
                    }
                }while(StrCompare_Sq(sub,emp));
                p->Union.ptr.tp = NULL;
            }
        }
    }

    void ClearGList_GL_H_T(GList *L)
    {
        GList p,q;
        if(*L)
        {
            if((*L)->tag == Atom)
            {
                free(*L);
                *L = NULL;
            }
            else
            {
                p = (*L)->Union.ptr.hp;
                q = (*L)->Union.ptr.tp;
                free(*L);
                *L =NULL;
                ClearGList_GL_H_T(&p);
                ClearGList_GL_H_T(&q);
            }
        }
    }

    void CopyGList_GL_H_T(GList *T,GList L)
    {
        if(!L)
            *T = NULL;
        else
        {
            *T =(GList)malloc(sizeof(GLNode));
            if(!*T)
                exit(OVERFLOW);
            (*T)->tag = L->tag;
            if(L->tag == Atom)
                (*T)->Union.atom = L->Union.atom;
            else
            {
                CopyGList_GL_H_T(&((*T)->Union.ptr.hp),L->Union.ptr.hp);
                CopyGList_GL_H_T(&((*T)->Union.ptr.tp),L->Union.ptr.tp);
            }
        }
    }

    int GListLength_GL_H_T(GList L)
    {
        int count;
        for(count=0;L;count++,L=L->Union.ptr.tp)
            ;
        return count;
    }

    int GListDepth_GL_H_T(GList L)
    {
        int max,deep;
        GList p;
        if(!L)
            return 1;
        if(L->tag == Atom)
            return 0;
        for(max=0,p=L;p;p=p->Union.ptr.tp)
        {
            deep = GListDepth_GL_H_T(p->Union.ptr.hp);
            if(deep>max)
                max = deep;
        }
        return max + 1;
    }

    Status GListEmpty_GL_H_T(GList L)
    {
        if(!L)
            return TRUE;
        else
            return FALSE;
    }

    GList GetHead_GL_H_T(GList L)
    {
        GList p;
        if(!L)
        {
            printf("Table is empty!\n");
            exit(ERROR);
        }
        CopyGList_GL_H_T(&p,L->Union.ptr.hp);
        return p;
    }

    GList GetTail_GL_H_T(GList L)
    {
        GList p;
        if(!L)
        {
            printf("Table is empty!\n");
            exit(ERROR);
        }
        CopyGList_GL_H_T(&p,L->Union.ptr.tp);
        return p;
    }

    void InsertFirst_GL_H_T(GList *L,GList e)
    {
        GList g;
        g = (GList)malloc(sizeof(GLNode));
        if(!g)
            exit(OVERFLOW);
        g->tag = 1;
        g->Union.ptr.hp = e;
        g->Union.ptr.tp = *L;
        *L = g;
    }

    void DeleteFirst_GL_H_T(GList *L,GList *e)
    {
        GList p;
        if(!(*L))
        {
            printf("Table is empty!\n");
            exit(ERROR);
        }
        p = *L;
        *L = (*L)->Union.ptr.tp;
        CopyGList_GL_H_T(e,p->Union.ptr.hp);
        free(p);
        p = NULL;
    }

    void Traverse_GL_H_T(GList L,void(Visit)(AtomType))
    {
        if(L)
        {
            if(L->tag == Atom)
                Visit(L->Union.atom);
            else
            {
                Traverse_GL_H_T(L->Union.ptr.hp,Visit);
                Traverse_GL_H_T(L->Union.ptr.tp,Visit);
            }
        }
    }

    void Output_GL_H_T(GList L,Mark mark)
    {
        if(!L)
        {
            if(mark==Head)
                printf("()");
            else
                printf(")");
        }
        else
        {
            if(L->tag==Atom)
                printf("%c",L->Union.atom);
            else
            {
                if(mark==Head)
                    printf("(");
                else
                    printf(",");
                Output_GL_H_T(L->Union.ptr.hp,Head);
                Output_GL_H_T(L->Union.ptr.tp,Tail);
            }
        }
    }

    #endif // GENERALIZEDLIST_H_T_C
	{%endhighlight%}

---

  If you find there are faults in the source codes, any method connecting with me is welcomed.
