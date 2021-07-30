//
// Created by Administrator on 2021/7/25.
//
#include<iostream>
#include <valarray>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int i = 0, j = (int)sqrt(c);
        while(i<=j){
            long long int temp = (i*i +j*j) ;
            if(temp ==c){
                return true;
            }else if(temp<c){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
};
//int main() {
//    Solution * sss=new Solution();
//    cout<<sss->judgeSquareSum(5)<<endl;
//    return 0;
//}