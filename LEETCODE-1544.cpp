string makeGood(string s) {

        int n = s.length();

        if(n==1){
            return s;
        }

        
        
        while(s != ""){
            bool flag = true;
            string ans = "";
            n = s.length();
            if(n==1){
                break;
            }
            for(int i=0 ; i<n-1 ; i++){
                if((s[i]-'a' == s[i+1]-'A') || (s[i]-'A' == s[i+1]-'a')){
                    flag = false;
                    i++;
                    if(i==(n-2)){
                        ans += s[i+1];
                    }
                    continue;
                }else{
                    ans += s[i];
                    if(i==(n-2)){
                        ans += s[i+1];
                    }
                    cout<<ans<<endl;
                }
            }
            s = ans;
            cout<<"1"<<s<<endl;
            if(flag){
                break;
            }
        }

        return s; 
        
    }