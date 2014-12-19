#ifndef SVSP_H
#define SVSP_H
#include <cstddef>
#include<iostream>

using namespace std;

typedef double Data;//!< ��������� ��������� ���� ������


struct Node//!< ���������� ��������� ����
{
    double value;
    Node* previous;
    Node* next;
};







class LinkedList //!< ��������� ����� LinkedList �������� ������
{
    Node* first;
    Node* last;
    Node* current;
    size_t size=0;

    friend void swap(LinkedList& a, LinkedList& b);// ������������� ������� ������ ���������  ������� �������

public:
    class Iterator //!< ��������� ����� Iterator ��� �������� ������
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

    LinkedList();// �������� ������� ������
    LinkedList(std::initializer_list<Data> values);
    LinkedList(const LinkedList& source);// �����������
    LinkedList(LinkedList&& source);// �����������
    LinkedList& operator=(LinkedList rhs);// �������� ������������
    virtual ~LinkedList();// ����������
    size_t get_size() const;// ������ ������
    Data& operator[](size_t index) const;// �������� ������ ���������� ��������
    void push_front(const Data& value);// ���������� �������� � ����� ������
    void push_back(const Data& value);// ���������� �������� � ������ ������
    void pop_front();// �������� �������� �� ����� ������
    void pop_back();// �������� �������� �� ������ ������
    void clear();// ������� �������� ������
    friend ostream& operator<<(ostream& output, const LinkedList& container);// �������� �����
    friend istream& operator>>(istream& input, LinkedList& container);// �������� ������
    void LL_erase (size_t index);//!< ����� ��� �������� ������������� ��������
    Iterator end() const;
    Iterator begin() const;
    Iterator find(const Data& what) const;
    Iterator erase(const Iterator& which);//!< ����� �������� �������� ��. ��������, �� ��������� ��������, �����. �� ����. ������� �� ���������
};







#endif // SVSP_H
