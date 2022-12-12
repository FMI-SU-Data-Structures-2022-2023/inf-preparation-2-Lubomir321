#include <iostream>
using namespace std;
struct Node 
{
    int val;
    Node* next;
    Node() : val(0), next(nullptr) 
    {}
    Node(int a): val(a), next(nullptr)
    {}
};
void mirror(Node* head)
{
    Node* temp = head;
    Node* cur = new Node(temp->val);
    temp = temp->next;
    while (temp->next)
    {
        Node* newnode = new Node(temp->val);
        newnode->next = cur;
        cur = newnode;
        temp = temp->next;
    }
    Node* newnode = new Node(temp->val);
    newnode->next = cur;
    cur = newnode;
    temp->next = cur;

}
//Разглеждаме "големи" цели положителни числа, представели свързан списък, обърнат,
//  т.е.стойноста на единиците е първото число в този списък.Пример за такова число е 123456789012, като то се представя като
//
//2->1->0->9->8->7->6->5->4->3->2->1
//Да се дефинира функция sum, която намира сумата на 2 такива дълги числа.
Node* sum(Node* num1, Node* num2)
{
    int sum;
    int add = 0;
    Node* result = nullptr;
    while (num1 && num2)
    {
        sum = num1->val + num2->val + add;
        if (sum > 9)
        {
            sum = sum % 10;
            add = 1;
        }
        else if( sum >= 0 && sum <= 9)
        {
            add = 0;
        }
        Node* temp = new Node(sum);
        temp->next = result;
        result = temp;
        num1 = num1->next;
        num2 = num2->next;
    }
    if (num1 != nullptr)
    {
        sum = num1->val + add;
        if (sum > 9)
        {
            sum = sum % 10;
            add = 1;
        }
        else if (sum >= 0 && sum <= 9)
        {
            add = 0;
        }
        Node* temp = new Node(sum);
        temp->next = result;
        result = temp;
        num1 = num1->next;
    }
    if (num2 != nullptr)
    {
        sum = num2->val + add;
        if (sum > 9)
        {
            sum = sum % 10;
            add = 1;
        }
        else if (sum >= 0 && sum <= 9)
        {
            add = 0;
        }
        Node* temp = new Node(sum);
        temp->next = result;
        result = temp;
        num2 = num2->next;
    }
    if (add != 0)
    {
        Node* temp = new Node(add);
        temp->next = result;
        result = temp;
    }
    return result;
}
int main()
{

    Node* node11 = new Node(3);
    Node* node12 = new Node(5);
    Node* node13 = new Node(8);
    Node* node21 = new Node(7);
    Node* node22 = new Node(4);
    Node* node23 = new Node(1);
    Node* node24 = new Node(9);


    node11->next = node12;
    node12->next = node13;
    node21->next = node22;
    node22->next = node23;
    node23->next = node24;

    Node* result = sum(node11, node21);
    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }
    /*Node* node1 = new Node(2);
    Node* node2 = new Node(1);
    Node* node3 = new Node(0);
    Node* node4 = new Node(9);
    Node* node5 = new Node(8);
    Node* node6 = new Node(7);
    Node* node7 = new Node(6);
    Node* node8 = new Node(5);
    Node* node9 = new Node(4);
    Node* node10 = new Node(3);
    Node* node11 = new Node(2);
    Node* node12 = new Node(1);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;
    node10->next = node11;
    node11->next = node12;*/

}

