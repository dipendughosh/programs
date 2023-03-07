// File: GAVLTREE.HPP:-------------------------------------------------------
//
// Classes to implement a generic, stack-based, self-balancing "AVL" binary
// search tree.
//
// (c) L.F. Holgate, May 1991.
//
//---------------------------------------------------------------------------

// Summary:------------------------------------------------------------------
//
// This file contains the classes GAvlTree and GAvlNode. These classes enable
// the creation of "generic" AVL binary search trees.
//
// Using the GAvlTree class you can create an AVL binary search tree for any
// type of data, you only have to supply a "comparison" function for the
// desired type and cast to and from pointers to BYTEs when adding and
// removing data.
//
// AVL trees, named after the Russians, Adel'son-Vel'skii and Landis, who
// first defined them, are height balanced binary search trees. To be
// considered an AVL tree a binary search tree must satisfy only one
// condition: for any node, the height of the left sub-tree and the height of
// the right sub-tree must differ by no more than one. As nodes are added and
// removed one or more node may lose the AVL property and need to be
// re-balanced. This can be achieved by applying one of four "rotations", for
// more details see GAVLNODE.CPP, this is far more efficient than having to
// reorganise the whole tree as you would to keep a binary tree perfectly
// balanced. In the worst case, a search for a specific node in an AVL tree
// will require 45% more comparisons than a perfectly balanced binary search
// tree. Whilst in the average case the additional comparisons required are
// negligable.
//
//------------------------------------------------------------End of summary.

#ifndef __GAVLTREE_HPP 	// This prevents the multiple inclusion of this file
#define __GAVLTREE_HPP	// in a module.

// Dependencies:-------------------------------------------------------------

#include "gavlstac.hpp"	// Needed for the GAvlStack class.

//-------------------------------------------------------End of dependencies.

// Macros:-------------------------------------------------------------------

#define EVER	;;			// For use in for loops, i.e. for(EVER).
#define FALSE 	0
#define TRUE  	1

#define NO_ERROR		0	// All OK
#define DATA_FOUND		1 	// Data found in tree
#define DATA_NOT_FOUND	2	// Data not found in tree
#define NO_MEM			3	// Memory allocation error
#define EMPTY_STACK		4	// Stack empty when it shouldn't be
#define NOT_BALANCED	5	// Tree left in unbalanced state
#define SYS_ERROR		6	// System error!

#define GAVLTREE_DEBUG		// include debug code...

//-------------------------------------------------------------End of macros.

// Enumerated constants:-----------------------------------------------------

enum { INORDER, PREORDER, POSTORDER }; 	// Used for initiating traversals.

//-----------------------------------------------End of enumerated constants.

// Typedefs:-----------------------------------------------------------------

typedef unsigned char BYTE;
typedef int (compareFnc) (BYTE *, BYTE *);

//-----------------------------------------------------------End of typedefs.

// Class definitions:--------------------------------------------------------

//extern class GAvlNode;	// Defined later in this file, but needed now.

// Class:GAvlNode:-----------------------------------------------------------

class GAvlNode {

	friend class GAvlTree;

	private:

		// Private data:-----------------------------------------------------

		int			errorCode;		// Used to identify errors.
		BYTE		*dataPtr;		// A pointer to the data item.
		GAvlNode  	*leftTreePtr,	// A pointer to the left sub-tree.
					*rightTreePtr;	// A pointer to the right sub-tree.

		//-----------------------------------------------End of private data.

	public:

		// Constructors:-----------------------------------------------------

		GAvlNode(BYTE *,int);

		//-----------------------------------------------End of constructors.

		// Public member functions:------------------------------------------

		int	getErrorCode(void);
		GAvlNode *rotateRight(void);
		GAvlNode *rotateLeft(void);
		GAvlNode *doubleRotateRight(void);
		GAvlNode *doubleRotateLeft(void);

		//------------------------------------End of public member functions.

		// Destructor:-------------------------------------------------------

		~GAvlNode(void);

		//-------------------------------------------------End of destructor.
};

//-----------------------------------------------------End of class:GAvlNode.


// Class:GAvlTree:-----------------------------------------------------------

