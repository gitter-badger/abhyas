#ifndef __ABHYAS_TEST_TRIE_H
#define __ABHYAS_TEST_TRIE_H

#include "gtest/gtest.h"
#include "trie.h"

// The fixture for testing library trie
class TrieTest : public ::testing::Test {

protected:

    // Set-up work for each test here.
    TrieTest();

    // Clean-up but do not throw exceptionse.
    virtual ~TrieTest();

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    // Code here will be called immediately after the constructor
    // (just before the destructor).
    virtual void SetUp();

    // Code here will be called immediately after each test 
    // (just before the destructor).
    virtual void TearDown();

    trie_node* _root;
};

#endif


