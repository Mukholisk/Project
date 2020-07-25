#define _CRT_SECURE_NO_WARNINGS
#ifndef _APPLICATION_H
#define _APPLICATION_H
#pragma comment(lib, "winmm.lib")

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "ArtistType.h"
#include "MusicType.h"
#include "SimplifiedType.h"
#include "SortedLinkedList.h"
#include "SortedArrayList.h"
#include "UnsortedArrayList.h"
#include "AlbumType.h"
//#include "PlayType.h"

#include<Windows.h>
#include<MMSystem.h>
using namespace std;

#define FILENameSIZE 1024
#define SIZE 100


/**
*	application class for item management simply.
*/
class Application
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		m_Command = 0;
	}

	/**
	*	destructor.
	*/
	~Application() {}

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.(Main Screen)
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	Management Part driver.
	*	@pre	Management Part is started.
	*	@post	Management Part is finished.
	*/
	void RunMusicManagement();

	/**
	*	@brief	Search and Play Part driver.
	*	@pre	Search and Play Part is started.
	*	@post	Search and Play Part is finished.
	*/
	void RunMusicSearchNPlay();

	/**
	*	@brief	Display command on screen and get a input from keyboard.(Management Screen)
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommandManagement();

	/**
	*	@brief	Display command on screen and get a input from keyboard.(Player Screen)
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommandPlayer();

	/**
	*	@brief	View Part in Management Part driver.
	*	@pre	View Part in Management Part is started.
	*	@post	View Part in Management Part is finished.
	*/
	void RunView();

	/**
	*	@brief	Search Part in Management Part driver.
	*	@pre	Search Part in Management Part is started.
	*	@post	Search Part in Management Part is finished.
	*/
	void RunSearch();

	/**
	*	@brief	Display command on screen and get a input from keyboard.(View Screen)
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int ViewWhat();

	/**
	*	@brief	Display command on screen and get a input from keyboard.(Search Screen)
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int SearchWhat();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddMusic();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllMusic();

	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile();

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile();

	/**
	*	@brief	Open a file(C:\\mukho.txt) as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	Open a file(C:\\mukho.txt) as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();

	/**
	*	@brief	��ü�� ���� ��, ���ڿ��� �Է¹޴´�.
	*	@pre	����.
	*	@post	SearchByName�Լ��� ���ڿ��� ������ ��ü�� �����Ѵ�.
	*	@return	����.
	*/
	void RetreiveRecordByName();

	/**
	*	@brief	inData�� �̸� �κ��� �����ϴ� ���ڿ��� ã�� ����Ѵ�.
	*	@pre	inData�� �̸� �κ��� �ʱ�ȭ�Ǿ��־�� �Ѵ�.
	*	@post	inData�� �˸��� �׸��� ����ȴ�.
	*	@param	inData	�̸��� �����Ǿ��ְ� �������� ����ִ� Musictype
	*	@return	����.
	*/
	void SearchByName(MusicType &inData);

	/**
	*	@brief	��ü�� ���� ��, ���ڿ��� �Է¹޴´�.
	*	@pre	����.
	*	@post	SearchByArtist�Լ��� ���ڿ��� ������ ��ü�� �����Ѵ�.
	*	@return	����.
	*/
	void RetreiveRecordByArtist();

	/**
	*	@brief	inData�� �̸� �κ��� �����ϴ� ���ڿ��� ã�� ����Ѵ�.
	*	@pre	inData�� �̸� �κ��� �ʱ�ȭ�Ǿ��־�� �Ѵ�.
	*	@post	inData�� �˸��� �׸��� ����ȴ�.
	*	@param	inData	�̸��� �����Ǿ��ְ� �������� ����ִ� Musictype
	*	@return	����.
	*/
	void SearchByArtist(MusicType &inData);

	/**
	*	@brief	��ü�� ���� ��, ���ڿ��� �Է¹޴´�.
	*	@pre	����.
	*	@post	SearchByAlbum�Լ��� ���ڿ��� ������ ��ü�� �����Ѵ�.
	*	@return	����.
	*/
	void RetreiveRecordByAlbum();

	/**
	*	@brief	inData�� �̸� �κ��� �����ϴ� ���ڿ��� ã�� ����Ѵ�.
	*	@pre	inData�� �̸� �κ��� �ʱ�ȭ�Ǿ��־�� �Ѵ�.
	*	@post	inData�� �˸��� �׸��� ����ȴ�.
	*	@param	inData	�̸��� �����Ǿ��ְ� �������� ����ִ� Musictype
	*	@return	����.
	*/
	void SearchByAlbum(MusicType &inData);

	/**
	*	@brief	����ڿ��� Name�� �Է¹޾� SortedList�� Delete�Լ��� �Ѱ��ִ� ������ �Ѵ�.
	*	@pre	����.
	*	@post	����ڰ� �Է��� Name�� ������ �ִ� Musictype�� m_List���� �������.
	*	@return	����.
	*/
	void Delete();

	/**
	*	@brief	����ڿ��� Name�� �Է¹޾� SortedList�� Replace�Լ��� �Ѱ��ִ� ������ �Ѵ�.
	*	@pre	����.
	*	@post	����ڰ� �Է��� Name�� ������ �ִ� MusicType�� �ٽ� �Է¹޾� �����Ѵ�.
	*	@return	����.
	*/
	void Update();

	/**
	*	@brief	Primary key�� �̿��� ���ϴ� ���������� �����´�.
	*	@pre	����Ʈ�� �ʱ�ȭ�Ǿ����.
	*	@post	inData�� ���ϴ� �������� ���
	*	@return	ã���� 1, �ƴϸ� 0
	*	@param  key ���ȣ�� ã������ int�� ����
	*	@param	inData ����� data
	*/
	bool Search(string key, MusicType& inData);

	/**
	*	@brief	��Ƽ��Ʈ ����Ʈ�� �ִ� ����� ��Ƽ��Ʈ�� ���� ���
	*	@pre	����.
	*	@post	����.
	*	@return	����.
	*/
	void DisplayMusicbyArtist();

	/**
	*	@brief	��ü�� ���� ��, ���ڿ��� �Է¹޴´�.
	*	@pre	����.
	*	@post	SearchByNameNArtist�Լ��� ���ڿ��� ������ ��ü�� �����Ѵ�.
	*	@return	����.
	*/
	void RetreiveRecordByNameNArtist();

	/**
	*	@brief	inData�� �̸� �κ��� �����ϴ� ���ڿ��� ã�� ����Ѵ�.
	*	@pre	inData�� �̸� �κ��� �ʱ�ȭ�Ǿ��־�� �Ѵ�.
	*	@post	inData�� �˸��� �׸��� ����ȴ�.
	*	@param	inData	�̸��� �����Ǿ��ְ� �������� ����ִ� Musictype
	*	@return	����.
	*/
	void SearchByNameNArtist(MusicType &inData);

	/**
	*	@brief	MusicList�� �ִ� ���� �ٹ� ���� ����Ѵ�.
	*	@pre	����.
	*	@post	����.
	*	@return	����.
	*/
	void DisplayMusicbyAlbum();

	/**
	*	@brief	�ٹ��� ���� ���� ����Ѵ�.
	*	@pre	����.
	*	@post	����.
	*	@return	����.
	*/
	void DisplayAlbumbyArtist();

	/**
	*	@brief	�ٹ��� ���� ������ �Է¹޾� ����Ѵ�.(DB�� ������ �����)
	*	@pre	����.
	*	@post	�뷡 ����
	*	@return	����.
	*/
	void PlayMusic();

	/**
	*	@brief	������ ��� ���̸� ����.
	*	@pre	������ ��� ����
	*	@post	������ ��
	*	@return	����.
	*/
	void StopMusic();

	/**
	*	@brief	��ü�� ���� ��, ���ڿ��� �Է¹޴´�.
	*	@pre	����.
	*	@post	SearchByNameNArtistToPlay�Լ��� ���ڿ��� ������ ��ü�� �����Ѵ�.
	*	@return	����.
	*/
	void RetreiveRecordByNameNArtistToPlay();

	/**
	*	@brief	inData�� �̸� �κ��� �����ϴ� ���ڿ��� ã�� ����Ѵ�.
	*	@pre	inData�� �̸� �κ��� �ʱ�ȭ�Ǿ��־�� �Ѵ�.
	*	@post	inData�� �˸��� �׸��� ����ȴ�.
	*	@param	inData	�̸��� �����Ǿ��ְ� �������� ����ִ� Musictype
	*	@return	����.
	*/
	void SearchByNameNArtistToPlay(MusicType &inData);

	/**
	*	@brief	��ü�� ���� ��, ���ڿ��� �Է¹޴´�.
	*	@pre	����.
	*	@post	SearchByLyrics�Լ��� ���ڿ��� ������ ��ü�� �����Ѵ�.
	*	@return	����.
	*/
	void RetreiveRecordByLyrics();

	/**
	*	@brief	inData�� ���ڿ� �κ��� �����ϴ� ���ڿ��� ã�� ����Ѵ�.
	*	@pre	inData�� ���� �κ��� �ʱ�ȭ�Ǿ��־�� �Ѵ�.
	*	@post	inData�� �˸��� �׸��� ����ȴ�.
	*	@param	inData	�̸��� �����Ǿ��ְ� �������� ����ִ� Musictype
	*	@return	����.
	*/
	void SearchByLyrics(MusicType &inData);

	/**
	*	@brief	r_List�� �ִ� ���� ����Ѵ�.
	*	@pre	����.
	*	@post	����.
	*	@return	����.
	*/
	void DisplayRecentMusic();

	/**
	*	@brief	p_List�� �ִ� ���� �ٹ� ���� ����Ѵ�.
	*	@pre	����.
	*	@post	����.
	*	@return	����.
	*/
	void DisplayPlayMusic();

