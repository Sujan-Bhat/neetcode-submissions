class Solution {
public:
    bool isAlphanumeric(char ch) {
        bool isLower = (ch >= 'a' && ch <= 'z');
        bool isUpper = (ch >= 'A' && ch <= 'Z');
        bool isDigit = (ch >= '0' && ch <= '9');
    
        return isLower || isUpper || isDigit;
    }

    char toLowerCase(char ch){
        if(ch >='A' && ch <='Z'){
            ch = ch + 32;
        }
        return ch;
    }

    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while(i < j){
            if(!isAlphanumeric(s[i])){
                i++;
                continue;
            }
            if(!isAlphanumeric(s[j])){
                j--;
                continue;
            }
     
            if(toLowerCase(s[i]) != toLowerCase(s[j])){
                return false;
            }
            

            i++;
            j--;
        }

        return true;
    }
};
