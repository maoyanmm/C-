#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
#include<vector>

template<class V>
struct HashNode
{
	V _data;
	HashNode<V>* _next;

	HashNode(const V& data = V())
		:_data(data)
		, _next(nullptr)
	{ }
};

//前置声明
template<class K, class V, class KeyOfValue,class HashFun>
class HashBucket;
//迭代器
template<class K, class V, class KeyOfValue, class HashFun>
struct HashIterator
{
	typedef HashNode<V> Node;
	typedef Node* pNode;
	typedef HashIterator<K, V, KeyOfValue, HashFun> Self;
	typedef typename HashBucket<K, V, KeyOfValue, HashFun> HSbucket;

	pNode _node;
	HSbucket* _hb;

	HashIterator(pNode node, HSbucket* hb)
		:_node(node)
		, _hb(hb)
	{

	}

	V& operator*()
	{
		return _node->_data;
	}
	V* operator->()
	{
		return &_node->_data;
	}
	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}
	Self& operator++()
	{
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else
		{
			KeyOfValue kov;
			HashFun hf;
			int table_size = _hb->_table.size();
			int index = hf(kov(_node->_data)) % table_size;
			++index;
			for (; index < table_size; ++index)
			{
				if (_hb->_table[index] != nullptr)
				{
					_node = _hb->_table[index];
					break;
				}
			}
			if (index == table_size)
			{
				_node = nullptr;
			}
		}
		return *this;
	}
};

//哈希桶
template<class K, class V, class KeyOfValue, class HashFun>
class HashBucket
{
public:
	friend HashIterator<K, V, KeyOfValue,HashFun>;
	typedef HashNode<V> Node;
	typedef Node* pNode;
	typedef typename HashIterator<K, V, KeyOfValue,HashFun> iterator;
private:
	vector<pNode> _table;
	size_t _size;
public:
	iterator begin()
	{
		for (size_t i = 0; i < _table.size(); ++i)
		{
			if (_table[i])
			{
				return iterator(_table[i], this);
			}
		}
		return iterator(nullptr, this);
	}
	iterator end()
	{
		return iterator(nullptr, this);
	}
	HashBucket()
		:_size(0)
	{
		_table.resize(5, nullptr);
	}
	pair<iterator,bool> Insert(const V& data)
	{
		//检查容量
		ChekckCapacity();
		//先确定数组下标
		KeyOfValue kov;
		HashFun hf;
		int index = hf(kov(data)) % _table.size();
		//插入
		pNode cur = _table[index];
		//判断是否已经有这个元素，直到cur为空
		while (cur)
		{
			if (hf(kov(cur->_data)) == hf(kov(data)))
			{
				return make_pair(iterator(cur, this), false);
			}
			cur = cur->_next;
		}
		//创建新节点
		cur = new Node(data);
		//让新节点指向这个链表的头，头插
		cur->_next = _table[index];
		//更新数组的元素
		_table[index] = cur;
		++_size;
		return make_pair(iterator(cur, this), true);
	}
	void ChekckCapacity()
	{
		//负载因子可以是1
		if (_size / _table.size() < 1)
		{
			return;
		}
		KeyOfValue kov;
		HashFun hf;
		vector<pNode> new_table(_size * 2);
		for (int i = 0; i < _table.size(); ++i)
		{
			pNode cur = _table[i];
			while (cur)
			{
				//先保存后一个节点
				pNode next = cur->_next;
				//确定这个数据在新表的位置
				int index = hf(kov(cur->_data)) % new_table.size();
				//头插
				cur->_next = new_table[index];
				//更新数组元素
				new_table[index] = cur;
				//继续遍历
				cur = next;
			}
			_table[i] = nullptr;
		}
		_table.swap(new_table);
	}
};

template<class K>
struct HashFunction
{
	int operator()(const K& key)
	{
		return key;
	}
};

template<>
struct HashFunction<string>
{
	int operator()(const string& key)
	{
		int hash = 0;
		for (const auto& ch : key)
		{
			hash = hash * 31 + ch;
		}
		return hash;
	}
};

//模拟unordered_map
template<class K, class V, class HashFun = HashFunction<K>>
class MyUnorderedMap
{
	struct MapKeyOfValue
	{
		const K& operator()(const pair<K, V>& data)
		{
			return data.first;
		}
	};

private:
	HashBucket<K, pair<K, V>, MapKeyOfValue, HashFun> _hb;
public:
	typedef typename HashBucket<K, pair<K, V>, MapKeyOfValue, HashFun>::iterator iterator;
	pair<iterator, bool> Insert(const pair<K, V>& data)
	{
		return _hb.Insert(data);
	}
	iterator begin()
	{
		return _hb.begin();
	}
	iterator end()
	{
		return _hb.end();
	}
	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = _hb.Insert(make_pair(key, V()));
		return ret.first->second;
	}

};

//模拟unordered_set
template<class K,class HashFun = HashFunction<K>>
class MyUnorderedSet
{
	struct SetKeyOfValue
	{
		const K& operator()(const K& data)
		{
			return data;
		}
	};
private:
	HashBucket<K, K, SetKeyOfValue, HashFunction<K>> _hb;
public:
	typedef typename HashBucket<K, K, SetKeyOfValue, HashFunction<K>>::iterator iterator;
	pair<iterator,bool> Insert(const K& data)
	{
		return _hb.Insert(data);
	}
};

void test_mymap()
{
	MyUnorderedMap<int, string> mmp;
	mmp.Insert(make_pair(1, "one"));
	mmp.Insert(make_pair(11, "two"));
	mmp.Insert(make_pair(256, "asd"));
	mmp.Insert(make_pair(12, "oasde"));
	mmp.Insert(make_pair(6, "onasd"));
	mmp.Insert(make_pair(3, "oasde"));
	mmp[3] = "xxxxxxxxxxxxxxx";
	MyUnorderedMap<int, string>::iterator it = mmp.begin();
	while(it != mmp.end())
	{
		cout << it->first << "-->" << it->second << endl;
		++it;
	}
}

//int main()
//{
//	test_mymap();
//	system("pause");
//	return 0;
//}