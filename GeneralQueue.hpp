#include <iostream>
//Do not include GeneralList.hpp because 
//	GeneralStack.hpp already includes it
/*#include "GeneralList.hpp"*/

template <class QueueClass>
class Queue {
	private:
		List<QueueClass> _values;
		size_t _size;
	public:
		Queue(){
			_size = 0;
		}
		
		Queue(const Queue<QueueClass> &q) { 

			_values = q._values;
			_size = _values.size();
		}
		
		size_t size() const{
			return _size;
		}

		QueueClass front() const{
			return _values.front();
		}

		QueueClass back() const{
			return _values.back();
		}

		void enqueue(QueueClass value) {
			_values.push_back(value);	
		}

		void dequeue(){
			_values.pop_front();
		}

		void print(){
			_values.print();
		}

		bool search(QueueClass value) {
			return _values.search(value);
		}


		bool empty() const{
			return( _values.empty());
		}

		Queue<QueueClass> &operator=(const Queue<QueueClass> q) {	
				_values=q._values;
				_size=_values.size();
				return *this;
		}
			

		template <class U>
		friend std::ostream &operator<<(std::ostream &out, 
				const Queue<U> &q);

		template <class U>
		friend bool operator==(const Queue<U> &left_queue, 
				const Queue<U> &right_queue);

		template <class U>
		friend bool operator!=(const Queue<U> &left_queue, 
				const Queue<U> &right_queue);

};
template <class U>
std::ostream &operator<<(std::ostream &out, const Queue<U> &q) {
		out << q._values;
	
}

template <class U>
bool operator==(const Queue<U> &left_side, const Queue<U> &right_side) {
	if(left_side._values != right_side._values) {
		return false;
	}
	else {
	return true;
	}
}

template <class U>
bool operator!=(const Queue<U> &left_side, const Queue<U> &right_side) {
	return !(left_side==right_side);

}
