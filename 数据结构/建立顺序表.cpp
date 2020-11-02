#include <stdio.h>
#include <malloc.h>
#define Maxsize 50
typedef char ElemType;
typedef struct 
{
    ElemType data[Maxsize];
    int length;
}SqList;
void CreateList(SqList *&L,ElemType a[],int n) //���彨��˳���
{
    L=(SqList *)malloc(sizeof(SqList));
    for(int i=0;i<n;i++)
        L->data[i]=a[i];
    L->length=n;
}
void InitList(SqList *&L) //��ʼ�����Ա�
{
    L=(SqList *)malloc(sizeof(SqList));
    L->length=0;
}
void DestroyList(SqList *&L) //�������Ա�
{
    free(L);
}
bool ListInsert(SqList *&L,int i,ElemType e) //������Ԫ��
{
    int j;
    if(i<1||i>L->length+1||i==Maxsize)
        return false;
    i--;
    for(j=L->length;j>i;j--)
        L->data[j]=L->data[j-1];
    L->data[i]=e;
    L->length++;
    return true;
}
void DispList(SqList *L) //������Ա�
{
    for(int i=0;i<L->length;i++)
        printf("%c ",L->data[i]);
    printf("\n");
}
int ListLength(SqList *L) //���˳���ĳ���
{
    return(L->length);
}
bool ListEmpty(SqList *L) //�ж�˳����Ƿ�Ϊ�ձ�
{
    return(L->length==0);
}
void GetElem(SqList *L,int i,ElemType e) //���˳����е�����Ԫ��
{
    e=L->data[i-1];
    printf("������Ԫ��Ϊ%c",L->data[i-1]);
}
int  LocateElem(SqList *L,ElemType e) //���Ԫ��a��λ��
{
    int i=0;
    while(i<L->length)
    {
        if(L->data[i]==e)
            return i+1;
        i++;
    }
}
void ListDelete(SqList *&L,int i,ElemType &e) //ɾ��������Ԫ��
{
    int j;
    i--;
    e=L->data[i];
    for(j=i;j<L->length-1;j++)
        L->data[j]=L->data[j+1];
    L->length--;
}
int main()
{
    SqList *L;
    ElemType e;
    printf("˳���Ļ����������£�");
    printf(" (1)��ʼ��˳���L\n");
    InitList(L);
    printf(" (2)���β���a,b,c,d,eԪ��\n");
    ListInsert(L,1,'a');
    ListInsert(L,2,'b');
    ListInsert(L,3,'c');
    ListInsert(L,4,'d');
    ListInsert(L,5,'e');
    printf(" (3)���˳���L��");
    DispList(L);
    printf(" (4)˳����ȣ�%d\n",ListLength(L));
    printf(" (5)˳���LΪ%s\n",(ListEmpty(L)?"��":"�ǿ�"));
    GetElem(L,3,'e');
    printf(" (6)˳���L�ĵ�����Ԫ�أ�%c\n",e);
    printf(" (7)Ԫ��a��λ�ã�%d\n",LocateElem(L,'a'));
    printf(" (8)�ڵ��ĸ�Ԫ��λ���ϲ���fԪ��\n");
    ListInsert(L,4,'f');
    printf(" (9)���˳���L��");
    DispList(L);
    printf(" (10)ɾ��L�ĵ�����Ԫ��\n");
    ListDelete(L,3,e);
    printf(" (11)���˳���L��");
    DispList(L);
    printf(" (12)�ͷ�˳���L\n");
    DestroyList(L);
    return 0;
}
