//Студенти з парними номерами в журналі виконують завдання 1, 3, 5; з непарними – 2, 4, 6.

/*1. Заданий рядок тексту, який в тому числі містить множину дужок : "(",
"{", "[" що відкриваються і закриваються.Рядок вважається коректним в тому
випадку, якщо всім дужкам, що відкриваються, є відповідні дужки, що
закриваються.Наприклад, рядок "abc (as) [] {aa [z]}" - вважається коректним, а
рядок "[[09] ({]})" - не є таким, Перевірити коректність рядка з використанням
стека.

3. Дано дві непусті черги, які містять однакову кількість елементів.
Об'єднати черги в одну зі збереженням упорядкованості елементів.

5. Написати функцію, яка дозволяє визначити число входжень елемента x в
бінарне дерево.*/




#include <iostream>
#include <string>

using namespace std;

struct Stack {
    char data[100];
    int top;

    Stack() : top(-1) {}

    void push(char c) {
        data[++top] = c;
    }

    char pop() {
        return data[top--];
    }

    char peek() {
        return data[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool isBalanced(const string& str) {
    Stack stack;

    // Перевірка балансу дужок у введеному рядку
    for (char c : str) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (stack.isEmpty()) {
                return false;  // Немає відкриваючої дужки для закриваючої
            }
            char top = stack.pop();
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false;  // Неправильна пара дужок
            }
        }
    }

    return stack.isEmpty();  // Всі дужки були парні та правильно збалансовані
}

struct Queue {
    int data[100];
    int front, rear;

    Queue() : front(0), rear(-1) {}

    void enqueue(int value) {
        data[++rear] = value;
    }

    int dequeue() {
        return data[front++];
    }

    int peek() {
        return data[front];
    }

    bool isEmpty() {
        return front > rear;
    }
};

Queue mergeQueues(const Queue& q1, const Queue& q2) {
    Queue mergedQueue;

    int i = q1.front;
    while (i <= q1.rear) {
        mergedQueue.enqueue(q1.data[i]);
        i++;
    }

    i = q2.front;
    while (i <= q2.rear) {
        mergedQueue.enqueue(q2.data[i]);
        i++;
    }

    return mergedQueue;
}

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode* createSampleTree() {
    // Створення прикладового бінарного дерева
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(18);
    return root;
}

int countOccurrences(TreeNode* root, int x) {
    if (root == nullptr) {
        return 0;
    }

    int count = 0;

    if (root->data == x) {
        count = 1;
    }

    count += countOccurrences(root->left, x);
    count += countOccurrences(root->right, x);

    return count;
}

int main() {
    string str;
    cout << "Введіть рядок з дужками: ";
    cin >> str;

    if (isBalanced(str)) {
        cout << "Рядок коректний." << endl;
    }
    else {
        cout << "Рядок не коректний." << endl;
    }

    cout << "\t\t" << "Друге завдання:" << endl;

    Queue queue1, queue2;
    // Ініціалізація черг queue1 та queue2
    queue1.enqueue(1);
    queue1.enqueue(2);
    queue1.enqueue(3);

    // Ініціалізація queue2
    queue2.enqueue(4);
    queue2.enqueue(5);
    queue2.enqueue(6);

    Queue mergedQueue = mergeQueues(queue1, queue2);

    cout << "Об'єднана черга: ";
    while (!mergedQueue.isEmpty()) {
        cout << mergedQueue.peek() << " ";
        mergedQueue.dequeue();
    }
    cout << endl;

    cout << "\t\t" << "Третє завдання:" << endl;

    TreeNode* root = createSampleTree();

    int x;
    cout << "Введіть число x: ";
    cin >> x;

    int occurrences = countOccurrences(root, x);

    cout << "Число " << x << " входить " << occurrences << " разів в бінарне дерево." << endl;

    // Звільнення виділеної пам'яті для бінарного дерева
    delete root;

    return 0;
}