private:
	FILE *m_InFile;			///< input file descriptor.
	FILE *m_OutFile;		///< output file descriptor.
	SortedLinkedList<MusicType> m_List;		/// �뷡 ����Ʈ
	ArtistType a_list[5];	///< ��Ƽ��Ʈ ����Ʈ
	UnsortedArrayList<MusicType> r_List;	///< �ֱ� �߰� ��
	//SortedArrayList<PlayType> p_List;		///< �÷��� ����Ʈ
	int m_Command;			///< main command number.
	int m_CommandSec;		/// Manege command number
	int m_CommandSec_;		/// Player command number
	int m_CommandThi;		/// View command number
	int m_CommandThi_;		/// Search command number
};

#endif	// _APPLICATION_H

//���Ǻ�

// Program main driver.
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:
			RunMusicManagement();
			break;
		case 2:
			RunMusicSearchNPlay();
			break;
		case 0:
			return;
		default:
			cout << "\n\n\t�߸��� �Է��Դϴ�...\n\n";
			break;
		}
	}
}


// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command0;
	cout << endl;
	cout << "\t*******************************" << endl;
	cout << "\t*   SG���ʺ� Player �Դϴ�.   *" << endl;
	cout << "\t*      ���� ȭ�� �Դϴ�.      *" << endl;
	cout << "\t*******************************" << endl;
	cout << endl;
	cout << "\t---No--- ��  �� ------ " << endl;
	cout << "\t   1 : ���� ����" << endl;
	cout << "\t   2 : ���� �÷��̾�" << endl;
	cout << "\t   0 : ����" << endl;
	
	cout << endl << "\t ���ϴ� ����� �����ϼ���--> ";

	cin >> command0;
	cout << endl << endl;

	return command0;
}

void Application::RunMusicManagement()
{
	while (1)
	{
		m_CommandSec = GetCommandManagement();

		switch (m_CommandSec)
		{
		case 1:
			AddMusic();
			break;
		case 2:
			if (!m_List.IsEmpty())
				Delete();
			else
				cout << "\n\n\t**����� ����ֽ��ϴ�. �߰� �� �̿����ּ���." << endl << endl;
			break;
		case 3:
			Update();
			break;
		case 4:
			RunView();
			break;
		case 5:
			WriteDataToFile();
			break;
		case 6:
			ReadDataFromFile();
			break;
		case 0:
			return;
		default:
			cout << "\n\n\t�߸��� �Է��Դϴ�...\n\n";
			break;
		}
	}
}

int Application::GetCommandManagement()
{
	int command2;
	cout << endl;
	cout << "\t*******************************" << endl;
	cout << "\t*    ���� ���� �޴��Դϴ�.    *" << endl;
	cout << "\t*                             *" << endl;
	cout << "\t*******************************" << endl;
	cout << endl;
	cout << "\t---No--- ��  �� ------ " << endl;
	cout << "\t   1 : ���� �߰�" << endl;
	cout << "\t   2 : ���� ����" << endl;
	cout << "\t   3 : ���� ����" << endl;
	cout << "\t   4 : ���� ��� ����" << endl;
	cout << "\t   5 : ���� ��� ����" << endl;
	cout << "\t   6 : ���� ��� �ҷ�����" << endl;
	cout << "\t   0 : �ڷ� ����(���� ȭ��)" << endl;

	cout << endl << "\t ���ϴ� ����� �����ϼ���--> ";
	cin >> command2;
	cout << endl << endl;

	return command2;
}

void Application::RunView()
{
	while (1)
	{
		m_CommandThi = ViewWhat();

		switch (m_CommandThi)
		{
		case 1:
			DisplayAllMusic();
			break;
		case 2:
			DisplayMusicbyArtist();
			break;
		case 3:
			DisplayMusicbyAlbum();
			break;
		case 4:
			DisplayAlbumbyArtist();
			break;
		case 5:
			DisplayRecentMusic();
			break;
		//case 6:
			//DisplayPlayMusic();
		case 0:
			return;
		default:
			cout << "\n\n\t�߸��� �Է��Դϴ�...\n\n";
			break;
		}
	}
}

