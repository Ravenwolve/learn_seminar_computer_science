#include <iostream>
#include <fstream>
using namespace std;
template <class Item>
class Queue {
    struct Element {
        Item inf;
        Element* next;
        Element(Item x) :inf(x), next(0) {}
    };
    Element* head, * tail;
    int size;
public:
    int Size() { return size; }
    Queue() : head(0), tail(0), size(0) {}
    bool Empty() { return head == 0; }
    Item Get() {
        if (!Empty()) {
            Element* t = head;
            Item i = t->inf;
            head = t->next;
            if (head == NULL)
                tail = NULL;
            delete t;
            size--;
            return i;
        }
    }
    void Put(Item data) {
        Element* t = tail;
        tail = new Element(data);
        if (!head)
            head = tail;
        else t->next = tail;
        size++;
    }
    void Print(ofstream& out) {
        for (Element* current = head; current != NULL; current = current->next) {
            out << current->inf << ' ';
        }
    }
    void Print() {
        for (Element* current = head; current != NULL; current = current->next) {
            cout << current->inf << ' ';
        }
    }
};
int pairs(Queue<int>& queue) {
    if (queue.Size() > 1) {
        int count = 0, lpop = queue.Get();
        for (int i = 0, size = queue.Size(), rpop; i < size; i++) {
            rpop = queue.Get();
            if (lpop == rpop)
                count++;
            else queue.Put(lpop);
            lpop = rpop;
        }
        queue.Put(lpop);
        return count;
    }
    else return 0;
}
int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int k;
    Queue<int> Q;
    while (fin >> k)
        Q.Put(k);
    fin.close();
    Q.Print();
    cout << endl << pairs(Q) << endl;
    Q.Print(fout);
    Q.Print();
}
