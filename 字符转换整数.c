int myAtoi(char* s) {
    int flag = 0;          // 标记是否已找到有效起始位置
    int len = strlen(s);
    int count = 0;         // 有效数字计数
    int a = 1;             // 正负标记，1为正，-1为负
    int start = 0;         // 数字开始位置
    
    for(int i = 0; i < len; i++) {
        if(flag == 0) {
            if(s[i] == ' ') {
                continue;
            }
            else if(s[i] == '+') {
                a = 1;
                flag = 1;
                start = i + 1;  
            }
            else if(s[i] == '-') {
                a = -1;
                flag = 1;
                start = i + 1; 
            }
            else if(s[i] >= '0' && s[i] <= '9') {
                flag = 1;
                start = i;      
                count = 1;      
            }
            else {

                return 0;
            }
        }
        else {
            if(s[i] >= '0' && s[i] <= '9') {
                count++; 
            }
            else {
                break;
            }
        }
    }
    
    if(count == 0) {
        return 0;
    }
    
    long long r = 0;
    for(int i = 0; i < count; i++) {
        r = 10 * r + (s[start + i] - '0');
        
        if(a == 1 && r > INT_MAX) {
            return INT_MAX;
        }
        if(a == -1 && -r < INT_MIN) {
            return INT_MIN;
        }
    }
    
    return a * (int)r;
}