#include <iostream>
#include <stdio.h>

using namespace std;
/**
	leetcode 第一题
	The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
	
	Example1: x = 123, return 321
    Example2: x = -123, return -321

**/
int reverse(int x) {
        long long int sum = 0;
        int m;
        while(1){
            m = x %10;
            x /= 10;
            
            sum = sum*10 + m;
            if(x==0)
            break;
        }
        // 溢出时返回0
        if(sum < INT_MIN || sum> INT_MAX)
        return 0;
        else{
            return sum;
        }
    }

int main(){

	return 0;
}