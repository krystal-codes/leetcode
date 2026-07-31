class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        set<int> st;
        for (int x : candyType) {
            st.insert(x);
        }
        int s = st.size();
        return min(s, n / 2);
    }
};