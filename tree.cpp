/*

                                             50
                                           /    \
                                        24       34
                                       /  \     /  \ 
                                    19    23  26   31
                                    / \    
                                   13  16
                                       /  \
                                      11   15
                                   

*/

#include<iostream>
#include<stack>


struct tree_node
{
    tree_node() : left(0), right(0)
    {}

    int value;
    tree_node* left;
    tree_node* right;
};

void take_left(const tree_node* const start)
{
    const tree_node* current = start; 
    while (current != 0)
    {
        std::cout << current->left->value << std::endl;

        current = current->left;
    }
    
}

void take_right(const tree_node* const start)
{
    const tree_node* current = start; 
    while (current != 0)
    {
        std::cout << current->value << std::endl;

        current = current->right;
    }
    
}

void iterate(tree_node const * const start)
{
    const tree_node* current = start; 
    if (current == 0)
    {
        return;
    }

    std::cout << current->value << std::endl;

    iterate(current->left);
    iterate(current->right);

    return;
}

void DFS(tree_node* start)
{
    std::stack<tree_node*> local_stack;
    local_stack.push(start);

    while (!local_stack.empty())
    {
        tree_node* temp = local_stack.top();
        
        local_stack.pop();

        std::cout << "value: " << temp->value << std::endl;
        
        if(temp->right)
        {
            local_stack.push(temp->right);
        }

        if(temp->left)
        {
            local_stack.push(temp->left);
        }
    }
    
}

void BFS(tree_node* start)
{
    std::queue<tree_node*> local_queue;
    local_queue.push(start);

    for(int i = 0; !local_queue.empty(); i++)
    {
        std::cout << "level: " << i << std::endl;

        std::vector<tree_node*> vector_tree;

        while (!local_queue.empty())
        {
            vector_tree.push_back(local_queue.front());
            local_queue.pop();
        }

        for(int i = 0; i < vector_tree.size(); i++)
        {

            std::cout << "value: " << vector_tree[i]->value << std::endl;

             if(vector_tree[i]->left)
            {
                local_queue.push(vector_tree[i]->left);
            }
        
            if(vector_tree[i]->right)
            {
                local_queue.push(vector_tree[i]->right);
            }
        }
        
        


       
        
        
    }
}


int main()
{
    tree_node root;
    tree_node l11,l12;
    tree_node l21, l22, l23, l24;
    tree_node l31, l32;
    tree_node l41, l42;

    root.left = &l11;
    root.right = &l12;

    l11.left = &l21;
    l11.right = &l22;
    l12.left = &l23;
    l12.right = &l24;

    l21.left = &l31;
    l21.right = &l32;

    l32.left = &l41;
    l32.right = &l42;

    root.value = 50;

    l11.value = 24;
    l12.value = 34;
    
    l21.value = 19;
    l22.value = 23;
    l23.value = 26;
    l24.value = 31;

    l31.value = 13;
    l32.value = 16;

    l41.value = 11;
    l42.value = 15;

    //take_right(&root);

    //iterate(&root);

    //DFS(&root);

    BFS(&root);
    return 0;
}