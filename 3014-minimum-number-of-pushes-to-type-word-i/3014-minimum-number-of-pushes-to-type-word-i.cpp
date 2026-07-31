class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int ans = 0;
        int cnt = 1;
        int track = 1;
        while(n > 0) {
            ans += track;
            if(cnt % 8 == 0) track ++;
            cnt ++;
            n --;
        }
        return ans;
    }
};