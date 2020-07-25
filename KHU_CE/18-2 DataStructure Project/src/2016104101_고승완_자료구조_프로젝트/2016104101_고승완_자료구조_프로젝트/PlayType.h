#pragma once

#include <iostream>
#include <string>
#include "MusicType.h"
using namespace std;

/**
*	PlayType class.
*/
class PlayType
{
private:
	string p_Artist; ///< 가수
	string p_Name;   ///< 노래
	int p_Play;		 ///<

public:
	/**
	*	default constructor.
	*/
	PlayType()
	{
		p_Artist = "";
		p_Name = "";
		p_Play = 0;
	}

	/**
	*	destructor.
	*/
	~PlayType() {}

	/**
	*	constructor.
*/	
	PlayType(string inArtist, string inName)
	{
		p_Artist = inArtist;
		p_Name = inName;
	}

	/**
	*	constructor.
	*/
	PlayType(string inArtist, string inName, int inPlay)
	{
		p_Artist = inArtist;
		p_Name = inName;
		p_Play = inPlay;
	}

	/**
	*	@brief	Get Artist
	*	@pre	Artist is set.
	*	@post	none.
	*	@return	Artist;
	*/
	string GetArtist()
	{
		return p_Artist;
	}

	/**
	*	@brief	Get Name
	*	@pre	Name is set.
	*	@post	none.
	*	@return	Name;
	*/
	string GetName()
	{
		return p_Name;
	}

	/**
	*	@brief	Get Play
	*	@pre	Play is set.
	*	@post	none.
	*	@return	Play;
	*/
	int GetPlay()
	{
		return p_Play;
	}

	/**
	*	@brief	Set Play
	*	@pre	none.
	*	@post	Play is set.
	*	@param	inPlay		Play
	*/
	void SetPlay(int inPlay)
	{
		p_Play = inPlay;
	}

	/**
	*	@brief	Set Artist
	*	@pre	none.
	*	@post	Artist is set.
	*	@param	inArtist		Artist
	*/
	void SetArtist(string inArtist)
	{
		p_Artist = inArtist;
	}

	/**
	*	@brief	Set Name
	*	@pre	none.
	*	@post	Name is set.
	*	@param	inName		Name
	*/
	void SetName(string inName)
	{
		p_Name = inName;
	}

	/**
	*	@brief	Set record
	*	@pre	none.
	*	@post	Record is set
	*	@param	inArtist		Artist
	*	@param	inName			Name
	*	@param	inPlay			Play
	*/
	void SetRecord(string inArtist, string inName, int inPlay)
	{
		SetArtist(inArtist);
		SetName(inName);
		SetPlay(inPlay);
	}

	/**
	*	Compare two PlayTypes.
	*	@brief	Compare two item types by item play.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.p_Play < data.p_Play,
	*			return GREATER if this.p_Play > data.p_Play then,
	*			otherwise return EQUAL.
	*/
	RelationType CompareByPlay(const PlayType &data)
	{
		if (this->p_Play > data.p_Play)
			return GREATER;
		else if (this->p_Play < data.p_Play)
			return LESS;
		else
			return EQUAL;
	};

	/**
	*	@brief	Compare two item types by Play.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.p_Play > data.p_Play, 0 if not.
	*/
	bool operator>(PlayType &data)
	{
		return (this->p_Play > data.GetPlay());
	};

	/**
	*	@brief	Compare two item types by Play.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.p_Play < data.p_Play, 0 if not.
	*/
	bool operator<(PlayType &data)
	{
		return (this->p_Play < data.GetPlay());
	};

	/**
	*	@brief	Compare two item types by Play.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.p_Play = data.p_Play, 0 if not.
	*/
	bool operator=(PlayType &data)
	{
		return (this->p_Play = data.GetPlay());
	};

	/**
	*	@brief	Compare two item types by Play.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.p_Play == data.p_Play, 0 if not.
	*/
	bool operator==(PlayType &data)
	{
		return (this->p_Play == data.GetPlay());
	};

	/**
	*	@brief	Display an record on screen.
	*	@pre	Record is set.
	*	@post	Record is on screen.
	*/
	void DisplayRecordOnScreen()
	{
		cout << "\t가수 : " << p_Artist << endl;
		cout << "\t곡명 : " << p_Name << endl;
		cout << "\t재생횟수 : " << p_Play << "회" << endl << endl;
	}

	/**
	*	@brief	Add Play
	*	@pre	Play is set.
	*	@post	Play is increase.
	*/
	void AddCounting()
	{
		p_Play++;
	}
};