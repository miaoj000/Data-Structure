//稀疏矩阵的十字链表
#include <stdio.h>
#define MAXSIZE 10

typedef enum{
    Head,
    Term
} NodeTag;
typedef int ElementType;

struct TermNode{
    int Row, Col;
    ElementType Value;
};

typedef struct MNode * PtrToMNode;
struct MNode{
    PtrToMNode Tag;
    union{
        PtrToMNode Next;
        struct TermNode Term;
    } URegion;
    
};
typedef PtrToMNode Matrix;
Matrix HeadNode[MAXSIZE];