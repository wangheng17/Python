#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct DNode
{
	ElemType data;
	struct DNode *prior;	//指向前驱结点
	struct DNode *next;		//指向后继结点
} DLinkNode;				//声明双链表结点类型
void CreateListF(DLinkNode *&L,ElemType a[],int n) //头插法建双链表
{
	DLinkNode *s;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  	//创建头结点
	L->prior=L->next=NULL;
	for (int i=0;i<n;i++)
	{	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));//创建新结点
		s->data=a[i];
		s->next=L->next;			//将结点s插在原开始结点之前,头结点之后
		if (L->next!=NULL) L->next->prior=s;
		L->next=s;s->prior=L;
	}
}
void CreateListR(DLinkNode *&L,ElemType a[],int n) //尾插法建双链表
{
	DLinkNode *s,*r;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  	//创建头结点
	L->prior=L->next=NULL;
	r=L;					//r始终指向终端结点,开始时指向头结点
	for (int i=0;i<n;i++)
	{	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));//创建新结点
		s->data=a[i];
		r->next=s;s->prior=r;	//将结点s插入结点r之后
		r=s;
	}
	r->next=NULL;				//尾结点next域置为NULL
}
void InitList(DLinkNode *&L)	//初始化线性表
{
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  	//创建头结点
	L->prior=L->next=NULL;
}
void DestroyList(DLinkNode *&L)	//销毁线性表
{
	DLinkNode *pre=L,*p=pre->next;
	while (p!=NULL)
	{
		free(pre);
		pre=p;					//pre、p同步后移一个结点
		p=pre->next;
	}
	free(p);
}
bool ListEmpty(DLinkNode *L)	//判线性表是否为空表
{
	return(L->next==NULL);
}

void DispList(DLinkNode *L) //输出单链表
{
    DLinkNode *p=L->next;
    while(p!=NULL)
    {
        printf("%c ",p->data);
        p=p->next;
    }
    printf("\n");
}
int ListLength(DLinkNode *L) //输出单链表的长度
{
    int n=0;
    DLinkNode *p=L;
    while(p->next!=NULL)
    {
        n++;
        p=p->next;
    }
    return(n);
}
bool GetElem(DLinkNode *L,int i,ElemType &e) //输出第三个元素
{
    int j=0;
    DLinkNode  *p=L;
    while(j<i &&p!=NULL)
    {
        j++;
        p=p->next;
    }
}
int LocateElem(DLinkNode *L,ElemType e) //找到元素a的位置
{
    int i=1;
    DLinkNode *p=L->next;
    while(p!=NULL&&p->data!=e)
    {
        p=p->next;
        i++;
    }
    if(p==NULL)
        return(0);
    else
        return(i);
}
bool ListInsert(DLinkNode *&L,int i,ElemType e) //插入元素
{   int j=0;
    DLinkNode *p=L,*s; //p指向头结点，j设置为0
    while (j<i-1 && p!=NULL) //查找第i-1个结点
    {   j++;
        p=p->next;
    }
    if (p==NULL) //未找到第i-1个结点，返回false
        return false;
    else //找到第i-1个结点p，在其后插入新结点s
    {
        s=(DLinkNode *)malloc(sizeof(DLinkNode));
        s->data=e; //创建新结点s
        s->next=p->next; //在p之后插入s结点
        if (p->next!=NULL) //若存在后继结点，修改其前驱指针
        p->next->prior=s;
        s->prior=p;
        p->next=s;
        return true;
    }
}
bool ListDelete(DLinkNode *&L,int i,ElemType &e) //删除某个元素
{   int j=0;
    DLinkNode *p=L,*q; //p指向头结点，j设置为0
    while (j<i-1 && p!=NULL) //查找第i-1个结点
    {   j++;
        p=p->next;
    }
    if (p==NULL) //未找到第i-1个结点
        return false;
    else //找到第i-1个结点p
    {   q=p->next; //q指向第i个结点
        if (q==NULL) //当不存在第i个结点时返回false
            return false;
        e=q->data;
        p->next=q->next; //从双单链表中删除q结点
        if (q->next!=NULL) //若q结点存在后继结点
        q->next->prior=p;//修改q结点后继结点的前驱指针
        free(q); //释放q结点
        return true;
    }
}
int main()
{
	DLinkNode *h;
	ElemType e;
	printf("双链表的基本运算如下:\n");
	printf("  (1)初始化双链表h\n");
	InitList(h);
	printf("  (2)依次采用尾插法插入a,b,c,d,e元素\n");
	ListInsert(h,1,'a');
	ListInsert(h,2,'b');
	ListInsert(h,3,'c');
	ListInsert(h,4,'d');
	ListInsert(h,5,'e');
	printf("  (3)输出双链表h:");
	DispList(h);
	printf("  (4)双链表h长度:%d\n",ListLength(h));
	printf("  (5)双链表h为%s\n",(ListEmpty(h)?"空":"非空"));
	GetElem(h,3,e);
	printf("  (6)双链表h的第3个元素:%c\n",e);
	printf("  (7)元素a的位置:%d\n",LocateElem(h,'a'));
	printf("  (8)在第4个元素位置上插入f元素\n");
	ListInsert(h,4,'f');
	printf("  (9)输出双链表h:");
	DispList(h);
	printf("  (10)删除h的第3个元素\n");
	ListDelete(h,3,e);
	printf("  (11)输出双链表h:");
	DispList(h);
	printf("  (12)释放双链表h\n");
	DestroyList(h);
	return 1;
}


