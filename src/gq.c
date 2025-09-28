#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "input.h"
#include "queue.h"
#include "types.h"

/** List of all the node creation functions.  This is a chain of
    responsibility; we can keep trying these functions until we find
    one that knows how to parse the init string. */
static Node *(*nodeMakers[])( char const *init ) = {
  makeIntNode,
  makeRealNode,
  makeStringNode
};

// Include your Queue and Node struct definitions and functions here

Node *parse_and_create_node(char const *init) {
    int num_node_makers = sizeof(nodeMakers) / sizeof(nodeMakers[0]);

    for (int i = 0; i < num_node_makers; i++) {
        Node *node = nodeMakers[i](init);
      
        if (node) {
            return node;
        }
    }

    return NULL;


}

int main() {

    Queue *queue = makeQueue();

    char input[1024];
    char *str;
    char command[1024];
    char value[1024];
    char blanks[1024];
    char ch;
    Node *prev_node;
    prev_node = NULL;

	printf("cmd> ");
      
	while (fscanf( stdin, "%c", &ch ) == 1) {
	

		if (ch == EOF) {  break;}
		ungetc( ch, stdin);
		str = readLine ( stdin);   

		if (strcmp(str,"zzzzzz") != 0) 
		{printf ("%s\n", str);}

        sscanf(str, "%s", command);

        if (strcmp(command, "enqueue") == 0) {

			sscanf(str, "%s%*[ \t\v\r]%[^\n]",command, value);
			
            Node *node = parse_and_create_node(value);
            
            if (node) {
				if (prev_node != NULL)
				{
				prev_node->next = node;};
                enqueue(queue, node);
        
                prev_node = node;
                
            } else {
                printf("Invalid command\n");
            }
        } else if (strcmp(command, "dequeue") == 0) {
            Node *node = dequeue(queue);
            if (node) {
                node->print(node);
                printf ("\n");
                free(node);
            } else {
                printf("Queue is empty\n");
            }
        } else if (strcmp(command, "promote") == 0) {

			sscanf(str, "%s%*[ \t\v\r]%[^\n]",command, value);
            Node *node = parse_and_create_node(value);

            if (node) {
				if (promote(queue, node)) {
				
				Node *p1 = queue->head;
				Node *c1 = queue->head->next;
	
				while (c1 != NULL) {
					p1 = c1;
					c1 = c1->next;
				}
				prev_node = p1;
				}
				else 
				{
		        printf("Invalid command\n");
				}

            }
        } else if (strcmp(command, "length") == 0) {
            printf("%d\n", q_length(queue));
        } else if (strcmp(command, "quit") == 0) {
            freeQueue(queue);
            return 0;
        } else {
            printf("Invalid command\n");
        }
        printf ("\n%s ", "cmd>");

    }
}


