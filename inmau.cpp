#include<iostream.h>
//char s[1];
using namespace std;
void inmautu(char s){
	cin>>s;
	string syllable;
	switch(s){
		case 'C':syllable="do";cout<<syllable;break;
		case 'D':s='re';cout<<s;break;
		case 'E':s='mi';cout<<s;break;
		case 'F':s='fa';cout<<s;break;
		case 'G':s='son';cout<<s;break;
		case 'A':s='la';cout<<s;break;
		case 'B':s='ti';cout<<s;break;
		default:
		cout<<"????";break;
	}
	
}
int main()
{
	char s;
	inmautu(s);
}