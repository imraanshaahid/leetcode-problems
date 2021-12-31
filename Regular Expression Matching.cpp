class Solution {
public:
    
    bool **dp;//[100][100];
    
    bool func(string s, int i, int j, string p, int x, int y){
        
        if(x>y){
           return i>j;
        }
        
        bool firstCheck = false;
        
        if(!(i>j) && (s[i]==p[x] || p[x]=='.'))
            firstCheck = true;
        
        if((y-x)>=1 && p[x+1]=='*')
            return ((firstCheck && func(s, i+1, j, p, x, y)) || func(s, i, j, p, x+2, y));
        else
            return firstCheck && func(s, i+1, j, p, x+1, y); 
    }
    
    bool isMatch(string s, string p) {
        
     //  func(s, 0, s.size()-1, p, 0, p.size()-1);
      
        dp=new bool*[s.size()+2];
        for(int i=0;i<=s.size()+1;i++)
            dp[i]=new bool[p.size()+2];
        
        for(int i=0;i<=s.size()+1;i++)
            for(int j=0;j<=p.size()+1;j++)
                dp[i][j]=false;
        
          dp[s.size()][p.size()]=1;
       // vector<int> curr(p.size()+1), prev(p.size()+1);
        // for(int i=0;i<100;i++){
        //     curr[i]=false;prev[i]=false;
        // }
        //curr[p.size()]=1;//prev[p.size()]=1; 
        
        for(int i=s.size();i>=0;i--){
            for(int j=p.size()-1;j>=0;j--){ //else dp[s.size()][p.size()]=0;
                bool firstCheck = false;
                firstCheck = ((i<s.size() && s[i]==p[j]) || (j<p.size() && p[j]=='.'));
                
                if(j+1<p.size() && p[j+1]=='*'){
                    dp[i][j]=(firstCheck && dp[i+1][j]) || dp[i][j+2];
                 //   curr[j]=(firstCheck && prev[j]) || curr[j+2];
                }
                else{
                    dp[i][j]=firstCheck && dp[i+1][j+1];
                    //curr[j]=firstCheck && prev[j+1];
                }
            }
            //fill(prev.begin(), prev.end(), false);
			//swap(prev, curr);
        }
        return dp[0][0];
         //return prev[0];
    }
};
