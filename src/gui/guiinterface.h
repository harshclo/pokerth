/***************************************************************************
 *   Copyright (C) 2006 by FThauer FHammer   *
 *   f.thauer@web.de   *
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
#ifndef GUIINTERFACE_H
#define GUIINTERFACE_H

// #include <iostream>
#include <string>

class Game;
class Session;
class HandInterface;


class GuiInterface{
public:
	virtual ~GuiInterface();

	
	//set
	virtual void setGame(Game*) =0;
	virtual void setHand(HandInterface*) =0;
	virtual void setSession(Session*) =0;

	//get
	virtual int getMaxQuantityPlayers() const=0;
	virtual std::string getPlayerName(int) const=0;

	
	
	//refresh-Funktionen
	virtual void refreshSet() const=0;
	virtual void refreshChangePlayer() const=0;
	virtual void refreshPot() const=0;
	virtual void refreshGroupbox() const=0;
	virtual void refreshAll() const=0;
	virtual void refreshPlayerName() const=0;

// 	virtual void refreshButton() const=0;

// 	virtual void refreshAction() const=0;
// 	virtual void refreshCash() const=0;

// 	// Karten-Funktionen
	virtual void dealHoleCards() const=0;
	virtual void dealFlopCards() const=0;
	virtual void dealTurnCard() const=0;
	virtual void dealRiverCard() const=0;

	virtual void highlightRoundLabel(std::string) const=0;

	virtual void nextPlayerAnimation() const=0;

	virtual void preflopAnimation1() const=0;
	virtual void preflopAnimation2() const=0;

	virtual void flopAnimation1() const=0;
	virtual void flopAnimation2() const=0;

	virtual void turnAnimation1() const=0;
	virtual void turnAnimation2() const=0;

	virtual void riverAnimation1() const=0;
	virtual void riverAnimation2() const=0;

	virtual void postRiverAnimation1() const=0;
	virtual void postRiverRunAnimation1() const=0;
// 	virtual void postRiverAnimation2() const=0;

// 	virtual void handSwitchRounds() const=0;
// 
// 	virtual void startNewHand() const=0;
	virtual void nextRoundCleanGui() const=0;
// 	
// 	virtual void userWidgetsBackgroudColor() const=0;
// 	virtual void timerBlockerFalse() const=0;
	virtual void meInAction() const=0;


	//log.cpp
	virtual void showPlayerActionLogMsg(std::string playName, int action, int setValue) const=0;





		
	
	



};

#endif
