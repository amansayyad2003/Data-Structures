
typedef struct node{
		int key;
		char balance_factor;
		struct node *left, *right, *parent;
}node;

typedef node *AVLTree;

void init_at(AVLTree *at);
void insert_at(AVLTree *at, int key);
int height_at(AVLTree at);
void remove_at(AVLTree *at);
void destroy_at(AVLTree *at);
void inorder(AVLTree at);
