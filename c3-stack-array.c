#include <stdio.h>
#define ERROR -1;//对应int，其他类型错误值在此定义
typedef int Position;
typedef struct SNode * PtrToSNode;
typedef int ElementType;
struct SNode{
    ElementType * Data;
    Position Top;
    int MaxSize;
};
typedef PtrToSNode Stack;

//创建
Stack CreateStack(int MaxSize){
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    S->MaxSize = MaxSize;
    S->Top = -1;
    return S;
}
//入栈
bool IsFull(Stack S){
    return (S->Top == S->MaxSize - 1);
}
bool Push(Stack S, ElementType X){
    if(IsFull(S)){
        printf("堆栈满");
        return false;
    }
    else{
        S->Data[++(S->Top)];
        return true;
    }
}
//出栈
bool IsEmpty(Stack S){
    return (S->Top == -1);
}
ElementType Pop(Stack S){
    if (IsEmpty(S)){
        printf("堆栈空");
        return ERROR;
    }
    else{
        return (S->Data[(S->Top--)]);
    }
}