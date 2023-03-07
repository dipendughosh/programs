// File: GAVLTREE.CPP:-------------------------------------------------------
//
// Implementation of the GAvlTree class, a generic, stack-based,
// self-balancing "AVL" binary search tree.
//
// (c) L.F. Holgate, May 1991.
//
//---------------------------------------------------------------------------

// Contents:-----------------------------------------------------------------
//
// This file contains the following:
//
// Constructors for the GAvlTree class:
// 		GAvlTree(unsigned int, compareFnc *).
//
// Public member functions for the GAvlTree class:
//		int addNode(BYTE *), BYTE *getNode(BYTE *), BYTE *removeNode(BYTE *),
//		int deleteNode(BYTE *), int getLeftDepth(GAvlNode *),
//		int getRightDepth(GAvlNode *), int getMaxDepth(GAvlNode *),
//		int initTraversal(int, GAvlNode *), BYTE *visitNextNode(void),
//		int initMapping(GAvlNode *, int &, int &),
//		BYTE *mapNextNode(int &, int &), int getErrorCode(void).
//
// Private member functions for the GAvlTree class:
// 		int findNode(BYTE *), int climbStackAndBalance(GAvlNode *),
//		GAvlNode *rotate(GAvlNode *,int),
//		GAvlNode *setupStackRight(GAvlNode *, GAvlNode *),
//		GAvlNode *setupStackLeft(GAvlNode *, GAvlNode *).
//
//-----------------------------------------------------------End of contents.

// Dependencies:-------------------------------------------------------------

#include "gavltree.hpp"

#ifdef GAVLTREE_DEBUG

#include <math.h>						// needed for pow()
void mapTree(GAvlTree *, GAvlNode *);

#endif //GAVLTREE_DEBUG

//-------------------------------------------------------End of dependencies.

// Constructor:--------------------------------------------------------------

GAvlTree::GAvlTree(unsigned int dataSize, compareFnc *compFncPtr)
{
	// Description of constructor:-------------------------------------------
	//
	// Summary:
	// 		The constructor for the GAvlTree class sets up the initial values
	//		for the private data members of the class.
	//
	// Parameters:
	// 	unsigned int dataSize -
	//		The size, in bytes, of the data items to be stored in the tree.
	//
	//	compareFnc *compFncPtr -
	//		A pointer to the function that should be used to compare data
	//		items in the tree. The comparison function should take two
	//		pointers to BYTEs as parameters and return an int. The function
	//		should return less than zero if the value of the data pointed to
	//		by the first parameter is "less" than the value of the data
	//		pointed to by the second parameter; zero if the value of the data
	//		pointed to by each pointer is "equal"; and more than zero if the
	//		value of the data pointed to by the first parameter is "more"
	//		than that pointed to by the second. See the example below for a
	//		valid comparison function for use in a tree of integers.
	//
	//			int compInt(BYTE *itemOne, BYTE *itemTwo)
	//			{
	//				return((*(int *)itemOne) - (*(int *)itemTwo));
	// 			}
	//
	// Return value:
	//		None.
	//
	// Functional description:
	//		None.
	//
	// Remarks:
	//		None.
	//
	//-------------------------------------End of description of constructor.

	size = dataSize;
	numNodes = traversalType = traversalStateFlag = 0;
	errorCode = NO_ERROR;
	rootNodePtr = traversalNodePtr = NULL;
	compareFncPtr = compFncPtr;
}

//--------------------------------------------------------End of constructor.

// Public member functions:--------------------------------------------------

