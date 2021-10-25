#pragma once

template <typename T>
class cola
{
	struct Node
	{
		T* item;
		Node* siguiente;
		Node(T* item) {
			this->item = item;
			this->siguiente = nullptr;
		}
	};
	Node* cabeza;
	Node* cola;
	
public:
	void Encolar(T* item){
		Node* nuevo = new Node(item);
		nuevo->item = item;
		if (this->cabeza == nullptr)
		{
			this->cabeza = nuevo;
			this->cola = nuevo;
		}
		else
		{
			this->cola->siguiente = nuevo;
			this->cola = nuevo;
		}
	}
	T* desEncolar() {
		T retorno = nullptr;
		if (cabeza != nullptr)
		{
			retorno = cabeza->valor;
			Node* Top = cabeza;
			cabeza = cabeza->siguiente;
			if (cabeza == nullptr)
			{
				cola = nullptr;
			}
			delete(Top);
		}	
	}
	int Tamaño() {
		int cantidad = 0;
		for (Node* i = cabeza; i != nullptr; i = i->siguiente)
		{
			cantidad++;
		}
		return cantidad;
	}
	bool ColaVacia() {
		return cabeza == nullptr;
	}
	void limpiar() {
		while (!ColaVacia())
		{
			desEncolar();
		}
	}
};

