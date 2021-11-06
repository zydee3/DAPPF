//
// Created by Vince on 11/6/2021.
//

#ifndef DAPPF_TREE_NODE_H
#define DAPPF_TREE_NODE_H

namespace dappf::utility {
    class tree_node {
    private:
        tree_node* parent;
        tree_node* left_child;
        tree_node* right_child;
    public:
        tree_node();
        ~tree_node();

        tree_node* get_parent();
        tree_node* get_left_child();
        tree_node* get_right_child();

        void set_parent(tree_node*);
        void set_left_child(tree_node*);
        void set_right_child(tree_node*);

        bool is_root();
    };
}


#endif //DAPPF_TREE_NODE_H