int GAvlTree::addNode(BYTE *newDataPtr)
{
	// Description of member function: addNode:------------------------------
	//
	// Summary:
	//		This member function is used to add a new data item to the tree.
	//
	// Parameters:
	// 	BYTE *newDataPtr -
	//		This is a pointer to the data item to add to the tree.
	//
	// Return value:
	// 		This function returns TRUE if the data item was successfully
	//		added to the tree and FALSE if the data was not added.
	//
	// Functional description:
	//		First errorCode is reset to NO_ERROR, throughout the function
	//		errorCode is regularly tested, if any of these tests fail then
	//		control passes to the error handler at the end of the function.
	//		The member function findNode() is called to ensure that the data
	//		item to be added is not already in the tree. If the data item has
	//		not been found in the tree an attempt is made to create a new
	//		node, checks are then made to ensure that the node has been
	//		successfully created. A check is then made to see if the new node
	//		is the only node in the tree, if it is then the new node is
	//		placed in the root. If this isn't the first node, a node and
	//		direction flag are popped from the stack, which findNode()
	//		created, the new node is added to the tree in the correct
	//		location and the tree is balanced, if necessary, by calling the
	//		member function climbStackAndBalance(). Finally the number of
	//		nodes count is incremented and the function returns TRUE
	//		indicating that the data item has been added. If at any stage an
	//		error occurs which would lead to the data item not being added
	//		to the tree control passes to the error handler. This frees any
	//		memory allocated and clears the stack built by findNode() and
	//		then returns FALSE to indicate that the data item was not added.
	//
	// Remarks:
	//		The member function getErrorCode() should be called after each
	//		call to addNode() as even after a successful call an error may
	//		have occurred during the tree balancing stage, if free memory is
	//		too low to build the stack of nodes, and correct balancing may
	//		not have been possible. If getErrorCode() reports an error after
	//		a successful call to addNode() then the tree will have been left
	//		in an unbalanced state, free some memory and call balanceTree()
	//		to correct this.
	//
	//------------------------End of description of member function: addNode.

	int         found,
				side;

	GAvlNode    *currentNodePtr = rootNodePtr,
				*newNodePtr = NULL;

	errorCode = NO_ERROR;

	found = findNode(newDataPtr);

	if (errorCode)
		goto Error;

	if (!found) {
		if (!(newNodePtr = new GAvlNode(newDataPtr,size))) {
			errorCode = NO_MEM;
			goto Error;
		}
		errorCode = newNodePtr->getErrorCode();
		if (errorCode)
			goto Error;
	} else {
		errorCode = DATA_FOUND;
		goto Error;
	}

	if (!rootNodePtr) {
		rootNodePtr = newNodePtr;
	} else {
		if (!(currentNodePtr = stack.pop(side))) {
			errorCode = stack.getErrorCode();
			goto Error;
		}

		if (side == RIGHT)
			currentNodePtr->rightTreePtr = newNodePtr;
		else
			currentNodePtr->leftTreePtr = newNodePtr;

		errorCode = climbStackAndBalance(currentNodePtr);
	}
	numNodes++;
	return(TRUE);

Error:
	if (newNodePtr)
		delete newNodePtr;
	stack.clear();
	return (FALSE);
}


BYTE *GAvlTree::getNode(BYTE *targetDataPtr)
{
	// Description of member function: getNode:------------------------------
	//
	// Summary:
	//		This member function is used to retrieve a pointer to a data item
	//		without removing the data item from the tree.
	//
	// Parameters:
	// 	BYTE *targetDataPtr -
	//		This is a pointer to a data item which will match the required
	//		data item when compared using the compare function.
	//
	// Return value:
	// 		This function returns a pointer to the data item that matches
	//		the data item pointed to by targetDataPtr if the data item is
	//		located in the tree and NULL if it is not.
	//
	// Functional description:
	//		First errorCode is reset to NO_ERROR, throughout the function
	//		errorCode is regularly tested, if any of these tests fail then
	//		control passes to the error handler at the end of the function.
	//      The member function findNode() is called to search the tree for
	//		a match to the data item pointed to by targetDataPtr. If a match
	//		is found in the tree, the matching node is popped from the stack,
	//		which findNode() built whilst searching, the stack is then
	//		cleared and the data item stored in the node is returned. If at
	//		any stage an error occurs, control passes to the error handler.
	//		This clears the stack built by findNode() and returns NULL, to
	//		signal failure.
	//
	// Remarks:
	//		After any call to getNode() that returns NULL the member function
	//		getErrorCode() should be called to check for errors, the error
	//		code returned will be DATA_NOT_FOUND if the function has operated
	//		correctly and simply failed to locate a match to the data item in
	//		the tree. The data item pointed to by the pointer that is
	//		returned by a successful call to this function can be manipulated
	//		normally but should not be deleted. You should also be careful
	//		NOT to alter any data that is used by the comparison function as
	//	    this could cause the node's location in the tree to become
	//		invalid.
	//
	//------------------------End of description of member function: getNode.

	int 		found;
	GAvlNode	*returnNodePtr;

	errorCode = NO_ERROR;

	found = findNode(targetDataPtr);

	if (errorCode)
		goto Error;

	if (!found) {
		if (!errorCode)
			errorCode = DATA_NOT_FOUND;
		goto Error;
	}

	if (!(returnNodePtr = stack.pop(found))) {
		errorCode = stack.getErrorCode();
		goto Error;
	}

	stack.clear();

	return(returnNodePtr->dataPtr);

Error:
	stack.clear();
	return(NULL);
}

