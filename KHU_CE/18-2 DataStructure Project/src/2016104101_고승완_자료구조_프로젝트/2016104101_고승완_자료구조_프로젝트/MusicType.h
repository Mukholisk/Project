#pragma once
#ifndef _MusicType_H
#define _MusicType_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
*	�� ����Ű�� ���ϱ� ���� ��
*/
enum RelationType { LESS, GREATER, EQUAL };


/**
*	�� ���� Ŭ����
*/
class MusicType
{
public:
	/**
	*	������
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
	*	�Ҹ���
	*/
	~MusicType() {}

	/**
	*	@brief	������ȣ�� ��ȯ��
	*	@pre	m_Primary�� ���ǵ��־�� ��.
	*	@post	����.
	*	@return	������ȣ
	*/
	string GetPrimary()
	{
		return m_Primary;
	}

	/**
	*	@brief	Ʈ�������� ��ȯ
	*	@pre	m_Num�� ���ǵ��־�� ��.
	*	@post	����.
	*	@return	Ʈ������;
	*/
	int GetNum()
	{
		return m_Num;
	}

	/**
	*	@brief	����� ��ȯ
	*	@pre	m_Name�� ���ǵ��־�� ��.
	*	@post	����.
	*	@return	m_Name;
	*/
	string GetName()
	{
		return m_Name;
	}

	/**
	*	@brief	������ ��ȯ
	*	@pre	m_Artist�� ���̵��־�� ��.
	*	@post	����.
	*	@return	m_Artist.
	*/
	string GetArtist()
	{
		return m_Artist;
	}

	/**
	*	@brief	�ٹ��̸��� ��ȯ
	*	@pre	m_Album�� ���ǵ��־�� ��.
	*	@post	����.
	*	@return	m_Album.
	*/
	string GetAlbum()
	{
		return m_Album;
	}

	/**
	*	@brief	�߸����� ��ȯ
	*	@pre	m_Date�� ���ǵ��־�� ��.
	*	@post	����.
	*	@return	m_Date.
	*/
	int GetDate()
	{
		return m_Date;
	}

	/**
	*	@brief	���縦 ��ȯ
	*	@pre	m_Lyrics�� ���ǵ��־�� ��.
	*	@post	����.
	*	@return	m_Lyrics.
	*/
	string GetLyrics()
	{
		return m_Lyrics;
	}

	/**
	*	@brief	���Ƚ���� ��ȯ
	*	@pre	m_Play�� ���ǵ��־�� ��.
	*	@post	����.
	*	@return	m_Play;
	*/
	int GetPlay()
	{
		return m_Play;
	}

	/**
	*	@brief	Ʈ���ѹ��� ����
	*	@pre	����.
	*	@post	m_Num�� ���ǵ�.
	*	@param	inNum	Num
	*/
	void SetNum(int inNum)
	{
		m_Num = inNum;
	}

	/**
	*	@brief	����� ����
	*	@pre	����.
	*	@post	m_Name�� ���ǵ�.
	*	@param	inName	 Name
	*/
	void SetName(string inName)
	{
		m_Name = inName;
	}

	/**
	*	@brief	�������� ����
	*	@pre	����.
	*	@post	m_Artist�� ������.
	*	@param	inArtist	Artist
	*/
	void SetArtist(string inArtist)
	{
		m_Artist = inArtist;
	}

	/**
	*	@brief	�ٹ��� ����
	*	@pre	����.
	*	@post	m_Album�� ������.
	*	@param	inAlbum		Album
	*/
	void SetAlbum(string inAlbum)
	{
		m_Album = inAlbum;
	}

	/**
	*	@brief	�߸����� ����
	*	@pre	����.
	*	@post	m_Date�� ������.
	*	@param	inDate		Date
	*/
	void SetDate(int inDate)
	{
		m_Date = inDate;
	}

	/**
	*	@brief	���縦 ����
	*	@pre	����.
	*	@post	m_Lyrics�� ������.
	*	@param	inLyrics	 Lyrics
	*/
	void SetLyrics(string inLyrics)
	{
		m_Lyrics = inLyrics;
	}

	/**
	*	@brief	�� ������ȣ�� ����
	*	@pre	����.
	*	@post	m_Primary�� ������.
	*	@param	inPrimary	 Primary
	*/
	void SetPri(string inPrimary)
	{
		m_Primary = inPrimary;
	}

	/**
	*	@brief	���Ƚ���� ����
	*	@pre	����.
	*	@post	m_Play�� ������.
	*	@param	inPlay		Play
	*/
	void SetPlay(int inPlay)
	{
		m_Play = inPlay;
	}

