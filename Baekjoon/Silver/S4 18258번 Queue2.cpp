#include <iostream>
using namespace std;

#define MAX_SIZE 200000

class Queue{
private:
    int data[MAX_SIZE];
    int front, rear;

public:
    Queue() {front=-1; rear=0;}
    ~Queue() {}

    void push(int x){
        data[rear++] = x;
    }

    int pop(){
        return data[++front];
    }

    int size(){
        return rear - front+1;
    }

    bool isEmpty(){
        return (rear==0 && front==-1);
    }

    int ffront(){
        if(!isEmpty()) return data[front+1];
        else cout<<"-1"<<endl;
    }

    int back(){
        if(!isEmpty()) return data[rear-1];
        else cout<<"-1"<<endl;
    }

};

int main(){
    Queue q;
    int n, x;
    string s;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>s;
        if(s=="push"){
            cin>>x;
            q.push(x);
        }
        else if(s=="pop"){
            cout<<q.pop()<<endl;
        }
        else if(s=="size"){
            cout<<q.size()<<endl;
        }
        else if(s=="empty"){
            cout<<!q.isEmpty()<<endl;
        }
        else if(s=="front"){
            cout<<q.ffront()<<endl;
        }
        else if(s=="back"){
            cout<<q.back()<<endl;
        }
    }

    return 0;
}