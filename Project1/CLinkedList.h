#pragma once

#include <iostream>
#include <assert.h> // 예외처리 헤더
//가변적 (STL) Template을 이용한 다양한 인터페이스를 제공.
// STL을 흉내내서 비슷한 기능을 제공할 수 있도록 할 것.
template <typename T>
class Node
{
	template <typename T>
	friend class CLinkedList;

private:
	Node() {
		std::cout << " Node 생성 됨";
		m_pNext = nullptr;
		m_pPrev = nullptr;
	}
public: //차후 private
	T m_Data; // 데이터 저장
	Node<T>* m_pNext; //다음 노드의 주소를 저장할 변수
	Node<T>* m_pPrev; // 이전 노드의 주소를 저장할 변수

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
	//begin과 end라는 범위 노드를 만들고 리스트의 시작과 끝을 나타냄.
	PNODE	m_pBegin;
	PNODE	m_pEnd;
	int		m_iSize;

public :
	void push_Back(const T& data) {
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		//뒤에 추가해야하므로 End의 이전 노드를 얻어온다.
		PNODE pPrev = m_pEnd->m_pPrev;

		//얻어온 이전 노드와 End노드 사이에 새로 생성한 노드를 추가한다.
		pPrev->m_pNext = pNode;
		pNode->m_pPrev = pPrev;

		//End노드와 새로 생성한 노드를 연결한다.
		pNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pNode;

		++m_iSize;
	}

	void push_Front(const T& data)
	{
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		//앞에 추가해야하므로 Begin 노드를 얻어온다
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

	//뒤에것을 지워주는 기능.
	void pop_back() {

		if (empty()) assert(false); // 에러메세지를 발생 시켜줌.
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
	//Begin과 End를 제외한 실제 추가한 노드의 삭제기능을 만들어준다.
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

	//리스트가 비어있을 경우 true, 아닐 경우 false 반환한다.
	bool empty() const
	{
		return m_iSize == 0;
	}
};

