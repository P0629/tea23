#include <fmt/chrono.h>
#include <fmt/format.h>

#include "list.hpp"
#include "vector.hpp"

int bss;
int bss2;


auto main(int argc, char** argv) -> int
{
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", argv[0]);
     fmt::print("Hello, {} bss: {}, bss2: {}!\n", argv[0], bss, bss2);

    ListNode_t* node = NewListNode();
    ListNode_t* elem = NewListNode();
    // FreeListNode(node);

    List_t* list =  NewList();
    // FreeList(list);

    int ret = EXIT_FAILURE;
    ret = InsertIntoLinkedList(list, node);
    fmt::println("Return value of: {}",ret);

     ret = InsertIntoLinkedListAfterNode(list, node, elem);
    fmt::println("Return value of: {}",ret);

    ret = RemoveFromList(list, elem);
    fmt::println("Return value of: {}",ret);
    ListNode_t* node2 =  GetNext(list, elem);


    // =       AB HIER: 4.1 Test der Liste (minimaler Block)      =

    fmt::println("\n===== Aufgabe 4.1: Liste testen =====");

    List_t* myList = NewList();

    // 5 Knoten erzeugen
    ListNode_t* n1 = NewListNode();
    ListNode_t* n2 = NewListNode();
    ListNode_t* n3 = NewListNode();
    ListNode_t* n4 = NewListNode();
    ListNode_t* n5 = NewListNode();

    // Werte zuweisen
    n1->data = 10;
    n2->data = 20;
    n3->data = 30;
    n4->data = 40;
    n5->data = 50;

    // Einfügen am Ende
    InsertIntoLinkedList(myList, n1);
    InsertIntoLinkedList(myList, n2);
    InsertIntoLinkedList(myList, n3);
    InsertIntoLinkedList(myList, n4);
    InsertIntoLinkedList(myList, n5);

    // Einfügen nach dem zweiten Knoten
    ListNode_t* nAfter = NewListNode();
    nAfter->data = 99;
    InsertIntoLinkedListAfterNode(myList, n2, nAfter);

    // Entfernen eines Elements (z. B. n4)
    RemoveFromList(myList, n4);

    // Traversieren und Ausgabe
    fmt::println("Inhalt der Liste nach allen Operationen:");
    for (ListNode_t* n = GetNext(myList, NULL); n != NULL; n = GetNext(myList, n)) {
        fmt::print("{} ", n->data);
    }
    fmt::println("");

    // Liste freigeben
    FreeList(myList);

   

    return 0; /* exit gracefully*/
}
