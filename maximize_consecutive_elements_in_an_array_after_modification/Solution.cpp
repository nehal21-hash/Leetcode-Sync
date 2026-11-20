class Solution {
public:
    bool check(vector<int>&v,int mid){
        int n= (int)v.size();
        for(int i=n-1;i>=0;--i){
            if(mid-v[i]<=1 && mid>=v[i]){
                mid--;
            }
        }
        return mid <=0;
    }
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l = 0 , h = (int)nums.size()+10;
        while(h-l>1){
            int mid = (l+h)>>1;
            if(check(nums,mid)){
                l = mid;
            }else{
                h = mid-1;
            }
        }
        return (check(nums,h)? h : l);
    }
};