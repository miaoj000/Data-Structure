#include<stdio.h>
#define MAXSIZE 10
#define ERROR -1

//数据类型定义
typedef int ElementType;
typedef int Position;//顺序表，下标
typedef struct LNode * PtrToLNode;
struct LNode{
    ElementType Data[MAXSIZE];
    Position Last;
};
typedef PtrToLNode List;
//创建
List MakeEmpty(){
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}
//查找
Position Find(List L, ElementType X){
    Position i = 0;
    while (i <= L->Last && L->Data[i] != X)
        i++;
    if(i>L->Last)
        return ERROR;
    else
        return i;
}
//插入
bool Insert(List L, ElementType X, int i){
    Position j;
    if(L->Last == MAXSIZE){
        printf("表满");
        return false;
    }
    if(i < 1 || i>L->Last + 2){
        printf("位序错误");
        return false;
    }
    for(j = L->Last; j >= 1; j--)
        L->Data[j+1] = L->Data[j]; 
    L->Data[i-1] = X;
    L->Last++;
    return true;
}
//删除
bool Delete(List L, int i){
    Position j;
    if (i < 1 || i > L->Last + 1){
        printf("位序不存在");
        return false;
    }
    for (j = i; j <= L->Last; j++)
        L->Data[j - 1] = L->Data[j];
    L->Last--;
    return true;
}