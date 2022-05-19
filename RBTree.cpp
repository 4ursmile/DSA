#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#define fort(i,a,b) for (int i = a; i<=b; i++)
#define forstep(i,a,b,step) for (int i = a; i<=b; i+=step)
#define ford(i,a,b) for (int i = a; i>=b; i--)
#define forrange(i,a,b) for (int i = a; i<b; i++)
using namespace std;
struct Node {
    int data = 0;
    Node* parent;
    Node* left;
    Node* right;
     // 0 represent for black, 1 represent for red
    bool color = 0;
};
class RBTRee
{
private:
    const int Cspace = 10;
    Node* Root;
    // this bool use to flag 4 cases of deviated tree
    bool ll = 0, lr = 0, rr = 0, rl = 0;
    /// All private function below to help public function

    /// Get color name function
    string initColor(Node* root) {
        if (root->color)
            return "R";
        else
            return "B";
    }
    void Free(Node* root)
    {
        if (root == NULL) 
            return;
        Free(root->left);
        Free(root->right);
        delete root;
    }
    void InOrderPos(Node* root)
    {
        if (root == NULL) return;
        InOrderPos(root->left);
        cout << root->data << " ";
        InOrderPos(root->right);
    }
    bool RBTreeSearch(Node* root, int val)
    {
        if (root == NULL)
            return 0;
        if (root->data == val)
            return 1;
        else if (val < root->data)
            return RBTreeSearch(root->left, val);
        else
            return RBTreeSearch(root->right, val);
    }
    /// Rotate function group
    Node* RotateRight(Node* root)
    {
        Node* x = root->left;
        root->left = x->right;
        if (x->right != NULL)
            x->right->parent = root;
        //root->parent->child = x;
        x->parent = root->parent;
        if (root->parent==NULL)
            // if root is Root, Root = x;
            Root = x;
        else if (root->parent->left == root)
            root->parent->left =  x;
        else if (root->parent->right == root)
            root->parent->right = x;
        // x->right = root
        x->right = root;
        root->parent = x;
        return x;
    }
    Node* RotateLeft(Node* root)
    {
        Node* y = root->right;
        root->right = y->left;
        if (y->left != NULL)
            y->left->parent = root;
        //root->parent->child = y;
        y->parent = root->parent;
        if (root->parent == NULL)
            Root = y;
        else if (root->parent->left == root)
            root->parent->left =  y;
        else if (root->parent->right == root)
            root->parent->right = y;   
        //y->left = root; 
        y->left = root;
        root->parent = y;
        return y;
    }

    // Insert
    Node* InsertNode(Node* root, int val)
    {
        // this bool variable to flag Red red case;
        bool flag = false;
 
        if (root == NULL) {
            // Always add red node
            return new Node{ val, NULL, NULL, NULL, 1 }; 
        }
        else if (val < root->data) {
            root->left = InsertNode(root->left, val);
            root->left->parent = root;
            // Red Red case
            if (Root != root) {
                if (root->color == root->left->color == 1)
                    flag = true;
            }
        }
        else 
        if (val > root->data) // if you dont want duplicate in your tree, uncomment this line and vice versa
        {
            root->right = InsertNode(root->right, val);
            root->right->parent = root;
            // Red Red case
            if (Root != root) {
                if (root->color == root->right->color == 1)
                    flag = true;
            }
        }
 
        //Rotate tree and change color for 4 case
        // Left left case
        if (ll) {
            //Rotate right grandpa node, root is grandpa node for now
            //Parent node ->black ;
            // Grandpa node -> red;
            root = RotateRight(root);
            //root node become parent and grandpa node become sibling (right) for now
            root->color = 0;
            root->right->color = 1;
            ll = false;
        }
        // right right case
        else if (rr) {
            //Rotate left grandpa node, root is grandpa node for now
            //Parent node ->black ;
            // Grandpa node -> red;
            root = RotateLeft(root);
            //root node become parent and grandpa node become sibling (left) for now
            root->color = 0;
            root->left->color = 1;
            rr = false;
        }
        // Left right case
        else if (lr) {
            //Rotate left parent node
            root->left = RotateLeft(root->left);
            root->left->parent = root;
            // It change to ll case, handling like ll case
            root = RotateRight(root);
            root->color = 0;
            root->right->color = 1;
            lr = false;
        }
        // Right left case
        else if (rl) {
            //Rotate right parent node
            root->right = RotateRight(root->right);
            root->right->parent = root;
            // It change to rr case, handling like rr case
            root = RotateLeft(root);
            root->color = 0;
            root->left->color = 1;
            rl = false;
        }
 
        // Solve Red red problem
        if (!flag)
            return root;
        if (root->parent->right == root) {
            if (root->parent->left == NULL || root->parent->left->color == 0) {
                // Parent is red and uncle is black (rr or rl)
                if (root->left != NULL && root->left->color == 1)
                    rl = true;
                if (root->right != NULL && root->right->color == 1)
                    rr = true;
            }
            else {
                // both parent and uncle is red
                root->color = root->parent->left->color = 0;
                if (root != Root)
                    root->parent->color = 1;
            }
        }
        else {
            if (root->parent->right == NULL || root->parent->right->color == 0) {
                // Parent is red and uncle is black (ll or lr)
                if (root->left != NULL && root->left->color == 1)
                    ll = true;
                if (root->right != NULL && root->right->color == 1)
                    lr = true;
            }
            else {
                // both parent and uncle is red
                root->color = root->parent->right->color = 0;
                if (root != Root)
                    root->parent->color = 1;
            }
        }
        flag = false;
        return root;
    }

