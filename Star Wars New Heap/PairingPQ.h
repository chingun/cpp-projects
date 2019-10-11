#ifndef PAIRING_PQ_H
#define PAIRING_PQ_H

#include "Eecs281PQ.h"

//A specialized version of the priority queue ADT implemented as a pairing heap.

template<typename TYPE, typename COMP_FUNCTOR = std::less<TYPE>>
class PairingPQ : public Eecs281PQ<TYPE, COMP_FUNCTOR> {
public:
    //Description: Construct a priority queue out of an iterator range with an optional
    //             comparison functor.
    //Runtime: O(n) where n is number of elements in range.
    template<typename InputIterator>
        PairingPQ(InputIterator start, InputIterator end, COMP_FUNCTOR comp = COMP_FUNCTOR());

    //Description: Construct an empty priority queue with an optional comparison functor.
    //Runtime: O(1)
    PairingPQ(COMP_FUNCTOR comp = COMP_FUNCTOR());

    //Description: Copy constructor.
    //Runtime: O(n)
    PairingPQ(const PairingPQ &other);

    //Description: Copy assignment operator.
    //Runtime: O(n)
    PairingPQ &operator=(const PairingPQ &rhs);

    //Description: Destructor
    //Runtime: O(n)
    ~PairingPQ();

    //Description: Add a new element to the priority_queue. This has been provided for you,
    //             in that you should implement push functionality in the
    //             addNode function.
    //Runtime: Amortized O(1)
    virtual void push(const TYPE& val) { addNode(val); }

    //Description: Remove the most extreme (defined by 'compare') element from
    //             the priority queue.
    //Note: We will not run tests on your code that would require it to pop an
    //element when the priority queue is empty. Though you are welcome to if you are
    //familiar with them, you do not need to use exceptions in this project.
    //Runtime: Amortized O(log n)
    virtual void pop();

    //Description: Return the most extreme (defined by 'compare') element of
    //             the priority queue.
    //Runtime: O(1)
    virtual const TYPE &top() const;

    //Description: Get the number of elements in the priority queue.
    //Runtime: O(1)
    virtual std::size_t size() const {
        //TODO: Implement this function
        return 0; // TODO: Delete or change this line
    }

    //Description: Return true if the priority queue is empty.
    //Runtime: O(1)
    virtual bool empty() const {
        //TODO: Implement this function
        return true; // TODO: Delete or change this line
    }

    //Description: Assumes that all elements in the priority queue are out of order.
    //             You must reorder the data so that the PQ invariant is restored.
    //Runtime: O(n)
    virtual void updatePriorities();

    // Each node within the pairing heap
    class Node {
        public:
            Node(const TYPE &val)
                : elt(val), sibling(nullptr), child(nullptr)
            {}
        public:
            //Description: Allows access to the element at that Node's position.
            //Runtime: O(1) - this has been provided for you.
            const TYPE &operator*() const { return elt; }
            const Node *sibling_ptr() const { return sibling; }
            const Node *child_ptr() const { return child; }

            //The following line allows you to access any private data members of this
            //Node class from within the PairingPQ class. (ie: myNode.elt is a legal
            //statement in PairingPQ's add_node() function).
            friend PairingPQ;
        private:
            TYPE elt;
            Node *sibling;
            Node *child;
    };

    //Description: Updates the priority of an element already in the priority_queue by
    //             replacing the element refered to by the Node with new_value.
    //             Must maintain priority_queue invariants.
    //
    //PRECONDITION: The new priority, given by 'new_value' must be more extreme
    //              (as defined by comp) than the old priority.
    //
    //Runtime: As discussed in reading material.
    void updateElt(Node* node, const TYPE &new_value);

    //Description: Add a new element to the priority_queue. Returns a Node* corresponding
    //             to the newly added element.
    //Runtime: Amortized O(1)
    Node* addNode(const TYPE& val);

    const Node *root_ptr() const { return root; }

private:
    Node *root;
    //TODO: Add any additional member functions or data you require here.
    //TODO: We recommend creating a 'meld' function (see the Pairing Heap papers).
};


