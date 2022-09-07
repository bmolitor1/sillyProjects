#include <stdio.h>
#include <string.h>

struct node{
	char name[10];
	void* next;
};

void addNode(struct node* before, struct node* new){
	new->next = before->next;
	before->next = new;
}

int main(){
	struct node first;
	struct node* f = &first;
	struct node second;
	struct node* s = &second;
	strcpy(first.name, "first");
	strcpy(second.name,"second");
	printf("%s\n",first.name);
	struct node cur;
	struct node* c;
	first.next = s;
	second.next = f;
	c = f;
	for(int i = 0; i < 9; i++){
		c = c->next;
		printf("%s\n",c->name);
	}
	printf("\n");
	struct node third;
	struct node* t = &third;
	strcpy(third.name, "third");
	addNode(s,t);
	for(int i = 0; i < 14; i++){
		c = c->next;
		printf("%s\n",c->name);
	}
	printf("\n");
	struct node oneAndHalf;
	struct node* f5 = &oneAndHalf;
	addNode(f,f5);
	strcpy(f5->name, "first.5");
	for(int i = 0; i < 19; i++){
		c = c->next;
		printf("%s\n",c->name);
	}
}
