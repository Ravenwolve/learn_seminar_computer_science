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
    if (!queue.Empty()) {
        int count = 0;
        for (int i = 1, lpop = queue.Get(), rpop, size = queue.Size(); i < size; i++) {
            rpop = queue.Get();
            if (lpop == rpop)
                count++;
            else queue.Put(lpop);
            queue.Put(rpop);
            lpop = rpop;
        }
        return count;
    }
    else return 0;
}

//int pairs(Queue<int>& queue) {
//    if (queue.Size() > 1) {
//        int count = 0, lpop = queue.Get(), rpop = queue.Get();
//        if (lpop != rpop) { //если левый элемент не равен правому, то возвращаем левый в конец очереди
//            queue.Put(lpop);
//        }
//        else count++; //счётчик становится равным 1
//        queue.Put(rpop); //в любом случае правый элемент возвращается в конец очереди
//        lpop = rpop; //левым становится правый элемент
//        for (int i = 1, size = queue.Size(); i < size; i++) {
//            rpop = queue.Get(); //берётся первый и он становится правым элементом (относительно lpop)
//            if (lpop == rpop) //если левый и правый равны, просто счётчик увеличивается. Так как элемент уже в конце очереди встал вне цикла, нам не нужно толкать туда ничего
//                count++;
//            else queue.Put(rpop); //если левый и правый не равны, то правый толкаем в конец очереди
//            lpop = rpop; //левый становится правым
//        }
//        return count;
//    }
//    else return 0;
//}

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
