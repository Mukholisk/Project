#pragma once

/**
*	Structure for NodeType to use in Linked structure.
*/
template <typename T>
struct NodeType
{
	T data;		///< A data for each node.
	NodeType* next;		///< A node pointer to point succeed node.
};

/**
*	Simple sorted list class for managing items.
*/
template<typename T>
class SortedLinkedList
{
public:
	/**
	*	default constructor.
	*/
	SortedLinkedList();

	/**
	*	destructor.
	*/
	~SortedLinkedList();

	/**
	*	default constructor.
	*/
	SortedLinkedList(const SortedLinkedList<T>& anotherList);

	/**
	*	@brief	Initialize list to empty state.
	*	@pre	None
	*	@post	List is empty.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get number of elements in the list.
	*	@pre	None.
	*	@post	Function value = number of elements in list.
	*	@return	Number of elements in this list.
	*/
	int GetLength();

	/**
	*	@brief	Add item into this list.
	*	@pre	List is not full. item is not in list.
	*	@post	Item is inserted in this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Add(T& data);

	/**
	*	@brief	item과 일치하는 num를 가진 레코드를 제거.
	*	@pre	해당하는 num를 가진 레코드가 있어야함
	*	@post	해당 레코드가 제거됨.
	*/
	int Delete(T& data);

	/**
	*	@brief	item과 일치하는 num를 가진 레코드를 갱신.
	*	@pre	해당하는 num를 가진 레코드가 있어야함
	*	@post	해당 레코드가 item의 내용으로 갱신됨.
	*/
	int Replace(T& data);

	/**
	*	@brief	Retrieve list element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	*	@return	1 if any element's primary key matches with item's, otherwise 0.
	*/
	int Get(T& item);

	/**
	*	@brief	Initialize current pointer for an iteration through the list.
	*	@pre	None.
	*	@post	current pointer is prior to list. current pointer has been initialized.
	*/
	void ResetList();

	/**
	*	@brief	Get the next element in list.
	*	@pre	current pointer is defined. Element at current pointer is not last in list.
	*	@post	current pointer is updated to next position. item is a copy of element at current pointer.
	*/
	void GetNextItem(T& data);

	/**
	*	@brief	리스트가 비어있는지를 확인한다.
	*	@pre	x
	*	@post	x
	*	@return 비었으면 1, 아니면 0
	*/
	bool IsEmpty()
	{
		if (m_nLength == 0)
			return true;
		else
			return false;
	}

	/**
	*	@brief	CurPointer을 다음으로 옮긴다.
	*	@pre	m_pCurPointer가 정의되어 있어야 함.
	*	@post	x
	*/
	void GotoNextItem()
	{
		m_pCurPointer = m_pCurPointer->next;
	}

	/**
	*	@brief	현재 포인터가 가르키는 데이터를 가져옴
	*	@pre	리스트가 초기화 되어 있어야 함.
	*	@post	해당하는 데이터를 가져옴
	*/
	void GetCurItem(T& data);

	/**
	*	@brief  포인터가 리스트의 끝에 있는지 판별
	*	@pre	none.
	*	@post	none.
	*	@return	끝이면 true, 아니면 false
	*/
	bool isLastPointer()
	{
		if (m_pCurPointer == NULL)   // m_p_CurPointer가 NULL일땐 리스트의 끝이다
			return true;
		else
			return false;
	}

	/**
	*	@brief	리스트의 head에 해당하는 데이터를 가져옴
	*	@pre	리스트가 초기화 되어 있어야 함.
	*	@post	head에 해당하는 데이터를 가져옴
	*/
	int GetFirstItem(T& item);

	/**
	*	@brief	m_pCurPointer가 가리키는 item의 주소를 받아온다.
	*	@pre	m_pCurPotiner가 정의되어 있어야한다.
	*	@post	none.
	*	@return m_pCurPointer가 가리키는 item의 주소값
	*/
	T* GetCurItemAddress()
	{
		// m_pCurPointer가 NULL이라면 처음 node를 가리킴.
		if (m_pCurPointer == NULL)
			m_pCurPointer = m_pList;

		return &(m_pCurPointer->data);
	}
	
