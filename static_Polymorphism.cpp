/*
Static Polymorphism

using TMP: Template Metaprogramming

Template is also usually called Static Polymorphism
*/
#include <iostream>
using namespace std;

// Dynamic polymorphism cost:
// 1. memory cost of virtual table
// 2. run time cost of dynamic binding

struct TreeNode 
{
    TreeNode *left, *right;
};

class Generic_Parser
{
public:
    void parse_preorder(TreeNode* node){
        if(node){
            process_node(node);
            parse_preorder(node->left);
            parse_preorder(node->right);
        }
    }
private:
    virtual void process_node(TreeNode* node){}
};

class EmployeeChart_Parser: public Generic_Parser{
private:
    void process_node(TreeNode *node){
        cout<<"Customized process_node() for EmployeeChart.\n";
    }
};

int main(){
    TreeNode *root;
    root->left=0;
    root->right=0;
    EmployeeChart_Parser ep;
    ep.parse_preorder(root);
}



/*
1. is-a relationship between base class and derived class
2. Base class defines a "generic" algorihm that's used by derived class
3. The "generic" algorithm is customized by the derived class
*/

// Use template

template<typename T> class Generic_Parser{
public:
    void parse_preorder(TreeNode* node){
        if(node){
            process_node(node);
            parse_preorder(node->left);
            parse_preorder(node->right);
        }
    }
    void process_node(TreeNode* node){
        static_cast<T*>(this)->process_node(node);
    }

};

class EmployeeChart_Parser: public Generic_Parser<EmployeeChart_Parser>{
private:
    void process_node(TreeNode *node){
        cout<<"Customized process_node() for EmployeeChart.\n";
    }
};

// Use template, consume more compile time, but not running time
// And takes more memory for the code, because two different typename creates different base classes





