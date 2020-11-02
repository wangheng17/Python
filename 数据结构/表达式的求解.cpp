#include <stdio.h>
#include <stdlib.h>
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
bool GetTop(SqStack *s,ElemType &e)
{
 if(s->top==-1)
 return false;
 e=s->data[s->top];
 return true;
} 
void trans(char *exp,char postexp[])
{
    int e;
    SqStack *Optr;//���������ջ��˳��ջ��ָ��
    InitStack(Optr);//��ʼ�������ջ
    int i=0;//i��Ϊpostexp���±�
    while(*exp!='\0')//exp���ʽδɨ����ʱѭ��
    {
        switch(*exp)//����Ԫ�����ͣ�ִ����Ӧ����
        {
            case '('://�ж�Ϊ�����ţ��������ջ������ɨ�������ַ�
                Push(Optr,'('); //�����Ž�ջ
                exp++;//����ɨ�������ַ�
                break;
            case ')'://�ж�Ϊ�����ţ����������ջ���η���postexp�ַ�������
                Pop(Optr,e); //��ջ�������������������Ԫ��e
                while(e!='(' )//��Ϊ��(��ʱѭ����ֱ�����ġ�(��������������������
                {
                    postexp[i++]=e; //�����������e��ŵ�postexp�У�
                    Pop(Optr,e);//������ջ�������������������Ԫ��e
                }
                exp++;//����ɨ�������ַ�
                break;
            case '+'://Ϊ�ӻ����ʱ��ջ������������postexp��ֱ��ջ�ջ���ջ��Ϊ��(��ʱ����
            case '-':
                while(!StackEmpty(Optr))//ջ��ʱ�˳�ѭ��
                {
                    GetTop(Optr,e);//ȡջ��Ԫ�أ������������������e
                    if(e!='(')//e����'('
                    {
                        postexp[i++]=e;//��(�������e��ŵ�postexp��
                        Pop(Optr,e);//��ջԪ�أ������������������ e
                    }
                    else break;//����������ʱ���˳�ѭ��
                }
                Push(Optr,*exp);//��'+'��'-'��ջ
                exp++; //����ɨ�������ַ�
                break;
            case '*'://�ж�Ϊ��*����/���ţ�ջ��*��/�����ȫ������postexp
            case '/':
                while(!StackEmpty(Optr))//ջ����ѭ��
                {
                    GetTop(Optr,e); //ȡջ��Ԫ��e
                    if(e=='*'||e=='/')//eΪ'*'��'/'�����
                    {
                        postexp[i++]=e;//��('*'��'/'�����)e��ŵ�postexp��
                        Pop(Optr,e);//��ջԪ��e
                    }
                else//eΪ��'*'��'/'�����ʱ�˳�ѭ��
                    break;
                }
                Push(Optr,*exp); //��'*'��'/'��ջ
                exp++; //����ɨ�������ַ�
                break;
            default://���������ַ�
                while(*exp>='0'&&*exp<='9') //ת�������ַ���
                {
                    postexp[i++]=*exp;//ֱ�ӽ������ַ��洢�ַ�����postexp��
                    exp++;
                }//ֱ�����ַ������ַ�ʱ����,��ʱ������һ��#
                postexp[i++]='#';//����#���߷������ַ�����ʶһ����ֵ������
        }
    }
    while(!StackEmpty(Optr))//��ʱexpɨ����ϣ�ջԪ��ȫ������postexp
    {
        Pop(Optr,e); //��ջԪ��e
        postexp[i++]=e;//��e��ŵ�postexp��
    }
    postexp[i]='\0'; //��postexp���ʽ����ַ�����Ԫ�ؽ�����ʶ
    DestroyStack(Optr);//����ջ
}
double compvalue(char *postexp)
{   int  a,b,c,d,e;
    SqStack *Opnd;//���������ջ
    InitStack(Opnd); //��ʼ��������ջ
    while(*postexp!='\0')//postexp�ַ���δɨ����ʱѭ��
    {   switch(*postexp)
        { 
            case '+'://�ж�Ϊ'+'��
                Pop(Opnd,a);//��ջԪ��a
                Pop(Opnd,b);//��ջԪ��b
                c=b+a;//����c
                Push(Opnd,c);//��������c��������ջOpnd
                break;
            case '-': //�ж�Ϊ'-'��
                Pop(Opnd,a); //��ջԪ��a
                Pop(Opnd,b); //��ջԪ��b
                c=b-a; //����c
                Push(Opnd,c); //��������c��������ջOpnd
                break;
            case '*': //�ж�Ϊ'*'��
                Pop(Opnd,a); //��ջԪ��a
                Pop(Opnd,b); //��ջԪ��b
                c=b*a; //����c
                Push(Opnd,c); //��������c��������ջOpnd
                break;
            case '/': //�ж�Ϊ'/'��
                Pop(Opnd,a); //��ջԪ��a
                Pop(Opnd,b); //��ջԪ��b
                if (a!=0)
                {   c=b/a; //����c
                    Push(Opnd,c); //��������c��������ջOpnd
                    break;
                }
                else
                {   printf("\n\t�������!\n");
                    exit(0); //�쳣�˳�
                }
                break;
            default://���������ַ�'0'-'9'
                d=0;//ת���ɶ�Ӧ����ֵ��ŵ�d��
                while(*postexp>='0'&&*postexp<='9')//�����������ַ�ʱ����
                {
                    d=10*d+*postexp-'0';//�������ִ�ת��Ϊ��ֵ����������
                    postexp++;//�������ַ�'#'���ñ�������-��-
                }
                Push(Opnd,d);//�����������ַ���ת�������ֵd��������ջOpnd
                    break; //�ȴ���������
            }
        postexp++;//�������������ַ�
    }
    GetTop(Opnd,e); //ȡ������ջOpndջ��Ԫ�أ����������������ֵ��e����
    DestroyStack(Opnd);//����ջ
    return e; //����e �������
}
int main()
{
    char exp[]="(2+3)*6+8*5+4"; //�ɽ�exp��Ϊ��������
    //char exp[50];
    //gets(str);//������ʽ�ַ���
    //puts(str);//������ʽ�ַ���
    char postexp[MaxSize];
    trans(exp,postexp);//ת����������
    printf("��׺���ʽ:%s\n",exp);
    printf("��׺���ʽ:%s\n",postexp);
    printf("���ʽ��ֵ:%g\n",compvalue(postexp));//��⺯������
    return 0;
}


