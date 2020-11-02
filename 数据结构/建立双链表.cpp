#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct DNode
{
	ElemType data;
	struct DNode *prior;	//ָ��ǰ�����
	struct DNode *next;		//ָ���̽��
} DLinkNode;				//����˫����������
void CreateListF(DLinkNode *&L,ElemType a[],int n) //ͷ�巨��˫����
{
	DLinkNode *s;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  	//����ͷ���
	L->prior=L->next=NULL;
	for (int i=0;i<n;i++)
	{	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));//�����½��
		s->data=a[i];
		s->next=L->next;			//�����s����ԭ��ʼ���֮ǰ,ͷ���֮��
		if (L->next!=NULL) L->next->prior=s;
		L->next=s;s->prior=L;
	}
}
void CreateListR(DLinkNode *&L,ElemType a[],int n) //β�巨��˫����
{
	DLinkNode *s,*r;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  	//����ͷ���
	L->prior=L->next=NULL;
	r=L;					//rʼ��ָ���ն˽��,��ʼʱָ��ͷ���
	for (int i=0;i<n;i++)
	{	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));//�����½��
		s->data=a[i];
		r->next=s;s->prior=r;	//�����s������r֮��
		r=s;
	}
	r->next=NULL;				//β���next����ΪNULL
}
void InitList(DLinkNode *&L)	//��ʼ�����Ա�
{
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  	//����ͷ���
	L->prior=L->next=NULL;
}
void DestroyList(DLinkNode *&L)	//�������Ա�
{
	DLinkNode *pre=L,*p=pre->next;
	while (p!=NULL)
	{
		free(pre);
		pre=p;					//pre��pͬ������һ�����
		p=pre->next;
	}
	free(p);
}
bool ListEmpty(DLinkNode *L)	//�����Ա��Ƿ�Ϊ�ձ�
{
	return(L->next==NULL);
}

void DispList(DLinkNode *L) //���������
{
    DLinkNode *p=L->next;
    while(p!=NULL)
    {
        printf("%c ",p->data);
        p=p->next;
    }
    printf("\n");
}
int ListLength(DLinkNode *L) //���������ĳ���
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
bool GetElem(DLinkNode *L,int i,ElemType &e) //���������Ԫ��
{
    int j=0;
    DLinkNode  *p=L;
    while(j<i &&p!=NULL)
    {
        j++;
        p=p->next;
    }
}
int LocateElem(DLinkNode *L,ElemType e) //�ҵ�Ԫ��a��λ��
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
bool ListInsert(DLinkNode *&L,int i,ElemType e) //����Ԫ��
{   int j=0;
    DLinkNode *p=L,*s; //pָ��ͷ��㣬j����Ϊ0
    while (j<i-1 && p!=NULL) //���ҵ�i-1�����
    {   j++;
        p=p->next;
    }
    if (p==NULL) //δ�ҵ���i-1����㣬����false
        return false;
    else //�ҵ���i-1�����p�����������½��s
    {
        s=(DLinkNode *)malloc(sizeof(DLinkNode));
        s->data=e; //�����½��s
        s->next=p->next; //��p֮�����s���
        if (p->next!=NULL) //�����ں�̽�㣬�޸���ǰ��ָ��
        p->next->prior=s;
        s->prior=p;
        p->next=s;
        return true;
    }
}
bool ListDelete(DLinkNode *&L,int i,ElemType &e) //ɾ��ĳ��Ԫ��
{   int j=0;
    DLinkNode *p=L,*q; //pָ��ͷ��㣬j����Ϊ0
    while (j<i-1 && p!=NULL) //���ҵ�i-1�����
    {   j++;
        p=p->next;
    }
    if (p==NULL) //δ�ҵ���i-1�����
        return false;
    else //�ҵ���i-1�����p
    {   q=p->next; //qָ���i�����
        if (q==NULL) //�������ڵ�i�����ʱ����false
            return false;
        e=q->data;
        p->next=q->next; //��˫��������ɾ��q���
        if (q->next!=NULL) //��q�����ں�̽��
        q->next->prior=p;//�޸�q����̽���ǰ��ָ��
        free(q); //�ͷ�q���
        return true;
    }
}
int main()
{
	DLinkNode *h;
	ElemType e;
	printf("˫����Ļ�����������:\n");
	printf("  (1)��ʼ��˫����h\n");
	InitList(h);
	printf("  (2)���β���β�巨����a,b,c,d,eԪ��\n");
	ListInsert(h,1,'a');
	ListInsert(h,2,'b');
	ListInsert(h,3,'c');
	ListInsert(h,4,'d');
	ListInsert(h,5,'e');
	printf("  (3)���˫����h:");
	DispList(h);
	printf("  (4)˫����h����:%d\n",ListLength(h));
	printf("  (5)˫����hΪ%s\n",(ListEmpty(h)?"��":"�ǿ�"));
	GetElem(h,3,e);
	printf("  (6)˫����h�ĵ�3��Ԫ��:%c\n",e);
	printf("  (7)Ԫ��a��λ��:%d\n",LocateElem(h,'a'));
	printf("  (8)�ڵ�4��Ԫ��λ���ϲ���fԪ��\n");
	ListInsert(h,4,'f');
	printf("  (9)���˫����h:");
	DispList(h);
	printf("  (10)ɾ��h�ĵ�3��Ԫ��\n");
	ListDelete(h,3,e);
	printf("  (11)���˫����h:");
	DispList(h);
	printf("  (12)�ͷ�˫����h\n");
	DestroyList(h);
	return 1;
}


