#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"

int main(int argc, char const *argv[]) {
	srand(time(NULL));
	Tree *tree = new Tree ();
	
	int n = 0;
	printf ("Please, enter num of elements to add to tree: ");
	scanf ("%d", &n);

	for (int i = 0; i < n; ++i) {
		int value = rand()%10;
		printf("\n---Trying to add value %d...\n", value);
		if (tree->insert (value))
			printf("Success!\n");
		else
			printf("Error!\n");
		printf("Current tree in in-order traverse:\n");
		tree->inorderTraverse ();
		printf("\n");
	}

	return 0;
}
