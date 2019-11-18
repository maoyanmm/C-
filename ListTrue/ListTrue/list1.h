#include<iostream>
using namespace std;

template <class T>
struct ListNode//结点类
{
	ListNode(const T& value = T())//数据的初始值为该类型的默认值
	:_data(value)
	, _prev(nullptr)
	, _next(nullptr)
	{
	}

	T _data;
	ListNode<T>* _prev;
	ListNode<T>* _next;
};

template <class T>
struct ListIterator
{
	typedef ListNode<T> Node;
	typedef Node* pNode;
	typedef ListIterator<T> Self;//Self为本身这个类的类型

	ListIterator(const pNode node)
		:_node(node)
	{
	}

	T& operator*()
	{
		return _node->_data;
	}
	
	T* operator->()
	{
		return &(_node->_data);
	}
	//迭代器前置++
	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	Self operator++(int)//int只是为了符合后置++语法
	{
		Self tmp(*this);
		_node = _node->_next;
		return tmp;
	}
	//迭代器前置--
	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	Self operator--(int)
	{
		Self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}

	bool operator!=(const Self& it)
	{
		return this->_node != it._node;//实际上是判断其中的成员变量_node是否相等
	}

	bool operator==(const Self& it)
	{
		return this->_node == it._node;
	}

	pNode _node;
};

template <class T>
class List
{
public:
	typedef ListNode<T> Node;
	typedef Node* pNode;
	typedef ListIterator<T> iterator;
	List()
	{
		CreateHead();
	}

	void CreateHead()
	{
		_head = new Node;
		_head->_next = _head;//一开始先将头的前后指向指向自己
		_head->_prev = _head;
	}

	List(const List<T>& lst)//拷贝构造需要深拷贝
	{
		CreateHead();//先把head创建了才能插入
		for (const auto e : lst)
		{
			PushBack(e);
		}
	}

	template <class InputIterator>
	List(InputIterator first, InputIterator last)
	{
		CreateHead();
		while (first != last)
		{
			PushBack(*first);
			++first;
		}
	}

	List<T>& operator=(List<T> lst)//传的是值，所以在传值的时候会隐式调用拷贝构造出一个深拷贝的lst
	{                           //所以只需交换head即可
		swap(_head,lst._head);
		return *this;
	}

	~List()
	{
		Clear();
		delete _head;
		_head = nullptr;
	}

	void PopBack()
	{
		Erase(iterator(_head->_prev));
	}

	void PopFront()
	{
		Erase(iterator(_head->_next));
	}

	void PushBack(const T& value)
	{
		Insert(end(), value);
	}

	void PushFront(const T& value)
	{
		Insert(begin(), value);
	}

	void Insert(iterator pos,const T& value)//prev -- pos -- next
	{                                   //          
		//创建结点
		pNode newnode = new Node(value);
		//插入结点
		pNode prev = pos._node->_prev;//要创建一个pos的前面的结点，否则将pos和newnode连接后将无法找到pos->prev
		pos._node->_prev = newnode;
		newnode->_next = pos._node;
		prev->_next = newnode;
		newnode->_prev = prev;
	}

	iterator Erase(iterator pos)//prev -- pos -- next
	{
		if (pos._node != _head )
		{
			//将pos的前后指向保留
			pNode prev = pos._node->_prev;
			pNode next = pos._node->_next;
			//释放
			delete pos._node;
			pos._node = nullptr;
			//连接
			prev->_next = next;
			next->_prev = prev;
			//更新迭代器为删除结点的下一个结点
			pos = iterator(next);
		}
		return pos;
	}

	bool Empty()
	{
		return _head->_next == _head;
	}

	void Clear()
	{
		if (!Empty())
		{
			iterator it = begin();
			while (it != end())
			{
				it = Erase(it);//因为Erase执行完毕后会返回删除结点的下一个结点，所以只需要用it接收就可以，而且删除了当前元素，it就失效了
				//++it; 不需要++it，如果++了，则会跳过一个结点
			}
		}
	}

	iterator begin()
	{
		return iterator(_head->_next);//返回的其实是是：有着和_head->next的值一样的成员变量的迭代器
	}

	iterator end()
	{
		return iterator(_head);
	}

	size_t Size()
	{
		size_t count = 0;
		/*pNode cur = _head->_next;
		while (cur != _head)
		{
			cur = cur->_next;
			++count;
		}*/
		for (const auto& e : *this)
		{
			++count;
		}
		return count;
	}

private:
	pNode _head;
};