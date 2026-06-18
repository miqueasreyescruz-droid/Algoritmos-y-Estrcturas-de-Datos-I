#include <iostream>
#include <cassert>
#include "BAUL.h"

void test_baul()
{
    std::cout << "Starting BAUL tests..." << std::endl;

    // 1. Create a BAUL with capacity 5
    BAUL c = BAULVACIO(5);
    assert(CAPACIDAD(c) == 5);
    assert(OCUPADO(c) == 0);
    assert(DISPONIBLE(c) == 5);
    assert(ESTAVACIO(c) == true);
    assert(ULTIMO(c) == indefinido);
    assert(PRIMERO(c) == indefinido);
    std::cout << "Test 1: BAULVACIO passed." << std::endl;

    // 2. Add elements
    c = AGREGAR(c, 'A');
    assert(OCUPADO(c) == 1);
    assert(DISPONIBLE(c) == 4);
    assert(ESTAVACIO(c) == false);
    assert(ULTIMO(c) == 'A');
    assert(PRIMERO(c) == 'A');
    assert(CONTIENE(c, 'A') == true);
    assert(CONTIENE(c, 'B') == false);
    std::cout << "Test 2: AGREGAR first element passed." << std::endl;

    c = AGREGAR(c, 'B');
    assert(OCUPADO(c) == 2);
    assert(DISPONIBLE(c) == 3);
    assert(ULTIMO(c) == 'B');
    assert(PRIMERO(c) == 'A');
    assert(CONTIENE(c, 'A') == true);
    assert(CONTIENE(c, 'B') == true);
    std::cout << "Test 2.1: AGREGAR second element passed." << std::endl;

    c = AGREGAR(c, 'C');
    c = AGREGAR(c, 'D');
    c = AGREGAR(c, 'E');
    assert(OCUPADO(c) == 5);
    assert(DISPONIBLE(c) == 0);
    assert(ULTIMO(c) == 'E');
    assert(PRIMERO(c) == 'A');
    std::cout << "Test 2.2: AGREGAR up to capacity passed." << std::endl;

    // Try adding beyond capacity
    c = AGREGAR(c, 'F');
    assert(OCUPADO(c) == 5); // Should not increase
    assert(ULTIMO(c) == 'E');
    assert(CONTIENE(c, 'F') == false);
    std::cout << "Test 2.3: AGREGAR beyond capacity rejected correctly." << std::endl;

    // 3. Quitar ultimo
    c = QUITARULTIMO(c);
    assert(OCUPADO(c) == 4);
    assert(ULTIMO(c) == 'D');
    assert(PRIMERO(c) == 'A');
    assert(CONTIENE(c, 'E') == false);
    std::cout << "Test 3: QUITARULTIMO passed." << std::endl;

    // 4. Vaciar
    c = VACIAR(c);
    assert(OCUPADO(c) == 0);
    assert(DISPONIBLE(c) == 5);
    assert(ESTAVACIO(c) == true);
    assert(ULTIMO(c) == indefinido);
    assert(PRIMERO(c) == indefinido);
    std::cout << "Test 4: VACIAR passed." << std::endl;

    // 5. Emptying one by one with QUITARULTIMO
    c = AGREGAR(c, 'X');
    c = AGREGAR(c, 'Y');
    assert(OCUPADO(c) == 2);
    assert(PRIMERO(c) == 'X');
    assert(ULTIMO(c) == 'Y');

    c = QUITARULTIMO(c);
    assert(OCUPADO(c) == 1);
    assert(PRIMERO(c) == 'X');
    assert(ULTIMO(c) == 'X');

    c = QUITARULTIMO(c);
    assert(OCUPADO(c) == 0);
    assert(ESTAVACIO(c) == true);
    assert(PRIMERO(c) == indefinido);
    assert(ULTIMO(c) == indefinido);
    std::cout << "Test 5: QUITARULTIMO until empty passed." << std::endl;

    std::cout << "All BAUL tests passed successfully!" << std::endl;
}

int main()
{
    test_baul();
    return 0;
}
