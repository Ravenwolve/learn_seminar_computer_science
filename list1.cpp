#include <iostream>
#include <fstream>
using namespace std;
template <class Item> 
class List {
    struct Element {
        Item inf;
        Element* next;
        Element(Item x) : inf(x), next(NULL) {}
    };
    Element* head;
    int size;
    Element* Find(int index) {
        if (index < 0 || index > size)
            return NULL;
        else {
            Element* current = head;
            for (int i = 1; i < index; i++)
                current = current->next;
            return current;
        }
    }
public:
    List() : head(NULL), size(0) {}
    ~List() {
        while (!Empty())
            Remove(0);
    }
    bool Empty() { return head == NULL; }
    int GetLength() { return size; }
    Item Get(int index) {
        if (index >= 0 && index < size) {
            Element* r = Find(index);
            Item i = r->inf;
            return i;
        }
    }
    void Insert(int index, Item data) {
        if (index >= 0 && index < size) {
            Element* newPtr = new Element(data);
            size++;
            if (index == 0) {
                newPtr->next = head;
                head = newPtr;
            }
            else {
                Element* prev = Find(index - 1);
                newPtr->next = prev->next;
                prev->next = newPtr;
            }
        }
    }
    void Remove(int index) {
        if (index >= 0 && index < size) {
            Element* current;
            --size;
            if (index == 0) {
                current = head;
                head = head->next;
            }
            else {
                Element* prev = Find(index - 1);
                current = prev->next;
                prev->next = current->next;
            }
            current->next = NULL;
            delete current;
        }
    }
    void Print(ofstream& out) {
        for (Element* current = head; current != NULL; current = current->next) {
            out << current->inf << '\n';
        }
    }
    void Print() {
        for (Element* current = head; current != NULL; current = current->next) {
            cout << current->inf << '\n';
        }
    }
    void Push_back(Item data) {
        if (head == NULL)
            head = new Element(data);
        else {
            Element* current = head;
            while (current->next != NULL)
                current = current->next;
            current->next = new Element(data);
        }
        size++;
    }
    //Item& operator[](const int index) {
    //    int counter = 0;
    //    Element* current = head;
    //    if (index >= 0 && index < size) {
    //        while (current->next != NULL) {
    //            if (counter == index)
    //                return current->inf;
    //            current = current->next;
    //            counter++;
    //        }
    //    }
    //}
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
    int inta;
    List<int> L;
    for (int i = 0; fin >> inta; i++)
        L.Push_back(inta);
    fin.close();
    ofstream fout("output.txt");
    L.Print();
    cout << endl << endl;
    cout << L.pairs() << endl << endl;
    L.Print();
}
