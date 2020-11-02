#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct Linknode //声明单链栈结点类型
{   ElemType data;
    struct Linknode *next; //指向后继结点
}LinkStNode;
void InitStack(LinkStNode *&s)//初始化单链栈
{
    s=(LinkStNode *)malloc(sizeof(LinkStNode)); //创建头结点
    s->next=NULL;
}
void DestroyStack(LinkStNode *&s)//销毁单链栈
{
    LinkStNode *p=s,*q=s->next; //p指向q的前驱结点
    while(q!=NULL)//扫描单链表L
    {   free(p); //释放p结点
        p=q;//p、q同步后移一个结点
        q=p->next;
    }
    free(p); //循环结束时，q为NULL，p指向尾结点，释放p
}
bool StackEmpty(LinkStNode *s)//判断单链栈是否为空栈
{
    return(s->next==NULL);
}
void Push(LinkStNode *&s,ElemType e)//元素进栈
{   LinkStNode *p;
    p=(LinkStNode *)malloc(sizeof(LinkStNode));
    p->data=e; //新建元素e对应的结点p
    p->next=s->next; //插入p结点作为开始结点
    s->next=p;
}
bool Pop(LinkStNode *&s,ElemType &e)//元素出栈
{   LinkStNode *p;
    if (s->next==NULL) //栈空的情况
    return false;
    p=s->next;//p指向开始结点
    e=p->data;
    s->next=p->next;//删除p结点，链栈不同于顺序栈，出栈结点一定要删除并释放
    free(p);//释放p结点
    return true;
}
int main()
{   ElemType e;
    LinkStNode *st;
    InitStack(st);//初始化顺序栈
    printf("栈st是否为空: %s\n",(StackEmpty(st)?"空":"非空"));
    Push(st,'a');
    Push(st,'b');
    Push(st,'c');
    printf("栈st是否为空: %s\n",(StackEmpty(st)?"空":"非空"));
    printf("出栈顺序: ");
    while(!StackEmpty(st))
    {   Pop(st,e);
        printf("%c ",e);
    }
     DestroyStack(st);
     return 0;
}




