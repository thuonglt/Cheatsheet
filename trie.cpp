struct Trie {
    vector<*Trie> sub;
    Trie() {
        sub.resize(26, NULL);

    }

    void add(string s, int index) {
        if(index == s.size()) return;
        if(sub[s[index] - 'a'] == NULL) {
            sub[s[index] - 'a'] = new Trie();
        }
        sub[s[index] - 'a'].add(s, index+1);
    }
};
