#pragma once
#ifndef _MusicType_H
#define _MusicType_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
*	두 고유키를 비교하기 위한 것
*/
enum RelationType { LESS, GREATER, EQUAL };


/**
*	곡 정보 클래스
*/
class MusicType
{
public:
	/**
	*	생성자
	*/
	MusicType()
	{
		m_Primary = "";
		m_Num = -1;
		m_Name = "";
		m_Artist = "";
		m_Album = "";
		m_Date = -1;
		m_Lyrics = "";
		m_Play = 0;
	}

	/**
	*	소멸자
	*/
	~MusicType() {}

	/**
	*	@brief	고유번호를 반환함
	*	@pre	m_Primary가 정의되있어야 함.
	*	@post	없음.
	*	@return	고유번호
	*/
	string GetPrimary()
	{
		return m_Primary;
	}

	/**
	*	@brief	트랙순서를 반환
	*	@pre	m_Num가 정의되있어야 함.
	*	@post	없음.
	*	@return	트랙순서;
	*/
	int GetNum()
	{
		return m_Num;
	}

	/**
	*	@brief	곡명을 반환
	*	@pre	m_Name가 정의되있어야 함.
	*	@post	없음.
	*	@return	m_Name;
	*/
	string GetName()
	{
		return m_Name;
	}

	/**
	*	@brief	가수를 반환
	*	@pre	m_Artist가 정이되있어야 함.
	*	@post	없음.
	*	@return	m_Artist.
	*/
	string GetArtist()
	{
		return m_Artist;
	}

	/**
	*	@brief	앨범이름을 반환
	*	@pre	m_Album가 정의되있어야 함.
	*	@post	없음.
	*	@return	m_Album.
	*/
	string GetAlbum()
	{
		return m_Album;
	}

	/**
	*	@brief	발매일을 반환
	*	@pre	m_Date가 정의되있어야 함.
	*	@post	없음.
	*	@return	m_Date.
	*/
	int GetDate()
	{
		return m_Date;
	}

	/**
	*	@brief	가사를 반환
	*	@pre	m_Lyrics가 정의되있어야 함.
	*	@post	없음.
	*	@return	m_Lyrics.
	*/
	string GetLyrics()
	{
		return m_Lyrics;
	}

	/**
	*	@brief	재생횟수를 반환
	*	@pre	m_Play가 정의되있어야 함.
	*	@post	없음.
	*	@return	m_Play;
	*/
	int GetPlay()
	{
		return m_Play;
	}

	/**
	*	@brief	트랙넘버를 설정
	*	@pre	없음.
	*	@post	m_Num가 정의됨.
	*	@param	inNum	Num
	*/
	void SetNum(int inNum)
	{
		m_Num = inNum;
	}

	/**
	*	@brief	곡명을 설정
	*	@pre	없음.
	*	@post	m_Name가 정의됨.
	*	@param	inName	 Name
	*/
	void SetName(string inName)
	{
		m_Name = inName;
	}

	/**
	*	@brief	가수명을 설정
	*	@pre	없음.
	*	@post	m_Artist가 설정됨.
	*	@param	inArtist	Artist
	*/
	void SetArtist(string inArtist)
	{
		m_Artist = inArtist;
	}

	/**
	*	@brief	앨범을 설정
	*	@pre	없음.
	*	@post	m_Album가 설정됨.
	*	@param	inAlbum		Album
	*/
	void SetAlbum(string inAlbum)
	{
		m_Album = inAlbum;
	}

	/**
	*	@brief	발매일을 설정
	*	@pre	없음.
	*	@post	m_Date가 설정됨.
	*	@param	inDate		Date
	*/
	void SetDate(int inDate)
	{
		m_Date = inDate;
	}

	/**
	*	@brief	가사를 설정
	*	@pre	없음.
	*	@post	m_Lyrics가 설정됨.
	*	@param	inLyrics	 Lyrics
	*/
	void SetLyrics(string inLyrics)
	{
		m_Lyrics = inLyrics;
	}

	/**
	*	@brief	곡 고유번호를 설정
	*	@pre	없음.
	*	@post	m_Primary가 설정됨.
	*	@param	inPrimary	 Primary
	*/
	void SetPri(string inPrimary)
	{
		m_Primary = inPrimary;
	}

	/**
	*	@brief	재생횟수를 설정
	*	@pre	없음.
	*	@post	m_Play가 설정됨.
	*	@param	inPlay		Play
	*/
	void SetPlay(int inPlay)
	{
		m_Play = inPlay;
	}

