#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;

struct Node {
    void *data;
    Node *next;
};

typedef struct {
    Node *head;
    Node *tail;
} LinkedList;

void LlPush(LinkedList *list, void *data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

typedef void (*IterFun)(void *data);

void LlIter(const LinkedList *list, IterFun fun) {
    const Node *cur = list->head;
    while (cur != NULL) {
        fun(cur->data);
        cur = cur->next;
    }
}

void LlFree(LinkedList *list) {
    Node *cur = list->head;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur->data);
        free(cur);
        cur = next;
    }
    list->head = NULL;
    list->tail = NULL;
}


// ---------------
typedef int grams;

typedef struct {
    char title[50];
    char language[50];
    int price;
    int pages;
    grams weight;
    int year;
} BookInfo;

BookInfo *enlighten(const BookInfo book) {
    BookInfo *aBook = malloc(sizeof(BookInfo));
    memcpy(aBook, &book, sizeof(BookInfo));
    return aBook;
}

void BiPrint(BookInfo *book) {
    printf("Title: %s, Language: %s, Price: %d, Pages: %d, Weight: %d, Year: %d\n",
           book->title, book->language, book->price, book->pages, book->weight, book->year);
}

int main(void) {
    LinkedList list = {NULL, NULL};

    LlPush(&list, enlighten((BookInfo){"Harry Potter and the Philosopher's Stone", "English", 555, 223, 555, 1997}));
    LlPush(&list, enlighten((BookInfo){"Harry Potter and the Chamber of Secrets", "English", 555, 251, 555, 1998}));
    LlPush(&list, enlighten((BookInfo){"Harry Potter and the Prisoner of Azkaban", "English", 555, 317, 555, 1999}));

    LlIter(&list, (IterFun) BiPrint);

    LlFree(&list);
    return 0;
}
