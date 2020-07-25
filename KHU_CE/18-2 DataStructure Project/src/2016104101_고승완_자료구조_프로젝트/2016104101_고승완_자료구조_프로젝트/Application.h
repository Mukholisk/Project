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
	*	@brief	객체를 생성 후, 문자열을 입력받는다.
	*	@pre	없다.
	*	@post	SearchByName함수에 문자열이 설정된 객체를 전달한다.
	*	@return	없다.
	*/
	void RetreiveRecordByName();

	/**
	*	@brief	inData의 이름 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 이름 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	이름이 설정되어있고 나머지는 비어있는 Musictype
	*	@return	없다.
	*/
	void SearchByName(MusicType &inData);

	/**
	*	@brief	객체를 생성 후, 문자열을 입력받는다.
	*	@pre	없다.
	*	@post	SearchByArtist함수에 문자열이 설정된 객체를 전달한다.
	*	@return	없다.
	*/
	void RetreiveRecordByArtist();

	/**
	*	@brief	inData의 이름 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 이름 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	이름이 설정되어있고 나머지는 비어있는 Musictype
	*	@return	없다.
	*/
	void SearchByArtist(MusicType &inData);

	/**
	*	@brief	객체를 생성 후, 문자열을 입력받는다.
	*	@pre	없다.
	*	@post	SearchByAlbum함수에 문자열이 설정된 객체를 전달한다.
	*	@return	없다.
	*/
	void RetreiveRecordByAlbum();

	/**
	*	@brief	inData의 이름 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 이름 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	이름이 설정되어있고 나머지는 비어있는 Musictype
	*	@return	없다.
	*/
	void SearchByAlbum(MusicType &inData);

	/**
	*	@brief	사용자에게 Name을 입력받아 SortedList의 Delete함수에 넘겨주는 역할을 한다.
	*	@pre	없다.
	*	@post	사용자가 입력한 Name을 가지고 있는 Musictype이 m_List에서 사라진다.
	*	@return	없다.
	*/
	void Delete();

	/**
	*	@brief	사용자에게 Name을 입력받아 SortedList의 Replace함수에 넘겨주는 역할을 한다.
	*	@pre	없다.
	*	@post	사용자가 입력한 Name을 가지고 있는 MusicType을 다시 입력받아 갱신한다.
	*	@return	없다.
	*/
	void Update();

	/**
	*	@brief	Primary key를 이용해 원하는 음악정보를 가져온다.
	*	@pre	리스트가 초기화되어야함.
	*	@post	inData에 원하는 곡정보가 담김
	*	@return	찾으면 1, 아니면 0
	*	@param  key 곡번호를 찾기위한 int형 변수
	*	@param	inData 저장될 data
	*/
	bool Search(string key, MusicType& inData);

	/**
	*	@brief	아티스트 리스트에 있는 곡들을 아티스트에 맞춰 출력
	*	@pre	없다.
	*	@post	없다.
	*	@return	없다.
	*/
	void DisplayMusicbyArtist();

	/**
	*	@brief	객체를 생성 후, 문자열을 입력받는다.
	*	@pre	없다.
	*	@post	SearchByNameNArtist함수에 문자열이 설정된 객체를 전달한다.
	*	@return	없다.
	*/
	void RetreiveRecordByNameNArtist();

	/**
	*	@brief	inData의 이름 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 이름 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	이름이 설정되어있고 나머지는 비어있는 Musictype
	*	@return	없다.
	*/
	void SearchByNameNArtist(MusicType &inData);

	/**
	*	@brief	MusicList에 있는 곡을 앨범 별로 출력한다.
	*	@pre	없다.
	*	@post	없다.
	*	@return	없다.
	*/
	void DisplayMusicbyAlbum();

	/**
	*	@brief	앨범을 가수 별로 출력한다.
	*	@pre	없다.
	*	@post	없다.
	*	@return	없다.
	*/
	void DisplayAlbumbyArtist();

	/**
	*	@brief	앨범을 곡명과 가수를 입력받아 재생한다.(DB에 있으면 재생됨)
	*	@pre	없다.
	*	@post	노래 정보
	*	@return	없다.
	*/
	void PlayMusic();

	/**
	*	@brief	음악이 재생 중이면 끈다.
	*	@pre	음악이 재생 상태
	*	@post	음악을 끔
	*	@return	없다.
	*/
	void StopMusic();

	/**
	*	@brief	객체를 생성 후, 문자열을 입력받는다.
	*	@pre	없다.
	*	@post	SearchByNameNArtistToPlay함수에 문자열이 설정된 객체를 전달한다.
	*	@return	없다.
	*/
	void RetreiveRecordByNameNArtistToPlay();

	/**
	*	@brief	inData의 이름 부분을 포함하는 문자열을 찾아 재생한다.
	*	@pre	inData의 이름 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	이름이 설정되어있고 나머지는 비어있는 Musictype
	*	@return	없다.
	*/
	void SearchByNameNArtistToPlay(MusicType &inData);

	/**
	*	@brief	객체를 생성 후, 문자열을 입력받는다.
	*	@pre	없다.
	*	@post	SearchByLyrics함수에 문자열이 설정된 객체를 전달한다.
	*	@return	없다.
	*/
	void RetreiveRecordByLyrics();

	/**
	*	@brief	inData의 문자열 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 가사 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	이름이 설정되어있고 나머지는 비어있는 Musictype
	*	@return	없다.
	*/
	void SearchByLyrics(MusicType &inData);

	/**
	*	@brief	r_List에 있는 곡을 출력한다.
	*	@pre	없다.
	*	@post	없다.
	*	@return	없다.
	*/
	void DisplayRecentMusic();

	/**
	*	@brief	p_List에 있는 곡을 앨범 별로 출력한다.
	*	@pre	없다.
	*	@post	없다.
	*	@return	없다.
	*/
	void DisplayPlayMusic();

