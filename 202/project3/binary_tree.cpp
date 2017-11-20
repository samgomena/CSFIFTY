/**
 * Author: Sam Gomena
 * Class: CS202 Fall 2017
 * Instructor: Karla Fant
 */

#include "binary_tree.h"

Node::Node() : left(NULL), right(NULL), race_history(new Sol()) {}

Node::Node(int days_to_race, int train_type, float workouts_per_week, int race_type)
        : left(NULL), right(NULL), race_history(NULL), days_to_race(days_to_race),
          train_type(train_type), workouts_per_week(workouts_per_week), race_type(race_type) {
    race_history = new Sol();
}

Node::~Node() {
    if(race_history) {
        delete race_history;
    }
}

Node::Node(const Node & copy) : left(NULL), right(NULL), race_history(copy.race_history) {}

Node &Node::operator=(const Node & equal) {
    if(this == &equal) {
        return *this;
    }
    if(race_history) {
        delete race_history;
    }
    this->days_to_race = equal.days_to_race;
    this->workouts_per_week = equal.workouts_per_week;
    this->train_type = equal.train_type;
    this->race_type = equal.race_type;
    this->race_history = equal.race_history;
}

void Node::add_data(float data_point) {
    race_history->add(data_point);
}

ostream& operator << (ostream& out, const Node& node) {
    out << "Days to race: " << node.days_to_race
        << "\nWorkouts per week: " << node.workouts_per_week
        << "\nTraining type: " << node.train_type
        << "\nRace type: " << node.race_type
        << "\nPrevious race times: ";
    int num_races = node.race_history->display();
    cout << "Total races completed: " << num_races << endl;
    return out;
}

BST::BST() : root(NULL) {
    import(); // Load data from file into bst
}

BST::BST(const char * INPUT): root(NULL), DATA_FILE(INPUT) {
    import(); // Load data from file into bst
}

BST::~BST() {
    destroy(root);
}

BST::BST(const BST & copy_me) : root(NULL) {
    copy(root, copy_me.root);
}

BST &BST::operator=(const BST & equal) {
    if(this == &equal) {
        return *this;
    }
    if(root) {
        destroy(root);
    }
    copy(root, equal.root);
    return *this;
}

bool BST::add(int days_to_race, int train_type, float workouts_per_week, int race_type, char * race_history) {
    Node *node = new Node(days_to_race, train_type, workouts_per_week, race_type);
    char *str_char;
    str_char = strtok(race_history, ", ");  // Split list
    while(str_char) {
        node->add_data(atof(str_char)); // Convert to float and add to race history list function
        str_char = strtok(NULL, ", ");
    }

    add(this->root, node, days_to_race);
    return true;
}

void BST::display() {
//    if(!root) {
//        cout << "You have no racing data!" << endl;
//    }
    display(root);
}

// Protected Functions
void BST::destroy(Node *&root) {
    if(!root) {
        return;
    }
    destroy(root->left);
    destroy(root->right);
    delete root;
    root = NULL;
    return;
}

void BST::copy(Node *& dest, Node * src) {
    if(src == NULL) {
        dest = NULL;
        return;
    }
    dest = new Node(*src);
    copy(dest->left, src->left);
    copy(dest->right, src->right);
    return;
}

bool BST::add(Node *& root, Node *& new_node, int key) {
    if(!root) {
        root = new_node;
        return true;
    } else if(key < root->days_to_race) {
        add(root->left, new_node, key);
    } else {
        add(root->right, new_node, key);
    }
    return true;
}

void BST::display(Node * root) {
    if(!root) {
        return;
    }
    display(root->left);
    cout << *root << endl; // TODO: Make this use overloaded operator
    display(root->right);
    return;
}

// Private Functions
void BST::import() {
    ifstream in(DATA_FILE);
    char str[256];
    int days_to_race;
    int train_type;
    float workouts_per_week;
    int race_type;
    if(in.is_open()) {
        while(!in.eof()) {
            in >> days_to_race;
            in >> train_type;
            in >> workouts_per_week;
            in >> race_type;
            in.getline(str, 256);

            if(!in.eof()) {
                add(days_to_race, train_type, workouts_per_week, race_type, str);
            }
        }
    } else {
        cout << "Could not find data file."
                "\nPlease try again, adding the data file as an argument."
                "\n\tNote: data file provided is `data.txt`" << endl;
    }

}


