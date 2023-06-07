#include <stdio.h>
#include <stdlib.h>
#include "helping_function.h"

#ifndef AVLTREE
#include "AVLTree.h"
#endif

void init_at(AVLTree *at){
		(*at) = NULL;
		return;
}


void insert_at(AVLTree *at, int key){
		node *temp = (node*)malloc(sizeof(node));
		if(!temp)
				return;
		temp->key = key;
		temp->balance_factor = 0;
		temp->left = temp->right = temp->parent = NULL;

		if(!(*at)){
				(*at) = temp;
				return;
		}

		node *t1, *previous = NULL;
		t1 = (*at);
		while(t1){
				previous = t1;
				if(key == t1->key){
						free(temp);
						return;
				}
				else if(key > t1->key)
						t1 = t1->right;
				else
						t1 = t1->left;
		}
		if(key > previous->key){
				previous->right = temp;
				temp->parent = previous;
		}
		else{
				previous->left = temp;
				temp->parent = previous;
		}

		node *imbalance_node = adjust_bf(previous);

		if(imbalance_node == NULL){
				return;
		}

		printf("Imbalance at node: %d\n", imbalance_node->key);
		// determine type of rotation and do coresponding rotation
		if(temp->key > imbalance_node->key){
				if(temp->key > imbalance_node->right->key){
						// do RR rotation
						printf("RR imbalance\n");
						RRrotate(at, imbalance_node);
				}
				else{
						//do RL rotation
						printf("RL imbalance\n");
						//RLrotate(at, imbalance_node);
				}
		}
		else{
				if(temp->key > imbalance_node->left->key){
						// do LL rotation
						printf("LL imbalance\n");
						LLrotate(at, imbalance_node);
				}
				else{
						// do LR rotation
						printf("LR imbalance\n");
						//LRrotate(at, imbalance_node);
				}
		}
		return;

}

void LRrotate(AVLTree *at, node *A){}
void RLrotate(AVLTree *at, node *A){}
void LLrotate(AVLTree *at, node *A){
		node *Ap = A->parent;
		node *B = A->left;
		node *Br = B->right;
		B->right = A;
		A->parent = B;
		B->parent = Ap;
		if(Ap == NULL){
				*at = B;
		}
		else{
				if(Ap->left == A){
						Ap->left = B;
				}
				else{
						Ap->right = B;
				}
		}
		A->left = Br;
		if(Br){
				Br->parent = A;
		}
		A->balance_factor = 0;
		B->balance_factor = 0;
		return;
}

void RRrotate(AVLTree *at, node *A){
		node *Ap = A->parent;
		node *B = A->right;
		node *Bl = B->left;
		B->left = A;
		A->parent = B;
		B->parent = Ap;
		if(Ap == NULL){
				*at = B;
		}
		else{
				if(Ap->left == A){
						Ap->left = B;
				}
				else{
						Ap->right = B;
				}
		}
		A->right = Bl;
		if(Bl){
				Bl->parent = A;
		}
		A->balance_factor = 0;
		B->balance_factor = 0;
		return;
}

		

node *adjust_bf(AVLTree t){
		node *temp = NULL;
		int flag = 0;
		while(t){
				t->balance_factor = height(t->left) - height(t->right);
				if((t->balance_factor > 1 || t->balance_factor < -1) && flag == 0){
						temp = t;
						flag = 1;
				}
				t = t->parent;
		}
		return temp;
}

int height(node *t){
		if(!t)
				return -1;
		return 1 + max(height(t->left), height(t->right));
}

int max(int num1, int num2){
		if(num1 > num2)
				return num1;
		else 
				return num2;
}
		
void inorder(AVLTree t){
		if(!t)
				return;
		inorder(t->left);
		if(t->parent == NULL){
				printf("%d -> parent: NULL\n", t->key);
		}
		else{
				printf("%d -> parent: %d\n", t->key, t->parent->key);
		}
		inorder(t->right);
		return;
}

		
					





