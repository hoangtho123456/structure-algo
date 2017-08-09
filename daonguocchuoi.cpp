#include<iostream.h>
#include<string>
using namespace std;
int main(){
	string s1="This is gameloft";
	//getline(cin,s1);
	int d=s1.length()-1;
	for(int i=s1.length()-1;i>=0;i--){
		//d=+1;
		if(s1[i]==' '){
			for(int j=i+1;j<=d;j++){
				cout<<s1[j];	
			}
			d=i-1;
			cout<<' ';
		}
		if(i==0){
			for(int j=i;j<=d;j++){
				cout<<s1[j];	
			}
		}
	}
	cout<<"\n"<<s1;
	cout<<endl;
}