	/**
	*	@brief	고유번호를 만들어 설정
	*	@pre	m_Date, m_Artist, m_Num이 정의되있어야 함.
	*	@post	곡 고유번호가 만들어짐
	*	@param	inNum		Num
	*	@param	inDate		Date
	*	@param  inArtist	Artist
	*/
	void SetPrimary(int inNum, string inArtist, int inDate)
	{
		m_Primary = "";
		string tString; // int형 변수를 string 변수로 변환하기 위한 임시 변수 선언

		tString = to_string(inDate);
		m_Primary += tString;

		if (inArtist == "SG워너비")
			m_Primary += "1";
		else if (inArtist == "채동하")
			m_Primary += "2";
		else if (inArtist == "김진호")
			m_Primary += "3";
		else if (inArtist == "이석훈")
			m_Primary += "4";
		else
			m_Primary += "5";

		tString = to_string(inNum);
		if (inNum < 10)
		{
			m_Primary += "0";
			m_Primary += tString;
		}
		else
			m_Primary += tString;
	}

	/**
	*	@brief	곡 정보를 만듬
	*	@pre	없음.
	*	@post	곡 정보가 설정됨
	*	@param	inNum		Num
	*	@param	inName		Name
	*	@param	inArtist	Artist
	*	@param	inAlbum		Album
	*	@param	inDate		Date
	*	@param	inLyrics	Lyrics
	*	@param	inPlay		Play
	*/
	void SetRecord(int inNum, string inName, string inArtist, string inAlbum, int inDate, string inLyrics, int inPlay)
	{
		SetPrimary(inNum, inArtist, inDate);
		SetNum(inNum);
		SetName(inName);
		SetArtist(inArtist);
		SetAlbum(inAlbum);
		SetDate(inDate);
		SetLyrics(inLyrics);
		SetPlay(inPlay);
	}

	/**
	*	@brief	곡 고유번호를 출력
	*	@pre	m_Primary가 정의되있어야 함
	*	@post	곡 고유번호가 화면에 출력됨.
	*/
	void DisplayPrimaryOnScreen()
	{
		cout << "\t곡 고유번호 : " << m_Primary << endl;
	}

	/**
	*	@brief	앨범에서의 곡 순서를 출력
	*	@pre	m_Num이 정의되있어야 함
	*	@post	곡 순서가 화면에 출력됨.
	*/
	void DisplayNumOnScreen()
	{
		cout << "\t트랙 순서 : " << m_Num << endl;
	}

	/**
	*	@brief	곡명를 출력
	*	@pre	m_Name이 정의되있어야 함
	*	@post	곡명이 화면에 출력됨.
	*/
	void DisplayNameOnScreen()
	{
		cout << "\t곡명 : " << m_Name << endl;
	}

	/**
	*	@brief	가수를 출력
	*	@pre	m_Artist이 정의되있어야 함
	*	@post	가수가 화면에 출력됨.
	*/
	void DisplayArtistOnScreen()
	{
		cout << "\t가수 : " << m_Artist << endl;
	}

	/**
	*	@brief	앨범을 출력
	*	@pre	m_Album이 정의되있어야 함
	*	@post	앨범이 화면에 출력됨.
	*/
	void DisplayAlbumOnScreen()
	{
		cout << "\t앨범 : " << m_Album << endl;
	}

	/**
	*	@brief	발매일을 출력
	*	@pre	m_Date가 정의되있어야 함
	*	@post	발매일이 화면에 출력됨.
	*/
	void DisplayDateOnScreen()
	{
		cout << "\t발매일 : " << m_Date << endl;
	}

	/**
	*	@brief	Display lyrics on screen.
	*	@pre	Lyrics is set.
	*	@post	Lyrics is on screen.
	*/
	void DisplayLyricsOnScreen()
	{
		cout << "\t가사 : " << m_Lyrics << endl;
	};

	/**
	*	@brief	Display Play count on screen.
	*	@pre	Play is set.
	*	@post	Play Count is on screen.
	*/
	void DisplayPlayOnScreen()
	{
		cout << "\t재생횟수 : " << m_Play << endl;
	};

