#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

//��ͳ�Ƶ�26����ĸ���ճ������г��ֵ�Ƶ��
double Alphabet[26] = {0.082,0.015,0.028,0.042,0.127,0.022,0.020,0.061,0.070,0.001,0.008,0.040,0.024,0.068,0.075,0.019,0.001,0.060,0.063,0.090,0.028,0.010,0.024,0.020,0.001,0.001};

//�غ�ָ��������Կ����
int keyLenght(char ciphertext[400],int len){
    double imax = 0.065;
    for(int i=1;i<26;i++){
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
            //cout<<n<<"  "<<sum<<"\n";
            cout<<"����"<<i<<" "<<j<<" "<<" "<<chonghezhishu;
            //cout<<"��Կ����"<<i<<"��"<<j<<"��"<<"�غ�ָ��"<<chonghezhishu;
        }
        cout<<"\n";
    }
    cout<<"������غ�ָ����С�����������Կ����";
    int temp = 0;
    cin>>temp;
    return temp;
}
//����������
string solveVirginia(char ciphertext[400],int len,int keylen){
    //
    char key[keylen];
    double imax = 0.065;
        int height = ceil(len/keylen);
        //���㰴����Կ���ȵó���ÿ���غ�ָ��
            int tempAlphabet[25];
            memset(tempAlphabet, 0, sizeof(int)*26);
            for(int j = 0;j<keylen;j++){
                int subAlphabet[height];
                //ÿһ��
                for(int k = 1;k<=height;k++){
                    //��¼�����Ĵ�
                    subAlphabet[k-1]=ciphertext[keylen*(k-1)+j]-'A';
                    //�����Ĵ�ÿ����ĸ���ֵ�Ƶ��
                    //tempAlphabet[subAlphabet[k-1]]++;
                }
                //cout<<"��"<<j<<"��\n";
                int tempi = 1;
                double tempsum=0;
                for(int i=0;i<26;i++){
                    memset(tempAlphabet, 0, sizeof(int)*26);
                    int temp = subAlphabet[0];
                    for(int a=0;a<height;a++){//�������Ķ�ƫ��26��
                        subAlphabet[a]=(subAlphabet[a]+1)%26;
                    }
                    //cout<<subAlphabet[0]<<"sss";
                    for(int b = 0;b<height;b++){
                        //�����Ĵ�ÿ����ĸ���ֵ�Ƶ��
                        tempAlphabet[subAlphabet[b]]++;
                    }
                                    //����ÿһ�е��غ�ָ��
                    double sum = 0;
                    for(int k = 0;k<=25;k++){
                    //ÿ����ÿ����ĸ���ֵ�Ƶ��
                        sum=sum+(Alphabet[k]*tempAlphabet[k]/height)/height;
                    }
                    if(sum>tempsum){
                        tempsum = sum;
                        tempi = i;
                    }
                }
                    key[j] =1+((ciphertext[j]-'A'-(26-tempi))<=0?(ciphertext[j]-'A'-(26-tempi)+26+'A'):(ciphertext[j]-'A'-(26-tempi))+'A');
                    //cout<<key[j]<<"ƥ��Ƶ��"<<"\n";

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
    cout<<"����Ϊ��\n"<<cleartext<<endl;
}
int main()
{
    char ciphertext[400];
    char key[20];
    string tempkey;
    cout<<"�������������";
    cin>>ciphertext;
    int len;//�������ĵĳ���
    int keylen;//��Կ����
    len = strlen(ciphertext);
    keylen = keyLenght(ciphertext,len);
    tempkey = solveVirginia(ciphertext,len,keylen);
    tempkey.copy(key,keylen,0); //����5�������Ƽ����ַ���0�����Ƶ�λ��
    //*(key+keylen)='/0';
    getClearText(ciphertext,len,keylen,key);
    return 0;
}