private:
	FILE *m_InFile;			///< input file descriptor.
	FILE *m_OutFile;		///< output file descriptor.
	SortedLinkedList<MusicType> m_List;		/// 노래 리스트
	ArtistType a_list[5];	///< 아티스트 리스트
	UnsortedArrayList<MusicType> r_List;	///< 최근 추가 곡
	//SortedArrayList<PlayType> p_List;		///< 플레이 리스트
	int m_Command;			///< main command number.
	int m_CommandSec;		/// Manege command number
	int m_CommandSec_;		/// Player command number
	int m_CommandThi;		/// View command number
	int m_CommandThi_;		/// Search command number
};

#endif	// _APPLICATION_H

//정의부

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
			cout << "\n\n\t잘못된 입력입니다...\n\n";
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
	cout << "\t*   SG워너비 Player 입니다.   *" << endl;
	cout << "\t*      메인 화면 입니다.      *" << endl;
	cout << "\t*******************************" << endl;
	cout << endl;
	cout << "\t---No--- 기  능 ------ " << endl;
	cout << "\t   1 : 음악 관리" << endl;
	cout << "\t   2 : 음악 플레이어" << endl;
	cout << "\t   0 : 종료" << endl;
	
	cout << endl << "\t 원하는 기능을 선택하세요--> ";

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
				cout << "\n\n\t**목록이 비어있습니다. 추가 후 이용해주세요." << endl << endl;
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
			cout << "\n\n\t잘못된 입력입니다...\n\n";
			break;
		}
	}
}

int Application::GetCommandManagement()
{
	int command2;
	cout << endl;
	cout << "\t*******************************" << endl;
	cout << "\t*    음악 관리 메뉴입니다.    *" << endl;
	cout << "\t*                             *" << endl;
	cout << "\t*******************************" << endl;
	cout << endl;
	cout << "\t---No--- 기  능 ------ " << endl;
	cout << "\t   1 : 음악 추가" << endl;
	cout << "\t   2 : 음악 삭제" << endl;
	cout << "\t   3 : 음악 갱신" << endl;
	cout << "\t   4 : 음악 목록 보기" << endl;
	cout << "\t   5 : 음악 목록 저장" << endl;
	cout << "\t   6 : 음악 목록 불러오기" << endl;
	cout << "\t   0 : 뒤로 가기(메인 화면)" << endl;

	cout << endl << "\t 원하는 기능을 선택하세요--> ";
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
			cout << "\n\n\t잘못된 입력입니다...\n\n";
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
		cout << "\t*    음악 목록 보기입니다.    *" << endl;
		cout << "\t*여러 기준으로 볼 수 있습니다.*" << endl;
		cout << "\t*******************************" << endl;
		cout << endl;
		cout << "\t---No--- 보  기 ------ " << endl;
		cout << "\t   1 : 전체 출력" << endl;
		cout << "\t   2 : 가수별 출력" << endl;
		cout << "\t   3 : 앨범별 출력" << endl;
		cout << "\t   4 : 가수별 앨범 출력" << endl;
		cout << "\t   5 : 최근 추가한 10곡 출력" << endl;
		//cout << "\t   6 : 재생횟수가 많은 10곡 출력" << endl;
		cout << "\t   0 : 뒤로 가기(음악 관리)" << endl;
		cout << endl << "\t 원하는 기능을 선택하세요--> ";
		cin >> command3;
		cout << endl;

		return command3;
	}
	else
	{
		cout << "\n\t**목록이 비어있습니다. 추가 후 이용해주세요." << endl << endl;
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
				cout << "\n\t**목록이 비어있습니다. 추가 후 이용해주세요." << endl << endl;
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
			cout << "\n\t잘못된 입력입니다...\n\n";
			break;
		}
	}
}