	/**
	*	@brief	Display an record on screen.
	*	@pre	Record is set.
	*	@post	Record is on screen.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayPrimaryOnScreen();
		DisplayNameOnScreen();
		DisplayArtistOnScreen();
		DisplayAlbumOnScreen();
		DisplayNumOnScreen();
		DisplayDateOnScreen();
		DisplayLyricsOnScreen();
		DisplayPlayOnScreen();
		cout << endl;
	}

	/**
	*	@brief	Display an album list on screen.
	*	@pre	Record is set.
	*	@post	Record is on screen.
	*/
	void DisplayAlbumListOnScreen()
	{
		DisplayNumOnScreen();
		DisplayNameOnScreen();
		DisplayArtistOnScreen();
		DisplayDateOnScreen();
		cout << endl;
	}

	/**
*	@brief	Set primary key from keyboard;
*	@pre	none.
*	@post	Primary Key is set.
*/
	void SetPriFromKB();

	/**
	*	@brief	Set num from keyboard.
	*	@pre	none.
	*	@post	Num is set.
	*/
	void SetNumFromKB();

	/**
	*	@brief	Set name from keyboard.
	*	@pre	none.
	*	@post	Name is set.
	*/
	void SetNameFromKB();

	/**
	*	@brief	Set Artist from keyboard.
	*	@pre	none.
	*	@post	Artist is set.
	*/
	void SetArtistFromKB();

	/**
	*	@brief	Set Album from keyboard.
	*	@pre	none.
	*	@post	Album is set.
	*/
	void SetAlbumFromKB();

	/**
	*	@brief	Set Date from keyboard.
	*	@pre	none.
	*	@post	Date is set.
	*/
	void SetDateFromKB();

	/**
	*	@brief	Set Lyrics from keyboard.
	*	@pre	none.
	*	@post	Lyrics is set.
	*/
	void SetLyricsFromKB();

	/**
	*	@brief	재생횟수를 증가시킴
	*	@pre	곡 정보가 정의되있어야 함.
	*	@post	Play is set.
	*/
	void PlayUp();

	/**
	*	@brief	Set record from keyboard.
	*	@pre	none.
	*	@post	record is set.
	*/
	void SetRecordFromKB();

	/**
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	music record is set.
	*	@param	fin	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new music record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile(ofstream& fout);

	/**
	*	Compare two MusicTypes.
	*	@brief	Compare two item types by item num.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.m_Num < data.m_Num,
	*			return GREATER if this.m_Num > data.m_Num then,
	*			otherwise return EQUAL.
	*/
	RelationType CompareByNum(const MusicType &data)
	{
		if (this->m_Num > data.m_Num)
			return GREATER;
		else if (this->m_Num < data.m_Num)
			return LESS;
		else
			return EQUAL;
	};

	/**
	*	Compare two MusicTypes.
	*	@brief	Compare two item types by item primary.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.m_Primary < data.m_Primary,
	*			return GREATER if this.m_Primary > data.m_Primary then,
	*			otherwise return EQUAL.
	*/
	RelationType CompareByPri(const MusicType &data)
	{
		if (this->m_Primary > data.m_Primary)
			return GREATER;
		else if (this->m_Primary < data.m_Primary)
			return LESS;
		else
			return EQUAL;
	};

	/**
	*	@brief	Compare two item types by music primary kry.
	*	@pre	two item types should be initialized.
	*	@param	item	target item for comparing.
	*	@return	return 1 if this.primary > data.primary, 0 if not.
	*/
	bool operator >(MusicType& item);

	/**
*	@brief	Compare two item types by music primary kry.
*	@pre	two item types should be initialized.
*	@param	item	target item for comparing.
*	@return	return 1 if this.primary < data.primary, 0 if not.
*/
	bool operator <(MusicType& item);

	/**
	*	@brief	Compare two item types by item name.
	*	@pre	two item types should be initialized.
	*	@param	item	target item for comparing.
	*	@return	return 1 if this.primary == data.primary, 0 if not.
	*/
	bool operator ==(MusicType& item);

	/**
	*	@brief	Compare two item types by item name.
	*	@pre	two item types should be initialized.
	*	@param	item	target item for comparing.
	*	@return	return 1 if this.primary = data.primary, 0 if not.
	*/
	MusicType operator=(const MusicType& item);

	/**
	*	Compare two PlayTypes.
	*	@brief	Compare two item types by item play.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.m_Play < data.m_Play,
	*			return GREATER if this.m_Play > data.m_Play then,
	*			otherwise return EQUAL.
	*/
	RelationType CompareByPlay(MusicType &data)
	{
		if (this->m_Play > data.m_Play)
			return GREATER;
		else if (this->m_Play < data.m_Play)
			return LESS;
		else
			return EQUAL;
	};

