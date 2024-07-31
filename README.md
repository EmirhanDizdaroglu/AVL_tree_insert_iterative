# AVL Tree Implementation in C

## Overview

This C program implements an AVL Tree, a self-balancing binary search tree. AVL Trees maintain a balance factor of -1, 0, or 1 for each node, ensuring that the tree remains balanced and operations like insertion, deletion, and search are performed in O(log n) time complexity.

## Features

- **AVL Tree Structure**: Defines an AVL Tree with nodes that include left and right children, balance factor, height, and key.
- **Dynamic Node Insertion**: Inserts nodes while maintaining the AVL balance property.
- **Rotations**: Implements right and left rotations to maintain balance during insertions.
- **Traversal**: Provides in-order traversal to print keys.
- **Visual Representation**: Includes a function to print the tree structure with heights and balance factors.

## Functions

### `bst_init()`

Initializes an empty AVL Tree. Returns a pointer to the new tree.

### `avlHeight(NODE node)`

Calculates and returns the height of a given node.

### `balancedFactor(NODE node)`

Computes and returns the balance factor of a given node.

### `bst_init_node(int key, void *data)`

Creates and returns a new node with the specified key and data.

### `right_rotation(NODE node)`

Performs a right rotation on the given node to balance the tree.

### `left_rotation(NODE node)`

Performs a left rotation on the given node to balance the tree.

### `bst_insert_rec2(NODE node, int key, void *data)`

Recursively inserts a new node into the AVL Tree and performs rotations to maintain balance.

### `bst_traverse_inorder(NODE node)`

Traverses the tree in-order and prints the keys of the nodes.

### `printTree(NODE node, int l)`

Prints a visual representation of the tree, showing node keys, heights, and balance factors.

## Usage

To use this program:

1. **Compile the Program**: Use a C compiler such as `gcc`.
   ```bash
   gcc -o avl_tree avl_tree.c
### Example output: 
10 13 24 25 31 50 62 69 75 78 90                90 (1)(0)
          78 (2)(0)
               75 (1)(0)
     69 (3)(0)
               62 (1)(0)
          50 (2)(0)
               31 (1)(0)
25 (4)(-1)
          24 (1)(0)
     13 (2)(0)
          10 (1)(0)

Process finished with exit code 0