int Application::GetCommandPlayer()
{
	int command4;
	cout << endl;
	cout << "\t*******************************" << endl;
	cout << "\t*    음악 플레이어입니다.     *" << endl;
	cout << "\t*                             *" << endl;
	cout << "\t*******************************" << endl;
	cout << endl;
	cout << "\t---No--- 기  능 ------ " << endl;
	cout << "\t   1 : 음악 재생" << endl;
	cout << "\t   2 : 음악 멈춤" << endl;
	cout << "\t   3 : 음악 검색" << endl;
	cout << "\t   0 : 뒤로 가기" << endl;
	
	cout << endl << "\t 원하는 기능을 선택하세요--> ";
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
			cout << "\n\t잘못된 입력입니다...\n\n";
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
		cout << "\t*    음악 검색 메뉴 입니다.   *" << endl;
		cout << "\t*                             *" << endl;
		cout << "\t*******************************" << endl;
		cout << endl;

		cout << "\t---No--- 검  색 ------ " << endl;
		cout << "\t   1 : 곡명으로 검색" << endl;
		cout << "\t   2 : 가수로 검색" << endl;
		cout << "\t   3 : 앨범으로 검색" << endl;
		cout << "\t   4 : 곡명과 제목으로 검색" << endl;
		cout << "\t   5 : 가사로 검색" << endl;
		cout << "\t   0 : 뒤로 가기(음악 플레이어)" << endl;
		cout << endl << "\t 원하는 기능을 선택하세요--> ";
		
		cin >> command5;
		cout << endl << endl;

		return command5;
	}
	else
	{
		cout << "\n\n\t**목록이 비어있습니다. 추가 후 이용해주세요." << endl << endl;
		return 0;
	}
}

// Add new record into list.
int Application::AddMusic()
{
	string artist;	///< 가수를 저장할 임시변수
	string name;	///< 곡명을 저장할 임시변수
	string primary; ///< 고유키를 저장할 임시변수
	int num;		///< 곡번호를 저장할 임시변수

	//MusicList에 추가
	MusicType item;
	item.SetRecordFromKB();

	if (m_List.Add(item))
	{
		//ArtistType에 추가
		SimplifiedType SimpleType;
		primary = item.GetPrimary();
		num = item.GetNum();
		name = item.GetName();
		artist = item.GetArtist();

		// 0->SG워너비, 1->채동하, 2->김진호, 3->이석훈, 4->김용준
		if (artist == "SG워너비")
		{
			SimplifiedType s_temp(artist, primary, name);
			a_list[0].addListinArtist(s_temp);
		}
		else if (artist == "채동하")
		{
			SimplifiedType s_temp(artist, primary, name);
			a_list[1].addListinArtist(s_temp);
		}
		else if (artist == "김진호")
		{
			SimplifiedType s_temp(artist, primary, name);
			a_list[2].addListinArtist(s_temp);
		}
		else if (artist == "이석훈")
		{
			SimplifiedType s_temp(artist, primary, name);
			a_list[3].addListinArtist(s_temp);
		}
		else if (artist == "김용준")
		{
			SimplifiedType s_temp(artist, primary, name);
			a_list[4].addListinArtist(s_temp);
		}

		// 최근 추가
		r_List.Add(item);
		/*
		PlayType data()
		data.SetArtist(item.GetArtist());
		data.SetName(item.GetName());
		data.SetPlay(item.GetPlay());
		
		p_List.Add(data);*/

		cout << "\n\n\t***추가되었습니다.\n" << endl;
		return 1;
	}
	else
	{
		cout << "\n\n\t**중복된 값이 있어 추가할 수 없습니다." << endl << endl;
		return 0;
	}
	cout << endl << endl;

}

// Display all records in the list on screen.
void Application::DisplayAllMusic()
{
	MusicType data;
	int cnt = 1;

	cout << "\n\n\t***전체 곡 목록***" << endl << endl;

	// list의 모든 데이터를 화면에 출력
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

	cout << "\t총 " << cnt-1 << "곡\n\n";
}

//찾을 Primary를 사용자에게 입력받고 SortedList의 Delete함수를 호출한다.
void Application::Delete()
{
	cout << "\t지울 ";
	MusicType data;	//Delete함수는 MusicType을 파라미터로 갖기 때문에 임의로 만들어준다.
	data.SetPriFromKB();	//사용자에게서 Primary값을 입력받는다.

	if (m_List.Delete(data))	//Delete함수에 data를 넘겨준다.
	{
		string temp = data.GetPrimary();
		char StrToCha = temp[8];
		int tempPri = StrToCha - '0';

		SimplifiedType SimpleType;
		int num = data.GetNum();
		string name = data.GetName();
		string artist = data.GetArtist();

		// 1->SG워너비, 2->채동하, 3->김진호, 4->이석훈, 5->김용준
		if (tempPri == 1)
		{
			SimplifiedType s_temp(artist, temp, name);
			a_list[0].setAArtist("SG워너비");
			a_list[0].deleteListinArtist(s_temp);
		}
		else if (tempPri == 2)
		{
			SimplifiedType s_temp(artist, temp, name);
			a_list[1].setAArtist("채동하");
			a_list[1].deleteListinArtist(s_temp);
		}
		else if (tempPri == 3)
		{
			SimplifiedType s_temp(artist, temp, name);
			a_list[2].setAArtist("김진호");
			a_list[2].deleteListinArtist(s_temp);
		}
		else if (tempPri == 4)
		{
			SimplifiedType s_temp(artist, temp, name);
			a_list[3].setAArtist("이석훈");
			a_list[3].deleteListinArtist(s_temp);
		}
		else if (tempPri == 5)
		{
			SimplifiedType s_temp(artist, temp, name);
			a_list[4].setAArtist("김용준");
			a_list[4].deleteListinArtist(s_temp);
		}
		// 최근 목록에서 삭제
		r_List.Delete(data);
	}
	else
	{
		cout << "\n\n\t일치하는 항목을 찾을 수 없습니다." << endl << endl;	//삭제에 실패했으면 메시지를 출력한다.
		return;
	}
	cout << "\n\n\t삭제를 완료했습니다." << endl << endl;	//삭제에 성공했으면 메시지를 출력한다.
}

