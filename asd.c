#include <stdio.h>
#include <stdlib.h>

void iii(int *q,int n,int *f,int *r,int in){
	*r = (*r+1)%n;
	q[*r] = in;
}

void ddd(int *q,int n,int *f,int *r){
	*f = (*f+1)%n;
	q[*f] = 0;
}

void ppp(int *q,int n,int *f,int *r){
	int i;
	for(i=0;i<n;i++){
		printf(" %d",*(q+i));
	}
	printf("\n");
}

int overflow(int *q,int n,int *f,int *r){
	if(*f == (*r+1)%n){
		printf("overflow");
		ppp(q,n,f,r);
		return 0;
	}
	else return 1;
}

int underflow(int *q,int n,int *f,int *r){
	if(*f == *r){
		printf("underflow");
		return 0;
	}
	else return 1;
}

int main(){
	int qn,*q,n,i,in,front=0,rear=0,*f,*r;
	char a,b[5];

	scanf("%d",&qn);
	q = (int*)calloc(qn,sizeof(int));

	f = &front;
	r = &rear;

	scanf("%d",&n);
	gets(b);
	for(i=1;i<=n;i++){
		scanf("%c",&a);
		
		switch(a){
			case 'I':
				scanf("%d",&in);
				gets(b);
				if(overflow(q,qn,f,r))
					iii(q,qn,f,r,in);
				else
					return 0;
				break;
			case 'D':
				gets(b);
				if(underflow(q,qn,f,r))
					ddd(q,qn,f,r);
				else
					return 0;

				break;
			case 'P':
				gets(b);
				ppp(q,qn,f,r);
				break;
		}
	}

	free(q);

}