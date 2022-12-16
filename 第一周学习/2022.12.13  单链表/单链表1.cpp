#include<iostream>
using namespace std;

//����һ����������
template<class T>class InkList :public List <T>
{
private:
	Link<T>* head, * tail;                            //���嵥�����ͷβָ��
	Link<T>* setPos(const int p);                     //��ʾ��p��Ԫ��ָ��
public:
	InkList(int s);                                   //���캯��
	~InkList();                                       //��������
	bool isEmpty();                                   //�ж������Ƿ�Ϊ�յĺ�������
	void clear();                                     //�������������
	int length();                                     //��������ǰʵ�ʳ���  ��������
	bool append(const T value);                       //������---��β����һ������value������һ
	bool insert(const int p, const T value);          //���뺯��---��λ��p����һ��Ԫ�� 
	bool delete(const int p);                         //ɾ������---ɾ��λ��p����Ԫ�أ����ұ�ĳ��ȼ�һ
	bool getValue(const int p, T& value);             //����λ��p��Ԫ��ֵ
	bool getPos(int& p, const T value);               //���Һ���---����ֵΪvalue��Ԫ��
};

//
//���ҹ���ʵ��
//template<class T>                                  //�������Ա��Ԫ������ΪT
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


//�����㷨ʵ��
template<class T>                                            //1.������½����Ϊԭ���ĵ�i�����      ���Ա��Ԫ������ΪT
bool InkList<T>::insert(const int i, const T value)          
{
	Link<T>* p, * q;
	if ((p = setPos(i - 1)) == NULL)                         //p�ǵ�i������ǰ��
	{
		cout << "�Ƿ������" << endl;
		return false;
	}
	q = new Link<T>(value, p->next);
	p->next = q;
	if (p == tail)                                           //2.������������β�����²���ĵ��Ϊ��β  
		tail = q;
	return true;
}