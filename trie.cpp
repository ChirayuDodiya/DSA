#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    
    bool flag = false;
    
    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }

    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag=true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            //moves to the reference trie
            node=node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node* node=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!node->containsKey(prefix[i]))
            {
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
    }
};

int main()
{
    Trie trie;
    int q;
    cin >> q;
    
    while(q--)
    {
        string operation, word;
        cin >> operation >> word;
        
        if(operation == "insert")
        {
            trie.insert(word);
            cout << "done\n";
        }
        else if(operation == "search")
        {
            cout << (trie.search(word) ? "found" : "not found") << "\n";
        }
        else if(operation == "startsWith")
        {
            cout << (trie.startsWith(word) ? "exists" : "don't exists") << "\n";
        }
    }
    
    return 0;
}