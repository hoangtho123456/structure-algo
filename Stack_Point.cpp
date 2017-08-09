#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
typedef int item;	//data type
struct NODE{
	item data;
	NODE *next;
};
struct STACK{
	NODE *Top;
};

//create empty stack
void init(STACK	&T){
	T.Top=NULL;	
}

//check empty
int empty(STACK T){
	return (T.Top==NULL);
}

int Len(STACK T){
	NODE *P=T.Top;
	int i=0;
	while(P!=NULL){
		i++;
		P=P->next;
	}
	return i;
}

//make a node
NODE *makeNode(item x){
	NODE *p=new NODE;
	p->data=x;
	p->next=NULL;
	return p;
}
void push(STACK &T,item x){
	NODE *p=makeNode(x);
	p->next=T.Top;
	T.Top=p;
}
item peak(STACK T){
	return T.Top->data;
}

item pop(STACK &T){
	if(!empty(T)){
		item x=T.Top->data;
		T.Top=T.Top->next;
		return x;
	}
}
item search(STACK L,item x){
	int i=1;
	NODE *p=L.Top;
	while(p!=NULL && p->data!=x){
		i++;
		p=p->next;
	}
	if(p!=NULL){
		return i;	
	}
	return 0;
}
void input(STACK &T){
	int i=0;item x;
	cout<<"\nEnter elements of stack:";
	do{
		i++;
		cout<<"\nEnter elements of stack at position "<<i<<":";
		cin>>x;
		if(x!=0){
			push(T,x);	
		}			
	}
	while(x!=0);
}
void output(STACK T){
	NODE *p=T.Top;
	//cout<<"\nStack consist "<<Len(T)<<".";
	while(p!=NULL){
		cout<<p->data<<"\t";
		p=p->next;
	}
}
int main()
{
	STACK T;
	init(T);
	input(T);
	output(T);	
	int choice;
	cout<<"hello!enter the action you want with Stack:";
 	printf("\n1: Kiem tra Stack rong");
    printf("\n2: Do dai Stack");
    printf("\n3: Them phan tu vao Stack");
    printf("\n4: Xoa phan tu trong Stack");
    printf("\n5: Search the element in Stack");
    printf("\n6: Thoat");
    do{
    	cout<<"\nyour choice:";
    	cin>>choice;
    	switch(choice){
	    	case 1:{
				if(empty(T)){
		    		cout<<"\nStack empty";
		    		}
  				else cout<<"\nStack is not empty";
   				break;
	    	}	
	    	case 2:{
	    		cout<<"\nLength of stack is:"<<Len(T);
	    		break;
	    	}
	    	case 3:{
	    		item x;
				cout<<"\nEnter an element you want to push into Stack:";
	    		cin>>x;
	    		push(T,x);
	    		output(T);
	    		break;
	    	}
	    	case 4:{
	    		cout<<"\nThe lelement was delete is:"<<pop(T)<<endl;
	    		output(T);
	    		break;
	    	}
	    	case 5:{
	    		item x;
	    		cout<<"Enter the element need to serach:";
	    		cin>>x;
	    		if(search(T,x)){
		    		cout<<"The position of "<<x<<"is:"<<search(T,x);
		    	}
		    	else{
	    			cout<<"not found!";
	    		}
	    		break;
	    	}
    	  }
		}
	while(choice!=6);
 }