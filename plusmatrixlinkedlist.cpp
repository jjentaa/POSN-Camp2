#include <bits/stdc++.h>

using namespace std;
int m=2, n=3;
struct Node{
    int row, col, data;
    struct Node *next;
};

void push(struct Node** head, int nrow, int ncol, int node_data){
    struct Node* newNode = new Node;
    newNode->data = node_data;
    newNode->row = nrow;
    newNode->col = ncol;
    newNode->next = (*head);
    (*head) = newNode;
}

void displayList(struct Node *node){
    int runner=0;
    while (node != NULL) {
        cout << node->data << " ";
        runner++;
        if(runner%n==0) cout << "\n";
        node = node->next;
    }

    // if (node == NULL)
    //     cout << "null" << endl << endl;
}

Node *find(struct Node *head, int trow, int tcol)
{
    struct Node *p = head;
    while(p != NULL && p->row != trow && p->col != tcol)
        p = p->next;

    return p;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int matrix1[2][3]={
        {3, -4, -9},
        {-1, 0, 8}
    };

    int matrix2[2][3]={
        {3, -4, -9},
        {-1, 0, 8}
    };

    struct Node *head1 = NULL; 
    for(int i=m-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            push(&head1, i, j, matrix1[i][j]);
        }
    }

    for(int i=m-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            struct Node *target=find(head1, i, j);
            target->data+=matrix2[i][j];
        }
    }

    displayList(head1);

    return 0;
}