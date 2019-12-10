#include "Node.h"

//Node Constructor
Node*createNode(int number){

    //Assign parametres to class fields
    Node *newNode = new Node();

    //newNode->left = left;

    //newNode->right = right;

    newNode->Number = number;

    return newNode;
}

//Empty Constructor
Node::Node(){

}