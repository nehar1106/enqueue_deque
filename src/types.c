/**
   @file types.c
   @author
   Implementation of linked list nodes for int values, real values
   (doubles) and string values.
*/

#include "types.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "queue.h"

/** Function used as the print method for an integer node. */
static void printIntNode( Node const *n )
{
  printf( "%d", * (int *) ( n->data ) );
}

static bool equalsIntNode(Node const *a, Node const *b) {
	
    if (b->print != printIntNode) {
        return false;
    }
    int *a_data = (int *)a->data;
    int *b_data = (int *)b->data;
    if (*a_data != *b_data) {
        return false;
    }
    return true;
}

static void printRealNode( Node const *n )
{
  printf( "%.3lf", * (double *) ( n->data ) );
}

static bool equalsRealNode(Node const *a, Node const *b) {


    if (b->print != printRealNode) {
        return false;
    }
    double *a_data = (double *)a->data;
    double *b_data = (double *)b->data;
    if (*a_data != *b_data) {
        return false;
    }
    return true;
}

static void printStringNode(Node const *n) {

	char str_val[100];
	str_val[0] = '\0';
	sscanf(n->data, "\"%[^\"]",str_val);

    printf("%s", str_val);
}



static bool equalsStringNode(Node const *a, Node const *b) {

    if (b->print != printStringNode) {

        return false;
    }

    char *a_data = (char *)a->data;

    char *b_data = (char *)b->data;

	if (strcmp(a_data, b_data) != 0) {

        return false;
    }
    
    return true;
}


Node *makeIntNode( char const *init )
{

	int int_val = 0;
	int cnt = 0;
	char rest[10];

	cnt = sscanf(init, "%d%s", &int_val, rest);

	if (cnt != 1) {return NULL;};

	Node *n = (Node *) malloc( sizeof( Node ) + sizeof( int ) );

	* (int *) n->data = int_val;

	n->print = printIntNode;
	n->equals = equalsIntNode;

	return n;

}

Node *makeRealNode( char const *init )
{
	
	double int_val = 0.0;
	int cnt = 0;
	char rest[10];


	cnt = sscanf(init, "%lf%s", &int_val, rest);
	if (cnt != 1) {return NULL;};


	Node *n = (Node *) malloc( sizeof( Node ) + sizeof( double ) );
	
	* (double *) n->data = int_val;
	n->print = printRealNode;

	n->equals = equalsRealNode;


	return n;

}



Node *makeStringNode(char const *init) {


    char int_val[strlen(init) + 1];
    int cnt = 0;
    
	char str_val[100];
	str_val[0] = '\0';
	cnt = sscanf(init, "\"%[^\"]\"",str_val);
	
	if (cnt != 1) {return NULL;};

	Node *n = (Node *)malloc(sizeof(Node) + (strlen(init) + 1));
	
    strcpy(n->data, init);

    n->print = printStringNode;
    n->equals = equalsStringNode;

    return n;
}