BYTE *GAvlTree::removeNode(BYTE *targetDataPtr)
{
	// Description of member function: removeNode:---------------------------
	//
	// Summary:
	//		This member function is used to remove a data item from the tree.
	//
	// Parameters:
	// 	BYTE *targetDataPtr -
	//		This is a pointer to a data item which will match the data item
	//		that should be removed from the tree when compared using the
	//		compare function.
	//
	// Return value:
	// 		This function returns the data item that matches the data item
	// 		pointed to by targetDataPtr if the data item is located in the
	//		tree and NULL if it is not.
	//
	// Functional description:
	//		First errorCode is reset to NO_ERROR, throughout the function
	//		errorCode is regularly tested, if any of these tests fail then
	//		control passes to the error handler at the end of the function.
	//      The member function findNode() is called to search the tree for
	//		a match to the data item pointed to by targetDataPtr. If a match
	//		is found in the tree, the matching node is popped from the stack,
	//		which findNode() built whilst searching. The node is removed from
	// 		the tree and its sub-trees are linked, adding to the stack as we
	//		move through the nodes to achieve the correct linking. If no
	//		error occured whilst linking the two sub-trees the member
	//		function climbStackAndBalance() is called to balance the tree.
	// 		The data from the removed node is then copied out of the node and
	//		the node is deleted. Finally the count of nodes is decreased by
	//		one and a pointer to the removed data item is returned. If at
	//		any stage an error occurs, control passes to the error handler.
	//		This clears the stack built by findNode() and returns NULL, to
	//		signal failure.
	//
	// Remarks:
	//		The member function getErrorCode() should be called after each
	//		call to removeNode() as even after a successful call an error may
	//		have occurred during the linking or tree balancing stage, if free
	//		memory is too low to build the stack of nodes, and correct
	//		balancing may not have been possible. If getErrorCode() reports
	//		an error after a successful call to removeNode() then the tree
	//		will have been left in a linked but unbalanced state, free some
	//		memory and call balanceTree() to correct this.
	//
	//---------------------End of description of member function: removeNode.

	int 		found,
				side,
				i;

	GAvlNode	*returnNodePtr,
				*rightNodePtr,
				*leftNodePtr,
				*currentNodePtr,
				*nextNodePtr;

	BYTE	 	*returnDataPtr;

	errorCode = NO_ERROR;

	found = findNode(targetDataPtr);

	if (errorCode)
		goto Error;

	if (!found) {
		if (!errorCode)
			errorCode = DATA_NOT_FOUND;
		goto Error;
	}

	if (!(returnNodePtr = stack.pop(side))) {
		errorCode = SYS_ERROR;			// Should be impossible, but check
		goto Error; 					// just to be on the safe side.
	}

	rightNodePtr = returnNodePtr->rightTreePtr;
	leftNodePtr = returnNodePtr->leftTreePtr;

	returnNodePtr->leftTreePtr = returnNodePtr->rightTreePtr = NULL;

	currentNodePtr = stack.pop(side);	// If this returns NULL then
										// we know we are deleting the
										// root of the tree.

	if (currentNodePtr) {				// Deleting a normal node.
		if (side == RIGHT) {
			currentNodePtr->rightTreePtr = leftNodePtr;
			nextNodePtr = leftNodePtr;
		} else if (side == LEFT) {
			currentNodePtr->leftTreePtr = rightNodePtr;
			nextNodePtr = rightNodePtr;
		}
	} else {							// Deleting the root.
		if (rightNodePtr) {
			currentNodePtr = rightNodePtr;
			nextNodePtr = rightNodePtr->leftTreePtr;
			side = LEFT;
		} else if (leftNodePtr) {
			currentNodePtr = leftNodePtr;
			nextNodePtr = leftNodePtr->rightTreePtr; //NULL;
			side = RIGHT;
		} else {
			currentNodePtr = NULL;			// deleting last node in tree
			nextNodePtr = NULL;
			side = -1;
		}
	}

	while (nextNodePtr) {
		if ((!stack.push(currentNodePtr, side)))
			errorCode = stack.getErrorCode();

		if (side == RIGHT) {
			currentNodePtr = nextNodePtr;
			nextNodePtr = currentNodePtr->rightTreePtr;
		} else {
			currentNodePtr = nextNodePtr;
			nextNodePtr = currentNodePtr->leftTreePtr;
		}
		// This stage must be completed or the tree could be left in an
		// unlinked state. We must skip the balancing stage if an error has
		// occured here as the stack will not have been correctly created.
	}
	if (side != -1) {			// if not deleting last node in tree

		if ((!stack.push(currentNodePtr, side)))
			errorCode = stack.getErrorCode();

		if (side == RIGHT)
			currentNodePtr = currentNodePtr->rightTreePtr = rightNodePtr;
		else
			currentNodePtr = currentNodePtr->leftTreePtr = leftNodePtr;

		if (!errorCode) {
			errorCode =	climbStackAndBalance(currentNodePtr);
		} else
			errorCode = NOT_BALANCED;
	} else
		rootNodePtr = NULL;

	if (!(returnDataPtr = new BYTE(size))) {
		errorCode = NO_MEM;
		goto Error;
	}

	for (i = 0; i < size; i++)
		returnDataPtr[i] = returnNodePtr->dataPtr[i];

	delete returnNodePtr;
	numNodes--;

	return(returnDataPtr);

Error:
	stack.clear();
	return(NULL);
}

