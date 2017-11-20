/**
 * Author: Sam Gomena
 * Class: CS202 Fall 2017
 * Instructor: Karla Fant
 */

#ifndef LIST_H
#define LIST_H

#include "utils.h"

class ListNode {
public:
    ListNode();
    ListNode(float);
    friend ostream& operator << (ostream&, const ListNode&);
    const float data() const;
    float data(float);
    bool operator==(const ListNode&) const;
    bool operator>(const ListNode&) const;
    bool operator<(const ListNode&) const;
    ListNode *next;


protected:
    float data_point;
};

class Sol {
public:
    Sol();
    ~Sol();
    Sol(const Sol &);
    Sol& operator=(const Sol&);
    bool add(float);
    int display();
    ListNode& operator[](int);
    const ListNode& operator[](int) const;



protected:
    ListNode * head, * tail;

    void destroy(ListNode *&);
    bool copy(ListNode *&, ListNode *);
    bool add(ListNode *&);
    bool add(ListNode *, ListNode *&);
    int display(ListNode *);
    ListNode& get_element_at(ListNode*, int, int) const;
};

#endif