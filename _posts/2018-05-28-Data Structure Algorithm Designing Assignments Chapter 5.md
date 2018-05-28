---
layout: post
title: Data Structure Algorithm Designing Assignments Chapter 5
description: "my own source codes of Algorithm Designing Assignment in Data Structure"
categories: [Data-Structure]
tags: [C]
redirect_from:
  - /2018/05/28/
---
# Data Structure Algorithm Designing Assignments Chapter 5

	
---

    {% highlight ruby %}
    5.18.c
    #include <stdio.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    Status Algo_5_18(int a[],int n,int k);
    Status Reversal_5_18(int a[],int n,int start,int end);
    int main(void)
    {
        int A[10]={1,2,3,4,5,6,7,8,9,10};
        int i;
        int k=5;
        printf("A: ");
        for(i=0;i<10;i++)
            printf("%2d ",A[i]);
        printf("\n");
        printf("k = %d,A: ",k);
        Algo_5_18(A,10,k);
        for(i=0;i<10;i++)
            printf("%2d ",A[i]);
        printf("\n");
        return 0;
    }

    Status Algo_5_18(int a[],int n,int k)
    {
        int p = k%n;
        if(p)
        {
            Reversal_5_18(a,n,1,n);
            Reversal_5_18(a,n,1,p);
            Reversal_5_18(a,n,p+1,n);
        }
        return OK;
    }
    Status Reversal_5_18(int a[],int n,int start,int end)
    {
        int e,i;
        if(start<1||end>n||start>end)
            return ERROR;
        for(i=0;i<(end-start+1)/2;++i)
        {
            e = a[end-i-1];
            a[end-i-1]=a[start+i-1];
            a[start+i-1]=e;
        }
        return OK;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	5.19.c
    #include <stdio.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    #define LEN 256

    typedef struct
    {
        int x;
        int y;
        int value;
    }Node;

    typedef Node SNode;

    Status Algo_5_19(int a[LEN][LEN],int row,int col,SNode p[LEN]);
    void Min_row(int a[LEN][LEN],int i,int col,Node min[LEN]);
    Status IsMax_col(int a[LEN][LEN],int row,Node v);
    int main(void)
    {
        SNode p[LEN];
        int row=4;
        int col=4;
        int a[LEN][LEN]={
                        {1,2,3,4},
                        {-1,-2,-3,-4},
                        {9,6,7,8},
                        {1,3,5,7}
                        };
        int i,j,k;
        printf("The matrix is:\n");
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
                printf("%3d ",a[i][j]);
            printf("\n");
        }
        printf("\n");
        if(Algo_5_19(a,row,col,p))
        {
            for(k=1;k<=p[0].value;k++)
                printf("row is %d, col is %d,value is %d",p[k].x,p[k].y,p[k].value);
        }
        else
            printf("There is none suitable point!\n");
        return 0;
    }

    Status Algo_5_19(int a[LEN][LEN],int row,int col,SNode p[LEN])
    {
        int i,k;
        Node min[LEN];
        p[0].value = 0;
        for(i=0;i<row;i++)
        {
            Min_row(a,col,i,min);
            for(k=1;k<=min[0].value;k++)
            {
                if(IsMax_col(a,row,min[k]))
                {
                    p[0].value++;
                    p[p[0].value] = min[k];
                }
            }
        }
        if(p[0].value)
            return TRUE;
        else
            return FALSE;
    }

    void Min_row(int a[LEN][LEN],int i,int col,Node min[LEN])
    {
        int j;
        min[0].value = 0;
        for(j=0;j<col;j++)
        {
            if(!j||a[i][j]==min[j-1].value)
                min[0].value++;
            else
            {
                if(a[i][j]<min[j-1].value)
                    min[0].value = 1;
                else
                    continue;
            }
            min[min[0].value].x = i;
            min[min[0].value].y = j;
            min[min[0].value].value = a[i][j];
        }
    }

    Status IsMax_col(int a[LEN][LEN],int row,Node v)
    {
        int i;
        for(i=0;i<row;i++)
        {
            if(a[i][v.y]>v.value)
                return FALSE;
        }
        return TRUE;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	5.20.c
    #include <stdio.h>

    void Algo_5_20(int a[][3][3],int m,int n,int l);

    int main(void)
    {
        int a[3][3][3]={-3,2,4,1,3,2,-5,1,3,
                        -1,3,2,5,5,6,-5,2,4,
                        2,3,5,4,3,1,-5,2,3};
        Algo_5_20(a,3,3,3);
        return 0;
    }

    void Algo_5_20(int a[][3][3],int m,int n,int l)
    {
        int i,j,k;
        for(i=m-1;i>=0;--i)
        {
            for(j=n-1;j>=0;--j)
            {
                for(k=l-1;k>=0;--k)
                {
                    if(a[i][j][k]!=0)
                    {
                        if(a[i][j][k]==1 && !i && !j && !k)
                            printf("1");
                        else
                        {
                            if(a[i][j][k]!=1)
                                printf("%d",a[i][j][k]);
                            if(i)
                                printf("xE%d",i);
                            if(j)
                                printf("yE%d",j);
                            if(k)
                                printf("zE%d",k);
                            if(!(!i && !j && !k))
                                printf(" + ");
                        }
                    }
                }
            }
        }
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	5.21.c
    #include <stdio.h>
    #include "TripleSparseMatrix.h"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    Status Algo_5_21(TSMatrix A,TSMatrix B,TSMatrix *C);

    int main(void)
    {
        return OK;
    }

    Status Algo_5_21(TSMatrix A,TSMatrix B,TSMatrix *C)
    {
        int m,n,k;
        if(B.mu!=A.mu||B.nu!=A.nu)
            return ERROR;
        C->mu = A.mu;
        C->nu = A.nu;
        C->tu = 0;
        m = n = k = 1;
        while(m<=A.tu && n<=B.tu)
        {
            if(A.data[m].i>B.data[n].j)
            {
                C->data[k] = A.data[m];
                m++;
            }
            else if(A.data[m].i<B.data[n].i)
            {
                C->data[k] = B.data[n];
                n++;
            }
            else
            {
                if(A.data[m].j>B.data[n].j)
                {
                    C->data[k] = A.data[m];
                    m++;
                }
                else if(A.data[m].j<B.data[n].j)
                {
                    C->data[k] = B.data[n];
                    n++;
                }
                else
                {
                    if(A.data[m].e+B.data[n].e)
                    {
                        C->data[k].i = A.data[m].i;
                        C->data[k].j = A.data[m].j;
                        C->data[k].e = A.data[m].e+B.data[n].e;
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
            C->tu++;
        }
        while(m<=A.tu)
        {
            C->data[k]=A.data[m];
            m++;
            n++;
            C->tu++;
        }
        while(n<=B.tu)
        {
            C->data[k]=B.data[n];
            n++;
            k++;
            C->tu++;
        }
        return OK;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	5.22.c
    #include <stdio.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    #include "TripleSparseMatrix.h"

    Status Algo_5_22(TSMatrix *A,TSMatrix B);

    int main(void)
    {
        return OK;
    }

    Status Algo_5_22(TSMatrix *A,TSMatrix B)
    {
        int m,n,k;
        if((*A).mu!=B.mu||(*A).nu!=B.nu)
            return ERROR;
        for(k=(*A).tu;k>0;k--)
            (*A).data[k+B.tu] = (*A).data[k];
        m = B.tu+1;
        n = 1;
        k = 0;
        while(m<=(*A).tu+B.tu && n<=B.tu)
        {
            if((*A).data[m].i<B.data[n].i)
                (*A).data[++k]= (*A).data[m++];
            else if((*A).data[m].i>B.data[n].i)
            (*A).data[++k] = B.data[n++];
            else
            {
                if((*A).data[m].j<B.data[n].j)
                    (*A).data[++k] = (*A).data[m++];
                else if((*A).data[m].j>B.data[n].j)
                    (*A).data[++k] = B.data[n++];
                else
                {
                    if((*A).data[m].e+B.data[n].e)
                    {
                        k++;
                        (*A).data[k].i = (*A).data[m].i;
                        (*A).data[k].j = (*A).data[m].j;
                        (*A).data[k].e = (*A).data[m].e+(*A).data[n].e;
                    }
                    m++;
                    n++;
                }
            }
        }
        while(m<=(*A).tu+B.tu)
            (*A).data[++k] = (*A).data[m++];
        while(n<=B.tu)
            (*A).data[++k] = B.data[n++];
        (*A).tu = k;
        return OK;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	5.24.c
    #include <stdio.h>
    #include <stdarg.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Scanf.c"
    #define MAXSIZE 400

    typedef struct
    {
        int seq;
        int e;
    }SElem;

    typedef struct
    {
        SElem data[MAXSIZE+1];
        int mu,nu,tu;
    }SMatrix;

    Status Algo_5_24(SMatrix M,int i,int j,int *e);
    Status CreateSMatrix_5_24(FILE *fp,int n,...);
    void PrintSMatrix_5_24(SMatrix M);

    int main(void)
    {
        SMatrix M;
        int e;
        FILE *fp;

        fp = fopen("Algo_5_24.txt","r");
        CreateSMatrix_5_24(fp,1,&M);
        fclose(fp);
        printf("M = \n");
        PrintSMatrix_5_24(M);
        printf("\n");
        Algo_5_24(M,1,1,&e);
        printf("The element in row %d col %d is %d",1,1,e);
        return 0;
    }

    Status Algo_5_24(SMatrix M,int i,int j,int *e)
    {
        int s,p;
        if(i<0||i>M.mu||j<0||j>M.nu)
            return ERROR;
        for(p=1,s=(i-1)*M.nu+j;M.data[p].seq<s;p++)
            ;
        *e = 0;
        if(M.data[p].seq==s)
            *e = M.data[p].e;
        return OK;
    }
    Status CreateSMatrix_5_24(FILE *fp,int n,...)
    {
        int count,k,i,j;
        SMatrix *M;
        if(n<1)
            return ERROR;
        va_list ap;
        va_start(ap,n);
        for(count=1;count<=n;count++)
        {
            M = va_arg(ap,SMatrix *);
            Scanf(fp,"%d%d%d",&((*M).mu),&((*M).nu),&((*M).tu));
            for(k=1;k<=(*M).tu;k++)
            {
                Scanf(fp,"%d%d%d",&i,&j,&((*M).data[k].e));
                (*M).data[k].seq = (i-1)*(*M).nu+j;
            }
        }
        va_end(ap);
        return OK;
    }
    void PrintSMatrix_5_24(SMatrix M)
    {
        int r,c;
        int k=1;
        for(r=1;r<=M.mu;r++)
        {
            for(c=1;c<=M.nu;c++)
            {
                if(r==(M.data[k].seq-1)/M.nu+1 && c==(M.data[k].seq-1)%M.nu+1)
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
    {% endhighlight %}
    
---

    {% highlight ruby %}
	5.25.c
    #include <stdarg.h>
    #include <stdio.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Scanf.c"

    #define MU 20
    #define NU 20
    #define MAXSIZE 400

    typedef struct
    {
        int mu,nu,tu;
        int V[MAXSIZE+1];
        int B[MU+1][NU+1];
    }Matrix;

    Status Algo_5_25(Matrix P,Matrix Q,Matrix *R);
    Status CreateMatrix_5_25(FILE *fp,int n,...);
    void PrintMatrix_5_25(Matrix M);

    int main(void)
    {
        Matrix M,N,Q;
        int i,j;
        FILE *fp;
        fp = fopen("Algo_5_25.txt","r");
        CreateMatrix_5_25(fp,2,&M,&N);
        fclose(fp);
        printf("M = \n");
        PrintMatrix_5_25(M);
        printf("N = \n");
        PrintMatrix_5_25(N);
        printf("\n");
        Algo_5_25(M,N,&Q);
        printf("M + N = \n");
        PrintMatrix_5_25(Q);
        printf("\n");
        return 0;
    }
    Status Algo_5_25(Matrix P,Matrix Q,Matrix *R)
    {
        int i,j;
        int p,q,r;
        if(P.mu!=Q.mu||P.nu!=Q.nu)
            return ERROR;
        (*R).mu = P.mu;
        (*R).nu = P.nu;
        (*R).tu = 0;
        p = q = r = 1;
        for(i=1;i<=P.mu;++i)
        {
            for(j=1;j<=P.nu;++j)
            {
                if(P.B[i][j]==0 && Q.B[i][j]==0)
                    (*R).B[i][j] = 0;
                else if(P.B[i][j]==0 && Q.B[i][j]==1)
                {
                    (*R).V[r++] = Q.V[q++];
                    (*R).B[i][j] = 1;
                    (*R).tu++;
                }
                else if(P.B[i][j]==1 && Q.B[i][j]==0)
                {
                    (*R).V[r++] = P.V[p++];
                    (*R).B[i][j] = 1;
                    (*R).tu++;
                }
                else
                {
                    if(P.V[p]+Q.V[q])
                    {
                        (*R).V[r++] = P.V[p++]+Q.V[q++];
                        (*R).B[i][j] = 1;
                        (*R).tu++;
                    }
                    else
                    {
                        p++;
                        q++;
                        (*R).B[i][j] = 0;
                    }
                }
            }
        }
        return OK;
    }

    Status CreateMatrix_5_25(FILE *fp,int n,...)
    {
        int count,k,i,j,r,c;
        Matrix *M;
        if(n<1)
            return ERROR;
        va_list ap;
        va_start(ap,n);
        for(count=1;count<=n;count++)
        {
            M = va_arg(ap,Matrix *);
            Scanf(fp,"%d%d%d",&((*M).mu),&((*M).nu),&((*M).tu));
            for(k=1,r=c=1;k<=(*M).tu;k++)
            {
                Scanf(fp,"%d%d%d",&i,&j,&((*M).V[k]));
                for(;r<i;r++)
                {
                    for(;c<=(*M).nu;c++)
                        (*M).B[r][c]==0;
                    c=1;
                }
                for(;c<j;c++)
                {
                    (*M).B[r][c]=0;
                }
                (*M).B[r][c]=1;
                if(++c==(*M).nu+1)
                {
                    c=1;
                    r++;
                }
            }
            for(;r<=(*M).mu;r++)
            {
                for(;c<=(*M).nu;c++)
                    (*M).B[r][c]=0;
                c = 1;
            }
        }
        va_end(ap);
        return OK;
    }

    void PrintMatrix_5_25(Matrix M)
    {
        int r,c;
        int k=1;
        for(r=1;r<=M.mu;r++)
        {
            for(c=1;c<=M.nu;c++)
            {
                if(M.B[r][c]==1)
                {
                    printf("%3d ",M.V[k]);
                    k++;
                }
                else
                    printf("  0 ");
            }
            printf("\n");
        }
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	5.26.c
    #include <stdio.h>
    #include "CrossList.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    Status Algo_5_26(CrossList M)
    {
        int i,j;
        OLNode *p;
        if(!M.tu)
            return ERROR;
        for(i=1;i<=M.mu;++i)
        {
            p = M.rhead[i];
            for(j=1;j<=M.nu;++j)
            {
                if(p&&p->j==j)
                {
                    printf("(%2d%2d%3d)\n",i,j,p->e);
                    p = p->right;
                }
            }
        }
        return OK;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	5.27.c
    #include <stdio.h>
    #include "CrossList.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    Status Algo_5_27(CrossList M,CrossList N,CrossList *Q)
    {
        if(AddSMatrix_OL(M,N,Q))
            return OK;
        else
            return ERROR;
    }
    {% endhighlight %}
    
---
    {% highlight ruby %}
	5.30.c
    #include <stdio.h>
    #include "GeneralizedList-H-T.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Chapter4\SequenceString.c"

    int Algo_5_30(GList L);

    int main(void)
    {
        GList L;
        char *s = "((()),a,((b,c),(),d),(((e))))"; //5.12(1)
        SString S;
        StrAssign_Sq(S,s);
        CreateGList_GL_H_T_1(&L,S);
        printf("L = ");
        Output_GL_H_T(L,Head);
        printf("\n");
        printf("The depth of generalized list is %d",Algo_5_30(L));
        return 0;
    }

    int Algo_5_30(GList L)
    {
        int m,n;
        if(!L)
            return 1;
        if(L->tag == Atom)
            return 0;
        m = Algo_5_30(L->Union.ptr.hp)+1;
        n = Algo_5_30(L->Union.ptr.tp);
        return m > n ? m : n;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	5.31.c
    #include <stdio.h>
    #include "GeneralizedList-H-T.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Chapter4\SequenceString.c"

    Status Algo_5_31(GList *T,GList L);

    int main(void)
    {
        GList L,T;
        char *s = "((()),a,((b,c),(),d),(((e))))"; //5.12(1)
        SString S;
        StrAssign_Sq(S,s);
        CreateGList_GL_H_T_1(&L,S);
        printf("L = ");
        Output_GL_H_T(L,Head);
        printf("\n");
        printf("Copy L to T.\n");
        Algo_5_31(&T,L);
        printf("T = ");
        Output_GL_H_T(T,Head);
        printf("\n");
        return 0;
    }

    Status Algo_5_31(GList *T,GList L)
    {
        if(!L)
            *T = NULL;
        else
        {
            *T = (GList)malloc(sizeof(GLNode));
            if(!T)
                exit(OVERFLOW);
            (*T)->tag = L->tag;
            if(L->tag == Atom)
                (*T)->Union.atom = L->Union.atom;
            else
            {
                Algo_5_31(&((*T)->Union.ptr.hp),L->Union.ptr.hp);
                Algo_5_31(&((*T)->Union.ptr.tp),L->Union.ptr.tp);
            }
        }
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	5.32.c
    #include <stdio.h>
    #include "GeneralizedList-H-T.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Chapter4\SequenceString.c"

    Status Algo_5_32(GList A,GList B);

    int main(void)
    {
        GList L,T;
        char *s = "((()),a,((b,c),(),d),(((e))))"; //5.12(1)
        SString S;
        StrAssign_Sq(S,s);
        CreateGList_GL_H_T_1(&L,S);
        CreateGList_GL_H_T_1(&T,S);
        printf("L = ");
        Output_GL_H_T(L,Head);
        printf("\n");
        printf("T = ");
        Output_GL_H_T(T,Head);
        printf("\n");
        Algo_5_32(L,T) ? printf("L = T!") : printf("L != T!");
        return 0;
    }

    Status Algo_5_32(GList A,GList B)
    {
        if(!A && !B)
            return OK;
        else if((!A && B)||(A && !B))
            return ERROR;
        else
        {
            if(A->tag==B->tag)
            {
                if(A->tag==Atom)
                {
                    if(A->Union.atom==B->Union.atom)
                        return OK;
                }
                else
                {
                    if(Algo_5_32(A->Union.ptr.hp,B->Union.ptr.hp))
                    {
                        if(Algo_5_32(A->Union.ptr.tp,B->Union.ptr.tp))
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
	5.33.c
    #include <stdio.h>
    #include "GeneralizedList-H-T.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Chapter4\SequenceString.c"

    Status Algo_5_33(GList A,int d);
    int main(void)
    {
        GList L;
        char *s = "((()),a,((b,c),(),d),(((e))))"; //5.12(1)
        SString S;
        StrAssign_Sq(S,s);
        CreateGList_GL_H_T_1(&L,S);
        printf("L = ");
        Output_GL_H_T(L,Head);
        printf("\n");
        Algo_5_33(L,Head);
        printf("\n");
        return 0;
    }

    Status Algo_5_33(GList A,int d)
    {
        int i = d;
        if(A)
        {
            if(A->tag == Atom)
                printf("%c -> Layer %d\n",A->Union.atom,i);
            if(A->tag == List)
            {
                Algo_5_33(A->Union.ptr.hp,i+1);
                Algo_5_33(A->Union.ptr.tp,i);
            }
        }
        return 0;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	5.34.c
    #include <stdio.h>
    #include "GeneralizedList-H-T.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Chapter4\SequenceString.c"

    void Algo_5_34(GList *L);

    int main(void)
    {
        GList L;
        char *s = "((()),a,((b,c),(),d),(((e))))"; //5.12(1)
        SString S;
        StrAssign_Sq(S,s);
        CreateGList_GL_H_T_1(&L,S);
        printf("L = ");
        Output_GL_H_T(L,Head);
        printf("\n");
        Algo_5_34(&L);
        printf("L = ");
        Output_GL_H_T(L,Head);
        printf("\n");
        return 0;
    }

    void Algo_5_34(GList *L)
    {
        GList head,tail;
        if(*L)
        {
            head = *L;
            tail = (*L)->Union.ptr.tp;
            if(head->Union.ptr.hp && head->Union.ptr.hp->tag==List)
                Algo_5_34(&(head->Union.ptr.hp));
            if(tail)
            {
                Algo_5_34(&((*L)->Union.ptr.tp));
                *L = (*L)->Union.ptr.hp;
                tail->Union.ptr.tp = head;
                head->Union.ptr.tp = NULL;
            }
        }
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	5.35.c
    #include <stdio.h>
    #include <stdlib.h>
    #include "GeneralizedList-H-T.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    Status Algo_5_35(FILE *fp,GList *L);
    Status Creat_5_35(FILE *fp,GList *L);

    int main(void)
    {
        GList L;
        FILE *fp;
        fp = fopen("Algo_5_35.txt","r");
        Algo_5_35(fp,&L);
        fclose(fp);
        printf("L = ");
        Output_GL_H_T(L,0);
        printf("\n");
        return 0;
    }

    Status Algo_5_35(FILE *fp,GList *L)
    {
        char ch;
        ch = getc(fp);
        if(ch=='(')
        {
            if(Creat_5_35(fp,L))
                return OK;
        }
        return ERROR;
    }

    Status Creat_5_35(FILE *fp,GList *L)
    {
        char ch;
        ch = getc(fp);
        if(ch==' ')
        {
            *L = NULL;
            if(getc(fp)!=')')
                return ERROR;
        }
        else
        {
            *L = (GList)malloc(sizeof(GLNode));
            if(!*L)
                exit(OVERFLOW);
            (*L)->tag = List;
            if(ch>='a' && ch<='z')
            {
                (*L)->Union.ptr.hp = (GList)malloc(sizeof(GLNode));
                (*L)->Union.ptr.hp->tag =Atom;
                (*L)->Union.ptr.hp->Union.atom=ch;
            }
            else if(ch == '(')
                Creat_5_35(fp,&((*L)->Union.ptr.hp));
            else
                return ERROR;
            ch = getc(fp);
            if(ch ==')')
                (*L)->Union.ptr.tp = NULL;
            else if(ch==',')
                Creat_5_35(fp,&((*L)->Union.ptr.tp));
            else
                return ERROR;
        }
        return OK;
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	5.36.c
    #include <stdio.h>
    #include "GeneralizedList-H-T.c"

    void Algo_5_36(GList L,Mark mark);

    int main(void)
    {
        GList L;
        char *s = "((()),a,((b,c),(),d),(((e))))"; //5.12(1)
        SString S;
        StrAssign_Sq(S,s);
        CreateGList_GL_H_T_1(&L,S);
        printf("\n");
        printf("L = ");
        Algo_5_36(L,0);
        return OK;
    }

    void Algo_5_36(GList L,Mark mark)
    {
        if(L)
        {
            if(L->tag==Atom)
                printf("%c ",L->Union.atom);
            else
            {
                Algo_5_36(L->Union.ptr.hp,Head);
                Algo_5_36(L->Union.ptr.tp,Tail);
            }
        }
        if(!L && mark == Head)
            printf("_ ");
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	5.37.c
    #include <stdio.h>
    #include "GeneralizedList-H-T.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Chapter4\SequenceString.c"

    Status Algo_5_37(GList *L,AtomType x);

    int main(void)
    {
        GList L;
        char *s = "((()),a,((b,c),(),d),(((e))))"; //5.12(1)
        SString S;
        StrAssign_Sq(S,s);
        CreateGList_GL_H_T_1(&L,S);
        printf("\n");
        printf("L = ");
        Algo_5_37(&L,'a');
        Output_GL_H_T(L,Head);
        return OK;
    }

    Status Algo_5_37(GList *L,AtomType x)
    {
        GList h,p;
        if(*L && (*L)->tag==List)
        {
            h = (*L)->Union.ptr.hp;
            if(h)
            {
                if(h->tag == List)
                {
                    Algo_5_37(&((*L)->Union.ptr.hp),x);
                    Algo_5_37(&((*L)->Union.ptr.tp),x);
                }
                else
                {
                    if(h->Union.atom==x)
                    {
                        p = *L;
                        *L = (*L)->Union.ptr.tp;
                        p->Union.ptr.hp = NULL;
                        ClearGList_GL_H_T(&p);
                        Algo_5_37(L,x);
                    }
                    else
                        Algo_5_37(&((*L)->Union.ptr.tp),x);
                }
            }
            else
            {
                if((*L)->Union.ptr.tp)
                    Algo_5_37(&((*L)->Union.ptr.tp),x);
            }
        }
    }
    {% endhighlight %}
    
---

    {% highlight ruby %}
	5.38.c
    #include <stdio.h>
    #include "GeneralizedList-H-T.c"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Chapter4\SequenceString.c"

    void Algo_5_38(GList L,int d,int l);

    int main(void)
    {
        GList L;
        char *s = "((()),a,((b,c),(),d),(((e))))"; //5.12(1)
        SString S;
        StrAssign_Sq(S,s);
        CreateGList_GL_H_T_1(&L,S);
        Output_GL_H_T(L,Head);
        printf("\n");
        printf("Layer 3 of L: ");
        Algo_5_38(L,0,3);
        return 0;
    }

    void Algo_5_38(GList L,int d,int l)
    {
        int i = d;
        if(L && l>=i)
        {
            if(L->tag == Atom)
            {
                if(l==i)
                    printf("%c ",L->Union.atom);
            }
            else
            {
                Algo_5_38(L->Union.ptr.hp,i+1,1);
                Algo_5_38(L->Union.ptr.tp,i,1);
            }
        }
    }
    {% endhighlight %}
    
---

If you find there are faults in the source codes, any method connecting with me is welcomed.
