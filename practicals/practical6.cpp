#include <iostream>
#include <cstring>

using namespace std;

char* lcs(char*, char*);

int main() {
    unsigned int str1Len;
    unsigned int str2Len;
    char *str1, *str2, *result;
    cout<<"Enter length of first string: ";
    cin>>str1Len;
    str1 = new char[str1Len+1];
    cout<<"Enter string 1: ";
    cin>>str1;
    cout<<"Enter length of second string: ";
    cin>>str2Len;
    str2 = new char[str2Len+1];
    cout<<"Enter string 2: ";
    cin>>str2;
    result = lcs(str1, str2);
    cout<<"Length of LCS is "<<strlen(result)<<endl;
    cout<<"LCS is \""<<result<<"\""<<endl;
    delete str1,str2,result;
    return 0;
}

char* lcs(char* str1, char* str2) {
    int lenStr1 = strlen(str1);
    int lenStr2 = strlen(str2);
    int maxCommonStrLength = 0;
    int **matrix = new int*[lenStr1+1];
    char* retStr;
    for(int i=0; i<=lenStr1; i++) {
        matrix[i] = new int[lenStr2+1];
    }
    for(int i=0; i<=lenStr1; i++) 
        for(int j=0; j<=lenStr2; j++)
            matrix[i][j] = 0;
    for(int i=1; i<=lenStr1; i++) {
        for(int j=1; j<=lenStr2; j++) {
            if(str1[i-1]==str2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1]+1;
            } else {
                matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]);
            }
        }
    }
    maxCommonStrLength = matrix[lenStr1][lenStr2];
    retStr = new char[maxCommonStrLength];
    retStr[maxCommonStrLength] = 0;
    for(int i=lenStr1, j=lenStr2, k=maxCommonStrLength-1; i>0&&j>0; ) {
        if(str1[i-1] == str2[j-1]) {
            retStr[k--] = str1[i-1];
            i--;
            j--;
        } else if(matrix[i-1][j] > matrix[i][j-1]){
            i--;
        } else {
            j--;
        }
    }
    return retStr;
}