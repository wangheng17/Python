#include <stdio.h>
#include <stdlib.h>
typedef int  ElemType;
#define MaxSize 50
typedef struct sqstack
{
    ElemType data[MaxSize];
    int top;
}SqStack;
void InitStack(SqStack *&s)//初始化顺序栈
{
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
}
bool StackEmpty(SqStack *s)//判断顺序表是否为空
{
    return(s->top==-1);
}
void DestroyStack(SqStack *&s)//释放顺序表占用的内存空间
{
    free(s);
} 
bool Push(SqStack *&s,ElemType e)//插入元素
{   if (s->top==MaxSize-1) //栈满的情况，即栈上溢出
        return false;
    s->top++; //栈顶指针增1
    s->data[s->top]=e; //元素e放在栈顶指针处
    return true;
}
bool Pop(SqStack *&s,ElemType &e)//将栈顶元素赋给e
{
    if (s->top==-1) //栈为空的情况，即栈下溢出
        return false;
    e=s->data[s->top]; //取栈顶指针元素的元素
    s->top--; //栈顶指针减1，下次入栈时，这个元素会被覆盖，故不予理会
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
    SqStack *Optr;//定义运算符栈（顺序栈）指针
    InitStack(Optr);//初始化运算符栈
    int i=0;//i作为postexp的下标
    while(*exp!='\0')//exp表达式未扫描完时循环
    {
        switch(*exp)//根据元素类型，执行相应操作
        {
            case '('://判定为左括号，入运算符栈，继续扫描其它字符
                Push(Optr,'('); //左括号进栈
                exp++;//继续扫描其他字符
                break;
            case ')'://判定为右括号，则运算符出栈依次放入postexp字符数组中
                Pop(Optr,e); //出栈（运算符或者左括弧）元素e
                while(e!='(' )//不为‘(’时循环，直到碰的‘(’结束，左括弧不存入
                {
                    postexp[i++]=e; //将（运算符）e存放到postexp中，
                    Pop(Optr,e);//继续出栈（运算符或者左括弧）元素e
                }
                exp++;//继续扫描其他字符
                break;
            case '+'://为加或减号时，栈里的运算符存入postexp，直到栈空或者栈顶为‘(’时结束
            case '-':
                while(!StackEmpty(Optr))//栈空时退出循环
                {
                    GetTop(Optr,e);//取栈顶元素（运算符或者左括弧）e
                    if(e!='(')//e不是'('
                    {
                        postexp[i++]=e;//将(运算符）e存放到postexp中
                        Pop(Optr,e);//出栈元素（运算符或者左括弧） e
                    }
                    else break;//碰到左括弧时，退出循环
                }
                Push(Optr,*exp);//将'+'或'-'进栈
                exp++; //继续扫描其他字符
                break;
            case '*'://判定为‘*’或‘/’号，栈里*和/运算符全部存入postexp
            case '/':
                while(!StackEmpty(Optr))//栈不空循环
                {
                    GetTop(Optr,e); //取栈顶元素e
                    if(e=='*'||e=='/')//e为'*'或'/'运算符
                    {
                        postexp[i++]=e;//将('*'或'/'运算符)e存放到postexp中
                        Pop(Optr,e);//出栈元素e
                    }
                else//e为非'*'或'/'运算符时退出循环
                    break;
                }
                Push(Optr,*exp); //将'*'或'/'进栈
                exp++; //继续扫描其他字符
                break;
            default://处理数字字符
                while(*exp>='0'&&*exp<='9') //转存数字字符，
                {
                    postexp[i++]=*exp;//直接将数字字符存储字符数组postexp中
                    exp++;
                }//直到出现非数字字符时结束,此时再增加一个#
                postexp[i++]='#';//增加#或者非数字字符，标识一个数值串结束
        }
    }
    while(!StackEmpty(Optr))//此时exp扫描完毕，栈元素全部放入postexp
    {
        Pop(Optr,e); //出栈元素e
        postexp[i++]=e;//将e存放到postexp中
    }
    postexp[i]='\0'; //给postexp表达式添加字符数组元素结束标识
    DestroyStack(Optr);//销毁栈
}
double compvalue(char *postexp)
{   int  a,b,c,d,e;
    SqStack *Opnd;//定义操作数栈
    InitStack(Opnd); //初始化操作数栈
    while(*postexp!='\0')//postexp字符串未扫描完时循环
    {   switch(*postexp)
        { 
            case '+'://判定为'+'号
                Pop(Opnd,a);//出栈元素a
                Pop(Opnd,b);//出栈元素b
                c=b+a;//计算c
                Push(Opnd,c);//将计算结果c进操作数栈Opnd
                break;
            case '-': //判定为'-'号
                Pop(Opnd,a); //出栈元素a
                Pop(Opnd,b); //出栈元素b
                c=b-a; //计算c
                Push(Opnd,c); //将计算结果c进操作数栈Opnd
                break;
            case '*': //判定为'*'号
                Pop(Opnd,a); //出栈元素a
                Pop(Opnd,b); //出栈元素b
                c=b*a; //计算c
                Push(Opnd,c); //将计算结果c进操作数栈Opnd
                break;
            case '/': //判定为'/'号
                Pop(Opnd,a); //出栈元素a
                Pop(Opnd,b); //出栈元素b
                if (a!=0)
                {   c=b/a; //计算c
                    Push(Opnd,c); //将计算结果c进操作数栈Opnd
                    break;
                }
                else
                {   printf("\n\t除零错误!\n");
                    exit(0); //异常退出
                }
                break;
            default://处理数字字符'0'-'9'
                d=0;//转换成对应的数值存放到d中
                while(*postexp>='0'&&*postexp<='9')//碰到非数字字符时结束
                {
                    d=10*d+*postexp-'0';//连续数字串转换为数值，参与运算
                    postexp++;//非数字字符'#'正好被废弃了-妙-
                }
                Push(Opnd,d);//将连续数字字符串转换后的数值d进操作数栈Opnd
                    break; //等待参与运算
            }
        postexp++;//继续处理其他字符
    }
    GetTop(Opnd,e); //取操作数栈Opnd栈顶元素（存放运算结果），赋值给e返回
    DestroyStack(Opnd);//销毁栈
    return e; //返回e （结果）
}
int main()
{
    char exp[]="(2+3)*6+8*5+4"; //可将exp改为键盘输入
    //char exp[50];
    //gets(str);//输入表达式字符串
    //puts(str);//输出表达式字符串
    char postexp[MaxSize];
    trans(exp,postexp);//转换函数调用
    printf("中缀表达式:%s\n",exp);
    printf("后缀表达式:%s\n",postexp);
    printf("表达式的值:%g\n",compvalue(postexp));//求解函数调用
    return 0;
}


