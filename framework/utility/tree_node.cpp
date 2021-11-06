//
// Created by Vince on 11/6/2021.
//

#include "tree_node.h"

dappf::utility::tree_node::tree_node() { }

dappf::utility::tree_node::~tree_node() {
    if(parent != nullptr){
        if(parent->get_left_child() == this) parent->set_left_child(nullptr);
        if(parent->get_right_child() == this) parent->set_right_child(nullptr);
        parent = nullptr;
    }

    if(left_child != nullptr){
        delete left_child;
        left_child = nullptr;
    }

    if(right_child != nullptr){
        delete right_child;
        right_child = nullptr;
    }
}

dappf::utility::tree_node* dappf::utility::tree_node::get_parent() {
    return parent;
}

void dappf::utility::tree_node::set_parent(dappf::utility::tree_node* node){
    parent = node;
}

dappf::utility::tree_node* dappf::utility::tree_node::get_left_child() {
    return left_child;
}

void dappf::utility::tree_node::set_left_child(dappf::utility::tree_node* node){
    left_child = node;
}

dappf::utility::tree_node* dappf::utility::tree_node::get_right_child() {
    return right_child;
}

void dappf::utility::tree_node::set_right_child(dappf::utility::tree_node* node){
    right_child = node;
}

bool dappf::utility::tree_node::is_root() {
    return parent == nullptr;
}
