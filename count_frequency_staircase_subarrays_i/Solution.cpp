class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        for(int i=1;i<60;++i){
            int len = (i+1)*i /2;
            int tempans =0;
            for(int j=0;j<n;++j){
                if(j+len-1>=n)continue;
                map<int,int>ms;
                vector<int>v;
                int k=0;
                while(k !=len){
                    if(ms[nums[j+k]] == 0){
                        v.push_back(nums[j+k]);
                    }
                    ms[nums[j+k]]++;
                    k++;
                }
                
                bool ok = true;
                int cnt =1;
                for(auto &x:v){
                    if(ms[x] != cnt){
                        ok = false;
                        break ;
                    }
                    cnt++;
                }
                if(len == 3 && ok){
                    cout<<j<<endl;
                }
                ans+=ok;
                tempans+=ok;
            }
            //cout<<i<<" "<<tempans<<endl;
        }
        return ans;
    }
};