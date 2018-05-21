---
layout: post
title: Data Structure Notes of Chapter 3
description: "my thoughts and notes when learning Data Structure"
categories: [Data-Structure]
tags: [C]
redirect_from:
  - /2018/05/22/
---
# Data Structure Notes of Chapter 3

This chapter mainly introduces the ADT of stack and queue. I'll put the source code of sequence stack, and the code of sequence queue is quite familiar with sequence stack, which can be implemented independently by the reader.

---

	{%highlight ruby%}
	SequenceStack.h
    #ifndef SEQUENCESTACK_H
    #define SEQUENCESTACK_H

    #include <stdio.h>
    #include <stdlib.h>
    #include "C:\coding\C\workspace\Data Structure-YanWeimin\Algorithm Designing Assignments\Status.h"

    #define STACK_INIT_SIZE 100
    #define STACKINCREMENT 10

    #if !defined MAZE_H  && !defined EXPRESSION_H   && !defined BINARYTREE_H && !defined CHILDSIBLINGTREE_H && !defined Question_8
    typedef int SElemType_Sq;
    #endif
    typedef struct
    {
        SElemType_Sq *base;
        SElemType_Sq *top;
        int stacksize;
    }SqStack;
    Status InitStack_Sq(SqStack *S);
    Status DestroyStack_Sq(SqStack *S);
    Status ClearStack_Sq(SqStack *S);
    Status StackEmpty_Sq(SqStack S);
    int StackLength_Sq(SqStack S);
    Status GetTop_Sq(SqStack S,SElemType_Sq *e);
    Status Push_Sq(SqStack *S,SElemType_Sq e);
    Status Pop_Sq(SqStack *S,SElemType_Sq *e);
    Status StackTraverse_Sq(SqStack S,void(Visit)(SElemType_Sq));

    #endif
	{%endhighlight%}

---

	{%highlight ruby%}
	SequenceStack.c
    #ifndef SEQUENCESTACK_C
    #define SEQUENCESTACK_C

    #include "SequenceStack.h"

    Status InitStack_Sq(SqStack *S)
    {
        (*S).base =(SElemType_Sq *)malloc(STACK_INIT_SIZE*sizeof(SElemType_Sq));
        if(!(*S).base)
            exit(OVERFLOW);

        (*S).top = (*S).base;
        (*S).stacksize = STACK_INIT_SIZE;
        return OK;
    }

    Status DestroyStack_Sq(SqStack *S)
    {
        free((*S).base);
        (*S).base = NULL;
        (*S).top = NULL;
        (*S).stacksize = 0;
        return OK;
    }

    Status ClearStack_Sq(SqStack *S)
    {
        (*S).top = (*S).base;
        return OK;
    }

    Status StackEmpty_Sq(SqStack S)
    {
        if(S.top ==S.base)
            return TRUE;
        else
            return FALSE;
    }

    int StackLength_Sq(SqStack S)
    {
        return S.top - S.base;
    }

    Status GetTop_Sq(SqStack S,SElemType_Sq *e)
    {
        if(S.top == S.base)
            return ERROR;
        *e = *(S.top - 1);
        return OK;
    }

    Status Push_Sq(SqStack *S,SElemType_Sq e)
    {
        if((*S).top-(*S).base>=(*S).stacksize)
        {
            (*S).base = (SElemType_Sq *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType_Sq));
            if(!(*S).base)
                exit(OVERFLOW);
            (*S).top = (*S).base+(*S).stacksize;
            (*S).stacksize += STACKINCREMENT;
        }
        *(S->top) = e;
        (S->top)++;

        return OK;
    }

    Status Pop_Sq(SqStack *S,SElemType_Sq *e)
    {
        if((*S).top == (*S).base)
            return ERROR;
        (*S).top--;
        *e=*((*S).top);
        return OK;
    }

    Status StackTraverse_Sq(SqStack S,void(Visit)(SElemType_Sq))
    {
        SElemType_Sq *p = S.base;

        while(p<S.top)
            Visit(*p++);
        return OK;
    }

    #endif
	{%endhighlight%}

---
  If you find there are faults in the source codes, any method connecting with me is welcomed.
