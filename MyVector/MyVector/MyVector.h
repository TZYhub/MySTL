#ifndef __MYVECTOR_H
#define __MYVECTOR_H

const int default_capacity = 10;

template <typename T> 
class MyVector
{
public:
	MyVector(int c = default_capacity)//默认构造函数
	{
		_elem = new T[_capacity = c];
		_size = 0;
	}
	MyVector(T const *A, int lo, int hi)//数组区间复制
	{
		CopyFrom(A,lo,hi);
	}
	MyVector(MyVector<T> const &V, int lo, int hi)//向量区间复制
	{
		CopyFrom(V._elem, lo, hi);
	}
	MyVector(MyVector<T> const &V)//向量整体复制
	{
		CopyFrom(V._elem, 0, V._size);
	}
	~MyVector();
	void Insert(T t);
protected:
	void CopyFrom(T const *A, int lo, int hi);//拷贝，构造函数中使用
	void Expend();//扩容
private:
	T* _elem;
	int _size;//实际大小
	int _capacity;//容量
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

#endif