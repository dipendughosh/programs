// File: GAVLSTAC.CPP:-------------------------------------------------------
//
// Implementation of the GAvlStack and GAvlStackNode classes. These form a
// dynamically allocated "stack" which is used by the GAvlTree class.
//
// (c) L.F. Holgate, May 1991.
//
//---------------------------------------------------------------------------

// Contents:-----------------------------------------------------------------
//
// This file contains the following:
//
// Public member functions for the GAvlStack class:
//		int push(GAvlNode *, int), GAvlNode *pop(int &), void clear(void),
//		void clearAll(void), int getErrorCode(void).
//
// Public member functions for the GAvlStackNode class:
//		int getErrorCode(void).
//
//-----------------------------------------------------------End of contents.

// Dependencies:-------------------------------------------------------------

#include "gavltree.hpp"

//-------------------------------------------------------End of dependencies.

// Public member functions for GAvlStack class:------------------------------

int GAvlStack::push(GAvlNode *pushedNodePtr, int side)
{
	GAvlStackNode  *newNodePtr;

	errorCode = NO_ERROR;

	if (!(newNodePtr = new GAvlStackNode(pushedNodePtr,side)))
		errorCode = NO_MEM;
	else {
		errorCode = newNodePtr->getErrorCode();
			if (errorCode)
				delete newNodePtr;
	}
	if (!errorCode) {

		numNodes++;

		if (side == STACK_BASE)
			numStacks++;

		if (!firstNodePtr) {
			firstNodePtr = newNodePtr;
			numStacks++;
		} else {
			newNodePtr->nextNodePtr = firstNodePtr;
			firstNodePtr = newNodePtr;
		}
	}
	if (!errorCode)
		return(TRUE);
	else
		return(FALSE);
}

GAvlNode *GAvlStack::pop(int &side)
{
	errorCode = NO_ERROR;

	if (!firstNodePtr) {
		errorCode = EMPTY_STACK;
		side = STACK_EMPTY;		// definate error condition.
		return(NULL);
	}

	GAvlStackNode 	*oldNodePtr = firstNodePtr;
	GAvlNode 		*poppedNodePtr;

	poppedNodePtr = oldNodePtr->nodePtr;
	side = oldNodePtr->sideRef;
	firstNodePtr = oldNodePtr->nextNodePtr;

	delete oldNodePtr;

	numNodes--;
	if (side == STACK_BASE || !firstNodePtr)
		numStacks--;
	return(poppedNodePtr);
}

void GAvlStack::clear(void)
{
	int flag;

	do
		pop(flag);
	while (flag >= 0);
}

void GAvlStack::clearAll(void)
{
	int notUsed;

	while (notEmpty())
		pop(notUsed);
}

int GAvlStack::getErrorCode(void)
{
	int 	retValue = errorCode;

	errorCode = NO_ERROR;
	return(retValue);
}

//------------------------End of public member functions for GAvlStack class.

// Public member functions for GAvlStackNode class:--------------------------

int GAvlStackNode::getErrorCode(void)
{
	int 	retValue = errorCode;

	errorCode = NO_ERROR;
	return(retValue);
}

//--------------------End of public member functions for GAvlStackNode class.

//-------------------------------------------------End of file: GAVLSTAC.CPP.
