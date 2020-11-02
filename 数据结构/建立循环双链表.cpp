#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct DNode		//����˫����������
{
	ElemType data;
	struct DNode *prior;	//ָ��ǰ�����
	struct DNode *next;		//ָ���̽��
} DLinkNode;
void CreateListF(DLinkNode *&L,ElemType a[],int n) //ͷ�巨����ѭ��˫����
{
	DLinkNode *s;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  	//����ͷ���
	L->next=NULL;
	for (int i=0;i<n;i++)
	{	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));//�����½��
		s->data=a[i];
		s->next=L->next;			//�����s����ԭ��ʼ���֮ǰ,ͷ���֮��
		if (L->next!=NULL) L->next->prior=s;
		L->next=s;s->prior=L;
	}
	s=L->next;	
	while (s->next!=NULL)			//����β���,��sָ����
		s=s->next;
	s->next=L;						//β���next��ָ��ͷ���
	L->prior=s;						//ͷ����prior��ָ��β���

}
void CreateListR(DLinkNode *&L,ElemType a[],int n) //β�巨����ѭ��˫����
{
	DLinkNode *s,*r;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  //����ͷ���
	L->next=NULL;
	r=L;					//rʼ��ָ��β���,��ʼʱָ��ͷ���
	for (int i=0;i<n;i++)
	{	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));//�����½��
		s->data=a[i];
		r->next=s;s->prior=r;	//�����s������r֮��
		r=s;
	}
	r->next=L;				//β���next��ָ��ͷ���
	L->prior=r;				//ͷ����prior��ָ��β���
}
void InitList(DLinkNode *&L)	//��ʼ�����Ա�
{
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  	//����ͷ���
	L->prior=L->next=L;
}
void DestroyList(DLinkNode *&L)	//�������Ա�
{
	DLinkNode *pre=L,*p=pre->next;
	while (p!=L)
	{
		free(pre);
		pre=p;			//pre��pͬ������һ�����
		p=pre->next;
	}
	free(pre);			//��ʱp=L,preָ��β���,�ͷ���
}
bool ListEmpty(DLinkNode *L)	//�����Ա��Ƿ�Ϊ�ձ�
{
	return(L->next==L);
}
bool ListInsert(DLinkNode *&L,int i,ElemType e)	//�����i��Ԫ��
{
	int j=1;
	DLinkNode *p=L,*s;
	if (i<=0) return false;				//i���󷵻ؼ�
	if (p->next==L)						//ԭ˫����Ϊ�ձ�ʱ
	{	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));	//�����½��s
		s->data=e;
		p->next=s;s->next=p;
		p->prior=s;s->prior=p;
		return true;
	}
	else if (i==1)						//L��Ϊ�գ�i=1��Ϊ�����������
	{
		s=(DLinkNode *)malloc(sizeof(DLinkNode));	//�����½��s
		s->data=e;
		s->next=p->next;p->next=s;		//�����s���뵽���p֮��
		s->next->prior=s;s->prior=p;
		return true;
	}
	else								//i��Ϊ1ʱ
	{	
		p=L->next;
		while (j<=i-2 && p!=L)			//���ҵ�i-1�����p
		{	j++;
			p=p->next;
		}
		if (p==L)						//δ�ҵ���i-1�����
			return false;
		else							//�ҵ���i-1�����*p
		{
			s=(DLinkNode *)malloc(sizeof(DLinkNode));	//�����½��s
			s->data=e;	
			s->next=p->next;			//�����s���뵽���p֮��
			if (p->next!=NULL) p->next->prior=s;
			s->prior=p;
			p->next=s;
			return true;
		}
	}
}
void DispList(DLinkNode *L)	//������Ա�
{
	DLinkNode *p=L->next;
	while (p!=L)
	{
		printf("%c ",p->data);
		p=p->next;
	}
	printf("\n");
}
int ListLength(DLinkNode *L)		//�����Ա�ĳ���
{
	DLinkNode *p=L;int i=0;		//pָ��ͷ���,n��Ϊ0(��ͷ�������Ϊ0)
	while (p->next!=L)
	{
		i++;
		p=p->next;
	}
	return(i);					//ѭ������,pָ��β���,�����nΪ������
}
bool GetElem(DLinkNode *L,int i,ElemType &e)	//�����Ա��е�i��Ԫ��ֵ
{
	int j=1;
	DLinkNode *p=L->next;
	if (i<=0 || L->next==L) 
		return false;			//i�������LΪ�ձ��ؼ�
	if (i==1)					//i=1��Ϊ�����������
	{
		e=L->next->data;
		return true;
	}
	else						//i��Ϊ1ʱ
	{
		while (j<=i-1 && p!=L)	//���ҵ�i�����p
		{
			j++;
			p=p->next;
		}
		if (p==L)				//û���ҵ���i���ڣ����ؼ�
			return false;
		else					//�ҵ��˵�i���ڣ�������
		{
			e=p->data;
			return true;
		}
	}
}
int LocateElem(DLinkNode *L,ElemType e)  //���ҵ�һ��ֵ��Ϊe��Ԫ�����
{
	DLinkNode *p=L->next;
	int i=1;
	while (p!=L && p->data!=e)	//���ҵ�һ��ֵ��Ϊe�Ľ��p
	{
		p=p->next;
		i++;					//i��Ӧ���p�����
	}
	if (p==L)
		return(0);				//û���ҵ�����0
	else
		return(i);				//�ҵ��˷��������
}
bool ListDelete(DLinkNode *&L,int i,ElemType &e) //ɾ����i��Ԫ��
{
	int j=1;
	DLinkNode *p=L,*q;
	if (i<=0 || L->next==L) 
		return false;				//i�������Ϊ�ձ��ؼ�
	if (i==1)						//i==1��Ϊ�����������
	{
		q=L->next;					//ɾ����1�����
		e=q->data;
		L->next=q->next;
		q->next->prior=L;
		free(q);
		return true;
	}
	else							//i��Ϊ1ʱ
	{	
		p=L->next;
		while (j<=i-2 && p!=NULL)	//���ҵ���i-1�����p	
		{
			j++;
			p=p->next;
		}
		if (p==NULL)				//δ�ҵ���i-1�����
			return false;
		else						//�ҵ���i-1�����p
		{
			q=p->next;				//qָ��Ҫɾ���Ľ��
			if (q==NULL) return 0;	//�����ڵ�i�����
			e=q->data;
			p->next=q->next;		//�ӵ�������ɾ��q���
			if (p->next!=NULL) p->next->prior=p;
			free(q);				//�ͷ�q���
			return true;
		}
	}
}
int main()
{
	DLinkNode *h;
	ElemType e;
	printf("ѭ��˫����Ļ�����������:\n");
	printf("  (1)��ʼ��ѭ��˫����h\n");
	InitList(h);
	printf("  (2)���β���β�巨����a,b,c,d,eԪ��\n");
	ListInsert(h,1,'a');
	ListInsert(h,2,'b');
	ListInsert(h,3,'c');
	ListInsert(h,4,'d');
	ListInsert(h,5,'e');
	printf("  (3)���ѭ��˫����h:");
	DispList(h);
	printf("  (4)ѭ��˫����h����:%d\n",ListLength(h));
	printf("  (5)ѭ��˫����hΪ%s\n",(ListEmpty(h)?"��":"�ǿ�"));
	GetElem(h,3,e);
	printf("  (6)ѭ��˫����h�ĵ�3��Ԫ��:%c\n",e);
	printf("  (7)Ԫ��a��λ��:%d\n",LocateElem(h,'a'));
	printf("  (8)�ڵ�4��Ԫ��λ���ϲ���fԪ��\n");
	ListInsert(h,4,'f');
	printf("  (9)���ѭ��˫����h:");
	DispList(h);
	printf("  (10)ɾ��h�ĵ�3��Ԫ��\n");
    	ListDelete(h,3,e);
	printf("  (11)���ѭ��˫����h:");
	DispList(h);
	printf("  (12)�ͷ�ѭ��˫����h\n");
	DestroyList(h);
	return 1;
}
