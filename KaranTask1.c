#include<stdio.h>

#define max 5
int stack[max], top=-1;
void push(int num){
    if(top==max-1){
        printf("Stack overflow %d");
    }
    else{
        top=top+1;
        stack[ top ] = num;
        printf("%d pushed to the stack.\n",num);
    }
}
int pop(){
    if(top==-1){
        printf("stack underflow!");
        return -1;
    }
    else{
        int popped =stack[top];
        printf("%d popped from the stack.\n",popped);
        top = top -1;
        return popped;
    }
}
void peek(){
    if(top == -1){
        printf("stack underflow!");
    }
    else{
        printf("Top element is: %d\n",stack[top]);
    }
}
void display(){
    if(top == -1){printf("Stack underflow!");
    }else{
        printf("Elements in stack:");
        for(int i=0;i<=top;i++){
            printf(" %d",stack[i]);
        }
        printf("\n");
    }
}
int main(){
    push(10);
    push(20);
    push(40);
    peek();
    pop();
    pop();
    display();
    return 0;
}