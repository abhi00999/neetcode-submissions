class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> res(n,0);

        for(int i = 0; i<n; i++){
            while(st.size() && temperatures[i] > temperatures[st.top()]){
                int cur = st.top();
                st.pop();
                res[cur] = i-cur;
            }
            st.push(i);
        }
        while(st.size()){
            int cur = st.top();
            st.pop();
            res[cur] = 0; 
        }
        return res;
    }
};
