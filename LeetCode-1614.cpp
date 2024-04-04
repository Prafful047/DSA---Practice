int maxDepth(string s) {
        int n = s.length();
        int maxDepth = -1;
        vector<int>arr(2,0);
        for(int i=0 ; i<n ; i++){
            if(s[i]=='('){
                arr[0]++;
            }

            if(s[i]==')' ){
                arr[1]++;
            }

            if(arr[1]>0){
                arr[0] -= arr[1];
                arr[1] = 0;
            }

            maxDepth = max(maxDepth, arr[0]);
        }

        return maxDepth;
    }