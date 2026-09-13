class PrefixTree {

private:
    struct Node{
        bool isEnd;
        vector<Node*>children;
        Node(){
            isEnd = false;
            for(int i=0;i<26;i++){
                children.push_back(nullptr);
            }
        }
    };
    Node* root;

public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node*cur = root;
        for(char c:word){
            if(!cur->children[c-'a']){
                cur->children[c-'a'] = new Node();
            }
            cur = cur->children[c-'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        Node*cur = root;
        for(char c:word){
            if(!cur->children[c-'a']){
                return false;
            }
            cur = cur->children[c-'a'];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node*cur = root;
        for(char c:prefix){
            if(!cur->children[c-'a']){
                return false;
            }
            cur = cur->children[c-'a'];
        }
        return true;
    }
};
