#pragma once

#include <iostream>
#include <string>
#include "MusicType.h"
using namespace std;

/**
*	SimplifiedType class.
*/
class SimplifiedType
{
private:
	string s_Name;///<°î¸í
	string s_Primary;///<°î °íÀ¯¹øÈ£
	string s_Artist;///<°¡¼ö
public:
	/**
	*	default constructor.
	*/
	SimplifiedType()
	{
		s_Primary = "";
		s_Name = "";
		s_Artist = "";
	}

	/**
	*	destructor.
	*/
	~SimplifiedType() {}

	/**
	*	constructor.
	*/
	SimplifiedType(string inArtist, string inPrimary,string inName )
	{

		s_Artist = inArtist;
		s_Primary = inPrimary;
		s_Name = inName;
	}

	/**
	*	@brief	Get Artist
	*	@pre	Artist is set.
	*	@post	none.
	*	@return	Artist;
	*/
	string GetArtist()
	{
		return s_Artist;
	}

	/**
	*	@brief	Get primary
	*	@pre	Primary is set.
	*	@post	none.
	*	@return	Primary;
	*/
	string GetPrimary()
	{
		return s_Primary;
	}

	/**
*	@brief	Get name
*	@pre	Name is set.
*	@post	none.
*	@return	Name;
*/
	string getName()
	{
		return s_Name;
	}

	/**
	*	@brief	Set name
	*	@pre	none.
	*	@post	Name is set.
	*	@param	inName		Name
	*/
	void setName(string inName)
	{
		s_Name = inName;
	}

	/**
	*	@brief	Set primary
	*	@pre	none.
	*	@post	Primary is set.
	*	@param	inPrimary		Primary
	*/
	void setPrimary(string inPrimary)
	{
		s_Primary = inPrimary;
	}

	/**
	*	@brief	Set Artist
	*	@pre	none.
	*	@post	Artist is set.
	*	@param	inArtist		Artist
	*/
	void setArtist(string inArtist)
	{
		s_Artist = inArtist;
	}

	/**
	*	@brief	Set record
	*	@pre	none.
	*	@post	Record is set
	*	@param	inName			Name
	*	@param	inPrimary		Primary
	*	@param	inArtist		Artist
	*/
	void SetRecord(string inName, string inPrimary, string inArtist)
	{
		setPrimary(inPrimary);
		setName(inName);
		setArtist(inArtist);
	}

	/**
	*	Compare two MusicTypes.
	*	@brief	Compare two item types by item num.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.s_Primary < data.s_Primary,
	*			return GREATER if this.s_Primary > data.s_Primary then,
	*			otherwise return EQUAL.
	*/
	RelationType CompareByPri(const SimplifiedType &data)
	{
		if (this->s_Primary > data.s_Primary)
			return GREATER;
		else if (this->s_Primary < data.s_Primary)
			return LESS;
		else
			return EQUAL;
	};

	/**
	*	@brief	Compare two item types by primary.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.Primary > data.Primary, 0 if not.
	*/
	bool operator>(SimplifiedType data)
	{
		return (this->s_Primary > data.GetPrimary());
	};

	/**
	*	@brief	Compare two item types by primary.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.Primary = data.Primary, 0 if not.
	*/
	bool operator==(SimplifiedType data)
	{
		return (this->s_Primary == data.GetPrimary());
	}

	/**
	*	@brief	Display an record on screen.
	*	@pre	Record is set.
	*	@post	Record is on screen.
	*/
	void DisplayRecordOnScreen()
	{
		cout << "\tPrimary Key : " << s_Primary << endl;
		cout << "\tName : " << s_Name << endl;
	}
};