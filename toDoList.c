#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE *td;
	char tdv[256][256];
	if(!(td = fopen("todo.txt","r"))){
		printf("no file, creating list\n");
		td = fopen("todo.txt","w");
		fprintf(td, "%s","Make todo list\n");
		fclose(td);
		td = fopen("todo.txt","r");
	}else{
		//printf("file exists\n");
	}
	char line[256];
	int i = 0;
	while(fgets(line,256,td)){
		//printf("task: %s", line);
		memcpy(tdv[i],line,256);
		i++;
	}

	for(int j = 0; j < i; j++){
		printf("%i: %s",j,tdv[j]);
	}

	fclose(td);

	// now we allow user to modify
	
	char answer[6];
	char element[3];
	char newElement[256];
	int elementInt;
	while(strcmp(answer,"quit")){
		printf("What action do you want to perform? (add/finish/quit)? ");
		scanf("%6s",answer);
		if(!strcmp(answer,"finish")){
			printf("Which element do you want to complete? ");
			scanf("%3s",element);
			elementInt = atoi(element);
			for(int j = elementInt; j < i-1; j++){
				memcpy(tdv[j],tdv[j+1],256);//tdv[j] = tdv[j+1];
			}
			memcpy(tdv[i],"",256);//tdv[i] = "";
			i--;
			printf("\n\n");
			for(int j = 0; j < i; j++){
				printf("%i: %s",j,tdv[j]);
			}
			printf("\n\n");
		}
		if(!strcmp(answer,"add")){
			printf("What is the task? ");
			while(getchar()!='\n'){
			}
			// how do you do this lol
			//scanf("%256s",newElement);
			fgets(newElement,256,stdin);

			memcpy(tdv[i],newElement,256);
			i++;
			printf("\n\n");
			for(int j = 0; j < i; j++){
				printf("%i: %s",j,tdv[j]);
			}
			printf("\n\n");
		}
	}

	remove("todo.txt");
	FILE * td2;
	td2 = fopen("todo.txt","w");
	for(int j = 0; j < i; j++){
		fprintf(td2,"%s",tdv[j]);
	}
	fclose(td2);

}