//찾을 Primary를 사용자에게 입력받고 SortedList의 Update함수를 호출한다.
void Application::Update()
{
	cout << "\t!!! 알림 !!! \n";
	cout << "\t!!! 발매년월일와 가수와 트랙 번호를 바꾸고 싶은 경우 삭제 후 추가해주세요.\n";

	cout << "\n\n\t변경을 원하는 항목의 ";
	MusicType data;	//Replace함수는 MusicType을 파라미터로 갖기 때문에 임의로 만들어준다.
	data.SetPriFromKB();	//사용자에게서 수정할 항목의 Primary을 입력받는다.
	cin.ignore();
	if (!m_List.Get(data))	//사용자가 입력한 항목이 List에 있나 검색
	{
		cout << "\n\t***항목을 찾을 수 없습니다." << endl << endl;		//찾을 수 없을때 메시지를 출력한다.
		return;
	}
	else	//찾을 수 있을때
	{
		cout << "\n\t***곡을 찾았습니다." << endl << endl << endl;
		data.DisplayNameOnScreen();
		cout << "\n\t변경을 원하는 항목의 ";
		data.SetNameFromKB();	//사용자에게서 곡명을 입력받는다.
		cout << "\t변경을 원하는 항목의 ";
		data.SetAlbumFromKB();	//사용자에게서 앨범을 입력받는다.
		cout << "\t변경을 원하는 항목의 ";
		data.SetLyricsFromKB(); ;//사용자에게서 가사를 입력받는다.

		if (m_List.Replace(data)) //Replace함수에 data를 넘겨준다.
		{
			r_List.Replace(data);

			string temp = data.GetPrimary();
			char StrToCha = temp[8];
			int tempPri = StrToCha - '0';

			SimplifiedType SimpleType;
			string name = data.GetName();
			string artist = data.GetArtist();

			// 1->SG워너비, 2->채동하, 3->김진호, 4->이석훈, 5->김용준
			if (tempPri == 1)
			{
				SimplifiedType SimpleType(artist, temp, name);
				a_list[0].setAArtist("SG워너비");
				a_list[0].replaceListinArtist(SimpleType);
			}
			else if (tempPri == 2)
			{
				SimplifiedType SimpleType(artist, temp, name);
				a_list[1].setAArtist("채동하");
				a_list[1].replaceListinArtist(SimpleType);
			}
			else if (tempPri == 3)
			{
				SimplifiedType SimpleType(artist, temp, name);
				a_list[2].setAArtist("김진호");
				a_list[2].replaceListinArtist(SimpleType);
			}
			else if (tempPri == 4)
			{
				SimplifiedType SimpleType(artist, temp, name);
				a_list[3].setAArtist("이석훈");
				a_list[3].replaceListinArtist(SimpleType);
			}
			else if (tempPri == 5)
			{
				SimplifiedType SimpleType(artist, temp, name);
				a_list[4].setAArtist("김용준");
				a_list[4].replaceListinArtist(SimpleType);
			}

			cout << "\n\n\t***수정을 완료했습니다." << endl << endl;	//수정을 성공했을 때 메시지를 출력한다.
		}
		else
			cout << "\n\n\t**수정에 실패했습니다." << endl << endl;	//수정에 실패했을 때 메시지를 출력한다.
	}
}

//사용자에게 찾고자하는 Name을 입력받고 넘겨주는 역할을 한다.
void Application::RetreiveRecordByName()
{
	cin.ignore();
	MusicType temp;
	cout << "\t찾을 ";
	temp.SetNameFromKB();	//SearchByName함수에 넘겨줄 temp의 Name을 사용자에게 입력받는다.
	SearchByName(temp);	//실질적으로 찾는 동작을 하는 SearchByName함수를 호출하고 temp값을 넘겨준다.
	cout << endl << endl;
}

