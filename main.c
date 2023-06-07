#include <stdio.h>
#include "AVLTree.h"

int main(){
		AVLTree at;
		init_at(&at);
		insert_at(&at, 10);
		insert_at(&at, 20);
		insert_at(&at, 30);
		insert_at(&at, 40);
		insert_at(&at, 50);
		inorder(at);
		return 0;
}