	/**
	*	@brief	������ȣ�� ����� ����
	*	@pre	m_Date, m_Artist, m_Num�� ���ǵ��־�� ��.
	*	@post	�� ������ȣ�� �������
	*	@param	inNum		Num
	*	@param	inDate		Date
	*	@param  inArtist	Artist
	*/
	void SetPrimary(int inNum, string inArtist, int inDate)
	{
		m_Primary = "";
		string tString; // int�� ������ string ������ ��ȯ�ϱ� ���� �ӽ� ���� ����

		tString = to_string(inDate);
		m_Primary += tString;

		if (inArtist == "SG���ʺ�")
			m_Primary += "1";
		else if (inArtist == "ä����")
			m_Primary += "2";
		else if (inArtist == "����ȣ")
			m_Primary += "3";
		else if (inArtist == "�̼���")
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
	*	@brief	�� ������ ����
	*	@pre	����.
	*	@post	�� ������ ������
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
	*	@brief	�� ������ȣ�� ���
	*	@pre	m_Primary�� ���ǵ��־�� ��
	*	@post	�� ������ȣ�� ȭ�鿡 ��µ�.
	*/
	void DisplayPrimaryOnScreen()
	{
		cout << "\t�� ������ȣ : " << m_Primary << endl;
	}

	/**
	*	@brief	�ٹ������� �� ������ ���
	*	@pre	m_Num�� ���ǵ��־�� ��
	*	@post	�� ������ ȭ�鿡 ��µ�.
	*/
	void DisplayNumOnScreen()
	{
		cout << "\tƮ�� ���� : " << m_Num << endl;
	}

	/**
	*	@brief	��� ���
	*	@pre	m_Name�� ���ǵ��־�� ��
	*	@post	����� ȭ�鿡 ��µ�.
	*/
	void DisplayNameOnScreen()
	{
		cout << "\t��� : " << m_Name << endl;
	}

	/**
	*	@brief	������ ���
	*	@pre	m_Artist�� ���ǵ��־�� ��
	*	@post	������ ȭ�鿡 ��µ�.
	*/
	void DisplayArtistOnScreen()
	{
		cout << "\t���� : " << m_Artist << endl;
	}

	/**
	*	@brief	�ٹ��� ���
	*	@pre	m_Album�� ���ǵ��־�� ��
	*	@post	�ٹ��� ȭ�鿡 ��µ�.
	*/
	void DisplayAlbumOnScreen()
	{
		cout << "\t�ٹ� : " << m_Album << endl;
	}

	/**
	*	@brief	�߸����� ���
	*	@pre	m_Date�� ���ǵ��־�� ��
	*	@post	�߸����� ȭ�鿡 ��µ�.
	*/
	void DisplayDateOnScreen()
	{
		cout << "\t�߸��� : " << m_Date << endl;
	}

	/**
	*	@brief	Display lyrics on screen.
	*	@pre	Lyrics is set.
	*	@post	Lyrics is on screen.
	*/
	void DisplayLyricsOnScreen()
	{
		cout << "\t���� : " << m_Lyrics << endl;
	};

	/**
	*	@brief	Display Play count on screen.
	*	@pre	Play is set.
	*	@post	Play Count is on screen.
	*/
	void DisplayPlayOnScreen()
	{
		cout << "\t���Ƚ�� : " << m_Play << endl;
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
	*	@brief	���Ƚ���� ������Ŵ
	*	@pre	�� ������ ���ǵ��־�� ��.
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
	string m_Primary;		 ///< �� ������ȣ [ primary key : �ٹ��ڵ�(�߸�����8�ڸ�) + �����ڵ�(1�ڸ�) + ���ȣ(2�ڸ�) ]
	string m_Name;			 ///< ���
	string m_Artist;		 ///< ����
	string m_Album;			 ///< �ٹ�
	int m_Num;				 ///< �ٹ� �������� ���ȣ
	int m_Date;				 ///< �߸ų����
	string m_Lyrics;		 ///< ����
	int m_Play;				 ///< ��� Ƚ��
};

#endif	// _MusicType_H

// Set Primary from keyboard.
void MusicType::SetPriFromKB()
{
	cout << "\t�� ������ȣ : ";
	cin >> m_Primary;
}

// Set Number from keyboard.
void MusicType::SetNumFromKB()
{
	cout << "\tƮ�� ���� : ";
	cin >> m_Num;
}

// Set Name from keyboard.
void MusicType::SetNameFromKB()
{
	cout << "\t��� : ";
	cin.clear();
	getline(cin, m_Name);
}

// Set Artist from keyboard.
void MusicType::SetArtistFromKB()
{
	while (1)
	{
		cout << "\tArtist(SG���ʺ�, ä����, ����ȣ, �̼���, �����) : ";
		getline(cin, m_Artist);
		if (m_Artist == "SG���ʺ�" || m_Artist == "ä����" || m_Artist == "����ȣ" || m_Artist == "�̼���" || m_Artist == "�����")
			break;
		else
			cout << "\t�߸��� �Է��Դϴ�." << endl;
	}
}

// Set Album from keyboard.
void MusicType::SetAlbumFromKB()
{
	cout << "\t�ٹ� : ";
	cin.clear();
	getline(cin, m_Album);
}
// Set Date from keyboard
void MusicType::SetDateFromKB()
{
	cout << "\t��¥(yyyymmdd) : ";
	cin >> m_Date;
}

// Set Lyrics from keyboard
void MusicType::SetLyricsFromKB()
{
	cout << "\t���� : ";
	//cin.ignore();
	getline(cin, m_Lyrics);
	cout << "  ";
}

void MusicType::PlayUp()
{
	cout << "\n\t***������ ����մϴ�***\n\n";
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