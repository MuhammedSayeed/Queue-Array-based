#include <iostream>
using namespace std;

class Queue
{
private:
    int *data_list;
    int front_index;
    int rear_index;
    int initial_size;
    int current_size;
    int length;
    bool isFull()
    {
        if (this->length == this->current_size)
        {
            return true;
        }
    }

public:
    Queue()
    {
        this->initial_size = 5;
        this->current_size;
        this->data_list = new int[this->initial_size];
        this->current_size = this->initial_size;
        this->front_index = 0;
        this->rear_index = -1;
        this->length = 0;
    }

    bool isEmpty()
    {
        if (this->length == 0)
        {
            return true;
        }
        return false;
    }

    void resizeOrNot()
    {
        if (!this->isFull())
        {
            return;
        }
        cout<<"queue will resizeed"<<endl;
        int *new_array = new int[current_size + initial_size];
        copy(this->data_list, this->data_list + current_size, new_array);
        delete[] this->data_list;
        this->data_list = new_array;
    }
    void enqueue(int _data)
    {
        this->resizeOrNot();

        this->data_list[++this->rear_index] = _data;
        length++;
    }

    int getFront(){
        if(isEmpty()){
            cout<<"Queue is empty, cannot get rear"<<endl;
            return -1;
        }
        return this->data_list[this->front_index];
    }

    int getRear(){
        if(isEmpty()){
            cout<<"Queue is empty, cannot get rear"<<endl;
            return -1;
        }
        return this->data_list[this->rear_index];
    }

    int dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty, cannot dequeue"<<endl;
            return -1;
        }
        int front_value = this->data_list[this->front_index];
        this->front_index++;
        this->length--;

        return front_value;
    }

    void print()
    {
        for (int i = this->front_index; i <= length; i++)
        {
            cout << data_list[i] << " -> ";
        }
        cout << "NULL";
        cout << endl;
    }

};

int main()
{

    Queue *q = new Queue();
    q->enqueue(10);
 
    cout<<q->dequeue()<<endl;
    q->print();
    cout<<"front value " <<q->getFront()<<endl;
    cout<<"rear value " <<q->getRear()<<endl;

    return 0;
}