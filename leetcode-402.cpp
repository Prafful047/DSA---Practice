string removeKdigits(string num, int k) {
        int n = num.length();
        string s = "";

        if (n == k) {
            return "0";
        }

        for (int i = 0; i < n; i++) {
            while (k > 0 && !s.empty() && s.back() > num[i]) {
                s.pop_back();
                k--;
            }
            s.push_back(num[i]);
        }

        while (k > 0 && !s.empty()) {
            s.pop_back();
            k--;
        }

        int i = 0;
        while (i < s.length() && s[i] == '0') {
            i++;
        }

        s = s.substr(i);

        if (s.empty()) {
            return "0";
        }

        return s;
    }