int Application::ViewWhat()
{
	if(!m_List.IsEmpty())
	{
		int command3;
		cout << endl;
		cout << "\t*******************************" << endl;
		cout << "\t*    ���� ��� �����Դϴ�.    *" << endl;
		cout << "\t*���� �������� �� �� �ֽ��ϴ�.*" << endl;
		cout << "\t*******************************" << endl;
		cout << endl;
		cout << "\t---No--- ��  �� ------ " << endl;
		cout << "\t   1 : ��ü ���" << endl;
		cout << "\t   2 : ������ ���" << endl;
		cout << "\t   3 : �ٹ��� ���" << endl;
		cout << "\t   4 : ������ �ٹ� ���" << endl;
		cout << "\t   5 : �ֱ� �߰��� 10�� ���" << endl;
		//cout << "\t   6 : ���Ƚ���� ���� 10�� ���" << endl;
		cout << "\t   0 : �ڷ� ����(���� ����)" << endl;
		cout << endl << "\t ���ϴ� ����� �����ϼ���--> ";
		cin >> command3;
		cout << endl;

		return command3;
	}
	else
	{
		cout << "\n\t**����� ����ֽ��ϴ�. �߰� �� �̿����ּ���." << endl << endl;
		return 0;
	}
}

void Application::RunMusicSearchNPlay()
{
	while (1)
	{
		m_CommandSec_ = GetCommandPlayer();

		switch (m_CommandSec_)
		{
		case 1:
			if (m_List.IsEmpty())
				cout << "\n\t**����� ����ֽ��ϴ�. �߰� �� �̿����ּ���." << endl << endl;
			else
				PlayMusic();
			break;
		case 2:
			StopMusic();
			break;
		case 3:
			RunSearch();
			break;
		case 0:
			return;
		default:
			cout << "\n\t�߸��� �Է��Դϴ�...\n\n";
			break;
		}
	}
}

int Application::GetCommandPlayer()
{
	int command4;
	cout << endl;
	cout << "\t*******************************" << endl;
	cout << "\t*    ���� �÷��̾��Դϴ�.     *" << endl;
	cout << "\t*                             *" << endl;
	cout << "\t*******************************" << endl;
	cout << endl;
	cout << "\t---No--- ��  �� ------ " << endl;
	cout << "\t   1 : ���� ���" << endl;
	cout << "\t   2 : ���� ����" << endl;
	cout << "\t   3 : ���� �˻�" << endl;
	cout << "\t   0 : �ڷ� ����" << endl;
	
	cout << endl << "\t ���ϴ� ����� �����ϼ���--> ";
	cin >> command4;
	cout << endl << endl;
	
	return command4;
}

void Application::RunSearch()
{
	while (1)
	{
		m_CommandThi_ = SearchWhat();

		switch (m_CommandThi_)
		{
		case 1:
			RetreiveRecordByName();
			break;
		case 2:
			RetreiveRecordByArtist();
			break;
		case 3:
			RetreiveRecordByAlbum();
			break;
		case 4:
			RetreiveRecordByNameNArtist();
			break;
		case 5:
			RetreiveRecordByLyrics();
			break;
		case 0:
			return;
		default:
			cout << "\n\t�߸��� �Է��Դϴ�...\n\n";
			break;
		}
	}
}

int Application::SearchWhat()
{
	if (!m_List.IsEmpty())
	{
		int command5;
		cout << endl;
		cout << "\t*******************************" << endl;
		cout << "\t*    ���� �˻� �޴� �Դϴ�.   *" << endl;
		cout << "\t*                             *" << endl;
		cout << "\t*******************************" << endl;
		cout << endl;

		cout << "\t---No--- ��  �� ------ " << endl;
		cout << "\t   1 : ������� �˻�" << endl;
		cout << "\t   2 : ������ �˻�" << endl;
		cout << "\t   3 : �ٹ����� �˻�" << endl;
		cout << "\t   4 : ���� �������� �˻�" << endl;
		cout << "\t   5 : ����� �˻�" << endl;
		cout << "\t   0 : �ڷ� ����(���� �÷��̾�)" << endl;
		cout << endl << "\t ���ϴ� ����� �����ϼ���--> ";
		
		cin >> command5;
		cout << endl << endl;

		return command5;
	}
	else
	{
		cout << "\n\n\t**����� ����ֽ��ϴ�. �߰� �� �̿����ּ���." << endl << endl;
		return 0;
	}
}

// Add new record into list.
int Application::AddMusic()
{
	string artist;	///< ������ ������ �ӽú���
	string name;	///< ����� ������ �ӽú���
	string primary; ///< ����Ű�� ������ �ӽú���
	int num;		///< ���ȣ�� ������ �ӽú���

	//MusicList�� �߰�
	MusicType item;
	item.SetRecordFromKB();

	if (m_List.Add(item))
	{
		//ArtistType�� �߰�
		SimplifiedType SimpleType;
		primary = item.GetPrimary();
		num = item.GetNum();
		name = item.GetName();
		artist = item.GetArtist();

		// 0->SG���ʺ�, 1->ä����, 2->����ȣ, 3->�̼���, 4->�����
		if (artist == "SG���ʺ�")
		{
			SimplifiedType s_temp(artist, primary, name);
			a_list[0].addListinArtist(s_temp);
		}
		else if (artist == "ä����")
		{
			SimplifiedType s_temp(artist, primary, name);
			a_list[1].addListinArtist(s_temp);
		}
		else if (artist == "����ȣ")
		{
			SimplifiedType s_temp(artist, primary, name);
			a_list[2].addListinArtist(s_temp);
		}
		else if (artist == "�̼���")
		{
			SimplifiedType s_temp(artist, primary, name);
			a_list[3].addListinArtist(s_temp);
		}
		else if (artist == "�����")
		{
			SimplifiedType s_temp(artist, primary, name);
			a_list[4].addListinArtist(s_temp);
		}

		// �ֱ� �߰�
		r_List.Add(item);
		/*
		PlayType data()
		data.SetArtist(item.GetArtist());
		data.SetName(item.GetName());
		data.SetPlay(item.GetPlay());
		
		p_List.Add(data);*/

		cout << "\n\n\t***�߰��Ǿ����ϴ�.\n" << endl;
		return 1;
	}
	else
	{
		cout << "\n\n\t**�ߺ��� ���� �־� �߰��� �� �����ϴ�." << endl << endl;
		return 0;
	}
	cout << endl << endl;

}

// Display all records in the list on screen.
void Application::DisplayAllMusic()
{
	MusicType data;
	int cnt = 1;

	cout << "\n\n\t***��ü �� ���***" << endl << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	m_List.ResetList();
	do
	{
		if (m_List.GetLength() == 0)
			break;
		cout << "\tNo." << cnt << endl;
		m_List.GetCurItem(data);
		m_List.GotoNextItem();
		data.DisplayRecordOnScreen();
		cnt++;
	} while (!m_List.isLastPointer());

	cout << "\t�� " << cnt-1 << "��\n\n";
}

