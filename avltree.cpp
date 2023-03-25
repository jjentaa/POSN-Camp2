#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data, height;
    Node *left, *right;
};

struct Node* newNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
	return temp;
}

int height(struct Node* node){
    if(node==NULL) return 0;
    return node->height;
}

int calcbfactor(struct Node* node){
    if(node==NULL) return 0;
    return height(node->left)-height(node->right);
}

struct Node* rotateLeft(struct Node* x){
    struct Node* y=x->right;
    struct Node* T2=y->left;

    y->left=x;
    x->right=T2;

    x->height=max(height(x->left), height(x->right))+1;
    y->height=max(height(y->left), height(y->right))+1;

    return y; // y=root node
}

struct Node* rotateRight(struct Node* y){
    struct Node* x=y->left;
    struct Node* T2=x->right;

    x->right=y;
    y->left=T2;

    y->height=max(height(y->left), height(y->right))+1;
    x->height=max(height(x->left), height(x->right))+1;

    return x; // y=root node
}

struct Node* insert(struct Node* node, int key){
    if(node==NULL) return newNode(key);
    if(node->data>key) node->left=insert(node->left, key);
    else if(node->data<key) node->right=insert(node->right, key);
    else return node; //there is this key in node already so don't update any thing

    //update node height cuz adding new node make more 1 height
    node->height=max(height(node->left), height(node->right))+1;
    int bfactor=calcbfactor(node);
    //positive l>r : negative r>l
    if(bfactor<-1){
        //right heavy
        if(node->right->data>key){
            //leftheavy
            return rotateLeft(node);
        }
        else if(node->right->data<key){
            //right heavy
            node->right=rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    else if(bfactor>1){
        //right heavy
        if(node->left->data>key){
            //leftheavy
            node->left=rotateLeft(node->left);
            return rotateRight(node);
        }
        else if(node->left->data<key){
            //right heavy
            return rotateRight(node);
        }
    }

    return node;

};

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    return 0;
}