#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<char> encrypt(char plaintext[], int key){
    vector<char>encryptedtext;
    for(int i =0;i<strlen(plaintext);i++){
        encryptedtext.push_back((plaintext[i]-'a'+key%26)%26 + 'a');
    }
    return encryptedtext;
}

vector<char> decrypt(vector<char> encryptedtext, int key){
    vector<char>decryptedtext;
    for(int i =0;i<encryptedtext.size();i++){
        decryptedtext.push_back((encryptedtext[i]-'a'-key%26)%26 + 'a');
    }
    return decryptedtext;
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
    vector<char> decryptedtext = decrypt(encryptedtext, key);
    for(int i =0;i<decryptedtext.size();i++){
        cout<<decryptedtext[i];
    }
    cout<<endl;
    cout<<"Done!"<<endl;
    return 0;
}
