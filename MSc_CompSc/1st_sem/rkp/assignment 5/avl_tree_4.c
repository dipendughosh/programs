
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174
175
176
177
178
179
180
181
182
183
184
185
186
187
188
189
190
191
192
193
194
195
196
197
198
199
200
201
202
203
204
205
206
207
208
209
210
211
212
213
214
215
216
217
218
219
220
221
222
223
224
225
226
227
228
229
230
231
232
233
234
235
236
237
238
239
240
241
242
243
244
245
246
247
248
249
250
251
252
253
254
255
256
257
258
259
260
261
262
263
264
265
266
267
268
269
270
271
272
273
274
275
276
277
278
279
280
281
282
283
284
285
286
287
288
289
290
291
292
293
294
295
296

	

/***************************************************************************
 *   Copyright (C) 2005 by senu                                            *
 *   senu@o2.pl                                                            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include <cstdio>
#include "avltree.h"
//-------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------- 
AVL_Tree::AVL_Tree()
{
	size=0;
	
	root=NULL;
/*	root->left=NULL;
	root->right=NULL;	
	root->parent=NULL;*/
}
//-------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------- 
element AVL_Tree::find(int key)
{
	if(size==0)
		return NULL;
	tmp=root;
	while(tmp!=NULL)
	{
		if(key<tmp->key)
			tmp=tmp->left;
		else if(key>tmp->key)
			tmp=tmp->right;
		else 
			return tmp->data;
	}
	return NULL;
}
//-------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------- 
inline int AVL_Tree::height( AVL_Node * pos ) const
{
    	if( pos == NULL )
      	return -1;
    	else
    		return pos->factor;
}
//-------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------- 
inline int AVL_Tree::max( int a, int b ) const
{
  	return a > b ? a : b;
}
//-------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------- 
AVL_Node * AVL_Tree::singleRotateLeft(AVL_Node *K2)
{
	K1 = K2->left;
	K2->left = K1->right;
	K1->right = K2;
	
	K2->factor = max(height(K2->left), height(K2->right))+1;
    	K1->factor = max(height(K1->left), K2->factor)+1;

           
	return K1;  // new root
}   
//-------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------- 
AVL_Node * AVL_Tree::singleRotateRight(AVL_Node *K1)
{
	K2 = K1->right;
	K1->right = K2->left;
	K2->left = K1;
	
	K1->factor = max(height(K1->left), height(K1->right))+1;
    	K2->factor = max(height(K2->right), K1->factor)+1;

           
	return K2;  // new root
}   
//-------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------- 
AVL_Node * AVL_Tree::doubleRotateLeft(AVL_Node *K3)
{
	K3->left = singleRotateRight(K3->left);
           
	return singleRotateLeft(K3);
}   
//-------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------- 
AVL_Node * AVL_Tree::doubleRotateRight(AVL_Node *K1)
{
	K1->right = singleRotateLeft(K1->right);
           
	return singleRotateRight(K1);
}   
//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------     
void AVL_Tree::insert(int key, cUser * data)
{
	size++;
	tmpdata=data;
	root=_insert(key,root);
}     
//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------     
AVL_Node * AVL_Tree::_insert(int key, AVL_Node * node)
{
	if (node==NULL)
	{
		node = new AVL_Node;
		node->factor=0;
		node->key=key;
		node->data=tmpdata;
		node->left=NULL;
		node->right=NULL;
// 		if(size==1)
// 			root=node;
	
	}
	else if(key < node->key)
	{
		node->left= _insert(key,node->left);
		if(height(node->left) - height(node->right) == 2)
		{
			if(key < node->left->key)
				node = singleRotateLeft(node);
			else
				node = doubleRotateLeft(node);
		}
 	}		 
	else if(key > node->key)		
	{
		node->right= _insert(key,node->right);
		if(height(node->right) - height(node->left) == 2)
		{
			if(key > node->right->key)
				node = singleRotateRight(node);
			else				
				node = doubleRotateRight(node);			
		}
 	}	 
		 
		 
		 
// 	node->factor=-1;		 
// 	if(node->left!=NULL)
// 		node->factor=node->left->factor;
// 	if(node->right!=NULL)
// 		node->factor=max(node->factor, node->right->factor);	

  	node->factor = max(height(node->left ),height(node->right))+1;
	return node;

}
//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------     
void AVL_Tree::erase(int key)
{
	root=_erase(key,root);
}
//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
AVL_Node * AVL_Tree::_erase(int key, AVL_Node * node)
{
	bool done=false;
	if (node==NULL) 
	{   
		h=false;  
		done=true;
	}
	else
	if (key < node->key) //delee from left subtree	
	{
		newnode=_erase(key,node->left);
		node->left=newnode;
		if(h)
		{
			if(height(node->right) - height(node->left) == 2)
			{
				if(height(node->right) > height(node->left))
					node = singleRotateLeft(node);
				else				
					node = singleRotateRight(node);			
			}
			
			node->factor = max(height(node->left ),height(node->right))+1;
		
		
// 			if (node->factor >= 0)
//          		{
//          		   node->factor=root->factor-1;
//             	   if (node->factor==-1)
//             	   		h=false;
//          		}
//          		else if (node->right->factor==-1)
//          			singleRotateRight(node); 
//          		else 
//          			singleRotateLeft(node);         			
         			
         		done=true;		
         		return node;
		}
		
	
	}
	else if (key == node->key) //del node
	{
	  	if (node->left==NULL || node->right==NULL)  // one or no children 
      	{
      		if (node->left == NULL) 
      			K1=node->right;
      		else 
      			K1=node->left;
      			
      		delete node;
      		
      		h=true; done=true;
      		
      		return(K1);     		      		
      	
      	}
      	else // both of children
      	{
      	 	K2=node->right;
         		while (K2->left != NULL) 
         			K2=K2->left;
         			
         		node->key=K2->key;
         		key=node->key;
		}
	}
	
	if (!done && key >= node->key) // delete from right subtree 
	{
         	newnode=_erase(key, node->right);
         	node->right=newnode;
      	if (h)
      	{       		
         		if(height(node->right) - height(node->left) == 2)
			{
				if(height(node->right) > height(node->left))
					node = singleRotateLeft(node);
				else				
					node = singleRotateRight(node);			
			}
			node->factor = max(height(node->left ),height(node->right))+1;
         		//
/*         		if (node->factor <= 0) 
         		{
            		node->factor=node->factor+1;
            		if (node->factor ==1) 
            			h=false;
         		}	
         		else if (node->right->factor==1) 
         		 	singleRotateLeft(node);
         		else          		
         	     	singleRotateRight(node);*/
         	     return node;
         	}
	}
	
	
}
//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------     
void AVL_Tree::dfs()
{
	_dfs(root);
}
//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------     
void AVL_Tree::_dfs(AVL_Node * v) const
{
	// DO WHAT U WANNA eg printf data->name or sth
		
	if(v->left!=NULL)
		_dfs(v->left);
	if(v->right!=NULL)
		_dfs(v->right);	
}
//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------     


