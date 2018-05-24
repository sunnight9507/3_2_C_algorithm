#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Que{
	struct Que* p;
	int num;
	struct Que* n;
}que;

typedef struct Deque{
	que *front;
	que *rear;
}deque;

void init(deque *dq){
	dq->front = NULL;
	dq->rear = NULL;
}

que* newnode(){
	que *newnode;
	newnode = (que*)malloc(sizeof(que));
	newnode->num = 0;
	newnode->n = NULL;
	newnode->p = NULL;
	return newnode;
}

int underflow(deque *dq){
	if(dq->front == NULL && dq->rear == NULL){
		printf("underflow");
		return 1;
	}
	else return 0;
}

void add_front(deque *dq,int num){
	que *node=newnode();
	node->num = num;
	if(dq->front == NULL && dq->rear == NULL){
		dq->front = node;
		dq->rear = node;
	}
	else{
		node->n = dq->front;
		dq->front->p = node;
		dq->front = node;		
	}
}

void add_rear(deque *dq,int num){

	que *node=newnode();
	node->num = num;
	if(dq->front == NULL && dq->rear==NULL){
		dq->front = node;
		dq->rear = node;
	}
	else{
		node->p = dq->rear;
		dq->rear->n = node;
		dq->rear = node;
	}
}

int delete_front(deque *dq){
	
	int n;
	que *node = newnode();
	n = dq->front->num;
	node = dq->front;
	if(dq->front == dq->rear){
		dq->front = NULL;
		dq->rear = NULL;
	}
	else{
		dq->front = dq->front->n;
		dq->front->p = NULL;
	}
	free(node);
	return n;
}

int delete_rear(deque *dq){
	
	int n;
	que *node = newnode();
	n = dq->front->num;
	node = dq->rear;
	if(dq->front == dq->rear){
		dq->front = NULL;
		dq->rear = NULL;
	}
	else{
		dq->rear = dq->rear->p;
		dq->rear->n = NULL;
	}
	free(node);
	return n;
}

void print(deque *dq){
	
	que *node = newnode();
	node = dq->front;
	while(1){
		if(node == NULL)
			break;
		printf(" %d",node->num);
		node = node->n;
	}
	printf("\n");
	free(node);
}

int main(){
	int n,i,num,del;
	deque dq;
	que *node;
	char a[5],b[3];

	scanf("%d",&n);
	gets(b);

	init(&dq);

	for(i=1;i<=n;i++){
		scanf("%s",a);
		if(a[0] == 'A' && a[1] == 'F'){
			scanf("%d",&num);
			add_front(&dq,num);
		}
		else if(a[0] == 'A' && a[1] == 'R'){
			scanf("%d",&num);
			add_rear(&dq,num);
		}
		else if(a[0] == 'D' && a[1] == 'F'){
			if(underflow(&dq))
				return 0;
			else
				del = delete_front(&dq);
		}
		else if(a[0] == 'D' && a[1] == 'R'){
			if(underflow(&dq))
				return 0;
			else
				del = delete_rear(&dq);
		}
		else if(a[0] == 'P'){
			print(&dq);
		}
	}

	node = newnode();
	node = dq.front;
	while(node != NULL){
		que* next = node->n;
		free(node);
		node = next;
	}
}