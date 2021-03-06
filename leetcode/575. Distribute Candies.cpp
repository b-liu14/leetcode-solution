// my solution
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        sort(candies.begin(), candies.end());
        int N = (int)candies.size() / 2;
        int ans = 0;
        int j = 0;
        for (int i = 0; i < N && j < 2*N; i ++) {
            ans ++;
            j ++;
            while (j < 2*N && candies[j] == candies[j-1]) {
                j ++;
            }
        }
        return ans;
    }
};

// concise solution using set
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set s;
        for (auto c: candies) {
            s.insert(c);
        }
        return min(candies.size() / 2, s.size());
    }
};