//사용자가 찾고자하는 Name을 포함하는 inData로 m_List의 항목들 중 일치하는 항목을 찾고 출력해준다. **프로그램에 전반적으로 Array에 index를 직접 접근하는 방법을 선호했으나 이 함수는 Application 클래스의 메소드이므로 GetNextItem함수를 이용해 iteration을 이용했습니다.
void Application::SearchByName(MusicType &inData)
{
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 MusicType.
	m_List.ResetList();
	int count = 0;	// count는 찾은 항목의 개수를 저장해주기 위한 변수.
	
	cout << endl << endl << "\n\n\t***음악 목록***" << endl << endl;
	if (m_List.GetLength() != 0)
	{
		m_List.GetCurItem(temp);
		m_List.GotoNextItem();

		if (temp.GetName().find(inData.GetName()) != -1)
		{
			temp.DisplayRecordOnScreen();
			count++;
		}

		while (!m_List.isLastPointer())	//List의 끝까지 도달하면 -1을 리턴하므로 반복을 멈춘다.
		{
			m_List.GetCurItem(temp);
			if (temp.GetName().find(inData.GetName()) != -1)	//find함수에서는 일치하는 항목이 존재하지 않을때 -1을 리턴하므로 -1이 아니면 일치하는 문자열이 있는것이다.
			{
				temp.DisplayRecordOnScreen();	//일치하는 문자열을 포함하는 temp의 내용을 출력한다.
				count++;	//찾은 개수를 1 늘려준다.
			}
			m_List.GotoNextItem();	//다음 item으로 옮김
		}
	}
	if (count == 0)
		cout << "\n\t**찾을 수 없습니다.";	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
		cout << endl << endl;
}

//사용자에게 찾고자하는 Artist을 입력받고 넘겨주는 역할을 한다.
void Application::RetreiveRecordByArtist()
{
	MusicType temp;
	cout << "\t찾을 ";
	cin.ignore();
	temp.SetArtistFromKB();	//SearchByArtist함수에 넘겨줄 temp의 Name을 사용자에게 입력받는다.
	SearchByArtist(temp);	//실질적으로 찾는 동작을 하는 SearchByArtist함수를 호출하고 temp값을 넘겨준다.
	cout << endl << endl;
}


//사용자가 찾고자하는 Artist을 포함하는 inData로 m_List의 항목들 중 일치하는 항목을 찾고 출력해준다. **프로그램에 전반적으로 Array에 index를 직접 접근하는 방법을 선호했으나 이 함수는 Application 클래스의 메소드이므로 GetNextItem함수를 이용해 iteration을 이용했습니다.
void Application::SearchByArtist(MusicType &inData)
{
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 MusicType.
	m_List.ResetList();
	int count = 0;	//count는 찾은 항목의 개수를 저장해주기 위한 변수.

	cout << endl << endl << "\n\n\t***음악 목록***" << endl << endl;
	if (m_List.GetLength() != 0)
	{
		m_List.GetCurItem(temp);
		m_List.GotoNextItem();

		if (temp.GetArtist().find(inData.GetArtist()) != -1)
		{
			temp.DisplayRecordOnScreen();
			count++;
		}

		while (!m_List.isLastPointer())	//List의 끝까지 도달하면 -1을 리턴하므로 반복을 멈춘다.
		{
			m_List.GetCurItem(temp);
			if (temp.GetArtist().find(inData.GetArtist()) != -1)	//find함수에서는 일치하는 항목이 존재하지 않을때 -1을 리턴하므로 -1이 아니면 일치하는 문자열이 있는것이다.
			{
				temp.DisplayRecordOnScreen();	//일치하는 문자열을 포함하는 temp의 내용을 출력한다.
				count++;	//찾은 개수를 1 늘려준다.
			}
			m_List.GotoNextItem();
		}
	}
	if (count == 0)
		cout << "\n\t**찾을 수 없습니다." << endl << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
	else
		cout << "\n\t***" << inData.GetArtist() << " 음악 목록 " << count << "곡을 찾았습니다.***" << endl << endl;
}

//사용자에게 찾고자하는 Album을 입력받고 넘겨주는 역할을 한다.
void Application::RetreiveRecordByAlbum()
{
	MusicType temp;
	cout << "\t찾을 ";
	cin.ignore();
	temp.SetAlbumFromKB();	//SearchByAlbum함수에 넘겨줄 temp의 Album을 사용자에게 입력받는다.
	SearchByAlbum(temp);	//실질적으로 찾는 동작을 하는 SearchByAlbum함수를 호출하고 temp값을 넘겨준다.
	cout << endl << endl;
}


