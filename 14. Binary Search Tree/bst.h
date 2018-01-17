#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

template<class ItemType>
class TreeNode
{
public:
    ItemType element;
    TreeNode *left;
    TreeNode *right;
};

template<class ItemType>
class BST
{
public:
    BST();
    bool isEmpty();
    void insert(ItemType);
    void remove(ItemType);
    bool find(ItemType);
    void printInOrder();
    void printPreOrder();
    void printPostOrder();
    int numLeaves();
    int size();
    int maxDepth();
    bool hasPathSum(int);
    ItemType findMin();
private:
    TreeNode<ItemType> *root;
    TreeNode<ItemType> *insert(TreeNode<ItemType>* n, ItemType);
    TreeNode<ItemType> *remove(TreeNode<ItemType> *n, ItemType);
    bool find(TreeNode<ItemType> *n, ItemType);
    void printInOrder(TreeNode<ItemType> *n);
    void printPreOrder(TreeNode<ItemType> *n);
    void printPostOrder(TreeNode<ItemType> *n);
    int numLeaves(TreeNode<ItemType> *t);
    ItemType findMin(TreeNode<ItemType> *t);
    int size(TreeNode<ItemType> *);
    int maxDepth(TreeNode<ItemType> *);
    bool hasPathSum(TreeNode<ItemType>*, int);
};

#include "bst.cpp"

#endif // BST_H

