#pragma once

#include <iostream>
#include <assert.h> // ����ó�� ���
//������ (STL) Template�� �̿��� �پ��� �������̽��� ����.
// STL�� �䳻���� ����� ����� ������ �� �ֵ��� �� ��.
template <typename T>
class Node
{
	template <typename T>
	friend class CLinkedList;

private:
	Node() {
		std::cout << " Node ���� ��";
		m_pNext = nullptr;
		m_pPrev = nullptr;
	}
public: //���� private
	T m_Data; // ������ ����
	Node<T>* m_pNext; //���� ����� �ּҸ� ������ ����
	Node<T>* m_pPrev; // ���� ����� �ּҸ� ������ ����

};

template <typename T>
class CLinkedList
{
public : 
	CLinkedList() {
		m_pBegin = new NODE;
		m_pEnd = new NODE;

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;

		m_iSize = 0;
	}
	~CLinkedList() {
		Clear();
		delete m_pBegin;
		delete m_pEnd;
	}
private:
	typedef Node<T>		NODE;
	typedef Node<T>*	PNODE;

private:
	//begin�� end��� ���� ��带 ����� ����Ʈ�� ���۰� ���� ��Ÿ��.
	PNODE	m_pBegin;
	PNODE	m_pEnd;
	int		m_iSize;

public :
	void push_Back(const T& data) {
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		//�ڿ� �߰��ؾ��ϹǷ� End�� ���� ��带 ���´�.
		PNODE pPrev = m_pEnd->m_pPrev;

		//���� ���� ���� End��� ���̿� ���� ������ ��带 �߰��Ѵ�.
		pPrev->m_pNext = pNode;
		pNode->m_pPrev = pPrev;

		//End���� ���� ������ ��带 �����Ѵ�.
		pNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pNode;

		++m_iSize;
	}

	void push_Front(const T& data)
	{
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		//�տ� �߰��ؾ��ϹǷ� Begin ��带 ���´�
		PNODE pNext = m_pBegin->m_pNext;
		
		pNode->m_pNext = pNext;
		pNext->m_pPrev = pNode;

		m_pBegin->m_pNext = pNode;
		pNode->m_pPrev = m_pBegin;

		++m_iSize;

	}

	T front() const
	{
		if (empty())
			assert(false);

		return m_pBegin->m_pNext->m_Data;
	}
	T Back() const {
		if (empty()) assert(false);
		return m_pEnd->m_pPrev->m_Data;
	}

	//�ڿ����� �����ִ� ���.
	void pop_back() {

		if (empty()) assert(false); // �����޼����� �߻� ������.
		PNODE pNode = m_pEnd->m_pPrev;
			PNODE pPrev = pNode->m_pPrev;
			m_pEnd->m_pPrev = pPrev;
			pPrev->m_pNext = m_pEnd;
			--m_iSize;
			delete pNode;
		
	}
	void pop_front() {
		if (empty()) assert(false);
		PNODE pNode = m_pBegin->m_pNext;
		PNODE pNext = pNode->m_pNext;
		
		m_pBegin->m_pNext = pNext;
		pNext->m_pPrev = m_pBegin;

		--m_iSize;
		delete pNode;
	}
	//Begin�� End�� ������ ���� �߰��� ����� ��������� ������ش�.
	void Clear() {
		PNODE ptrNode = m_pBegin->m_pNext;
		while (ptrNode != m_pEnd)
		{
			PNODE pNext = ptrNode->m_pNext;

			delete ptrNode;

			ptrNode = pNext;
		}
		m_iSize = 0;

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;
	}
	int size() const
	{
		return m_iSize;
	}

	//����Ʈ�� ������� ��� true, �ƴ� ��� false ��ȯ�Ѵ�.
	bool empty() const
	{
		return m_iSize == 0;
	}
};

