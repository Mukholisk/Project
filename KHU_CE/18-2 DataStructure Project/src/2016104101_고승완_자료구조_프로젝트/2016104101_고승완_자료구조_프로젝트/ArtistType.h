#pragma once
#include <iostream>
#include <string>
#include "SimplifiedType.h"
#include "SortedLinkedList.h"
#include "MusicType.h"
using namespace std;

/**
*	ArtistType class.
*/
class ArtistType
{
public:
	/**
	*	default constructor.
	*/
	ArtistType()
	{
		a_Primary = "";
		a_Name = "";
		a_Artist = "";
	}

	/**
	*	default constructor.
	*/
	ArtistType(string inPrimary, string inName, string inArtist)
	{
		a_Primary = "";
		a_Name = "";
		a_Artist = "";
	}

	/**
	*	destructor.
	*/
	~ArtistType() {}

	/**
	*	@brief	Set Primary
	*	@pre	none.
	*	@post	Primary is set.
	*	@param	inPrimary	 Primary
	*/
	void setAPrimary(string inPrimary)
	{
		a_Primary = inPrimary;
	}

	/**
	*	@brief	Set Name
	*	@pre	none.
	*	@post	Name is set.
	*	@param	inName	 Name
	*/
	void setAName(string inName)
	{
		a_Name = inName;
	}

	/**
	*	@brief	Set Artist
	*	@pre	none.
	*	@post	Artist is set.
	*	@param	inArtist	 Artist
	*/
	void setAArtist(string inArtist)
	{
		a_Artist = inArtist;
	}

	/**
	*	@brief	Get primary
	*	@pre	none.
	*	@post	Primary is set.
	*	@return	Primary.
	*/
	string getAPrimary()
	{
		return a_Primary;
	}

	/**
	*	@brief	Get Name
	*	@pre	none.
	*	@post	Name is set.
	*	@param	Name
	*/
	string getAName()
	{
		return a_Name;
	}

	/**
	*	@brief	Get Artist
	*	@pre	none.
	*	@post	Artist is set.
	*	@return	Artist.
	*/
	string getAArtist()
	{
		return a_Artist;
	}

	/**
	*	@brief	Artist별로 data를 저장한다.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*/
	void addListinArtist(SimplifiedType &data)
	{
		s_List.Add(data);
	}

	/**
	*	@brief	Artist별로 data를 삭제한다.
	*	@pre	list should be initialized.
	*	@post	deleted the new record into the list.
	*	@param	data	지울 data.
	*/
	void deleteListinArtist(SimplifiedType &data)
	{
		s_List.Delete(data);
	}

	/**
	*	@brief	Artist별로 data를 수정한다.
	*	@pre	list should be initialized.
	*	@post	updateed the new record into the list.
	*	@param	data	new data.
	*/
	void replaceListinArtist(SimplifiedType &data)
	{
		s_List.Replace(data);
	}

	/**
	*	@brief	Compare two item types by album date.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.Primary < data.Primary, 0 if not.
	*/
	bool operator<(ArtistType data)
	{
		return (a_Primary < data.a_Primary);
	};

	/**
	*	@brief	Compare two item types by album date.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.Primary > data.Primary, 0 if not.
	*/
	bool operator>(ArtistType data)
	{
		return (a_Primary > data.a_Primary);
	};

	/**
	*	@brief	Compare two item types by album date.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.Primary == data.Primary, 0 if not.
	*/
	bool operator==(ArtistType data)
	{
		if (a_Primary == data.a_Primary)
			return true;
		else
			return false;
	};

	/**
	*	@brief	Compare two item types by artist.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.Artist = data.Artist, 0 if not.
	*/
	ArtistType operator=(const ArtistType& data)
	{
		this->a_Artist = data.a_Artist;
		this->s_List = data.s_List;
		return *this;
	};

	/**
	*	@brief	Display all list on screen.
	*	@pre	list is set.
	*	@post	All list is on screen.
	*/
	void PrintAll()
	{
		SimplifiedType temp;
		s_List.GetFirstItem(temp);
		if (temp.GetPrimary() == "")
			return;

		cout << "\n\t**가수 : " << temp.GetArtist() << endl;
		temp.DisplayRecordOnScreen();
		while (!s_List.isLastPointer())
		{
			s_List.GetCurItem(temp);
			s_List.GotoNextItem();
			temp.DisplayRecordOnScreen();
		}
		cout << endl;
	}

	/**
	*	@brief	Display album list by artist on screen.
	*	@pre	list is set.
	*	@post	Album list by artist is on screen.
	*/
	void PrintAlbumList()
	{
		SimplifiedType temp;
		s_List.GetFirstItem(temp);
		if (temp.GetPrimary() == "")
			return;
		cout << "\n\t가수 : " << a_Artist << endl;
		temp.DisplayRecordOnScreen();
		while (!s_List.isLastPointer())
		{
			s_List.GetCurItem(temp);
			s_List.GotoNextItem();
			temp.DisplayRecordOnScreen();
		}
	}

	/**
	*	Compare two MusicTypes.
	*	@brief	Compare two item types by item primary.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.a_Primary < data.a_Primary,
	*			return GREATER if this.a_Primary > data.a_Primary then,
	*			otherwise return EQUAL.
	*/
	RelationType CompareByNum(const ArtistType &data)
	{
		if (this->a_Primary > data.a_Primary)
			return GREATER;
		else if (this->a_Primary < data.a_Primary)
			return LESS;
		else
			return EQUAL;
	}

private:
	string a_Artist;	///< 가수
	SortedLinkedList<SimplifiedType> s_List;
	string a_Primary;	///< 고유번호
	string a_Name;		///< 곡몀
};