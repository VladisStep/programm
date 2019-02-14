#include <stdio.h>
#include <stdlib.h>

struct Node{
	int n;
	struct Node *next;

};

struct Node *doStruct(int a, struct Node *add){
	
	struct Node *elem = malloc(sizeof(struct Node));
	elem->n = a;
	add->next = elem;
	elem->next = NULL;  
	return elem;

}


int howN(struct Node *st){
	
	
	int maxN = 0;
	int n = 1;
	int i;
	struct Node *head = st;
	struct Node *headconst= st;
	struct Node *tmp = st;
	do{
		n = 1;
		do{
			if(tmp->n == tmp->next->n)
				n++;
			else{
				if(n > maxN)

					maxN = n;
				n = 1;
			}

		tmp = tmp->next;

 		}while(tmp != head);
		
		if(n > maxN)
			maxN = n-1;
		
		
		head = head->next;
		tmp = head;

		
	}while(head != headconst);
	
	return maxN;	
} 

	
int main(){

	int i, n, d;
	scanf("%d", &n);
	int *arr = calloc(n, sizeof(int));
	
	scanf("%d", &arr[0]);
	struct Node *head = malloc(sizeof(struct Node));
	head->n = arr[0];
	head->next = NULL;
	
	scanf("%d", &arr[1]);
	

	struct Node *tmp = doStruct(arr[1], head);
	
	for(i = 2; i < n; i++){
		scanf("%d", &arr[i]);
		tmp = doStruct(arr[i], tmp);
	}
	
	tmp->next = head;

	printf("%d\n", howN(head));

}
