#ifndef _SORTEDARRAYLIST_H
#define _SORTEDARRAYLIST_H


#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#define pMAXSIZE 10

// 재생횟수 용

/**
*	array based simple unsorted list.
*/
template <class T>
class SortedArrayList
{
public:
	/**
	*	default constructor.
	*/
	SortedArrayList()
	{
		m_Length = 0;
		m_CurPointer = -1;
	}

	/**
	*	destructor.
	*/
	~SortedArrayList() {}

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();

	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
	bool IsFull();

	/**
	*	@brief	add a new data into list.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(T data);

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(T& data);

	/**
	*	@brief	item을 찾아서 해당 item을 반환한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에서 찾은 item이 data에 입력된다.
	*	@param	data	찾고자 하는 id가 입력된 ItemType값. 발견한 item이 리턴된다.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int Get(T& data);

	/**
	*	@brief	id가 일치하는 item을 찾아서 해당 item을 제거한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에 해당 item이 제거된다.
	*	@param	data	제거하고자 하는 id가 입력된 ItemType값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Delete(T data);

	/**
	*	@brief	id가 일치하는 list내 item을 찾아서 변경한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	배열 내에 넘겨받은 item과 id가 일치하는 값이 넘겨받은 item의 내용으로 변경된다.
	*	@param	data	교체하고자 하는 id와 레코드를 가진 ItemType값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Replace(T data);

	/**
	*	@brief	이진탐색을 통해 id가 일치하는 list내 item을 찾아서 반환한다.
	*	@pre	없음.
	*	@post	배열 내에 넘겨받은 item과 id가 일치하는 값을 찾아서 data로 반환된다.
	*	@param	data	찾고자 하는 id가 입력된 ItemType값.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int GetBinarySearch(T& data);

	/**
	*	@brief	m_CurPointer가 가리키는 item의 주소를 받아온다.
	*	@pre	m_CurPotiner가 정의되어 있어야한다.
	*	@post	none.
	*	@return m_CurPointer가 가리키는 item의 주소값
	*/
	T* GetCurItemAddress()
	{
		if (m_CurPointer == -1)
			return 0;

		return &(m_Array[m_CurPointer]);
	}

	/**
	*	@brief	목록 비우기
	*	@pre	목록이 비어있지 않아야 함.
	*	@post	목록이 비워짐
	*/
	void Reset()
	{
		delete[] m_Array;
		m_Length = 0;
		m_CurPointer = -1;
	}

private:
	T m_Array[pMAXSIZE];  ///< list array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
};

// Make list empty.
template <class T>
void SortedArrayList<T>::MakeEmpty()
{
	m_Length = 0;
}


// Get a number of records in current list.
template <class T>
int SortedArrayList<T>::GetLength()
{
	return m_Length;
}


// Check capacity of list is full.
template <class T>
bool SortedArrayList<T>::IsFull()
{
	if (m_Length > pMAXSIZE - 1)
		return true;
	else
		return false;
}


// add a new data into list.
template <class T>
int SortedArrayList<T>::Add(T inData)
{
	if (!IsFull())
	{
		T CurItem;
		CurItem = inData;

		ResetList();
		GetNextItem(CurItem);

		while (m_CurPointer <= m_Length) //처음부터 끝까지
		{
			if (CurItem.CompareByPlay(inData) == GREATER || m_CurPointer == m_Length)	//만약 CurItem>inData일경우 혹은 배열의 마지막이라서 비교대상이 없는경우
			{
				for (int i = m_CurPointer; i < pMAXSIZE; i++)	//앞에서 부터 하나씩 땡긴다.
					m_Array[i] = m_Array[i + 1];	//배열 밀기
				m_Array[m_CurPointer] = inData;	//배열 밀은 후 현재 포인터에 아이템 넣는다.
				m_Length++;	//개수 증가
				break;
			}
			GetNextItem(CurItem);	//다음아이템으로
		}
	}
	else
		return 0;

	return 1;
}


// Initialize list iterator.
template <class T>
void SortedArrayList<T>::ResetList()
{
	m_CurPointer = -1;
}

