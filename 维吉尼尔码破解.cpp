#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

//��ͳ�Ƶ�26����ĸ���ճ������г��ֵ�Ƶ��
double Alphabet[26] = {0.082,0.015,0.028,0.042,0.127,0.022,0.020,0.061,0.070,0.001,0.008,0.010,0.024,0.068,0.075,0.019,0.001,0.060,0.063,0.090,0.028,0.010,0.024,0.050,0.001,0.001};

//�غ�ָ��������Կ����
int keyLenght(char ciphertext[400],int len){
    double imax = 0.065;
    for(int i=1;i<25;i++){
        int height = ceil(len/i);
        //���㰴�ռ�����Կ���ȵó���ÿ���غ�ָ��
        int tempAlphabet[26];
        memset(tempAlphabet, 0, sizeof(int)*26);
        for(int j = 0;j<i;j++){
            //ÿһ��
            for(int k = 1;k<=height;k++){
                //ÿ����ÿ����ĸ���ֵ�Ƶ��
               tempAlphabet[ciphertext[i*(k-1)+j]-'A']++;
            }
            //����ÿһ�е��غ�ָ��
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
            cout<<"��Կ����"<<i<<"��"<<j<<"��"<<"�غ�ָ��"<<chonghezhishu<<"\n";
        }
    }
    return 5;
}

int main()
{
    char ciphertext[400];
    cout<<"�������������";
    cin>>ciphertext;
    int len;//�������ĵĳ���
    int keylen;//��Կ����
    len = strlen(ciphertext);
    keylen = keyLenght(ciphertext,len);
    return 0;
}
