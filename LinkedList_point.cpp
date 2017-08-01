//linked list for int number
#include<iostream.h>
typedef int item;
typedef struct NODE{
	item info;
	struct NODE *next; //tro den 1 node tiep theo
};
typedef NODE *LIST;

void init(LIST &L){
	L=NULL;
}

int is_Empty(LIST L){
	return L==NULL;
}
//tinh do dai danh sach
int len(LIST L){
	NODE *P=L;
	int i=0;
	while(P!=NULL){
		i++;
		P=P->next;
	}
	return i;
}
//create node
NODE *makeNode(NODE *P,item x){
	P=new NODE;
	P->next=NULL;
	P->info=x;
	return P;
}
//insert at the first element in the list
void insert_First(LIST &L,item x){
	NODE *p=makeNode(p,x);
	p->next=L;
	L=p;
}
//insert at the k position in the list
void insert_k(LIST &L,item x,int k){
	NODE *p,*Q=L;
	int i=1;
	if(k<1 || k>len(L)+1){
		cout<<"The position is not possible!";
	}
	else{
		p=makeNode(p,x);
		if(k==1)insert_First(L,x);
		else{
			while(p!=NULL && i!=(k-1)){
			i++;
			Q=Q->next;
			}
		p->next=Q->next;
		Q->next=p;
		}
	}
}
//delete fisrt
void delete_first(LIST &L,item &x){
	x=L->info;
	L=L->next;
}
//delete k
void delete_k(LIST &L,item &x,int k){
	int i=1;
	NODE *Q=L;
	if(k<1 || k>len(L)){
		cout<<"position is not possible to delete!";
	}
	else{
		if(k==1)delete_first(L,x);
		else{
			while(Q!=NULL & (i!=k-1)){
			Q=Q->next;
			i++;
			}
			x=Q->next->info;	
			Q->next=Q->next->next;
		}
	}
}
//Search
int Search(LIST L,item x){
	NODE *P=L;
	int i=1;
	while(P!=NULL && P->info!=x){
		P=P->next;
		i++;
	}
	if(P!=NULL)return i; //return position found
	else return 0;
}

void input(LIST &L){
	int i=0;
	item x;
	init(L);
	do{
		i++;
		cout<<"Nhap phan tu thu "<<i<<":";
		cin>>x;
		if(x!=0)
		{
			insert_First(L,x);
		}
	}
	while(x!=0);
}
void output(LIST L){
	//NODE *P=L;
	for(NODE *P=L;P!=NULL;P=P->next){	
		cout<<P->info<<"  ";
		//P=P->next;	
	}
	cout<<"\n";
}
int main(){
	LIST L;
	item x;
	int k;
	input(L);
	output(L);
	if(is_Empty(L)){
		cout<<"\nList null";
	}else cout<<"\nList is not null";
	cout<<"\nlen:"<<len(L);
	int choice;
	cout<<"\nyou get a algorithm for linked list,please!";
	cout<<"\n1. Insert a new element at position k";
	cout<<"\n2. Delete an element at position k";
	cout<<"\n3. Search a position of the element need to find!";
	cout<<"\n4. Delete an element at value k";
	cout<<"\n5. Exit";
	do{
		cout<<"\nYou choose:";
		cin>>choice;
		switch(choice){
		 case 1:
		 	cout<<"Enter insert potition:";
		 	cin>>k;
			cout<<"\nEnter insert value:";
			cin>>x; 
	  		insert_k(L,x,k);
			output(L);
			break;
		case 2:
			cout<<"Enter delete potition:";
		 	cin>>k;
		 	delete_k(L,x,k);
		 	output(L);
		 	break;
	 	case 3:
	 		cout<<"Enter value need to find:";
	 		cin>>x;
	 		if(Search(L,x)){
		 		cout<<"potision of "<<x<<" is:"<<Search(L,x);
		 	}else cout<<"Not found!";
		 	break;
	 	case 4:
	 		cout<<"Enter value need to delete:";
	 		cin>>x;
	 		if(Search(L,x)){
		 		delete_k(L,x,Search(L,x));
		 		output(L);		 		
		 	}else cout<<"Not found!";
		 	break;
		case 5:
	 		break;
		}	
	}
	while(choice!=5);
	return 0;
}