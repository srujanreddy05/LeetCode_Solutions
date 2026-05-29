class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector <int> heights(cols,0);
        int maxArea = 0;
        for (int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j]=='1'){
                    heights[j]+= 1;
                }
                else {
                    heights[j]=0;
                }
            }
            maxArea = max(maxArea,LargestRectangleArea(heights));
        }
        return maxArea;
    }
    int LargestRectangleArea(vector<int> &heights){
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for (int i = 0; i<=n;i++){
            int h = (i == n) ? 0 : heights[i];
            while(!st.empty() && h < heights[st.top()]){
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};