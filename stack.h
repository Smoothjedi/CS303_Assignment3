#ifndef STACK_H_
#define STACK_H_
/** Definition file for class KW:: stack */
// Include directives needed by the implementation
#include <vector>
namespace KW {
	/** A stack is a data structure that provides last-in first-out access to the items that are stored in it. Only the most recently inserted item is accessible.
	*/
	template<typename Item_Type> class stack {
	public:
		// Constructor and member functions

		/** Constructs an initially empty stack. */ 
		stack();
		/** Pushes an item onto the top of the stack.
		@param item The item to be inserted
		*/
		void push(const Item_Type& item);
		/** Returns a reference to the object at the top of the stack without removing it.
		@return A reference to the object at the top of the stack
		*/
		Item_Type& top();
		/** Returns a const reference to the object at the at the top of the stack without removing it.
		@return A const reference to the object at the top of the stack
		*/
		const Item_Type& top() const;

		/** Removes the top item from the stack. */
		void pop();
		/** Determines whether the stack is empty. */
		bool empty() const;
		/** Returns the number of items in the stack. */ 
		size_t size() const;
	private:
		// Data fields
		/** A sequential container to contain the stack items */ 
		std::vector<Item_Type> container;
	}; // End class stack
	// Insert implementation of member functions here #include "Stack.tc"
} // End namespace KW
#endif