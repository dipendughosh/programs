// File: GAVLNODE.CPP:-------------------------------------------------------
//
// Implementation of the GAvlNode class, the nodes of a generic, stack-based,
// self-balancing "AVL" binary search tree.
//
// (c) L.F. Holgate, May 1991.
//
//---------------------------------------------------------------------------

// Contents:-----------------------------------------------------------------
//
// This file contains the following:
//
// Constructor for the GAvlNode class:
//		GAvlNode(BYTE *,int).
//
// Public member functions for the GAvlNode class:
//		int getErrorCode(void), GAvlNode *rotateLeft(void),
//		GAvlNode *doubleRotateLeft(void), GAvlNode *rotateRight(void),
//		GAvlNode *doubleRotateRight(void).
//
// Destructor for the GAvlNode class:
//		~GAvlNode(void).
//
//-----------------------------------------------------------End of contents.

// Dependencies:-------------------------------------------------------------

#include "gavltree.hpp"

#ifdef GAVLTREE_DEBUG

#include "stdio.h"		// needed for printf()

#endif //GAVLTREE_DEBUG

//-------------------------------------------------------End of dependencies.

// Constructor:--------------------------------------------------------------

GAvlNode::GAvlNode(BYTE *newDataPtr,int size)
{
	errorCode = NO_ERROR;	// reset error code

	if (!(dataPtr = new BYTE[size]))
		errorCode = NO_MEM;

	if (!errorCode) {
		for (int i = 0; i < size; i++)
			dataPtr[i] = newDataPtr[i];

		leftTreePtr = rightTreePtr = NULL;
	}
}

//--------------------------------------------------------End of constructor.

// Public member functions:--------------------------------------------------

int GAvlNode::getErrorCode(void)
{
	int 	retValue = errorCode;

	errorCode = NO_ERROR;
	return(retValue);
}

GAvlNode *GAvlNode::rotateLeft(void)
{
	// If this function were to be applied to node "a" in the diagram below,
	// it would return node "b", with it's leftTreePtr and rightTreePtr set
	// as shown.
	//	 a
	//    \			 b
	//		b	=	/ \
	//     	 \     a   c
	//        c

#ifdef GAVLTREE_DEBUG

	printf("Rotate Left\n");

#endif //GAVLTREE_DEBUG

	GAvlNode *tempTreePtr = rightTreePtr;

	rightTreePtr = tempTreePtr->leftTreePtr;
	tempTreePtr->leftTreePtr = this;

	return(tempTreePtr);
}

GAvlNode *GAvlNode::doubleRotateLeft(void)
{
	// If this function were to be applied to node "a" in the diagram below,
	// it would return node "b", with it's leftTreePtr and rightTreePtr set
	// as shown.
	//	 a
	//    \			 b
	//		c	=	/ \
	//     /       a   c
	//    b

#ifdef GAVLTREE_DEBUG

	printf("Double Rotate Left\n");

#endif //GAVLTREE_DEBUG

	if (!rightTreePtr)
		return(this);	// cant do it to this node.

	if (!rightTreePtr->leftTreePtr)
		return(this);

	GAvlNode *tempTreePtr = rightTreePtr->leftTreePtr;

	rightTreePtr->leftTreePtr = tempTreePtr->rightTreePtr;
	tempTreePtr->rightTreePtr = rightTreePtr;
	rightTreePtr = tempTreePtr->leftTreePtr;
	tempTreePtr->leftTreePtr = this;

	return(tempTreePtr);
}

GAvlNode *GAvlNode::rotateRight(void)
{
	// If this function were to be applied to node "c" in the diagram below,
	// it would return node "b", with it's leftTreePtr and rightTreePtr set
	// as shown.
	//		  c
	//       /		 b
	//		b	=	/ \
	//     /       a   c
	//    a

#ifdef GAVLTREE_DEBUG

	printf("Rotate Right\n");

#endif //GAVLTREE_DEBUG

	GAvlNode *tempTreePtr = leftTreePtr;

	leftTreePtr = tempTreePtr->rightTreePtr;
	tempTreePtr->rightTreePtr = this;

	return(tempTreePtr);
}

GAvlNode *GAvlNode::doubleRotateRight(void)
{
	// If this function were to be applied to node "c" in the diagram below,
	// it would return node "b", with it's leftTreePtr and rightTreePtr set
	// as shown.
	//		  c
	//       /		 b
	//		a	=	/ \
	//       \     a   c
	//        b

#ifdef GAVLTREE_DEBUG

	printf("Double Rotate Right\n");

#endif //GAVLTREE_DEBUG

	if (!leftTreePtr)
		return(this);

	if (!leftTreePtr->rightTreePtr)
		return(this);

	GAvlNode *tempTreePtr = leftTreePtr->rightTreePtr;

	leftTreePtr->rightTreePtr = tempTreePtr->leftTreePtr;
	tempTreePtr->leftTreePtr = leftTreePtr;
	leftTreePtr = tempTreePtr->rightTreePtr;
	tempTreePtr->rightTreePtr = this;

	return(tempTreePtr);
}

//--------------------------------------------End of public member functions.

// Destructor:---------------------------------------------------------------

GAvlNode::~GAvlNode(void)
{
	if (dataPtr)
		delete dataPtr;

	if (leftTreePtr)
		delete leftTreePtr;

	if (rightTreePtr)
		delete rightTreePtr;
}

//---------------------------------------------------------End of destructor.

//-------------------------------------------------End of file: GAVLNODE.CPP.
