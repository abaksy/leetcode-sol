#include<stdio.h>
#include<string.h>

int lengthOfLastWord(char * s){
    int len = strlen(s);
    int idx = len-1;
    int wordLen = 0;
    while(idx >= 0)
    {
        if(wordLen > 0 && s[idx] == ' ')
            break;
        else if(wordLen >= 0 && s[idx] != ' ')
            wordLen++;
        idx --;
    }
    return wordLen;
}

int main()
{
    char* s = "   fly me   to   the moon  ";
    int len_last_word = lengthOfLastWord(s);
    printf("The length of last word is: %d\n", len_last_word);
    return 0;
}