class Solution {
public:
    int myAtoi(string s) {
        
        if(s.empty())
            return 0;
        
        int i=0;
        while(i<s.size() && s[i]==' ')
            i++;
        
        bool sign = true;
        if(i<s.size() && s[i]=='-')
            sign=false;
        
        if(i<s.size() && ((s[i]=='+') || (s[i]=='-')))
            i++;
        
        while(i<s.size() && s[i]=='0')
            i++;
        
        int ans =0;
        while(i<s.size() && s[i]>='0' && s[i]<='9'){
            
            int k=s[i]-'0';
            
            if(!sign){
                if(ans < (INT_MIN + k)/10 ){
                    ans = INT_MIN;
                    break;
                }
                else
                    ans = (ans*10)-k;
            }
            else{
                if(ans >(INT_MAX - k)/10){
                    ans = INT_MAX;
                    break;
                }
                else
                    ans = (ans*10)+k;
            }
            i++;
        }
        return ans;
    }
};
