#include <iostream>

using namespace std;

class Node {
	public:
		int value;
		Node* next;

		Node(int new_value) {
			value = new_value;
		}
};

class LinkedList {
	public:
		Node* head;
		Node* tail;
		int length;

		LinkedList() {
			length = 0;
		}

		void append(int new_value) {
			Node* new_node = new Node(new_value);

			if (length == 0) {
                head = new_node;
                tail = new_node;
			} else {
                tail->next = new_node;
                tail = new_node;
			}

			length++;
		}

		void prepend(int new_value) {
            Node* new_node = new Node(new_value);

            if (length == 0) {
                head = new_node;
                tail == new_node;
            } else {
                new_node->next = head;
                head = new_node;
            }

            length++;
        }

		void show(Node *node) {
            if (node == NULL) {
                cout << "Nothing found" << endl;
                return;
            }

            cout << node->value << endl;

            if (node->next != NULL) {
                show(node->next);
            }
		}

		int get(int index, Node* node) {
            if (index > length - 1) {
                cout << "Index too big" << endl;
            } else if (index < 0) {
                cout << "Index too small" << endl;
            } else {
                if (index == 0) {
                    return node->value;
                } else {
                    if (node->next == NULL) {
                        cout << "We're somehow at the end of the list but no value";
                    } else {
                        return get(--index, node->next);
                    }
                }
            }

            return -1;
		}
		
		
};

int main() {
	LinkedList* list = new LinkedList();

	list->append(5);
	list->append(10);
	list->append(331);

	list->show(list->head);

	cout << "----" << endl;

	list->append(-5);

	list->show(list->head);

	cout << "----" << endl;

	list->prepend(-69);

	list->show(list->head);


	cout << "----" << endl;

	cout << list->get(2, list->head) << endl;

	return 0;
}

