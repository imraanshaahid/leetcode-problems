class Solution {// 2 methods 1.DP 2.odd/even
public:
    
    string longestPalindrome(string s) {
     
       if(s.size()==0 || s.size()==1)
           return s;
        
        int l=s.size();
     
        int start=0, len=0;
        for(int i=0;i<l-1;i++){
            
            pallCheck(s, i, i, start, len); //"aaa"
            pallCheck(s, i, i+1, start, len); // "aa"
            
        }
    
        return s.substr(start, len);
    }
    
    void pallCheck(string s, int i, int j, int &start, int &len){
        
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--,j++;
        }           
        if(len<j-i-1){
            len=j-i-1;
            start=i+1;
        }
    }
    
};
