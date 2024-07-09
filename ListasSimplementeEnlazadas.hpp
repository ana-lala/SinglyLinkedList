#ifndef LISTASSIMPLEMENTEENLAZADAS_HPP_INCLUDED
#define LISTASSIMPLEMENTEENLAZADAS_HPP_INCLUDED

#define NO_ENCONTRADO -1

class ListaVacia : public std::exception {
public:
    const char* what() const throw() override {
        return "Lista vacía";
    }
};

class FueraDeRango : public std::exception {
public:
    const char* what() const throw() override {
        return "Índice fuera de rango";
    }
};

template <typename T>

class ListaSimple
{
public:
    ListaSimple();
    ~ListaSimple();
    ListaSimple(const ListaSimple<T> &l);
    ListaSimple<T> & operator=(const ListaSimple &l);
    void AgregarInicio(T valor);
    void AgregarFinal(T valor);
    void AgregarPos(T valor, int pos);
    void EliminarInicio();
    void EliminarFinal();
    void EliminarPos(int pos);
    bool BuscarValor(T valor) const;
    int BuscarPos(T valor) const;
    bool EstaVacia() const;
    T ObtenerPrimero() const;
    T ObtenerUltimo() const;
    T ObtenerPorPos(int pos) const;
    void ModificarPos(T valor, int pos);
    int NumElementos() const;
    void Vaciar();
    void Imprimir() const;

private:
    int tam, pos;
    struct Elemento
    {
        T valor;
        Elemento *siguiente;
        Elemento(T val, Elemento *sig) : valor(val), siguiente(sig) {}
    };
    Elemento *primero, *ultimo;
};

#include "ListasSimplementeEnlazadas.tpp"

#endif // LISTASSIMPLEMENTEENLAZADAS_HPP_INCLUDED
