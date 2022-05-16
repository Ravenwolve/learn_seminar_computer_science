#include <iostream>
#include <fstream>
using namespace std;
template <class Item>
class DoubleLinkedList {
    struct Element {
        Item inf;
        Element* next;
        Element* prev;
        Element(Item x) : inf(x), next(0), prev(0) {}
    };
    Element* head;
    Element* tail;
    int size;
    bool inrange(int index) { return index >= 0 && index <= size; }
    Element* Find(int index) {
        if (inrange(index)) {
            Element* cur = head;
            for (int i = 0; i < index; i++)
                cur = cur->next;
            return cur;
        }
        return NULL;
    }
public:
    DoubleLinkedList() : head(0), tail(0), size(0) {}
    ~DoubleLinkedList() {
        while (!Empty())
            Remove(0);
    }
    bool Empty() { return head == 0; }
    int GetLength() { return size; }
    Item Get(int index) {
        if (inrange(index)) {
            Element* r = Find(index);
            Item i = r->inf;
            return i;
        }
        return NULL;
    }
    void InsertLeft(int index, Item data) {
        if (inrange(index)) {
            Element* newPtr = new Element(data);
            size++;
            Element* cur = Find(index);
            if (cur == NULL) {
                head = newPtr;
                tail = newPtr;
            }
            else {
                Element* prev = Find(index - 1);
                newPtr->next = cur;
                newPtr->prev = cur->prev;
                cur->prev = newPtr;
                if (cur == head)
                    head = newPtr;
                else newPtr->prev->next = newPtr;
            }
        }
    }
    void InsertRight(int index, Item data) {
        if (inrange(index)) {
            Element* newPtr = new Element(data);
            size++;
            Element* cur = Find(index);
            if (cur == NULL) {
                head = newPtr;
                tail = newPtr;
            }
            else {
                newPtr->next = cur->next;
                newPtr->prev = cur;
                cur->next = newPtr;
                if (cur == tail)
                    tail = newPtr;
                else newPtr->next->prev = newPtr;
            }
        }
    }
    void Remove(int index) {
        if (inrange(index)) {
            Element* cur = Find(index);
            --size;
            if (size == 0) {
                head = NULL;
                tail = NULL;
            }
            else if (cur == head) {
                head = head->next;
                head->prev = NULL;
            }
            else if (cur == tail) {
                tail = tail->prev;
                tail->next = NULL;
            }
            else {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
            }
            cur->next = NULL;
            cur->prev = NULL;
            delete cur;
        }
    }
    void Print(ofstream& out) {
        for (Element* current = head; current != NULL; current = current->next)
            out << current->inf << ' ';
    }
    void Print() {
        for (Element* current = head; current != NULL; current = current->next)
            cout << current->inf << ' ';
    }
    int pairs() {
        int count = 0;
        for (int i = 0; i < size - 1; i++) {
            if (Get(i) == Get(i + 1)) {
                Remove(i);
                i--;
                count++;
            }
        }
        return count;
    }
};
int main() {
    ifstream fin("input.txt");
    DoubleLinkedList<int> DLL;
    int a;
    fin >> a;
    DLL.InsertRight(0, a);
    for (int i = 0; fin >> a; i++)
        DLL.InsertRight(i, a);
    fin.close();
    ofstream fout("output.txt");
    DLL.Print();
    cout << endl << endl;
    cout << DLL.pairs() << endl << endl;
    DLL.Print();
}
