#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//14010379 권태양

void makeExternalNode(char** tr,int k){
	printf("Enter decision: ");
	gets(tr[k]);

}

void makeInternalNode(char** tr,int k){
	char* a,an[10];

	printf("Enter question: ");
	gets(tr[k]);

	printf("Question if yes to %s ? ",tr[k]);
	gets(an);

	if(!strcmp(an,"yes")){
		makeInternalNode(tr,2*k);
	}
	else{
		makeExternalNode(tr,2*k);
	}
	
	printf("Question if no to %s ? ",tr[k]);
	gets(an);

	if(!strcmp(an,"yes")){
		makeInternalNode(tr,2*k+1);
	}
	else{
		makeExternalNode(tr,2*k+1);
	}
}

char** buildDecisionTree(){
	char **tr;
	int i;

	tr = (char**)malloc(sizeof(char*)*64);
	for(i=1;i<=64;i++){
		tr[i] = (char*)malloc(sizeof(char)*100);
		tr[i][0] = '\0';
	}

	printf("***Let's build a dichotomous QA system\n");
	makeInternalNode(tr,1);

	return tr;
}

void process(char** tr,int k){
	char an[10];

	puts(tr[k]);
	if(tr[2*k][0] == '\0' && tr[2*k+1][0] == '\0')
		return;
	gets(an);

	if(!strcmp(an,"yes")){
		if(tr[2*k][0] == '\0')
			return;
		process(tr,k*2);
	}
	else{
		if(tr[2*k+1][0] == '\0')
			return;
		process(tr,k*2+1);
	}
}

void runDecisionTree(char **tr){

	printf("***Please answer questions\n");
	process(tr,1);

}

int main(){
	char **tr;
	int i;

	tr = buildDecisionTree();

	for(i=1;i<=3;i++){
		runDecisionTree(tr);
	}

	for(i=1;i<=64;i++){
		free(tr[i]);
	}
	free(tr);

	return 0;
}