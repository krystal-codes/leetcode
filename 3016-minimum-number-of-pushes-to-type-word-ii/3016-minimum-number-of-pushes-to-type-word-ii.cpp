class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        unordered_map<char, int> freq;
        for(int i = 0 ; i < n ; i ++) {
            freq[word[i]] ++;
        }
        int ans = 0;
        int cnt = 0;
        int track = 1;
        vector<int> check;
        for (int i = 0 ; i < n ; i ++) {
            if(freq[word[i]] != 0) check.push_back(freq[word[i]]);
            freq[word[i]] = 0;
        }
        sort(check.begin(), check.end(), greater<int>());
        for (int i = 0 ; i < check.size() ; i ++) {
            ans += track * check[i];
            cnt ++;
            if(cnt % 8 == 0) track ++;
        }
        return ans;
    }
};