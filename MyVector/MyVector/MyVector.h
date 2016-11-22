#ifndef __MYVECTOR_H
#define __MYVECTOR_H

const int default_capacity = 10;

template <typename T> 
class MyVector
{
public:
	MyVector(int c = default_capacity)//Ĭ�Ϲ��캯��
	{
		_elem = new T[_capacity = c];
		_size = 0;
	}
	MyVector(T const *A, int lo, int hi)//�������临��
	{
		CopyFrom(A,lo,hi);
	}
	MyVector(MyVector<T> const &V, int lo, int hi)//�������临��
	{
		CopyFrom(V._elem, lo, hi);
	}
	MyVector(MyVector<T> const &V)//�������帴��
	{
		CopyFrom(V._elem, 0, V._size);
	}
	~MyVector();
	T & operator[](int i)
	{
		if (i < _size && i >= 0)
		{
			return _elem[i];
		}
	}

	int Insert(int r, T const &e);
	int Remove(int lo, int hi);//����ɾ��
	int Remove(int r);//ɾ����Ԫ��
	void Traverse(void (*visit)(T&));//����
	template <typename VST> void Traverse(VST &visit);
	int Find(T e,int lo, int hi);//����eԪ�ص�λ��
	int Deduplicate();//��������ȥ�ز���

	//����

	int Disorder();//�������
	int Search(T e, int lo, int hi);
	int Unique();//��������ȥ�ز���

	void binSearch(T e, int lo, int hi);

protected:
	void CopyFrom(T const *A, int lo, int hi);//���������캯����ʹ��
	void Expend();//����
private:
	T* _elem;
	int _size;//ʵ�ʴ�С
	int _capacity;//����
};


template <typename T>
void MyVector<T>::CopyFrom(T const *A, int lo, int hi)
{
	_elem = new T[_capacity = 2*(hi - ho)];
	_size = 0;
	while(lo < hi)
	{
		_elem[_size++] = A[lo++];
	}
}

template <typename T>
MyVector<T>::~MyVector()
{
	if (_elem != NULL)
	{
		delete []_elem;
	}
}

template <typename T>
void MyVector<T>::Expend()
{
	if (_size < _capacity)
		return;
	_capacity = max(_capacity, default_capacity);
	T* oldElem = _elem;
	_elem = new T[_capacity << 1];
	for (int i=0; i < _size; i++)
	{
		_elem[i] = oldElem[i];
	}
	delete []oldElem;
}

template <typename T>
int MyVector<T>::Insert(int r, T const &e)
{
	if (_capacity <= _size)
	{
		Expend();
	}
	for (int i = _size; i > r; i-- )
	{
		_elem[i + 1] = _elem[i];
	}
	_elem[r] = e;
	_size++;
	return r;
}

template <typename T>
int MyVector<T>::Remove(int lo, int hi)
{
	assert(0 <= lo && hi < _size);
	if (hi == lo)
	{
		return 0;
	}
	while (hi < _size)
	{
		_elem[lo++] = _elem[hi++];
	}
	_size = lo;
	return hi - lo;
}

template <typename T>
int MyVector<T>::Find(T e,int lo, int hi)
{
	assert(0 <= lo && hi < _size);
	while ((lo <= hi--) && (e != _elem[hi]));
	return hi;
}

template <typename T>
int MyVector<T>::Remove(int r)
{
	assert(0 <= r && r < _size);
	T e = _elem[r];
	Remove(r,r+1);
	return e;
}

template <typename T>
int MyVector<T>::Deduplicate()
{
	int i = 1;
	int oldSize = _size;
	while (i++ < _size)
	{
		int rt = find(_elem[i], i+1, _size);
		if (rt < 0)
		{
			i++;
		}
		else
		{
			Remove(rt);
		}
	}
	return oldSize - _size;
}

template <typename T>
void MyVector<T>::Traverse(void (*visit)(T&))
{
	for (int i = 0; i < _size; i++)
	{
		visit(_elem[i]);
	}
}


template <typename T> template <typename VST>
void MyVector<T>::Traverse(VST &visit)
{
	for (int i = 0; i < _size; i++)
	{
		visit(_elem[i]);
	}
}


template <typename T>
int MyVector<T>::Disorder()
{
	int rt = 0;
	for (int i = _size; i > 0; i--)
	{
		if (_elem[i] < _elem[i-1])
		{
			rt++;
		}
	}
	return rt;
}


template <typename T>
int MyVector<T>::Unique()
{
	int i = j = 0;
	while (++j < _size)
	{
		if (_elem[i] != _elem[j])
		{
			_elem[++i] = _elem[j];
		}
	}
	_size = ++i;
	return j - i;
}

#endif