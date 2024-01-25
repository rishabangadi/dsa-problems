#include <bits/stdc++.h>
using namespace std;

class StackNode
{
public:
    int data;
    StackNode* next;
};

StackNode*
newNode(int data)
{
    StackNode* temp = new StackNode();

    temp->data = data;
    temp->next = NULL;
    return temp;
}

void push(StackNode** root, int data) {
    StackNode* temp = newNode(data);
    temp->next = *root;
    *root = temp;
    cout << data << " pushed" << endl;
}

bool empty(StackNode* root)
{
    return !root;
}

int pop(StackNode** root) {
    if (empty(*root)) return INT_MIN;
    StackNode* temp = *root;
    *root = temp->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int peek(StackNode* root)
{
    if (empty(root)) return INT_MIN;
    return root->data;
}

int main() {
    StackNode* root = NULL;
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    while (!empty(root))
    {
        cout << peek(root) << endl;
        pop(&root);
    }

    return 0;

}