// An overview of the GAvlTree class-----------------------------------------
//
// The GAvlTree class implements an AVL binary search tree.
//
// The constructor:
//
// GAvlTree -
//		The constructor for the GAvlTree class takes two parameters. The
//		first, an unsigned int, is the size of the data items to be stored in
//  	the tree. The second, a pointer to a function, is a pointer to the
//		function that is used during searches of the tree to compare items to
// 		each other. The compare function should take two pointers to BYTEs as
//		parameters and return an int. The function should return less than
//		zero if the data pointed to by the first parameter is "less" than the
//		data pointed to by the second parameter; zero if the data pointed to
//		by each pointer is "equal"; and more than zero if the data pointed to
//		by the first parameter is "more" than that pointed to by the second.
//		See the example below for a valid comparison function for use in a
//		tree of integers.
//
//				int compInt(BYTE *itemOne, BYTE *itemTwo)
//				{
//					return((*(int *)itemOne) - (*(int *)itemTwo));
//				}
//
// Public member functions:
//
// int addNode(BYTE *) -
//		This member function searches the tree for a data item that matches
//		the data item supplied. If the data item is found to be already in
//		the tree then addNode() fails. If the data item is not found to be in
//		the tree the data is added to the tree and the tree balanced as
//		necessary. The function returns TRUE if the data item is succesfully
//		added and FALSE if it fails for any reason. After all calls to
//		addNode()
//
// getNode -
//		This member function searches the tree for a match to data supplied
// 		and, if a match is found, returns a pointer to the data in the tree.
//		This data can be manipulated in any way as long as data used by the
//		comparison function is not changed - this could lead to the node
//		being located in the "wrong" place in the tree. Unlike removeNode()
//		the data remains in the tree. If the data is not found in the tree
//		getNode() returns NULL.
//
// removeNode -
//		This member function works in a similar way to getNode(). As with
// 		getNode() if the data is found in the tree a pointer to the data is
//		returned. The difference is that removeNode() does NOT leave the node
// 		in the tree. Like getNode(), removeNode() returns NULL if the data is
// 		not located.
//
// deleteNode -
//		This member function uses removeNode() to remove the node that
//		matches the data supplied from the tree. However, unlike removeNode()
//		deleteNode() does not return a pointer to the data. Instead, the data
//		is deleted and TRUE is returned. If the data is not located in the
//		tree then the function returns FALSE.
//
// The destructor:
//
// ~GAvlTree -
//
//		MAKE THIS NON DESTRUCTIVE TO THE DATA! OR SUPPLY A tree.clear()
//		function to remove all data before destroying the tree.
//
// Overloaded operators:
//
// The following operators have been overloaded to work specially for
// instances of the RingBuffer class.
//
//----------------------------------End of description of the GAvlTree class.

class GAvlTree {

	private:

		// Private data:-----------------------------------------------------

		int			size,				// The size of the type stored.
					numNodes,			// The number of nodes in the tree.
					errorCode,			// Used to identify errors.
					traversalType,     	// The type of traversal in progress.
					traversalStateFlag; // Current state of traversal.

		GAvlNode	*rootNodePtr,	 	// Pointer to the root of the tree.
					*traversalNodePtr;	// Pointer to the current node,
										// during a traversal.

		GAvlStack	stack;				// A stack for use during balancing
										// the tree etc.

		compareFnc	*compareFncPtr;		// A pointer to the function used to
										// compare nodes.

#ifdef GAVLTREE_DEBUG

		int			maxDepth;			// The maximum depth of the tree.

#endif	//GAVLTREE_DEBUG

		//-----------------------------------------------End of private data.

		// Private member functions:-----------------------------------------

		int findNode(BYTE *);
		int climbStackAndBalance(GAvlNode *);
		GAvlNode *rotate(GAvlNode *,int);
		GAvlNode *setupStackRight(GAvlNode *,GAvlNode *);
		GAvlNode *setupStackLeft(GAvlNode *,GAvlNode *);

		//-----------------------------------End of private member functions.

	public:

		// Constructor:------------------------------------------------------

		GAvlTree(unsigned int, compareFnc *);

		//------------------------------------------------End of constructor.

		// Public member functions:------------------------------------------

		int addNode(BYTE *);
		int deleteNode(BYTE *);
		BYTE *getNode(BYTE *);
		BYTE *removeNode(BYTE *);

		int initTraversal(int, GAvlNode *startNodePtr = NULL);
		BYTE *visitNextNode(void);

		int getRightDepth(GAvlNode *startNodePtr = NULL);
		int getLeftDepth(GAvlNode *startNodePtr = NULL);
		int getMaxDepth(GAvlNode *startNodePtr = NULL);

		inline int getNumNodes(void) {
			return (numNodes);
		};
		int getErrorCode(void);

#ifdef GAVLTREE_DEBUG

		int initMapping(GAvlNode *, int &, int &);
		BYTE *mapNextNode(int &, int &);

#endif	// GAVLTREE_DEBUG

		//------------------------------------End of public member functions.

		// Destructor:-------------------------------------------------------

		inline ~GAvlTree(void) {
			if (rootNodePtr)
				delete rootNodePtr;
		};

		//-------------------------------------------------End of destructor.
};

//-----------------------------------------------------End of class:GAvlTree.


//--------------------------------------------------End of class definitions.

#endif // __GAVLTREE_HPP

//--------------------------------------------------End of file:GAVLTREE.HPP.
