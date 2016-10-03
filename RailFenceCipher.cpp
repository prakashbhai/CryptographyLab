#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<char> encrypt(char plaintext[], int key){
    vector<char>encryptedtext;
    for(int i =0;i<2*key - 2;i++){
        for(int j = i; j<strlen(plaintext);j+=2*key-2)
            encryptedtext.push_back(plaintext[j]);
    }
    return encryptedtext;
}

int main(){
    int key;
    char plaintext[100];
    cout<<"Enter Plain Text"<<endl;
    cin>>plaintext;
    cout<<"Enter Key"<<endl;
    cin>>key;
    vector<char> encryptedtext = encrypt(plaintext, key);
    for(int i =0;i<encryptedtext.size();i++){
        cout<<encryptedtext[i];
    }
    cout<<endl;
    cout<<"Done!"<<endl;
    return 0;
}
