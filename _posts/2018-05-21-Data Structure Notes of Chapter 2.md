---
layout: post
title: Data Structure Notes of Chapter 2
description: "my thoughts and notes when learning Data Structure"
categories: [Data-Structure]
tags: [C]
redirect_from:
  - /2018/05/21/
---
# Data Structure Notes of Chapter 2

Linear list is the most common and simplest data structure. I put the source codes of sequencelist,singlelinkedlist and dualcyclelinkedlist on this article.

I'll put Status.h on this article,too. And this header file will be used in this whole categories.

---

	{%highlight ruby%}
	SequenceList.h
    #ifndef SEQUENCELIST_H_INCLUDED
    #define SEQUENCELIST_H_INCLUDED

    #include <stdio.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    #define LIST_INIT_SIZE 100
    #define LISTINCREMENT 10

    #ifndef LELEMTYPE_SQ
    #define LELEMTYPE_SQ
    typedef int LElemType_Sq;
    #endif // LELEMTYPE_SQ

    typedef struct{
        LElemType_Sq *elem;
        int length;
        int listsize;
    }SqList;

    Status InitList_Sq(SqList *L);

    void ClearList_Sq(SqList *L);

    void Destroy_Sq(SqList *L);

    Status ListEmpty_Sq(SqList L);

    int ListLength_Sq(SqList L);

    Status GetElem_Sq(SqList L, int i,LElemType_Sq *e);

    int LocateElem_Sq(SqList L,LElemType_Sq e,Status(Compare)(LElemType_Sq,LElemType_Sq));

    Status PriorElem_Sq(SqList L,LElemType_Sq cur_e,LElemType_Sq *pre_e);

    Status NextElem_Sq(SqList L,LElemType_Sq cur_e,LElemType_Sq *next_e);

    Status ListInsert_Sq(SqList *L,int i,LElemType_Sq e);

    Status ListDelete_Sq(SqList *L,int i,LElemType_Sq *e);

    Status ListTraverse_Sq(SqList L,void(Visit)(LElemType_Sq));

    #endif // SEQUENCELIST_H_INCLUDED

	{%endhighlight%}

---

	{%highlight ruby%}
	SequenceList.c
    #ifndef SEQUENCELIST_C
    #define SEQUENCELIST_C

    #include "SequenceList.h"


    Status InitList_Sq(SqList *L)
    {
        (*L).elem = (LElemType_Sq*)malloc(LIST_INIT_SIZE*sizeof(LElemType_Sq));
        if(!(*L).elem)
            exit(OVERFLOW);

        (*L).length = 0;
        (*L).listsize = LIST_INIT_SIZE;

        return OK;
    }

    void ClearList_Sq(SqList *L)
    {
        (*L).length = 0;
    }

    void DestroyList_Sq(SqList *L)
    {
        free((*L).elem);

        (*L).elem = NULL;
        (*L).length = 0;
        (*L).listsize = 0;
    }

    Status ListEmpty_Sq(SqList L)
    {
        return 	L.length==0 ? TRUE : FALSE;
    }

    int ListLength_Sq(SqList L)
    {
        return L.length;
    }

    Status GetElem_Sq(SqList L, int i, LElemType_Sq *e)
    {
        if(i<1 || i>L.length)
            return ERROR;
        else
            *e = L.elem[i-1];

        return OK;
    }

    int LocateElem_Sq(SqList L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq))
    {
        int i = 1;

        while(i<=L.length && !Compare(e, L.elem[i-1]))
            ++i;

        if(i<=L.length)
            return i;
        else
            return 0;
    }

    Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e)
    {
        int i = 1;

        if(L.elem[0]!=cur_e)
        {
            while(i<L.length && L.elem[i]!=cur_e)
                ++i;

            if(i<L.length)
            {
                *pre_e = L.elem[i-1];
                return OK;
            }
        }

        return ERROR;
    }

    Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e)
    {
        int i = 0;

        while(i<L.length && L.elem[i]!=cur_e)
            ++i;

        if(i<L.length-1)
        {
            *next_e = L.elem[i+1];
            return OK;
        }

        return ERROR;
    }

    Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e)
    {
        LElemType_Sq *newbase;
        LElemType_Sq *p, *q;

        if(i<1 || i>(*L).length+1)
            return ERROR;

        if((*L).length >= (*L).listsize)
        {
            newbase = (LElemType_Sq*)realloc((*L).elem, ((*L).listsize+LISTINCREMENT)*sizeof(LElemType_Sq));
            if(!newbase)
                exit(OVERFLOW);

            (*L).elem = newbase;
            (*L).listsize += LISTINCREMENT;
        }

        q = &(*L).elem[i-1];

        for(p=&(*L).elem[(*L).length-1]; p>=q; --p)
            *(p+1) = *p;

        *q = e;
        (*L).length++;

        return OK;
    }

    Status ListDelete_Sq(SqList *L, int i, LElemType_Sq *e)
    {
        LElemType_Sq *p, *q;

        if(i<1 || i>(*L).length)
            return ERROR;

        p = &(*L).elem[i-1];
        *e = *p;
        q = (*L).elem+(*L).length-1;

        for(++p; p<=q; ++p)
            *(p-1) = *p;

        (*L).length--;

        return OK;
    }

    Status ListTraverse_Sq(SqList L, void(Visit)(LElemType_Sq))
    {
        int i;

        for(i=0; i<L.length; i++)
            Visit(L.elem[i]);

        return OK;
    }

    #endif
	{%endhighlight%}

