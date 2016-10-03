#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

long long int powr(long long int g, long long int x){
    long long pr = 1;
    for(int i=1;i<=x;i++){
        pr *= g;
    }
    return pr;
}


int main(){
    long long int g, n;
    cout<<"Enter values for g and n"<<endl;
    cin>>g>>n;
    cout<<"Enter the message from Alice"<<endl;
    long long int x;
    cin>>x;
    long long int a = powr(g,x)%n;
    cout<<a<<endl;
    cout<<"Enter the message from Bob"<<endl;
    long long int y;
    cin>>y;
    int b = powr(g,y)%n;
    cout<<b<<endl;
    cout<<"The message for Alice is"<<powr(b,x)%n<<endl;
    cout<<"The message for Bob is"<<powr(a,y)%n<<endl;
    return 0;
}
