#include<limits.h>

int myAtoi(char * s){
    if(!s)
        return 0;
    int num = 0;
    int length = strlen(s);
    int i = 0;
    int positive = 1;
    
    
    while(i < length && s[i] == ' ')
        i++;
    
    if(s[i] == '+' || s[i] == '-')
    {
        positive = (s[i] == '+'? 1 : 0);
        i++;
    }
    
    if(s[i] - '0' < 0 || s[i] - '0' > 9){
            return 0;
    }
    
    while(s[i] >= '0' && s[i] <= '9')
    {
        if(num > INT_MAX/10 || (num == INT_MAX/10 && s[i] - '0' > 7))
            return positive? INT_MAX : INT_MIN;
        
        num = num*10 + (s[i]-'0');
        i++;
    }
    if(positive)
        return num;
    else
        return num*-1;
}