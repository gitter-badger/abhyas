#include <cstdio>
#include "trie.h"

int main()
{
    trie_node* root = new trie_node();
    add_word(root, "word");
    add_word(root, "wonder");
    add_word(root, "wind");
    add_word(root, "whale");

    print_trie(root);

    const char* text = "wonder";
    if( search(root, text) )
        printf("Found %s\n in Trie\n", text);
    else
        printf("%s does not exist in Trie\n", text);
    
    return 0;

}

