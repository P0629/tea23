// #include "list.hpp"

// #include <stdio.h>
// #include <stdlib.h>

// #include <fmt/format.h>

// // 2.1 Knotenverwaltung

// ListNode_t* NewListNode(void) {
//     fmt::println("in \"{}\"",__func__);

//     ListNode_t* node = (ListNode_t*)malloc(sizeof(ListNode_t));
//     if (!node) return NULL;

//     node->data = 0;
//     node->pNext = NULL;
//     return NULL;
// }

// void FreeListNode(ListNode_t* elem) {
//     fmt::println("in \"{}\"",__func__);
//     free(elem);

// }

// // 2.2 Listenverwaltung

// List_t* NewList(void) {
//     fmt::println("in \"{}\"",__func__);

//     List_t* list = (List_t*)malloc(sizeof(List_t));
//     if (!list) return NULL;

//     list->pHead = NULL;
//     list->pTail = NULL;
//     list->size = 0;

//     return NULL;
// }

// void FreeList(List_t* list) {
//     fmt::println("in \"{}\"",__func__);

//     ListNode_t* n = list->pHead;
//     while (n != NULL) {
//         ListNode_t* next = n->pNext;
//         FreeListNode(n);
//         n = next;
//     }

//     free(list);
// }


// // 2.3 Einfügen

// int InsertIntoLinkedList(List_t* list, ListNode_t* elem) {
//     fmt::println("in \"{}\"",__func__);

//     if (!list || !elem) return EXIT_FAILURE;

//     elem->pNext = NULL;                // immer am Ende

//     if (list->pTail == NULL) {
//         // leere Liste
//         list->pHead = elem;
//         list->pTail = elem;
//     } else {
//         // nicht leere Liste
//         list->pTail->pNext = elem;
//         list->pTail = elem;
//     }

//     list->size++;
//     return EXIT_SUCCESS;
// }

// int InsertIntoLinkedListAfterNode(List_t* list, ListNode_t* node /* the node we insert the element into */, ListNode_t* elem) {
//     fmt::println("in \"{}\"",__func__);

//     if (!list || !node || !elem) return EXIT_FAILURE;

//     elem->pNext = node->pNext;
//     node->pNext = elem;

//     if (node == list->pTail)
//         list->pTail = elem;

//     list->size++;
//     return EXIT_SUCCESS;
// }

// // 2.4 Entfernen

// int RemoveFromList(List_t* list, ListNode_t* elem) {
//     fmt::println("in \"{}\"",__func__);

//     if (!list || !elem) return EXIT_FAILURE;
//     if (!list->pHead) return EXIT_FAILURE;

//     // Element ist pHead
//     if (list->pHead == elem) {
//         list->pHead = elem->pNext;
//         if (elem == list->pTail) {
//             list->pTail = NULL;
//         }
//         FreeListNode(elem);
//         list->size--;
//     return EXIT_SUCCESS;
// }

// // Vorgänger suchen
//     ListNode_t* prev = list->pHead;
//     while (prev->pNext != NULL && prev->pNext != elem) {
//         prev = prev->pNext;
//     }

//     if (prev->pNext == NULL)
//         return EXIT_FAILURE; // nicht gefunden

//     prev->pNext = elem->pNext;

//     if (elem == list->pTail)
//         list->pTail = prev;

//     FreeListNode(elem);
//     list->size--;

//     return EXIT_SUCCESS;
// }

// // 2.5 Traversieren

// ListNode_t* GetNext(const List_t* list, ListNode_t* elem) {
//     fmt::println("in \"{}\"",__func__);

//     if (elem == NULL)
//         return list->pHead;
//     return NULL;
// }

#include "list.hpp"

#include <stdio.h>
#include <stdlib.h>

#include <fmt/format.h>

// 2.1 Knotenverwaltung

ListNode_t* NewListNode(void) {
    fmt::println("in \"{}\"", __func__);

    ListNode_t* node = (ListNode_t*)malloc(sizeof(ListNode_t));
    if (!node) return NULL;

    node->data = 0;
    node->pNext = NULL;
    return node;         // <-- fix: return the allocated node
}

void FreeListNode(ListNode_t* elem) {
    fmt::println("in \"{}\"", __func__);
    if (!elem) return;
    free(elem);
}

// 2.2 Listenverwaltung

List_t* NewList(void) {
    fmt::println("in \"{}\"", __func__);

    List_t* list = (List_t*)malloc(sizeof(List_t));
    if (!list) return NULL;

    list->pHead = NULL;
    list->pTail = NULL;
    list->size = 0;

    return list;         // <-- fix: return the allocated list
}

void FreeList(List_t* list) {
    fmt::println("in \"{}\"", __func__);
    if (!list) return;

    ListNode_t* n = list->pHead;
    while (n != NULL) {
        ListNode_t* next = n->pNext;
        FreeListNode(n);
        n = next;
    }

    free(list);
}

// 2.3 Einfügen

int InsertIntoLinkedList(List_t* list, ListNode_t* elem) {
    fmt::println("in \"{}\"", __func__);

    if (!list || !elem) return EXIT_FAILURE;

    elem->pNext = NULL;                // immer am Ende

    if (list->pTail == NULL) {
        // leere Liste
        list->pHead = elem;
        list->pTail = elem;
    } else {
        // nicht leere Liste
        list->pTail->pNext = elem;
        list->pTail = elem;
    }

    list->size++;
    return EXIT_SUCCESS;
}

int InsertIntoLinkedListAfterNode(List_t* list, ListNode_t* node /* the node we insert the element into */, ListNode_t* elem) {
    fmt::println("in \"{}\"", __func__);

    if (!list || !node || !elem) return EXIT_FAILURE;

    elem->pNext = node->pNext;
    node->pNext = elem;

    if (node == list->pTail)
        list->pTail = elem;

    list->size++;
    return EXIT_SUCCESS;
}

// 2.4 Entfernen

int RemoveFromList(List_t* list, ListNode_t* elem) {
    fmt::println("in \"{}\"", __func__);

    if (!list || !elem) return EXIT_FAILURE;
    if (!list->pHead) return EXIT_FAILURE;

    // Element ist pHead
    if (list->pHead == elem) {
        list->pHead = elem->pNext;
        if (elem == list->pTail) {
            list->pTail = NULL;
        }
        FreeListNode(elem);
        if (list->size > 0) list->size--;
        return EXIT_SUCCESS;
    }

    // Vorgänger suchen
    ListNode_t* prev = list->pHead;
    while (prev->pNext != NULL && prev->pNext != elem) {
        prev = prev->pNext;
    }

    if (prev->pNext == NULL)
        return EXIT_FAILURE; // nicht gefunden

    prev->pNext = elem->pNext;

    if (elem == list->pTail)
        list->pTail = prev;

    FreeListNode(elem);
    if (list->size > 0) list->size--;
    return EXIT_SUCCESS;
}

// 2.5 Traversieren

ListNode_t* GetNext(const List_t* list, ListNode_t* elem) {
    fmt::println("in \"{}\"", __func__);
    if (!list) return NULL;

    if (elem == NULL)
        return list->pHead;

    return elem->pNext;    // <-- fix: return next element
}