//ã�� Primary�� ����ڿ��� �Է¹ް� SortedList�� Delete�Լ��� ȣ���Ѵ�.
void Application::Delete()
{
	cout << "\t���� ";
	MusicType data;	//Delete�Լ��� MusicType�� �Ķ���ͷ� ���� ������ ���Ƿ� ������ش�.
	data.SetPriFromKB();	//����ڿ��Լ� Primary���� �Է¹޴´�.

	if (m_List.Delete(data))	//Delete�Լ��� data�� �Ѱ��ش�.
	{
		string temp = data.GetPrimary();
		char StrToCha = temp[8];
		int tempPri = StrToCha - '0';

		SimplifiedType SimpleType;
		int num = data.GetNum();
		string name = data.GetName();
		string artist = data.GetArtist();

		// 1->SG���ʺ�, 2->ä����, 3->����ȣ, 4->�̼���, 5->�����
		if (tempPri == 1)
		{
			SimplifiedType s_temp(artist, temp, name);
			a_list[0].setAArtist("SG���ʺ�");
			a_list[0].deleteListinArtist(s_temp);
		}
		else if (tempPri == 2)
		{
			SimplifiedType s_temp(artist, temp, name);
			a_list[1].setAArtist("ä����");
			a_list[1].deleteListinArtist(s_temp);
		}
		else if (tempPri == 3)
		{
			SimplifiedType s_temp(artist, temp, name);
			a_list[2].setAArtist("����ȣ");
			a_list[2].deleteListinArtist(s_temp);
		}
		else if (tempPri == 4)
		{
			SimplifiedType s_temp(artist, temp, name);
			a_list[3].setAArtist("�̼���");
			a_list[3].deleteListinArtist(s_temp);
		}
		else if (tempPri == 5)
		{
			SimplifiedType s_temp(artist, temp, name);
			a_list[4].setAArtist("�����");
			a_list[4].deleteListinArtist(s_temp);
		}
		// �ֱ� ��Ͽ��� ����
		r_List.Delete(data);
	}
	else
	{
		cout << "\n\n\t��ġ�ϴ� �׸��� ã�� �� �����ϴ�." << endl << endl;	//������ ���������� �޽����� ����Ѵ�.
		return;
	}
	cout << "\n\n\t������ �Ϸ��߽��ϴ�." << endl << endl;	//������ ���������� �޽����� ����Ѵ�.
}

//ã�� Primary�� ����ڿ��� �Է¹ް� SortedList�� Update�Լ��� ȣ���Ѵ�.
void Application::Update()
{
	cout << "\t!!! �˸� !!! \n";
	cout << "\t!!! �߸ų���Ͽ� ������ Ʈ�� ��ȣ�� �ٲٰ� ���� ��� ���� �� �߰����ּ���.\n";

	cout << "\n\n\t������ ���ϴ� �׸��� ";
	MusicType data;	//Replace�Լ��� MusicType�� �Ķ���ͷ� ���� ������ ���Ƿ� ������ش�.
	data.SetPriFromKB();	//����ڿ��Լ� ������ �׸��� Primary�� �Է¹޴´�.
	cin.ignore();
	if (!m_List.Get(data))	//����ڰ� �Է��� �׸��� List�� �ֳ� �˻�
	{
		cout << "\n\t***�׸��� ã�� �� �����ϴ�." << endl << endl;		//ã�� �� ������ �޽����� ����Ѵ�.
		return;
	}
	else	//ã�� �� ������
	{
		cout << "\n\t***���� ã�ҽ��ϴ�." << endl << endl << endl;
		data.DisplayNameOnScreen();
		cout << "\n\t������ ���ϴ� �׸��� ";
		data.SetNameFromKB();	//����ڿ��Լ� ����� �Է¹޴´�.
		cout << "\t������ ���ϴ� �׸��� ";
		data.SetAlbumFromKB();	//����ڿ��Լ� �ٹ��� �Է¹޴´�.
		cout << "\t������ ���ϴ� �׸��� ";
		data.SetLyricsFromKB(); ;//����ڿ��Լ� ���縦 �Է¹޴´�.

		if (m_List.Replace(data)) //Replace�Լ��� data�� �Ѱ��ش�.
		{
			r_List.Replace(data);

			string temp = data.GetPrimary();
			char StrToCha = temp[8];
			int tempPri = StrToCha - '0';

			SimplifiedType SimpleType;
			string name = data.GetName();
			string artist = data.GetArtist();

			// 1->SG���ʺ�, 2->ä����, 3->����ȣ, 4->�̼���, 5->�����
			if (tempPri == 1)
			{
				SimplifiedType SimpleType(artist, temp, name);
				a_list[0].setAArtist("SG���ʺ�");
				a_list[0].replaceListinArtist(SimpleType);
			}
			else if (tempPri == 2)
			{
				SimplifiedType SimpleType(artist, temp, name);
				a_list[1].setAArtist("ä����");
				a_list[1].replaceListinArtist(SimpleType);
			}
			else if (tempPri == 3)
			{
				SimplifiedType SimpleType(artist, temp, name);
				a_list[2].setAArtist("����ȣ");
				a_list[2].replaceListinArtist(SimpleType);
			}
			else if (tempPri == 4)
			{
				SimplifiedType SimpleType(artist, temp, name);
				a_list[3].setAArtist("�̼���");
				a_list[3].replaceListinArtist(SimpleType);
			}
			else if (tempPri == 5)
			{
				SimplifiedType SimpleType(artist, temp, name);
				a_list[4].setAArtist("�����");
				a_list[4].replaceListinArtist(SimpleType);
			}

			cout << "\n\n\t***������ �Ϸ��߽��ϴ�." << endl << endl;	//������ �������� �� �޽����� ����Ѵ�.
		}
		else
			cout << "\n\n\t**������ �����߽��ϴ�." << endl << endl;	//������ �������� �� �޽����� ����Ѵ�.
	}
}

//����ڿ��� ã�����ϴ� Name�� �Է¹ް� �Ѱ��ִ� ������ �Ѵ�.
void Application::RetreiveRecordByName()
{
	cin.ignore();
	MusicType temp;
	cout << "\tã�� ";
	temp.SetNameFromKB();	//SearchByName�Լ��� �Ѱ��� temp�� Name�� ����ڿ��� �Է¹޴´�.
	SearchByName(temp);	//���������� ã�� ������ �ϴ� SearchByName�Լ��� ȣ���ϰ� temp���� �Ѱ��ش�.
	cout << endl << endl;
}

