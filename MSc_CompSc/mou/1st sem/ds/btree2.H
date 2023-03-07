#include <stdio.h>
#include <stdlib.h>

struct tnode {
 int data;
 struct tnode *left;
 struct tnode *right;
};

/* insert, swap, search value, search minimum and search maximum values */
struct tnode *tnode_insert(struct tnode *p, int value);
struct tnode *tnode_swap(struct tnode *p);
struct tnode *tnode_search(struct tnode *p, int key);
struct tnode *tnode_searchmin(struct tnode *p);
struct tnode *tnode_searchmax(struct tnode *p);

/* destroy, count tree nodes */
void tnode_destroy(struct tnode *p);
int tnode_count(struct tnode *p);

/* print binary tree inorder, preorder, postorder [recursive] */
void print_inorder(struct tnode *p);
void print_preorder(struct tnode *p);
void print_postorder(struct tnode *p);

int main(void) {
 int demo_nr[] = {1, 3, 4, 7, 2, 9, 9, 0, 5, 6, 8, 7, 1, 2, 4};
 struct tnode *root = NULL; 
 struct tnode *searchval = NULL;
 int querry = 0;
 int i = 0;

 /* demo: insert some nr's into the binary tree */
 for(i = 0; i < 15; i++)
  root = tnode_insert(root, demo_nr[i]);

 printf("=-=-=\n");
 printf("Total number of tree nodes: %d\n", tnode_count(root));
 printf("inorder  : ");
 print_inorder(root);
 printf("\n");

 printf("preorder : ");
 print_preorder(root);
 printf("\n");

 printf("postorder: ");
 print_postorder(root);
 printf("\n");

 printf("=-=-=\n");
 printf("Enter integer, find: ");
 scanf("%d", &querry);
 searchval = tnode_search(root, querry);
 if(searchval == NULL)
  printf(" * %d Not! found in btree\n", querry);
 else
  printf(" * Found! %d in btree\n", searchval->data);

 searchval = NULL;
 printf("Searching for Minimum value\n");
 searchval = tnode_searchmin(root);
 if(searchval == NULL)
  printf(" * Minimum Not! found in btree ?\n");
 else
  printf(" * Found! minimum value %d in btree\n", searchval->data);

 searchval = NULL;
 printf("Searching for Maximum value\n");
 searchval = tnode_searchmax(root);
 if(searchval == NULL)
  printf(" * Maximum Not! found in btree ?\n");
 else
  printf(" * Found! Maximum value %d in btree\n", searchval->data);

 printf("=-=-=\n");
 printf("Exchanging all tree nodes: left <-> right\n");
 root = tnode_swap(root);

 printf("inorder  : ");
 print_inorder(root);
 printf("\n");

 printf("preorder : ");
 print_preorder(root);
 printf("\n");

 printf("postorder: ");
 print_postorder(root);
 printf("\n");

 printf("=-=-=\n");
 printf("Destroying btree... bye!\n");
 tnode_destroy(root);

 return 0;
}

/* insert a tnode into the binary tree */
struct tnode *tnode_insert(struct tnode *p, int value) {
 struct tnode *tmp_one = NULL;
 struct tnode *tmp_two = NULL;

 if(p == NULL) {
  /* insert [new] tnode as root node */
  p = (struct tnode *)malloc(sizeof(struct tnode));
  p->data = value;
  p->left = p->right = NULL;
 } else {
  tmp_one = p;
  /* Traverse the tree to get a pointer to the specific tnode */
  /* The child of this tnode will be the [new] tnode */
  while(tmp_one != NULL) {
   tmp_two = tmp_one;
   if(tmp_one ->data > value)
    tmp_one = tmp_one->left;
   else
    tmp_one = tmp_one->right;
  }

  if(tmp_two->data > value) {
   /* insert [new] tnode as left child */
   tmp_two->left = (struct tnode *)malloc(sizeof(struct tnode));
   tmp_two = tmp_two->left;
   tmp_two->data = value;
   tmp_two->left = tmp_two->right = NULL;
  } else {
   /* insert [new] tnode as left child */
   tmp_two->right = (struct tnode *)malloc(sizeof(struct tnode)); 
   tmp_two = tmp_two->right;
   tmp_two->data = value;
   tmp_two->left = tmp_two->right = NULL;
  }
 }

 return(p);
}

/* print binary tree inorder */
void print_inorder(struct tnode *p) {
 if(p != NULL) {
  print_inorder(p->left);
  printf("%d ", p->data);
  print_inorder(p->right);
 }
}

/* print binary tree preorder */
void print_preorder(struct tnode *p) {
 if(p != NULL) {
  printf("%d ", p->data);
  print_preorder(p->left);
  print_preorder(p->right);
 }
}

/* print binary tree postorder */
void print_postorder(struct tnode *p) {
 if(p != NULL) {
  print_postorder(p->left);
  print_postorder(p->right);
  printf("%d ", p->data);
 }
}

/* returns the total number of tree nodes */
int tnode_count(struct tnode *p) {
 if(p == NULL)
  return 0;
 else {
  if(p->left == NULL && p->right == NULL)
   return 1;
  else
   return(1 + (tnode_count(p->left) + tnode_count(p->right)));
 }
}

/* exchange all left and right tnodes */
struct tnode *tnode_swap(struct tnode *p) {
 struct tnode *tmp_one = NULL; 
 struct tnode *tmp_two = NULL;

 if(p != NULL) { 
  tmp_one = tnode_swap(p->left);
  tmp_two = tnode_swap(p->right);
  p->right = tmp_one;
  p->left  = tmp_two;
 }

 return(p);
}

/* locate a value in the btree */
struct tnode *tnode_search(struct tnode *p, int key) {
 struct tnode *temp;
 temp = p;

 while(temp != NULL) {
  if(temp->data == key)
   return temp;
  else if(temp->data > key)
   temp = temp->left;
  else
   temp = temp->right;
 }

 return NULL;
}

/* locate a minimum value in the btree */
struct tnode *tnode_searchmin(struct tnode *p) {
 if(p == NULL)
  return NULL;
 else
  if(p->left == NULL)
   return p;
  else
   return tnode_searchmin(p->left);
}

/* locate a maximum value in the btree */
struct tnode *tnode_searchmax(struct tnode *p) {
 if(p != NULL)
  while(p->right != NULL)
   p = p->right;

 return p;
}

/* destroy the binary tree */
void tnode_destroy(struct tnode *p) {
 if(p != NULL) {
  tnode_destroy(p->left);
  tnode_destroy(p->right);

  free(p);
 }
}
