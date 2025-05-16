#include<iostream>
#include<stack>
#include<queue>

struct node
{
    int value;
};


int main()
{
    //int a = 1, x = 2;

    node n1 = {1}, n2 = {2}, n3 = {3};
    
    std::stack<node*> local_stack;

    local_stack.push(&n1);
    local_stack.push(&n2);
    local_stack.push(&n3);

    while(!local_stack.empty())
    {
        std::cout << local_stack.top()->value << std::endl;
        
        local_stack.pop();

    }

    std::cout << "*******************" << std::endl;

    std::queue<node*> local_queue;

    local_queue.push(&n1);
    local_queue.push(&n2);
    local_queue.push(&n3);

    while (!local_queue.empty())
    {
        std::cout << "queue: " << local_queue.front()->value << std::endl;

        local_queue.pop();
    }
    

    return 0;
}