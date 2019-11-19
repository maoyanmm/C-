#include<iostream>
using namespace std;

template <class T>
struct ListNode//�����
{
	ListNode(const T& value = T())//���ݵĳ�ʼֵΪ�����͵�Ĭ��ֵ
	:_data(value)
	, _prev(nullptr)
	, _next(nullptr)
	{
	}

	T _data;
	ListNode<T>* _prev;
	ListNode<T>* _next;
};

template <class T, class Ref, class Ptr>//ģ���������࣬T��Ϊ�˶��������Node
struct ListIterator                 //Ref��Ptr��Ϊ����List�ж���const����������ͨ������ʱ�������任T&��T*ǰ���Ƿ���const
{
	typedef ListNode<T> Node;
	typedef Node* pNode;
	typedef ListIterator<T, Ref, Ptr> Self;//SelfΪ��������������

	ListIterator(const pNode node)
		:_node(node)
	{
	}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &(_node->_data);
	}

	//������ǰ��++
	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	Self operator++(int)//intֻ��Ϊ�˷��Ϻ���++�﷨
	{
		Self tmp(*this);
		_node = _node->_next;
		return tmp;
	}
	//������ǰ��--
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
		return this->_node != it._node;//ʵ�������ж����еĳ�Ա����_node�Ƿ����
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
	typedef ListIterator<T, T&, T*> iterator;
	typedef ListIterator<T, const T&, const T*> const_iterator;//����const������ʱ�������ú�ָ������Ϊconst

	List()
	{
		CreateHead();
	}

	void CreateHead()
	{
		_head = new Node;
		_head->_next = _head;//һ��ʼ�Ƚ�ͷ��ǰ��ָ��ָ���Լ�
		_head->_prev = _head;
	}

	List(const List<T>& lst)//����������Ҫ���
	{
		CreateHead();//�Ȱ�head�����˲��ܲ���
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

	List<T>& operator=(List<T> lst)//������ֵ�������ڴ�ֵ��ʱ�����ʽ���ÿ��������һ�������lst
	{                           //����ֻ�轻��head����
		swap(_head, lst._head);
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

	void Insert(iterator pos, const T& value)//prev -- pos -- next
	{                                   //          
		//�������
		pNode newnode = new Node(value);
		//������
		pNode prev = pos._node->_prev;//Ҫ����һ��pos��ǰ��Ľ�㣬����pos��newnode���Ӻ��޷��ҵ�pos->prev
		pos._node->_prev = newnode;
		newnode->_next = pos._node;
		prev->_next = newnode;
		newnode->_prev = prev;
	}

	iterator Erase(iterator pos)//prev -- pos -- next
	{
		if (pos._node != _head)
		{
			//��pos��ǰ��ָ����
			pNode prev = pos._node->_prev;
			pNode next = pos._node->_next;
			//�ͷ�
			delete pos._node;
			pos._node = nullptr;
			//����
			prev->_next = next;
			next->_prev = prev;
			//���µ�����Ϊɾ��������һ�����
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
				it = Erase(it);//��ΪEraseִ����Ϻ�᷵��ɾ��������һ����㣬����ֻ��Ҫ��it���վͿ��ԣ�����ɾ���˵�ǰԪ�أ�it��ʧЧ��
				//++it; ����Ҫ++it�����++�ˣ��������һ�����
			}
		}
	}

	iterator begin()
	{
		return iterator(_head->_next);//���ص���ʵ���ǣ����ź�_head->next��ֵһ���ĳ�Ա�����ĵ�����
	}

	iterator end()
	{
		return iterator(_head);
	}

	const_iterator begin()const
	{
		return const_iterator(_head->_next);
	}

	const_iterator end()const
	{
		return const_iterator(_head);
	}

	/*void PrintList()    // ͨ������˽�г�Աhead���������е�data��Ա
	{
	pNode cur = _head->_next;
	while (cur != _head)
	{
	cout << cur->_data << ' ';
	cur = cur->_next;
	}
	cout << endl;
	}*/

	//void PrintList()    //�õ�����������data��Ա
	//{
	//	iterator it = begin();
	//	while (it != end())
	//	{
	//		cout << *it << ' ';
	//		++it;
	//	}
	//	cout << endl;
	//}

	void PrintList()
	{
		for (const auto& e : *this)
		{
			cout << e << ' ';
		}
		cout << endl;
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
		for (const auto& e : *this)//�÷�Χfor������
		{
			++count;
		}
		return count;
	}

private:
	pNode _head;
};