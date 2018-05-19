#include <stdio.h>
#include <string.h>

typedef struct stack
{
	int data[100];
	int t;
}stack;

void init(stack *a)
{
	a->t = -1;
}

int empty(stack *a)
{
	return (a->t == -1);
}

int full(stack *a)
{
	return (a->t == 99);
}

void push(stack *a,int data)
{
	if(full(a)){
		return;
	}
	else{
		a->data[++(a->t)]=data;
		
	}
}

int pop(stack *a)
{
	if(empty(a))
	{
		return -1;
	}
	return a->data[(a->t)--];
}

int cal(char *aaa) // 후위표기식을 계산하는 함수
{ 
    stack s; 
    int i,len; 
    char ch; 
    int a,b,value; 
	len = strlen(aaa);

    init(&s); 

    for(i=0;i<len;i++) 
    { 
        ch=aaa[i]; 
        if(ch != '+' && ch != '-' && ch != '*' && ch != '/') 
            push(&s,ch-'0'); // 피연산자 
        else 
        { 
            b=pop(&s); 
            a=pop(&s); 

            switch(ch) 
            { 
                case '+' : push(&s,a+b);    break; 
                case '-' : push(&s,a-b);    break; 
                case '*' : push(&s,a*b);    break; 
                case '/' : push(&s,a/b);    break; 
            } 
        } 
    } 

    return pop(&s); 
} 

int main(){
	int i,n;
	char ch[101];

	scanf("%d",&n);
	gets(ch);
	for(i=1;i<=n;i++){
		gets(ch);
		printf("%d\n",cal(ch));
	}

}