#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *head;
void insert_first(int val)
{
    node *temp = new node;
    temp->data = val;
    //2nd step
    temp->next = head;
    //3rd step
    head = temp;

}

void insert_last(int val)
{
    //1st step
    node *temp = new node;
    temp->data = val;

    //2nd step
    node *last = head;
    while(last->next!=nullptr)
    {
        last = last->next;
    }

    //3rd step
    last->next = temp;

    //4th step
    temp->next = nullptr;

}

void show_list()
{
    node *temp = head;
    while(temp!=nullptr)
    {
        cout << temp->data << ", ";
        temp = temp->next;
    }
    cout << endl;
}

void search_in_list(int val)
{
    node *temp = head;
    int flag =0;
    while(temp->next!=nullptr)
    {
        if(temp->data==val)
        {
            cout<<"Found \n"<<endl;
            flag =1;
            break;
        }
        else temp = temp->next;
    }
    if(flag ==0)
    {
        cout<<"Not Found \n"<<endl;
    }
}

int main()
{
    int ch;
    int val;
    while(1)
    {
        cout << "---MENU---" << endl;
        cout << "1. Insert First" << endl;
        cout << "2. Show All " << endl;
        cout << "3. Search " << endl;
        cout << "4. Insert Last " << endl;
        cout << "5. Exit " << endl;

        cin >> ch;

        switch(ch)
        {
        case 1:
            cout << "Enter the value of data: ";
            cin >> val;
            insert_first(val);
            break;

        case 2:
            show_list();
            break;

        case 3:
            cout << "Enter a value to search in the list: ";
            cin >> val;
            search_in_list(val);
            break;

        case 4:
            cout << "Enter the value of data: ";
            cin >> val;
            insert_last(val);
            break;

        case 5:
            return 0;
            break;

        default:
            cout << "Wrong input!" << endl;
        }
    }

    return 0;
}
