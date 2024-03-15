#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

template <typename T>
struct DLLNode {

    DLLNode<T>* next;
    DLLNode<T>* prev;
    T data;

    DLLNode(T data){
        this->next = nullptr;
        this->prev = nullptr;
        this->data = data;
    }

};

template <typename T>
class DoublyLinkedList {

    private:
        DLLNode<T>* head;
        DLLNode<T>* tail;
        unsigned int size;
    
    public:
        DoublyLinkedList(){

            this->head = nullptr;
            this->tail = nullptr;
            this->size = 0;

        }

        void push(T data){

            if(size){

                DLLNode<T>* tailNode = this->tail;

                this->tail = new DLLNode<T>(data);
                this->tail->prev = tailNode;
                tailNode->next = this->tail;

            } else {

                this->head = new DLLNode<T>(data);
                this->tail = this->head;

            }

            this->size++;

        }

        void pop(){

            if(this->size){
                DLLNode<T>* popped = this->tail;
                this->tail = this->tail->prev;
                delete popped;

                this->size--;
            } 

        }

        void insert(T data, int idx){

            if(idx < 0 || idx >= this->size){
                std::cout << "Nothing Inserted. Index Error" << std::endl;
                return;
            }

            DLLNode<T>* newNode = new DLLNode<T>(data);

            if(idx == 0){ // insert at head

                DLLNode<T>* headNode = this->head;

                this->head = newNode;
                headNode->prev = newNode;
                newNode->next = headNode;

                this->size++;

                return;

            }

            if(idx == (this->size - 1)){ // insert before tail

                T oldData = this->tail->data;
                
                this->tail->data = data;

                this->push(oldData);

                return;

            }
            
            DLLNode<T>* nextNode = this->head;

            for(unsigned int i = 0; i < idx; i++){

                nextNode = nextNode->next;

            }

            DLLNode<T>* prevNode = nextNode->prev;

            prevNode->next = newNode;
            nextNode->prev = newNode;

            newNode->next = nextNode;
            newNode->prev = prevNode;

            this->size++;

        }

        void remove(int idx){

            if(idx < 0 || idx >= this->size){
                std::cout << "Nothing Removed. Index Error" << std::endl;
                return;
            }

            DLLNode<T>* tempNode = this->head;

            for(unsigned int i = 0; i < idx; i++){

                tempNode = tempNode->next;                    

            }

            DLLNode<T>* prevNode = tempNode->prev;
            DLLNode<T>* nextNode = tempNode->next;

            if(!prevNode){ // were at the head

                this->head = nextNode;
                nextNode->prev = nullptr;

            } else if(!nextNode){ // were at the tail

                this->tail = prevNode;
                prevNode->next = nullptr;

            } else { // inbetween
                
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
            }

            delete tempNode;

            this->size--;

        }

        int getSize() const {
            return this->size;
        };

        void print(){
            std::cout << "DoublyLinkedList:";

            if(!this->head){
                std::cout << "NULL";
                return;
            }
            
            std::cout << "{";

            DLLNode<T>* tempNode = this->head;
            
            for(int i = 0; i < this->size; i++){
                std::cout << tempNode->data;

                if(i == (this->size - 1)){
                    std::cout << "}";
                } else {
                    std::cout << ", ";
                    tempNode = tempNode->next;
                }

            }

            std::cout << std::endl;
        }

        T& at(int idx) const{

            DLLNode<T>* tempNode = this->head;

            for(unsigned int i = 0; i < idx; i++){
                tempNode = tempNode->next;
            }

            return tempNode->data;
        }

        ~DoublyLinkedList(){
            while(head != nullptr){
                DLLNode<T>* next = head->next;
                delete head;
                head = next;
            }
        }

        DoublyLinkedList(const DoublyLinkedList& original){

            this->size = 0;
            this->head = nullptr;
            this->tail = nullptr;

            for(unsigned int i = 0; i < original.getSize(); i++){

                this->push(original.at(i));

            }

        }

        void operator=(const DoublyLinkedList& rhs){

            while(this->head != nullptr){
                DLLNode<T>* tempNode = this->head;
                this->head = this->head->next;
                delete tempNode;
            }

            this->head = nullptr;
            this->tail = nullptr;
            this->size = 0;

            for(unsigned int i = 0; i < rhs.getSize(); i++){

                this->push(rhs.at(i));
            
            }
            
        }

};

#endif