    //Delete;
    Node* Sibling(Node* root)
    {
        if (root->parent == NULL)
            return NULL;
        if (root->parent->left == root)
            return root->parent->right;
        else
            return root->parent->left;
    }
    bool HasRedChill(Node* root)
    {
        if (root->left != NULL)
            if (root->left->color == 1)
                return 1;
        if (root->right != NULL)
            if (root->right->color == 1)
                return 1;
        return 0;
    }

    void HandleDoubleBlack(Node* root)
    {
        if (root == Root)
            return;
        Node* sib = Sibling(root);
        Node* parent = root->parent;
        // sibling == nuull case
        if (sib == NULL)
            HandleDoubleBlack(parent);
        else
        {
            //sibling.color == red case
            if (sib->color == 1)
            {
                parent->color = 1;
                sib->color = 0;
                if (sib->parent->left == sib)
                    parent = RotateRight(parent);
                else
                    parent = RotateLeft(parent);
                HandleDoubleBlack(root);
            } else
            {
                // sibling color == 1 and have red child
                if (HasRedChill(sib))
                {
                    //sibling is left child of parent (ll or lr case)
                    if (sib->parent->left == sib)
                    {
                        // left left case
                        if (sib->left != NULL && sib->left->color)
                        {
                            sib->left->color = sib->color;
                            sib->color = parent->color;
                            parent->color = 0;
                            parent = RotateRight(parent);
                        } else // left right case
                        {
                            sib->right->color = parent->color;
                            parent->color = 0;
                            sib = RotateLeft(sib);
                            parent = RotateRight(parent);
                        }
                    } else//sibling is right child of parent (rr or rl case)
                    {
                        // rigt rigt case
                        if (sib->right != NULL && sib->right->color)
                        {
                            sib->right->color = sib->color;
                            sib->color = parent->color;
                            parent->color = 0;
                            parent = RotateLeft(parent);
                        } else // right left case
                        {
                            sib->left->color = parent->color;
                            parent->color = 0;
                            sib = RotateRight(sib);
                            parent = RotateLeft(parent);
                        }
                    }
                } else // 
                {
                    sib->color = 1;
                    if (!parent->color)
                        HandleDoubleBlack(parent);
                    else
                        parent->color = 0;
                }
            }
        } 
    }
    Node* MaxValueNode(Node* root)
    {
        Node* tmp;
        tmp = root;
        while (tmp->right != NULL)
            tmp = tmp->right;
        return tmp;
    }
    void DeleteNode(Node* vDelete)
    {
        Node* uReplace;
        if ((vDelete->left != NULL) && (vDelete->right != NULL))
            uReplace = MaxValueNode(vDelete->left);
        else if (vDelete->left != NULL) 
            uReplace = vDelete->left;
        else if (vDelete->right != NULL) 
            uReplace = vDelete->right;
        else 
            uReplace = NULL;
 
        bool uvBlack = ((uReplace == NULL) || (uReplace->color == 0)) && (vDelete->color == 0);
        Node* parent = vDelete->parent;
        Node* sib = Sibling(vDelete);
        if (uReplace == NULL) {
            if (vDelete == Root) {
                Root = NULL;
            }
            else {
                if (uvBlack)
                    HandleDoubleBlack(vDelete);
                else if(sib != NULL)
                    sib->color = 1;
 
                if (vDelete->parent->left == vDelete)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }
            delete vDelete;
            return;
        }
 
        if (vDelete->left == NULL || vDelete->right == NULL) {
            if (vDelete == Root) {
                vDelete->data = uReplace->data;
                vDelete->left = vDelete->right = NULL;
                delete uReplace;            
            }
            else {
                if (vDelete->parent->left == vDelete)
                    parent->left = uReplace;
                else
                    parent->right = uReplace;
                delete vDelete;
 
                uReplace->parent = parent;
                if (uvBlack)
                    HandleDoubleBlack(uReplace);
                else
                    uReplace->color = 0;
            }
            return;
        }
        //swap value of u and v
        int tmp = vDelete->data;
        vDelete->data = uReplace->data;
        uReplace->data =  tmp;
        DeleteNode(uReplace);
    }
    
