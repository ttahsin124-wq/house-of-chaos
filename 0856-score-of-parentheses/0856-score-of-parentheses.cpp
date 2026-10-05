class Solution {
public:
    int scoreOfParentheses(string s) {
    stack<int>score;
    score.push(0);
    for(char ch:s)
    {
        if(ch=='(')
        {
            score.push(0);
        }
        else
        {
            int top=score.top();
            score.pop();
            int A=max(2*top,1);
            int B=score.top();
            score.pop();
            score.push(A+B);
        }
    }
    return score.top();   
    }
};