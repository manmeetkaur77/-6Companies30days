class Solution {
public:
    int func(vector<int>& num, int k,int n){
        /////
        if(k<0)return 0;
        int l=0;
        int r=0;
        int sum=0;
        int cnt=0;
        while(r<n){
            sum+=num[r];
            while(sum>k){
                sum=sum-num[l];
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>num(n);
        for(int i=0;i<n;i++){
            num[i]=nums[i]%2;
        }
        return func(num,k,n)-func(num,k-1,n);
    }
};