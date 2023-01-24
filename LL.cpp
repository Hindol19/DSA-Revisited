#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    Node()
    {
        this->data=0;
        this->next=NULL;
    }
};

class LL
{
    private:
        Node *root = NULL;
    public:
        bool isEmpty()
        {
            if (root==NULL)
                return 1;
            return 0;
        }

        void insertEnd(int ele)
        {
            Node*ptr=new Node(ele);
            if (root==NULL)
                root = ptr;
            else
            {
                Node*temp=root;
                while(temp->next!=NULL)
                    temp=temp->next;
                temp->next=ptr;
            }
        }
        void insertBeg(int ele)
        {
            Node*ptr=new Node(ele);
            if (root==NULL)
                root=ptr;
            else
            {
                Node*temp=root;
                ptr->next=temp;
                root=ptr;
            }
        }

        void insert(int pos, int ele)
        {
            Node*ptr=new Node(ele);
            if (root==NULL)
            {
                cout<<"LIST EMPTY...."<<endl<<"NEW ELEMENT INSERTD...."<<endl;
                root=ptr;  
                return;              
            }
            Node *temp1=root, *temp2;
            int c=0;
            while (c<pos-1)
            {
                if (temp1->next==NULL)
                {
                    insertEnd(ele);
                    break;
                }   
                else
                {
                    temp1=temp1->next;
                    c++;
                }
            }
            temp2=temp1->next;
            temp1->next=ptr;
            ptr->next=temp2;
        }

        void deleteBeg()
        {
            if (root==NULL)
            {
                cout<<"EMPTY LIST..."<<endl;
                return;
            }
            Node *temp=root->next;
            free(root);
            root=temp;
        }

        void deleteEnd()
        {
            if (root==NULL)
            {
                cout<<"EMPTY LIST..."<<endl;
                return;
            }          
            Node *ptr=root;
            while(ptr->next->next!=NULL)
                ptr=ptr->next;
            ptr->next=NULL;  
        }

        void deletePos(int pos)
        {
            if (root==NULL)
            {
                cout<<"EMPTY LIST..."<<endl;
                return;
            }
            int c=0;
            Node *temp1 = root, *temp2;
            while (c < pos-1)
            {
                if (temp1->next == NULL)
                {
                    deleteEnd();
                    break;
                }
                else
                {
                    temp1 = temp1->next;
                    c++;
                }
            }
            temp2 = temp1->next->next;
            free(temp1->next);
            temp1->next = temp2;
        }
        
        void display()
        {
            Node *temp=root;
            if (root==NULL)
            {
                cout<<"EMPTY LIST..."<<endl;
                return;
            }
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
/*      Node *revDisplay(Node *ptr)
        {
            if (ptr==NULL)
            {
                return;
            }
            revDisplay(ptr->next);
            cout<<ptr->data;
        }*/
};

int main(void)
{
    LL l;
    int c, ele, pos;
    do
    {
            cout << "0.EXIT \n1.Insert at Beg \n2.Insert at Beg \n3.Insert at any pos \n4.Delete from beg \n5.delete from end \n6.Delete from any pos \n7.Display\n";
            cout << "Enter your choice : ";
            cin>>c;
            switch (c)
            {
            case 0:
                cout<<"EXITED..."<<endl;
                break;
            case 1:
                cout << "Enter the element : ";
                cin>>ele;
                l.insertBeg(ele);
                break;
            case 2:
                cout << "Enter the element : ";
                cin >> ele;
                l.insertEnd(ele);
                break;
            case 3:
                cout << "Enter the element : ";
                cin >> ele;
                cout<<"Enter the position : ";
                cin>>pos;
                l.insert(pos, ele);
                break;
            case 4:
                l.deleteBeg();
                cout << endl;
                break;
            case 5:
                l.deleteBeg();
                cout << endl;
                break;
            case 6:
                cout << "Enter the position : ";
                cin >> pos;
                l.deletePos(pos);
                cout << endl;
                break;
            case 7:
                l.display();
                break;
            default:
                cout<<"WRONG CHOICE..."<<endl;
                break;
            }
    } while (c!=0);
    
}