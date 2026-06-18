#include <iostream>
#include <cassert>
#include "stdAB.h"

void destruir_ab(AB T);
void test_ab_vacio();
void test_armarab_and_traversal();
void test_pertenece();
bool estaLleno(AB T);
void test_esta_lleno();

int main() {
    std::cout << "Starting Binary Tree ADT tests..." << std::endl;
    test_ab_vacio();
    test_armarab_and_traversal();
    test_pertenece();
    test_esta_lleno();
    std::cout << "All tests passed successfully!" << std::endl; 
    return 0;
}

// Clean helper to free memory of a binary tree
void destruir_ab(AB T) {
    if (!ESABVACIO(T)) {
        destruir_ab(IZQUIERDO(T));
        destruir_ab(DERECHO(T));
        delete T;
    }
}

void test_ab_vacio() {
    std::cout << "Testing ABVACIO and ESABVACIO..." << std::endl;
    AB t = ABVACIO();
    assert(ESABVACIO(t) == true);
    std::cout << "ABVACIO and ESABVACIO tests passed!" << std::endl;
}

void test_armarab_and_traversal() {
    std::cout << "Testing ARMARAB, IZQUIERDO, DERECHO, and RAIZ..." << std::endl;
    
    // Constructing a tree:
    //      'A'
    //     /   \
    //   'B'   'C'
    
    AB empty1 = ABVACIO();
    AB empty2 = ABVACIO();
    AB empty3 = ABVACIO();
    AB empty4 = ABVACIO();
    
    AB left_child = ARMARAB(empty1, 'B', empty2);
    AB right_child = ARMARAB(empty3, 'C', empty4);
    AB root = ARMARAB(left_child, 'A', right_child);
    
    assert(ESABVACIO(root) == false);
    assert(RAIZ(root) == 'A');
    
    assert(IZQUIERDO(root) == left_child);
    assert(DERECHO(root) == right_child);
    
    assert(RAIZ(IZQUIERDO(root)) == 'B');
    assert(RAIZ(DERECHO(root)) == 'C');
    
    std::cout << "ARMARAB and traversal tests passed!" << std::endl;
    
    destruir_ab(root);
}

void test_pertenece() {
    std::cout << "Testing PERTENECE..." << std::endl;
    
    AB empty = ABVACIO();
    assert(PERTENECE(empty, 'A') == false);
    
    // Build tree:
    //      'X'
    //     /   \
    //   'Y'   'Z'
    AB left = ARMARAB(ABVACIO(), 'Y', ABVACIO());
    AB right = ARMARAB(ABVACIO(), 'Z', ABVACIO());
    AB root = ARMARAB(left, 'X', right);
    
    assert(PERTENECE(root, 'X') == true);
    assert(PERTENECE(root, 'Y') == true);
    assert(PERTENECE(root, 'Z') == true);
    assert(PERTENECE(root, 'W') == false);
    
    std::cout << "PERTENECE tests passed!" << std::endl;
    
    destruir_ab(root);
}

void test_esta_lleno() {
    std::cout << "Testing estaLleno..." << std::endl;
    
    // 1. Empty tree
    AB t1 = ABVACIO();
    assert(estaLleno(t1) == true);
    destruir_ab(t1);
    
    // 2. Single node (leaf)
    AB t2 = ARMARAB(ABVACIO(), 'A', ABVACIO());
    assert(estaLleno(t2) == true);
    destruir_ab(t2);
    
    // 3. Tree with only left child
    AB leaf3 = ARMARAB(ABVACIO(), 'A', ABVACIO());
    AB t3 = ARMARAB(leaf3, 'B', ABVACIO());
    assert(estaLleno(t3) == false);
    destruir_ab(t3);
    
    // 4. Tree with only right child
    AB leaf4 = ARMARAB(ABVACIO(), 'A', ABVACIO());
    AB t4 = ARMARAB(ABVACIO(), 'B', leaf4);
    assert(estaLleno(t4) == false);
    destruir_ab(t4);
    
    // 5. Full tree (root with 2 children)
    AB l5 = ARMARAB(ABVACIO(), 'L', ABVACIO());
    AB r5 = ARMARAB(ABVACIO(), 'R', ABVACIO());
    AB t5 = ARMARAB(l5, 'M', r5);
    assert(estaLleno(t5) == true);
    destruir_ab(t5);
    
    // 6. Non-full tree (root with 2 children, but one of them has only 1 child)
    AB l6 = ARMARAB(ABVACIO(), 'L', ABVACIO());
    AB sub_r6 = ARMARAB(ABVACIO(), 'S', ABVACIO());
    AB r6 = ARMARAB(sub_r6, 'R', ABVACIO()); // R has only left child (S)
    AB t6 = ARMARAB(l6, 'M', r6);
    assert(estaLleno(t6) == false);
    destruir_ab(t6);
    
    std::cout << "estaLleno tests passed!" << std::endl;
}

bool estaLleno(AB T)
{
    if (ESABVACIO(T))
    {
        return true;
    }
    else
    {
        if (ESABVACIO(IZQUIERDO(T)) && !ESABVACIO(DERECHO(T)))
        {
            return false;
        }
        else if (ESABVACIO(DERECHO(T)) && !ESABVACIO(IZQUIERDO(T)))
        {
            return false;
        }
        else
        {
            return estaLleno(IZQUIERDO(T)) && estaLleno(DERECHO(T));
        }
    }
}
