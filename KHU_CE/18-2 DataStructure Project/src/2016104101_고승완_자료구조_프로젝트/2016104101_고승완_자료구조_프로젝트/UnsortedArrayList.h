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
	*	@brief	item�� ã�Ƽ� �ش� item�� ��ȯ�Ѵ�.
	*	@pre	�μ� data�� �ִ� Primary�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ������ ã�� item�� data�� �Էµȴ�.
	*	@param	data	ã���� �ϴ� id�� �Էµ� ItemType��. �߰��� item�� ���ϵȴ�.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
	int Get(T& data);

	/**
	*	@brief	id�� ��ġ�ϴ� item�� ã�Ƽ� �ش� item�� �����Ѵ�.
	*	@pre	�μ� data�� �ִ� id�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ���� �ش� item�� ���ŵȴ�.
	*	@param	data	�����ϰ��� �ϴ� id�� �Էµ� ItemType��.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int Delete(T data);

	/**
	*	@brief	id�� ��ġ�ϴ� list�� item�� ã�Ƽ� �����Ѵ�.
	*	@pre	�μ� data�� �ִ� id�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	�迭 ���� �Ѱܹ��� item�� id�� ��ġ�ϴ� ���� �Ѱܹ��� item�� �������� ����ȴ�.
	*	@param	data	��ü�ϰ��� �ϴ� id�� ���ڵ带 ���� ItemType��.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int Replace(T data);

	/**
	*	@brief	��� ����
	*	@pre	����� ������� �ʾƾ� ��.
	*	@post	����� �����
	*/
	void Reset()
	{
		delete[]m_Array;
		m_Length = 0;
		m_CurPointer = -1;
	}

	/**
	*	@brief	m_CurPointer�� ����Ű�� item�� �ּҸ� �޾ƿ´�.
	*	@pre	m_CurPotiner�� ���ǵǾ� �־���Ѵ�.
	*	@post	none.
	*	@return m_CurPointer�� ����Ű�� item�� �ּҰ�
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
			for (int i = m_Length+1; i > 0; i--)	//�̹� �Էµ� �ͺ��� �ֱ� �Էµ� �ͱ��� �迭 �� ��+1���� �ݺ�
				m_Array[i] = m_Array[i - 1];	//�迭 �տ��� ������ �ϳ��� ����
	
		m_Array[0] = inData;
		m_Length++;
	}
	else if (IsFull())
	{
		for (int i = 1; i < m_Length-1; i++)	 // m_Length = 20, m_Array[20]�� ��������
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
	m_CurPointer++;	// list pointer ����
	if (m_CurPointer == MAXSIZE_)	// end of list�̸� -1�� ����
		return -1;
	data = m_Array[m_CurPointer];	// ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}

//Primary�� ��ġ�ϴ� item�� ã�Ƽ� ��ȯ��
template <class T>
int UnsortedArrayList<T>::Get(T& data)
{
	MusicType CurItem;

	ResetList();	//iterator �ʱ�ȭ
	GetNextItem(CurItem);	//ù������ ������
	while (m_CurPointer < m_Length)	//ó������ ������
	{
		switch (CurItem.CompareByPri(data))	//�Է� �����۰� ���� �������� ��
		{
		case EQUAL:	//��ġ�ϸ�
			data = CurItem;	//data�� ���� �������� ��ȯ
			return 1;	//����(1)�� ����
			break;
		case GREATER:	//���� �������� id�� �� ������
			GetNextItem(CurItem);	//���� �������� �����´�.(��� Ž��)
			break;
		default:	//���� �������� id�� �� ������
			GetNextItem(CurItem);	//���� �������� �����´�.(��� Ž��)
			break;
		}
	}
	return 0; //���н�0
}

//Primary�� ��ġ�ϴ� item�� ã�Ƽ� ������
template <typename T>
int UnsortedArrayList<T>::Delete(T data)
{
	if (m_Length == 0)
		return 0;
	if (Get(data))	//Primary�� ��ġ�ϴ� item�� �߰��Ѵٸ�(1)
	{
		for (int i = m_CurPointer; i < m_Length; i++)	//���� �����ͺ��� �Էµ� �迭 ������ �ݺ�
			m_Array[i] = m_Array[i + 1];	//�迭 �ڿ��� ������ �ϳ��� ����

		m_Length--;	//������ ������ �ϳ� ����
		return 1;	//����(1)�� ����
	}
	return 0;	//Primary��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����
}

//Primary�� ��ġ�ϴ� item�� ������ ��ü��Ŵ
template <class T>
int UnsortedArrayList<T>::Replace(T data)
{
	MusicType tmp(data);	//�Է¹��� item�� ���

	if (Get(data))	//��ġ�ϴ� �������� ã�� ���
	{
		m_Array[m_CurPointer] = tmp;	//�迭���� ���������Ͱ� ����Ű�� ���� ����ߴ� ���������� ��ü��Ŵ
		return 1;	//����(1)�� ����
	}
	return 0;	//id��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����
}