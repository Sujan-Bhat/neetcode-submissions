class Solution {
public:
    bool isValid(string s) {
        int n = size(s)-1;
        vector<int> stk;
        int top =0;
        stk.push_back(s[0]);
        for(int i=1;i<=n;i++){
            if(pair(stk[top],s[i])){
                top=top-1;
                stk.pop_back();
            }
            else{
                top=top+1;
                stk.push_back(s[i]);
            }
        }
        if(top<0){
            return true;
        }
        return false;

    }
    private:
    bool pair(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }
};
