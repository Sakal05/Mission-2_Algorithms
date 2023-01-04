//Header file for Double_node class

#ifndef DOUBLENODE_H
#define DOUBLENODE_H

template <class T> //Generic template for the Double_node class
class Double_node
{
  private:
    T data;//Generic data type       
    Double_node<T> *next;//Node pointer pointing to the next node 
    Double_node<T> *prev;//Node pointer pointing to the previous node     

  public:
    Double_node(T data){
    data = getData();
    next = nullptr;
    prev = nullptr;
    }//constructor

    T getData() {
        return data;
    }//Return data
    Double_node<T> *getNext() {
        return next;
    }//Return next
    Double_node<T> *getPrev() {
        return prev;
    }//Return prev
    
    void setData(T data) {
        this->data = data;
    }//Set data to the input data
    void setNext(Double_node<T> *next){
        this->next = next;
    } //Set next to the input next
    void setPrev(Double_node<T> *prev) {
        this->prev = prev;
    };//Set prev to the input prev

};

#endif