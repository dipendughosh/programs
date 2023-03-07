#include "gavltree.hpp"
#include <stdio.h>	 	// scanf
#include <string.h>    	// strcmp
#include <math.h>		// pow
#include <dos.h>		// sleep
#include <time.h>    // time

int count;

int compChar(BYTE *itemOne, BYTE *itemTwo)
{
	return((int)((*(char *)itemOne) - (*(char *)itemTwo)));
}

int compLong(BYTE *itemOne, BYTE *itemTwo)
{
	return((int)((*(long *)itemOne) - (*(long *)itemTwo)));
}

int compInt(BYTE *itemOne, BYTE *itemTwo)
{
	return((*(int *)itemOne) - (*(int *)itemTwo));
}

int displayInorder(GAvlTree *tree)
{
		char 	*visitPtr;
		int 	numNodes = 0;

		tree->initTraversal(INORDER);
		printf("In-order traversal\n");
		while ((visitPtr = (char *)tree->visitNextNode()) != NULL) {
			printf(" %c",*visitPtr);
			numNodes++;
		}
		printf("\n");
		return(numNodes);
}

int displayPreorder(GAvlTree *tree)
{
		char 	*visitPtr;
		int 	numNodes = 0;

		tree->initTraversal(PREORDER);
		printf("Pre-order traversal\n");
		while ((visitPtr = (char *)tree->visitNextNode()) != NULL) {
			printf(" %c",*visitPtr);
			numNodes++;
		}
		printf("\n");
		return(numNodes);
}

int displayPostorder(GAvlTree *tree)
{
		char 	*visitPtr;
		int 	numNodes = 0;

		tree->initTraversal(POSTORDER);
		printf("Post-order traversal\n");
		while ((visitPtr = (char *)tree->visitNextNode()) != NULL) {
			printf(" %c",*visitPtr);
			numNodes++;
		}
		printf("\n");
		return(numNodes);
}
#ifdef GAVLTREE_DEBUG

void mapTree(GAvlTree *tree, GAvlNode *startNodePtr)
{
		char 	*visitPtr,
				*dispBufPtr;
		int 	xPos, yPos,
				dispWidth, dispHeight, dispSize,
				dispPos;


		tree->initMapping(startNodePtr,xPos,yPos);
		dispWidth = 2 * (xPos + 1);
		dispHeight = 1 + tree->getMaxDepth(startNodePtr);
		dispSize = dispWidth * dispHeight;

		dispBufPtr = new char[(dispSize + 1)];

		*dispBufPtr = ' ';
		for(int i = 1; i < dispSize; i++)
			if (i % dispWidth == 0)
				*(dispBufPtr + i) = '\n';
			else
				*(dispBufPtr + i) = ' ';
		*(dispBufPtr + dispSize) = '\0';

		while ((visitPtr = (char *)tree->mapNextNode(xPos,yPos)) != NULL) {
			dispPos = (xPos + ((yPos -1) * dispWidth));
			if (dispPos < dispSize)
				*(dispBufPtr + dispPos) = *visitPtr;
			else {
				printf("FATAL Error!\n");
				exit(256);
			}
		}
		//count++;
		if (count == 10) {
			fprintf(stdout,"\n%s\n",dispBufPtr);
			count = 0;
		}
		printf("\n%s\n",dispBufPtr);

		delete dispBufPtr;
}
#endif

int	letters[26];

void setupRandomLetters(void)
{
	for (int i = 0; i < 26; i++)
		letters[i] = 0;
}

int getRandomLetter()
{
	int i;

	for(EVER) {
		//i = random(26);
      i = (rand()%26);

		if (!letters[i]) {
			letters[i] = 1;
			break;
		}
	 }
	 return(97+i);
}

main()
{
	GAvlTree	charTree(sizeof(char),compChar);

	char 	*charPtr = new char;

   //randomize();
	srand( (unsigned)time( NULL ) );
   
   count = 0;
	for (int loop = 0; loop < 25; loop++) {

	int count = 0;
	int numNodes = 0;

	setupRandomLetters();

	while (count < 26) {
		*charPtr = getRandomLetter();
		printf("Attempting to add %c\n",*charPtr);
		if ((charTree.addNode((BYTE *)charPtr)) == TRUE) {
			printf("%c added, %i nodes now in tree.\n",*charPtr,charTree.getNumNodes());
			numNodes = displayInorder(&charTree);
#ifdef GAVLTREE_DEBUG
			mapTree(&charTree,NULL);
#endif
			count++;
			if (numNodes != charTree.getNumNodes()) {
				printf("Error!\nOnly %i nodes found when there should be %i.\n",numNodes, charTree.getNumNodes());
				exit(250);
			}
		}
	}

#ifdef GAVLTREE_DEBUG
			mapTree(&charTree,NULL);
#endif
	setupRandomLetters();

	for (int i = 0; i < 13; i++) {
		*charPtr = getRandomLetter();
		if ((charTree.deleteNode((BYTE *)charPtr)) == TRUE) {
			printf("%c deleted, %i nodes now in tree.\n",*charPtr, charTree.getNumNodes());
			numNodes = displayInorder(&charTree);
#ifdef GAVLTREE_DEBUG
			mapTree(&charTree,NULL);
#endif
			if (numNodes != charTree.getNumNodes()) {
				printf("Error!\nOnly %i nodes found when there should be %i.\n",numNodes, charTree.getNumNodes());
				exit(250);
			}
		 }
	}
#ifdef GAVLTREE_DEBUG
		mapTree(&charTree,NULL);
#endif
		numNodes = displayInorder(&charTree);
		numNodes = displayPreorder(&charTree);
		numNodes = displayPostorder(&charTree);

		while (charTree.getNumNodes() > 0) {
			*charPtr = getRandomLetter();
			if ((charTree.deleteNode((BYTE *)charPtr)) == TRUE) {
				printf("%c deleted, %i nodes now in tree.\n",*charPtr, charTree.getNumNodes());
				numNodes = displayInorder(&charTree);
#ifdef GAVLTREE_DEBUG
				if (numNodes)
					mapTree(&charTree,NULL);
#endif
			}
		}
		printf("And again!\n");
	}

	return(TRUE);
}
