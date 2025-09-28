#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "queue.h"

Queue *makeQueue() {

    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    
    return q;
}

int q_length (Queue * q) {

    int count = 0;
    Node *current = q->head;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}


bool promote(Queue *q, Node const *example) {

    if (q->head == NULL) {
        return false;
    }

    if (q->head->equals(q->head, example)) {
        return true;
    }
	Node *prev = q->head;
	Node *current = q->head->next;
	


    while (current != NULL) {

        if (current->equals(current, example)) {

            prev->next = current->next;
            current->next = q->head;
            q->head = current;
    
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false;
}


void freeQueue(Queue *q) {

//	printf (" In freeQueue \n");

    Node *current = q->head;
    Node *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    free(q);
}


void enqueue(Queue *queue, Node *node) {

    node->next = NULL; 

    if (queue->head == NULL) {

        queue->head = node;
        queue->tail = &node->next;
    } else {
        queue->tail = &node->next;

    }

}


Node *dequeue(Queue *queue) {

    if (queue->head == NULL) {
        return NULL;
    }
    Node *node = queue->head;
    queue->head = queue->head->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    return node;
}

void print_queue(const Queue *queue) {

    int cnt = 0;
    
    Node *node = queue->head;

    while (node != NULL) {
    	cnt++;


        node->print(node);
        printf(" ");
        node = node->next;
    }
    printf("\n");
}
