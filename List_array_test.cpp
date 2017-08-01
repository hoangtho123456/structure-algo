#include<iostream.h>
#define N 100
typedef int item;
typedef struct List{
	item Eles[N]; //mang kieu item
	int size;	
}LIST;
//declare function
void init(LIST *L);
int isEmty(LIST L);
int isFull(LIST L);
void input(LIST *L);
void output(LIST L);
int Insert_position(LIST *L,item x,int k);
int init_x();
//int Delete_position(LIST *L,*item x,int k);
//function
void init(LIST	*L){
	(*L).size=0;
}

int isEmty(LIST L){
	return(L.size==0);
}

int isFull(LIST L){
	return(L.size==N);
}

void input(LIST *L){
	cout<<"Enter size of list:";
	cin>>(*L).size;
	for(int i=0;i<(*L).size;i++){
		cout<<"The element "<<i+1<<": ";
		(*L).Eles[i]=init_x();
	}
}

int init_x(){
	int num;
	cin>>num;
	return num;
}

void output(LIST L){
	cout<<"List:\n";
	for(int i=0;i<L.size;i++){
		cout<<L.Eles[i]<<"   ";
	}
	cout<<endl;
}

int Insert_position(LIST *L,item x,int k){
	if(isFull(*L)){
		cout<<"List full!";
		return 0;
	}
	else if(k<1 || k>(*L).size+1){
		cout<<"the position is not possible to insert!\n";
		return 0;
	}
	else{
		cout<<"Input information:";
		x=init_x();
		for(int i=(*L).size;i>=k;i--){
			(*L).Eles[i]=(*L).Eles[i-1];
		}
		(*L).Eles[k-1]=x;
		(*L).size++;
		return 1;
	}	
}

int search(LIST L,item x){
	for(int i=0;i<L.size;i++){
		if(L.Eles[i]==x)
			return i+1;
	}
	return 0;
}

int Delete_position(LIST *L,item *x,int k){
	if(isEmty(*L)){
		cout<<"List null!";
		return 0;
	}
	if(k<1 || k>(*L).size){
		cout<<"Position k is not correct!";
		return 0;
	}
	//luu gia tri phan tu can xoa
	
	*x=(*L).Eles[k-1];
	for(int i=k-1;i<(*L).size;i++){
		(*L).Eles[i]=(*L).Eles[i+1];
	}
	(*L).size--;	
	return 1;
}

int delete_last(LIST *L,item *x){
	if(isEmty(*L)){
		cout<<"List null!";
		return 0;
	}
	*x=(*L).Eles[(*L).size-1];
	(*L).Eles[(*L).size-1]=(*L).Eles[(*L).size];
	(*L).size--;
	return 1;
}

int main(){
	LIST L;item x;int k;int option;
	init(&L);
	input(&L);
	output(L);
	cout<<"Enter algorithm you want to deal with list:";
	printf("\n1: Check null list:");
	printf("\n2: Check full list:");
	printf("\n3: Chen phan tu x vao vi tri k trong DS");
    printf("\n4: Xoa phan tu tai vi tri k");
    printf("\n5: Search element");
    printf("\n6: Thoat");
	do{
		cout<<"\nyour option:";
		cin>>option;
		switch(option){
			case 1:{
				if(isEmty(L)){
					cout<<"The List is none element-list";				
				}else{
					cout<<"The List is not none element-list";
				}
				break;
			}
			case 2:{
				if(isFull(L)){
					cout<<"The List is full!";				
				}else{
					cout<<"The List is not full!";
				}
				break;
			}
			case 3:{
				cout<<"input insert position: ";
				cin>>k;
				if(Insert_position(&L,x,k)){
					cout<<"the new List after insert:";
					output(L);
				}
				break;
			}
			case 4:{
				cout<<"Input delete position:";
				cin>>k;
				if(Delete_position(&L,&x,k)){
					cout<<"the new List after delete:";
					output(L);
					cout<<"\nValue was deleted:"<<x;
				}
				break;
			}
			case 5:{
				cout<<"input a value for search:";
				cin>>x;
				int temp=search(L,x);
				if(temp==0){
					cout<<"a value not found!";
				}
				else{
					cout<<"\nThe value is "<<x<<" at position "<<temp;	
				}
				break;
			}
			case 6:{
				cout<<"Thank you for use---";
				break;
			}
				
		}
	}while(option!=6);
	cout<<"\n"<<delete_last(&L,&x);
	output(L);
	
	return 0;
}