//사용자가 찾고자하는 Album을 포함하는 inData로 m_List의 항목들 중 일치하는 항목을 찾고 출력해준다. **프로그램에 전반적으로 Array에 index를 직접 접근하는 방법을 선호했으나 이 함수는 Application 클래스의 메소드이므로 GetNextItem함수를 이용해 iteration을 이용했습니다.
void Application::SearchByAlbum(MusicType &inData)
{
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 MusicType.
	m_List.ResetList();
	int count = 0;	//count는 찾은 항목의 개수를 저장해주기 위한 변수.
	
	cout << endl << endl << "\t***음악 목록***" << endl << endl << endl;
	
	if (m_List.GetLength() != 0)
	{
		m_List.GetCurItem(temp);
		m_List.GotoNextItem();

		string curAlbum = "";
		string curArtist = "";
		int curDate = -1;

		if (temp.GetAlbum().find(inData.GetAlbum()) != -1)
		{
			// 앨범정보
			cout << "\t앨범 : " << temp.GetAlbum() << "(가수 : " << temp.GetArtist() << ")" << endl;
			cout << "\t발매일자 : " << temp.GetDate() << endl << endl << endl;

			curAlbum = temp.GetAlbum();
			curArtist = temp.GetArtist();
			curDate = temp.GetDate();

			// 곡정보
			temp.DisplayNumOnScreen();
			temp.DisplayPrimaryOnScreen();
			temp.DisplayNameOnScreen();
			cout << endl;
			count++;
		}
		while (!m_List.isLastPointer())	//List의 끝까지 도달하면 -1을 리턴하므로 반복을 멈춘다.
		{
			m_List.GetCurItem(temp);
			if (temp.GetAlbum().find(inData.GetAlbum()) != -1)	//find함수에서는 일치하는 항목이 존재하지 않을때 -1을 리턴하므로 -1이 아니면 일치하는 문자열이 있는것이다.
			{
				if (curAlbum != temp.GetAlbum() && curArtist != temp.GetArtist() && curDate != temp.GetDate())
				{
					// 앨범정보
					cout << "\t앨범 : " << temp.GetAlbum() << "(가수 : " << temp.GetArtist() << ")" << endl;
					cout << "\t발매일자 : " << temp.GetDate() << endl << endl << endl;

					curAlbum = temp.GetAlbum();
					curArtist = temp.GetArtist();
					curDate = temp.GetDate();
				}

				// 곡정보
				temp.DisplayNumOnScreen();
				temp.DisplayPrimaryOnScreen();
				temp.DisplayNameOnScreen();
				cout << endl;
				count++;	//찾은 개수를 1 늘려준다.
			}
			m_List.GotoNextItem();
		}
	}
	if (count == 0)
		cout << "\n\t**찾을 수 없습니다." << endl << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
	else
		cout << "\n\t***앨범 수록곡 수 : " << count << "곡" << endl << endl;
}

// Open a file by file descriptor as an input file.
int Application::OpenInFile()
{
	m_InFile = fopen("C:\\mukho.txt", "r");	// file open for reading.

	// return 1 if file opened, not 0.
	if (m_InFile == NULL)
	{
		cout << "\n\t**불러올 수 없습니다. C Drive에 있는 mukho.txt 파일을 확인해보세요." << endl << endl;
		return 0;
	}
	else
		return 1;
}

// Open a file by file descriptor as an output file.
int Application::OpenOutFile()
{
	fopen_s(&m_OutFile, "C:\\mukho.txt", "w");// file open for writing.

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (m_OutFile == NULL)
	{
		cout << "\n\t**저장할 수 없습니다. C Drive에 있는 mukho.txt 파일을 확인해보세요."<< endl;
		cout << "\t**프로그램을 관리자 권한으로 실행하세요." << endl << endl;
		return 0;
	}
	else
		return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int cnt = 0;
	MusicType data;	// 읽기용 임시 변수

	// C:\mukho.txt 파일을 연다.

	// file open, open error가 발생하면 0을 리턴
	if (!OpenInFile())
	{
		cout << "\n\t**세이브 파일이 없습니다." << endl << endl;
		return 0;
	}
	// 파일의 모든 내용을 읽어 list에 추가
	while (!feof(m_InFile))
	{
		// 파일에서 불러온 정보를 저장할 임시 변수
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

		// 불러오기
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
			cout << "\n\t**파일이 비어있어 불러올 수 없습니다." << endl << endl;
			break;
		}

		// 변환
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

		// data에 저장
		data.SetPrimary(tracknum_, artist, date_);
		data.SetName(name);
		data.SetArtist(artist);
		data.SetAlbum(album);
		data.SetNum(tracknum_);
		data.SetDate(date_);
		data.SetLyrics(lyrics);
		data.SetPlay(play_);

		// 리스트에 저장
		m_List.Add(data);

		// ArtistType에 추가
		SimplifiedType SimpleType;

		string t_artist;	///< 가수를 저장할 임시변수
		string t_name;	///< 곡명을 저장할 임시변수
		string t_primary; ///< 고유키를 저장할 임시변수
		int t_num;		///< 곡번호를 저장할 임시변수

		t_primary = data.GetPrimary();
		t_num = data.GetNum();
		t_name = data.GetName();
		t_artist = data.GetArtist();

		// 0->SG워너비, 1->채동하, 2->김진호, 3->이석훈, 4->김용준
		if (t_artist == "SG워너비")
		{
			SimplifiedType s_temp(t_artist,t_primary,t_name);
			a_list[0].addListinArtist(s_temp);
		}
		else if (t_artist == "채동하")
		{
			SimplifiedType s_temp(t_artist, t_primary, t_name);
			a_list[1].addListinArtist(s_temp);
		}
		else if (t_artist == "김진호")
		{
			SimplifiedType s_temp(t_artist, t_primary, t_name);
			a_list[2].addListinArtist(s_temp);
		}
		else if (t_artist == "이석훈")
		{
			SimplifiedType s_temp(t_artist, t_primary, t_name);
			a_list[3].addListinArtist(s_temp);
		}
		else if (t_artist == "김용준")
		{
			SimplifiedType s_temp(t_artist, t_primary, t_name);
			a_list[4].addListinArtist(s_temp);
		}
		cnt++;

		r_List.Add(data);
	}

	fclose(m_InFile);	// file close


	cout << "\n\t***불러오기가 완료되었습니다." << endl << endl;

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	MusicType data;	// 쓰기용 임시 변수

	if (m_List.GetLength() == 0)
	{
		cout << "\t***데이터가 없어 저장할 수 없습니다." << endl;
		return 0;
	}

	// C:\mukho.txt 파일을 연다.

	// file open, open error가 발생하면 0을 리턴
	if (!OpenOutFile())
		return 0;

	// list 포인터를 초기화
	m_List.ResetList();

	do
	{
		m_List.GetCurItem(data);
		
		// 저장용 임시 변수
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

		// 변환
		strcpy(primary, data.GetPrimary().c_str());
		strcpy(name, data.GetName().c_str());
		strcpy(artist, data.GetArtist().c_str());
		strcpy(album, data.GetAlbum().c_str());
		tracknum_ = data.GetNum();
		date_ = data.GetDate();
		strcpy(lyrics, data.GetLyrics().c_str());
		play_ = data.GetPlay();

		// 변환 (int형 변수룰 char*로 바꿈)
		_itoa(tracknum_, tracknum, 10);
		_itoa(date_, date, 10);
		_itoa(play_, play, 10);

		// 파일에 입력
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

		// 다음 데이터
		m_List.GotoNextItem();

		// 항목이 더 있으면 구분을 위해 '\n' 추가 입력
		if(!m_List.isLastPointer())
			fputs("\n\n", m_OutFile);
	} while (!m_List.isLastPointer());

	fclose(m_OutFile);	// file close

	cout << "\t***저장되었습니다." << endl;
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
	
	cout << "\n\t***음악 목록***\n\n";
	for (int i = 0; i < 5; i++)
	{
		a_list[i].PrintAll();
	}
}

