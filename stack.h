template<typename T>
class Stack{
private:
	struct node{
		T val;
		node* below = NULL,* above = NULL;
		node(T val, node* above, node* below):
			val(val), above(above), below(below) {}
	};
	size_t sz = 0;
	node* head = nullptr;
public:
	Stack(){}
	~Stack(){
		while(!this->empty())
			this->pop();
	}
	size_t size(){ return sz; }
	bool empty(){ return head == nullptr; }
	T top(){ return head == nullptr ? INT_MAX : head->val; }
	void push(T v){
		sz++;
		if(head == nullptr) {
			head = new node(v, nullptr, nullptr);
		} else {
			head->above = new node(v, nullptr, head);
			head = head->above;
		}
	}
	void pop(){
		if(head == nullptr)
			return;
		node* toRemove = head;
		head = head->below;
		if(head != nullptr)
			head->above = nullptr;
		delete toRemove;
		sz--;
	}
};
