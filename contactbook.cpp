#include<bits/stdc++.h>
using namespace std;
struct node
{
   string name , number;
   node *next;
};

node *head = NULL , *newnode , *temp;
int len = 0 ;

void Add_contact()
{

    newnode = new node;
    cout<<"Enter Name : ";
    cin>>newnode->name;
    cout<<"Enter number : ";
    cin>>newnode->number;
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        temp->next= newnode;
        temp = newnode;
    }
}
void display ()
{

    if(head == NULL)
    {
        cout<<"Contact list is Empty"<<endl;
    }
    else
    {
        node *trav = head ;
        while (trav != NULL)
        {
            cout<<len+1;
            cout<<". Full Name : "<<trav->name;
            cout<<"  --> Phone Number : "<<trav->number<<endl;
            trav= trav->next;
            len++;
        }
        cout<<"Total number of contacts in the list = "<<len<<endl<<endl;
    }
}

void search_contact()  //search contact
{
     node *search_node = head, *next_node , *temp = head;
    //*search_node pointer is used to find the contact
    //*next_node pointer is used to free the deleted node storage

    string search1;
    int count = 0;
    cout<<"Enter your desired contact to search ";
    cin>>search1;
    bool found = false;
    if(head == NULL)
    {
        cout<<"\nNo contact list are available"<<endl;
    }
    else
    {
        while (search_node != NULL)
        {
            if(search1 == search_node->name || search1 == search_node->number)/// to search contact
            {
                cout<<"Full name : "<<search_node->name<<endl;
                cout<<"phone number : "<<search_node->number<<endl;
                found = true;
            }
            search_node = search_node->next;
            count++;
        }

    }
    if(found == true)
    {

        cout<<"Index of the Contact = "<<count+1<<endl;
    }
    else
    {
        cout<<"Desired contact not found "<<endl;
    }
}

void Delete_contact() 
{
    node *search_node = head, *next_node , *temp = head;
    

    string search1;
    int count = 0;
    cout<<"Enter your desired contact to delete ";
    cin>>search1;
    bool found = false;
    if(head == NULL)
    {
        cout<<"\nNo contact list are available"<<endl;
    }
    else
    {
        while (search_node != NULL)
        {
            if(search1 == search_node->name || search1 == search_node->number)/// to search contact
            {
                if(count == 0) 
              {
              temp = head;
              head = head->next;
               delete temp;
              cout<<"Contact has been deleted"<<endl;
            }


            else
            {
                for (int i = 1 ; i<count ; i++)
                {
                        temp= temp->next;

                }
                next_node = temp->next;
                temp->next = next_node->next;
                delete next_node;
                cout<<"Contact has been deleted"<<endl;
            }


        found =true;
        break;
        }

             
            search_node = search_node->next;
            count++;

        }
    }
    if(found == true)
    {

        cout<<"Index of the Contact = "<<count+1<<endl;
    }
    else
    {
        cout<<"Desired contact not found"<<endl;
    }
}

void clear_all ()
{
    if(head == NULL)
    {
        cout<<"No contact list are available "<<endl;
    }
    else
    {
        temp = head;
        while (head != NULL)
        {
            head = head->next;
            delete temp;
        }
        cout<<"ALL contact lists has been deleted "<<endl;
    }
}
void menu ()
{
    cout<<"#####Enter the choice#####"<<endl;
    cout<<"1.Add contact"<<endl;
    cout<<"2.Display all contacts"<<endl;
    cout<<"3.Search contact"<<endl;
    cout<<"4.Delete contact"<<endl;
    cout<<"5.Clear all contacts"<<endl;
}
int main ()
{

    system("color 0A");
    int choice;
    while (true )
    {
        menu();
        cin>>choice;
        switch(choice)
        {
        case 1:
                 Add_contact();
                 break;
        case 2:
                len = 0;
                display();
                break;
        case 3:
                search_contact();
                break;
        case 4:
                Delete_contact();
                 break;

        case 5:
                clear_all();
                break;
        default:
            cout<<"Invalid choice "<<endl;
        }
    }
}