//����ڰ� ã�����ϴ� Name�� �����ϴ� inData�� m_List�� �׸�� �� ��ġ�ϴ� �׸��� ã�� ������ش�. **���α׷��� ���������� Array�� index�� ���� �����ϴ� ����� ��ȣ������ �� �Լ��� Application Ŭ������ �޼ҵ��̹Ƿ� GetNextItem�Լ��� �̿��� iteration�� �̿��߽��ϴ�.
void Application::SearchByName(MusicType &inData)
{
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� MusicType.
	m_List.ResetList();
	int count = 0;	// count�� ã�� �׸��� ������ �������ֱ� ���� ����.
	
	cout << endl << endl << "\n\n\t***���� ���***" << endl << endl;
	if (m_List.GetLength() != 0)
	{
		m_List.GetCurItem(temp);
		m_List.GotoNextItem();

		if (temp.GetName().find(inData.GetName()) != -1)
		{
			temp.DisplayRecordOnScreen();
			count++;
		}

		while (!m_List.isLastPointer())	//List�� ������ �����ϸ� -1�� �����ϹǷ� �ݺ��� �����.
		{
			m_List.GetCurItem(temp);
			if (temp.GetName().find(inData.GetName()) != -1)	//find�Լ������� ��ġ�ϴ� �׸��� �������� ������ -1�� �����ϹǷ� -1�� �ƴϸ� ��ġ�ϴ� ���ڿ��� �ִ°��̴�.
			{
				temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
				count++;	//ã�� ������ 1 �÷��ش�.
			}
			m_List.GotoNextItem();	//���� item���� �ű�
		}
	}
	if (count == 0)
		cout << "\n\t**ã�� �� �����ϴ�.";	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
		cout << endl << endl;
}

//����ڿ��� ã�����ϴ� Artist�� �Է¹ް� �Ѱ��ִ� ������ �Ѵ�.
void Application::RetreiveRecordByArtist()
{
	MusicType temp;
	cout << "\tã�� ";
	cin.ignore();
	temp.SetArtistFromKB();	//SearchByArtist�Լ��� �Ѱ��� temp�� Name�� ����ڿ��� �Է¹޴´�.
	SearchByArtist(temp);	//���������� ã�� ������ �ϴ� SearchByArtist�Լ��� ȣ���ϰ� temp���� �Ѱ��ش�.
	cout << endl << endl;
}


//����ڰ� ã�����ϴ� Artist�� �����ϴ� inData�� m_List�� �׸�� �� ��ġ�ϴ� �׸��� ã�� ������ش�. **���α׷��� ���������� Array�� index�� ���� �����ϴ� ����� ��ȣ������ �� �Լ��� Application Ŭ������ �޼ҵ��̹Ƿ� GetNextItem�Լ��� �̿��� iteration�� �̿��߽��ϴ�.
void Application::SearchByArtist(MusicType &inData)
{
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� MusicType.
	m_List.ResetList();
	int count = 0;	//count�� ã�� �׸��� ������ �������ֱ� ���� ����.

	cout << endl << endl << "\n\n\t***���� ���***" << endl << endl;
	if (m_List.GetLength() != 0)
	{
		m_List.GetCurItem(temp);
		m_List.GotoNextItem();

		if (temp.GetArtist().find(inData.GetArtist()) != -1)
		{
			temp.DisplayRecordOnScreen();
			count++;
		}

		while (!m_List.isLastPointer())	//List�� ������ �����ϸ� -1�� �����ϹǷ� �ݺ��� �����.
		{
			m_List.GetCurItem(temp);
			if (temp.GetArtist().find(inData.GetArtist()) != -1)	//find�Լ������� ��ġ�ϴ� �׸��� �������� ������ -1�� �����ϹǷ� -1�� �ƴϸ� ��ġ�ϴ� ���ڿ��� �ִ°��̴�.
			{
				temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
				count++;	//ã�� ������ 1 �÷��ش�.
			}
			m_List.GotoNextItem();
		}
	}
	if (count == 0)
		cout << "\n\t**ã�� �� �����ϴ�." << endl << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
	else
		cout << "\n\t***" << inData.GetArtist() << " ���� ��� " << count << "���� ã�ҽ��ϴ�.***" << endl << endl;
}

//����ڿ��� ã�����ϴ� Album�� �Է¹ް� �Ѱ��ִ� ������ �Ѵ�.
void Application::RetreiveRecordByAlbum()
{
	MusicType temp;
	cout << "\tã�� ";
	cin.ignore();
	temp.SetAlbumFromKB();	//SearchByAlbum�Լ��� �Ѱ��� temp�� Album�� ����ڿ��� �Է¹޴´�.
	SearchByAlbum(temp);	//���������� ã�� ������ �ϴ� SearchByAlbum�Լ��� ȣ���ϰ� temp���� �Ѱ��ش�.
	cout << endl << endl;
}


//����ڰ� ã�����ϴ� Album�� �����ϴ� inData�� m_List�� �׸�� �� ��ġ�ϴ� �׸��� ã�� ������ش�. **���α׷��� ���������� Array�� index�� ���� �����ϴ� ����� ��ȣ������ �� �Լ��� Application Ŭ������ �޼ҵ��̹Ƿ� GetNextItem�Լ��� �̿��� iteration�� �̿��߽��ϴ�.
void Application::SearchByAlbum(MusicType &inData)
{
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� MusicType.
	m_List.ResetList();
	int count = 0;	//count�� ã�� �׸��� ������ �������ֱ� ���� ����.
	
	cout << endl << endl << "\t***���� ���***" << endl << endl << endl;
	
	if (m_List.GetLength() != 0)
	{
		m_List.GetCurItem(temp);
		m_List.GotoNextItem();

		string curAlbum = "";
		string curArtist = "";
		int curDate = -1;

		if (temp.GetAlbum().find(inData.GetAlbum()) != -1)
		{
			// �ٹ�����
			cout << "\t�ٹ� : " << temp.GetAlbum() << "(���� : " << temp.GetArtist() << ")" << endl;
			cout << "\t�߸����� : " << temp.GetDate() << endl << endl << endl;

			curAlbum = temp.GetAlbum();
			curArtist = temp.GetArtist();
			curDate = temp.GetDate();

			// ������
			temp.DisplayNumOnScreen();
			temp.DisplayPrimaryOnScreen();
			temp.DisplayNameOnScreen();
			cout << endl;
			count++;
		}
		while (!m_List.isLastPointer())	//List�� ������ �����ϸ� -1�� �����ϹǷ� �ݺ��� �����.
		{
			m_List.GetCurItem(temp);
			if (temp.GetAlbum().find(inData.GetAlbum()) != -1)	//find�Լ������� ��ġ�ϴ� �׸��� �������� ������ -1�� �����ϹǷ� -1�� �ƴϸ� ��ġ�ϴ� ���ڿ��� �ִ°��̴�.
			{
				if (curAlbum != temp.GetAlbum() && curArtist != temp.GetArtist() && curDate != temp.GetDate())
				{
					// �ٹ�����
					cout << "\t�ٹ� : " << temp.GetAlbum() << "(���� : " << temp.GetArtist() << ")" << endl;
					cout << "\t�߸����� : " << temp.GetDate() << endl << endl << endl;

					curAlbum = temp.GetAlbum();
					curArtist = temp.GetArtist();
					curDate = temp.GetDate();
				}

				// ������
				temp.DisplayNumOnScreen();
				temp.DisplayPrimaryOnScreen();
				temp.DisplayNameOnScreen();
				cout << endl;
				count++;	//ã�� ������ 1 �÷��ش�.
			}
			m_List.GotoNextItem();
		}
	}
	if (count == 0)
		cout << "\n\t**ã�� �� �����ϴ�." << endl << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
	else
		cout << "\n\t***�ٹ� ���ϰ� �� : " << count << "��" << endl << endl;
}

