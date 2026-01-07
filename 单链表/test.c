#include"SList.h"
int main()
{
    SLnode* n1 = NULL;

    SLTPushBack(&n1, 1);
    SLTPushBack(&n1, 2);
    SLTPushBack(&n1, 3);
    SLTPushBack(&n1, 4);
    SLTPushBack(&n1, 5);

    SLTPrint(n1);
    SLTPopBack(&n1);
    SLTPrint(n1);
    SLTPopFront(&n1);
    SLTPrint(n1);

    SLnode* find = SLTFind(n1, 3);
    SLTInsert(&n1, find, 11);
    SLTPrint(n1);
    SLTInsertAfter(find, 12);
    SLTPrint(n1);
    SLTEraseAfter(find);
    SLTPrint(n1);
    SLTErase(&n1, find);
    SLTPrint(n1);
    return 0;
}