//****************************************************************************************
template <typename T>
ListaSimple<T>::ListaSimple(): tam(0), primero(nullptr), ultimo(nullptr)
{

}
//****************************************************************************************
template <typename T>
ListaSimple<T> &ListaSimple<T>::operator=(const ListaSimple &l)
{
    if (this == &l)
        return *this;
    Vaciar();
    Elemento *actual = l.primero;
    while (actual != nullptr)
    {
        Agregar(actual->valor);
        actual = actual->siguiente;
    }
    return *this;
}
//****************************************************************************************
template <typename T>
ListaSimple<T>::ListaSimple(const ListaSimple<T> &l): tam(0), primero(nullptr), ultimo(nullptr)
{
    *this = l;
}
//****************************************************************************************
template <typename T>
ListaSimple<T>::~ListaSimple()
{
    Vaciar();
}
//****************************************************************************************
template <typename T>
void ListaSimple<T>::AgregarInicio(T valor)
{
        Elemento *nuevo = new Elemento(valor, EstaVacia() ? nullptr : primero);
        primero = nuevo;
        if(EstaVacia()) ultimo = nuevo;
        ++tam;
}
//****************************************************************************************
template <typename T>
void ListaSimple<T>::AgregarFinal(T valor)
{
        Elemento *nuevo = new Elemento(valor, nullptr);
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
        if(EstaVacia()) primero = nuevo;
        ++tam;
}
//****************************************************************************************
template <typename T>
void ListaSimple<T>::AgregarPos(T valor, int pos)
{
    if(pos<0 || pos > tam) FueraDeRango();
    if(pos==0) AgregarInicio(valor);
    else if(pos==tam) AgregarFinal(valor);
    else{
        Elemento *ant = primero;
        for(int i = 1; i<pos; ++i) ant = ant->siguiente;
        Elemento *nuevo = new Elemento(valor, ant->siguiente);
        ant->siguiente = nuevo;
        ++tam;
    }
}
//************************************************************************************
template <typename T>
void  ListaSimple<T>::EliminarInicio()
{
    if(EstaVacia()) ListaVacia();
    Elemento *porBorrar = primero;
    primero = primero->siguiente;
    delete porBorrar;
    --tam;
    if(EstaVacia()) ultimo = nullptr;
}
//************************************************************************************
template <typename T>
void  ListaSimple<T>::EliminarFinal()
{
    if(EstaVacia()) throw "Lista Vacia"; ListaVacia();
    Elemento *porBorrar = ultimo;
    Elemento *penultimo = primero;
    for(int i = 1; i<tam-2; ++i) penultimo = penultimo->siguiente;
    penultimo->siguiente = nullptr;
    ultimo = penultimo;
    delete porBorrar;
    --tam;
    if(EstaVacia()) primero = nullptr;
}
//************************************************************************************
template <typename T>
void  ListaSimple<T>::EliminarPos(int pos)
{
    if(EstaVacia()) ListaVacia();
    if(pos<0 || pos >= tam) FueraDeRango();
    if(pos==0) EliminarInicio();
    else if(pos==tam-1) EliminarFinal();
    else{
        Elemento *ant = primero;
        for(int i = 1; i<pos; ++i) ant = ant->siguiente;
        Elemento *porBorrar = ant->siguiente;
        ant->siguiente = porBorrar->siguiente;
        delete porBorrar;
        --tam;
    }
}
//*********************************************************************************************
//Buscar un valor
template <typename T>
bool ListaSimple<T>::BuscarValor(T valor) const
{
    Elemento *actual = primero;
    while(actual != nullptr){
        if(actual->valor == valor){
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

//*********************************************************************************************
//Buscar la posicion de un valor
template <typename T>
int ListaSimple<T>::BuscarPos(T valor) const
{
    Elemento *actual = primero;
    int pos;
    for(pos = 0; actual!= nullptr && actual->valor != valor; ++pos)
        actual = actual->siguiente;
    if(actual!= nullptr) return pos;
    else NO_ENCONTRADO;
}
//*********************************************************************************************
template <typename T>
bool ListaSimple<T>::EstaVacia() const
{
    return tam==0;
}
//*********************************************************************************************
template <typename T>
T ListaSimple<T>::ObtenerPrimero() const
{
    return primero->valor;
}
//*********************************************************************************************
template <typename T>
T ListaSimple<T>::ObtenerUltimo() const
{
    return ultimo->valor;
}
//*********************************************************************************************
template <typename T>
T ListaSimple<T>::ObtenerPorPos(int pos) const
{
    Elemento *actual = primero;
    for(int i = 0; actual!= nullptr && i<pos; ++i)
        actual = actual->siguiente;
    if(actual!= nullptr) return actual->valor;
    else throw "No se encuentra ese valor";
}
//*********************************************************************************************
template <typename T>
void ListaSimple<T>::ModificarPos(T valor, int pos)
{
    Elemento *actual = primero;
    if(pos<0 || pos >= tam) FueraDeRango();
    for(int i = 0; actual!= nullptr && i<pos; ++i)
        actual = actual->siguiente;
    if(actual!= nullptr) actual->valor = valor;
    else throw "Ocurrio un error al encontrar la posicion";
}
//*********************************************************************************************
template <typename T>
int ListaSimple<T>::NumElementos() const
{
    return tam;
}
//*********************************************************************************************
template <typename T>
void ListaSimple<T>::Vaciar()
{
    while(!EstaVacia()){
        EliminarFinal();
    }
}
//*********************************************************************************************
template <typename T>
void ListaSimple<T>::Imprimir() const
{
    Elemento *actual = primero;
    while(actual != nullptr){
        std::cout << actual->valor << ", ";
        actual = actual->siguiente;
    }
}