// Open a file by file descriptor as an input file.
int Application::OpenInFile()
{
	m_InFile = fopen("C:\\mukho.txt", "r");	// file open for reading.

	// return 1 if file opened, not 0.
	if (m_InFile == NULL)
	{
		cout << "\n\t**�ҷ��� �� �����ϴ�. C Drive�� �ִ� mukho.txt ������ Ȯ���غ�����." << endl << endl;
		return 0;
	}
	else
		return 1;
}

// Open a file by file descriptor as an output file.
int Application::OpenOutFile()
{
	fopen_s(&m_OutFile, "C:\\mukho.txt", "w");// file open for writing.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (m_OutFile == NULL)
	{
		cout << "\n\t**������ �� �����ϴ�. C Drive�� �ִ� mukho.txt ������ Ȯ���غ�����."<< endl;
		cout << "\t**���α׷��� ������ �������� �����ϼ���." << endl << endl;
		return 0;
	}
	else
		return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int cnt = 0;
	MusicType data;	// �б�� �ӽ� ����

	// C:\mukho.txt ������ ����.

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile())
	{
		cout << "\n\t**���̺� ������ �����ϴ�." << endl << endl;
		return 0;
	}
	// ������ ��� ������ �о� list�� �߰�
	while (!feof(m_InFile))
	{
		// ���Ͽ��� �ҷ��� ������ ������ �ӽ� ����
		char temp[2] = { 0, };
		char primary[13] = "";
		char name[SIZE] = { 0, };
		char artist[SIZE] = { 0 ,};
		char album[SIZE] = { 0, };
		char tracknum[4] = { 0, };
		char date[10] = "";
		char lyrics[FILENameSIZE] = { 0, };
		char play[5] = { 0, };
		int tracknum_ = -1;
		int date_ = -1;
		int play_ = -1;

		// �ҷ�����
		if(cnt != 0)
			fgets(temp, 2, m_InFile);
		fgets(primary, 13, m_InFile);
		fgets(name, SIZE, m_InFile);
		fgets(artist, SIZE, m_InFile);
		fgets(album , SIZE, m_InFile);
		fgets(tracknum, 4, m_InFile);
		fgets(date, 10, m_InFile);
		fgets(lyrics, FILENameSIZE, m_InFile);
		fgets(play, 5, m_InFile);
		
		if (cnt == 0 && primary[0] == '\0')
		{
			cout << "\n\t**������ ����־� �ҷ��� �� �����ϴ�." << endl << endl;
			break;
		}

		// ��ȯ
		if (primary[strlen(primary) - 1] == '\n')
			primary[strlen(primary) - 1] = '\0';

		name[strlen(name) - 1] = '\0';
		artist[strlen(artist) - 1] = '\0';
		album[strlen(album) - 1] = '\0';

		if (tracknum[strlen(tracknum) - 1] == '\n')
			tracknum[strlen(tracknum) - 1] = '\0';
		tracknum_ = atoi(tracknum);

		if (date[strlen(date) - 1] == '\n')
			date[strlen(date) - 1] = '\0';
		date_ = atoi(date);

		if (lyrics[strlen(lyrics) - 1] == '\n')
			lyrics[strlen(lyrics) - 1] = '\0';

		if (play[strlen(play) - 1] == '\n')
			play[strlen(play) - 1] = '\0';
		play_ = atoi(play);

		// data�� ����
		data.SetPrimary(tracknum_, artist, date_);
		data.SetName(name);
		data.SetArtist(artist);
		data.SetAlbum(album);
		data.SetNum(tracknum_);
		data.SetDate(date_);
		data.SetLyrics(lyrics);
		data.SetPlay(play_);

		// ����Ʈ�� ����
		m_List.Add(data);

		// ArtistType�� �߰�
		SimplifiedType SimpleType;

		string t_artist;	///< ������ ������ �ӽú���
		string t_name;	///< ����� ������ �ӽú���
		string t_primary; ///< ����Ű�� ������ �ӽú���
		int t_num;		///< ���ȣ�� ������ �ӽú���

		t_primary = data.GetPrimary();
		t_num = data.GetNum();
		t_name = data.GetName();
		t_artist = data.GetArtist();

		// 0->SG���ʺ�, 1->ä����, 2->����ȣ, 3->�̼���, 4->�����
		if (t_artist == "SG���ʺ�")
		{
			SimplifiedType s_temp(t_artist,t_primary,t_name);
			a_list[0].addListinArtist(s_temp);
		}
		else if (t_artist == "ä����")
		{
			SimplifiedType s_temp(t_artist, t_primary, t_name);
			a_list[1].addListinArtist(s_temp);
		}
		else if (t_artist == "����ȣ")
		{
			SimplifiedType s_temp(t_artist, t_primary, t_name);
			a_list[2].addListinArtist(s_temp);
		}
		else if (t_artist == "�̼���")
		{
			SimplifiedType s_temp(t_artist, t_primary, t_name);
			a_list[3].addListinArtist(s_temp);
		}
		else if (t_artist == "�����")
		{
			SimplifiedType s_temp(t_artist, t_primary, t_name);
			a_list[4].addListinArtist(s_temp);
		}
		cnt++;

		r_List.Add(data);
	}

	fclose(m_InFile);	// file close


	cout << "\n\t***�ҷ����Ⱑ �Ϸ�Ǿ����ϴ�." << endl << endl;

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	MusicType data;	// ����� �ӽ� ����

	if (m_List.GetLength() == 0)
	{
		cout << "\t***�����Ͱ� ���� ������ �� �����ϴ�." << endl;
		return 0;
	}

	// C:\mukho.txt ������ ����.

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenOutFile())
		return 0;

	// list �����͸� �ʱ�ȭ
	m_List.ResetList();

	do
	{
		m_List.GetCurItem(data);
		
		// ����� �ӽ� ����
		char primary[13] = "";
		char name[SIZE] = { 0, };
		char artist[SIZE] = { 0 , };
		char album[SIZE] = { 0, };
		char tracknum[4] = { 0, };
		char date[10] = "";
		char lyrics[FILENameSIZE] = { 0, };
		char play[5] = { 0, };
		int tracknum_ = -1;
		int date_ = -1;
		int play_ = -1;

		// ��ȯ
		strcpy(primary, data.GetPrimary().c_str());
		strcpy(name, data.GetName().c_str());
		strcpy(artist, data.GetArtist().c_str());
		strcpy(album, data.GetAlbum().c_str());
		tracknum_ = data.GetNum();
		date_ = data.GetDate();
		strcpy(lyrics, data.GetLyrics().c_str());
		play_ = data.GetPlay();

		// ��ȯ (int�� ������ char*�� �ٲ�)
		_itoa(tracknum_, tracknum, 10);
		_itoa(date_, date, 10);
		_itoa(play_, play, 10);

		// ���Ͽ� �Է�
		fputs(primary, m_OutFile);
		fputs("\n", m_OutFile);
		fputs(name, m_OutFile);
		fputs("\n", m_OutFile);
		fputs(artist, m_OutFile);
		fputs("\n", m_OutFile);
		fputs(album, m_OutFile);
		fputs("\n", m_OutFile);
		fputs(tracknum, m_OutFile);
		fputs("\n", m_OutFile);
		fputs(date, m_OutFile);
		fputs("\n", m_OutFile);
		fputs(lyrics, m_OutFile);
		fputs("\n", m_OutFile);
		fputs(play, m_OutFile);

		// ���� ������
		m_List.GotoNextItem();

		// �׸��� �� ������ ������ ���� '\n' �߰� �Է�
		if(!m_List.isLastPointer())
			fputs("\n\n", m_OutFile);
	} while (!m_List.isLastPointer());

	fclose(m_OutFile);	// file close

	cout << "\t***����Ǿ����ϴ�." << endl;
	return 1;
}