// move list iterator to the next item in list and get that item.
template <class T>
int SortedArrayList<T>::GetNextItem(T& data)
{
	m_CurPointer++;	// list pointer 증가
	if (m_CurPointer == pMAXSIZE)	// end of list이면 -1을 리턴
		return -1;

	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}

//id가 일치하는 item을 찾아서 반환함
template <class T>
int SortedArrayList<T>::Get(T& data)
{
	MusicType CurItem;

	ResetList();	//iterator 초기화
	GetNextItem(CurItem);	//첫아이템 가져옴
	while (m_CurPointer < m_Length)	//처음부터 끝까지
	{
		switch (CurItem.CompareByPri(data))	//입력 아이템과 현재 아이템을 비교
		{
		case EQUAL:	//일치하면
			data = CurItem;	//data에 현재 아이템을 반환
			return 1;	//성공(1)을 리턴
			break;
		case GREATER:	//현재 아이템의 id가 더 크면(정렬되있으므로 나머지에 찾는게 없다)
			return 0;	//실패(0)을 리턴
			break;
		default:	//현재 아이템의 id가 더 작으면
			GetNextItem(CurItem);	//다음 아이템을 가져온다.(계속 탐색)
			break;
		}
	}
	return 0; //실패시0
}

//Primary가 일치하는 item을 찾아서 제거함
template <typename T>
int SortedArrayList<T>::Delete(T data)
{
	if (m_Length == 0)
		return 0;
	if (Get(data))	//Primary가 일치하는 item을 발견한다면(1)
	{
		for (int i = m_CurPointer; i < m_Length; i++)	//현재 포인터부터 입력된 배열 끝까지 반복
			m_Array[i] = m_Array[i + 1];	//배열 뒤에걸 앞으로 하나씩 땡김
		m_Length--;	//아이템 개수를 하나 줄임
		return 1;	//성공(1)을 리턴
	}
	return 0;	//Primary일치하는 item을 찾지 못한다면 실패(0)을 리턴
}

//id가 일치하는 item의 내용을 교체시킴
template <class T>
int SortedArrayList<T>::Replace(T data)
{
	MusicType tmp(data);	//입력받은 item을 백업

	if (Get(data))	//일치하는 아이템을 찾은 경우
	{
		m_Array[m_CurPointer] = tmp;	//배열에서 현재포인터가 가르키는 것을 백업했던 아이템으로 교체시킴
		return 1;	//성공(1)을 리턴
	}
	return 0;	//id일치하는 item을 찾지 못한다면 실패(0)을 리턴
}

//id가 일치하는 item을 이진탐색으로 검색해서 반환한다.
template <class T>
int SortedArrayList<T>::GetBinarySearch(T& data)
{
	if (m_Length == 0)	//만약 배열이 비었다면
		return 0;	//실패(0)을 리턴
	int currentPos = m_Length / 2;	//배열의 중간부터 시작
	while (1)
	{
		switch (m_Array[currentPos].CompareByPri(data))
		{
		case EQUAL:	//현재 아이템과 입력 아이템의 id가 일치한다면
			data = m_Array[currentPos];	//data에 발견한 값을 리턴
			return 1;	//성공(1)을 리턴
			break;
		case GREATER:	//현재 아이템의 id가 입력 아이템의 id보다 크다면
			if (currentPos == 0)	//처음 배열의 값보다 작은경우
				return 0;	//실패(0)을 리턴
			currentPos /= 2;	//더 작은쪽 인덱스의 절반로 이동
			break;
		case LESS:	//현재 아이템의 id가 입력 아이템의 id보다 작다면
			if (currentPos == m_Length - 1)	//마지막 배열의 값보다 큰경우
				return 0;	//실패(0)을 리턴
			currentPos = (currentPos + m_Length) / 2;	//더 큰쪽 인덱스의 절반으로 이동
			break;
		}
	}
	return 0;	//호출될 일 없는 리턴(WARNING 방지용)
}



#endif	// _SORTEDARRAYLIST_H