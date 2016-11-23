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
	T & operator[](int i)
	{
		if (i < _size && i >= 0)
		{
			return _elem[i];
		}
	}

	int Insert(int r, T const &e);
	int Remove(int lo, int hi);//区间删除
	int Remove(int r);//删除单元素
	void Traverse(void (*visit)(T&));//遍历
	template <typename VST> void Traverse(VST &visit);
	int Find(T e,int lo, int hi);//查找e元素的位置
	int Deduplicate();//无序向量去重操作

	//有序

	int Disorder();//无序对数
	int Search(T e, int lo, int hi);
	int Unique();//有序向量去重操作

	int binSearch(T *a, T e, int lo, int hi);
	void fibSearch(T *a, T e, int lo, int hi);


	void BubbleSort(T *a, int lo, int hi);
	void MergeSort(T *a, int lo, int hi);

protected:
	void CopyFrom(T const *A, int lo, int hi);//拷贝，构造函数中使用
	int bubble(T *a, int lo, int hi);
	void Merge(T *a, int lo, int mi, int hi);
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


template <typename T>
int MyVector<T>::binSearch(T *a, T e, int lo, int hi)
{
	while (lo < hi)
	{
		int mi = (lo + hi) >> 1;
		(e < a[mi]) ? hi = mi : lo = mi + 1;
	}
	return --lo;
}


class Fib
{
	Fib get();
};


//////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
template <typename T>
void MyVector<T>::fibSearch(T *a, T e, int lo, int hi)
{
	Fib fib(hi - lo);
	
}
//////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

template <typename T>
void MyVector<T>::BubbleSort(T *a, int lo, int hi)
{
	while(lo < (hi = bubble(a, lo, hi)));
}

template <typename T>
int MyVector<T>::bubble(T *a, int lo, int hi)
{
	////最普通的一种
	//while(++lo < hi)
	//{
	//	if (a[lo - 1] < a[lo])
	//	{
	//		swap(a[lo - 1], a[lo]);
	//	}
	//}
	////第二版
	//bool flag = true;
	//while (++lo < hi)
	//{
	//	if (a[lo - 1] < a[lo])
	//	{
	//		flag = false;
	//		swap(a[lo - 1], a[lo]);
	//	}
	//}
	//return false;
	//第三版
	int last = lo;
	while(++lo < hi)
	{
		if (a[lo - 1] < a[lo])
		{
			last = lo;
			swap(a[lo - 1], a[lo]);
		}
	}
	return lo;
}



template <typename T>
void MyVector<T>::MergeSort(T *a, int lo, int hi)//a 也可以理解为_elem数组
{
	if (hi - lo < 2)
	{
		return;
	}
	int mi = (hi - lo) >> 1;
	MergeSort(a, lo, mi);
	MergeSort(a, mi, hi);
	Merge(a, lo, mi, hi);

}

template <typename T>
void MyVector<T>::Merge(T *a, int lo, int mi, int hi)
{
	int lb = mi - lo;
	T *B = new T[lb];
	for(int i = 0; i < lb; B[i++] = a[lo++]);
	int lc = hi - mi;
	T *C = a + mi;
	for (int i = j = k = 0; (j < lb) || (k < lc))
	{
		if ((j < lb)&&(lc <= k || B[j] <= C[k]))
		{
			a[i++] = B[++];
		}
		if ((k < lc)&&(lb <= j || C[k] < B[j]))
		{
			a[i++] = C[k++];
		}
	}
	delete []B;
}


#endif