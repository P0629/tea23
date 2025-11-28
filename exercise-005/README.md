# Übungsaufgabe Nr. 5 – Einfach verkettete Liste (API-basiert) & Mini-Vector

Diese Übung basiert vollständig auf folgendem **vorgegebenen Header**, der **unverändert** zu verwenden ist:

```cpp
#ifndef MY_FANCY_LINKED_LIST_H__
#define MY_FANCY_LINKED_LIST_H__

typedef struct ListNode {
    unsigned int data;
    struct ListNode* pNext;
} ListNode_t;

typedef struct List {
    ListNode_t* pHead;
    ListNode_t* pTail;
    unsigned int size;
} List_t;

ListNode_t* NewListNode(void);
void FreeListNode(ListNode_t* elem);

List_t* NewList(void);
void FreeList(List_t* list);

int InsertIntoLinkedList(List_t* list, ListNode_t* elem);
int InsertIntoLinkedListAfterNode(List_t* list, ListNode_t* node /* the node we insert the element into */, ListNode_t* elem);
int RemoveFromList(List_t* list, ListNode_t* elem);
ListNode_t* GetNext(const List_t* list, ListNode_t* elem);

#endif
```

Alle Funktionen, die Sie implementieren, müssen exakt diese API erfüllen.

---

## 1. Projektstruktur & Vorbereitung

Erstellen oder ergänzen Sie folgenden Ordner:

```
exercise-005/
  CMakeLists.txt
  main.cpp
  list.cpp
  list.hpp
  vector.cpp
  vector.hpp
  ANSWER.md
```

`list.hpp` enthält **genau** den vorgegebenen Header oben.

---

## 2. Aufgabe – Implementieren der verketteten Liste

Ihre Aufgabe ist es, alle Funktionen aus dem Header zu implementieren:

### 2.1 Knotenverwaltung

#### `NewListNode()`

- allokiert Speicher für einen neuen Knoten (Heap)
- setzt `data = 0`
- setzt `pNext = NULL`

#### `FreeListNode(elem)`

- gibt den Speicher wieder frei
- entfernt das Element **nicht automatisch** aus der Liste

---

### 2.2 Listenverwaltung

#### `NewList()`

- erzeugt eine neue Liste dynamisch auf dem Heap
- setzt `pHead = pTail = NULL`, `size = 0`

#### `FreeList(list)`

- traversiert die Liste
- ruft `FreeListNode()` für jeden Knoten auf
- gibt am Ende die Liste selbst frei

---

### 2.3 Einfügen

#### `InsertIntoLinkedList(list, elem)`

- fügt `elem` am **Ende** der Liste ein
- Sonderfälle:
  - leere Liste
  - nicht leere Liste
- `pTail` aktualisieren
- `size++`

#### `InsertIntoLinkedListAfterNode(list, node, elem)`

- fügt `elem` **nach** `node` ein
- wenn `node == pTail`, wird `pTail = elem`
- `size++`

---

### 2.4 Entfernen

#### `RemoveFromList(list, elem)`

- entfernt ein bestimmtes Element (nicht nur nach Vorgänger)
- muss den Vorgänger finden
- Sonderfälle:
  - Element ist `pHead`
  - Element ist `pTail`
- Element freigeben → `FreeListNode(elem)`
- `size--`

---

### 2.5 Traversieren

#### `GetNext(list, elem)`

- wenn `elem == NULL`, gebe `pHead` zurück
- sonst gebe `elem->pNext` zurück

Damit lässt sich die Liste wie folgt durchlaufen:

```cpp
for (ListNode_t* n = GetNext(list, NULL); n != NULL; n = GetNext(list, n)) {
    fmt::print("{} ", n->data);
}
```

---

## 3. Mini-Vector (dynamisches Array)

Implementieren Sie folgende Struktur:

```cpp
typedef struct Vector {
    unsigned int* data;
    size_t size;
    size_t capacity;
} Vector_t;
```

API:

```cpp
void vector_init(Vector_t* vec);
void vector_clear(Vector_t* vec);

int vector_push_back(Vector_t* vec, unsigned int value);
int vector_get(const Vector_t* vec, size_t index, unsigned int* outValue);
void vector_print(const Vector_t* vec);
```