//name 과 artist 정보를 받아 Search함수에 넘긴다.
void Application::RetreiveRecordByNameNArtist()
{
	MusicType temp;
	cin.ignore();
	cout << "\t찾을 곡의 ";
	temp.SetNameFromKB();
	cout << "\t찾을 곡의 ";
	temp.SetArtistFromKB();	//SearchByArtist함수에 넘겨줄 temp의 Artist을 사용자에게 입력받는다.
	SearchByNameNArtist(temp);	//실질적으로 찾는 동작을 하는 SearchByArtist함수를 호출하고 temp값을 넘겨준다.
	cout << endl << endl;
}

void Application::SearchByNameNArtist(MusicType& inData)
{
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 MusicType.
	m_List.ResetList();
	m_List.GetCurItem(temp);
	m_List.GotoNextItem();

	int count = 0;	// count는 찾은 항목의 개수를 저장해주기 위한 변수.
	if (m_List.GetLength() != 0)
	{
		cout << endl << endl << "\t***음악 목록***" << endl << endl;
		if (temp.GetArtist().find(inData.GetArtist()) != -1 && temp.GetName().find(inData.GetName()) != -1)
		{
			temp.DisplayRecordOnScreen();
			count++;
		}
		while (!m_List.isLastPointer())	//List의 끝까지 도달하면 -1을 리턴하므로 반복을 멈춘다.
		{
			m_List.GetCurItem(temp);
			if (temp.GetArtist().find(inData.GetArtist()) != -1 && temp.GetName().find(inData.GetName()) != -1)
			{
				temp.DisplayRecordOnScreen();	//일치하는 문자열을 포함하는 temp의 내용을 출력한다.
				count++;	//찾은 개수를 1 늘려준다.
			}
			m_List.GotoNextItem();
		}
	}
	if (count == 0)
		cout << "\n\t**찾을 수 없습니다." << endl << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
	else
		cout << endl << endl;
}

