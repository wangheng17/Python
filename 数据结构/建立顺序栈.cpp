#include <stdio.h>
#include <malloc.h>
typedef int  ElemType;
#define MaxSize 50
typedef struct sqstack
{
    ElemType data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack *&s)//��ʼ��˳��ջ
{
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
}
bool StackEmpty(SqStack *s)//�ж�˳����Ƿ�Ϊ��
{
    return(s->top==-1);
}
void DestroyStack(SqStack *&s)//�ͷ�˳���ռ�õ��ڴ�ռ�
{
    free(s);
} 
bool Push(SqStack *&s,ElemType e)//����Ԫ��
{   if (s->top==MaxSize-1) //ջ�����������ջ�����
        return false;
    s->top++; //ջ��ָ����1
    s->data[s->top]=e; //Ԫ��e����ջ��ָ�봦
    return true;
}
bool Pop(SqStack *&s,ElemType &e)//��ջ��Ԫ�ظ���e
{
    if (s->top==-1) //ջΪ�յ��������ջ�����
        return false;
    e=s->data[s->top]; //ȡջ��ָ��Ԫ�ص�Ԫ��
    s->top--; //ջ��ָ���1���´���ջʱ�����Ԫ�ػᱻ���ǣ��ʲ������
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
    InitStack(st);//��ʼ��˳��ջ
    printf("ջst�Ƿ�Ϊ��: %s\n",(StackEmpty(st)?"��":"�ǿ�"));
    Push(st,'a');
    Push(st,'b');
    Push(st,'c');
    printf("ջst�Ƿ�Ϊ��: %s\n",(StackEmpty(st)?"��":"�ǿ�"));
    printf("��ջ˳��: ");
    while(!StackEmpty(st))
    {   Pop(st,e);
        printf("%c ",e);
    }
     DestroyStack(st);
     return 0;
}