### Anforderungen:

- Startkapazität = 4
- automatische Verdopplung der Kapazität bei Bedarf
- Verwendung von `malloc`/`free` oder `new[]`/`delete[]`
- Konsistenz mit Listen-Stil

---

## 4. Aufgabe – Testprogramm (main.cpp)

Ihr Testprogramm muss:

### 4.1 Liste testen

1. `List_t* list = NewList();`
2. Fünf neue Knoten erzeugen (`NewListNode()`), Werte manuell setzen, einfügen
3. Einfügen **nach dem zweiten Knoten**
4. Ein bestimmtes Element entfernen
5. Traversieren mit `GetNext`
6. Liste ausgeben

### 4.2 Vector testen

1. Vector initialisieren
2. Fünf Werte einfügen
3. Element an Index 2 ausgeben
4. Vector ausgeben

---

## 5. Aufgabe – Vergleich in `ANSWER.md`

Beantworten Sie kurz:

- Vorteile der verketteten Liste
- Nachteile der verketteten Liste
- Vorteile des Mini-Vectors
- Nachteile des Mini-Vectors
- Wann benutzt man welche Struktur?
- Was passiert wenn man die Elemente sortiert?
  - Beim Mini-Vector
  - Bei der Liste
- Wie würden Sie einen Binären Baum strukturieren?

---

## 6. Optional

- `vector_insert_at()` implementieren
- Zeitmessung mit `std::chrono` (Listen-Insert vs. Vector-Insert)

---

## Anhang A – Wiederholung: Strukturen in C/C++

Dieser Anhang ergänzt die Übungsaufgabe Nr. 5 und bietet eine kompakte Wiederholung zu **Strukturen**, **Zeigern**, **Heap/Stack**, sowie Zugriffssyntax (`.` vs. `->`). Er ist speziell für Studierende gedacht, die noch Schwierigkeiten mit C/C++-Grundlagen haben.

---

### 1. Was ist eine Struktur?

Eine Struktur fasst mehrere Werte zu einem neuen Datentyp zusammen.

```cpp
struct Point {
    int x;
    int y;
};
```

Verwendung:

```cpp
Point p;
p.x = 3;
p.y = 7;
```

---

### 2. typedef für Strukturen

Durch `typedef` kann die Verwendung vereinfacht werden:

```cpp
typedef struct ListNode {
    unsigned int data;
    struct ListNode* pNext;
} ListNode_t;
```

Ohne typedef müsste man schreiben:

```cpp
struct ListNode node;
```

Mit typedef genügt:

```cpp
ListNode_t node;
```

---

### 3. Stack vs. Heap

#### Stack-Allocation (automatisch)

```cpp
ListNode_t n;
n.data = 42;
```

- Lebensdauer begrenzt auf Funktionsblock
- sehr schnell
- feste Größe beim Kompilieren

#### Heap-Allocation (dynamisch)

```cpp
ListNode_t* n = (ListNode_t*)malloc(sizeof(ListNode_t));
n->data = 42;
```

- lebt weiter, auch nach Funktionsende
- muss **manuell** freigegeben werden
- flexibler Speicher

Dies ist wichtig für verkettete Listen:
**Die Knoten müssen auf dem Heap leben**, weil sie über Funktionsgrenzen hinweg bestehen.

---

### 4. Zugriff auf Strukturfelder

#### Direkt (Stack)

```cpp
n.data = 10;
```

#### Über Zeiger (Heap)

```cpp
n->data = 10;  // NICHT n.data
```

**Merksatz:**
*`.` für Werte – `->` für Zeiger.*

---

### 5. Selbstreferenzierende Strukturen

Listen nutzen Zeiger auf dieselbe Struktur:

```cpp
typedef struct ListNode {
    unsigned int data;
    struct ListNode* pNext;
} ListNode_t;
```

Ergebnis:

```
[10] → [20] → [30] → NULL
```

Ohne Pointer wären Listen nicht möglich.

---

### 6. Warum eine API verwenden? (`list_init(&list)`)

Man könnte direkt Felder setzen:

