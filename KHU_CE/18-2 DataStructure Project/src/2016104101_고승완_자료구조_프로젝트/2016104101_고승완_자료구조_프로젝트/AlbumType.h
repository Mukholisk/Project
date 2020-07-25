#pragma once
#include "SimplifiedType.h"
#include "SortedLinkedList.h"

/**
*	AlbumType class.
*/
class AlbumType
{
private:
	string a_Primary;	///< 고유번호
	string a_Album;		///< 앨범명
	string a_Artist;	///< 가수명
	int a_Date;			///< 날짜
public:
	/**
	*	default constructor.
	*/
	AlbumType()
	{
		a_Primary = "";
		a_Album = "";
		a_Artist = "";
		a_Date = -1;
	}

	/**
	*	destructor.
	*/
	~AlbumType() {}

	/**
	*	constructor.
	*/
	AlbumType(string inPrimary, string inAlbum, string inArtist, int inDate)
	{
		a_Primary = inPrimary;
		a_Album = inAlbum;
		a_Artist = inArtist;
		a_Date = inDate;
	}

	/**
	*	@brief	Set primary
	*	@pre	none.
	*	@post	Primary is set.
	*	@param	inPrimary	 Primary
	*/
	void SetPrimary(string inPrimary)
	{
		a_Primary = inPrimary;
	}

	/**
	*	@brief	Set album
	*	@pre	none.
	*	@post	Album is set.
	*	@param	inAlbum	 Album
	*/
	void SetAlbum(string inAlbum)
	{
		a_Album = inAlbum;
	}

	/**
	*	@brief	Set artist
	*	@pre	none.
	*	@post	Artist is set.
	*	@param	inArtist	 Artist
	*/
	void SetArtist(string inArtist)
	{
		a_Artist = inArtist;
	}

	/**
	*	@brief	Set date
	*	@pre	none.
	*	@post	Date is set.
	*	@param	inDate	 inDate
	*/
	void SetDate(int inDate)
	{
		a_Date = inDate;
	}

	/**
	*	@brief	Get primary
	*	@pre	Primary is set.
	*	@post	none.
	*	@return	Primary;
	*/
	string GetPrimary()
	{
		return a_Primary;
	}

	/**
	*	@brief	Get album
	*	@pre	Album is set.
	*	@post	none.
	*	@return	Album;
	*/
	string GetAlbum()
	{
		return a_Album;
	}

	/**
	*	@brief	Get artist
	*	@pre	Artist is set.
	*	@post	none.
	*	@return	Artist;
	*/
	string GetArtist()
	{
		return a_Artist;
	}

	/**
	*	@brief	Get date
	*	@pre	Date is set.
	*	@post	none.
	*	@return	Date;
	*/
	int GetDate()
	{
		return a_Date;
	}

	/**
	*	@brief	Compare two item types by album.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.Primary < data.Primary, 0 if not.
	*/
	bool operator<(AlbumType data)
	{
		return (this->a_Primary < data.GetPrimary());
	};

	/**
	*	@brief	Compare two item types by album.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.Primary > data.Primary, 0 if not.
	*/
	bool operator>(AlbumType data)
	{
		return (this->a_Primary > data.GetPrimary());
	};

	/**
	*	@brief	Compare two item types by album.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.Album = data.Album, 0 if not.
	*/
	bool operator==(AlbumType data)
	{
		return (this->a_Album == data.GetAlbum() && this->a_Artist == data.GetArtist() && this->a_Date == data.GetDate());
	}

	/**
	*	Compare two MusicTypes.
	*	@brief	Compare two item types by item num.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.a_Primary < data.a_Primary,
	*			return GREATER if this.a_Primary > data.a_Primary then,
	*			otherwise return EQUAL.
	*/
	RelationType CompareByPri(const AlbumType &data)
	{
		if (this->a_Primary > data.a_Primary)
			return GREATER;
		else if (this->a_Primary < data.a_Primary)
			return LESS;
		else
			return EQUAL;
	};
};