	/**
	*	@brief	데이터를 복사함.
	*	@pre	two item types should be initialized.
	*	@param	anotherList	저장할 데이터
	*	@return	return 1 if saved, 0 if not.
	*/
	SortedLinkedList<T> operator=(const SortedLinkedList<T> &anotherList);

private:
	NodeType<T> *m_pList;	///< Pointer for pointing a first node.
	NodeType<T> *m_pCurPointer;	///< Node pointer for pointing current node to use iteration.
	int m_nLength; ///< Number of node in the list.
};

// Class constructor
template<typename T>
SortedLinkedList<T>::SortedLinkedList()
{
	m_nLength = 0;
	m_pList = NULL;
	m_pCurPointer = NULL;
}

// Class destructor
template<typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
	//리스트내의 모든 node 제거
	MakeEmpty();
}

// Initialize list to empty state.
template<typename T>
void SortedLinkedList<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
	NodeType<T> *tempPtr;
	while (m_pList != NULL)
	{
		tempPtr = m_pList;
		m_pList = m_pList->next;
		delete tempPtr;
	}

	m_nLength = 0;
}

// Get number of elements in the list.
template <typename T>
int SortedLinkedList<T>::GetLength()
{
	return m_nLength;
}

// Add item into this list.
template<typename T>
int SortedLinkedList<T>::Add(T &data)
{
	// 리스트 초기화
	ResetList();

	// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;

	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = data;
	node->next = NULL;

	// list 에 node 가 존재하지 않는 경우
	if (!m_nLength)
	{
		m_pList = node;
		bFound = true;
	}

	// list 에 node 가 하나 이상 존재하는 경우
	else
	{
		// 가장 마지막 node 로 이동 후 삽입
		while (1)
		{
			// 이전 노드를 가리키는 포인터 갱신
			pre = m_pCurPointer;

			// iteration 을 이용해 node 포인터 갱신.
			GetNextItem(dummy);
			if (m_pCurPointer->data == node->data)
				break;

			if (m_pCurPointer->data > node->data)
			{
				if (pre == NULL)
				{
					node->next = m_pCurPointer;
					m_pList = node;
					bFound = true;
					break;
				}	//넣을 자리 앞 원소가 존재하지 않을 때 첫번째 원소로 삽입.
				else
				{
					node->next = m_pCurPointer;
					pre->next = node;
					bFound = true;
					break;
				}//지금 가리키는 원소의 data값이 node의 data값보다 클 경우 pre 뒷자리에 삽입.
			}	

			// node 포인터가 마지막 node 를 가리키면 그 뒤에 새로운 node 삽입.
			if (m_pCurPointer->next == NULL)
			{
				// 마지막 node 와 새로운 node 연결
				m_pCurPointer->next = node;
				bFound = true;
				break;
			}
		}
	}

	if (bFound == true)
	{
		m_nLength++;
		return 1;
	}
	else
		return 0;
}

//Delete item from this list.
template<typename T>
int SortedLinkedList<T>::Delete(T& data)
{
	NodeType<T> *pre;
	NodeType<T> *toDel;
	ResetList();
	T tmp;
	bool found = false;

	if (Get(data) == 0)	//해당하는 값이 없으면, 0보내고 종료
		return 0;

	while (1)
	{
		pre = m_pCurPointer;
		GetNextItem(tmp);
		if (tmp == data)		//id값이 일치
		{
			if (pre == NULL) //삭제해야할 노드가 맨처음일때
			{
				toDel = m_pList;	//잠시 옮겨두고 삭제
				m_pList = m_pList->next;	//맨처음을 두번째로바꿈
				delete toDel;
				found = true;
				break;
			}
			else
			{
				toDel = m_pCurPointer;
				pre->next = m_pCurPointer->next;	//전 포인터와 다음포인터를 연결
				delete toDel;
				found = true;
				break;
			}
		}
		if (m_pCurPointer->next == NULL)	//맨마지막, 루프를 다돌았을때
			break;
	}
	m_nLength--;

	if (found)
		return 1;
	else
	{
		cout << "삭제할 수 없습니다." << endl << endl;
		return 0;
	}
}

