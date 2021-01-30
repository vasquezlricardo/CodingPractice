#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Trie
{

    Trie()
        : mIsWordEnd(false)
    {
    }

    void addWord(string newWord)
    {
        if(newWord == "")
        {
            mIsWordEnd = true;
            return;
        }

        if(mMap.find(newWord[0]) == mMap.end())
            mMap[newWord[0]] = new Trie();

        mMap[newWord[0]]->addWord(newWord.substr(1));
    }

    void printWords()
    {
        rec_print("");
    }

private:
    void rec_print(string const prefix)
    {
        if(mIsWordEnd)
            cout << prefix << endl;

        for(auto& children : mMap)
        {
            children.second->rec_print(prefix + children.first);
        }
    }
    bool mIsWordEnd;
    map<char, Trie*> mMap;
};

int main()
{

    Trie myTrie;

    myTrie.addWord("hola");
    myTrie.addWord("holanda");
    myTrie.addWord("haha");
    myTrie.addWord("chao");

    myTrie.printWords();
    return 0;
}
