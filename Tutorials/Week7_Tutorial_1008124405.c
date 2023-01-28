#include <stdio.h>
#include <stdlib.h>
 
// Define StringList CDT
typedef struct StringList {
    char character;
    struct StringList *next;
} StringList;
 
// new linked list function
StringList *newNode(char c) {
    StringList *node = calloc(1, sizeof(StringList *));
    if (node == NULL) return NULL;
 
    node->character = c;
    node->next = NULL;
    return node;
}
 
// insert at tail
void insert(StringList *head, char c) {
    StringList *node = newNode(c);
    if (node == NULL) return;
 
    StringList *traverse = head;
    while (traverse != NULL) {
        traverse = traverse->next;
    }
    // at the last node
    traverse->next = node;
}
 
// print
void printList(StringList *head) {
    StringList *traverse = head;
 
    while (traverse != NULL) {
        printf("%c", traverse->character);
        traverse = traverse->next;
    }
    printf("\n");
    return;
}
 
int main() {
    StringList *head = newNode('a');
    insert(head, 'b');
    insert(head, 'c');
    insert(head, 'd');
    insert(head, 'e');
    printList(head);
}