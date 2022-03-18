#include<stdio.h>
#include<stdbool.h>

bool isPalindrome(int x){
    if(x < 0)
        return false;
    int copy = x;
    long int rev = 0;
    while(x){
        rev = rev*10 + (x%10);
        x /= 10;
    }
    return rev == copy;
}