//Change value of item which is in this list.
template<typename T>
int SortedLinkedList<T>::Replace(T& data)
{
	bool MoreToSearch, found;
	NodeType<T> *location; //변수 선언

	location = m_pList;
	found = false;
	MoreToSearch = (location != NULL); //변수 초기화

	while (MoreToSearch && !found) //리스트의 끝이 아니면서 아직 몾찾을경우 반복한다
	{
		if (data == location->data)
		{
			found = true;
			location->data = data;
		}	//일치하는 항목을 찾았을 때 found의 값을 변경해주고 리스트의 항목에 item을 복사해준다.
		else
		{
			location = location->next;
			MoreToSearch = (location != NULL);
		}	//찾지 못했을 때 다음 항목으로 location을 옮기고 그 값이 NULL이면 리스트의 끝이므로 moreToSearch의 값을 변경해준다.

	}

	if (found)
		return 1;
	else
		return 0;
}

// Retrieve list element whose key matches item's key (if present).
template<typename T>
int SortedLinkedList<T>::Get(T& data)
{
	bool MoreToSearch, found;
	NodeType<T>* location;		//변수 선언

	location = m_pList;
	found = false;
	MoreToSearch = (location != NULL); 	//변수 초기화

	while (MoreToSearch && !found)	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (data == location->data)
		{
			found = true;
			data = location->data;
		} //일치하는 항목을 찾았을 때 found의 값을 변경해주고 item에 해당 항목을 복사해준다.
		else
		{
			location = location->next;
			MoreToSearch = (location != NULL);
		} //찾지 못했을 때 다음 항목으로 location을 옮기고 그 값이 NULL이면 리스트의 끝이므로 moreToSearch의 값을 변경해준다.
	}

	if (found)
		return 1;
	else
		return 0;
}

// Initializes current pointer for an iteration through the list.
template<typename T>
void SortedLinkedList<T>::ResetList()
{
	m_pCurPointer = NULL;

}

template<typename T>
void SortedLinkedList<T>::GetNextItem(T& data)
{
	if (m_pCurPointer == NULL)	//NULL이면
		m_pCurPointer = m_pList; //처음을 가리킨다
	else
		m_pCurPointer = m_pCurPointer->next;

	data = m_pCurPointer->data;

}


template<typename T>
void SortedLinkedList<T>::GetCurItem(T& item)
{
	// m_pCurPointer가 NULL이라면 처음 node를 가리킴.
	if (m_pCurPointer == NULL)
		m_pCurPointer = m_pList;

	item = m_pCurPointer->data;

}


template<typename T>
int SortedLinkedList<T>::GetFirstItem(T& item)
{
	if (m_nLength == 0)
		return	0;
	else
	{
		item = m_pList->data;
		m_pCurPointer = m_pList->next;
		return 1;
	}
}

// Copy constructor
template<typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T>& aList)
{
	m_pList = NULL;
	m_pCurPointer = NULL;
	if (aList.m_pList == NULL)
		return;
	else
	{
		this->m_nLength = aList.m_nLength;

		NodeType<T> *Node1 = new NodeType<T>;
		NodeType<T> *Node2;
		m_pList = Node1;
		Node1->data = aList.m_pList->data;
		Node2 = aList.m_pList->next;

		while (Node2 != NULL)
		{
			Node1->next = new NodeType<T>;
			Node1 = Node1->next;
			Node1->data = Node2->data;
			Node2 = Node2->next;
		}
		Node1->next = NULL;
	}
}

// copy
template<typename T>
SortedLinkedList<T> SortedLinkedList<T>::operator=(const SortedLinkedList<T> &aList)
{
	MakeEmpty();
	SortedLinkedList<T> temp(aList);

	m_pList = NULL;
	m_pCurPointer = NULL;

	if (aList.m_pList == NULL)
		return *this;
	else
	{
		this->m_nLength = aList.m_nLength;

		NodeType<T> *Node1 = new NodeType<T>;
		NodeType<T> *Node2;
		m_pList = Node1;
		Node1->data = aList.m_pList->data;
		Node2 = aList.m_pList->next;

		while (Node2 != NULL)
		{
			Node1->next = new NodeType<T>;
			Node1 = Node1->next;
			Node1->data = Node2->data;
			Node2 = Node2->next;
		}
		Node1->next = NULL;
	}
	return temp;
}