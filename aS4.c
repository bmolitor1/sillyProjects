#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1000

struct Snake{
	int v; //vertical direction (0 is down)
	int h; //horizontal direction (0 is right)
	int length;
	struct snakePiece* pieces[MAX_LENGTH];
};

struct snakePiece{
	int v;
	int h; //piece coordinates
};

struct snakePiece newP(struct snakePiece *sp){
	sp->v = 0;
	sp->h = 0;
	return *sp;
}

int main(int argc, char** argv){
	// build surface
	// int height = 79;
	// int width = 155;
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
	// bulid snake
	struct Snake s;
	s.v = 0;
	s.h = 0;
	s.length = 5;
	if(argc == 2){
		s.length = atoi(argv[1]);
	}
	if(argc == 4){
		s.length = atoi(argv[3]);
	}

	struct snakePiece p[s.length];
	for(int i = 0; i < s.length; i++){
		p[i].v = 0;
		p[i].h = 0;
		struct snakePiece *pp;
		pp = &p[i];
		s.pieces[i] = pp;
	}

	
	// surface from inputs
	if(argc >= 3){
		width = atoi(argv[1]);
		height = atoi(argv[2]);
	}


	// running loop
	int cycle = 0;
	while(1==1){
		clock_t start = clock();
		int spin;
		float dif = 0;
		while(dif < 50000){
			dif = clock() - start;
		}
		
		// right now we're drawing the entire snake and background every time
		// it would probably be better to draw a "pencil" and an "eraser" head.
		// Then we can just draw two points, move the cursor to those two points and print "X" or " ".
		// Although this would mean every snake intersection would be deleted when you pass over, making a hole-y snake sometimes.

		for(int i = 0; i <= height; i++){
			for(int j = 0; j <= width; j++){
				int flag = 0;
				for(int k = 0; k < s.length; k++){
					if(i == s.pieces[k]->v && j == s.pieces[k]->h){
						flag = 1;
					}
				}
				if(flag == 1){
					printf("X");
				}else{
					printf(" ");
				}
			}
			printf("\n");
		}
		fflush(stdout);


		// here we will move the dots
		// do i want to shift the pointers or just move the coordinates
		for(int i = s.length-1; i > 0; i--){
			s.pieces[i]->v = s.pieces[i-1]->v;
			s.pieces[i]->h = s.pieces[i-1]->h;
		}

		if(s.h==0){
			s.pieces[0]->h++;
			if(s.pieces[0]->h > width){
				s.h = 1;
				s.pieces[0]->h--;
			}
		}else{
			s.pieces[0]->h--;
			if(s.pieces[0]->h < 0){
				s.h = 0;
				s.pieces[0]->h++;
			}
		}
		if(s.v==0){
			s.pieces[0]->v++;
			if(s.pieces[0]->v > height){
				s.v = 1;
				s.pieces[0]->v--;
			}
		}else{
			s.pieces[0]->v--;
			if(s.pieces[0]->v < 0){
				s.v = 0;
				s.pieces[0]->v++;
			}
		}
		// now we go back to the top and reprint:
		for(int i = 0; i <= height; i++){
			printf("\033[F");
		}
		
	}
}
