#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

struct Node* newNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->left = NULL;
    temp->right = NULL;
	return temp;
}

struct Node* insert(struct Node *node, int key){
    if(node==NULL) return newNode(key);
    if(node->data>key) node->left=insert(node->left, key);
    else node->right=insert(node->right, key);

    return node;
}

void inorder(Node* root)
{
	if (!root)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void preorder(Node* root)
{
	if (!root)
		return;
    cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node* root)
{
	if (!root)
		return;
	postorder(root->left);
	postorder(root->right);
    cout << root->data << " ";
}

int main()
{
	Node* root = NULL;
	int arr[]={10, 8, 2, 4, 3, 15, 26, 30, 17, 6};
    for(int i=0; i<10; i++){
        root = insert(root, arr[i]);
    }

	cout << "Inorder traversal of BST is: " << endl;
	inorder(root);
    cout << "\nPreorder traversal of BST is: " << endl;
	preorder(root);
    cout << "\nPostorder traversal of BST is: " << endl;
	postorder(root);
	return 0;
}

