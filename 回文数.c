bool isPalindrome(int x) {
    char str[20];
    sprintf(str, "%d", x);
    int length=strlen(str);
    for(int i=0;i<length/2;i++){
        if(str[i]==str[length-i-1]){
            continue;
        }
        else {
            return flase;
        }
    }
    return true;
}