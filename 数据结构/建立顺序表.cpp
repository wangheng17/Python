#include <stdio.h>
#include <malloc.h>
#define Maxsize 50
typedef char ElemType;
typedef struct 
{
    ElemType data[Maxsize];
    int length;
}SqList;
void CreateList(SqList *&L,ElemType a[],int n) //整体建立顺序表
{
    L=(SqList *)malloc(sizeof(SqList));
    for(int i=0;i<n;i++)
        L->data[i]=a[i];
    L->length=n;
}
void InitList(SqList *&L) //初始化线性表
{
    L=(SqList *)malloc(sizeof(SqList));
    L->length=0;
}
void DestroyList(SqList *&L) //销毁线性表
{
    free(L);
}
bool ListInsert(SqList *&L,int i,ElemType e) //插入新元素
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
void DispList(SqList *L) //输出线性表
{
    for(int i=0;i<L->length;i++)
        printf("%c ",L->data[i]);
    printf("\n");
}
int ListLength(SqList *L) //输出顺序表的长度
{
    return(L->length);
}
bool ListEmpty(SqList *L) //判断顺序表是否为空表
{
    return(L->length==0);
}
void GetElem(SqList *L,int i,ElemType e) //输出顺序表中第三个元素
{
    e=L->data[i-1];
    printf("第三个元素为%c",L->data[i-1]);
}
int  LocateElem(SqList *L,ElemType e) //输出元素a的位置
{
    int i=0;
    while(i<L->length)
    {
        if(L->data[i]==e)
            return i+1;
        i++;
    }
}
void ListDelete(SqList *&L,int i,ElemType &e) //删除第三个元素
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
    printf("顺序表的基本运算如下：");
    printf(" (1)初始化顺序表L\n");
    InitList(L);
    printf(" (2)依次插入a,b,c,d,e元素\n");
    ListInsert(L,1,'a');
    ListInsert(L,2,'b');
    ListInsert(L,3,'c');
    ListInsert(L,4,'d');
    ListInsert(L,5,'e');
    printf(" (3)输出顺序表L：");
    DispList(L);
    printf(" (4)顺序表长度：%d\n",ListLength(L));
    printf(" (5)顺序表L为%s\n",(ListEmpty(L)?"空":"非空"));
    GetElem(L,3,'e');
    printf(" (6)顺序表L的第三个元素：%c\n",e);
    printf(" (7)元素a的位置：%d\n",LocateElem(L,'a'));
    printf(" (8)在第四个元素位置上插入f元素\n");
    ListInsert(L,4,'f');
    printf(" (9)输出顺序表L：");
    DispList(L);
    printf(" (10)删除L的第三个元素\n");
    ListDelete(L,3,e);
    printf(" (11)输出顺序表L：");
    DispList(L);
    printf(" (12)释放顺序表L\n");
    DestroyList(L);
    return 0;
}
