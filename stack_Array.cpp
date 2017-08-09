#include<iostream.h>
#include<stdio.h>
#define maxn 100
typedef int item;
struct STACK{
	item data[maxn];
	int top;
};
void Init(STACK &T);
int is_empty(STACK T);
int is_full(STACK T);
void push(STACK &T,item x);
item pop(STACK &T);	//get top element then delete it
item peak(STACK T);	//get top element without delete top
void input(STACK &T);
void output(STACK T);
//--------Function------------

//init
void Init(STACK &T){
	T.top=0;
}
int is_empty(STACK T){
	return T.top==0;
}
int is_full(STACK T){
	return (T.top==maxn);
}
//push element into stack
void push(STACK &T,item x){
	if(!is_full(T)){
		T.data[T.top]=x;
		T.top++;
	}
}
//peak
item peak(STACK T){
	return T.data[T.top-1];
}
//pop
item pop(STACK &T){
	if(!is_empty(T)){
		T.top--;
		return T.data[T.top];	
	}
}
//input
void input(STACK &T){
	int i, n;
	item x;
	do{
		cout<<"Enter a number of elements in stack:";
		cin>>n;
	}while(n<1 || n>maxn);
	for(i=0;i<n;i++){
		cout<<"Enter the element "<<(i+1)<<":";
		cin>>x;
		push(T,x);
	}
}
//void output
void output(STACK T){
	int i;
	for(i=T.top-1;i>=0;i--){
		cout<<T.data[i]<<"\t";
	}
	cout<<endl;
}
//--------------------------
int main(){
	STACK T;
	Init(T);
	input(T);
	output(T);
	
	int choice;
	 printf("You can choose algorithm for stack below:");
    printf("\n1: check Stack is empty");
    printf("\n2: check Stack full");
    printf("\n3: Push an element into Stack");
    printf("\n4: Delete an element in Stack");
    printf("\n5: Exit");	
    
    do{
    	cout<<"\nYou choose:";
    	cin>>choice;
    	switch(choice){
	    	case 1:{
	    		if(is_empty(T)){
	    		cout<<"Stack is empty";
	    		}
	    		else cout<<"Stack is not empty";
	    		break;	
	    	}
	    	case 2:{
		    	if(is_full(T)){
		    		cout<<"Stack is full";
	    		}
	    		else cout<<"Stack is not full";
	    		break;		
	    	}
	    	case 3:{
	    		item x;
	    		cout<<"\nEnter the elements you want to insert:";
	    		cin>>x;
	    		push(T,x);
	    		output(T);
	    		break;
			}
			case 4:{
				cout<<pop(T)<<"\n";
				output(T);
				break;
			}
			case 5:{
				break;
			}
	    }
    }while(choice!=5);
}