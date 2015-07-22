#ifndef __ABHYASI_TRIE_H
#define __ABHYASI_TRIE_H

struct trie_node
{
    static const unsigned int SIZE_CHARSET = 26;

    int word_count;
    int prefix_count;
    trie_node* children[SIZE_CHARSET];
};

trie_node* create();
void destroy(trie_node* node, int level = 0);
void add_word(trie_node* node, const char* word, int index = 0);
bool search(trie_node* node, const char* word, int index = 0);
void print_trie(trie_node* start);

#endif

