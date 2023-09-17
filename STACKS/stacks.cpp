#include<iostream>
using namespace std;

int MAX_SIZE=10000;
char stack[10000];
int top =-1;

//check full or not
bool isFull(){
    if(top == MAX_SIZE-1)
        return true;
    else
        return false;
}
//check empty or not
bool isEmpty(){
    if(top==-1)
        return true;
    else
        return false;
}


//insert into the stack
void push(int x){
    if(!isFull()){
        top++;
        stack[top]=x;
    }
    else
        cout<<"Stack is full"<<endl;
}
//delete element
void pop(){
    if(!isEmpty()){
        top--;
    }
    else{
        cout<<"Stack is empty"<<endl;
    }

}
//size of the stack
void size(){
    cout<<"Size of the stack is :"<<top+1<<endl;
}
//get the topmost element
int peek(){
   return stack[top];
}

int main(){
    
    // pop();
    string str;
    cin>>str;
    for(int i=0;i<str.length();i++){
        push(str[i]);
    }
    // size();
    while(!isEmpty()){
        cout<<stack[top];;
        pop();
    }
   

}