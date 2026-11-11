class Solution {
public:
    long long func(int l, int r,string &s) {
        if(l >= r)return 1;
        long long cnt = 0, ans = 0;
        int j = l;
        for (int i = l; i <= r; i++) {
            if (s[i] == '(') cnt++;
            else cnt--;
            if (cnt == 0) {
                ans += func(j + 1, i - 1,s);
                j = i + 1;
            }
        }
        return 2 * ans;
    }
    int scoreOfParentheses(string s) {
        /*
        (M) - > 
        def func(l,r):
            int cnt =0;
            int ans = 0,j=l;
            for i - l to r:
                if ( cnt+=1
                else cnt-=1

                if(cnt ==0):
                    ans+=func(j,i);
                    j = i;
            
            return 2*ans

        */
        int ans =0,cnt=0,l = 0;
        for(int i=0;i<(int)s.size();++i){
            if(s[i] == '('){
                cnt++;
            }else{
                cnt--;
            }
            if(cnt == 0){
                ans+=func(l+1,i-1,s);
                l = i+1;
            }
        }
        return ans;
    }
};