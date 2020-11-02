#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct LNode 
{
	ElemType data;
	struct LNode *next;		//ָ���̽��
} LinkNode;		 			//������������
void CreateListF(LinkNode *&L,ElemType a[],int n)//ͷ�巨����������
{
	LinkNode *s;
	L=(LinkNode *)malloc(sizeof(LinkNode));  //����ͷ���
	L->next=NULL;
	for (int i=0;i<n;i++)
	{	
		s=(LinkNode *)malloc(sizeof(LinkNode));//�����½��s
		s->data=a[i];
		s->next=L->next;			//�����s����ԭ��ʼ���֮ǰ,ͷ���֮��
		L->next=s;
	}
}

void CreateListR(LinkNode *&L,ElemType a[],int n)//β�巨����������
{
	LinkNode *s,*r;
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//����ͷ���
	L->next=NULL;
	r=L;						//rʼ��ָ��β���,��ʼʱָ��ͷ���
	for (int i=0;i<n;i++)
	{	
		s=(LinkNode *)malloc(sizeof(LinkNode));//�����½��s
		s->data=a[i];
		r->next=s;				//�����s����r���֮��
		r=s;
	}
	r->next=NULL;				//β���next����ΪNULL
}

void InitList(LinkNode *&L)		//��ʼ�����Ա�
{
	L=(LinkNode *)malloc(sizeof(LinkNode));  //����ͷ���
	L->next=NULL;				//��������Ϊ�ձ�
}

void DestroyList(LinkNode *&L)	//�������Ա�
{
	LinkNode *pre=L,*p=pre->next;
	while (p!=NULL)
	{	free(pre);
		pre=p;					//pre��pͬ������һ�����					
		p=pre->next;
	}
	free(pre);					//��ʱpΪNULL,preָ��β���,�ͷ���
}
bool ListEmpty(LinkNode *L)		//�����Ա��Ƿ�Ϊ�ձ�
{
	return(L->next==NULL);
}

int ListLength(LinkNode *L) //���������ĳ���
{
    int n=0;
    LinkNode *p=L;
    while(p->next!=NULL)
    {
        n++;
        p=p->next;
    }
    return(n);
}
void DispList(LinkNode *L) //���������
{
    LinkNode *p=L->next;
    while(p!=NULL)
    {
        printf("%c ",p->data);
        p=p->next;
    }
    printf("\n");
}

bool GetElem(LinkNode *L,int i,ElemType &e) //���������Ԫ��
{
    int j=0;
    LinkNode  *p=L;
    while(j<i &&p!=NULL)
    {
        j++;
        p=p->next;
    }
}
int LocateElem(LinkNode *L,ElemType e) //�ҵ�Ԫ��a��λ��
{
    int i=1;
    LinkNode *p=L->next;
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
bool ListInsert(LinkNode *&L,int i,ElemType e) //��ĳ��λ�ò���Ԫ��
{   int j=0;
    LinkNode *p=L,*s; //pָ��ͷ��㣬j��Ϊ0
    while (j<i-1 && p!=NULL)
    {    j++;
        p=p->next;
    }
    if(p==NULL) //δ�ҵ���i-1����㣬����false
    return false;
    else //�ҵ���i-1�����p�������½�㲢����true
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=e; //�����½��s����data����Ϊe
        s->next=p->next; //��s���뵽p֮��
        p->next=s;
        return true;
    }
}
bool ListDelete(LinkNode *&L,int i,ElemType &e) //ɾ��ĳ��Ԫ��
{   int j=0;
    LinkNode *p=L,*q; //pָ��ͷ��㣬j��Ϊ0
    while (j<i-1 && p!=NULL) //���ҵ�i-1�����
    {   j++;
        p=p->next;
    }
    if (p==NULL) //δ�ҵ���i-1����㣬����false
        return false;
    else //�ҵ���i-1�����p
    {   q=p->next; //qָ���i�����
        if (q==NULL) //�������ڵ�i����㣬����false
            return false;
        e=q->data;
        p->next=q->next; //�ӵ�������ɾ��q���
        free(q); //�ͷ�q���
         return true; //����true��ʾ�ɹ�ɾ����i�����
    }
}
int main()
{
	LinkNode *h;
	ElemType e;
	printf("������Ļ�����������:\n");
	printf("  (1)��ʼ��������h\n");
	InitList(h);
	printf("  (2)���β���β�巨����a,b,c,d,eԪ��\n");
	ListInsert(h,1,'a');
	ListInsert(h,2,'b');
	ListInsert(h,3,'c');
	ListInsert(h,4,'d');
	ListInsert(h,5,'e');
	printf("  (3)���������h:");
	DispList(h);
	printf("  (4)������h����:%d\n",ListLength(h));
	printf("  (5)������hΪ%s\n",(ListEmpty(h)?"��":"�ǿ�"));
	GetElem(h,3,e);
	printf("  (6)������h�ĵ�3��Ԫ��:%c\n",e);
	printf("  (7)Ԫ��a��λ��:%d\n",LocateElem(h,'a'));
	printf("  (8)�ڵ�4��Ԫ��λ���ϲ���fԪ��\n");
	ListInsert(h,4,'f');
	printf("  (9)���������h:");
	DispList(h);
	printf("  (10)ɾ��h�ĵ�3��Ԫ��\n");
    ListDelete(h,3,e);
	printf("  (11)���������h:");
	DispList(h);
	printf("  (12)�ͷŵ�����h\n");
	DestroyList(h);
	return 0;
}

