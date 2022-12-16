#include<iostream>
using namespace std;

//定义一个单链表类
template<class T>class InkList :public List <T>
{
private:
	Link<T>* head, * tail;                            //定义单链表的头尾指针
	Link<T>* setPos(const int p);                     //表示第p个元素指针
public:
	InkList(int s);                                   //构造函数
	~InkList();                                       //析构函数
	bool isEmpty();                                   //判断链表是否为空的函数声明
	void clear();                                     //清空链表函数声明
	int length();                                     //返回链表当前实际长度  函数声明
	bool append(const T value);                       //增添函数---表尾增添一个函数value，表长加一
	bool insert(const int p, const T value);          //插入函数---在位置p插入一个元素 
	bool delete(const int p);                         //删除函数---删除位置p处的元素，并且表的长度减一
	bool getValue(const int p, T& value);             //返回位置p的元素值
	bool getPos(int& p, const T value);               //查找函数---查找值为value的元素
};

//
//查找功能实现
//template<class T>                                  //定义线性表的元素类型为T
//bool InkList<T>::setPos(int i)
//{
//	int count = 0;
//	if (i == -1)
//		return head;
//	Link<T> * p = head->next;
//	while (p != NULL && count < i)
//	{
//		p = p->next;
//		count++;
//	};
//	return p;
//}


//插入算法实现
template<class T>                                            //1.插入的新结点作为原来的第i个结点      线性表的元素类型为T
bool InkList<T>::insert(const int i, const T value)          
{
	Link<T>* p, * q;
	if ((p = setPos(i - 1)) == NULL)                         //p是第i个结点的前驱
	{
		cout << "非法插入点" << endl;
		return false;
	}
	q = new Link<T>(value, p->next);
	p->next = q;
	if (p == tail)                                           //2.如果插入点在链尾，则新插入的点成为链尾  
		tail = q;
	return true;
}