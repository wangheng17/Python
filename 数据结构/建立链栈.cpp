#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct Linknode //��������ջ�������
{   ElemType data;
    struct Linknode *next; //ָ���̽��
}LinkStNode;
void InitStack(LinkStNode *&s)//��ʼ������ջ
{
    s=(LinkStNode *)malloc(sizeof(LinkStNode)); //����ͷ���
    s->next=NULL;
}
void DestroyStack(LinkStNode *&s)//���ٵ���ջ
{
    LinkStNode *p=s,*q=s->next; //pָ��q��ǰ�����
    while(q!=NULL)//ɨ�赥����L
    {   free(p); //�ͷ�p���
        p=q;//p��qͬ������һ�����
        q=p->next;
    }
    free(p); //ѭ������ʱ��qΪNULL��pָ��β��㣬�ͷ�p
}
bool StackEmpty(LinkStNode *s)//�жϵ���ջ�Ƿ�Ϊ��ջ
{
    return(s->next==NULL);
}
void Push(LinkStNode *&s,ElemType e)//Ԫ�ؽ�ջ
{   LinkStNode *p;
    p=(LinkStNode *)malloc(sizeof(LinkStNode));
    p->data=e; //�½�Ԫ��e��Ӧ�Ľ��p
    p->next=s->next; //����p�����Ϊ��ʼ���
    s->next=p;
}
bool Pop(LinkStNode *&s,ElemType &e)//Ԫ�س�ջ
{   LinkStNode *p;
    if (s->next==NULL) //ջ�յ����
    return false;
    p=s->next;//pָ��ʼ���
    e=p->data;
    s->next=p->next;//ɾ��p��㣬��ջ��ͬ��˳��ջ����ջ���һ��Ҫɾ�����ͷ�
    free(p);//�ͷ�p���
    return true;
}
int main()
{   ElemType e;
    LinkStNode *st;
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




