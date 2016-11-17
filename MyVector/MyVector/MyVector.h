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
	void Insert(T t);
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

#endif