    // print
    void PrintTree(Node* root, int space) {
        if (root == NULL)
            return;
        space += Cspace;

        PrintTree(root->right, space);
        cout << endl;

        for (int i = Cspace; i < space; i++)
            cout << " ";
        cout << root->data << " (" << initColor(root) << ") " << "\n";

        PrintTree(root->left, space);
    }
    
    int _get_height(Node* sr)
    {
        if (!sr)
            return -1;
        return 1 + max(_get_height(sr->left), _get_height(sr->right));
    }

    void _display_subtree(Node* q, vector<string>& output, int left, int top, int width)
    {
        string str = to_string(q->data)+ "(" + initColor(q) + ")";

        int left_begin_shift = 1 - (str.length() - 1) / 2;
        for (size_t i = 0; i < str.length() && left + width / 2 + i < output[top].length(); i++)
            output[top][left + width / 2 + left_begin_shift + i] = str[i];

        int branch_off_set = (width + 3) / pow(2, 3);
        int mid = left + width / 2;
        int left_mid = left + (width / 2 - 1) / 2;
        int right_mid = left + width / 2 + 2 + (width / 2 - 1) / 2;

        if (q->left)
        {
            int branch_position = mid - branch_off_set + 1;
            for (int pos = mid + left_begin_shift - 2; pos > branch_position; pos--)
                output[top][pos] = '_';
            output[top + 1][branch_position] = '/';
            for (int pos = branch_position - 1; pos > left_mid + 2; pos--)
                output[top + 1][pos] = '_';
            _display_subtree(q->left, output, left, top + 2, width / 2 - 1);
        }

        if (q->right)
        {
            int branch_position = mid + branch_off_set + 1;
            for (int pos = mid + left_begin_shift + str.length() + 1; pos < branch_position; pos++)
                output[top][pos] = '_';
            output[top + 1][branch_position] = '\\';
            for (int pos = branch_position + 1; pos < right_mid; pos++)
                output[top + 1][pos] = '_';
            _display_subtree(q->right, output, left + width / 2 + 2, top + 2, width / 2 - 1);
        }
    }


    void _display_tree(Node* root)
    {
        if (!root)
            return;

        int height = _get_height(root);
        int width_display = 4 * pow(2, height) - 3;
        int height_display = 2 * height + 1;

        vector<string> output(height_display);
        for (size_t i = 0; i < output.size(); i++)
            output[i] = string(width_display + 4, ' ');

        _display_subtree(root, output, 0, 0, width_display);

        for (int row = 0; row < height_display; row++)
            cout << output[row] << endl;
    }
public:
    RBTRee()
    {
        Root = NULL;
    }
    RBTRee(int val)
    {
        Root = new Node{ val,NULL, NULL, NULL, 0 };
    }
    RBTRee(int* Arr, int n)
    {
        Root = NULL;
        forrange(i, 0, n)
            Insert(Arr[i]);
    }
    ~RBTRee()
    {
        Free(Root);
    }
    void DeleteTree() {
        Free(Root);
    }
    void Print(int Delta = 0)
    {
        _display_tree(Root);
    }
    //Inorder browser
    void Inorder()
    {
        InOrderPos(Root);
    }
    bool Search(int val)
    {
        return RBTreeSearch(Root, val);
    }
    Node* SearchNode(int val)
    {
        Node* tmp = Root;
        while (tmp !=  NULL)
        {
            if (val < tmp->data)
                tmp = tmp->left;
            else if (val == tmp->data)
                break;
            else
                tmp = tmp->right;
        }
        return tmp;
        
    }
    void Delete(int val)
    {
        Node* vD = SearchNode(val);
        if (vD == NULL)
        {
            cout << "Gia tri " << val <<" khong ton tai trong cay! \n";
            return;
        }
        cout << "Delete node " << val << " form tree! \n";
        DeleteNode(vD);
    }
    void Insert(int val)
    {
        if (Root == NULL)
            /// Root node is alway black
            Root = new Node{ val,NULL,NULL,NULL,0 };
        else
        {
            Root = InsertNode(Root, val);
            // Sure that Root node is alway black
            if (Root->color)
                Root->color = 0;
        }
    }
};

int main()
{
    int A[]{ -1,-2,3,4,5,6,7,8,9,0,1,-2,-6,4,5,6,20,30,50,46,22 };
    RBTRee Tree(A, 21);
    Tree.Print();
    Tree.Delete(9);
    Tree.Print(9);
    Tree.Delete(14);
    Tree.Delete(4);
    Tree.Print();
    return 0;
}