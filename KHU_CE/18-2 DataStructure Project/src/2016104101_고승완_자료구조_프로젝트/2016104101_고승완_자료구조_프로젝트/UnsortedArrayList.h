#ifndef _UNSORTEDLIST_H
#define _UNSORTEDLIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#include "MusicType.h"

#define MAXSIZE_ 20

/**
*	array based simple unsorted list.
*/
template<class T>
class UnsortedArrayList
{
public:
	/**
	*	default constructor.
	*/
	UnsortedArrayList()
	{
		m_Length = 0;
		ResetList();
	}

	/**
	*	destructor.
	*/
	~UnsortedArrayList() {}

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
	*	@pre	인수 data에 있는 Primary가 list 내에 존재하는 값이어야 한다.
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
	*	@brief	목록 비우기
	*	@pre	목록이 비어있지 않아야 함.
	*	@post	목록이 비워짐
	*/
	void Reset()
	{
		delete[]m_Array;
		m_Length = 0;
		m_CurPointer = -1;
	}

	/**
	*	@brief	m_CurPointer가 가리키는 item의 주소를 받아온다.
	*	@pre	m_CurPotiner가 정의되어 있어야한다.
	*	@post	none.
	*	@return m_CurPointer가 가리키는 item의 주소값
	*/
	T* GetCurItemAddress()
	{
		if (m_CurPointer == -1)
			return &(m_Array[m_CurPointer]);

		return &(m_Array[m_CurPointer]);
	}
private:
	MusicType m_Array[MAXSIZE_];  ///< list array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
};

#endif	// _UNSORTEDLIST_H


// Make list empty.
template<class T>
void UnsortedArrayList<T>::MakeEmpty()
{
	m_Length = 0;
}


// Get a number of records in current list.
template<class T>
int UnsortedArrayList<T>::GetLength()
{
	return m_Length;
}


// Check capacity of list is full.
template<class T>
bool UnsortedArrayList<T>::IsFull()
{
	if (m_Length > MAXSIZE_ - 1)
		return true;
	else
		return false;
}


// add a new data into list.
template<class T>
int UnsortedArrayList<T>::Add(T inData)
{
	if (!IsFull())
	{
		if (m_Length == 0)
			m_Array[m_Length] = inData;
		else
			for (int i = m_Length+1; i > 0; i--)	//이미 입력된 것부터 최근 입력된 것까지 배열 맨 앞+1까지 반복
				m_Array[i] = m_Array[i - 1];	//배열 앞에걸 뒤으로 하나씩 땡김
	
		m_Array[0] = inData;
		m_Length++;
	}
	else if (IsFull())
	{
		for (int i = 1; i < m_Length-1; i++)	 // m_Length = 20, m_Array[20]은 날려버림
			m_Array[i] = m_Array[i + 1];	
		m_Array[0] = inData;
	}
	else
		return 0;

	return 1;
}

// Initialize list iterator.
template<class T>
void UnsortedArrayList<T>::ResetList()
{
	m_CurPointer = -1;
}


// move list iterator to the next item in list and get that item.
template<class T>
int UnsortedArrayList<T>::GetNextItem(T& data)
{
	m_CurPointer++;	// list pointer 증가
	if (m_CurPointer == MAXSIZE_)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}

//Primary가 일치하는 item을 찾아서 반환함
template <class T>
int UnsortedArrayList<T>::Get(T& data)
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
		case GREATER:	//현재 아이템의 id가 더 작으면
			GetNextItem(CurItem);	//다음 아이템을 가져온다.(계속 탐색)
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
int UnsortedArrayList<T>::Delete(T data)
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

//Primary가 일치하는 item의 내용을 교체시킴
template <class T>
int UnsortedArrayList<T>::Replace(T data)
{
	MusicType tmp(data);	//입력받은 item을 백업

	if (Get(data))	//일치하는 아이템을 찾은 경우
	{
		m_Array[m_CurPointer] = tmp;	//배열에서 현재포인터가 가르키는 것을 백업했던 아이템으로 교체시킴
		return 1;	//성공(1)을 리턴
	}
	return 0;	//id일치하는 item을 찾지 못한다면 실패(0)을 리턴
}