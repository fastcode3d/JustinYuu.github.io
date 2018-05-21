---
layout: post
title: Data Structure Algorithm Designing Assignments Chapter 2
description: "my own source codes of Algorithm Designing Assignment in Data Structure"
categories: [Data-Structure]
tags: [C]
redirect_from:
  - /2018/04/11/
---
# Data Structure Algorithm Designing Assignments Chapter 2

    {% highlight ruby %}
	2.10.c
    #include <stdio.h>
    #include "SequenceList.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    Status Algo_2_10(SqList *a,int i,int k);
    void PrintElem(LElemType_Sq e);
    int main(void)
    {
        SqList L;
        int i;
        if(InitList_Sq(&L))
        {
            for(i=1;i<=20;i++)
                ListInsert_Sq(&L,i,i);
        }
        printf("L = ");
        ListTraverse_Sq(L,PrintElem);
        printf("\n");

        printf("Delete 10 elements from the fifth element.\n");
        Algo_2_10(&L,5,10);
        printf("L= ");
        ListTraverse_Sq(L,PrintElem);
        printf("\n");
        printf("Bye!");
        return 0;
    }
    Status Algo_2_10(SqList *a,int i,int k)
    {
        int j;
        if(i<1||i>(*a).length||k<0||i+k-1>(*a).length)
            return ERROR;
        for(j=i+k;j<=(*a).length;j++)
            (*a).elem[j-k-1] = (*a).elem[j-1];
        (*a).length -=k;
        return OK;
    }
    void PrintElem(LElemType_Sq e)
    {
        printf("%d ",e);
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.11.c
    #include <stdio.h>
    #include "SequenceList.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    Status Algo_2_11(SqList *a,LElemType_Sq x);
    void PrintElem(LElemType_Sq e);
    int main(void)
    {
        SqList L;
        int i;
        if(InitList_Sq(&L))
        {
            for(i=1;i<=5;i++)
                ListInsert_Sq(&L,i,2*i);
        }
        printf("L = ");
        ListTraverse_Sq(L,PrintElem);
        printf("\n");

        printf("Insert 5.\n");
        Algo_2_11(&L,5);
        printf("L= ");
        ListTraverse_Sq(L,PrintElem);
        printf("\n");
        printf("Bye!");
        return 0;
    }
    Status Algo_2_11(SqList *a,LElemType_Sq x)
    {
        int i;
        LElemType_Sq *temp;
        if(!(*a).length)
            return ERROR;
        if((*a).length==(*a).listsize)
        {
            temp = (LElemType_Sq*)realloc((*a).elem,((*a).listsize+LISTINCREMENT)*sizeof(LElemType_Sq));
            if(!temp)
                exit(OVERFLOW);
            (*a).elem = temp;
            (*a).listsize+=LISTINCREMENT;
        }
        for(i=(*a).length;i>=1;i--)
        {
            if((*a).elem[i-1]>x)
                (*a).elem[i] = (*a).elem[i-1];
            else
                break;
        }
        (*a).elem[i] = x;
        (*a).length++;
        return OK;
    }
    void PrintElem(LElemType_Sq e)
    {
        printf("%d ",e);
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.12.c
    #include <stdio.h>
    #include "SequenceList.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    int Algo_2_12(SqList a,SqList b);
    void PrintElem(LElemType_Sq e);

    int main(void)
    {
        SqList A;
        SqList B;
        int i;
        int j;
        if(InitList_Sq(&A))
        {
            for(i=1;i<=10;i++)
                ListInsert_Sq(&A,i,i);
        }
        printf("A = ");
        ListTraverse_Sq(A,PrintElem);
        printf("\n");
        if(InitList_Sq(&B))
        {
            for(i=1;i<=5;i++)
                ListInsert_Sq(&B,i,i);
        }
        printf("B = ");
        ListTraverse_Sq(B,PrintElem);
        printf("\n");
        j=Algo_2_12(A,B);
        if(i<0)
            printf("A<B\n");
        else if(i>0)
            printf("A>B\n");
        else
            printf("A=B\n");
        printf("Bye!\n");
        return 0;
    }
    int Algo_2_12(SqList a,SqList b)
    {
        int i,j;
        for(int i=0;i<=a.length && i<=b.length;i++)
        {
            if(a.elem[i]>b.elem[i])
                return 1;
            else if(a.elem[i]<b.elem[i])
                return -1;
            else
                i++;
        }
        if(i<a.length)
            return 1;
        else if(i<b.length)
            return -1;
        else
            return 0;
    }
    void PrintElem(LElemType_Sq e)
    {
        printf("%d ",e);
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.13.c
    #include <stdio.h>
    #include "SingleLinkedList.c"
    int Algo_2_13(LinkList L,LElemType_L e);
    void PrintElem(LElemType_L e);
    int main()
    {
        LinkList L;
        int i;
        if(InitList_L(&L))
        {
            for(i=1;i<=10;i++)
                ListInsert_L(L,i,2*i);
        }
        printf("L = ");
        ListTraverse_L(L,PrintElem);
        printf("\n");
        printf("The location of element \"12\" in the single linked list is %d",Algo_2_13(L,12));
        return 0;
    }
    int Algo_2_13(LinkList L,LElemType_L e)
    {
        int i;
        LinkList p;
        if(L)
        {
            i=1;
            p=L->next;
            while(p)
            {
                if(p->data==e)
                    return i;
                i++;
                p=p->next;
            }
        }
        return 0;
    }
    void PrintElem(LElemType_L e)
    {
        printf("%d ",e);
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.14.c
    #include <stdio.h>
    #include "SingleLinkedList.c"
    int Algo_2_14(LinkList L);
    void PrintElem(LElemType_L e);
    int main(void)
    {
        int i;
        LinkList L;
        if(InitList_L(&L))
        {
            for(i=1;i<=10;i++)
                ListInsert_L(L,i,2*i);
        }
        printf("L = ");
        ListTraverse_L(L,PrintElem);
        printf("\n");
        printf("The length of the single linked list is %d",Algo_2_14(L));
        return 0;
    }
    int Algo_2_14(LinkList L)
    {
        int i;
        LinkList q;
        if(L)
        {
            i=0;
            q=L->next;
            while(q)
            {
                i++;
                q=q->next;
            }
        }
        return i;
    }
    void PrintElem(LElemType_L e)
    {
        printf("%d ",e);
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.15.c
    #include <stdio.h>
    #include "SingleLinkedList.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    Status Algo_2_15(LinkList ha,LinkList hb,LinkList *hc);
    void PrintElem(LElemType_L e);
    int main(void)
    {
        LinkList ha,hb,hc;
        int i;
        if(InitList_L(&ha)&&InitList_L(&hb)&&InitList_L(&hc))
        {
            for(i=1;i<=10;i++)
                ListInsert_L(ha,i,i);
            for(i=1;i<=7;i++)
                ListInsert_L(hb,i,i);
        }
        printf("ha = ");
        ListTraverse_L(ha,PrintElem);
        printf("\n");
        printf("hb = ");
        ListTraverse_L(hb,PrintElem);
        printf("\n\n");
        Algo_2_15(ha,hb,&hc);
        printf("hc = ");
        ListTraverse_L(hc,PrintElem);
        printf("\n");
        return 0;
    }
    Status Algo_2_15(LinkList ha,LinkList hb,LinkList *hc)
    {
        LinkList pa;
        LinkList pb;
        if(ha&&hb)
        {
            pa=ha;
            pb=hb;
            while(pa->next && pb->next)
            {
                pa=pa->next;
                pb=pb->next;
            }
            if(!pa->next)
            {
                *hc=ha;
                pa->next=hb->next;
            }
            if(!pb->next)
            {
                *hc=hb;
                pb->next=ha->next;
            }
            return OK;
        }
        else
            return ERROR;
    }
    void PrintElem(LElemType_L e)
    {
        printf("%d ",e);
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.16.c
    #include <stdio.h>
    #include "SingleLinkedList.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    Status Algo_2_16(LinkList *la,LinkList *Slb,int i,int j,int len);
    void PrintElem(LElemType_L e);
    int main(void)
    {
        LinkList ha,hb;
        int i;
        if(InitList_L(&ha)&&InitList_L(&hb))
        {
            for(i=1;i<=10;i++)
                ListInsert_L(ha,i,i);
            for(i=1;i<=7;i++)
                ListInsert_L(hb,i,i);
        }
        printf("ha = ");
        ListTraverse_L(ha,PrintElem);
        printf("\n");
        printf("hb = ");
        ListTraverse_L(hb,PrintElem);
        printf("\n\n");
        Algo_2_16(&ha,&hb,4,5,2);
        printf("ha = ");
        ListTraverse_L(ha,PrintElem);
        printf("\n");
        printf("hb = ");
        ListTraverse_L(hb,PrintElem);
        printf("\n\n");
        printf("\n");
        return 0;
    }
    Status Algo_2_16(LinkList *la,LinkList *lb,int i,int j,int len)
    {
        LinkList p,q,s,temp;
        int k;
        if(i<0||j<0||len<0)
            return INFEASIBLE;
        p=*la;
        k=1;
        temp = NULL;
        while(p&&k<i)
        {
            temp = p;
            p=p->next;
            k++;
        }
        if(!p)
            return INFEASIBLE;
        q=p;
        while(q && k<i+len-1)
        {
            q=q->next;
            k++;
        }
        if(!q)
            return INFEASIBLE;
        if(!temp)
            *la = q->next;
        else
            temp->next = q->next;
        if(j==1)
        {
            q->next = *lb;
            *lb = p;
        }
        else
        {
            s=*lb;
            k=1;
            while(s && k<j-1)
            {
                s=s->next;
                k++;
            }
        if(!s)
            return INFEASIBLE;
        q->next = s->next;
        s->next = p;
        return OK;
        }
    }
    void PrintElem(LElemType_L e)
    {
        printf("%d ",e);
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.17.c
    //This LinkList have no head node.Thus only algorithm is given for there's no header file creating LinkList without head node.
    Status Algo_2_17(LinkList *L,int i;LElemType_L b)
    {
        LinkList p,q;
        int count;
        p=(LinkList)malloc(sizeof(LNode))
        if(!p)
            exit(OVERFLOW);
        p->date =b;
        if(i>0)
        {
            if(i==1)
            {
                p->next = *L;
                *L=p;
                return OK;
            }
            else
            {
                if(*L)
                {
                    count = 1;
                    q = *L;
                    while(count <i-1&& q)
                    {
                        count++;
                        q = q->next;
                    }
                    if(q)
                    {
                        p->next = q->next;
                        q->next = p;
                        return OK;
                    }
                }
            }
        }
        return ERROR;
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.18.c
    //This LinkList have no head node.Thus only algorithm is given for there's no header file creating LinkList without head node.
    Status Algo_2_18(LinkList *L,int i)
    {
        LinkList p,q;
        int count;
        if(i>0)
        {
            p=*L;
            count =1;
            while(p&&count<i-1)
            {
                count++;
                p=p->next;
            }
            if(p)
            {
                if(count>i-1)
                {
                    *L=(*L)->next;
                    free(p);
                    return OK;
                }
                else
                {
                    if(p->next)
                    {
                        q = p->next;
                        p->next = q->next;
                        free(q);
                        return OK;
                    }
                }
            }
        }
        else
            return ERROR;
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.19.c
    #include <stdio.h>
    #include "SingleLinkedList.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    Status Algo_2_19(LinkList L,int mink,int maxk);
    void PrintElem(LElemType_L e);
    int main(void)
    {
        LinkList L;
        int i;
        int mink;
        int maxk;
        if(InitList_L(&L))
        {
            for(i=1;i<=10;i++)
                ListInsert_L(L,i,i);
        }
        printf("L = ");
        ListTraverse_L(L,PrintElem);
        printf("\n");
        printf("Please input your maximum number:");
        scanf("%d",&maxk);
        printf("Please input your minimum number:");
        scanf("%d",&mink);
        if(Algo_2_19(L,mink,maxk))
        {
            printf("L = ");
            ListTraverse_L(L,PrintElem);
            printf("\n");
        }
        else
            printf("Error!");
    }
    Status Algo_2_19(LinkList L,int mink,int maxk)
    {
        LinkList p,q,s;
        if(!L||!L->next)
            return ERROR;
        if(mink>=maxk)
            return ERROR;
        q = L;
        p=q->next;
        while(p && p->data<maxk)
        {
            if(p->data<=mink)
            {
                q=p;
                p=p->next;
            }
            else
            {
                s=p;
                q->next = p->next;
                p=p->next;
                free(s);
            }
        }
        return OK;
    }
    void PrintElem(LElemType_L e)
    {
        printf("%d ",e);
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.20.c
    #include <stdio.h>
    #include "SingleLinkedList.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    Status Algo_2_20(LinkList L);
    void PrintElem(LElemType_L e);
    int main(void)
    {
        LinkList L;
        int i;
        InitList_L(&L);
        int a[10]={1,2,2,3,4,5,5,5,7,9};

        for(i=0;i<10;i++)
            ListInsert_L(L,i+1,a[i]);
        printf("L = ");
        ListTraverse_L(L,PrintElem);
        printf("\n");

        Algo_2_20(L);
        printf("The LinkList without repeated element are as below:\n");
        printf("L = ");
        ListTraverse_L(L,PrintElem);
        return 0;
    }
    Status Algo_2_20(LinkList L)
    {
        LinkList p,q,s;
        if(!L||!L->next)
            return ERROR;
        q = L->next;
        p = q->next;
        while(p)
        {
            if(q->data != p->data)
            {
                q = p;
                p = p->next;
            }
            else
            {
                s = p;
                q->next = p->next;
                p = p->next;
                free(s);
            }
        }
        return OK;
    }
    void PrintElem(LElemType_L e)
    {
        printf("%d ",e);
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.21.c
    #include <stdio.h>
    #include "SequenceList.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    Status Algo_2_21(SqList L);
    void PrintElem(LElemType_Sq);
    int main(void)
    {
        SqList L;
        int i; 
        InitList_Sq(&L);
        for(i=1;i<=10;i++)
            ListInsert_Sq(&L,i,i);
        printf("L = ");
        ListTraverse_Sq(L,PrintElem);
        printf("\n");
        Algo_2_21(L);
        printf("The SequenceList in reverse sequence is:\n");
        printf("L = ");
        ListTraverse_Sq(L,PrintElem);
        printf("\n");
        return 0;
    }
    Status Algo_2_21(SqList L)
    {
        int i,j;
        LElemType_Sq temp;
        if(L.length == 0)
            return ERROR;
        for(j=1,i=(L.length/2);j<=i;j++)
        {
            temp = L.elem[j-1];
            L.elem[j-1]=L.elem[L.length-j];
            L.elem[L.length-j] = temp;
        }
        return OK;
    }
    void PrintElem(LElemType_Sq e)
    {
        printf("%d ",e);
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.22.c
    #include <stdio.h>
    #include "SingleLinkedList.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    Status Algo_2_22(LinkList L);
    void PrintElem(LElemType_L e);
    int main(void)
    {
        int i;
        LinkList L;
        InitList_L(&L);
        for(i=1;i<=10;i++)
            ListInsert_L(L,i,i);
        printf("L = ");
        ListTraverse_L(L,PrintElem);
        printf("\n");

        Algo_2_22(L);
        printf("L = ");
        ListTraverse_L(L,PrintElem);
        printf("\n");
        return 0;
    }
    Status Algo_2_22(LinkList L)
    {
        LinkList pre,p;
        if(!L||!L->next)
            return ERROR;
        p = L->next;
        L->next = NULL;
        while(p)
        {
            pre = p;
            p = p->next;
            pre->next = L->next;
            L->next = pre;
        }
        return OK;
    }
    void PrintElem(LElemType_L e)
    {
        printf("%d ",e);
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.23.c
    #include <stdio.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    typedef int LElemType_DC;
    typedef struct DuLNode
    {
        LElemType_DC data;
        struct DuLNode *prior;
        struct DuLNode *next;
        int freq;
    }DuLNode;
    typedef DuLNode* DuLinkList;

    DuLinkList Algo_2_38(DuLinkList *L,LElemType_DC e);
    Status CreateList_Dul_2_38(DuLinkList *L,int n,LElemType_DC Data[]);
    void Output_Dul_2_38(DuLinkList L);
    int main(void)
    {
        DuLinkList L,p;
        int i;
        LElemType_DC data[10] = {1,2,3,4,5,6,7,8,9,10};
        LElemType_DC temp[10] = {1,2,3,4,5,6,7,8,9,10};
        CreateList_Dul_2_38(&L,10,data);
        Output_Dul_2_38(L);
        printf("\n");
        for(i=0;i<10;i++)
            Algo_2_38(&L,temp[i]);
        Output_Dul_2_38(L);
        printf("\n");
        return 0;
    }
    Status CreateList_Dul_2_38(DuLinkList *L,int n,LElemType_DC Data[])
    {
        int i;
        DuLinkList s,h;
        *L =NULL;
        for(i=1;i<=n;i++)
        {
            s = (DuLinkList)malloc(sizeof(DuLNode));
            if(!s)
                exit(OVERFLOW);
            s->data = Data[i-1];
            s->freq = 0;
            if(*L == NULL)
            {
                *L = s;
                h = s;
                s->prior=s;
                s->next = s;
            }
            else
            {
                s->next = *L;
                s->prior = h;
                h->next = s;
                (*L)->prior = s;
                h = h->next;
            }
        }
        s = NULL;
        return OK;
    }
    void Output_Dul_2_38(DuLinkList L)
    {
        DuLinkList p = L;
        printf("L = ");
        for(p=L;p;p=p->next)
        {
            printf("%2d ",p->data);
            if(p->next == L)
                break;
        }
    }
    DuLinkList Algo_2_38(DuLinkList *L,LElemType_DC e)
    {
        DuLinkList p,pre;
        int i;
        if(!(*L))
            return NULL;
        for(p=*L;p;p = p->next)
        {
            if(p->data == e)
                break;
            if(p->next == p)
            {
                p =NULL;
                break;
            }
        }
        if(p!=NULL)
        {
            p->freq++;
            if(p!=*L)
            {
                for(pre=p->prior;pre->freq<p->freq;pre=pre->prior)
                {
                    if(pre == *L)
                    {
                        pre==NULL;
                        break;
                    }
                }
                p->next->prior = p->prior;
                p->prior->next = p->next;
                if(pre == NULL)
                {
                    p->prior = (*L)->prior;
                    p->prior->next = p;
                    p->next = *L;
                    (*L)->prior = p;
                    *L = p;
                }
                else
                {
                    p->prior = pre;
                    p->next = pre->next;
                    p->next->prior = p;
                    pre->next = p;
                }
            }
        }
        return p;
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.24.c
    #include <stdio.h>
    #include "SingleLinkedList.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    Status Algo_2_24(LinkList La,LinkList *Lb,LinkList *Lc);
    void PrintElem(LElemType_L e);
    int main(void)
    {
        LinkList la,lb,lc;
        int i;
        InitList_L(&la);
        InitList_L(&lb);
        InitList_L(&lc);
        for(i=1;i<=5;i++)
        {
            ListInsert_L(la,i,i);
            ListInsert_L(lb,i,i+5);
        }
        printf("La = ");
        ListTraverse_L(la,PrintElem);
        printf("\n");
        printf("Lb = ");
        ListTraverse_L(lb,PrintElem);
        printf("\n");
        Algo_2_24(la,&lb,&lc);
        printf("Lc = ");
        ListTraverse_L(lc,PrintElem);
        printf("\n");
        return 0;
    }
    Status Algo_2_24(LinkList La,LinkList *Lb,LinkList *Lc)
    {
        LinkList pa,pb,s;
        if(!La || !Lb ||(!La->next && !(*Lb)->next))
            return ERROR;
        *Lc = La;
        pa = La->next;
        pb = (*Lb)->next;
        La->next = NULL;

        while(pa&&pb)
        {
            if(pa->data <= pb->data)
            {
                s = pa->next;
                pa->next = La->next;
                La->next = pa;
                pa = s;
            }
            else
            {
                s = pb->next;
                pb->next = La->next;
                La->next = pb;
                pb = s;
            }
        }
        while(pa)
        {
            s = pa->next;
            pa->next = La->next;
            La->next = pa;
            pa = s;
        }
        while(pb)
        {
            s = pb->next;
            pb->next = La->next;
            La->next = pb;
            pb = s;
        }
        free(*Lb);
        return OK;
    }
    void PrintElem(LElemType_L e)
    {
        printf("%d ",e);
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.25.c
    #include <stdio.h>
    #include "SequenceList.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    void PrintElem(LElemType_Sq e);
    Status Algo_2_25(SqList la,SqList lb,SqList *lc);
    int main(void)
    {
        SqList la,lb,lc;
        int i;
        InitList_Sq(&la);
        InitList_Sq(&lb);
        InitList_Sq(&lc);
        for(i=1;i<=10;i++)
        {
            ListInsert_Sq(&la,i,i);
            ListInsert_Sq(&lb,i,2*i);
        }
        printf("La = ");
        ListTraverse_Sq(la,PrintElem);
        printf("\n");
        printf("Lb = ");
        ListTraverse_Sq(lb,PrintElem);
        printf("\n");
        Algo_2_25(la,lb,&lc);
        printf("The insertion of La and Lb is:\n");
        ListTraverse_Sq(lc,PrintElem);
        return 0;
    }
    Status Algo_2_25(SqList la,SqList lb,SqList *lc)
    {
        int i,j,k;
        i=0;
        j=0;
        k=1;
        while(i<la.length && j<lb.length)
        {
            if(la.elem[i]<lb.elem[j])
                i++;
            else if(la.elem[i]>lb.elem[j])
                j++;
            else
            {
                ListInsert_Sq(lc,k,la.elem[i]);
                k++;
                i++;
                j++;
            }
        }
        return OK;
    }
    void PrintElem(LElemType_Sq e)
    {
        printf("%d ",e);
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.26.c
    #include <stdio.h>
    #include "SingleLinkedList.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    Status Algo_2_26(LinkList La,LinkList Lb,LinkList Lc);
    void PrintElem(LElemType_L e);
    int main(void)
    {
        LinkList la,lb,lc;
        int i;
        InitList_L(&la);
        InitList_L(&lb);
        InitList_L(&lc);
        for(i=1;i<=5;i++)
        {
            ListInsert_L(la,i,i);
            ListInsert_L(lb,i,2*i);
        }
        printf("La = ");
        ListTraverse_L(la,PrintElem);
        printf("\n");
        printf("Lb = ");
        ListTraverse_L(lb,PrintElem);
        printf("\n");
        Algo_2_26(la,lb,lc);
        printf("Lc = ");
        ListTraverse_L(lc,PrintElem);
        printf("\n");
        return 0;
    }
    Status Algo_2_26(LinkList La,LinkList Lb,LinkList Lc)
    {
        LinkList pa,pb,pc,s;
        if(!La || !Lb )
            return ERROR;
        pa = La->next;
        pb = Lb->next;
        pc = Lc;

        while(pa&&pb)
        {
            if(pa->data < pb->data)
                pa = pa->next;
            else if(pa->data > pb->data)
                pb = pb->next;
            else
            {
                s = (LinkList)malloc(sizeof(LNode));
                if(!s)
                    exit(OVERFLOW);
                s->data = pa->data;
                s->next = NULL;
                pc->next = s;
                pc = pc->next;
                pa = pa->next;
                pb = pb->next;
            }
        }
        return OK;
    }
    void PrintElem(LElemType_L e)
    {
        printf("%d ",e);
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.27.c
    #include <stdio.h>
    #include "SequenceList.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    void PrintElem(LElemType_Sq e);
    Status Algo_2_27_1(SqList la,SqList lb,SqList *lc);
    Status Algo_2_27_2(SqList *la,SqList lb);
    int main(void)
    {
        SqList la,lb,lc;
        int i;
        InitList_Sq(&la);
        InitList_Sq(&lb);
        InitList_Sq(&lc);
        for(i=1;i<=10;i++)
        {
            ListInsert_Sq(&la,i,i);
            ListInsert_Sq(&lb,i,2*i);
        }
        printf("La = ");
        ListTraverse_Sq(la,PrintElem);
        printf("\n");
        printf("Lb = ");
        ListTraverse_Sq(lb,PrintElem);
        printf("\n");
        Algo_2_27_1(la,lb,&lc);
        printf("The insertion of La and Lb is:\n");
        ListTraverse_Sq(lc,PrintElem);
        printf("\n");
        Algo_2_27_2(&la,lb);
        printf("The insertion of La and Lb is:\n");
        ListTraverse_Sq(lc,PrintElem);
        printf("\n");
        return 0;
    }
    Status Algo_2_27_1(SqList la,SqList lb,SqList *lc)
    {
        int i,j,k;
        i=0;
        j=0;
        k=1;
        while(i<la.length && j<lb.length)
        {
            if(la.elem[i]<lb.elem[j])
                i++;
            else if(la.elem[i]>lb.elem[j])
                j++;
            else
            {
                if(!i||la.elem[i]!=la.elem[i-1])
                {
                    ListInsert_Sq(lc,k,la.elem[i]);
                    k++;
                }
                i++;
                j++;
            }
        }
        return OK;
    }
    Status Algo_2_27_2(SqList *la,SqList lb)
    {
        int i,j,k;
        i=0;
        j=0;
        k=1;
        int a_len=0;
        while(i<(*la).length && j<lb.length)
        {
            if((*la).elem[i]<lb.elem[j])
                i++;
            else if((*la).elem[i]>lb.elem[j])
                j++;
            else
            {
                if(!i||(*la).elem[i]!=(*la).elem[i-1])
                {
                    (*la).elem[k]=(*la).elem[i];
                    k++;
                }
                i++;
                j++;
            }
        }
        (*la).length = a_len;
        return OK;
    }
    void PrintElem(LElemType_Sq e)
    {
        printf("%d ",e);
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.28.c
    #include <stdio.h>
    #include "SingleLinkedList.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    Status Algo_2_28_1(LinkList La,LinkList Lb,LinkList Lc);
    Status Algo_2_28_2(LinkList La,LinkList Lb);
    void PrintElem(LElemType_L e);
    int main(void)
    {
        LinkList la,lb,lc;
        int i;
        InitList_L(&la);
        InitList_L(&lb);
        InitList_L(&lc);
        for(i=1;i<=10;i++)
        {
            ListInsert_L(la,i,i);
            ListInsert_L(lb,i,2*i);
        }
        printf("La = ");
        ListTraverse_L(la,PrintElem);
        printf("\n");
        printf("Lb = ");
        ListTraverse_L(lb,PrintElem);
        printf("\n");
        Algo_2_28_1(la,lb,lc);
        printf("Lc = ");
        ListTraverse_L(lc,PrintElem);
        printf("\n");
        Algo_2_28_2(la,lb);
        printf("Lc = ");
        ListTraverse_L(lc,PrintElem);
        printf("\n");
        return 0;
    }
    Status Algo_2_28_1(LinkList La,LinkList Lb,LinkList Lc)
    {
        LinkList pa,pb,pc,s;
        if(!La || !Lb )
            return ERROR;
        pa = La->next;
        pb = Lb->next;
        pc = Lc;

        while(pa&&pb)
        {
            if(pa->data < pb->data)
                pa = pa->next;
            else if(pa->data > pb->data)
                pb = pb->next;
            else
            {
                if(pc == Lc || pc->data != pa->data)
                {
                    s = (LinkList)malloc(sizeof(LNode));
                    if(!s)
                        exit(OVERFLOW);
                    s->data = pa->data;
                    s->next = NULL;
                    pc->next = s;
                    pc = pc->next;
                }
                pa = pa->next;
                pb = pb->next;
            }
        }
        return OK;
    }
    Status Algo_2_28_2(LinkList La,LinkList Lb)
    {
        LinkList pa,pb,p;
        if(!La || !Lb )
            return ERROR;
        pa = La->next;
        pb = Lb->next;
        p = La;

        while(pa&&pb)
        {
            if(pa->data < pb->data)
                {
                    p->next = pa->next;
                    free(pa);
                    pa = p->next;
                }
            else if(pa->data > pb->data)
                    pb = pb->next;
            else
            {
                if(p == La || p->data != pa->data)
                {
                    p->next = pa;
                    free(pa);
                    pa = pa->next;
                }
                else
                {
                    p->next = pa->next;
                    free(pa);
                    pa = p->next;
                }
                pb = pb->next;
            }
        }
        return OK;
    }
    void PrintElem(LElemType_L e)
    {
        printf("%d ",e);
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.29.c
    #include <stdio.h>
    #include "SequenceList.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    void PrintElem(LElemType_Sq e);
    Status Algo_2_29(SqList *la,SqList lb,SqList lc);
    int main(void)
    {
        SqList la,lb,lc;
        int i,j,k;
        InitList_Sq(&la);
        InitList_Sq(&lb);
        InitList_Sq(&lc);
        for(i=1;i<=30;i++)
            ListInsert_Sq(&la,i,i);
        for(j=1;j<=15;j++)
            ListInsert_Sq(&lb,j,2*j);
        for(k=1;k<=10;k++)
            ListInsert_Sq(&lc,k,3*k);
        printf("La = ");
        ListTraverse_Sq(la,PrintElem);
        printf("\n");
        printf("Lb = ");
        ListTraverse_Sq(lb,PrintElem);
        printf("\n");
        printf("Lc = ");
        ListTraverse_Sq(lc,PrintElem);
        printf("\n");
        if(Algo_2_29(&la,lb,lc)==OK)
        {
            printf("Now La is:\n");
            ListTraverse_Sq(la,PrintElem);
            printf("\n");
        }
        else
            printf("ERROR!");
        return 0;
    }
    Status Algo_2_29(SqList *la,SqList lb,SqList lc)
    {
        int i,j,k,count;
        i=0;
        j=0;
        k=0;
        count = 0;
        while(i<(*la).length && j<lb.length && k<lc.length)
        {
            if(lb.elem[j]<lc.elem[k])
                j++;
            else if(lb.elem[j]>lc.elem[k])
                k++;
            else
            {
                while(i<(*la).length&&(*la).elem[i]<lb.elem[j])
                {
                    (*la).elem[count]=(*la).elem[i];
                    count++;
                    i++;
                }
                while(i<(*la).length&&(*la).elem[i]==lb.elem[j])
                    i++;
                if(i<(*la).length)
                {
                    j++;
                    k++;
                }
            }
        }
        while(i<(*la).length)
        {
            (*la).elem[count]=(*la).elem[i];
            count++;
            i++;
        }
        (*la).length = count;
        return OK;
    }
    void PrintElem(LElemType_Sq e)
    {
        printf("%d ",e);
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.30.c
    #include <stdio.h>
    #include "SingleLinkedList.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    void PrintElem(LElemType_L e);
    Status Algo_2_30(LinkList la,LinkList lb,LinkList lc);
    int main(void)
    {
        LinkList la,lb,lc;
        int i,j,k;
        InitList_L(&la);
        InitList_L(&lb);
        InitList_L(&lc);
        for(i=1;i<=30;i++)
            ListInsert_L(la,i,i);
        for(j=1;j<=15;j++)
            ListInsert_L(lb,j,2*j);
        for(k=1;k<=10;k++)
            ListInsert_L(lc,k,3*k);
        printf("La = ");
        ListTraverse_L(la,PrintElem);
        printf("\n");
        printf("Lb = ");
        ListTraverse_L(lb,PrintElem);
        printf("\n");
        printf("Lc = ");
        ListTraverse_L(lc,PrintElem);
        printf("\n");
        if(Algo_2_30(la,lb,lc)==OK)
        {
            printf("Now La is:\n");
            ListTraverse_L(la,PrintElem);
            printf("\n");
        }
        else
            printf("ERROR!");
        return 0;
    }
    Status Algo_2_30(LinkList la,LinkList lb,LinkList lc)
    {
        LinkList pa,pb,pc,pre;
        if(!la||!lb||!lc)
            return ERROR;
        pa = la->next;
        pb = lb->next;
        pc = lc->next;
        pre = la;

        while(pa && pb && pc)
        {
            if (pb->data<pc->data)
                pb = pb->next;
            else if(pb->data>pc->data)
                pc = pc->next;
            else
            {
                while(pa && pa->data<pb->data)
                {
                    pre = pa;
                    pa = pa->next;
                }
                while(pa && pa->data==pb->data)
                {
                    pre->next = pa->next;
                    free(pa);
                    pa = pre->next;
                }
                if(pa)
                {
                    pb = pb->next;
                    pc = pc->next;
                }
            }
        }
        return OK;
    }
    void PrintElem(LElemType_L e)
    {
        printf("%d ",e);
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.31.c
    #include <stdio.h>
    #include "SingleLinkedList.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    Status Algo_2_31(LinkList L,LinkList s);
    void InitList_2_31(LinkList *L);
    Status CreateList_2_31(LinkList *L,int n,LElemType_L Data[]);
    void Output_2_31(LinkList L);
    int main(void)
    {
        LinkList L,s;
        int a[10]={1,2,3,4,5,6,7,8,9,10};
        InitList_2_31(&L);
        CreateList_2_31(&L,10,a);
        printf("L = ");
        Output_2_31(L);
        printf("\n");
        s = L->next->next->next->next;
        printf("Delete the former element of %d.\n",s->data);
        Algo_2_31(L,s);
        printf("L = ");
        Output_2_31(L);
        printf("\n");
        return 0;
    }
    Status Algo_2_31(LinkList L,LinkList s)
    {
        LinkList r,p;
        if(s->next == s)
            return ERROR;
        r = s;
        while(r->next->next!=s)
            r = r->next;
        p = r->next;
        r->next = p->next;
        if(p==L)
            L = p->next;
        free(p);
        return OK;
    }
    void InitList_2_31(LinkList *L)
    {
        *L = NULL;
    }
    Status CreateList_2_31(LinkList *L,int n,LElemType_L Data[])
    {
        LinkList s,r;
        int i;
        if(*L)
            return ERROR;
        for(i=1;i<=n;i++)
        {
            s=(LinkList)malloc(sizeof(LNode));
            s->data = Data[i-1];
            if(!s)
                exit(OVERFLOW);
            if(i==1)
            {
                *L = s;
                s->next = *L;
                r = *L;
            }
            else
            {
                s->next = r->next;
                r->next = s;
                r = r->next;
            }
        }
        return OK;
    }
    void Output_2_31(LinkList L)
    {
        LinkList p;
        if(L)
        {
            printf("%2d ",L->data);
            p = L->next;
            while(p!=L)
            {
                printf("%2d ",p->data);
                p = p->next;
            }
        }
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.32.c
    #include <stdio.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    typedef int LElemType_L;
    typedef struct LNode
    {
        LElemType_L data;
        struct LNode* next;
        struct LNode* prior;
    }LNode;
    typedef LNode* LinkList;
    Status Algo_2_32(LinkList L);
    Status InitList_2_32(LinkList *L);
    Status CreateList_2_32(LinkList L,int n,LElemType_L Data[]);
    void Output_2_32(LinkList L);
    void OutputReserve_2_32(LinkList L);
    int main(void)
    {
        LinkList L;
        LElemType_L a[10] = {1,2,3,4,5,6,7,8,9,10};
        InitList_2_32(&L);
        CreateList_2_32(L,10,a);
        printf("L = ");
        Output_2_32(L);
        printf("\n");
        Algo_2_32(L);
        printf("L = ");
        OutputReserve_2_32(L);
        printf("\n");
        return 0;
    }
    Status Algo_2_32(LinkList L)
    {
        LinkList r;
        if(!L)
            return ERROR;
        for(r=L;r->next!=L;r=r->next)
            r->next->prior = r;
        L->prior = r;
        return OK;
    }
    Status InitList_2_32(LinkList *L)
    {
        *L = (LinkList)malloc(sizeof(LNode));
        if(!(*L))
            exit(OVERFLOW);
        (*L)->prior = NULL;
        (*L)->next = *L;
        return OK;
    }
    Status CreateList_2_32(LinkList L,int n,LElemType_L Data[])
    {
        LinkList s,r;
        int i;
        if(!L||L->next != L)
            return ERROR;
        for(i=1,r=L;i<=n;i++)
        {
            s = (LinkList)malloc(sizeof(LNode));
            if(!s)
                exit(OVERFLOW);
            s->data = Data[i-1];
            s->prior = NULL;
            s->next = r->next;
            r->next = s;
            r = r->next;
        }
        return OK;
    }
    void Output_2_32(LinkList L)
    {
        LinkList p;
        if(L)
        {
            p = L->next;
            while(p!=L)
            {
                printf("%2d ",p->data);
                p = p->next;
            }
        }
    }
    void OutputReserve_2_32(LinkList L)
    {
        LinkList p;
        if(L)
        {
            p = L->prior;
            while(p!=L)
            {
                printf("%2d ",p->data);
                p = p->prior;
            }
        }
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.33.c
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    typedef char LElemType_L;
    typedef struct LNode
    {
        LElemType_L data;
        struct LNode* next;
    }LNode;
    typedef LNode* LinkList;
    Status Algo_2_33(LinkList L,LinkList L_char,LinkList L_num,LinkList L_other);
    Status InitList_2_33(LinkList *L);
    Status CreateList_2_33(LinkList L,int n,LElemType_L Data[]);
    Status InitList_2_33_R(LinkList *L);
    void Output_2_33(LinkList L);
    void Output_2_33_R(LinkList L);
    int main(void)
    {
        LinkList L,L_char,L_num,L_other;
        LElemType_L *a = "as2af^%asd12$@2";
        InitList_2_33(&L);
        CreateList_2_33(L,15,a);
        printf("L = ");
        Output_2_33(L);
        printf("\n");
        printf("The result is:\n");
        InitList_2_33_R(&L_char);
        InitList_2_33_R(&L_num);
        InitList_2_33_R(&L_other);
        Algo_2_33(L,L_char,L_num,L_other);
        printf("L_char = ");
        Output_2_33_R(L_char);
        printf("\n");
        printf("L_num = ");
        Output_2_33_R(L_num);
        printf("\n");
        printf("L_other = ");
        Output_2_33_R(L_other);
        printf("\n");
        return 0;
    }
    Status Algo_2_33(LinkList L,LinkList L_char,LinkList L_num,LinkList L_other)
    {
        LinkList p,q,r,s,t;
        if(!L)
            return ERROR;
        p = L->next;
        q = L_char;
        r = L_num;
        s = L_other;
        while(p)
        {
            t = (LinkList)malloc(sizeof(LNode));
            if(!t)
                exit(OVERFLOW);
            t->data = p->data;
            if(isalpha(p->data))
            {
                t->next = q->next;
                q->next = t;
                q = q->next;
            }
            else if(isdigit(p->data))
            {
                t->next = r->next;
                r->next = t;
                r = r->next;
            }
            else
            {
                t->next = s->next;
                s->next = t;
                s = s->next;
            }
            p=p->next;
        }
        return OK;
    }
    Status InitList_2_33(LinkList *L)
    {
        *L = (LinkList)malloc(sizeof(LNode));
        if(!(*L))
            exit(OVERFLOW);
        (*L)->next = NULL;
        return OK;
    }
    Status CreateList_2_33(LinkList L,int n,LElemType_L Data[])
    {
        LinkList s,r;
        int i;
        if(!L||L->next)
            return ERROR;
        for(i=1,r=L;i<=n;i++)
        {
            s = (LinkList)malloc(sizeof(LNode));
            if(!s)
                exit(OVERFLOW);
            s->data = Data[i-1];
            s->next = r->next;
            r->next = s;
            r = r->next;
        }
        return OK;
    }
    Status InitList_2_33_R(LinkList *L)
    {
        *L = (LinkList)malloc(sizeof(LNode));
        if(!(*L))
            exit(OVERFLOW);
        (*L)->next = (*L);
        return OK;
    }
    void Output_2_33(LinkList L)
    {
        LinkList p;
        if(L)
        {
            p = L->next;
            while(p)
            {
                printf("%2c ",p->data);
                p = p->next;
            }
        }
    }
    void Output_2_33_R(LinkList L)
    {
        LinkList p;
        if(L)
        {
            p = L->next;
            while(p!=L)
            {
                printf("%2c ",p->data);
                p = p->next;
            }
        }
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.34.c
    #include <stdio.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    typedef char XElemType;
    typedef struct XorNode
    {
        XElemType data;
        struct XorNode *LRPtr;
    }XorNode;
    typedef XorNode *XorPointer;
    typedef struct
    {
        XorPointer Left;
        XorPointer Right;
    }XorLinkedList;
    typedef XorLinkedList* Xor;
    Status Algo_2_34(Xor L,int mark);
    XorPointer XorP(XorPointer p,XorPointer q);
    Status Init_XorL(Xor *L);
    Status Create_XorL(Xor L,int n,XElemType Data[]);
    int main(void)
    {
        Xor L;
        XElemType e;
        int n = 9;
        XElemType *data = "123456789";
        Init_XorL(&L);
        Create_XorL(L,n,data);
        printf("L = ");
        Algo_2_34(L,0);
        printf("\n");
        printf("L(in reverse sequence) = ");
        Algo_2_34(L,1);
        printf("\n");
        return 0;
    }
    XorPointer XorP(XorPointer p,XorPointer q)
    {
        unsigned x,y,z;
        x =(unsigned long)p;
        y =(unsigned long)q;

        z = x^y;
        return (XorPointer)z;
    }
    Status Init_XorL(Xor *L)
    {
        *L = (Xor)malloc(sizeof(XorLinkedList));
        if(!(*L))
            exit(OVERFLOW);
        (*L)->Left = NULL;
        (*L)->Right = NULL;
        return OK;
    }
    Status Create_XorL(Xor L,int n,XElemType Data[])
    {
        int i;
        XorPointer pre_l,pre_m,pre_r;
        pre_l = pre_m = NULL;
        for(i=1;i<=n;i++)
        {
            pre_r = (XorPointer)malloc(sizeof(XorNode));
            if(!pre_r)
                exit(OVERFLOW);
            pre_r->data = Data[i-1];
            if(i==1)
                L->Left = pre_r;
            if(pre_m)
                pre_m->LRPtr = XorP(pre_l,pre_r);
            L->Right = pre_r;
            pre_r->LRPtr = XorP(pre_m,NULL);
            pre_l = pre_m;
            pre_m = pre_r;
        }
        return OK;
    }
    Status Algo_2_34(Xor L,int mark)
    {
        XorPointer p_l,p_m,p_r;
        if(mark !=1 && mark != 0)
            return ERROR;
        if(!L && !L->Left)
            return ERROR;
        if(mark == 0)
        {
            p_l = NULL;
            p_m = L->Left;
            while(p_m)
            {
                printf("%c ",p_m->data);
                p_r = XorP(p_l,p_m->LRPtr);
                p_l = p_m;
                p_m = p_r;
            }
        }
        if(mark == 1)
        {
            p_m = L->Right;
            p_r = NULL;
            while(p_m)
            {
                printf("%c ",p_m->data);
                p_l = XorP(p_m->LRPtr,p_r);
                p_r = p_m;
                p_m = p_l;
            }
        }
        return OK;
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.35.c
    #include <stdio.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    typedef char XElemType;
    typedef struct XorNode
    {
        XElemType data;
        struct XorNode *LRPtr;
    }XorNode;
    typedef XorNode *XorPointer;
    typedef struct
    {
        XorPointer Left;
        XorPointer Right;
    }XorLinkedList;
    typedef XorLinkedList* Xor;
    Status Algo_2_35(Xor L,int i,XElemType e);
    Status Algo_2_34(Xor L,int mark);
    XorPointer XorP(XorPointer p,XorPointer q);
    Status Init_XorL(Xor *L);
    Status Create_XorL(Xor L,int n,XElemType Data[]);
    XorPointer GetElemPtr_Xor(Xor L,int i);
    int Length_Xor(Xor L);
    int main(void)
    {
        Xor L;
        XElemType e;
        int n = 9;
        XElemType *data = "123456789";
        Init_XorL(&L);
        Create_XorL(L,n,data);
        printf("L = ");
        Algo_2_34(L,0);
        Algo_2_35(L,5,'*');
        printf("\n");
        printf("L = ");
        Algo_2_34(L,0);
        printf("\n");
        return 0;
    }
    XorPointer XorP(XorPointer p,XorPointer q)
    {
        unsigned x,y,z;
        x =(unsigned long)p;
        y =(unsigned long)q;

        z = x^y;
        return (XorPointer)z;
    }
    Status Init_XorL(Xor *L)
    {
        *L = (Xor)malloc(sizeof(XorLinkedList));
        if(!(*L))
            exit(OVERFLOW);
        (*L)->Left = NULL;
        (*L)->Right = NULL;
        return OK;
    }
    Status Create_XorL(Xor L,int n,XElemType Data[])
    {
        int i;
        XorPointer pre_l,pre_m,pre_r;
        pre_l = pre_m = NULL;
        for(i=1;i<=n;i++)
        {
            pre_r = (XorPointer)malloc(sizeof(XorNode));
            if(!pre_r)
                exit(OVERFLOW);
            pre_r->data = Data[i-1];
            if(i==1)
                L->Left = pre_r;
            if(pre_m)
                pre_m->LRPtr = XorP(pre_l,pre_r);
            L->Right = pre_r;
            pre_r->LRPtr = XorP(pre_m,NULL);
            pre_l = pre_m;
            pre_m = pre_r;
        }
        return OK;
    }
    int Length_Xor(Xor L)
    {
        int count;
        XorPointer p,pre,psuc;
        if(!L)
            exit(OVERFLOW);
        count = 0;
        pre = NULL;
        p = L->Left;
        while(p)
        {
            count++;
            psuc = XorP(pre,p->LRPtr);
            pre = p;
            p = psuc;
        }
        return count;
    }
    XorPointer GetElemPtr_Xor(Xor L,int i)
    {
        int count;
        XorPointer pre,psuc,p;
        if(!L|| !L->Left)
            return ERROR;
        if(i<1)
            return ERROR;
        count = 1;
        pre = NULL;
        p = L->Left;
        while(count<i && p)
        {
            psuc = XorP(pre,p->LRPtr);
            pre = p;
            p = psuc;
            count++;
        }
        return p;
    }
    Status Algo_2_34(Xor L,int mark)
    {
        XorPointer p_l,p_m,p_r;
        if(mark !=1 && mark != 0)
            return ERROR;
        if(!L && !L->Left)
            return ERROR;
        if(mark == 0)
        {
            p_l = NULL;
            p_m = L->Left;
            while(p_m)
            {
                printf("%c ",p_m->data);
                p_r = XorP(p_l,p_m->LRPtr);
                p_l = p_m;
                p_m = p_r;
            }
        }
        if(mark == 1)
        {
            p_m = L->Right;
            p_r = NULL;
            while(p_m)
            {
                printf("%c ",p_m->data);
                p_l = XorP(p_m->LRPtr,p_r);
                p_r = p_m;
                p_m = p_l;
            }
        }
        return OK;
    }
    Status Algo_2_35(Xor L,int i,XElemType e)
    {
        XorPointer pre,cur,suc,pre_pre,s;
        if(!L)
            return ERROR;
        if(i<1 || i>Length_Xor(L)+1)
            return ERROR;
        s = (XorPointer)malloc(sizeof(XorNode));
        if(!s)
            return OVERFLOW;
        s->data = e;
        cur = GetElemPtr_Xor(L,i);
        pre = GetElemPtr_Xor(L,i-1);
        pre_pre = GetElemPtr_Xor(L,i-2);
        if(!cur)
        {
            if(!pre)
            {
                s->LRPtr = NULL;
                L->Left = s;
            }
            else
            {
                s->LRPtr = pre;
                pre->LRPtr = XorP(pre_pre,s);
            }
            L->Right = s;
        }
        else
        {
            suc = XorP(pre,cur->LRPtr);
            s->LRPtr = XorP(pre,cur);
            cur->LRPtr = XorP(s,suc);
            if(!pre)
                L->Left = s;
            else
                pre->LRPtr = XorP(pre_pre,s);
        }
        return OK;
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.36.c
    #include <stdio.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    typedef char XElemType;
    typedef struct XorNode
    {
        XElemType data;
        struct XorNode *LRPtr;
    }XorNode;
    typedef XorNode *XorPointer;
    typedef struct
    {
        XorPointer Left;
        XorPointer Right;
    }XorLinkedList;
    typedef XorLinkedList* Xor;
    Status Algo_2_36(Xor L,int i);
    Status Algo_2_34(Xor L,int mark);
    XorPointer XorP(XorPointer p,XorPointer q);
    Status Init_XorL(Xor *L);
    Status Create_XorL(Xor L,int n,XElemType Data[]);
    XorPointer GetElemPtr_Xor(Xor L,int i);
    int Length_Xor(Xor L);
    int main(void)
    {
        Xor L;
        XElemType e;
        int n = 9;
        XElemType *data = "123456789";
        Init_XorL(&L);
        Create_XorL(L,n,data);
        printf("L = ");
        Algo_2_34(L,0);
        Algo_2_36(L,5);
        printf("\n");
        printf("L = ");
        Algo_2_34(L,0);
        printf("\n");
        return 0;
    }
    XorPointer XorP(XorPointer p,XorPointer q)
    {
        unsigned x,y,z;
        x =(unsigned long)p;
        y =(unsigned long)q;

        z = x^y;
        return (XorPointer)z;
    }
    Status Init_XorL(Xor *L)
    {
        *L = (Xor)malloc(sizeof(XorLinkedList));
        if(!(*L))
            exit(OVERFLOW);
        (*L)->Left = NULL;
        (*L)->Right = NULL;
        return OK;
    }
    Status Create_XorL(Xor L,int n,XElemType Data[])
    {
        int i;
        XorPointer pre_l,pre_m,pre_r;
        pre_l = pre_m = NULL;
        for(i=1;i<=n;i++)
        {
            pre_r = (XorPointer)malloc(sizeof(XorNode));
            if(!pre_r)
                exit(OVERFLOW);
            pre_r->data = Data[i-1];
            if(i==1)
                L->Left = pre_r;
            if(pre_m)
                pre_m->LRPtr = XorP(pre_l,pre_r);
            L->Right = pre_r;
            pre_r->LRPtr = XorP(pre_m,NULL);
            pre_l = pre_m;
            pre_m = pre_r;
        }
        return OK;
    }
    int Length_Xor(Xor L)
    {
        int count;
        XorPointer p,pre,psuc;
        if(!L)
            exit(OVERFLOW);
        count = 0;
        pre = NULL;
        p = L->Left;
        while(p)
        {
            count++;
            psuc = XorP(pre,p->LRPtr);
            pre = p;
            p = psuc;
        }
        return count;
    }
    XorPointer GetElemPtr_Xor(Xor L,int i)
    {
        int count;
        XorPointer pre,psuc,p;
        if(!L|| !L->Left)
            return ERROR;
        if(i<1)
            return ERROR;
        count = 1;
        pre = NULL;
        p = L->Left;
        while(count<i && p)
        {
            psuc = XorP(pre,p->LRPtr);
            pre = p;
            p = psuc;
            count++;
        }
        return p;
    }
    Status Algo_2_34(Xor L,int mark)
    {
        XorPointer p_l,p_m,p_r;
        if(mark !=1 && mark != 0)
            return ERROR;
        if(!L && !L->Left)
            return ERROR;
        if(mark == 0)
        {
            p_l = NULL;
            p_m = L->Left;
            while(p_m)
            {
                printf("%c ",p_m->data);
                p_r = XorP(p_l,p_m->LRPtr);
                p_l = p_m;
                p_m = p_r;
            }
        }
        if(mark == 1)
        {
            p_m = L->Right;
            p_r = NULL;
            while(p_m)
            {
                printf("%c ",p_m->data);
                p_l = XorP(p_m->LRPtr,p_r);
                p_r = p_m;
                p_m = p_l;
            }
        }
        return OK;
    }
    Status Algo_2_36(Xor L,int i)
    {
        XorPointer pre_pre,pre,cur,suc,suc_suc;
        if(!L||!L->Left)
            return ERROR;
        if(i<1 || i>Length_Xor(L))
            return ERROR;
        cur = GetElemPtr_Xor(L,i);
        pre = GetElemPtr_Xor(L,i-1);
        suc = XorP(pre,cur->LRPtr);
        if(!suc)
        {
            L->Right = pre;
            if(!pre)
                L->Left = NULL;
            else
                pre->LRPtr = XorP(pre->LRPtr,cur);
        }
        else
        {
            if(!pre)
            {
                L->Left = suc;
                suc->LRPtr = XorP(cur,suc->LRPtr);
            }
            else
            {
                pre_pre = XorP(pre->LRPtr,cur);
                suc_suc = XorP(cur,suc->LRPtr);
                pre->LRPtr = XorP(pre_pre,suc);
                suc->LRPtr = XorP(pre,suc_suc);
            }
        }
        free(cur);
        cur = NULL;
        return OK;
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.37.c
    #include <stdio.h>
    #include "DualCycleLinkedList.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    Status Algo_2_37(DuLinkList L);
    void PriorElem(LElemType_DC e);
    int main(void)
    {
        DuLinkList L;
        int i;
        InitList_DuL(&L);
        for(i=1;i<=10;i++)
            ListInsert_DuL(L,i,i);
        ListTraverse_DuL(L,PriorElem);
        printf("\n");
        Algo_2_37(L);
        printf("\n");
        ListTraverse_DuL(L,PriorElem);
        printf("\n");
        return 0;
    }
    Status Algo_2_37(DuLinkList L)
    {
        DuLinkList p,head,tail;
        if(!L)
            return ERROR;
        head = L->next;
        tail = L->prior;
        while(head != tail)
        {
            if(head->next != tail)
            {
                p = head->next;
                p->next->prior = head;
                head->next = p->next;

                p->next = tail->next;
                p->prior = tail;
                tail->next->prior = p;
                tail->next = p;
            }
            else
                break;
        }
        return OK;
    }
    void PriorElem(LElemType_DC e)
    {
        printf("%d ",e);
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.38.c
    #include <stdio.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    typedef int LElemType_DC;
    typedef struct DuLNode
    {
        LElemType_DC data;
        struct DuLNode *prior;
        struct DuLNode *next;
        int freq;
    }DuLNode;
    typedef DuLNode* DuLinkList;

    DuLinkList Algo_2_38(DuLinkList *L,LElemType_DC e);
    Status CreateList_Dul_2_38(DuLinkList *L,int n,LElemType_DC Data[]);
    void Output_Dul_2_38(DuLinkList L);
    int main(void)
    {
        DuLinkList L,p;
        int i;
        LElemType_DC data[10] = {1,2,3,4,5,6,7,8,9,10};
        LElemType_DC temp[10] = {1,2,3,4,5,6,7,8,9,10};
        CreateList_Dul_2_38(&L,10,data);
        Output_Dul_2_38(L);
        printf("\n");
        for(i=0;i<10;i++)
            Algo_2_38(&L,temp[i]);
        Output_Dul_2_38(L);
        printf("\n");
        return 0;
    }
    Status CreateList_Dul_2_38(DuLinkList *L,int n,LElemType_DC Data[])
    {
        int i;
        DuLinkList s,h;
        *L =NULL;
        for(i=1;i<=n;i++)
        {
            s = (DuLinkList)malloc(sizeof(DuLNode));
            if(!s)
                exit(OVERFLOW);
            s->data = Data[i-1];
            s->freq = 0;
            if(*L == NULL)
            {
                *L = s;
                h = s;
                s->prior=s;
                s->next = s;
            }
            else
            {
                s->next = *L;
                s->prior = h;
                h->next = s;
                (*L)->prior = s;
                h = h->next;
            }
        }
        s = NULL;
        return OK;
    }
    void Output_Dul_2_38(DuLinkList L)
    {
        DuLinkList p = L;
        printf("L = ");
        for(p=L;p;p=p->next)
        {
            printf("%2d ",p->data);
            if(p->next == L)
                break;
        }
    }
    DuLinkList Algo_2_38(DuLinkList *L,LElemType_DC e)
    {
        DuLinkList p,pre;
        int i;
        if(!(*L))
            return NULL;
        for(p=*L;p;p = p->next)
        {
            if(p->data == e)
                break;
            if(p->next == p)
            {
                p =NULL;
                break;
            }
        }
        if(p!=NULL)
        {
            p->freq++;
            if(p!=*L)
            {
                for(pre=p->prior;pre->freq<p->freq;pre=pre->prior)
                {
                    if(pre == *L)
                    {
                        pre==NULL;
                        break;
                    }
                }
                p->next->prior = p->prior;
                p->prior->next = p->next;
                if(pre == NULL)
                {
                    p->prior = (*L)->prior;
                    p->prior->next = p;
                    p->next = *L;
                    (*L)->prior = p;
                    *L = p;
                }
                else
                {
                    p->prior = pre;
                    p->next = pre->next;
                    p->next->prior = p;
                    pre->next = p;
                }
            }
        }
        return p;
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.39.c
    #include <stdio.h>
    #include <math.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    typedef struct
    {
        int coef;
        int exp;
    }PolyTerm;
    typedef struct
    {
        PolyTerm *data;
        int last;
    }SqPoly;

    int Algo_2_39(SqPoly P,int x)
    {
        int i,sum;
        for(i=1,sum=0;i<P.last;i++)
            sum+=P.data[i].coef*(int)(pow(x,P.data[i].exp));
        return sum;
    }
    Status CreatPoly_Sq(SqPoly *P,int n,PolyTerm Data[])
    {
        int i;
        (*P).last = n;
        (*P).data = (PolyTerm*)malloc(sizeof(PolyTerm));
        if(!(*P).data)
            exit(OVERFLOW);
        for(int i=0;i<n;i++)
            (*P).data[i] = Data[i];
        return OK;
    }
    void OutputPoly_Sq(SqPoly P)
    {
        int i;
        for(i=0;i<P.last;i++)
        {
            if(i==0)
                printf("%d",P.data[i].coef);
            else
            {
                if(P.data[i].coef<0)
                {
                    printf(" - ");
                    printf("%d",-P.data[i].coef);
                }
                else
                {
                    printf(" + ");
                    printf("%d",P.data[i].coef);
                }
            }
            if(P.data[i].exp)
            {
                printf("x");
                if(P.data[i].exp!=1)
                    printf("^%d",P.data[i].exp);
            }
        }
    }
    int main(void)
    {
        SqPoly Pa;
        PolyTerm a[5]={{-2,1},{4,3},{11,5},{-7,7},{8,9}};
        CreatPoly_Sq(&Pa,5,a);
        printf("Pa = ");
        OutputPoly_Sq(Pa);
        printf("\n");
        printf("The value of pa is %d.\n",Algo_2_39(Pa,2));
        return 0;
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.40.c
    #include <stdio.h>
    #include <math.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    typedef struct
    {
        int coef;
        int exp;
    }PolyTerm;
    typedef struct
    {
        PolyTerm *data;
        int last;
    }SqPoly;

    Status Algo_2_40(SqPoly Pa,SqPoly Pb,SqPoly *Pc)
    {
        int i,j,k,sum;
        (*Pc).data = (PolyTerm*)malloc((Pa.last+Pb.last)*sizeof(PolyTerm));
        if(!(*Pc).data)
            exit(OVERFLOW);
        i = j = k = 0;
        while(i<Pa.last && j<Pb.last)
        {
            if(Pa.data[i].exp < Pb.data[j].exp)
            {
                (*Pc).data[k++]=Pa.data[i];
                i++;
            }
            else if(Pa.data[i].exp > Pb.data[j].exp)
            {
                (*Pc).data[k].coef=-Pb.data[j].coef;
                (*Pc).data[k].exp = Pb.data[j].exp;
                k++;
                j++;
            }
            else
            {
                sum = Pa.data[i].coef - Pb.data[j].coef;
                if(sum)
                {
                    (*Pc).data[k].coef = sum;
                    (*Pc).data[k].exp = Pa.data[i].exp;
                    k++;
                }
                i++;
                j++;
            }
        }
        while(i<Pa.last)
        {
            (*Pc).data[k++] = Pa.data[i];
            i++;
        }
        while(j<Pb.last)
        {
            (*Pc).data[k].coef = -Pb.data[j].coef;
            (*Pc).data[k].exp = Pb.data[j].exp;
            k++;
            j++;
        }
        (*Pc).last = k;
        return OK;
    }
    Status CreatPoly_Sq(SqPoly *P,int n,PolyTerm Data[])
    {
        int i;
        (*P).last = n;
        (*P).data = (PolyTerm*)malloc(sizeof(PolyTerm));
        if(!(*P).data)
            exit(OVERFLOW);
        for(int i=0;i<n;i++)
            (*P).data[i] = Data[i];
        return OK;
    }
    void OutputPoly_Sq(SqPoly P)
    {
        int i;
        for(i=0;i<P.last;i++)
        {
            if(i==0)
                printf("%d",P.data[i].coef);
            else
            {
                if(P.data[i].coef<0)
                {
                    printf(" - ");
                    printf("%d",-P.data[i].coef);
                }
                else
                {
                    printf(" + ");
                    printf("%d",P.data[i].coef);
                }
            }
            if(P.data[i].exp)
            {
                printf("x");
                if(P.data[i].exp!=1)
                    printf("^%d",P.data[i].exp);
            }
        }
    }
    int main(void)
    {
        SqPoly Pa,Pb,Pc;
        PolyTerm a[5]={{-2,1},{4,3},{11,5},{-7,7},{8,9}};
        PolyTerm b[5]={{-3,1},{3,3},{10,5},{-8,7},{7,9}};
        CreatPoly_Sq(&Pa,5,a);
        CreatPoly_Sq(&Pb,5,b);
        printf("Pa = ");
        OutputPoly_Sq(Pa);
        printf("\n");
        printf("Pb = ");
        OutputPoly_Sq(Pb);
        printf("\n");
        Algo_2_40(Pa,Pb,&Pc);
        printf("pa - pb is:\n");
        OutputPoly_Sq(Pc);
        printf("\n");
        return 0;
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.41.c
    #include <stdio.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    typedef struct
    {
        int coef;
        int exp;
    }PolyTerm;
    typedef struct PolyNode
    {
        PolyTerm data;
        struct PolyNode *next;
    }PolyNode;
    typedef PolyNode *PolyLink;
    typedef PolyLink LinkedPoly;

    Status Algo_2_41(LinkedPoly P);
    Status CreatPoly_L(LinkedPoly *P,int n,PolyTerm Data[]);
    Status OutputPoly_L(LinkedPoly P);
    int main(void)
    {
        LinkedPoly P1;
        PolyTerm a[7]={{-2,1},{4,2},{2,3},{11,5},{-7,6},{8,9},{-3,10}};
        CreatPoly_L(&P1,7,a);
        printf("Pn(x) = ");
        OutputPoly_L(P1);
        printf("\n");
        Algo_2_41(P1);
        printf("The derivative is :");
        OutputPoly_L(P1);
    }
    Status CreatPoly_L(LinkedPoly *P,int n,PolyTerm Data[])
    {
        int i;
        LinkedPoly s,r;
        *P= (LinkedPoly)malloc(sizeof(PolyNode));
        if(!(*P))
            exit(OVERFLOW);
        (*P)->next = (*P);
        for(i=1,r=*P;i<n;i++)
        {
            s = (LinkedPoly)malloc(sizeof(PolyNode));
            if(!s)
                exit(OVERFLOW);
            s->data = Data[i];
            s->next = r->next;
            r->next = s;
            r = r->next;
        }
        return OK;
    }
    Status OutputPoly_L(LinkedPoly P)
    {
        LinkedPoly r;
        int i;
        if(!P)
            return ERROR;
        for(r=P->next;r!=P;r=r->next)
        {
            if(r==P->next)
                printf("%d", r->data.coef);
            else
            {
                if(r->data.coef<0)
                {
                    printf(" - ");
                    printf("%d",-r->data.coef);
                }
                else
                {
                    printf(" + ");
                    printf("%d",r->data.coef);
                }
            }
            if(r->data.exp)
            {
                printf("x");
                if(r->data.exp!=1)
                    printf("^%d",r->data.exp);
            }
        }
        return OK;
    }
    Status Algo_2_41(LinkedPoly P)
    {
        LinkedPoly r,pre;
        if(!P)
            return ERROR;
        pre = P;
        r = P->next;
        while(r!=P)
        {
            if(r->data.exp)
            {
                r->data.coef *= r->data.exp;
                r->data.exp--;
                pre = r;
            }
            else
            {
                pre->next = r->next;
                free(r);
            }
            r = pre->next;
        }
        return OK;
    }
    {% endhighlight %}
---

    {% highlight ruby %}
	2.42.c
    #include <stdio.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    typedef struct
    {
        int coef;
        int exp;
    }PolyTerm;
    typedef struct PolyNode
    {
        PolyTerm data;
        struct PolyNode *next;
    }PolyNode;
    typedef PolyNode *PolyLink;
    typedef PolyLink LinkedPoly;

    Status Algo_2_42(LinkedPoly *P,LinkedPoly *P_odd,LinkedPoly *P_even);
    Status CreatPoly_L(LinkedPoly *P,int n,PolyTerm Data[]);
    Status OutputPoly_L(LinkedPoly P);
    int main(void)
    {
        LinkedPoly P,P_odd,P_even;
        PolyTerm a[7]={{-2,1},{4,2},{2,3},{11,5},{-7,6},{8,9},{-3,10}};
        CreatPoly_L(&P,7,a);
        printf("Pn(x) = ");
        OutputPoly_L(P);
        printf("\n");
        Algo_2_42(&P,&P_odd,&P_even);
        printf("The odd-polyomial is:");
        OutputPoly_L(P_odd);
        printf("\n");
        printf("The even-polyomail is:");
        OutputPoly_L(P_even);
        printf("\n");
        return 0;
    }
    Status CreatPoly_L(LinkedPoly *P,int n,PolyTerm Data[])
    {
        int i;
        LinkedPoly s,r;
        *P= (LinkedPoly)malloc(sizeof(PolyNode));
        if(!(*P))
            exit(OVERFLOW);
        (*P)->next = (*P);
        for(i=1,r=*P;i<n;i++)
        {
            s = (LinkedPoly)malloc(sizeof(PolyNode));
            if(!s)
                exit(OVERFLOW);
            s->data = Data[i];
            s->next = r->next;
            r->next = s;
            r = r->next;
        }
        return OK;
    }
    Status OutputPoly_L(LinkedPoly P)
    {
        LinkedPoly r;
        int i;
        if(!P)
            return ERROR;
        for(r=P->next;r!=P;r=r->next)
        {
            if(r==P->next)
                printf("%d", r->data.coef);
            else
            {
                if(r->data.coef<0)
                {
                    printf(" - ");
                    printf("%d",-r->data.coef);
                }
                else
                {
                    printf(" + ");
                    printf("%d",r->data.coef);
                }
            }
            if(r->data.exp)
            {
                printf("x");
                if(r->data.exp!=1)
                    printf("^%d",r->data.exp);
            }
        }
        return OK;
    }
    Status Algo_2_42(LinkedPoly *P,LinkedPoly *P_odd,LinkedPoly *P_even)
    {
        LinkedPoly r,s,p,q;
        *P_odd =(LinkedPoly)malloc(sizeof(PolyNode));
        *P_even =(LinkedPoly)malloc(sizeof(PolyNode));
        if(!(*P_odd)||!(*P_even))
            exit(OVERFLOW);
        (*P_odd)->next = *P_odd;
        (*P_even)->next = *P_even;
        if(!(*P))
            return ERROR;
        p = *P_odd;
        q = *P_even;
        r=(*P)->next;
        while(r!=(*P))
        {
            s = r;
            r = r->next;
            if(s->data.exp%2)
            {
                s->next = p->next;
                p->next = s;
                p=p->next;
            }
            else
            {
                s->next = q->next;
                q->next = s;
                q = q->next;
            }
        }
        free(*P);
        *P = NULL;
        return OK;
    }
    {% endhighlight %}
---

  If you find there are faults in the source codes, any method connecting with me is welcomed.