bool Application::Search(string key, MusicType& inData)
{
	inData.SetPri(key);

	if (m_List.Get(inData))
		return true;
	else
		return false;
}

//Display Music by artist through artist list
void Application::DisplayMusicbyArtist()
{
	
	cout << "\n\t***���� ���***\n\n";
	for (int i = 0; i < 5; i++)
	{
		a_list[i].PrintAll();
	}
}

//name �� artist ������ �޾� Search�Լ��� �ѱ��.
void Application::RetreiveRecordByNameNArtist()
{
	MusicType temp;
	cin.ignore();
	cout << "\tã�� ���� ";
	temp.SetNameFromKB();
	cout << "\tã�� ���� ";
	temp.SetArtistFromKB();	//SearchByArtist�Լ��� �Ѱ��� temp�� Artist�� ����ڿ��� �Է¹޴´�.
	SearchByNameNArtist(temp);	//���������� ã�� ������ �ϴ� SearchByArtist�Լ��� ȣ���ϰ� temp���� �Ѱ��ش�.
	cout << endl << endl;
}

void Application::SearchByNameNArtist(MusicType& inData)
{
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� MusicType.
	m_List.ResetList();
	m_List.GetCurItem(temp);
	m_List.GotoNextItem();

	int count = 0;	// count�� ã�� �׸��� ������ �������ֱ� ���� ����.
	if (m_List.GetLength() != 0)
	{
		cout << endl << endl << "\t***���� ���***" << endl << endl;
		if (temp.GetArtist().find(inData.GetArtist()) != -1 && temp.GetName().find(inData.GetName()) != -1)
		{
			temp.DisplayRecordOnScreen();
			count++;
		}
		while (!m_List.isLastPointer())	//List�� ������ �����ϸ� -1�� �����ϹǷ� �ݺ��� �����.
		{
			m_List.GetCurItem(temp);
			if (temp.GetArtist().find(inData.GetArtist()) != -1 && temp.GetName().find(inData.GetName()) != -1)
			{
				temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
				count++;	//ã�� ������ 1 �÷��ش�.
			}
			m_List.GotoNextItem();
		}
	}
	if (count == 0)
		cout << "\n\t**ã�� �� �����ϴ�." << endl << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
	else
		cout << endl << endl;
}

void Application::DisplayMusicbyAlbum()
{
	cout << "\n\t***���� ���***\n\n";
	if (m_List.GetLength() == 0)
		return;
	int count = 0;
	SortedLinkedList<AlbumType> a_List;
	m_List.ResetList();
	do
	{
		MusicType tempM;
		m_List.GetCurItem(tempM);

		AlbumType Album;
		Album.SetAlbum(tempM.GetAlbum());
		Album.SetArtist(tempM.GetArtist());

		a_List.Add(Album);
		
		m_List.GotoNextItem();
	} while (!m_List.isLastPointer());

	string curAlbum = "";
	string curArtist = "";

	a_List.ResetList();
	do
	{
		AlbumType tempA;
		a_List.GetCurItem(tempA);

		if (curAlbum != tempA.GetAlbum() || curArtist != tempA.GetArtist())
		{
			cout << "\n\t**�ٹ� : " << tempA.GetAlbum() << "(���� : " << tempA.GetArtist() << ")" << endl;
			curAlbum = tempA.GetAlbum();
			curArtist = tempA.GetArtist();

			m_List.ResetList();
			do
			{
				MusicType tempM;
				m_List.GetCurItem(tempM);
				tempA.SetDate(tempM.GetDate());

				AlbumType tempA_(tempM.GetPrimary(),tempM.GetAlbum(), tempM.GetArtist(), tempM.GetDate());
				if (tempA == tempA_)
					tempM.DisplayNameOnScreen();


				m_List.GotoNextItem();
			} while (!m_List.isLastPointer());
		}
		a_List.GotoNextItem();
	} while (!a_List.isLastPointer());
	cout << endl << endl;
}

void Application::DisplayAlbumbyArtist()
{
	cout << endl << endl << "\t***���� ���***\n\n\n";
	if (m_List.GetLength() == 0)
	{
		cout << "\n\t**ã�� �� �����ϴ�.\n\n";
		return;
	}

	SortedLinkedList<AlbumType> a_List;

	m_List.ResetList();
	do
	{
		MusicType tempM;
		m_List.GetCurItem(tempM);

		AlbumType Album;
		Album.SetAlbum(tempM.GetAlbum());
		Album.SetArtist(tempM.GetArtist());

		a_List.Add(Album);
		m_List.GotoNextItem();
	} while (!m_List.isLastPointer());

	a_List.ResetList();
	string curArtist = "";
	string curAlbum = "";	

	int current[6];
	for (int i = 0; i < 5; i++)
		current[i] = 0;
	current[5] = 1;

	do
	{
		AlbumType tempA;
		a_List.GetCurItem(tempA);
		
		int index = -1;
		if (tempA.GetArtist() == "SG���ʺ�")
			index = 0;
		else if (tempA.GetArtist() == "ä����")
			index = 1;
		else if (tempA.GetArtist() == "����ȣ")
			index = 2;
		else if (tempA.GetArtist() == "�̼���")
			index = 3;
		else if (tempA.GetArtist() == "�����")
			index = 4;
		else
			index = 5;

		if (current[index] < 1)
		{
			cout << "\t**���� : " << tempA.GetArtist() << endl;
			curArtist = tempA.GetArtist();

			current[index] = 1;

			m_List.ResetList();
			do
			{
				MusicType tempM;
				m_List.GetCurItem(tempM);
				tempA.SetAlbum(tempM.GetAlbum());
				tempA.SetDate(tempM.GetDate());

				AlbumType tempA_(tempM.GetPrimary(), tempM.GetAlbum(), tempM.GetArtist(), tempM.GetDate());
				if (tempA == tempA_)
				{
					if (curAlbum != tempM.GetAlbum())
					{
						tempM.DisplayAlbumOnScreen();
						curAlbum = tempM.GetAlbum();
					}
				}
				m_List.GotoNextItem();
			} while (!m_List.isLastPointer());
		}
		a_List.GotoNextItem();
		cout << endl;
	} while (!a_List.isLastPointer());
	cout << endl << endl;
}
		
