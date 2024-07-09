# ListaSimple Class

## Overview

The `ListaSimple` class implements a singly linked list for storing elements of type `T`.

## Implementation Details

- **Constructor (`ListaSimple()`)**: Initializes an empty list.
  
- **Destructor (`~ListaSimple()`)**: Clears all allocated memory upon object destruction.

- **Copy Constructor (`ListaSimple(const ListaSimple<T> &l)`)** and **Assignment Operator (`operator=`)**: Allow copying of lists while maintaining correct internal pointers and sizes.

## Methods

### `AgregarInicio(T valor)`

Adds an element of type `T` to the beginning of the list.

### `AgregarFinal(T valor)`

Adds an element of type `T` to the end of the list.

### `AgregarPos(T valor, int pos)`

Adds an element of type `T` at a specified position in the list.

### `EliminarInicio()`

Removes the element at the beginning of the list.

### `EliminarFinal()`

Removes the element at the end of the list.

### `EliminarPos(int pos)`

Removes the element at a specified position in the list.

### `BuscarValor(T valor) const`

Searches for a specific value in the list and returns true if found, false otherwise.

### `BuscarPos(T valor) const`

Searches for a specific value in the list and returns its position. Returns `NO_ENCONTRADO` (-1) if not found.

### `EstaVacia() const`

Checks if the list is empty.

### `ObtenerPrimero() const`

Returns the value of the first element in the list.

### `ObtenerUltimo() const`

Returns the value of the last element in the list.

### `ObtenerPorPos(int pos) const`

Returns the value at a specified position in the list.

### `ModificarPos(T valor, int pos)`

Modifies the value at a specified position in the list.

### `NumElementos() const`

Returns the number of elements currently in the list.

### `Vaciar()`

Empties the list by deleting all elements.

### `Imprimir() const`

Prints all elements in the list.

## Exception Handling

- **`ListaVacia`**: Custom exception thrown when attempting to perform operations on an empty list.
- **`FueraDeRango`**: Custom exception thrown when an index is out of range.

## Example Usage

```cpp
#include <iostream>
#include "ListasSimplementeEnlazadas.hpp"

int main() {
    ListaSimple<int> lista;

    lista.AgregarInicio(10);
    lista.AgregarFinal(20);
    lista.AgregarPos(15, 1);

    lista.Imprimir();
    std::cout << std::endl;

    lista.EliminarInicio();
    lista.EliminarPos(1);

    lista.Imprimir();
    std::cout << std::endl;

    return 0;
}