int GAvlTree::deleteNode(BYTE *targetDataPtr)
{
	// Description of member function: deleteNode:---------------------------
	//
	// Summary:
	//		This member function is used to remove a data item from the tree
	//		and delete it.
	//
	// Parameters:
	// 	BYTE *targetDataPtr -
	//		This is a pointer to a data item which will match the data item
	//		that should be deleted when compared using the compare function.
	//
	// Return value:
	//		This member function returns TRUE upon successful deletion and
	//		FALSE should the attempted deletion have failed for any reason.
	//
	// Functional description:
	// 		This member function calls the member function removeNode() to
	//		remove the node that matches the node pointed to by targetDataPtr
	//	 	from the tree. If the call to removeNode() returns NULL
	//		deleteNode() fails and returns FALSE. If removeNode() did return
	//		a data item then the data item is deleted and deleteNode()
	//		returns TRUE.
	//
	// Remarks:
	//		The member function getErrorCode() should be called after each
	//		call to deleteNode() as even after a successful call an error may
	//		have occurred during the call to removeNode(). If getErrorCode()
	//		reports an error after a successful call to deleteNode() then the
	//		tree will have been left in an unbalanced state, free some memory
	// 		and call balanceTree() to correct this.
	//
	//---------------------End of description of member function: deleteNode.

	BYTE	*deadDataPtr;

	if (!(deadDataPtr = removeNode(targetDataPtr)))
		return(FALSE);
	else {
		delete deadDataPtr;
		return(TRUE);
	}
}

