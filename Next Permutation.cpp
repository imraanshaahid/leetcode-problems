class Solution {
public:
    void nextPermutation(vector<int>& nums) {        
        
        //next_permutation(nums.begin(), nums.end());
        int l = nums.size();
        int i=0; int j=nums.size()-1;
        
        while(j>0 && nums[j]<=nums[j-1]){
            j--;
        }
        
        if(j==0){
            int x=0; int y=nums.size()-1;
            while(x<y){
                int t=nums[x];
                nums[x]=nums[y];
                nums[y]=t;
                x++,y--;
            }
            return;
        }
        
        int x=nums[j-1];
        i=j;int diff=INT_MAX;int idx;
        while(i<l){
            int d = nums[i]-x;
            if(d<=0){
                i++;
                continue;
            }
            if(d<=diff){
                diff=d;
                idx=i;
            }
            i++;
        }
        
        swap(nums[j-1], nums[idx]);
        
        reverse(nums.begin()+j, nums.end());
    }
};