---

	{%highlight ruby%}
	SingleLinkedList.h
    #ifndef SINGLYLINKEDLIST_H
    #define SINGLYLINKEDLIST_H

    #include <stdio.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    #ifndef BANKQUEUING_H
    typedef int LElemType_L;


    typedef struct LNode
    {
        LElemType_L data;
        struct LNode* next;
    }LNode;
    typedef LNode* LinkList;
    #endif


    Status InitList_L(LinkList *L);

    Status ClearList_L(LinkList L);

    void DestroyList_L(LinkList *L);

    Status ListEmpty_L(LinkList L);

    int ListLength_L(LinkList L);

    Status GetElem_L(LinkList L, int i, LElemType_L *e);

    int LocateElem_L(LinkList L, LElemType_L e, Status(Compare)(LElemType_L, LElemType_L));

    Status PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *pre_e);

    Status NextElem_L(LinkList L, LElemType_L cur_e, LElemType_L *next_e);

    Status ListInsert_L(LinkList L, int i, LElemType_L e);

    Status ListDelete_L(LinkList L, int i, LElemType_L *e);

    Status ListTraverse_L(LinkList L, void(Visit)(LElemType_L));

    //Status CreateList_HL(FILE *fp, LinkList *L, int n);

    //Status CreateList_TL(FILE *fp, LinkList *L, int n);

    #endif
	{%endhighlight%}