int GAvlTree::getLeftDepth(GAvlNode *startNodePtr)
{
	// Description of member function: getLeftDepth:-------------------------
	//
	// Summary:
	//		This member function is used to determine the "depth" of the
	//		left sub-tree of the node supplied.
	//
	// Parameters:
	// 	BYTE *startNodePtr -
	//		This is a pointer to the node in the tree whos left sub-tree will
	//		be measured.
	//
	// Return value:
	//		The value returned is the "depth" of the left sub-tree of the
	//		node pointed to by the pointer startNodePtr.
	//
	// Functional description:
	//      This member function starts at the node supplied as a parameter
	//		and moves down the left side of the left sub-tree of the node
	//		counting the nodes as it descends.
	//
	// Remarks:
	//		None.
	//
	//-------------------End of description of member function: getLeftDepth.

	int 		depth = 0;
	GAvlNode	*tempNodePtr;

	if ((tempNodePtr = startNodePtr) == NULL)
		tempNodePtr = rootNodePtr;

	while (tempNodePtr->leftTreePtr) {
		depth++;
		tempNodePtr = tempNodePtr->leftTreePtr;
	}

	return(depth);
}

int GAvlTree::getRightDepth(GAvlNode *startNodePtr)
{
	// Description of member function: getRightDepth:------------------------
	//
	// Summary:
	//		This member function is used to determine the "depth" of the
	//		right sub-tree of the node supplied.
	//
	// Parameters:
	// 	BYTE *startNodePtr -
	//		This is a pointer to the node in the tree whos right sub-tree
	//		will be measured.
	//
	// Return value:
	//		The value returned is the "depth" of the right sub-tree of the
	//		node pointed to by the pointer startNodePtr.
	//
	// Functional description:
	//      This member function starts at the node supplied as a parameter
	//		and moves down the right side of the right sub-tree of the node
	//		counting the nodes as it descends.
	//
	// Remarks:
	//		None.
	//
	//------------------End of description of member function: getRightDepth.

	int 		depth = 0;
	GAvlNode	*tempNodePtr;

	if ((tempNodePtr = startNodePtr) == NULL)
		tempNodePtr = rootNodePtr;

	while (tempNodePtr->rightTreePtr) {
		depth++;
		tempNodePtr = tempNodePtr->rightTreePtr;
	}

	return(depth);
}

int GAvlTree::getMaxDepth(GAvlNode *startNodePtr)
{
	// Description of member function: getMaxDepth:--------------------------
	//
	// This member function starts at the node pointed to by startNodePtr and
	// works its way through all the nodes in both sub-trees and returns the
	// maximum depth reached.
	//
	// NOTE: Should be changed so that it isn't recursive and uses the stack.
	//
	//--------------------End of description of member function: getMaxDepth.

	int 		leftDepth = 0,
				rightDepth = 0;

	GAvlNode	*tempNodePtr;

	if ((tempNodePtr = startNodePtr) == NULL)
		tempNodePtr = rootNodePtr;

	if (tempNodePtr->leftTreePtr)
		leftDepth = 1 + getMaxDepth(tempNodePtr->leftTreePtr);

	if (tempNodePtr->rightTreePtr)
		rightDepth = 1 + getMaxDepth(tempNodePtr->rightTreePtr);

	if (rightDepth > leftDepth)
		return(rightDepth);
	else
		return(leftDepth);
}

static int stateList[3][4] = {  { 1, 2, 3, 4, },		// In order
								{ 2, 3, 1, 4, },        // Pre order
								{ 1, 3, 4, 2, } };      // Post order

