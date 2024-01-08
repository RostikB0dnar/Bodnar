

//Завдання 2: Створити новий(третій) список однозв'язний список. Помістити в  нього перші три елементи з першого і другого списків. Результуючий список вивести на екран.
//Завдання 14: Створити новий(третій) список однозв'язний список. Помістити в нього всі символи верхнього регістру з перших двох. Результуючий список вивести на екран.

#include <iostream>
#include <locale.h>

using namespace std;

// Структура для вузла списку
struct Node {
    char data;
    Node* next;
    Node(char val) : data(val), next(nullptr) {}
};

// Додавання на початок списку
void addToBeginning(Node*& head, char value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// Додавання в кінець списку
void addToEnd(Node*& head, char value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

// Виведення списку на екран
void print(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

//Очищення списку
void clearList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteNodeByIndex(Node*& head, int index) {

    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    int currentIndex = 0;

    while (current->next != nullptr && currentIndex < index - 1) {
        current = current->next;
        currentIndex++;
    }

    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}


// Перемістити всі символи верхнього регістру з перших двох списків в третій список
void moveUppercaseCharacters(Node*& source1, Node*& source2, Node*& destination) {
    Node* current1 = source1;
    Node* current2 = source2;

    while (current1) {
        if (isupper(current1->data)) {
            addToEnd(destination, current1->data);
        }
        current1 = current1->next;
    }

    while (current2) {
        if (isupper(current2->data)) {
            addToEnd(destination, current2->data);
        }
        current2 = current2->next;
    }
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    Node* list1 = nullptr;
    Node* list2 = nullptr;
    Node* result = nullptr;

    // Заповнення списків з клавіатури
    int n;
    cout << "Введіть кількість елементів для списку 1: ";
    cin >> n;
    cout << "Введіть елементи для списку 1: ";
    for (int i = 0; i < n; i++) {
        char value;
        cin >> value;
        addToEnd(list1, value);
    }

    cout << "Введіть кількість елементів для списку 2: ";
    cin >> n;
    cout << "Введіть елементи для списку 2: ";
    for (int i = 0; i < n; i++) {
        char value;
        cin >> value;
        addToEnd(list2, value);
    }

    Node* current1 = list1;
    Node* current2 = list2;
    for (int i = 0; i < 3; i++) {
        if (current1) {
            addToEnd(result, current1->data);
            current1 = current1->next;
        }
        if (current2) {
            addToEnd(result, current2->data);
            current2 = current2->next;
        }
    }


    cout << "Результуючий список: ";
    print(result);

    clearList(result);

    // Перемістимо всі символи верхнього регістру в результат
    moveUppercaseCharacters(list1, list2, result);
    
    // Виведення результату
    cout << "Результуючий список: ";
    print(result);

   

    // Звільнення пам'яті
    while (list1) {
        Node* temp = list1;
        list1 = list1->next;
        delete temp;
    }
    while (list2) {
        Node* temp = list2;
        list2 = list2->next;
        delete temp;
    }
    while (result) {
        Node* temp = result;
        result = result->next;
        delete temp;
    }

    

    return 0;
}
