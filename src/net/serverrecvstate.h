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
/* State of network server. */

#ifndef _SERVERRECVSTATE_H_
#define _SERVERRECVSTATE_H_

#include <net/connectdata.h>
#include <playerdata.h>

#define SERVER_INITIAL_STATE	ServerRecvStateInit
#define SERVER_START_GAME_STATE	ServerRecvStateStartGame

class Game;
class PlayerInterface;
class ServerRecvThread;
class ServerCallback;

class ServerRecvState
{
public:
	virtual ~ServerRecvState();

	// Handling of a new TCP connection.
	virtual void HandleNewConnection(ServerRecvThread &server, boost::shared_ptr<ConnectData> connData) = 0;

	// Main processing function of the current state.
	virtual int Process(ServerRecvThread &server) = 0;
};

// State: Initialization.
class ServerRecvStateInit : public ServerRecvState
{
public:
	// Access the state singleton.
	static ServerRecvStateInit &Instance();

	virtual ~ServerRecvStateInit();

	// 
	virtual void HandleNewConnection(ServerRecvThread &server, boost::shared_ptr<ConnectData> data);

	// 
	virtual int Process(ServerRecvThread &server);

protected:

	// Protected constructor - this is a singleton.
	ServerRecvStateInit();

private:

	unsigned		m_curUniquePlayerId;
};

// State: Start server game.
class ServerRecvStateStartGame : public ServerRecvState
{
public:
	// Access the state singleton.
	static ServerRecvStateStartGame &Instance();

	virtual ~ServerRecvStateStartGame();

	// 
	virtual void HandleNewConnection(ServerRecvThread &server, boost::shared_ptr<ConnectData> data);

	// 
	virtual int Process(ServerRecvThread &server);

protected:

	// Protected constructor - this is a singleton.
	ServerRecvStateStartGame();
};

// State: Start new hand.
class ServerRecvStateStartHand : public ServerRecvState
{
public:
	// Access the state singleton.
	static ServerRecvStateStartHand &Instance();

	virtual ~ServerRecvStateStartHand();

	// 
	virtual void HandleNewConnection(ServerRecvThread &server, boost::shared_ptr<ConnectData> data);

	// 
	virtual int Process(ServerRecvThread &server);

protected:

	// Protected constructor - this is a singleton.
	ServerRecvStateStartHand();
};

// State: Start new round.
class ServerRecvStateStartRound : public ServerRecvState
{
public:
	// Access the state singleton.
	static ServerRecvStateStartRound &Instance();

	virtual ~ServerRecvStateStartRound();

	// 
	virtual void HandleNewConnection(ServerRecvThread &server, boost::shared_ptr<ConnectData> data);

	// 
	virtual int Process(ServerRecvThread &server);

protected:

	// Protected constructor - this is a singleton.
	ServerRecvStateStartRound();

	void GameRun(Game &curGame, int state);
	PlayerInterface *GetCurrentPlayer(Game &curGame);
};

// State: Final.
class ServerRecvStateFinal : public ServerRecvState
{
public:
	// Access the state singleton.
	static ServerRecvStateFinal &Instance();

	virtual ~ServerRecvStateFinal();

	// 
	virtual void HandleNewConnection(ServerRecvThread &server, boost::shared_ptr<ConnectData> data);

	// 
	virtual int Process(ServerRecvThread &server);

protected:

	// Protected constructor - this is a singleton.
	ServerRecvStateFinal();
};

#endif
