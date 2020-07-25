#ifndef _SORTEDARRAYLIST_H
#define _SORTEDARRAYLIST_H


#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#define pMAXSIZE 10

// ���Ƚ�� ��

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
	*	@brief	item�� ã�Ƽ� �ش� item�� ��ȯ�Ѵ�.
	*	@pre	�μ� data�� �ִ� id�� list ���� �����ϴ� ���̾�� �Ѵ�.
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
	*	@brief	����Ž���� ���� id�� ��ġ�ϴ� list�� item�� ã�Ƽ� ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	�迭 ���� �Ѱܹ��� item�� id�� ��ġ�ϴ� ���� ã�Ƽ� data�� ��ȯ�ȴ�.
	*	@param	data	ã���� �ϴ� id�� �Էµ� ItemType��.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
	int GetBinarySearch(T& data);

	/**
	*	@brief	m_CurPointer�� ����Ű�� item�� �ּҸ� �޾ƿ´�.
	*	@pre	m_CurPotiner�� ���ǵǾ� �־���Ѵ�.
	*	@post	none.
	*	@return m_CurPointer�� ����Ű�� item�� �ּҰ�
	*/
	T* GetCurItemAddress()
	{
		if (m_CurPointer == -1)
			return 0;

		return &(m_Array[m_CurPointer]);
	}

	/**
	*	@brief	��� ����
	*	@pre	����� ������� �ʾƾ� ��.
	*	@post	����� �����
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

		while (m_CurPointer <= m_Length) //ó������ ������
		{
			if (CurItem.CompareByPlay(inData) == GREATER || m_CurPointer == m_Length)	//���� CurItem>inData�ϰ�� Ȥ�� �迭�� �������̶� �񱳴���� ���°��
			{
				for (int i = m_CurPointer; i < pMAXSIZE; i++)	//�տ��� ���� �ϳ��� �����.
					m_Array[i] = m_Array[i + 1];	//�迭 �б�
				m_Array[m_CurPointer] = inData;	//�迭 ���� �� ���� �����Ϳ� ������ �ִ´�.
				m_Length++;	//���� ����
				break;
			}
			GetNextItem(CurItem);	//��������������
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
	m_CurPointer++;	// list pointer ����
	if (m_CurPointer == pMAXSIZE)	// end of list�̸� -1�� ����
		return -1;

	data = m_Array[m_CurPointer];	// ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}

//id�� ��ġ�ϴ� item�� ã�Ƽ� ��ȯ��
template <class T>
int SortedArrayList<T>::Get(T& data)
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
		case GREATER:	//���� �������� id�� �� ũ��(���ĵ������Ƿ� �������� ã�°� ����)
			return 0;	//����(0)�� ����
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
int SortedArrayList<T>::Delete(T data)
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

//id�� ��ġ�ϴ� item�� ������ ��ü��Ŵ
template <class T>
int SortedArrayList<T>::Replace(T data)
{
	MusicType tmp(data);	//�Է¹��� item�� ���

	if (Get(data))	//��ġ�ϴ� �������� ã�� ���
	{
		m_Array[m_CurPointer] = tmp;	//�迭���� ���������Ͱ� ����Ű�� ���� ����ߴ� ���������� ��ü��Ŵ
		return 1;	//����(1)�� ����
	}
	return 0;	//id��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����
}

//id�� ��ġ�ϴ� item�� ����Ž������ �˻��ؼ� ��ȯ�Ѵ�.
template <class T>
int SortedArrayList<T>::GetBinarySearch(T& data)
{
	if (m_Length == 0)	//���� �迭�� ����ٸ�
		return 0;	//����(0)�� ����
	int currentPos = m_Length / 2;	//�迭�� �߰����� ����
	while (1)
	{
		switch (m_Array[currentPos].CompareByPri(data))
		{
		case EQUAL:	//���� �����۰� �Է� �������� id�� ��ġ�Ѵٸ�
			data = m_Array[currentPos];	//data�� �߰��� ���� ����
			return 1;	//����(1)�� ����
			break;
		case GREATER:	//���� �������� id�� �Է� �������� id���� ũ�ٸ�
			if (currentPos == 0)	//ó�� �迭�� ������ �������
				return 0;	//����(0)�� ����
			currentPos /= 2;	//�� ������ �ε����� ���ݷ� �̵�
			break;
		case LESS:	//���� �������� id�� �Է� �������� id���� �۴ٸ�
			if (currentPos == m_Length - 1)	//������ �迭�� ������ ū���
				return 0;	//����(0)�� ����
			currentPos = (currentPos + m_Length) / 2;	//�� ū�� �ε����� �������� �̵�
			break;
		}
	}
	return 0;	//ȣ��� �� ���� ����(WARNING ������)
}



#endif	// _SORTEDARRAYLIST_H