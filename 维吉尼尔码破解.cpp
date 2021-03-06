#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

//已统计的26个字母在日常生活中出现的频率
double Alphabet[26] = {0.082,0.015,0.028,0.042,0.127,0.022,0.020,0.061,0.070,0.001,0.008,0.040,0.024,0.068,0.075,0.019,0.001,0.060,0.063,0.090,0.028,0.010,0.024,0.020,0.001,0.001};

//重合指数法求密钥长度
int keyLenght(char ciphertext[400],int len){
    double imax = 0.065;
    for(int i=1;i<26;i++){
        int height = ceil(len/i);
        //计算按照假设密钥长度得出的每列重合指数
        int tempAlphabet[26];
        memset(tempAlphabet, 0, sizeof(int)*26);
        for(int j = 0;j<i;j++){
            //每一列
            for(int k = 1;k<=height;k++){
                //每列中每个字母出现的频数
               tempAlphabet[ciphertext[i*(k-1)+j]-'A']++;
            }
            //计算每一列的重合指数
            double sum =0;
            double n=0;
            for(int k = 0;k<26;k++){
                if(tempAlphabet[k]>0){
                    n=n+tempAlphabet[k];
                    sum=sum+tempAlphabet[k]*(tempAlphabet[k]-1);
                }
            }
            double chonghezhishu = 0;
            chonghezhishu = sum/(n*(n-1));
            //cout<<n<<"  "<<sum<<"\n";
            cout<<"长度"<<i<<" "<<j<<" "<<" "<<chonghezhishu;
            //cout<<"密钥长度"<<i<<"第"<<j<<"列"<<"重合指数"<<chonghezhishu;
        }
        cout<<"\n";
    }
    cout<<"请根据重合指数大小给出具体的密钥长度";
    int temp = 0;
    cin>>temp;
    return temp;
}
//求解具体密码
string solveVirginia(char ciphertext[400],int len,int keylen){
    //
    char key[keylen];
    double imax = 0.065;
        int height = ceil(len/keylen);
        //计算按照密钥长度得出的每列重合指数
            int tempAlphabet[25];
            memset(tempAlphabet, 0, sizeof(int)*26);
            for(int j = 0;j<keylen;j++){
                int subAlphabet[height];
                //每一列
                for(int k = 1;k<=height;k++){
                    //记录子密文串
                    subAlphabet[k-1]=ciphertext[keylen*(k-1)+j]-'A';
                    //子密文串每个字母出现的频数
                    //tempAlphabet[subAlphabet[k-1]]++;
                }
                //cout<<"第"<<j<<"个\n";
                int tempi = 1;
                double tempsum=0;
                for(int i=0;i<26;i++){
                    memset(tempAlphabet, 0, sizeof(int)*26);
                    int temp = subAlphabet[0];
                    for(int a=0;a<height;a++){//对子密文段偏移26次
                        subAlphabet[a]=(subAlphabet[a]+1)%26;
                    }
                    //cout<<subAlphabet[0]<<"sss";
                    for(int b = 0;b<height;b++){
                        //子密文串每个字母出现的频数
                        tempAlphabet[subAlphabet[b]]++;
                    }
                                    //计算每一列的重合指数
                    double sum = 0;
                    for(int k = 0;k<=25;k++){
                    //每列中每个字母出现的频数
                        sum=sum+(Alphabet[k]*tempAlphabet[k]/height)/height;
                    }
                    if(sum>tempsum){
                        tempsum = sum;
                        tempi = i;
                    }
                }
                    key[j] =1+((ciphertext[j]-'A'-(26-tempi))<=0?(ciphertext[j]-'A'-(26-tempi)+26+'A'):(ciphertext[j]-'A'-(26-tempi))+'A');
                    //cout<<key[j]<<"匹配频率"<<"\n";

        }
        return key;
        cout<<"\n";
}
void getClearText(char ciphertext[400],int len,int keylen,char key[20] ){
    char cleartext[400];
    //memset(cleartext, 'a', sizeof(char)*400);
                 //cout<<(('O'-'a'+'O')%25)<<endl;
    for(int i = 0;i<len;){
        for(int j = 0;j<keylen; j++){
            cleartext[i] = (ciphertext[i]-'A'+(26+'A'-key[j]))%26+'A';
            i++;
        }
    }
    cout<<"明文为：\n"<<cleartext<<endl;
}
int main()
{
    char ciphertext[400];
    char key[20];
    string tempkey;
    cout<<"请输入你的密码";
    cin>>ciphertext;
    int len;//输入密文的长度
    int keylen;//密钥长度
    len = strlen(ciphertext);
    keylen = keyLenght(ciphertext,len);
    tempkey = solveVirginia(ciphertext,len,keylen);
    tempkey.copy(key,keylen,0); //这里5，代表复制几个字符，0代表复制的位置
    //*(key+keylen)='/0';
    getClearText(ciphertext,len,keylen,key);
    return 0;
}
