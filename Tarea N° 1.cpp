#include <iostream>
using namespace std;
struct Node {
    int value;
    Node *next_node;
};

void push(Node *&top, int value) {
    Node *new_node = new Node{value, top};
    top = new_node;
}

void pop(Node *&top) {
    int value = top->value;
    Node *temporal_node = top;
    top = top->next_node;
    delete temporal_node;
    cout << "Se eliminó el elemento " << value << " de la pila." <<endl;
}

void print_stack(Node *top) {
    Node *current_node = top;
    while (current_node != NULL) {
        std::cout << current_node->value << " ";
        current_node = current_node->next_node;
    }
    cout << endl;
}

int main() {
    Node *top = NULL;
    int option;
    int value;
    do {
        cout << "1. Agregar elemento a la pila." << endl;
        cout << "2. Eliminar elemento de la pila." << endl;
        cout << "3. Mostrar elementos de la pila." << endl;
        cout << "4. Salir." << endl;
        cout << "Ingrese una opción: ";
        cin >> option;
        switch (option) {
            case 1:
                cout << "Ingrese el valor a agregar: ";
                cin >> value;
                push(top, value);
                break;
            case 2:
                pop(top);
                break;
            case 3:
                print_stack(top);
                break;
            case 4:std::cout << "Gracias por usar el programa." <<endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." <<endl;
        }
    } while (option != 4);
    return 0;
}