//Description: Construct a priority queue out of an iterator range with an optional
//             comparison functor.
//Runtime: O(n) where n is number of elements in range.
//TODO: when you implement this function, uncomment the parameter names
template<typename TYPE, typename COMP_FUNCTOR>
template<typename InputIterator>
PairingPQ<TYPE, COMP_FUNCTOR>::PairingPQ(
        InputIterator /* start */,
        InputIterator /* end */,
        COMP_FUNCTOR /* comp */
        ) {
    //TODO: Implement this function
}


//Description: Construct an empty priority queue with an optional comparison functor.
//Runtime: O(1)
//TODO: when you implement this function, uncomment the parameter name
template<typename TYPE, typename COMP_FUNCTOR>
PairingPQ<TYPE, COMP_FUNCTOR>::PairingPQ(COMP_FUNCTOR /* comp */) {
    //TODO: Implement this function
}


//Description: Copy constructor.
//Runtime: O(n)
//TODO: when you implement this function, uncomment the parameter name
template<typename TYPE, typename COMP_FUNCTOR>
PairingPQ<TYPE, COMP_FUNCTOR>::PairingPQ(const PairingPQ & /* other */) {
    //TODO: Implement this function
}


//Description: Copy assignment operator.
//Runtime: O(n)
//TODO: when you implement this function, uncomment the parameter name
template<typename TYPE, typename COMP_FUNCTOR>
PairingPQ<TYPE, COMP_FUNCTOR>&
PairingPQ<TYPE, COMP_FUNCTOR>::operator=(const PairingPQ & /* rhs */) {
    //TODO: Implement this function
    return *this;
}


//Description: Destructor
//Runtime: O(n)
template<typename TYPE, typename COMP_FUNCTOR>
PairingPQ<TYPE, COMP_FUNCTOR>::~PairingPQ() {
    //TODO: Implement this function
}


//Description: Remove the most extreme (defined by 'compare') element from
//             the priority queue.
//Note: We will not run tests on your code that would require it to pop an
//element when the priority queue is empty. Though you are welcome to if you are
//familiar with them, you do not need to use exceptions in this project.
//Runtime: Amortized O(log n)
template<typename TYPE, typename COMP_FUNCTOR>
void PairingPQ<TYPE, COMP_FUNCTOR>::pop() {
    //TODO: Implement this function
}


//Description: Return the most extreme (defined by 'compare') element of
//             the priority queue.
//Runtime: O(1)
template<typename TYPE, typename COMP_FUNCTOR>
const TYPE &PairingPQ<TYPE, COMP_FUNCTOR>::top() const {
    //TODO: Implement this function

    //These lines are present only so that this provided file compiles.
    static TYPE temp; //TODO: Delete this line
    return temp;      //TODO: Delete or change this line
}


//Description: Assumes that all elements in the priority queue are out of order.
//             You must reorder the data so that the PQ invariant is restored.
//Runtime: O(n log n)
template<typename TYPE, typename COMP_FUNCTOR>
void PairingPQ<TYPE, COMP_FUNCTOR>::updatePriorities() {
    //TODO: Implement this function
}


//Description: Updates the priority of an element already in the priority_queue by
//             replacing the element refered to by the Node with new_value.
//             Must maintain priority_queue invariants.
//
//PRECONDITION: The new priority, given by 'new_value' must be more extreme
//              (as defined by comp) than the old priority.
//
//Runtime: As discussed in reading material.
//TODO: when you implement this function, uncomment the parameter names
template<typename TYPE, typename COMP_FUNCTOR>
void PairingPQ<TYPE, COMP_FUNCTOR>::updateElt(Node * /* node*/, const TYPE & /*new_value */) {
    //TODO: Implement this function
}


//Description: Add a new element to the priority_queue. Returns a Node* corresponding
//             to the newly added element.
//Runtime: Amortized O(1)
//TODO: when you implement this function, uncomment the parameter name
template<typename TYPE, typename COMP_FUNCTOR>
typename PairingPQ<TYPE, COMP_FUNCTOR>::Node*
PairingPQ<TYPE, COMP_FUNCTOR>::addNode(const TYPE & /* val */) {
    //TODO: Implement this function

    //These lines are present only so that this provided file compiles.
    return nullptr; //TODO: Delete or change this line
}


#endif //PAIRING_H
