Vorteile der verketteten Liste

- Einfügen und Entfernen von Elementen ist sehr effizient (O(1)), wenn die Position bekannt ist.
- Speicher wird dynamisch zugewiesen (keine feste Größe).
- Kein Verschieben von Elementen nötig.

Nachteile der verketteten Liste

- Kein direkter Indexzugriff (lineares Suchen O(n)).
- Schlechtere Cache-Locality → langsam bei sequentiellem Zugriff.
- Speicher-Overhead durch Zeiger.
- Zersplitterung im Speicher möglich.

Vorteile des Mini-Vectors

- Direkter Zugriff per Index (O(1)).
- Sehr gute Cache-Locality → schnelles Iterieren.
- Weniger Speicher-Overhead (nur das Array).
- Kompaktes Datenlayout.

Nachteile des Mini-Vectors

- Kapazität muss vergrößert werden → Realloc-Kosten (teuer, O(n)).
- Einfügen/Entfernen im Inneren erfordert Verschieben aller nachfolgenden Elemente (O(n)).
- Kann Speicher verschwenden (überallokiert).
- Größe ist nicht so flexibel wie bei einer Liste.

Wann benutzt man welche Struktur?
Situation	                                                                Empfehlung
Viele Einfügungen/Entfernungen mitten in der Struktur	                    Liste
Viele Zugriffe per Index	                                                Vector
Häufige Iteration über alle Elemente	                                    Vector
Datenmenge unbekannt, wächst dynamisch	                                    Liste oder Vector (mit Reservierung)
Speicher soll kompakt zusammenhängend sein	                                Vector
Echtzeit-Anforderungen ohne Realloc	                                        Liste

Kurzform:
➡ Liste = gute Änderungen, schlechte Zugriffe
➡ Vector = gute Zugriffe, schlechte Änderungen

Was passiert, wenn man die Elemente sortiert?
Beim Mini-Vector

- Sortieren ist effizient (z. B. Quicksort).
- Array liegt zusammenhängend → sehr gut für CPU-Caches.
- Vergleichsoperationen sind O(n log n).
- Kein zusätzlicher Aufwand beim Umstrukturieren.
→ Sehr gut sortierbar – ideal für Sortieralgorithmen.

Bei der Liste

- Sortieren ist deutlich langsamer.
- Man kann keine direkten Elemente tauschen – nur Zeiger umhängen.
- Vergleichsoperationen sind weiterhin O(n log n), aber Zugriff auf das k-th Element ist O(k) → insgesamt schlechter.
→ Sortieren ist möglich, aber unperformant und komplex.
Typischer Algorithmus: „Merge Sort for Linked Lists“.

Wie würden Sie einen Binären Baum strukturieren?

Ein Knoten enthält:

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node_t;


Die Baumstruktur:

        (root)
        /    \
   (left)   (right)


Eigenschaften:

- Jeder Knoten hat maximal zwei Kinder.
- Der Baum hat genau einen Root-Knoten.
- Unterbäume sind wieder vollständige Bäume (rekursiv).
- Bei einem Binary Search Tree (BST) zusätzlich:

left->data  <  node->data  <  right->data