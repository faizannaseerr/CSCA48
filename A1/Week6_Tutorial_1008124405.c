StringList *reverse(StringList *head){

	StringList *current = head;
    StringList *prev = NULL;
    StringList *next = NULL;
  
    while (current != NULL) {
        next = current -> next;
  		current -> next = prev;
        prev = current;
        current = next;
    }
    head = prev; 
    return head;  
}