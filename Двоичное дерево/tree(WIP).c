#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *left, *right;
}node;

node* node_create(int val)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->key = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}


node* add_tree(node *root, int val)
{
    if (root == NULL) root = node_create(val);
    if (val < root->key)
    {
        if (root->left == NULL)
        {
            root->left = node_create(val);
        }else
        {
            add_tree(root->left,val);
        }
    }else
    {
        if (root->right == NULL)
        {
            root->right = node_create(val);
        }else
        {
            add_tree(root->right,val);
        }
    }
    return root;
}

node* find_tree(node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (val == root->key)
    {
        return root;
    }
    if (val < root->key)
    {
        return find_tree(root->left,val);
    }else if (val > root->key)
    {
        return find_tree(root->right,val);
    }
}


int main(void)
{

}
