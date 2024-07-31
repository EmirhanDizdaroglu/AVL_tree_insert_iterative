#include <stdio.h>
#include <stdlib.h>

typedef struct NODE_s *NODE;
typedef struct NODE_s {
    NODE left;
    NODE right;
    int bFactor;
    void *data;
    int key;
    int height;

} NODE_t[1];

typedef struct{
    NODE root;
} BST_t[1], *BST;

BST bst_init(){
    BST tree = (BST)malloc(sizeof(BST_t));
    tree->root = NULL;
    return tree;
}

int max(int a, int b){
    if(a<b)
        return b;
    return a;
}
int avlHeight(NODE node) {
    if (node == NULL)
        return 0;
    node->height= max(avlHeight(node->left), avlHeight(node->right)) + 1;//en buyuk olana 1 ekliyor
    return node->height;
}
int balancedFactor(NODE node) {
    if (node == NULL)
        return 0;
    return (avlHeight(node->left) - avlHeight(node->right));
}
NODE bst_init_node(int key, void *data){
    NODE node = (NODE)malloc(sizeof(NODE_t));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    node->key = key;
    node->height=1;
    return node;
}

NODE right_rotation(NODE node) {
    NODE left_child = node->left;
    NODE right_of_left_child = left_child->right;

    left_child->right = node;
    node->left = right_of_left_child;

    // Update heights
    node->height = max(avlHeight(node->left), avlHeight(node->right)) + 1;
    left_child->height = max(avlHeight(left_child->left), avlHeight(left_child->right)) + 1;

    return left_child;
}

NODE left_rotation(NODE node) {
    NODE right_child = node->right;
    NODE left_of_right_child = right_child->left;

    right_child->left = node;
    node->right = left_of_right_child;

    // Update heights
    node->height = max(avlHeight(node->left), avlHeight(node->right)) + 1;
    right_child->height = max(avlHeight(right_child->left), avlHeight(right_child->right)) + 1;

    return right_child;
}

NODE bst_insert_rec2(NODE node, int key, void *data){ //better
    if(node == NULL){
        node = bst_init_node(key, data);
    }
    else{
        if(key < node->key){
            node->left = bst_insert_rec2(node->left, key, data);
        }
        else if(key > node->key){
            node->right = bst_insert_rec2(node->right, key, data);
        }
        else{
            printf("ERROR: Duplicate key!!!\n");
            return node;
        }

        node->height= max(avlHeight(node->left), avlHeight(node->right))+1;
        int balance = balancedFactor(node);

        if (balance > 1 && key < node->left->key) {
            return right_rotation(node); // LL case
        }
        if (balance > 1 && key > node->left->key) {
            node->left = left_rotation(node->left);
            return right_rotation(node); // LR case
        }
        if (balance < -1 && key > node->right->key) {
            return left_rotation(node); // RR case
        }
        if (balance < -1 && key < node->right->key) {
            node->right = right_rotation(node->right);
            return left_rotation(node); // RL case
        }}

        return node;
    }
void bst_traverse_inorder(NODE node){
    if(node != NULL){
        bst_traverse_inorder(node->left);
        printf("%d ", node->key);
        bst_traverse_inorder(node->right);
    }
}


void printTree(NODE node,int l){

    if(node!=NULL){
        printTree(node->right,l+1);
        for(int i=0;i<l;i++) {
            printf("     ");
        }
        int height= avlHeight(node);
        int balance= balancedFactor(node);
        printf("%d (%d)(%d)",node->key,height,balance);
        printf(" \n");
        printTree(node->left,l+1);
    }
}

int main() {
    BST tree= bst_init();
    tree->root = bst_insert_rec2(tree->root, 50, NULL);
    tree->root = bst_insert_rec2(tree->root, 25, NULL);
    tree->root = bst_insert_rec2(tree->root, 75, NULL);
    tree->root = bst_insert_rec2(tree->root, 10, NULL);
    tree->root = bst_insert_rec2(tree->root, 31, NULL);
    tree->root = bst_insert_rec2(tree->root, 13, NULL);
    tree->root = bst_insert_rec2(tree->root, 69, NULL);
    tree->root = bst_insert_rec2(tree->root, 90, NULL);
    tree->root = bst_insert_rec2(tree->root, 62, NULL);
    tree->root = bst_insert_rec2(tree->root, 24, NULL);
    tree->root = bst_insert_rec2(tree->root, 78, NULL);
    bst_traverse_inorder(tree->root);
    printTree(tree->root,0);
    return 0;
}
