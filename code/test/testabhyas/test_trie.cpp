#include "test_trie.h"

TrieTest::TrieTest() : _root(new trie_node())
{
    // Initializae the trie here
    add_word(_root, "word");
    add_word(_root, "wonder");
    add_word(_root, "wind");
    add_word(_root, "whale");
}

TrieTest::~TrieTest() 
{
    destroy(_root);    
}

void TrieTest::SetUp() {};

void TrieTest::TearDown() {};

TEST_F(TrieTest, SearchAnAddedWordInTrie)
{
    EXPECT_EQ( search(_root, "wonder"), true);
}

TEST_F(TrieTest, SearchForANonExistentWordInTrie)
{
    EXPECT_EQ( search(_root, "wonderful"), false);
}

