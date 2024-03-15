#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

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

                this->tail->setNext(new DLLNode<T>(data));
                this->tail->getNext()->setPrev(tail);
                this->tail = this->tail->getNext();

            } else {

                this->head = new DLLNode<T>(data);
                this->tail = this->head;

            }

            this->size++;

        }

        void pop(){

            if(this->size){
                DLLNode<T>* popped = this->tail;
                this->tail = this->tail->getPrev();
                delete popped;

                this->size--;
            } 

        }

        void insert(T data, int idx){

        }

        void remove(int idx){

        }

        int size(){
            return this->size;
        };

        void print(){
            std::cout << "DoublyLinkedList:";

            if(!this->head){
                std::cout << "NULL";
                return;
            }
            
            std::cout << "{";

            DLLNode<T>* temp = this->head;
            
            for(int i = 0; i < this->size; i++){
                std::cout << temp->getData();

                if(i == this->size - 1;){
                    std::cout << "}";
                } else {
                    std::cout << ", ";
                    temp = temp->getNext();
                }

            }
        }

        T& at(int idx){
            
            if(idx < 0){
                return nullptr;
            }

            if(idx >= this->size){
                return nullptr;
            }

            DLLNode<T>* temp = this->head;

            for(unsigned int i = 0; i < idx; i++){
                temp = temp->getNext();
            }

            return temp->getData();
        }

        ~DoublyLinkedList(){
            while(head != nullptr){
                DLLNode* next = head->getNext();
                delete head;
                head = next;
            }
        }

        DoublyLinkedList(const DoublyLinkedList& original){

            this->size = 0;

            for(int i; i < original.size(); i++){

                this->push(original.at(i));

            }

        }

        DoublyLinkedList<T>& operator=(const DoublyLinkedList& original){

            return DoublyLinkedList<T>(original);

        }

};

template <typename T>
class DLLNode {

    private:
        DLLNode<T>* next;
        DLLNode<T>* prev:
        T data;

    public:
        DLLNode(T data){
            this->next = nullptr;
            this->prev = nullptr;
            this->data = data;
        }

        T getData(){
            return this->data;
        }
        
        void setData(T data){
            this->data = data;
        }

        DLLNode<T>* getNext(){
            return this->next;
        }

        void setNext(DLLNode<T>* next){
            this->next = next;
        }

        DLLNode<T>* getPrev(){
            return this->prev;
        }

        void setPrev(DLLNode<T>* prev){
            this->prev = prev;
        }

};

#endif
