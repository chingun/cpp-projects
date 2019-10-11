#ifndef JARJARPQ_H
#define JARJARPQ_H

#include "Eecs281PQ.h"

#include <algorithm>
#include <cassert>
#include <iterator>
#include <vector>

//A bad priority queue that linearly searches for the maximum element every
//time it is needed. You do not need to implement this; it is already done
//for you.

//It uses bestIndexValid and bestIndex because a call to .top() is almost
//always followed by a call to .pop().  If .top() remembers the index of
//the best element, .pop() doesn't immediately have to perform another
//linear search.

template<typename TYPE, typename COMP_FUNCTOR = std::less<TYPE>>
class JarJarPQ  : public Eecs281PQ<TYPE, COMP_FUNCTOR> {
public:
    //Description: Construct a priority queue out of an iterator range with an optional
    //             comparison functor.  When bestIndexValid is false, the bestIndex is
    //             not known, but it's good to initialize all member variables.
    //Runtime: O(n) where n is number of elements in range.
    template<typename InputIterator>
    JarJarPQ(InputIterator start, InputIterator end, COMP_FUNCTOR comp = COMP_FUNCTOR())
        : data(start, end), bestIndex(0), bestIndexValid(false)
    {
        this->compare = comp;
    } // JarJarPQ()


    //Description: Construct an empty priority queue with an optional comparison functor.
    //             When bestIndexValid is false, the bestIndex is not known, but it's good
    //             to initialize all member variables.
    //Runtime: O(1)
    JarJarPQ(COMP_FUNCTOR comp = COMP_FUNCTOR()) : bestIndex(0), bestIndexValid(false) {
        this->compare = comp;
    } // JarJarPQ()


    //Description: Add a new element to the priority queue.
    //Runtime: O(1)
    virtual void push(const TYPE& val) {
        data.push_back(val);
        //If the best index is already known, update it if the new element
        //has higher priority
        if (bestIndexValid)
            if (this->compare(data[bestIndex], data.back())) {
                bestIndex = data.size() - 1;
            } // if
    } // push()


    //Description: Remove the most extreme (defined by 'compare') element from
    //             the priority queue.
    //Runtime: O(1) if the highest priority element is already known, O(n) otherwise
    virtual void pop() {
        assert(!data.empty());

        //If the best index is not known, calculate it
        if (!bestIndexValid) {
            auto it = std::max_element(data.begin(), data.end(), this->compare);
            bestIndex = it - data.begin();
        } // if

        std::swap(data[bestIndex], data.back());
        data.pop_back();
        bestIndexValid = false;
    } // pop()


    //Description: Return the most extreme (defined by 'compare') element of
    //             the priority queue.
    //Runtime: O(1) if the highest priority element is already known, O(n) otherwise
    virtual const TYPE& top() const {
        //If the best index is not known, calculate it: pop() will probably be called next
        if (!bestIndexValid) {
            auto it = std::max_element(data.begin(), data.end(), this->compare);
            bestIndex = it - data.begin();
            bestIndexValid = true;
        } // if

        return data[bestIndex];
    } // top()


    //Description: Get the number of elements in the priority queue.
    //Runtime: O(1)
    virtual std::size_t size() const {
        return data.size();
    } // size()


    //Description: Return true if the priority queue is empty.
    //Runtime: O(1)
    virtual bool empty() const {
        return data.empty();
    } // empty()


    //Description: Assumes that all elements in the priority queue are out of order.
    //             There is no reordering of the data to be done, simply mark the
    //             best index as not known.
    //Runtime: O(1)
    virtual void updatePriorities() {
        bestIndexValid = false;
    } // updatePriorities()

private:
    std::vector<TYPE> data;
    mutable std::size_t bestIndex;
    mutable bool bestIndexValid;
};

#endif // JARJARPQ_H
