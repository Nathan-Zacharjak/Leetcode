class TrieNode {
private:
    array<TrieNode*, 26> children;
    bool isEnd = false;

public:
    TrieNode(){
        for (auto& child: children){
            child = nullptr;
        }
    }

    TrieNode* AddChild(const char& c){
        return children[c - 'a'] = new TrieNode;
    }

    bool HasChild(const char& c){
        return children[c - 'a'] != nullptr;
    }

    TrieNode* GetChild(const char& c){
        return children[c - 'a'];
    }

    void SetEnd(){
        isEnd = true;
    }

    bool IsEnd(){
        return isEnd;
    }
};

class Trie {
private:
    TrieNode* head;
public:
    Trie() {
        head = new TrieNode;
    }
    
    void insert(string word) {
        TrieNode* currentNode = head;

        for (const auto& c: word){
            if (currentNode->HasChild(c)){
                currentNode = currentNode->GetChild(c);
            } else {
                currentNode = currentNode->AddChild(c);
            }
        }

        currentNode->SetEnd();
    }
    
    bool search(string word, bool isPrefix = false) {
        TrieNode* currentNode = head;

        for (const auto& c: word){
            if (currentNode->HasChild(c)){
                currentNode = currentNode->GetChild(c);
            } else {
                return false;
            }
        }

        return currentNode->IsEnd() || isPrefix;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */