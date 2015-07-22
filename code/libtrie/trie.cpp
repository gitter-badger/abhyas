#include <cstdio>
#include <cassert>
#include <string>
#include <vector>

#include "trie.h"

enum type {WORD, PREFIX};

// Support only English language
static const unsigned int MAX_LEVELS = 10;
static const unsigned char START_CHARACTER = 'a';

trie_node* create_node()
{
    trie_node* node     = new trie_node();
    node->word_count    = 0;
    node->prefix_count  = 0;
    for (int i = 0; i < trie_node::SIZE_CHARSET; ++i)
        node->children[i] = NULL;
    return node;
}

// Recursively delete the children of a node 
// if they exist
void destroy(trie_node* node, int level)
{
    assert(node != NULL);

    if (node->word_count > 0 || node->prefix_count > 0)
    {
        for (int i = 0; i < trie_node::SIZE_CHARSET; ++i)
        {
            if (node->children[i])
            {
                destroy(node->children[i], level + 1);
            }

            delete node->children[i];
        }
        
    }
}

// Recursively navigate the trie to add a word
// chopping of a character at each iteration.
void add_word(trie_node* node, const char* word, int index)
{
    assert(node != NULL);

    // Have we processed the whole word?
    if (index < strlen(word))
    {
        node->prefix_count += 1;
        int position = word[index] - START_CHARACTER;
        if (node->children[position] == NULL)
        {
            trie_node* child = create_node();
            node->children[position] = child;
        }

        add_word(node->children[position], word, index + 1);
    }
    else
    {
        // This node finishes a word
        node->word_count += 1 ;
    }
}

bool search(trie_node* node, const char* word, int index)
{
    // We have found the word if during the recursion
    // we reached 
    if (index == strlen(word))
        return true;

    int position = word[index] - START_CHARACTER;
    if (node->children[position] != NULL)
    {
        printf("Matched: %c\n", START_CHARACTER + position);
        return search(node->children[position], word, index + 1);
    }

    return false;
}

void collect(trie_node* node, std::vector<std::string>& v, int level = 0)
{
    for (int i = 0; i < trie_node::SIZE_CHARSET; ++i)
    {
        if (node->children[i] != NULL)
        {
            v[level].append(1, START_CHARACTER + i);
            collect(node->children[i], v , level + 1);
        }
    }
}

void print_trie(trie_node* start)
{
    std::vector<std::string> levels(MAX_LEVELS);

    collect(start, levels);

    for (int i = 0; i < MAX_LEVELS; ++i)
        if (levels[i].size() > 0)
            printf("%s\n", levels[i].c_str());
}

