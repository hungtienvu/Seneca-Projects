 /*
I declare that the attached assignment is wholly my own work in 
accordance with Seneca Academic Policy.  No part of this assignment has 
been copied manually or electronically from any other source (including 
web sites) or distributed to other students.  
Name : M Saeed Mohiti   Student ID : 116236159
*/
#define _CRT_SECURE_NO_WARNINGS
#define NAme 10
#include <stdio.h>

//This function returns the tile type for the tile indicated by the parameter

char getTileType(unsigned int index){

	char variable;

    	if(index  == 0)
        	variable = 'C';
    	else if(index% 7 == 0)
        	variable = 'G';
    	else if(index% 5 == 0)
        	variable = 'L';
    	else if(index% 3 == 0)
        	variable = 'W';

    	else
        	variable = ' ';

        return variable;
}


// this function will print the tiles as a square board base on user input

void displayBoard(unsigned int size){

// top rows

int counter = ((size*4)-5);	
int counter1 = size;
int counter2 = size - size ;
        for(int i=0;i<size;++i){
        	printf(" ___ ");
	}
	printf("\n");
	for(int i=0;i<size;++i){
                printf("| %c |", getTileType(counter2));
		counter2++;
        }
	printf("\n");

	for(int i=0;i<size;++i){
                printf("|___|");
        }
    	printf("\n");

//middle rows

	for(int j=0;j<size-2;j++){

		printf(" ___ ");
		for(int l=0;l<size-2;l++)
		printf("     ");
                printf(" ___ ");		
		printf("\n");		
                printf("| %c |",getTileType(counter));
		counter--;


                for(int l=0;l<size-2;l++)
                printf("     ");
                printf("| %c |", getTileType(counter1));
                printf("\n");
                printf("|___|");
		counter1++;

                for(int l=0;l<size-2;l++)
                printf("     ");
                printf("|___|");
                printf("\n");
		
		
        }


// bottom rows

	for(int i=0;i<size;++i){
                printf(" ___ ");
        }
        printf("\n");
        for(int i=0;i<size;++i){
                printf("| %c |", getTileType(counter));
		counter--;
        }
        printf("\n");

        for(int i=0;i<size;++i){
                printf("|___|");
        }
        printf("\n");
}
	


int main() {
	int s = 1;
        if (getTileType(153) != 'W') printf("153 should return W");
        else if (getTileType(65) != 'L') printf("65 should return L");
        else if (getTileType(49) != 'G') printf("49 should return G");
        else if (getTileType(0) != 'C') printf("0 should return C");
        else if (getTileType(105) != 'G') printf("105 should be G");
        else if (getTileType(79) != ' ') printf("79 should be space");
        else {
		printf("\n\n--Program Start--\n\n");
        	printf("getTileType test passed!\nEnter board size: ");
        	scanf("%d", &s);

	if(s == 1){
		printf(" ___ \n");
		printf("| %c |\n" , getTileType(0));	
		printf("|___|\n");
	}

	else
        	displayBoard(s);
		printf("\n--Program End--\n\n");

        }
}
