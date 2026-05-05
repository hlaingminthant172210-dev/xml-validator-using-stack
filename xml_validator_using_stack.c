#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data[50];
    struct node* next;
} nodeType, *NodePtr;

typedef struct {
    NodePtr top;
} stackSize, *Stack;

Stack initStack() {
    Stack sp = (Stack)malloc(sizeof(stackSize));
    sp->top = NULL;
    return sp;
}

int empty(Stack S) {
    return (S->top == NULL);
}

void push(Stack S, char *tag) {
    NodePtr np = (NodePtr)malloc(sizeof(nodeType));
    strcpy(np->data, tag);   // Copy each character from 'tag' into 'np->data'
    np->next = S->top;
    S->top = np;
}

char* pop(Stack S) {
    if (empty(S)){
        return NULL;
    }

    NodePtr temp = S->top;
    char *result = (char*)malloc(50);   
    strcpy(result, S->top->data);

    S->top = S->top->next;
    free(temp);

    return result;
}

int main() {

    Stack S = initStack();

    FILE *fp = fopen("test.xml", "r");

    if (!fp) {
        printf("File not found\n");
        return 0;
    }

    char ch;
    char tag[50];
    int i;

    while ((ch = fgetc(fp)) != EOF) {

        if (ch == '<') {
            i = 0;

            while ((ch = fgetc(fp)) != '>') {
                tag[i++] = ch;
            }
            tag[i] = '\0';

            if (tag[0] == '/') {
                char *topTag = pop(S);

                if (topTag == NULL || strcmp(topTag, tag + 1) != 0) {
                    printf("Invalid XML\n");
                    return 0;
                }

                free(topTag); // free memory after use
            }
            else {
                push(S, tag);
            }
        }
    }

    fclose(fp);

    if (empty(S))
        printf("Valid XML\n");
    else
        printf("Invalid XML\n");

    return 0;
}