void Application::DisplayMusicbyAlbum()
{
	cout << "\n\t***음악 목록***\n\n";
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
			cout << "\n\t**앨범 : " << tempA.GetAlbum() << "(가수 : " << tempA.GetArtist() << ")" << endl;
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
	cout << endl << endl << "\t***음악 목록***\n\n\n";
	if (m_List.GetLength() == 0)
	{
		cout << "\n\t**찾을 수 없습니다.\n\n";
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
		if (tempA.GetArtist() == "SG워너비")
			index = 0;
		else if (tempA.GetArtist() == "채동하")
			index = 1;
		else if (tempA.GetArtist() == "김진호")
			index = 2;
		else if (tempA.GetArtist() == "이석훈")
			index = 3;
		else if (tempA.GetArtist() == "김용준")
			index = 4;
		else
			index = 5;

		if (current[index] < 1)
		{
			cout << "\t**가수 : " << tempA.GetArtist() << endl;
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
	cout << "\t재생할 곡의 ";
	temp.SetArtistFromKB();
	cout << "\t재생할 곡의 ";
	temp.SetNameFromKB();	//SearchByNameToPlay함수에 넘겨줄 temp의 가수와 곡명을 사용자에게 입력받는다.
	cout << endl << endl;
	SearchByNameNArtistToPlay(temp);
	//실질적으로 재생을 하는 SearchByNameNArtistToPlay함수를 호출하고 temp값을 넘겨준다.
}

void Application::SearchByNameNArtistToPlay(MusicType &inData)
{
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 MusicType.
	
	m_List.ResetList();
	r_List.ResetList();

	int count = 0;	// count는 찾은 항목의 개수를 저장해주기 위한 변수.
	if (m_List.GetLength() != 0)
	{
		for (int i = 0; i < m_List.GetLength(); i++)
		{
			string test; // C:\\ + 가수 + . + wav

			m_List.GetCurItem(temp);
			r_List.Get(temp);

			if (temp.GetArtist().find(inData.GetArtist()) != -1 && temp.GetName().find(inData.GetName()) != -1)
			{
				test = "C:\\\\" + temp.GetArtist() + "-" + temp.GetName() + ".wav"; // 파일명 만들기

				LPCSTR test_ = test.c_str(); // 변환

				if (sndPlaySoundA(test_, SND_ASYNC | SND_NODEFAULT | SND_FILENAME | SND_NOSTOP)) // C드라이브에 있는 음악 파일 실행 + 없으면 실행 안됨.
				{
					m_List.GetCurItemAddress()->PlayUp();
					cout << "\n\t*현재 재생중인 곡*\n";
					m_List.GetCurItemAddress()->AddCounting();
					r_List.GetCurItemAddress()->AddCounting();
					m_List.GetCurItemAddress()->DisplayRecordOnScreen();
				}
				else // 이미 곡이 재생 중일때. 
				{
					cout << "\n\t**이미 음악이 재생 중입니다." << endl;
					cout << "\t**기존 음악을 정지하고 새로운 음악을 재생해주세요." << endl << endl;
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
		cout << "\n\t**노래가 목록에 없습니다." << endl << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
}

void Application::StopMusic()
{
	cout << "\n\t**정지를 선택하셨습니다.**\n\n";
	PlaySound(NULL, 0, 0);
}

void Application::PlayMusic()
{
	RetreiveRecordByNameNArtistToPlay();
}

void Application::RetreiveRecordByLyrics()
{
	MusicType temp;
	cout << "\t찾을 ";
	cin.ignore();
	temp.SetLyricsFromKB();
	cout << endl << endl;
	SearchByLyrics(temp);
}

void Application::SearchByLyrics(MusicType &inData)
{
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 MusicType.
	m_List.ResetList();
	int count = 0;	// count는 찾은 항목의 개수를 저장해주기 위한 변수.
	int cnt = 1;

	cout << "\n\n\t***음악 목록***" << endl << endl;

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

			count++;	//찾은 개수를 1 늘려준다.
			cnt++;
		}
		while (!m_List.isLastPointer())	//List의 끝까지 도달하면 -1을 리턴하므로 반복을 멈춘다.
		{
			m_List.GetCurItem(temp);
			if (temp.GetLyrics().find(inData.GetLyrics()) != -1)	//find함수에서는 일치하는 항목이 존재하지 않을때 -1을 리턴하므로 -1이 아니면 일치하는 문자열이 있는것이다.
			{
				//일치하는 문자열을 포함하는 temp의 내용을 출력한다.
				cout << "\tNo." << cnt << endl;
				temp.DisplayPrimaryOnScreen();
				temp.DisplayNameOnScreen();
				temp.DisplayArtistOnScreen();
				temp.DisplayLyricsOnScreen();
				cout << endl;

				count++;	//찾은 개수를 1 늘려준다.
				cnt++;
			}
			m_List.GotoNextItem();	//다음 item으로 옮김
		}
	}
	cin.clear();
	if (count == 0)
		cout << "\t찾을 수 없습니다." << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
	else
		cout << "\n\t찾은 곡 수 : " << count << "곡" << endl << endl;
}

// 최근 추가한 10곡 출력
void Application::DisplayRecentMusic()
{
	MusicType data;
	int no = 1;
	int cnt = r_List.GetLength();
	r_List.ResetList();

	r_List.GetNextItem(data);
	if (cnt == 0 || cnt > 20)
		cout << "\n\t**추가된 곡이 없습니다." << endl << endl;
	else
	{
		if(cnt >= 10)
			cout << "\n\t***최근 추가된 " << 10 << "곡***" << endl << endl;
		else
			cout << "\n\t***최근 추가된 " << cnt << "곡***" << endl << endl;

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
// 재생 횟수가 많은 10곡 출력
void Application::DisplayPlayMusic()
{
	PlayType data;
	int no = 1;
	int cnt = p_List.GetLength();

	p_List.ResetList();
	p_List.GetNextItem(data);
	
	if (cnt == 0 || cnt > pMAXSIZE)
		cout << "\n\t**재생한 곡이 없습니다." << endl << endl;
	else
	{
		if (cnt >= 10)
			cout << "\n\t***최근 재생된 " << 10 << "곡***" << endl << endl;
		else
			cout << "\n\t***최근 재생된 " << cnt << "곡***" << endl << endl;

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