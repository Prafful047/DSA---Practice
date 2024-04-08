int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();

        queue<int> qu;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            qu.push(students[i]);
            st.push(sandwiches[n - i - 1]);
        }

        while (!qu.empty()) {
            int quSize = qu.size();
            cout<<quSize<<endl;
            bool flag = true;
            while (quSize--) {
                if (st.top() == qu.front()) {
                    st.pop();
                    qu.pop();
                    flag = false;
                } else {
                    int temp = qu.front();
                    qu.pop();
                    qu.push(temp);
                }
            }

            if(flag){
                return qu.size();
            }
        }

        return qu.size();
    }