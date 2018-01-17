#ifndef BST_CPP
#define BST_CPP

#include "bst.h"

template<class ItemType>
BST<ItemType>::BST()
{
    root = NULL;
}

template<class ItemType>
bool BST<ItemType>::isEmpty()
{
    return (root == NULL);
}

template<class ItemType>
void BST<ItemType>::insert(ItemType item)
{
    root = insert(root, item);
}

template<class ItemType>
TreeNode<ItemType>* BST<ItemType>::insert(TreeNode<ItemType> *n, ItemType item)
{
    if(n == NULL) {
        TreeNode<ItemType> *t = new TreeNode<ItemType>;
        t->element = item;
        t->left = NULL;
        t->right = NULL;
        n = t;
        return n;
    }
    if(item < n->element) {
        n->left = insert(n->left, item);
        return n;
    } else {
        n->right = insert(n->right, item);
        return n;
    }
}

template<class ItemType>
bool BST<ItemType>::find(ItemType item)
{
    return find(root, item);
}

template<class ItemType>
bool BST<ItemType>::find(TreeNode<ItemType>* n, ItemType item)
{
    if(n == NULL)
        return false;
    if(item == n->element)
        return true;
    if(item > n->element)
        return find(n->right, item);
    else
        return find(n->left, item);
}

template<class ItemType>
void BST<ItemType>::printInOrder()
{
    printInOrder(root);
}

template<class ItemType>
void BST<ItemType>::printInOrder(TreeNode<ItemType>* n)
{
    if(n == NULL)
        return;
    printInOrder(n->left);
    cout << n->element << " ";
    printInOrder(n->right);
}

template<class ItemType>
void BST<ItemType>::printPreOrder()
{
    printPreOrder(root);
}

template<class ItemType>
void BST<ItemType>::printPreOrder(TreeNode<ItemType>* n)
{
    if(n == NULL)
        return;
    cout << n->element << " ";
    printPreOrder(n->left);
    printPreOrder(n->right);
}

template<class ItemType>
void BST<ItemType>::printPostOrder()
{
    printPostOrder(root);
}

template<class ItemType>
void BST<ItemType>::printPostOrder(TreeNode<ItemType>* n)
{
    if(n == NULL)
        return;
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout << n->element << " ";
}

template<class ItemType>
int BST<ItemType>::numLeaves()
{
    return numLeaves(root);
}

template<class ItemType>
int BST<ItemType>::numLeaves(TreeNode<ItemType>* t)
{
    if(t == NULL)
        return 0;
    if(t->left == NULL && t->right == NULL)
        return 1;
    else
        return numLeaves(t->left) + numLeaves(t->right);
}

template<class ItemType>
ItemType BST<ItemType>::findMin()
{
    return findMin(root);
}

template<class ItemType>
ItemType BST<ItemType>::findMin(TreeNode<ItemType>* t)
{
    if(t->left == NULL)
        return t->element;
    else
        return findMin(t->left);
}

template<class ItemType>
void BST<ItemType>::remove(ItemType item)
{
    root = remove(root, item);
}

template<class ItemType>
TreeNode<ItemType>* BST<ItemType>::remove(TreeNode<ItemType> *n, ItemType item)
{
    if(n == NULL)
        return n;
    if(item < n->element) {
        n->left = remove(n->left, item);
        return n;
    }
    if(item > n->element) {
        n->right = remove(n->right, item);
        return n;
    }
    if(n->left == NULL && n->right == NULL) {
        delete n;
        return NULL;
    }
    if(n->left != NULL && n->right != NULL) {
        ItemType x = findMin(n->right);
        n->element = x;
        n->right = remove(n->right, x);
        return n;
    }
    if(n->left != NULL) {
        TreeNode<ItemType> *p = n;
        n = n->left;
        delete p;
        return n;
    }
    TreeNode<ItemType> *p = n;
    n = n->right;
    delete p;
    return n;
}

template<class ItemType>
int BST<ItemType>::size()
{
    return size(root);
}

template<class ItemType>
int BST<ItemType>::size(TreeNode<ItemType> *t)
{
    if(t == NULL)
        return 1;
    if(t->left == NULL && t->right == NULL)
        return 1;
    return size(t->left) + size(t->right) + 1;
}

template<class ItemType>
int BST<ItemType>::maxDepth()
{
    return maxDepth(root);
}

template<class ItemType>
int BST<ItemType>::maxDepth(TreeNode<ItemType> *t)
{
    if(t == NULL)
        return 0;
    else
        return max(maxDepth(t->left) + 1, maxDepth(t->right) + 1);
}

template<class ItemType>
bool BST<ItemType>::hasPathSum(int sum)
{
    return hasPathSum(root, sum);
}

template<class ItemType>
bool BST<ItemType>::hasPathSum(TreeNode<ItemType>* n, int& sum)
{
    if(n->left == NULL || n->right == NULL)
        sum -= n->element;
    return()

}


#endif // BST_CPP

