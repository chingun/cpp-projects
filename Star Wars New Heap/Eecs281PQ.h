#ifndef EECS281_PQ_H
#define EECS281_PQ_H

#include <functional>
#include <iterator>
#include <vector>

//An interface for a generic priority queue.  Derived class' runtime
//specifications assume constant time comparison and copying.

//*** You are not allowed to make any changes to this file ***

template<typename TYPE, typename COMP_FUNCTOR = std::less<TYPE>>
class Eecs281PQ {
public:
    virtual ~Eecs281PQ() {}

    //Description: Add a new element to the priority queue.
    virtual void push(const TYPE& val) = 0;

    //Description: Remove the most extreme (defined by 'compare') element from
    //             the priority queue.
    //Note: We will not run tests on your code that would require it to pop an
    //element when the priority queue is empty. Though you are welcome to if you are
    //familiar with them, you do not need to use exceptions in this project.
    virtual void pop() = 0;

    //Description: Return the most extreme (defined by 'compare') element of
    //             the priority queue.
    virtual const TYPE& top() const = 0;

    //Description: Get the number of elements in the priority queue.
    virtual std::size_t size() const = 0;

    //Description: Return true if the priority queue is empty.
    virtual bool empty() const = 0;

    //Description: Assumes that all elements in the priority queue are out of order.
    //             You must reorder the data so that the PQ invariant is restored.
    //             Each derived PQ will have to implement this appropriately.
    virtual void updatePriorities() = 0;

protected:
    //Note: These data members *must* be used in all of your priority queue
    //      implementations.

    //You can use this in the derived classes with:
    //this->compare(Thing1, Thing2)
    //With the default compare function (std::less), this will
    //tell you if Thing1 is lower priority than Thing2.
    COMP_FUNCTOR compare;
};


#endif
