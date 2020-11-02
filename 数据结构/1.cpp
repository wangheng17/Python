#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct  LNode
{
   ElemType data;
   struct LNode *next;
}LNode;
void CreatelistF(LNode *&L,ElemType a[],int n)
{
    LNode *s;
    L=(LNode *)malloc(sizeof(LNode));
    L->next=NULL;
    for(int i=0;i<n;i++)
    {
        s=(LNode *)malloc(sizeof(LNode));
        s->data=a[i];
        s->next=L->next;
        L->next=s;
    }
}
void CreatelistR(LNode *&L,ElemTYpe a[],int n)
{
    LNode *s,*r;
    L=(LNode *)malloc(sizeof(LNode));
    L->next=NULL;
    r=L;
    for(int i=0;i<n;i++)
    {
        s=(LNode *)malloc(sizeof(LNode));
        s->data=a[i];
        r->next=s;
        s=r;
    }
    r->next=NULL;
}
void Initlist(LNode *&L)
{
    L=(LNode *)malloc(sizeof(LNode));
    L->next=NULL;
}
void Destorylist(LNode *&L)
{
    LNode *pre=L,*p=p->next;
    while(p!=NULL)
    {
        free(pre);
        pre=p;
        p=p->next;
    }
    free(pre);
}
int Emptylist(LNode *&L)
{
    return(L->next==NULL);
}
int Listlength(LNode *&L)
{
    int n=0;
    LNode *p=L;
    while(p->next!=NULL)
    {
        n++;
        p=p->next;
    }
    return n; 
}
bool ListInsert(LNode *&L,int i,ElemType e)
{
    int j=0;
    LNode *p=L,*s;
    while(j<i-1&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else
    {
        s=(LNode *)malloc(sizeof(LNode));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return true;
    }   
}
bool Deletelist(LNode *&L,int i,ElemType e)
{
    int j=0;
    LNode *p=L,*q;
    while(j<i-1&&p!=NULL)
    {
        j++;
        p=p->next
    if(p=NULL)
        return false;
    else
    {
        q=p->next;
        if(q=NULL)
        return false;
        e=q->data;
        p->next=q->next;
        free(q);
        return true;
    }   
}
void Locatelist(LNode *&L,int i,ElemType e)
{
asdfghjkl;'现场v不那么，。/'
}




