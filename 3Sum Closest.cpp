class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int i=0; int j=nums.size()-1;
        
        int ans=INT_MAX;
        int val=INT_MAX;
        for(int i=0;i<nums.size();i++){
            
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            int k=nums[i];
            int x=i+1; int y=nums.size()-1;
            int search = target-k;
            while(x<y){
                if(nums[x]+nums[y]==search)
                    return target;
                else if(nums[x]+nums[y]>search){
                    if(abs(nums[x]+nums[y]+k-target)<ans){
                        ans=abs(nums[x]+nums[y]+k-target);
                        val=nums[x]+nums[y]+k;
                    }
                    while(y>0 && nums[y]==nums[y-1])
                        y--;
                     y--;
                }
                else{
                    if(abs(nums[x]+nums[y]+k-target)<ans){
                        ans=abs(nums[x]+nums[y]+k-target);
                        val=nums[x]+nums[y]+k;
                    }
                    while(x<y && nums[x]==nums[x+1])
                        x++;
                    x++;
                }
            }
        }
        return val;
    }
};
