#include<bits/stdc++.h>
using namespace std;

int main(){
	string message;
	cout<<"Enter the message"<<endl;
	cin>>message;
	cout<<"Enter the flag"<<endl;
	char f;
	cin>>f;
	cout<<"Enter the Escape Sequence"<<endl;
	char e;
	cin>>e;
	string ans;
	ans.push_back(f);
	for(int i=0;i<(int)message.length();++i){
		if(message[i] == f){
			ans.push_back(e);
		}
		else if(message[i] == e){
			ans.push_back(e);
		}
		ans.push_back(message[i]);
	}
	ans.push_back(f);
	cout<<"Byte Stuffed Message:"<<endl;
	cout<<ans<<endl;
}