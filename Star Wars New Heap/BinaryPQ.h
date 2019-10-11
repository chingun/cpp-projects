#ifndef BINARY_H
#define BINARY_H

#include "Eecs281PQ.h"
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

//A specialized version of the priority queue ADT implemented as a binary heap.

template<typename TYPE, typename COMP_FUNCTOR = std::less<TYPE>>
class BinaryPQ : public Eecs281PQ<TYPE, COMP_FUNCTOR> {
public:
    //Description: Construct a priority queue out of an iterator range with an optional
    //             comparison functor.
    //Runtime: O(n) where n is number of elements in range.
    template<typename InputIterator>
        BinaryPQ(InputIterator start, InputIterator end, COMP_FUNCTOR comp = COMP_FUNCTOR());

    //Description: Construct an empty priority queue with an optional comparison functor.
    //Runtime: O(1)
    BinaryPQ(COMP_FUNCTOR comp = COMP_FUNCTOR());

    //Description: Add a new element to the priority queue.
    //Runtime: O(log n)
    virtual void push(const TYPE& val);

    //Description: Remove the most extreme (defined by 'compare') element from
    //             the priority queue.
    //Note: We will not run tests on your code that would require it to pop an
    //element when the priority queue is empty. Though you are welcome to if you are
    //familiar with them, you do not need to use exceptions in this project.
    //Runtime: O(log n)
    virtual void pop();

    //Description: Return the most extreme (defined by 'compare') element of
    //             the priority queue.
    //Runtime: O(1)
    virtual const TYPE& top() const;

    //Description: Get the number of elements in the priority queue.
    //Runtime: O(1)
    virtual std::size_t size() const {
        //Fill this in - might be very simple depending on implementation
        return data.size();
    }

    //Description: Return true if the priority queue is empty.
    //Runtime: O(1)
    virtual bool empty() const {
        // Fill this in - might be very simple depending on implementation
        return data.empty();
    }

    //Description: Assumes that all elements in the priority queue are out of order.
    //             You must reorder the data so that the PQ invariant is restored.
    //Runtime: O(n)
    virtual void updatePriorities();

    void printall(){
        cout << "    " << data[0] << endl;
        cout << "  " << data[1] << "   ";
        cout << data[2] << endl;
        cout << " " << data[3] << " ";
        cout << data[4] << "  ";
        cout << data[5] << " ";
        cout << data[6] << endl;
        cout << data[7] << "   ";
    }
    void printall2(){
        cout << "    " << data[0] << endl;
        cout << "  " << data[1] << "   ";
        cout << data[2] << endl;
        cout << " " << data[3] << " ";
        cout << data[4] << "  ";
        cout << data[5] << " ";
        cout << data[6] << endl;
    }
    
    
private:
    //Note: This vector *must* be used your priority queue implementation.
    std::vector<TYPE> data;
private:
    //TODO: Add any additional member functions or data you require here.
    COMP_FUNCTOR comp;
    void FixUp(int k){
        while(k > 0 && this->compare(data[k/2], data[k])){
            swap(data[k], data[k/2]);
            k /= 2;
        }
    }
    
    void FixDown(int heapsize, int k){
        while(2 * k <= heapsize){
            int j = 2 * k;
            if((j < heapsize) && this->comp(data[j], data[j + 1])) ++j;
            if(!this->compare(data[k],data[j])) break;
            swap(data[k],data[j]);
            k = j;
        }
    }
};


//Description: Construct a priority queue out of an iterator range with an optional
//             comparison functor.
//Runtime: O(n) where n is number of elements in range.
//TODO: when you implement this function, uncomment the parameter names
template<typename TYPE, typename COMP_FUNCTOR>
template<typename InputIterator>
BinaryPQ<TYPE, COMP_FUNCTOR>::BinaryPQ(
        InputIterator start,
        InputIterator end,
        COMP_FUNCTOR comp){
    this->compare = comp;
    vector<TYPE> arr(start, end);
    for (int i = 0; i < arr.size(); i++) {
        push(arr[i]);
    }
}


//Description: Construct an empty priority queue with an optional comparison functor.
//Runtime: O(1)
//TODO: when you implement this function, uncomment the parameter name
template<typename TYPE, typename COMP_FUNCTOR>
BinaryPQ<TYPE, COMP_FUNCTOR>::BinaryPQ(COMP_FUNCTOR comp){
    this->compare = comp;
}


//Description: Add a new element to the priority queue.
//Runtime: O(log n)
//TODO: when you implement this function, uncomment the parameter name
template<typename TYPE, typename COMP_FUNCTOR>
void BinaryPQ<TYPE, COMP_FUNCTOR>::push(const TYPE & val) {
    data.push_back(val);
    FixUp((int)data.size() - 1);
}

//Description: Remove the most extreme (defined by 'compare') element from
//             the priority queue.
//Note: We will not run tests on your code that would require it to pop an
//element when the priority queue is empty. Though you are welcome to if you are
//familiar with them, you do not need to use exceptions in this project.
//Runtime: O(log n)
template<typename TYPE, typename COMP_FUNCTOR>
void BinaryPQ<TYPE, COMP_FUNCTOR>::pop() {
    swap(data[0], data[data.size() - 1]);
    data.pop_back();
    FixDown((int)data.size() - 1, 0);
    
}

//Description: Return the most extreme (defined by 'compare') element of
//             the priority queue.
//Runtime: O(1)
template<typename TYPE, typename COMP_FUNCTOR>
const TYPE& BinaryPQ<TYPE, COMP_FUNCTOR>::top() const {
    return data[0];
}

//Description: Assumes that all elements in the priority queue are out of order.
//             You must reorder the data so that the PQ invariant is restored.
//Runtime: O(n)
template<typename TYPE, typename COMP_FUNCTOR>
void BinaryPQ<TYPE, COMP_FUNCTOR>::updatePriorities(){  // <= WRONG NEED FIXING 
    for (int i = (int)data.size() - 1; i >= 0; i--) {
        swap(data[i], data[0]);
     
        FixDown((int)data.size() - 1, 0);
    }
}


#endif //BINARY_H
