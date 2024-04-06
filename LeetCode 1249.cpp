string minRemoveToMakeValid(string s) {
        int n = s.length();
        
        stack<int>idx;
        unordered_set<int>removeIdx;

        for(int i=0 ; i<n ; i++){
            if(s[i]=='('){
                idx.push(i);
            }else if(s[i]==')'){
                
                if(idx.empty()){
                    removeIdx.insert(i);
                }else{
                    idx.pop();
                }
            }
        }

        while(!idx.empty()){
            removeIdx.insert(idx.top());
            idx.pop();
        }

        string result = "";

        for(int i=0 ; i<n ; i++){
           if(removeIdx.find(i) == removeIdx.end()){
            result.push_back(s[i]);
           } 
        }

        return result;
    }