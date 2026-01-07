#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;

typedef struct SListnode
{
    SLTDataType data;
    struct SListnode* next;
}SLnode;

void SLTPrint(SLnode* phead)
{
    assert(phead);
    SLnode* tmp = phead;
    while (tmp)
    {
        printf("%d->", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

SLnode* SLTBuyNode(SLTDataType x)
{
    SLnode* tmp = (SLnode*)malloc(sizeof(SLnode));
    if (tmp == NULL)
    {
        perror("malloc");
        return -1;
    }
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

void SLTPushBack(SLnode** phead, SLTDataType x)
{
    assert(phead);
    SLnode* newnode = SLTBuyNode(x);
    if (*phead == NULL)
    {
        *phead = newnode;
    }
    else
    {
        SLnode* tmp = *phead;
        while (tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = newnode;
    }
}

void SLTPushFront(SLnode** phead, SLTDataType x)
{
    assert(phead);
    SLnode* newnode = SLTBuyNode(x);
    newnode->next = *phead;
    *phead = newnode;
}

void SLTPopBack(SLnode** phead)
{
    assert(phead && *phead);
    if ((*phead)->next == NULL)
    {
        free(*phead);
    }
    else
    {
        SLnode* prev = NULL;
        SLnode* ptail = (*phead)->next;
        while (ptail->next)
        {
            prev = ptail;
            ptail = ptail->next;
        }
        free(ptail);
        prev->next = NULL;
    }
}

void SLTPopFront(SLnode** phead)
{
    assert(phead && *phead);
    SLnode* tmp = (*phead)->next;
    free(*phead);
    *phead = tmp;
}

//查找
SLnode* SLTFind(SLnode* phead, SLTDataType x)
{
    SLnode* tmp = phead;
    while (tmp)
    {
        if (tmp->data == x)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

//指定之前插
void SLTInsert(SLnode** phead, SLnode* pos, SLTDataType x)
{
    assert(phead && *phead);
    assert(pos);
    if (pos == *phead)
    {
        SLTPushFront(phead, x);
    }
    else
    {
        SLnode* prev = *phead;
        SLnode* newnode = SLTBuyNode(x);
        while (prev->next != pos)
        {
            prev = prev->next;
        }
        prev->next = newnode;
        newnode->next = pos;
    }
    
}

//指定之后插
void SLTInsertAfter(SLnode* pos, SLTDataType x)
{
    assert(pos);
    SLnode* newnode = SLTBuyNode(x);
    newnode->next = pos->next;
    pos->next = newnode;
}

//删除指定
void SLTErase(SLnode** phead, SLnode* pos)
{
    assert(phead && *phead);
    assert(pos);
    if ((*phead)->next == NULL)
    {
        SLTPopFront(phead);
    }
    else
    {
        SLnode* prev = (*phead)->next;
        while (prev->next != pos)
        {
            prev = prev->next;
        }
        prev->next = pos->next;
        free(pos);
        pos = NULL;
    }
}

void SLTEraseAfter(SLnode* pos)
{
    if (pos->next == NULL)
    {
        return;
    }
    SLnode* del = pos->next;
    pos->next = del->next;
    free(del);
    del = NULL;
}