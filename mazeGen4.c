#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREY "\e[0;100m"
#define RSET "\e[0m"

struct block{
	int ub;
	int db;
	int rb;
	int lb;
	int uw;
	int dw;
	int rw;
	int lw;
	int used;
};

int main(int argc, char* argv[]){
	char buff[255];
        system("tput cols > output.txt");
        FILE* file = fopen("output.txt","r");
        fgets(buff,255,(FILE*)file);

        fclose(file);
        char buff2[255];
        system("tput lines > output.txt");
        FILE* file2 = fopen("output.txt","r");
        fgets(buff2,255,(FILE*)file2);
        fclose(file2);
        int width = atoi(buff) - 2;
        int height = atoi(buff2) - 2;
	int sizej = height/3;
	int sizek = width/3;
	if(argc > 2){
		sizek = atoi(argv[1]);
		sizej = atoi(argv[2]);
	}
	struct block maze[sizej][sizek];
	srand(time(NULL));


	// populating the data into the maze
	
	// fill with zeros for some reason
	for(int j = 0; j < sizej; j++){
		for(int k = 0; k < sizek; k++){
			maze[j][k].uw=0;
			maze[j][k].dw=0;
			maze[j][k].lw=0;
			maze[j][k].rw=0;
			maze[j][k].ub=1;
			maze[j][k].db=1;
			maze[j][k].lb=1;
			maze[j][k].rb=1;
			maze[j][k].used=0;
		}
	}
	
	// top/bottom row
	for(int k = 0; k < sizek; k++){
		maze[0][k].uw=999;
		maze[sizej-1][k].dw=999;
	}
	// left/right column
	for(int j = 0; j < sizej; j++){
		maze[j][0].lw=999;
		maze[j][sizek-1].rw=999;
	}

	// down weights for those not filled in
	for(int j = 0; j < sizej-1; j++){
		for(int k = 0; k < sizek; k++){
			maze[j][k].dw = rand()&127;
		}
	}

	// right weights for those not filled in
	for(int j = 0; j < sizej; j++){
		for(int k = 0; k < sizek-1; k++){
			maze[j][k].rw = rand()&127;
		}
	}
	
	// copy down weights to up weights, right weights to left weights
	// for those not filled in
	for(int j = 1; j < sizej; j++){
		for(int k = 0; k < sizek; k++){
			maze[j][k].uw = maze[j-1][k].dw;
		}
	}
	
	for(int j = 0; j < sizej; j++){
		for(int k = 1; k < sizek; k++){
			maze[j][k].lw = maze[j][k-1].rw;
		}
	}
	goto skipTestPrint;
	for(int j = 0; j < sizej; j++){
		for(int k = 0; k < sizek; k++){
			printf("\t%i\t\t",maze[j][k].uw);
		}
		printf("\n");
		for(int k = 0; k < sizek; k++){
			printf("%i\t\t%i\t",maze[j][k].lw,maze[j][k].rw);
		}
		printf("\n");
		for(int k = 0; k < sizek; k++){
			printf("\t%i\t\t",maze[j][k].dw);
		}
		printf("\n");
	}
	skipTestPrint:

	// this is where we implement djikstra's algorithm
	// center = [0][0], end = [size-1][size-1], but that doesn't matter
	// the algorith finds the shortest path to all points
	
	// our goal is to find the lowest cost, unused node adjacent to the known path
	maze[0][0].used = 1;
	int lowestValue = 998;
	int prevCoor[2];
	int conCoor[2];
	int direction; // counter clockwise, starting at up?
	for(int q = 0; q < sizej*sizek-1; q++){
		lowestValue= 998;
		for(int j = 0; j < sizej; j++){
			for(int k = 0; k < sizek; k++){
				if(maze[j][k].used==1){
					// if any of the unused adjacent blocks are lower cost than lowestValue, swap
					if(j!=0){
						if(maze[j][k].uw<lowestValue && maze[j-1][k].used==0){
							lowestValue=maze[j][k].uw;
							prevCoor[0]=j;
							prevCoor[1]=k;
							conCoor[0]=j-1;
							conCoor[1]=k;
							direction = 0;
						}
					}
					if(j!=sizej-1){
						if(maze[j][k].dw<lowestValue && maze[j+1][k].used==0){
							lowestValue=maze[j][k].dw;
							prevCoor[0]=j;
							prevCoor[1]=k;
							conCoor[0]=j+1;
							conCoor[1]=k;
							direction = 2;
						}
					}
					if(k!=0){
						if(maze[j][k].lw<lowestValue && maze[j][k-1].used==0){
							lowestValue=maze[j][k].lw;
							prevCoor[0]=j;
							prevCoor[1]=k;
							conCoor[0]=j;
							conCoor[1]=k-1;
							direction = 1;
						}
					}
					if(k!=sizek-1){
						if(maze[j][k].rw<lowestValue && maze[j][k+1].used==0){
							lowestValue=maze[j][k].rw;
							prevCoor[0]=j;
							prevCoor[1]=k;
							conCoor[0]=j;
							conCoor[1]=k+1;
							direction = 3;
						}
					}
				}
			}
		}
		//printf("lowest cost:\t%i\n",lowestValue);
		//printf("direction:\t%i\n",direction);
		//printf("modify maze[%i][%i]\n",conCoor[0],conCoor[1]);
		// so we make prevCoor in direction bit = 0;
		// then we can make conCoor in the opposite direction = 0;
		// make conCoor used bit = 1;
		if(direction==0){
			maze[prevCoor[0]][prevCoor[1]].ub = 0;
		}else if(direction==1){
			maze[prevCoor[0]][prevCoor[1]].lb = 0;
		}else if(direction==2){
			maze[prevCoor[0]][prevCoor[1]].db = 0;
		}else if(direction==3){
			maze[prevCoor[0]][prevCoor[1]].rb = 0;
		}else{
			printf("hhhhhmmm something went wrong\n");
		}

		if(direction==0){
			maze[conCoor[0]][conCoor[1]].db = 0;
		}else if(direction==1){
			maze[conCoor[0]][conCoor[1]].rb = 0;
		}else if(direction==2){
			maze[conCoor[0]][conCoor[1]].ub = 0;
		}else if(direction==3){
			maze[conCoor[0]][conCoor[1]].lb = 0;
		}else{
			printf("hhhhhmmm something went wrong\n");
		}

		maze[conCoor[0]][conCoor[1]].used = 1;
	}

	goto realPrint;
	for(int j = 0; j < sizej; j++){
		for(int k = 0; k < sizek; k++){
			if(maze[j][k].used==1){
				printf("j:%i\tk:%i\t\n",j,k);
			}
		}
	}
	//return 0;
	
realPrint:

	// here i'm gonna place the doors so it's not centered 
	// just kidding, seems like corner doors were the hardest version for me

	// printing the maze
	for(int j = 0; j < sizej; j++){
		for(int k = 0; k < sizek; k++){
			if(maze[j][k].ub==0 || (j==0 && k==0)){	
				printf(GREY " " RSET " " GREY " " RSET); // "X X");
			}else{
				printf(GREY "   " RSET); //"XXX");
			}
		}
		printf("\n");
		for(int k = 0; k < sizek; k++){
			if(maze[j][k].lb==0){
				printf("  ");
			}else{
				printf(GREY " " RSET " "); //"X ");
			}
			if(maze[j][k].rb==0){
				printf(" ");
			}else{
				printf(GREY " " RSET);
			}
		}
		printf("\n");
		for(int k = 0; k < sizek; k++){
			if(maze[j][k].db==0 || (j==sizej-1 && k==sizek-1)){
				printf(GREY " " RSET " " GREY " " RSET); //"X X");
			}else{
				printf(GREY "   " RSET); //"XXX");
			}
		}
		printf("\n");
	}
}
