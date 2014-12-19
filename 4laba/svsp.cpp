#include "svsp.h"
#include<iostream>
#include <cstddef>

/** @file svsp.h
* Объектно-ориентированное программирования
* Устройство связанного списка как структуры данных, а также идеи
и особенности алгоритмов операций над ним.
Применяли языковые средства С++ поддержки объектно-ориентированного
программирования (ООП) для реализации типа данных-связанного списка.
Овладели концепцией итераторов и её применением в сочетании
со стандартной библиотекой языка C++. Создали проект и отладку программ в среде Code::Blocks.
*/

/**
* A global integer value.
* More details about this value.
*/


/*!
* @brief Производит операции над связанным списком
* @author Юматов Борис и Всеволод Авдеев
* @date 2014
* @see LinkedList myLL
*/
using namespace std;

LinkedList::LinkedList()
{
    first = nullptr;
    last = nullptr;
    size = 0;


}
LinkedList::~LinkedList() //Деструктор
{
    while (first) //Пока по адресу на начало списка что-то есть
    {
        Node* temp_node = first->next; //Резервная копия адреса следующего звена списка
        delete first; //Очистка памяти от первого звена
        first=temp_node; //Смена адреса начала на адрес следующего элемента

    }
}

void LinkedList::LL_erase ( size_t index)
{


    Node * current_node = first;
    for (size_t i = 0; i != index; ++i)
    {
        current_node = current_node->next;
    }

    if (current_node -> previous)
        current_node -> previous -> next = current_node -> next;
    if (current_node ->next)
        current_node -> next-> previous = current_node -> previous;
    if (current_node == first)
        first = current_node -> next;
    if (current_node == last)
        last = current_node -> previous;
    delete current_node;
    --size;

}



void LinkedList::push_front(const Data& value)
{
    Node* node = new Node;
    node->value = value;
    node->previous = nullptr;
    node->next = first;
    if (first != nullptr)
    {
        first->previous = node;
    }
    first = node;
    if (last == nullptr)
    {
        last = node;
    }
    ++size;
}
void LinkedList::push_back(const Data& value)
{
    Node * node=new Node; //Выделение памяти под новый элемент структуры
    node->next=nullptr;  //Указываем, что изначально по следующему адресу пусто
    node->value=value; //Записываем значение в структуру

    if (first!=nullptr) //Если список не пуст
    {
        node->previous=last; //Указываем адрес на предыдущий элемент в соотв. поле
        last->next=node; //Указываем адрес следующего за хвостом элемента
        last=node; //Меняем адрес хвоста
        size++;
    }
    else //Если список пустой
    {
        node->previous=nullptr; //Предыдущий элемент указывает в пустоту
        first=last=node; //Голова=Хвост=тот элемент, что сейчас добавили
        size++;
    }

}

std::ostream& operator << (ostream& output, const LinkedList& container)
{
    Node* current = container.first;
    while (current)
    {
        output << current-> value << ' ';
        current = current-> next;
    }
    return output;
}
void LinkedList::clear()
{
    while (size)
        LL_erase (0);
}
size_t LinkedList::get_size() const
{
    return size;
}

void LinkedList::pop_back()
{
    Node* p=last->previous;
    p->next=nullptr;
    delete last;
    last=p;
    --size;
}
void LinkedList::pop_front()
{
    Node* p=first->next;
    p->previous=nullptr;
    delete first;
    first=p;
    --size;
}
LinkedList::LinkedList(initializer_list <Data> values ) :
    LinkedList()
{
    for (Data value : values)
    {
        push_back (value);
    }
}




void swap(LinkedList & a, LinkedList & b)
{
    swap ( a . first, b . first );
    swap ( a . last, b . last );
    swap ( a . size, b . size );
}


LinkedList::LinkedList(const LinkedList& source)
    : LinkedList()
{
    Node* current = source . first;
    while (current)
    {
        push_back (current-> value);
        current = current-> next;
    }
}

LinkedList& LinkedList::operator=(LinkedList value)
{
    swap(*this, value);
    return *this;
}

LinkedList::Iterator::Iterator (Node *obj)
{
    pointertonode=obj;
}




LinkedList::Iterator LinkedList::begin() const
{

    return Iterator (first) ;
}

LinkedList::Iterator LinkedList::end() const
{

    return Iterator (nullptr) ;
}

void LinkedList::Iterator::operator++()
{
    pointertonode=pointertonode->next;

}
Data& LinkedList::Iterator::operator* () const
{
    return pointertonode->value;

}
Data* LinkedList::Iterator::operator->() const
{
    return &pointertonode->value;
}

bool LinkedList::Iterator::operator!=(const Iterator& other) const
{
    return pointertonode!=other.pointertonode;
}
bool LinkedList::Iterator::operator==(const Iterator& other) const
{
    return pointertonode==other.pointertonode;
}

LinkedList::Iterator::Iterator() {}


LinkedList::Iterator LinkedList::find(const Data& what) const
{
    Iterator b=begin();
    Iterator e=end();
    while(b!=e)
    {

        if(*b==what) return b;
        ++b;
    }
    cout<< "not found"<<endl;
    return e;
}



Data& LinkedList::operator[](size_t index) const
{
    Node * current_node = first;
    for (size_t i = 0; i != index; ++i)
    {
        current_node = current_node->next;
    }
    return current_node->value;

}

LinkedList::Iterator LinkedList:: erase(const Iterator& which)
{
    size_t i=0;
    Node* pointertonode=first;
    while (pointertonode)
    {
        if (pointertonode== which.pointertonode)
        {
            ++i;
            Iterator result;
            result.pointertonode = which.pointertonode->next;

            LL_erase (i);

            return result;
        }
        pointertonode = pointertonode -> next;
    }
}


