// Infix to Postfix Conversion using Stack in C++

#include <bits/stdc++.h>

using namespace std;

string InfixToPostfix(string s)
{
    stack<char> st;
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/'&&s[i]!=')'&&s[i]!='('&&s[i]!='^')
            ans+=s[i];
            else
            {
              if(st.empty())
                st.push(s[i]);
                else
                {
                    if(s[i]=='+')
                 {
                      if(!st.empty()&&(st.top()=='('||st.top()==')'))
                        st.push('+');
                     else
                        {
                           while(!st.empty()&&!(st.top()=='('))
                            {
                                ans+=st.top();
                                st.pop();
                            }

                            st.push('+');

                        }

                    }
                    else if(s[i]=='-')
                    {
                        if(!st.empty()&&(st.top()=='('||st.top()==')'))
                        st.push('-');
                        else
                        {
                            while(!st.empty()&&!(st.top()=='('))
                            {
                                ans+=st.top();
                                st.pop();
                            }
                            st.push('-');
                        }
                    }
                    else if(s[i]=='^')
                    {
                        st.push('^');
                    }
                    else if(s[i]=='*')
                    {
                        if(st.top()=='-'||st.top()=='+'||st.top()=='('||st.top()==')')
                        st.push('*');
                        else
                        {
                            while(!st.empty()&&!(st.top()=='-'||st.top()=='+'||st.top()=='('||st.top()==')'))
                            {
                              ans+=st.top();
                                st.pop();
                            }
                            st.push('*');
                        }
                    }
                    else if(s[i]=='/')

                    {
                        if(st.top()=='-'||st.top()=='+'||st.top()=='('||st.top()==')')
                        st.push('/');
                        else
                        {
                            while(!st.empty()&&!(st.top()=='-'||st.top()=='+'||st.top()=='('||st.top()==')'))
                          {
                                ans+=st.top();
                                st.pop();
                            }
                            st.push('/');
                        }
                    }
                    else if(s[i]==')')
                    {
                        while(!st.empty()&&(st.top()!='('))
                        {
                            ans+=st.top();
                            st.pop();
                        }
                        st.pop();
                    }
                    else if(s[i]=='(')

                    {

                        st.push('(');

                    }
                }
            }
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }

int main()
{
    string expression = "a+b*(c^d-e)^(f+g*h)-i";
    cout << InfixToPostfix(expression) << endl;
}

// Output
// abcd^e-fgh*+^*+i-