void Application::RetreiveRecordByNameNArtistToPlay()
{
	MusicType temp;
	cin.ignore();
	cout << "\t����� ���� ";
	temp.SetArtistFromKB();
	cout << "\t����� ���� ";
	temp.SetNameFromKB();	//SearchByNameToPlay�Լ��� �Ѱ��� temp�� ������ ����� ����ڿ��� �Է¹޴´�.
	cout << endl << endl;
	SearchByNameNArtistToPlay(temp);
	//���������� ����� �ϴ� SearchByNameNArtistToPlay�Լ��� ȣ���ϰ� temp���� �Ѱ��ش�.
}

void Application::SearchByNameNArtistToPlay(MusicType &inData)
{
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� MusicType.
	
	m_List.ResetList();
	r_List.ResetList();

	int count = 0;	// count�� ã�� �׸��� ������ �������ֱ� ���� ����.
	if (m_List.GetLength() != 0)
	{
		for (int i = 0; i < m_List.GetLength(); i++)
		{
			string test; // C:\\ + ���� + . + wav

			m_List.GetCurItem(temp);
			r_List.Get(temp);

			if (temp.GetArtist().find(inData.GetArtist()) != -1 && temp.GetName().find(inData.GetName()) != -1)
			{
				test = "C:\\\\" + temp.GetArtist() + "-" + temp.GetName() + ".wav"; // ���ϸ� �����

				LPCSTR test_ = test.c_str(); // ��ȯ

				if (sndPlaySoundA(test_, SND_ASYNC | SND_NODEFAULT | SND_FILENAME | SND_NOSTOP)) // C����̺꿡 �ִ� ���� ���� ���� + ������ ���� �ȵ�.
				{
					m_List.GetCurItemAddress()->PlayUp();
					cout << "\n\t*���� ������� ��*\n";
					m_List.GetCurItemAddress()->AddCounting();
					r_List.GetCurItemAddress()->AddCounting();
					m_List.GetCurItemAddress()->DisplayRecordOnScreen();
				}
				else // �̹� ���� ��� ���϶�. 
				{
					cout << "\n\t**�̹� ������ ��� ���Դϴ�." << endl;
					cout << "\t**���� ������ �����ϰ� ���ο� ������ ������ּ���." << endl << endl;
				}
				count++;
			}
			m_List.GotoNextItem();
			r_List.GetNextItem(temp);
		}
		m_List.GetCurItem(temp);
		r_List.Get(temp);
	}
	if (count == 0)
		cout << "\n\t**�뷡�� ��Ͽ� �����ϴ�." << endl << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
}

void Application::StopMusic()
{
	cout << "\n\t**������ �����ϼ̽��ϴ�.**\n\n";
	PlaySound(NULL, 0, 0);
}

void Application::PlayMusic()
{
	RetreiveRecordByNameNArtistToPlay();
}

void Application::RetreiveRecordByLyrics()
{
	MusicType temp;
	cout << "\tã�� ";
	cin.ignore();
	temp.SetLyricsFromKB();
	cout << endl << endl;
	SearchByLyrics(temp);
}

void Application::SearchByLyrics(MusicType &inData)
{
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� MusicType.
	m_List.ResetList();
	int count = 0;	// count�� ã�� �׸��� ������ �������ֱ� ���� ����.
	int cnt = 1;

	cout << "\n\n\t***���� ���***" << endl << endl;

	if (m_List.GetLength() != 0)
	{
		m_List.GetCurItem(temp);
		m_List.GotoNextItem();

		if (temp.GetLyrics().find(inData.GetLyrics()) != -1)
		{
			cout << "\tNo." << cnt << endl;
			temp.DisplayPrimaryOnScreen();
			temp.DisplayNameOnScreen();
			temp.DisplayArtistOnScreen();
			temp.DisplayLyricsOnScreen();
			cout << endl;

			count++;	//ã�� ������ 1 �÷��ش�.
			cnt++;
		}
		while (!m_List.isLastPointer())	//List�� ������ �����ϸ� -1�� �����ϹǷ� �ݺ��� �����.
		{
			m_List.GetCurItem(temp);
			if (temp.GetLyrics().find(inData.GetLyrics()) != -1)	//find�Լ������� ��ġ�ϴ� �׸��� �������� ������ -1�� �����ϹǷ� -1�� �ƴϸ� ��ġ�ϴ� ���ڿ��� �ִ°��̴�.
			{
				//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
				cout << "\tNo." << cnt << endl;
				temp.DisplayPrimaryOnScreen();
				temp.DisplayNameOnScreen();
				temp.DisplayArtistOnScreen();
				temp.DisplayLyricsOnScreen();
				cout << endl;

				count++;	//ã�� ������ 1 �÷��ش�.
				cnt++;
			}
			m_List.GotoNextItem();	//���� item���� �ű�
		}
	}
	cin.clear();
	if (count == 0)
		cout << "\tã�� �� �����ϴ�." << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
	else
		cout << "\n\tã�� �� �� : " << count << "��" << endl << endl;
}

// �ֱ� �߰��� 10�� ���
void Application::DisplayRecentMusic()
{
	MusicType data;
	int no = 1;
	int cnt = r_List.GetLength();
	r_List.ResetList();

	r_List.GetNextItem(data);
	if (cnt == 0 || cnt > 20)
		cout << "\n\t**�߰��� ���� �����ϴ�." << endl << endl;
	else
	{
		if(cnt >= 10)
			cout << "\n\t***�ֱ� �߰��� " << 10 << "��***" << endl << endl;
		else
			cout << "\n\t***�ֱ� �߰��� " << cnt << "��***" << endl << endl;

		for (int i = 0; i < 10; i++)
		{
			if (cnt >= MAXSIZE_ || i >= cnt)
				break;
			cout << "\tNo." << i + 1 << endl;
			data.DisplayRecordOnScreen();
			r_List.GetNextItem(data);
			no++;
		}
	}
	cout << endl << endl;
}
/*
// ��� Ƚ���� ���� 10�� ���
void Application::DisplayPlayMusic()
{
	PlayType data;
	int no = 1;
	int cnt = p_List.GetLength();

	p_List.ResetList();
	p_List.GetNextItem(data);
	
	if (cnt == 0 || cnt > pMAXSIZE)
		cout << "\n\t**����� ���� �����ϴ�." << endl << endl;
	else
	{
		if (cnt >= 10)
			cout << "\n\t***�ֱ� ����� " << 10 << "��***" << endl << endl;
		else
			cout << "\n\t***�ֱ� ����� " << cnt << "��***" << endl << endl;

		for (int i = 0; i < 10; i++)
		{
			if (cnt >= pMAXSIZE || i >= cnt)
				break;

			cout << "\tNo." << i + 1 << endl;
			data.DisplayRecordOnScreen();
			p_List.GetNextItem(data);
			no++;
		}
	}
	cout << endl << endl;
	
}
*/