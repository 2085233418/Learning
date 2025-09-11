
/*中心扩展算法*/
/*
int length(char*s,int left,int right,int*start){
    while(left>=0&&right<strlen(s)&&s[left]==s[right]){
        *start=left;
        left--;
        right++;
        
    }
    return right-left-1;
}char* longestPalindrome(char* s) {
    if(s==NULL||strlen(s)==1){
        return s;
    }
    int max=0;
    int start=0;
    for(int i=0;i<strlen(s);i++){
        int start1;
        int start2;
        int odd=length(s,i,i,&start1);
        int eve=length(s,i,i+1,&start2);
        if(odd>max){
            max=odd;
            start=start1;
        }
        if(eve>max){
            max=eve;
            start=start2;
        }
    } 
    char* result=(char*)malloc((max+1)*sizeof(char));
     strncpy(result, s + start, max); 
    result[max]='\0';
    return result;
}
*/