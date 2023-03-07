// File: GAVLSTAC.HPP:-------------------------------------------------------
//
// Classes to implement a generic, stack-based, self-balancing "AVL" binary
// search tree.
//
// (c) L.F. Holgate, May 1991.
//
//---------------------------------------------------------------------------

// Summary:------------------------------------------------------------------
//
// This file contains the classes GAvlStack and GAvlStackNode. These classes
// are used by the class GAvlTree to create a "stack" of GAvlNodes. The
// stack itself is actually a linked list which behaves like a stack. It was
// implemented in this way to allow for dynamic creation. This file is
// automatically included by the file GAVLTREE.HPP.
//
//------------------------------------------------------------End of summary.

#ifndef __GAVLSTAC_HPP 	// This prevents the multiple inclusion of this file
#define __GAVLSTAC_HPP	// in a module.

// Dependencies:-------------------------------------------------------------

#include <stdlib.h>		// Needed for NULL.

//-------------------------------------------------------End of dependencies.

// Enumerated constants:-----------------------------------------------------

enum { STACK_BASE = -2, STACK_EMPTY, LEFT, RIGHT,	// Used for stack
	   LEFT_NOBALANCE, RIGHT_NOBALANCE,				// manipulations.
	   DOUBLE_LEFT, DOUBLE_RIGHT };


//-----------------------------------------------End of enumerated constants.

// Class definitions:--------------------------------------------------------

class GAvlStackNode;	// Defined later in the file, but needed now.
class GAvlNode;

// Class:GAvlStack:----------------------------------------------------------

class GAvlStack {

	private:

		// Private data:-----------------------------------------------------

		int				numNodes,
						numStacks,
						errorCode;
		GAvlStackNode	*firstNodePtr;

		//-----------------------------------------------End of private data.

	public:

		// Constructor:------------------------------------------------------

		inline GAvlStack(void) {
			errorCode = numNodes = numStacks = 0;
			firstNodePtr = NULL;
		};

		//------------------------------------------------End of constructor.

		// Public member functions:------------------------------------------

		int push(GAvlNode *, int);
		GAvlNode *pop(int &);
		void clear(void);
		void clearAll(void);
		inline int notEmpty(void) {
			return(firstNodePtr != NULL);
		};
		inline int setStackBase(void) {
			return(push(NULL,STACK_BASE));
		};
		inline int getNumNodes(void) {
			return(numNodes);
		};
		inline int getNumStacks(void) {
			return(numStacks);
		};
		int getErrorCode(void);

		//------------------------------------End of public member functions.

		// Destructor:-------------------------------------------------------

		inline ~GAvlStack(void) {
			clear();
		};

		//-------------------------------------------------End of destructor.
};

//----------------------------------------------------End of class:GAvlStack.

// Class:GAvlStackNode:------------------------------------------------------

class GAvlStackNode {

	friend GAvlStack;

	private:

		// Private data:-----------------------------------------------------


		int				sideRef,
						errorCode;
		GAvlNode		*nodePtr;
		GAvlStackNode	*nextNodePtr;

		//-----------------------------------------------End of private data.

	public:

	// Constructor:----------------------------------------------------------

		inline GAvlStackNode(GAvlNode *newNodePtr, int newSideRef) {
			errorCode = 0;
			nodePtr = newNodePtr;
			nextNodePtr = NULL;
			sideRef = newSideRef;
		};
	//----------------------------------------------------End of constructor.

	// Public member functions:------------------------------------------

	int getErrorCode(void);

	//------------------------------------End of public member functions.
};

//------------------------------------------------End of class:GAvlStackNode.

//--------------------------------------------------End of class definitions.

#endif // __GAVLSTAC_HPP

//--------------------------------------------------End of file:GAVLSTAC.HPP.
