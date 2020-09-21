class Trie {
    bool isEnd;
    Trie *next[26];
    string word; // 当前结点表示的词(可有可无)
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        memset(next,0,sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *root = this;
        for(auto ch : word)
        {
            if(root->next[ch - 'a'] == NULL)
            {
                root->next[ch - 'a'] = new Trie();
            }
            root = root->next[ch - 'a'];
        }
        root->isEnd = true;
        root->word = word;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *root = this;
        for(auto ch : word)
        {
            if(root->next[ch - 'a'] == NULL)
            {
                return false;
            }
            root = root->next[ch - 'a'];
        }
        return root->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node = this;
        for(auto ch : prefix)
        {
            if(node->next[ch - 'a'] == NULL)
            {
                return false;
            }
            node = node->next[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */