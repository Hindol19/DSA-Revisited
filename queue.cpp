#include<iostream>
#define MAX 10
using namespace std;
class Queue{
    int front=-1, rear=-1;
    int arr[MAX];
    public:
        bool isEmpty(){
            if (front==rear && (front==-1 || front == MAX)) {
                if (front == MAX)
                    front=-1;
                    rear=-1;
                return 1;
            };
            return 0;
        }
        
        bool isFull(){
            if(rear==MAX-1) return 1;
            return 0;
        }

        void enque(int ele){
            if (isFull()){
                cout<<"QUEUE OVERFLOWq...."<<endl;
                return;
            }
            rear++;
            arr[rear]=ele;
            if(front==-1) front=0;
        }

        void deque(){
            if (isEmpty()){
                cout<<"QUEUE UNDERFLOWq..."<<endl;
                return;
            }
            front++;
        }

        void display(){
            for (int i = front ; i <= rear ; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main(void){
    int c, x;
    class Queue q;
    do
    {
        cout << "0.EXIT 1.ENQUE 2.DEQUE 3.DISPLAY" << endl;
        cout << "Enter your choice : ";
        cin >> c;
        switch (c){
        case 0:
            cout << "EXITED....";
            break;
        case 1:
            int n;
            cout << "Enter the element : ";
            cin >> n;
            q.enque(n);
            break;
        case 2:
            q.deque();
            cout << "element deleted..." <<endl;
            break;
        case 3:
            q.display();
            break;
        default:
            cout << "Wrong input...";
            break;
        }
    } while (c != 0);
    return 0;
}