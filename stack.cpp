#include<iostream>
#define MAX 10
using namespace std;
class Stack{
    int top;
    public:
        int arr[MAX];
        Stack(){
            top=-1;
        }
        bool isEMpty(){
            if (top == -1)
                return 1;
            return 0;
        }

        void push(int ele){
            if (top>=MAX-1){
                cout<<"STACK OVERFLOW...";
                return;
            }
            arr[++top] = ele;
        }

        int pop(){
            if (isEMpty()){
                cout<<"STACK UNERFLOW...";
                return -9999;
            }
            int x = arr[top--];
            return x;
        }

        int peek(){
            if (isEMpty()){
                cout<<"STACK EMPTY....";
                return -9999;
            }
            return arr[top];
        }

        void display(){
            for (int i = 0 ; i <= top ; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    int c, x;
    class Stack s;
    do{
        cout<<"0.EXIT 1.PUSH 2.POP 3.DISPLAY 4.PEEK"<<endl;
        cout<<"Enter your choice : ";
        cin>>c;
        switch (c){
            case 0:
                cout<<"EXITED....";
                break;
            case 1:
                int n;
                cout<<"Enter the element : ";
                cin>>n;
                s.push(n);
                break;
            case 2:
                x = s.pop();
                if (x!=-9999)
                    cout<<"element popped : "<<x<<endl;
                else
                    cout<<endl;
                break;
            case 3:
                s.display();
                break;
            case 4:
                cout<<"element at the top is : "<<s.peek()<<endl;
                break;
            default:
                cout<<"Wrong input...";
                break;
        }
    }while(c!=0);
    return 0;
}