---

	{%highlight ruby%}
	SingleLinkedList.c
    #ifndef SINGLELINKEDLIST_C
    #define SINGLELINKEDLIST_C

    #include "SingleLinkedList.h"

    Status InitList_L(LinkList *L)
    {
        (*L) = (LinkList)malloc(sizeof(LNode));
        if(!(*L))
            exit(OVERFLOW);
        (*L)->next = NULL;

        return OK;
    }

    Status ClearList_L(LinkList L)
    {
        LinkList pre, p;

        if(!L)
            return ERROR;

        pre = L->next;

        while(pre)
        {
            p = pre->next;
            free(pre);
            pre = p;
        }

        L->next = NULL;

        return OK;
    }

    void DestroyList_L(LinkList *L)
    {
        LinkList p = *L;

        while(p)
        {
            p = (*L)->next;
            free(*L);
            (*L) = p;
        }
    }

    Status ListEmpty_L(LinkList L)
    {
        if(L!=NULL && L->next==NULL)
            return TRUE;
        else
            return FALSE;
    }

    int ListLength_L(LinkList L)
    {
        LinkList p;
        int i;

        if(L)
        {
            i = 0;
            p = L->next;
            while(p)
            {
                i++;
                p = p->next;
            }
        }

        return i;
    }

    Status GetElem_L(LinkList L, int i, LElemType_L *e)
    {
        int j;
        LinkList p = L->next;

        j = 1;
        p = L->next;

        while(p && j<i)
        {
            j++;
            p = p->next;
        }

        if(!p || j>i)
            return ERROR;

        *e = p->data;

        return OK;
    }

    int LocateElem_L(LinkList L, LElemType_L e, Status(Compare)(LElemType_L, LElemType_L))
    {
        int i;
        LinkList p;

        i = -1;

        if(L)
        {
            i = 0;
            p = L->next;

            while(p)
            {
                i++;

                if(!Compare(e, p->data))
                {
                    p = p->next;
                    if(p==NULL)
                        i++;
                }
                else
                    break;
            }
        }

        return i;
    }

    #ifndef BANKQUEUING_C
    Status PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *pre_e)
    {
        LinkList p, suc;

        if(L)
        {
            p = L->next;

            if(p->data!=cur_e)
            {
                while(p->next)
                {
                    suc = p->next;
                    if(suc->data==cur_e)
                    {
                        *pre_e = p->data;
                        return OK;
                    }
                    p = suc;
                }
            }
        }

        return ERROR;
    }

    Status NextElem_L(LinkList L, LElemType_L cur_e, LElemType_L *next_e)
    {
        LinkList p, suc;

        if(L)
        {
            p = L->next;

            while(p && p->next)
            {
                suc = p->next;

                if(suc && p->data==cur_e)
                {
                    *next_e = suc->data;
                    return OK;
                }

                if(suc)
                    p = suc;
                else
                    break;
            }
        }

        return ERROR;
    }
    #endif

    Status ListInsert_L(LinkList L, int i, LElemType_L e)
    {
        LinkList p, s;
        int j;

        p = L;
        j = 0;

        while(p && j<i-1)
        {
            p = p->next;
            ++j;
        }

        if(!p || j>i-1)
            return ERROR;

        s = (LinkList)malloc(sizeof(LNode));
        if(!s)
            exit(OVERFLOW);
        s->data = e;
        s->next = p->next;
        p->next = s;

        return OK;
    }

    Status ListDelete_L(LinkList L, int i, LElemType_L *e)
    {
        LinkList pre, p;
        int j;

        pre = L;
        j = 1;

        while(pre->next && j<i)
        {
            pre = pre->next;
            ++j;
        }

        if(!pre->next || j>i)
            return ERROR;

        p = pre->next;
        pre->next = p->next;
        *e = p->data;
        free(p);

        return OK;
    }

    Status ListTraverse_L(LinkList L, void(Visit)(LElemType_L))
    {
        LinkList p;

        if(!L)
            return ERROR;
        else
            p = L->next;

        while(p)
        {
            Visit(p->data);
            p = p->next;
        }

        return OK;
    }

    /*Status CreateList_HL(FILE *fp, LinkList *L, int n)
    {
        int i;
        LinkList p;
        LElemType_L tmp;

        *L = (LinkList)malloc(sizeof(LNode));
        if(!(*L))
            exit(OVERFLOW);
        (*L)->next = NULL;

        for(i=1; i<=n; ++i)
        {
            if(Scanf(fp, "%d", &tmp)==1)
            {
                p = (LinkList)malloc(sizeof(LNode));
                if(!p)
                    exit(OVERFLOW);
                p->data = tmp;
                p->next = (*L)->next;
                (*L)->next = p;
            }
            else
                return ERROR;
        }

        return OK;
    }

    Status CreateList_TL(FILE *fp, LinkList *L, int n)
    {
        int i;
        LinkList p, q;
        LElemType_L tmp;

        *L = (LinkList)malloc(sizeof(LNode));
        if(!(*L))
            exit(OVERFLOW);
        (*L)->next = NULL;

        for(i=1,q=*L; i<=n; ++i)
        {
            if(Scanf(fp, "%d", &tmp)==1)
            {
                p = (LinkList)malloc(sizeof(LNode));
                if(!p)
                    exit(OVERFLOW);
                p->data = tmp;
                q->next = p;
                q = q->next;
            }
            else
                return ERROR;
        }

        q->next = NULL;

        return OK;
    }
    */
    #endif
	{%endhighlight%}

---

	{%highlight ruby%}
	DualCycleLinkedList.h
    #ifndef DUALCYCLELINKEDLIST_H
    #define DUALCYCLELINKEDLIST_H

    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    typedef int LElemType_DC;
    typedef struct DuLNode
    {
        LElemType_DC data;
        struct DuLNode *prior;
        struct DuLNode *next;
    }DuLNode;
    typedef DuLNode* DuLinkList;

    Status InitList_DuL(DuLinkList *L);

    Status ClearList_DuL(DuLinkList L);

    void DestroyList_DuL(DuLinkList *L);

    Status ListEmpty_DuL(DuLinkList L);

    int ListLength_DuL(DuLinkList L);

    Status GetElem_DuL(DuLinkList L, int i, LElemType_DC *e);

    int LocateElem_DuL(DuLinkList L, LElemType_DC e, Status (Compare)(LElemType_DC, LElemType_DC));

    Status PriorElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *pre_e);

    Status NextElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *next_e);

    DuLinkList GetElemPtr_DuL(DuLinkList L, int i);

    Status ListInsert_DuL(DuLinkList L, int i, LElemType_DC e);

    Status ListDelete_DuL(DuLinkList L, int i, LElemType_DC *e);

    void ListTraverse_DuL(DuLinkList L, void(Visit)(LElemType_DC));

    #endif
	{%endhighlight%}

