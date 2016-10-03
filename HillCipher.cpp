#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

vector<char> encrypt(char plaintext[], char matrix[][2]){
    vector<char>encryptedtext;
    for(int k =0;k<strlen(plaintext);k+=2){
        char sum[2];
        memset(sum,0,sizeof(sum));
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                sum[i] += matrix[i][j]*(plaintext[k+j]-'a');
            }
        }
        for(int i=0;i<2;i++){
            encryptedtext.push_back(sum[i]%26 + 'a');
        }
    }
    return encryptedtext;
}

vector<char> decrypt(vector<char> encryptedtext, int matrix[][2]){
    vector<char>decryptedtext;
    for(int k =0;k<encryptedtext.size();k+=2){
        int sum[2];
        memset(sum,0,sizeof(sum));
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                sum[i] += (matrix[i][j])*(encryptedtext[k+j]-'a');
            }
        }
        for(int i=0;i<2;i++){
            //cout<<sum[i]%26<<' ';
            decryptedtext.push_back((char)(sum[i]%26 + 'a'));
        }
    }
    return decryptedtext;
}

int main(){
    char plaintext[100];
    cout<<"Enter Cipher Text of size 4"<<endl;
    char matrix[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"The matrix is:"<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            matrix[i][j] -= 'a';
            cout<<(int)matrix[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<"Enter Plain Text of even length, if odd add 1 dummy character"<<endl;
    cin>>plaintext;
    vector<char> encryptedtext = encrypt(plaintext, matrix);
    for(int i =0;i<encryptedtext.size();i++){
        cout<<encryptedtext[i];
    }
    cout<<endl;
    int inv_matrix[2][2];
    bool flag = true;
    inv_matrix[0][0] = matrix[1][1];
    inv_matrix[0][1] = -matrix[0][1];
    inv_matrix[1][0] = -matrix[1][0];
    inv_matrix[1][1] = matrix[0][0];
    int mod = matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
    cout<<"Modulus is"<<endl;
    cout<<mod<<endl;
    int mul;
    for(int i=1;; i++){
        if((mod*i)%26==1){
            mul = i;
            break;
        }
    }
    cout<<"Modulo multiplier is"<<endl;
    cout<<mul<<endl;
    cout<<"Inverse Matrix is"<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            inv_matrix[i][j] += 26;
            inv_matrix[i][j] %= 26;
            inv_matrix[i][j] *= mul;
            inv_matrix[i][j] %= 26;
            cout<<inv_matrix[i][j]<<' ';
        }
        cout<<endl;
    }
    vector<char> decryptedtext = decrypt(encryptedtext, inv_matrix);
    for(int i =0;i<decryptedtext.size();i++){
        cout<<decryptedtext[i];
    }
    cout<<endl;
    cout<<"Done!"<<endl;
    return 0;
}
