#pragma once
#include<iostream>
namespace mystl
{

struct list_node {
    int val;
    list_node* next;
    list_node(int _val) : val(_val), next(nullptr)
    {}
};

class list
{
private:
    list_node* head;
public:
    list(int _val);

    ~list();

    list_node* get_head() { return head; }

    void push_back(int val);

    void pop_front();
};

}  // namespace mystl