---

	{%highlight ruby%}
	DualCycleLinkedList.c
    #ifndef DUALCYCLELINKEDLIST_C
    #define DUALCYCLELINKEDLIST_C

    #include "DualCycleLinkedList.h"

    Status InitList_DuL(DuLinkList *L)
    {
        *L = (DuLinkList)malloc(sizeof(DuLNode));
        if(!(*L))
            exit(OVERFLOW);

        (*L)->next = (*L)->prior = *L;

        return OK;
    }

    Status ClearList_DuL(DuLinkList L)
    {
        DuLinkList p, q;

        p = L->next;

        while(p!=L)
        {
            q = p->next;
            free(p);
            p = q;
        }

        L->next = L->prior = L;

        return OK;
    }

    void DestroyList_DuL(DuLinkList *L)
    {
        ClearList_DuL(*L);

        free(*L);

        *L = NULL;
    }

    Status ListEmpty_DuL(DuLinkList L)
    {
        if(L && L->next==L && L->prior==L)
            return TRUE;
        else
            return FALSE;
    }

    int ListLength_DuL(DuLinkList L)
    {
        DuLinkList p;
        int count;

        if(L)
        {
            count = 0;
            p = L;

            while(p->next!=L)
            {
                count++;
                p = p->next;
            }
        }

        return count;
    }

    Status GetElem_DuL(DuLinkList L, int i, LElemType_DC *e)
    {
        DuLinkList p;
        int count;

        if(L)
        {
            count = 1;
            p = L->next;

            while(p!=L && count<i)
            {
                count++;
                p = p->next;
            }

            if(p!=L)
            {
                *e = p->data;
                return OK;
            }
        }

        return ERROR;
    }

    int LocateElem_DuL(DuLinkList L, LElemType_DC e, Status(Compare)(LElemType_DC, LElemType_DC))
    {
        DuLinkList p;
        int count;

        if(L)
        {
            count = 1;
            p = L->next;

            while(p!=L && !Compare(e, p->data))
            {
                count++;
                p = p->next;
            }

            if(p!=L)
                return count;
        }

        return 0;
    }

    Status PriorElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *pre_e)
    {
        DuLinkList p;

        if(L)
        {
            p = L->next;

            while(p!=L && p->data!=cur_e)
                p = p->next;

            if(p!=L && p->prior!=L)
            {
                *pre_e = p->prior->data;
                return OK;
            }
        }

        return ERROR;
    }

    Status NextElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *next_e)
    {
        DuLinkList p;

        if(L)
        {
            p = L->next;

            while(p!=L && p->data!=cur_e)
                p = p->next;

            if(p!=L && p->next!=L)
            {
                *next_e = p->next->data;
                return OK;
            }
        }


        return ERROR;
    }

    DuLinkList GetElemPtr_DuL(DuLinkList L, int i)
    {
        int count;
        DuLinkList p;

        if(L && i>0)
        {
            count = 1;
            p = L->next;

            while(p!=L && count<i)
            {
                count++;
                p = p->next;
            }

            if(p!=L)
                return p;
        }

        return NULL;
    }

    Status ListInsert_DuL(DuLinkList L, int i, LElemType_DC e)
    {
        DuLinkList p, s;

        if(i<1 || i>ListLength_DuL(L)+1)
            return ERROR;

        p = GetElemPtr_DuL(L, i);
        if(!p)
            p = L;

        s = (DuLinkList)malloc(sizeof(DuLNode));
        if(!s)
            exit(OVERFLOW);
        s->data = e;

        s->prior = p->prior;
        p->prior->next = s;
        s->next = p;
        p->prior = s;

        return OK;
    }

    Status ListDelete_DuL(DuLinkList L, int i, LElemType_DC *e)
    {
        DuLinkList p;

        if(!(p=GetElemPtr_DuL(L, i)))
            return ERROR;

        *e = p->data;
        p->prior->next = p->next;
        p->next->prior = p->prior;

        free(p);
        p = NULL;

        return OK;
    }

    void ListTraverse_DuL(DuLinkList L, void(Visit)(LElemType_DC))
    {
        DuLinkList p;

        p = L->next;

        while(p!=L)
        {
            Visit(p->data);
            p = p->next;
        }
    }

    #endif
	{%endhighlight%}

---

	{%highlight ruby%}
	Status.h
    #ifndef STATUS_H_INCLUDED
    #define STATUS_H_INCLUDED

    #define TRUE 1
    #define FALSE 0
    #define YES 1
    #define NO 0
    #define OK 1
    #define ERROR 0
    #define SUCCESS 1
    #define UNSUCCESS 0
    #define INFEASIBLE -1

    #ifndef _MATH_H
    #define OVERFLOW -2
    #define UNDERFLOW -3
    #endif // _MATH_H

    #ifndef NULL
    #define NULL ((void*)0)
    #endif // NULL

    typedef int Status;

    #define Wait(x)\
    {\
        double _Loop_Num_;\
        for(_Loop_Num_=0.01;_Loop_Num_<=100000.0*x;_Loop_Num+=0.01)\
            ;\
    }

    #define PressEnter\
     {\
        fflush(stdin);\
        printf("Press Enter...");\
        getchar();\
        fflush(stdin);\
    }

    #endif // STATUS_H_INCLUDED
	{%endhighlight%}

---
  If you find there are faults in the source codes, any method connecting with me is welcomed.
