#include <bits/stdc++.h>

using namespace std;
struct Node
{
    pair<int, int> number;
    struct Node *next;
};

void display(struct Node *head)	//function to print linked list
{
    struct Node *ptr = head;
    while (ptr)
    {
        cout << (ptr->number).first << "x^" << (ptr->number).second << " ";
        ptr = ptr->next;
    }
}

struct Node *newNode (pair<int, int> data)
{
    struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));
    newNode->number = data;
    newNode->next = NULL;

    return newNode;
}

void sortedInsert (struct Node **head, struct Node *newNode){
    if (*head == NULL || ((*head)->number).second < (newNode->number).second)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    if (((*head)->number).second == (newNode->number).second){
        ((*head)->number).first+=(newNode->number).first;
        return;
    }

    int check=0;
    struct Node *current = *head;
    while (current->next != NULL && (current->next->number).second >= (newNode->number).second){
        if((current->next->number).second == (newNode->number).second){
            check=1;
            break;
        }
        else current = current->next;
    }

    if(!check){
        newNode->next = current->next;
        current->next = newNode;
    }
    else{
        (current->next->number).first += (newNode->number).first;
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    struct Node *head1 = NULL; 
    sortedInsert(&head1, newNode({5, 2}));
    sortedInsert(&head1, newNode({4, 1}));
    sortedInsert(&head1, newNode({5, 3}));
    sortedInsert(&head1, newNode({2, 0}));

    sortedInsert(&head1, newNode({-5, 1}));
    sortedInsert(&head1, newNode({4, 3}));
    sortedInsert(&head1, newNode({-5, 0}));

    display(head1);

    return 0;
}