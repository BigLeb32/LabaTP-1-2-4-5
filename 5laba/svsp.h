#ifndef SVSP_H
#define SVSP_H
#include <cstddef>
#include<iostream>

using namespace std;

typedef double Data;//!< Определен псевдоним типа данных


struct Node//!< Определена структура узла
{
    double value;
    Node* previous;
    Node* next;
};







class LinkedList //!< Определен класс LinkedList связного списка
{
    Node* first;
    Node* last;
    Node* current;
    size_t size=0;

    friend void swap(LinkedList& a, LinkedList& b);// дружественная функция обмена состояний  связных списков

public:
    class Iterator //!< определен класс Iterator для связного списка
    {
        friend class LinkedList;

        Node *pointertonode;

    public:

        Iterator(Node *obj);
        Iterator();
        bool operator!=(const Iterator& other) const;
        bool operator==(const Iterator& other) const;
        void operator++();
        Data& operator* () const;
        Data* operator->() const;
    };

    LinkedList();// создание пустого списка
    LinkedList(std::initializer_list<Data> values);
    LinkedList(const LinkedList& source);// копирование
    LinkedList(LinkedList&& source);// перемещение
    LinkedList& operator=(LinkedList rhs);// оператор присваивания
    virtual ~LinkedList();// деструктор
    size_t get_size() const;// размер списка
    Data& operator[](size_t index) const;// оператор взятия отдельного элемента
    void push_front(const Data& value);// добавление элемента в конец списка
    void push_back(const Data& value);// добавление элемента в начало списка
    void pop_front();// удаление элемента из конца списка
    void pop_back();// удаление элемента из начала списка
    void clear();// очистка связного списка
    friend ostream& operator<<(ostream& output, const LinkedList& container);// оператор ввода
    friend istream& operator>>(istream& input, LinkedList& container);// оператор вывода
    void LL_erase (size_t index);//!< метод для удаления произвольного элемента
    Iterator end() const;
    Iterator begin() const;
    Iterator find(const Data& what) const;
    Iterator erase(const Iterator& which);//!< Метод удаления элемента пр. итератор, на удаляемом элементе, возвр. на след. элемент за удаленным
};







#endif // SVSP_H