int GAvlTree::initTraversal(int type, GAvlNode *startNodePtr)
{
	// Description of member function: initTraversal:------------------------
	//
	//
	//------------------End of description of member function: initTraversal.

	errorCode = NO_ERROR;

	if ((traversalNodePtr = startNodePtr) == NULL)
		traversalNodePtr = rootNodePtr;

	if (stack.notEmpty())
		if (!(stack.setStackBase()))
			errorCode = stack.getErrorCode();

	if (!errorCode) {
		traversalType = type;
		traversalStateFlag = stateList[traversalType][0];
		return(TRUE);
	}

	return(FALSE);
}

BYTE *GAvlTree::visitNextNode(void)
{
	// Description of member function: visitNextNode:------------------------
	//
	//
	//------------------End of description of member function: visitNextNode.

	int 	side;

	errorCode = NO_ERROR;

	if (!traversalNodePtr)
		return(NULL);

	for(EVER) {

		if (traversalStateFlag == 1) {
			if (traversalNodePtr->leftTreePtr) {
				if (!(stack.push(traversalNodePtr,LEFT))) {
					errorCode = stack.getErrorCode();
					return(NULL);
				}
				traversalNodePtr = traversalNodePtr->leftTreePtr;
				traversalStateFlag = stateList[traversalType][0];
			} else
				traversalStateFlag = stateList[traversalType][1];
		}

		if (traversalStateFlag == 2) {
			traversalStateFlag = stateList[traversalType][2];
			return(traversalNodePtr->dataPtr);
		}

		if (traversalStateFlag == 3) {
			if (traversalNodePtr->rightTreePtr) {
				if (!(stack.push(traversalNodePtr,RIGHT))) {
					errorCode = stack.getErrorCode();
					return(NULL);
				}
				traversalNodePtr = traversalNodePtr->rightTreePtr;
				traversalStateFlag = stateList[traversalType][0];
			} else
				traversalStateFlag = stateList[traversalType][3];
		}

		if (traversalStateFlag == 4) {
			if (!(traversalNodePtr = stack.pop(side)))
				return(NULL);

			if (side == LEFT)
				traversalStateFlag = stateList[traversalType][1];
			else
				traversalStateFlag = stateList[traversalType][3];
		}
	}
}

#ifdef GAVLTREE_DEBUG

int GAvlTree::initMapping(GAvlNode *startNodePtr, int &xPos, int &yPos)
{
	errorCode = NO_ERROR;

	if (startNodePtr == NULL)
		traversalNodePtr = rootNodePtr;
	else
		traversalNodePtr = startNodePtr;

	if (stack.notEmpty())
		if (!(stack.setStackBase()))
			errorCode = stack.getErrorCode();

	if (!errorCode) {
		traversalStateFlag = 1;
		maxDepth = getMaxDepth(traversalNodePtr);
		xPos = (2 * pow(2,maxDepth));
		yPos = 1;
		return(TRUE);
	}
	return(FALSE);
}

BYTE *GAvlTree::mapNextNode(int &xPos, int &yPos)
{
	errorCode = NO_ERROR;

	for(EVER) {

		if (traversalStateFlag == 1) {
			while(traversalNodePtr->leftTreePtr) {
				if (!(stack.push(traversalNodePtr,LEFT))) {
					errorCode = stack.getErrorCode();
					return(NULL);
				}
				traversalNodePtr = traversalNodePtr->leftTreePtr;
				yPos++;
				xPos = xPos - (2 * (pow(2,(maxDepth - yPos))));
			}
			traversalStateFlag = 2;
		}

		if (traversalStateFlag == 2) {
			traversalStateFlag = 3;
			return(traversalNodePtr->dataPtr);
		}

		if (traversalStateFlag == 3) {
			if (yPos == 1)
				xPos++;
			if (traversalNodePtr->rightTreePtr) {
				if (!(stack.push(traversalNodePtr,RIGHT))) {
					errorCode = stack.getErrorCode();
					return(NULL);
				}
				traversalNodePtr = traversalNodePtr->rightTreePtr;
				yPos++;
				xPos = xPos + (2 * (pow(2,(maxDepth - yPos))));
				traversalStateFlag = 1;
			} else
				traversalStateFlag = 4;
		}

		if (traversalStateFlag == 4) {
			int 	side;
			if (!(traversalNodePtr = stack.pop(side)))
				return(NULL);
			if (side == LEFT) {
				traversalStateFlag = 3;
				xPos = xPos + (2 * (pow(2,(maxDepth - yPos))));
				yPos--;
				if (yPos == 1)
					xPos--;
				return(traversalNodePtr->dataPtr);
			} else {
				xPos = xPos - (2 * (pow(2,(maxDepth - yPos))));
				yPos--;
				traversalStateFlag = 4;
			}
		}
	}
}

