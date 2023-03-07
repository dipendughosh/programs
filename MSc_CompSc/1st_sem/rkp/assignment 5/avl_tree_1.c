
01.typedef int ElementType;
02. 
03.#ifndef _AvlTree_H
04.#define _AvlTree_H
05. 
06.struct AvlNode;
07.typedef struct AvlNode *Position;
08.typedef struct AvlNode *AvlTree;
09. 
10.AvlTree MakeEmpty( AvlTree T );
11.Position Find( ElementType X, AvlTree T );
12.Position FindMin( AvlTree T );
13.Position FindMax( AvlTree T );
14.AvlTree Insert( ElementType X, AvlTree T );
15.AvlTree Delete( ElementType X, AvlTree T );
16.ElementType Retrieve( Position P );
17. 
18.#endif
view source
print?
001.#include "avltree.h"
002.#include <stdlib.h>
003.#include "fatal.h"
004. 
005.struct AvlNode
006.{
007.    ElementType Element;
008.    AvlTree  Left;
009.    AvlTree  Right;
010.    int      Height;
011.};
012. 
013.AvlTree MakeEmpty( AvlTree T )
014.{
015.    if( T != NULL )
016.    {
017.        MakeEmpty( T->Left );
018.        MakeEmpty( T->Right );
019.        free( T );
020.    }
021.    return NULL;
022.}
023. 
024.Position Find( ElementType X, AvlTree T )
025.{
026.    if( T == NULL )
027.        return NULL;
028.    if( X < T->Element )
029.        return Find( X, T->Left );
030.    else
031.        if( X > T->Element )
032.            return Find( X, T->Right );
033.        else
034.            return T;
035.}
036. 
037.Position FindMin( AvlTree T )
038.{
039.    if( T == NULL )
040.        return NULL;
041.    else
042.        if( T->Left == NULL )
043.            return T;
044.        else
045.            return FindMin( T->Left );
046.}
047. 
048.Position FindMax( AvlTree T )
049.{
050.    if( T != NULL )
051.        while( T->Right != NULL )
052.            T = T->Right;
053. 
054.    return T;
055.}
056. 
057. 
058.static int Height( Position P )
059.{
060.    if( P == NULL )
061.        return -1;
062.    else
063.        return P->Height;
064.}
065. 
066. 
067.static int Max( int Lhs, int Rhs )
068.{
069.    return Lhs > Rhs ? Lhs : Rhs;
070.}
071. 
072. 
073./* This function can be called only if K2 has a left child */
074./* Perform a rotate between a node (K2) and its left child */
075./* Update heights, then return new root */
076. 
077.static Position SingleRotateWithLeft( Position K2 )
078.{
079.    Position K1;
080. 
081.    K1 = K2->Left;
082.    K2->Left = K1->Right;
083.    K1->Right = K2;
084. 
085.    K2->Height = Max( Height( K2->Left ), Height( K2->Right ) ) + 1;
086.    K1->Height = Max( Height( K1->Left ), K2->Height ) + 1;
087. 
088.    return K1;  /* New root */
089.}
090. 
091. 
092./* This function can be called only if K1 has a right child */
093./* Perform a rotate between a node (K1) and its right child */
094./* Update heights, then return new root */
095. 
096.static Position SingleRotateWithRight( Position K1 )
097.{
098.    Position K2;
099. 
100.    K2 = K1->Right;
101.    K1->Right = K2->Left;
102.    K2->Left = K1;
103. 
104.    K1->Height = Max( Height( K1->Left ), Height( K1->Right ) ) + 1;
105.    K2->Height = Max( Height( K2->Right ), K1->Height ) + 1;
106. 
107.    return K2;  /* New root */
108.}
109. 
110. 
111./* This function can be called only if K3 has a left */
112./* child and K3's left child has a right child */
113./* Do the left-right double rotation */
114./* Update heights, then return new root */
115. 
116.static Position DoubleRotateWithLeft( Position K3 )
117.{
118.    /* Rotate between K1 and K2 */
119.    K3->Left = SingleRotateWithRight( K3->Left );
120. 
121.    /* Rotate between K3 and K2 */
122.    return SingleRotateWithLeft( K3 );
123.}
124. 
125. 
126./* This function can be called only if K1 has a right */
127./* child and K1's right child has a left child */
128./* Do the right-left double rotation */
129./* Update heights, then return new root */
130. 
131.static Position DoubleRotateWithRight( Position K1 )
132.{
133.    /* Rotate between K3 and K2 */
134.    K1->Right = SingleRotateWithLeft( K1->Right );
135. 
136.    /* Rotate between K1 and K2 */
137.    return SingleRotateWithRight( K1 );
138.}
139. 
140. 
141. 
142.AvlTree Insert( ElementType X, AvlTree T )
143.{
144.    if( T == NULL )
145.    {
146.        /* Create and return a one-node tree */
147.        T = malloc( sizeof( struct AvlNode ) );
148.        if( T == NULL )
149.            FatalError( "Out of space!!!" );
150.        else
151.        {
152.            T->Element = X; T->Height = 0;
153.            T->Left = T->Right = NULL;
154.        }
155.    }
156.    else
157.        if( X < T->Element )
158.        {
159.            T->Left = Insert( X, T->Left );
160.            if( Height( T->Left ) - Height( T->Right ) == 2 )
161.                if( X < T->Left->Element )
162.                    T = SingleRotateWithLeft( T );
163.                else
164.                    T = DoubleRotateWithLeft( T );
165.        }
166.        else
167.            if( X > T->Element )
168.            {
169.                T->Right = Insert( X, T->Right );
170.                if( Height( T->Right ) - Height( T->Left ) == 2 )
171.                    if( X > T->Right->Element )
172.                        T = SingleRotateWithRight( T );
173.                    else
174.                        T = DoubleRotateWithRight( T );
175.            }
176.            /* Else X is in the tree already; we'll do nothing */
177. 
178.            T->Height = Max( Height( T->Left ), Height( T->Right ) ) + 1;
179.            return T;
180.}
181. 
182. 
183.AvlTree Delete( ElementType X, AvlTree T )
184.{
185.    printf( "Sorry; Delete is unimplemented; %d remains\n", X );
186.    return T;
187.}
188. 
189.ElementType Retrieve( Position P )
190.{
191.    return P->Element;
192.}
view source
print?
01.#include "avltree.h"
02.#include <stdio.h>
03. 
04.main()
05.{
06.    AvlTree T;
07.    Position P;
08.    int i;
09.    int j = 0;
10. 
11.    T = MakeEmpty( NULL );
12.    for( i = 0; i < 50; i++, j = ( j + 7 ) % 50 )
13.        T = Insert( j, T );
14.    for( i = 0; i < 50; i++ )
15.        if( ( P = Find( i, T ) ) == NULL || Retrieve( P ) != i )
16.            printf( "Error at %d\n", i );
17. 
18.    /* for( i = 0; i < 50; i += 2 )
19.    T = Delete( i, T );
20. 
21.    for( i = 1; i < 50; i += 2 )
22.    if( ( P = Find( i, T ) ) == NULL || Retrieve( P ) != i )
23.    printf( "Error at %d\n", i );
24.    for( i = 0; i < 50; i += 2 )
25.    if( ( P = Find( i, T ) ) != NULL )
26.    printf( "Error at %d\n", i );
27.    */
28.    printf( "Min is %d, Max is %d\n", Retrieve( FindMin( T ) ),
29.        Retrieve( FindMax( T ) ) );
30. 
31.    return 0;
32.}