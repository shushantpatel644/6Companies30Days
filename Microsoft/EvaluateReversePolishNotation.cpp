// #include <bits/stdc++.h>
// using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (auto s : tokens)
        {
            if (s == "+" || s == "-" || s == "/" || s == "*")
            {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();

                if (s == "+")
                {
                    st.push(op1 + op2);
                }
                if (s == "-")
                {
                    st.push(op1 - op2);
                }
                if (s == "*")
                {
                    st.push(op1 * op2);
                }
                if (s == "/")
                {
                    st.push(op1 / op2);
                }
            }
            else
            {
                stringstream ss(s);
                int data;
                ss >> data;
                st.push(data);
            }
        }
        return st.top();
    }
};