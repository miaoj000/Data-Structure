#include <stdio.h>
#define MAXSIZE 10
#define ERROR -1

//数据类型定义
typedef int ElementType;
typedef struct LNode * PtrToLNode;
struct LNode{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;//节点地址
typedef PtrToLNode List;
//求表长
int Length(List L){
    Position p;
    int cnt = 0;
    p = L;
    while(p){
        p = p->Next;
        cnt++;
    }
    return cnt;
}
//创建
List L;
//查找，按序号
ElementType FindKth(List L, int K){
    Position p;
    int cnt = 1;
    p = L;
    while (p && cnt < k){
        p = p->Next;
        cnt++;
    }
    if ((cnt == k) && p)
        return p->Data;
    else
        return ERROR;  
}
//查找，按值
Position Find(List L, ElementType X){
    Position p = L;
    while (p && p->Data != X)
        p = p->Next;
    return p;
}
//插入
// List Insert(List L, ElementType X, int i){
//     Position tmp, pre;
//     tmp = (Position)malloc(sizeof(struct LNode));
//     tmp->Data = X;
//     if(i == 1){
//         tmp->Next = L;
//         return tmp;
//     }
//     else{
//         int cnt = 1;
//         pre = L;
//         while(pre && cnt < i-1){
//             pre = pre->Next;
//             cnt++;
//         }
//         if(pre == NULL || cnt != i-1){
//             printf("位序错误");
//             free(tmp);
//             return NULL;
//         }
//         tmp->Next = pre->Next;
//         pre->Next = tmp;
//         return L;
//     }
// }

//带头结点版本
bool Insert(List L, ElementType X, int i){
    Position tmp, pre;
    int cnt = 0;
    pre = L;
    while(pre && cnt < i-1){
        pre = pre->Next;
        cnt++;
    }
    if(pre == NULL || cnt != i-1){
        printf("位序错误");
        return false;
    }
    tmp = (Position)malloc(sizeof(struct LNode));
    tmp->Data = X;
    tmp->Next = pre->Next;
    pre->Next = tmp;
    return true;
}
//删除
bool Delete(List L, int i){
    Position tmp, pre;
    int cnt = 0;
    pre = L;
    while (pre && cnt < i - 1){
        pre = pre->Next;
        cnt++;
    }
    if (pre == NULL || cnt != i - 1 || pre->Next == NULL){
        printf("位序错误");
        return false;
    }
    tmp = pre->Next;
    pre->Next = tmp->Next;
    free(tmp);
    return true;
}