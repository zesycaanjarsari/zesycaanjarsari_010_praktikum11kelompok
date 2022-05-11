#include <iostream>
#include <cstdlib>
using namespace std;

class BinarySearchTree
{
    private:
    struct nodeTree
    {
        nodeTree* kiri;
        nodeTree* kanan;
        int data;
    };
    nodeTree* root;

    public:
    BinarySearchTree()
    {
        root = NULL;
    }

    bool isEmpty() const { return root==NULL; }
    void print_inorder();
    void inorder(nodeTree*);
    void print_preorder();
    void preorder(nodeTree*);
    void print_postorder();
    void postorder(nodeTree*);
    void insert(int);
    void hapus(int);
};

void BinarySearchTree::insert(int d)
{
    nodeTree* t = new nodeTree;
    nodeTree* parent;
    t->data = d;
    t->kiri = NULL;
    t->kanan = NULL;
    parent = NULL;

    if(isEmpty()) root = t;
    else
    {
        nodeTree* current;
        current = root;

        while(current)
        {
            parent = current;
            if(t->data > current->data) current = current->kanan;
            else current = current->kiri;
        }

        if(t->data < parent->data)
        parent->kiri = t;
        else
        parent->kanan = t;
    }
}

void BinarySearchTree::hapus(int d)
{
    //Locate the element
    bool found = false;
    if(isEmpty())
    {
        cout<<" Tree Masih kosong! "<<endl;
        return;
    }

    nodeTree* current;
    nodeTree* parent;
    current = root;

    while(current != NULL)
    {
        if(current->data == d)
        {
            found = true;
            break;
        }
        else
        {
            parent = current;
            if(d>current->data) current = current->kanan;
            else current = current->kiri;
        }
    }
    if(!found)
    {
        cout<<" Data not found! "<<endl;
        return;
    }

    // Node dengan single child
    if((current->kiri == NULL && current->kanan != NULL)|| (current->kiri != NULL && current->kanan == NULL))
    {
        if(current->kiri == NULL && current->kanan != NULL)
        {
        if(parent->kiri == current)
        {
            parent->kiri = current->kanan;
            delete current;
        }
        else
        {
            parent->kanan = current->kanan;
            delete current;
        }
        }
        else
        {
            if(parent->kiri == current)
            {
                parent->kiri = current->kiri;
                delete current;
            }
            else
            {
                parent->kanan = current->kiri;
                delete current;
            }
        }
        return;
    }

    // node tidak mempunyai child node
    if( current->kiri == NULL && current->kanan == NULL)
    {
        if(parent->kiri == current ) parent->kiri = NULL;
        else parent->kanan = NULL;
        delete current;
        return;
    }

    //Node dengan 2 child node
    // ganti node dengan nilai terkecil di subtree bagain kanan
    if (current->kiri != NULL && current->kanan != NULL)
    {
        nodeTree* temp;
        temp = current->kanan;
        if((temp->kiri == NULL) && (temp->kanan == NULL))
        {
            current = temp;
            delete temp;
            current->kanan = NULL;
        }
        else
    {

    if((current->kanan)->kiri != NULL)
    {
        nodeTree* lcurrent;
        nodeTree* lcurrp;
        lcurrp = current->kanan;
        lcurrent = (current->kanan)->kiri;
        while(lcurrent->kiri != NULL)
        {
            lcurrp = lcurrent;
            lcurrent = lcurrent->kiri;
        }
        current->data = lcurrent->data;
        delete lcurrent;
        lcurrp->kiri = NULL;
    }
    else
    {
        nodeTree* tmp2;
        tmp2 = current->kanan;
        current->data = tmp2->data;
        current->kanan = tmp2->kanan;
        delete tmp2;
    }

    }
    return;
    }

}

void BinarySearchTree::print_inorder()
{
    inorder(root);
}

void BinarySearchTree::inorder(nodeTree* p)
{
    if(p != NULL)
    {
        if(p->kiri) inorder(p->kiri);
        cout<<" "<<p->data<<" ";
        if(p->kanan) inorder(p->kanan);
    }
    else return;
}

void BinarySearchTree::print_preorder()
{
    preorder(root);
}

void BinarySearchTree::preorder(nodeTree* p)
{
    if(p != NULL)
    {
        cout<<" "<<p->data<<" ";
        if(p->kiri) preorder(p->kiri);
        if(p->kanan) preorder(p->kanan);
    }
    else return;
}

void BinarySearchTree::print_postorder()
{
    postorder(root);
}

void BinarySearchTree::postorder(nodeTree* p)
{
    if(p != NULL)
    {
        if(p->kiri) postorder(p->kiri);
        if(p->kanan) postorder(p->kanan);
        cout<<" "<<p->data<<" ";
    }
    else return;
}

int main()
{
    BinarySearchTree b;
    int ch,tmp,tmp1;
    while(1)
    {
        cout<<endl<<endl;
        cout<<" Binary Search Tree Operations "<<endl;
        cout<<" ----------------------------- "<<endl;
        cout<<" 1. Insertion/Creation "<<endl;
        cout<<" 2. In-Order Traversal "<<endl;
        cout<<" 3. Pre-Order Traversal "<<endl;
        cout<<" 4. Post-Order Traversal "<<endl;
        cout<<" 5. Removal "<<endl;
        cout<<" 6. Exit "<<endl;
        cout<<" Pilih operasi yang ingin dilakukan : ";
        cin>>ch;
        switch(ch)
        {
            case 1 : cout<<" Masukkan nilai yang pada BST : ";
            cin>>tmp;
            b.insert(tmp);
            break;
            case 2 : cout<<endl;
            cout<<" In-Order Traversal "<<endl;
            cout<<" -------------------"<<endl;
            b.print_inorder();
            break;
            case 3 : cout<<endl;
            cout<<" Pre-Order Traversal "<<endl;
            cout<<" -------------------"<<endl;
            b.print_preorder();
            break;
            case 4 : cout<<endl;
            cout<<" Post-Order Traversal "<<endl;
            cout<<" --------------------"<<endl;
            b.print_postorder();
            break;
            case 5 : cout<<" Masukan nilai yang ingin dihapus : ";
            cin>>tmp1;
            b.hapus(tmp1);
            break;
            case 6 :
            return 0;

        }
    }
}
