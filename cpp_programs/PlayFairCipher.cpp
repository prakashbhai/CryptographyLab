#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<char> encrypt(vector<char>plaintext, char matrix[][5]){
    vector<char>encryptedtext;
    for(int k =0;k<plaintext.size();k+=2){
        int fi, fj, si, sj;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(plaintext[k] == matrix[i][j]){
                    fi = i;
                    fj = j;
                }
                if(k+1<plaintext.size() && plaintext[k+1] == matrix[i][j]){
                    si = i;
                    sj = j;
                }else if(k+1>=plaintext.size() && matrix[i][j]=='x'){
                    si = i;
                    sj = j;
                }
            }
        }
        if(fi == si && fj != sj){
            encryptedtext.push_back(matrix[fi][(fj+1)%5]);
            encryptedtext.push_back(matrix[fi][(sj+1)%5]);
        }else if(fi != si && fj == sj){
            encryptedtext.push_back(matrix[(fi+1)%5][fj]);
            encryptedtext.push_back(matrix[(si+1)%5][fj]);
        }else if(fi != si && fj != sj){
            encryptedtext.push_back(matrix[fi][sj]);
            encryptedtext.push_back(matrix[si][fj]);
        }
    }
    return encryptedtext;
}

vector<char> decrypt(vector<char> encryptedtext, char matrix[][5]){
    vector<char>decryptedtext;
    for(int k =0;k<encryptedtext.size();k+=2){
        int fi, fj, si, sj;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(encryptedtext[k] == matrix[i][j]){
                    fi = i;
                    fj = j;
                }
                if(encryptedtext[k+1] == matrix[i][j]){
                    si = i;
                    sj = j;
                }
            }
        }
        if(fi == si && fj != sj){
            decryptedtext.push_back(matrix[fi][(fj+4)%5]);
            decryptedtext.push_back(matrix[fi][(sj+4)%5]);
        }else if(fi != si && fj == sj){
            decryptedtext.push_back(matrix[(fi+4)%5][fj]);
            decryptedtext.push_back(matrix[(si+4)%5][fj]);
        }else if(fi != si && fj != sj){
            decryptedtext.push_back(matrix[fi][sj]);
            decryptedtext.push_back(matrix[si][fj]);
        }
    }
    return decryptedtext;
}

int main(){
    char plaintext[100];
    char ciphertext[100];
    bool bitmask[26];
    memset(bitmask,false,sizeof(bitmask));
    cout<<"Enter Plain Text"<<endl;
    cin>>plaintext;
    cout<<"Enter Cipher Text"<<endl;
    cin>>ciphertext;
    int k=0,l=0;
    char matrix[5][5];
    for(int i=0;i<strlen(ciphertext);i++){
        if(!bitmask[ciphertext[i]-'a']){
        bitmask[ciphertext[i]-'a'] = true;
        matrix[k][l] = ciphertext[i];
        l++;
        if(l>=5){
            l=0;
            k++;
        }
       }     
    }
    bitmask['j'-'a'] = true;
    for(int i=0;i<26;i++){
        if(!bitmask[i]){
            matrix[k][l] = i+'a';
            l++;
            if(l>=5){
                l=0;
                k++;
            }
        }
    }
    cout<<"The matrix is:"<<endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<matrix[i][j]<<' ';
        }
        cout<<endl;
    }
    vector<char>pt;
    for(int i=0;i<strlen(plaintext)-1;i+=2){
        if(plaintext[i]!=plaintext[i+1]){
            pt.push_back(plaintext[i]);
            pt.push_back(plaintext[i+1]);
        }else{
            pt.push_back(plaintext[i]);
            pt.push_back('x');
            pt.push_back(plaintext[i+1]);
        }
    }
    if(strlen(plaintext)%2==1){
        pt.push_back(plaintext[strlen(plaintext)-1]);
    }
    cout<<"Corrected Text"<<endl;
    for(int i =0;i<pt.size();i++){
        cout<<pt[i];
    }
    cout<<endl;
    vector<char> encryptedtext = encrypt(pt, matrix);
    for(int i =0;i<encryptedtext.size();i++){
        cout<<encryptedtext[i];
    }
    cout<<endl;
    vector<char> decryptedtext = decrypt(encryptedtext, matrix);
    for(int i =0;i<decryptedtext.size();i++){
        cout<<decryptedtext[i];
    }
    cout<<endl;
    cout<<"Done!"<<endl;
    return 0;
}
