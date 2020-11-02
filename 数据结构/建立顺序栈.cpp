#include <stdio.h>
#include <malloc.h>
typedef int  ElemType;
#define MaxSize 50
typedef struct sqstack
{
    ElemType data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack *&s)//初始化顺序栈
{
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
}
bool StackEmpty(SqStack *s)//判断顺序表是否为空
{
    return(s->top==-1);
}
void DestroyStack(SqStack *&s)//释放顺序表占用的内存空间
{
    free(s);
} 
bool Push(SqStack *&s,ElemType e)//插入元素
{   if (s->top==MaxSize-1) //栈满的情况，即栈上溢出
        return false;
    s->top++; //栈顶指针增1
    s->data[s->top]=e; //元素e放在栈顶指针处
    return true;
}
bool Pop(SqStack *&s,ElemType &e)//将栈顶元素赋给e
{
    if (s->top==-1) //栈为空的情况，即栈下溢出
        return false;
    e=s->data[s->top]; //取栈顶指针元素的元素
    s->top--; //栈顶指针减1，下次入栈时，这个元素会被覆盖，故不予理会
    return true;
}
void DispStack(SqStack *s)
{
    while(s->top!=-1)
    {
        printf("%d ",s->data[s->top]);
        s->top--;
    }
    printf("\n");
}
int main()
{   ElemType e;
    SqStack *st;
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