	/**
	*	@brief	Add Play
	*	@pre	Play is set.
	*	@post	Play is increase.
	*/
	void AddCounting()
	{
		m_Play++;
	}
protected:
	string m_Primary;		 ///< 곡 고유번호 [ primary key : 앨범코드(발매일자8자리) + 가수코드(1자리) + 곡번호(2자리) ]
	string m_Name;			 ///< 곡명
	string m_Artist;		 ///< 가수
	string m_Album;			 ///< 앨범
	int m_Num;				 ///< 앨범 내에서의 곡번호
	int m_Date;				 ///< 발매년월일
	string m_Lyrics;		 ///< 가사
	int m_Play;				 ///< 재생 횟수
};

#endif	// _MusicType_H

// Set Primary from keyboard.
void MusicType::SetPriFromKB()
{
	cout << "\t곡 고유번호 : ";
	cin >> m_Primary;
}

// Set Number from keyboard.
void MusicType::SetNumFromKB()
{
	cout << "\t트랙 순서 : ";
	cin >> m_Num;
}

// Set Name from keyboard.
void MusicType::SetNameFromKB()
{
	cout << "\t곡명 : ";
	cin.clear();
	getline(cin, m_Name);
}

// Set Artist from keyboard.
void MusicType::SetArtistFromKB()
{
	while (1)
	{
		cout << "\tArtist(SG워너비, 채동하, 김진호, 이석훈, 김용준) : ";
		getline(cin, m_Artist);
		if (m_Artist == "SG워너비" || m_Artist == "채동하" || m_Artist == "김진호" || m_Artist == "이석훈" || m_Artist == "김용준")
			break;
		else
			cout << "\t잘못된 입력입니다." << endl;
	}
}

// Set Album from keyboard.
void MusicType::SetAlbumFromKB()
{
	cout << "\t앨범 : ";
	cin.clear();
	getline(cin, m_Album);
}
// Set Date from keyboard
void MusicType::SetDateFromKB()
{
	cout << "\t날짜(yyyymmdd) : ";
	cin >> m_Date;
}

// Set Lyrics from keyboard
void MusicType::SetLyricsFromKB()
{
	cout << "\t가사 : ";
	//cin.ignore();
	getline(cin, m_Lyrics);
	cout << "  ";
}

void MusicType::PlayUp()
{
	cout << "\n\t***음악을 재생합니다***\n\n";
}

// Set Record from keyboard.
void MusicType::SetRecordFromKB()
{
	cin.ignore();
	SetNameFromKB();
	SetArtistFromKB();
	SetAlbumFromKB();
	SetNumFromKB();
	SetDateFromKB();
	cin.ignore();
	SetLyricsFromKB();
	SetPrimary(m_Num, m_Artist, m_Date);
}

// Read a record from file.
int MusicType::ReadDataFromFile(ifstream& fin)
{
	getline(fin, m_Primary);
	getline(fin, m_Name);
	getline(fin, m_Artist);
	getline(fin, m_Album);
	fin >> m_Num;
	fin >> m_Date;
	getline(fin, m_Lyrics);
	fin >> m_Play;
	return 1;
};

// Write a record into file.
int MusicType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_Primary << " ";
	fout << m_Name << " ";
	fout << m_Artist << " ";
	fout << m_Album << " ";
	fout << m_Num << " ";
	fout << m_Date << " ";
	fout << m_Lyrics << " ";
	fout << m_Play << " ";
	return 1;
}

// Compare two item types by item primary.
bool MusicType::operator >(MusicType& item)
{
	return (this->GetPrimary() > item.GetPrimary());
}	//return 1 if this.primary > data.primary, 0 if not.

// Compare two item types by item primary.
bool MusicType::operator <(MusicType& item)
{
	return (this->GetPrimary() < item.GetPrimary());
}	//return 1 if this.primary < data.primary, 0 if not.

// Compare two item types by item primary.
bool MusicType::operator ==(MusicType& item)
{
	return (this->GetPrimary() == item.GetPrimary());
}	//return 1 if this.primary == data.primary, 0 if not.

// Compare two item types by item primary.
 MusicType MusicType::operator =(const MusicType& item)
{
	this->m_Primary = item.m_Primary;
	this->m_Num = item.m_Num;
	this->m_Name = item.m_Name;
	this->m_Artist = item.m_Artist;
	this->m_Album = item.m_Album;
	this->m_Date = item.m_Date;
	this->m_Lyrics = item.m_Lyrics;
	this->m_Play = item.m_Play; m_Play;

	return *this;
}