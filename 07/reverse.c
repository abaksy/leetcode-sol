#include<limits.h>


int reverse(int x){
    int max = INT_MAX/10;
    int min = INT_MIN/10;
    int rev = 0;
    int ld;
    while(x)
    {
        ld = x % 10;
        x /= 10;
        if(rev > max || rev < min)
            return 0;
        rev = (rev*10) + ld;
    }
    return rev;
}