#endif //GAVLTREE_DEBUG

int GAvlTree::getErrorCode(void)
{
	int 	retValue = errorCode;

	errorCode = NO_ERROR;
	return(retValue);
}

//--------------------------------------------End of public member functions.

// Private member functions:-------------------------------------------------

int GAvlTree::findNode(BYTE *targetDataPtr)
{
	// Description of member function: findNode:-----------------------------
	//
	//-----------------------End of description of member function: findNode.

	int 		found = FALSE,
				compResult;
	GAvlNode	*currentNodePtr = rootNodePtr;

	errorCode = NO_ERROR;

	if (!currentNodePtr)
		return(FALSE);

	if (stack.notEmpty())
		if (!stack.setStackBase())
			errorCode = stack.getErrorCode();

	while (!found && !errorCode) {
		compResult = (*compareFncPtr)(targetDataPtr,currentNodePtr->dataPtr);
		if (compResult > 0) {
			if (!stack.push(currentNodePtr, RIGHT)) {
				errorCode = stack.getErrorCode();
				break;
			}
			if (currentNodePtr->rightTreePtr)
					currentNodePtr = currentNodePtr->rightTreePtr;
			else
				break;
		} else if (compResult < 0) {
			if (!stack.push(currentNodePtr, LEFT)) {
				errorCode = stack.getErrorCode();
				break;
			}
			if (currentNodePtr->leftTreePtr)
				currentNodePtr = currentNodePtr->leftTreePtr;
			else
				break;
		} else {
			if (!stack.push(currentNodePtr, 0)) {
				errorCode = stack.getErrorCode();
				break;
			} else
				found = TRUE;
		}
	}

	return(found);
}

int GAvlTree::climbStackAndBalance(GAvlNode *currentNodePtr)
{
	// Description of member function: climbStackAndBalance:-----------------
	//
	// NOTE: check for errors during the rotations, for each rotation you
	// push 5 or 6 nodes onto the stack, perhaps you should set up some of
	// these nodes before getting to this stage? either in the add or delete
	// stage, before it becomes irreversible. Maybe check the number of
	// nodes on the stack attempt to allocate the max number of required nodes
	// then start balancing?
	//
	//-----------End of description of member function: climbStackAndBalance.

	GAvlNode	*lastNodePtr = currentNodePtr;
	int         side,
				leftDepth,
				rightDepth,
				maxDepth;

	errorCode = NO_ERROR;

	while (stack.getNumStacks()) {

		currentNodePtr = stack.pop(side);	// no need to check for errors
											// only possible error is an
											// empty stack.
		while (side >= 0) {

			if (side == RIGHT || side == RIGHT_NOBALANCE)
				currentNodePtr->rightTreePtr = lastNodePtr;
			else if (side == LEFT || side == LEFT_NOBALANCE)
				currentNodePtr->leftTreePtr = lastNodePtr;

			if (side < 2) {
				rightDepth = getRightDepth(currentNodePtr);
				leftDepth = getLeftDepth(currentNodePtr);
				maxDepth = getMaxDepth(currentNodePtr);

				if (rightDepth - leftDepth > 1)
					currentNodePtr = rotate(currentNodePtr,LEFT);
				else if (leftDepth - rightDepth > 1)
					currentNodePtr = rotate(currentNodePtr,RIGHT);
				else if ((rightDepth > leftDepth) && (maxDepth > (rightDepth + leftDepth)))
					currentNodePtr = rotate(currentNodePtr,DOUBLE_LEFT);
				else if ((leftDepth > rightDepth) && (maxDepth > (leftDepth + rightDepth)))
					currentNodePtr = rotate(currentNodePtr,DOUBLE_RIGHT);
			}
			lastNodePtr = currentNodePtr;
			currentNodePtr = stack.pop(side);
		}
		if (stack.getNumStacks())
			lastNodePtr = stack.pop(side);
	}
	rootNodePtr = lastNodePtr;
	return(errorCode);
}

