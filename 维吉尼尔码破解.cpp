#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

//已统计的26个字母在日常生活中出现的频率
double Alphabet[26] = {0.082,0.015,0.028,0.042,0.127,0.022,0.020,0.061,0.070,0.001,0.008,0.010,0.024,0.068,0.075,0.019,0.001,0.060,0.063,0.090,0.028,0.010,0.024,0.050,0.001,0.001};

//重合指数法求密钥长度
int keyLenght(char ciphertext[400],int len){
    double imax = 0.065;
    for(int i=1;i<25;i++){
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
            cout<<n<<"  "<<sum<<"\n";
            cout<<"密钥长度"<<i<<"第"<<j<<"列"<<"重合指数"<<chonghezhishu<<"\n";
        }
    }
    return 5;
}

int main()
{
    char ciphertext[400];
    cout<<"请输入你的密码";
    cin>>ciphertext;
    int len;//输入密文的长度
    int keylen;//密钥长度
    len = strlen(ciphertext);
    keylen = keyLenght(ciphertext,len);
    return 0;
}
