#include <bits/stdc++.h>
//#include "display_tree.cpp"
#define e endl
#define n NULL
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};


//////////////////////////////////
/////   Function Prototype ///////
//////////////////////////////////


node * insert_num(node *,int);
void display(node *);
void search_num(node *,int);
void clear_screen();
void menu();
void display_menu();
void display(node *);
void preorder(node *);
void inorder(node *);
void postorder(node *);
void levelorder(node *);
int maxFind(node *);




////////////////////////////
////// main()  starts///////
////////////////////////////

int main()
{
    node *root=NULL;
    int option;
    int num;
    while(1)
    {
        menu();
        cin>>option;
        switch(option)
        {
            case 0:
                clear_screen();
                break;
            case 1:
                cin>>num;
                root=insert_num(root,num);
                break;
            case 2:
                display(root);
                break;
            case 3:
                cin>>num;
                search_num(root,num);
                break;
            case 4:
                exit(0);
                break;
            case 5:
                num=maxFind(root);
                cout<<num<<e;
                break;
            default:
                cout<<"Invalid input"<<e;
        }
    }
    return 100;
}


////////////////////////////
////// main()  ENDs/////////
////////////////////////////

void menu()
{
    cout<<e;
    cout<<"------------------------------"<<e;
    cout<<"0 : Clear"<<e;
    cout<<"1 : Insert"<<e;
    cout<<"2 : Display"<<e;
    cout<<"3 : Search"<<e;
    cout<<"4 : Exit"<<e;
    cout<<"5 : FindMax"<<e;
    cout<<"------------------------------"<<e;
}


void clear_screen()
{
    system("clear");
}

node * insert_num(node *root,int num)
{
    node *tmp;
    tmp=(node *)malloc(sizeof(node));
    if(!tmp)
        cout<<"Memeory Full"<<e;
    else
    {
        tmp->left=n;
        tmp->right=n;
        tmp->data=num;
        if(!root)
            return tmp;
        else
        {
            node *ptr;
            queue<node *> q;
            q.push(root);
            while(!q.empty())
            {
                ptr=q.front();
                q.pop();
                if(ptr->left)
                    q.push(ptr->left);
                else
                {
                    ptr->left=tmp;
                    //q.clear();
                    return root;
                }
                if(ptr->right)
                    q.push(ptr->right);
                else
                {
                    ptr->right=tmp;
                    //q.clear();
                    return root;
                }
            }
        }
    }
}


////////////////////////////////////////////
//////Display Functions start here//////////
////////////////////////////////////////////

void display_menu()
{
    cout<<"------Tree Traversal-------"<<e;
    cout<<"0 : Clear Screen"<<e;
    cout<<"1 : Preorder"<<e;
    cout<<"2 : Inorder"<<e;
    cout<<"3 : Postorder"<<e;
    cout<<"4 : Level Order"<<e;
    cout<<"5 : Main Menu"<<e;
    cout<<"---------------------------"<<e;
}


void display(node *root)
{
    if(!root)
        cout<<"Empty"<<e;
    else
    { 
        while(1)
        {
            
            int option;
            display_menu();
            cin>>option;
            switch(option)
            {
                case 0:
                    clear_screen();
                    break;
                case 1:
                    cout<<"Preorder"<<e;
                    preorder(root);
                    cout<<e;
                    break;
                case 2:
                    cout<<"Inorder"<<e;
                    inorder(root);
                    cout<<e;
                    break;
                case 3:
                    cout<<"Postorder"<<e;
                    postorder(root);
                    cout<<e;
                    break;
                case 4:
                    cout<<"Levelorder"<<e;
                    levelorder(root);
                    cout<<e;
                    break;
                case 5:
                    return;
                default:
                    cout<<"Invalid Input"<<e;
            }
        }

    }
}

void preorder(node *root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}


void inorder(node *root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}


void postorder(node *root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}


void levelorder(node *root)
{
    if(!root)
        return;
    queue<node *> q;
    q.push(root);
    node *tmp;
    if(tmp)
        cout<<"hi";
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        cout<<tmp->data<<" ";
        if(tmp->left)
            q.push(tmp->left);
        if(tmp->right)
            q.push(tmp->right);
    }
    free(tmp);
    return;
}

////////////////////////////////////////////
//////Display Functions END here////////////
////////////////////////////////////////////


//---------------------------------------------------------------------------



//////////////////////////////////////////////////
//////Search Functions Search START here//////////
//////////////////////////////////////////////////

void search_num(node *root,int key)
{
    if(!root)
    {
        cout<<"Tree Empty"<<e;
        return;
    }
    queue<node *> q;
    node *tmp;
    q.push(root);
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        if(tmp->data==key)
        {
            cout<<"FOUND "<<key<<" in Tree"<<e;
            return;
        }
        if(tmp->left)
            q.push(tmp->left);
        if(tmp->right)
            q.push(tmp->right);
    }
    cout<<"NOT Found "<<key<<" in Tree"<<e;
    return;
}

////////////////////////////////////////////
//////Search Functions END here/////////////
////////////////////////////////////////////


int maxFind(node *root)
{
    int left,right,root_val,max=INT_MIN;
    if(root)
    {
        root_val=root->data;
        left=maxFind(root->left);
        right=maxFind(root->right);
        if(left>right)
            max=left;
        else
            max=right;
        if(max<root_val)
            max=root_val;
    }
    return max;
}