```cpp
List_t list;
list.pHead = nullptr;
list.pTail = nullptr;
list.size = 0;
```

Aber das ist fehleranfällig.

Eine API abstrahiert:

```cpp
list_init(&list);
```

**Vorteile:**

- nur *eine zentrale Stelle* für Initialisierung
- Fehlervermeidung (pTail vergessen?)
- leicht erweiterbar
- professionelle Softwarestruktur
- klarer Einstiegspunkt wie Konstruktoren in C++

---

### 7. Beispiel: Liste im Speicher

```cpp
List_t list;
list_init(&list);
list_push_back(&list, 10);
list_push_back(&list, 20);
```

Visualisierung:

```
List_t:
  pHead → Knoten(10) → Knoten(20) → NULL
  pTail → Knoten(20)
  size  = 2
```

Heap:

```
+-----------+      +-----------+
| data = 10 | ---> | data = 20 |
| pNext = --|      | pNext=NULL|
+-----------+      +-----------+
```

---

### 8. Häufige Fehler

| Fehler                         | Ursache                          | Lösung                         |
|-------------------------------|----------------------------------|--------------------------------|
| `node.data` vs. `node->data`  | Zeiger verwechselt               | `->` für Zeiger nutzen         |
| falsche sizeof-Angabe         | Anfängerfehler bei malloc        | `sizeof(ListNode_t)` verwenden |
| leere Liste nicht berücksichtigt | Vergessen in Funktionen         | frühzeitig prüfen (`nullptr`)  |
| Knoten auf Stack erzeugt      | Lebensdauer falsch verstanden    | immer Heap (`malloc/new`)      |
| fehlendes free/delete         | Speicherleck                     | in clear/Löschfunktionen einbauen |

---

### 9. Wichtigste Begriffe

- `struct`
- `typedef`
- Zeiger und `->`
- `malloc` / `free`
- Stack vs. Heap
- Include-Guard
- selbstreferenzierende Strukturen

---

Dieser Anhang soll sicherstellen, dass Sie die Übung auch dann erfolgreich bearbeiten können, wenn Ihre C/C++-Grundlagen noch nicht vollständig gefestigt sind.


Die Größen der Speichersegemente können Sie sich mit dem Programm `size` anzeigen lassen:

```sh
size -A -x ./build/bin/exercise-004 
./build/bin/exercise-004  :
section                  size      addr
.interp                  0x1c     0x318
.note.gnu.property       0x20     0x338
.note.gnu.build-id       0x24     0x358
.note.ABI-tag            0x20     0x37c
.gnu.hash                0x50     0x3a0
.dynsym                0x10b0     0x3f0
.dynstr                0x2363    0x14a0
.gnu.version            0x164    0x3804
.gnu.version_r          0x100    0x3968
.rela.dyn              0x1cf8    0x3a68
.rela.plt               0xd68    0x5760
.init                    0x17    0x7000
.plt                    0x900    0x7020
.plt.got                 0x18    0x7920
.text                 0x49d72    0x7940
.fini                     0x9   0x516b4
.rodata                0x1d03   0x52000
.eh_frame_hdr          0x4c5c   0x53d04
.eh_frame             0x13cec   0x58960
.gcc_except_table      0x2ee4   0x6c64c
.init_array              0x10   0x70370
.fini_array               0x8   0x70380
.data.rel.ro            0x9c0   0x70388
.dynamic                0x220   0x70d48
.got                     0x80   0x70f68
.got.plt                0x490   0x70fe8
.data                    0x50   0x71478
.bss                    0x490   0x714c8
.comment                 0x50       0x0
.debug_info           0x46575       0x0
.debug_abbrev           0xf73       0x0
.debug_line           0x27b1f       0x0
.debug_str            0x9e6b7       0x0
.debug_addr            0x5ab8       0x0
.debug_line_str         0x7f2       0x0
.debug_loclists         0xaf2       0x0
.debug_rnglists        0x308e       0x0
.debug_str_offsets     0x8490       0x0
Total                0x18ed30
```

## Hilfreiche Links

- [Markdown Cheat Sheet](https://guides.github.com/pdfs/markdown-cheatsheet-online.pdf)