GAvlNode *GAvlTree::rotate(GAvlNode *currentNodePtr,int flag)
{
	// Description of member function: rotate:-------------------------------
	//
	//
	//-------------------------End of description of member function: rotate.

	GAvlNode	*lastNodePtr = currentNodePtr;

	switch (flag) {
		case RIGHT :
			currentNodePtr = currentNodePtr->rotateRight();
			break;
		case DOUBLE_RIGHT :
			currentNodePtr = currentNodePtr->doubleRotateRight();
			break;
		case LEFT :
			currentNodePtr = currentNodePtr->rotateLeft();
			break;
		case DOUBLE_LEFT :
			currentNodePtr = currentNodePtr->doubleRotateLeft();
			break;
	}
	if (lastNodePtr != currentNodePtr) {
		if (flag == RIGHT || flag == DOUBLE_RIGHT)
			currentNodePtr = setupStackRight(currentNodePtr, lastNodePtr);
		else if (flag == LEFT || flag == DOUBLE_LEFT)
			currentNodePtr = setupStackLeft(currentNodePtr, lastNodePtr);
	}
	return(currentNodePtr);
}

GAvlNode *GAvlTree::setupStackRight(GAvlNode *currentNodePtr, GAvlNode *lastNodePtr)
{
	// Need to make these two into one function and add error checking

	GAvlNode	*tempNodePtr;
	int			side;

	stack.push(currentNodePtr, RIGHT);
	tempNodePtr = lastNodePtr->rightTreePtr;
	side = RIGHT;
	if (!tempNodePtr) {
		tempNodePtr = lastNodePtr->leftTreePtr;
		side = LEFT;
	}
	stack.push(lastNodePtr, side);
	stack.push(tempNodePtr, side);

	stack.setStackBase();
	stack.push(currentNodePtr, LEFT_NOBALANCE);
	currentNodePtr = currentNodePtr->leftTreePtr;
	stack.push(currentNodePtr, LEFT);
	currentNodePtr = currentNodePtr->leftTreePtr;
	if (currentNodePtr) {
		stack.push(currentNodePtr, LEFT);
		currentNodePtr = currentNodePtr->leftTreePtr;
	}
	return(currentNodePtr);
}

GAvlNode *GAvlTree::setupStackLeft(GAvlNode *currentNodePtr, GAvlNode *lastNodePtr)
{
	GAvlNode	*tempNodePtr;
	int			side;

	stack.push(currentNodePtr, LEFT);
	tempNodePtr = lastNodePtr->leftTreePtr;
	side = LEFT;
	if (!tempNodePtr) {
		tempNodePtr = lastNodePtr->rightTreePtr;
		side = RIGHT;
	}
	stack.push(lastNodePtr, side);
	stack.push(tempNodePtr, side);

	stack.setStackBase();
	stack.push(currentNodePtr, RIGHT_NOBALANCE);
	currentNodePtr = currentNodePtr->rightTreePtr;
	stack.push(currentNodePtr, RIGHT);
	currentNodePtr = currentNodePtr->rightTreePtr;
	if (currentNodePtr) {
		stack.push(currentNodePtr, RIGHT);
		currentNodePtr = currentNodePtr->rightTreePtr;
	}
	return(currentNodePtr);
}

//-------------------------------------------End of private member functions.

//-------------------------------------------------End of file: GAVLTREE.CPP.

