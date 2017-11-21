/**
 * Author: Sam Gomena
 * Class: CS202 Fall 2017
 * Instructor: Karla Fant
 */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <fstream>
#include <cstring>
#include <cstdlib>
#include "list.h"

class Node {
public:
    Node();
    Node(int, int, float, int);
    ~Node();
    Node(const Node&);
    Node& operator=(const Node&);
    void add_data(float); // Wrapper for list add
    friend ostream& operator << (ostream&, const Node&);
    Node& operator+=(const Node&);
    void operator++();
    void operator++(int);
    Node& operator-=(const Node&);
    void operator--();
    void operator--(int);


    Node *left;
    Node *right;
    int days_to_race;
protected:
    int train_type;
    float workouts_per_week;
    int race_type;

private:
    Sol *race_history;
    const void determine_race_type(int) const;
    const void determine_train_type(int) const;
};

class BST {
public:
    BST();
    BST(const char *);
    ~BST();
    BST(const BST&);
    BST& operator=(const BST&);
    bool add(int, int, float, int, char *); // Wrapper for protected add
    void display();

protected:
    void destroy(Node *&);
    void copy(Node *&, Node *);
    bool add(Node *&, Node *&, int);
    void display(Node *);

    Node * root;
private:
    const char * DATA_FILE;
    void import();
};

#endif
