#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node * next_node;
	struct node * previous_node;
} node;

int main(int argc, char **argv)
{
	if(argc > 1){
		printf("Hello, world, %s!\n", argv[1]); 
	}
}
