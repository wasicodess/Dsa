class Solution {
public:
    vector<int> pse(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> nse(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--) {

            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {

        long long total = 0;
        int n = arr.size();
        int MOD = 1e9 + 7;

        vector<int> p = pse(arr);
        vector<int> ne = nse(arr);

        for(int i = 0; i < n; i++) {

            long long left = i - p[i];
            long long right = ne[i] - i;

            total = (total + left * right * arr[i]) % MOD;
        }

        return total;
    }
};