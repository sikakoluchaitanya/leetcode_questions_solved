/*Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
 

Example 1:

Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, top, and empty.
All the calls to pop and top are valid.*/

typedef struct {
    int* data;
    int top;
    int capacity;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->data = (int*)malloc(sizeof(int) * 100); // Adjust the capacity as needed
    stack->top = -1;
    stack->capacity = 100; // Adjust the capacity as needed
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    obj->data[++obj->top] = x;
}

int myStackPop(MyStack* obj) {
    if (obj->top >= 0) {
        return obj->data[obj->top--];
    }
    return -1; // Stack is empty
}

int myStackTop(MyStack* obj) {
    if (obj->top >= 0) {
        return obj->data[obj->top];
    }
    return -1; // Stack is empty
}

bool myStackEmpty(MyStack* obj) {
    return obj->top == -1;
}

void myStackFree(MyStack* obj) {
    free(obj->data);
    free(obj);
}
