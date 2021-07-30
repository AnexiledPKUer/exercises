//
// Created by Administrator on 2021/7/25.
//
#include<iostream>
#include <string>
using namespace std;

int LongestSubstringKCharacters(string &s, int k);

int nonZero(int array[],int n){
    int r=0;
    for (int i=0;i<n;i++){
        if (array[i]!=0) r++;
    }
    return r;
}


int LongestSubstringKCharacters(string &s, int k){
    int finalLen=0;
    int tempLen=0;
    int cnt[128]={0};
    int leftPtr=0;int rightPtr=0;

    while (rightPtr<s.size()){
        ++cnt[s[rightPtr]];//
        if(nonZero(cnt,128)<=k) {
            ++tempLen;
            ++rightPtr;
            continue;
        }
        //此时rightPtr所指元素无能再加进去
        finalLen=tempLen>finalLen ? tempLen:finalLen;
        ++tempLen;
        while(nonZero(cnt,128)>k){
            --cnt[s[leftPtr]];
            ++leftPtr;
            --tempLen;
        }
        ++rightPtr;
    }
    finalLen=tempLen>finalLen ? tempLen:finalLen;
    return finalLen;
}

int main(){
    string s="ababaaaaaaaaaaaacdcdcdcdcdcda";
    cout<<LongestSubstringKCharacters(s,1)<<endl;
    return 0;
}

