/***************************************************************************
 *   Copyright (C) 2007 by Lothar May                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
/* Player data. */

#ifndef _PLAYERDATA_H_
#define _PLAYERDATA_H_

#include <string>
#include <list>
#include <boost/shared_ptr.hpp>

enum PlayerType
{
	PLAYER_TYPE_COMPUTER,
	PLAYER_TYPE_HUMAN
};

class PlayerData
{
public:
	PlayerData();
	~PlayerData();

	const std::string &GetName() const
	{return m_name;}
	void SetName(const std::string &name)
	{m_name = name;}
	const std::string &GetAvatarFile() const
	{return m_avatarFile;}
	void SetAvatarFile(const std::string &avatarFile)
	{m_avatarFile = avatarFile;}
	PlayerType GetType() const
	{return m_type;}
	void SetPlayerType(PlayerType type)
	{m_type = type;}

private:
	std::string	m_name;
	std::string	m_avatarFile;
	PlayerType	m_type;
};

typedef std::list<boost::shared_ptr<PlayerData> > PlayerDataList;

#endif

