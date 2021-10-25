#pragma 
#include "Comparar.h"

template <typename T>
class lista
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
	int size = 0;
public:
	int getSize() {
		return this->size;
	}
	bool vacio() {
		return this->size == 0;
	}
	void agregar(T* item) {
		Node* node = new Node(item);
		if (this->vacio())
		{
			this->cabeza = this->cola = node;
		}
		else
		{
			this->cola->siguiente = node;
			this->cola = this->cola->siguiente;
		}
		this->size++;
	}
	T* Obtener(int index) {
		if (index >= this->size || index < 0)
		{
			return nullptr;
		}
		Node* iterador = this->cabeza;

		int i = 0;
		while (i < index)
		{
			iterador = iterador->siguiente;
			i++;
		}

		return iterador->item;
	}
	T* eliminar(int index) {
		if (index >= this->size || index < 0)
		{
			return nullptr;
		}

		Node** iterador = &this->cabeza;
		Node* anterior = nullptr;

		int i = 0;
		while (i< index)
		{
			anterior = *iterador;
			iterador = &((*iterador)->siguiente);
			i++;
		}
		if (this->size - 1 == index)
		{
			this->cola = anterior;
		}
		*iterador = (*iterador)->siguiente;
		this->size--;
	}

	lista<T>* bubblesort(Comparar<T>* comparar) {
		Node** i = &(this->cabeza);
		while (*i != nullptr)
		{
			Node** j = &(*i)->siguiente;
			while (*j != nullptr)
			{
				T** itemA = &(*i)->item;
				T** itemB = &(*j)->item;

				if (comparar->compare(**itemA , **itemB) > 0)
				{
					T* aux = *itemA;
					*itemA = *itemB;
					*itemB = aux;
				}
				j = &(*j) ->siguiente;
			}
			i = &(*i)->siguiente;
		}
		return this;
	}
	lista<T>* bubblesorted(Comparar<T>* comparar) {
		Node** i = &(this->cabeza);
		while (*i != nullptr)
		{
			Node** j = &(*i)->siguiente;
			while (*j != nullptr)
			{
				T** itemA = &(*i)->item;
				T** itemB = &(*j)->item;

				if (comparar->compare(**itemA, **itemB) < 0)
				{
					T* aux = *itemA;
					*itemA = *itemB;
					*itemB = aux;
				}
				j = &(*j)->siguiente;
			}
			i = &(*i)->siguiente;
		}
		return this;
	}
};

	