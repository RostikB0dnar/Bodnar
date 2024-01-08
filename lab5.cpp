//�������� � ������� �������� � ������ ��������� �������� 1, 3, 5; � ��������� � 2, 4, 6.

/*1. ������� ����� ������, ���� � ���� ���� ������ ������� ����� : "(",
"{", "[" �� ������������ � ������������.����� ��������� ��������� � ����
�������, ���� ��� ������, �� ������������, � ������� �����, ��
������������.���������, ����� "abc (as) [] {aa [z]}" - ��������� ���������, �
����� "[[09] ({]})" - �� � �����, ��������� ���������� ����� � �������������
�����.

3. ���� �� ������ �����, �� ������ �������� ������� ��������.
��'������ ����� � ���� � ����������� �������������� ��������.

5. �������� �������, ��� �������� ��������� ����� �������� �������� x �
������ ������.*/




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

    // �������� ������� ����� � ��������� �����
    for (char c : str) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (stack.isEmpty()) {
                return false;  // ���� ���������� ����� ��� ����������
            }
            char top = stack.pop();
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false;  // ����������� ���� �����
            }
        }
    }

    return stack.isEmpty();  // �� ����� ���� ���� �� ��������� �����������
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
    // ��������� ������������ �������� ������
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
    cout << "������ ����� � �������: ";
    cin >> str;

    if (isBalanced(str)) {
        cout << "����� ���������." << endl;
    }
    else {
        cout << "����� �� ���������." << endl;
    }

    cout << "\t\t" << "����� ��������:" << endl;

    Queue queue1, queue2;
    // ����������� ���� queue1 �� queue2
    queue1.enqueue(1);
    queue1.enqueue(2);
    queue1.enqueue(3);

    // ����������� queue2
    queue2.enqueue(4);
    queue2.enqueue(5);
    queue2.enqueue(6);

    Queue mergedQueue = mergeQueues(queue1, queue2);

    cout << "��'������ �����: ";
    while (!mergedQueue.isEmpty()) {
        cout << mergedQueue.peek() << " ";
        mergedQueue.dequeue();
    }
    cout << endl;

    cout << "\t\t" << "���� ��������:" << endl;

    TreeNode* root = createSampleTree();

    int x;
    cout << "������ ����� x: ";
    cin >> x;

    int occurrences = countOccurrences(root, x);

    cout << "����� " << x << " ������� " << occurrences << " ���� � ������ ������." << endl;

    // ��������� ������� ���'�� ��� �������� ������
    delete root;

    return 0;
}
