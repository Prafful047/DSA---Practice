int lengthOfLastWord(string s) {

        int n = s.length();
        int maxcount;
        int count = 0;
        for(int i=n-1 ; i>=0 ; i--){

            if(s[i]==' '){

                if(count==0){
                    continue;
                }else{
                    maxcount = count;
                    break;
                }
            }else{
                count++;
            }
        }

        return maxcount;
        
    }