typedef struct StringList{
	char character;
	struct StringList *next;

} StringList;

// return a new stringlist node with the char c inside
StringList *newNode(char c){
	StringList *node = (StringList *)calloc(1, sizeof(StringList))
	node -> character = c;
	node -> next = NULL;
	return node;

}

//create a new StringList node and insert at the end of the linked list

void insertAtTail(StringList *head, char c){
	StringList *traverse = head;
	while (traverse -> next != NULL){
		traverse = traverse -> next
	}
	StringList *newNode = newNode(c);
	traverse -> next = newNode;
	newNode -> next = NULL;

}

// convert the string to a string list
// abc to a -> b -> c
StringList *toStringList(char *input){


}

// traverse through linked list and print
void printList(StringList *head){



}

// Delete the first occurence of c from the linked list

StringList *deleteChar(StringList *head, char c){
	if (head -> character == c){
		StringList *remove = head;
		head = head -> next
		free(remove)
		remove -> next = NULL;
		return head
	}

	StringList *prev = head;
	StringList *trav = head -> next;
	while(trav -> character != 'c'){
		trav = trav -> next
		prev = prev -> next
	}
	prev -> next = trav -> next;
	free(trav);
	trav -> next = NULL;

	// have to add situation where there is no c

	
	


}

//given the head of a linked list, return a new list with order reversed.
// a-> b -> c
// c -> b -> a

StringList *reverse(StringList *head){

	StringList *current = head;
    StringList *prev = NULL;
    StringList *next = NULL;
  
    while (current != NULL) {
        next = current->next;
  		current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;   
}

