//
// C++ Interface: gamelobbydialogimpl
//
// Description: 
//
//
// Author: FThauer FHammer <webmaster@pokerth.net>, (C) 2007
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef GAMELOBBYDIALOGIMPL_H
#define GAMELOBBYDIALOGIMPL_H

#include <ui_gamelobbydialog.h>

#include <QtGui>
#include <QtCore>

#include <iostream>

#include <gamedata.h>
#include "createinternetgamedialogimpl.h"
#include "sdlplayer.h"
#include "gametableimpl.h"

class Session;
class ConfigFile;
class LobbyChat;
class startWindowImpl;

/**
	@author FThauer FHammer <webmaster@pokerth.net>
*/
class gameLobbyDialogImpl: public QDialog, public Ui::gameLobbyDialog {
Q_OBJECT
public:
	gameLobbyDialogImpl(startWindowImpl *parent = 0, ConfigFile* = 0);

	~gameLobbyDialogImpl();

	void exec();

	LobbyChat *getLobbyChat() { return myChat; }

	void setSession(boost::shared_ptr<Session> session) { mySession = session; }
	boost::shared_ptr<Session> getSession() { assert(mySession.get()); return mySession; }

	void setMyW ( gameTableImpl* theValue ) { myW = theValue; }

public slots:

	void createGame();
	void joinGame();
	void joinAnyGame();

	void gameSelected(QTreeWidgetItem*, QTreeWidgetItem*);
	void updateGameItem(QTreeWidgetItem *item, unsigned gameId);

	void addGame(unsigned gameId);
	void updateGameMode(unsigned gameId, int newMode);
	void updateGameAdmin(unsigned gameId, unsigned adminPlayerId);
	void removeGame(unsigned gameId);
	void gameAddPlayer(unsigned gameId, unsigned playerId);
	void gameRemovePlayer(unsigned gameId, unsigned playerId);

	void updateStats(ServerStats stats);

	void refreshGameStats();
	void refreshPlayerStats();

	void setCurrentGameName ( const QString& theValue ) { currentGameName = theValue; }
	QString getCurrentGameName() const { return currentGameName; }	

	gameTableImpl* getMyW() const { return myW; }
	void checkPlayerQuantity();

	void joinedNetworkGame(unsigned, QString, int);
	void addConnectedPlayer(unsigned, QString, int);
	void updatePlayer(unsigned, QString);
	void removePlayer(unsigned, QString);
	void newGameAdmin(unsigned, QString);

	void refreshConnectedPlayerAvatars();

	void playerSelected(QTreeWidgetItem*, QTreeWidgetItem*);
	void refresh(int actionID);
	void removedFromGame(int reason);
	void startGame();
	void leaveGame();
	void kickPlayer();

	void joinedGameDialogUpdate();
	void leftGameDialogUpdate();
	void updateDialogBlinds(const GameData &gameData);
	void clearDialog();

	void keyPressEvent(QKeyEvent * keyEvent); 
	bool event(QEvent * event); 
	void hideShowGameDescription(bool show);

	void showWaitStartGameMsgBox();

	void joinAnyGameButtonRefresh();

	void reject();
	
private:
	
	gameTableImpl* myW;
	startWindowImpl* myStartWindow;
	ConfigFile *myConfig;	
	boost::shared_ptr<Session> mySession;
	createInternetGameDialogImpl *myCreateInternetGameDialog;
	QString currentGameName;
	unsigned myPlayerId;
	bool isAdmin;
	bool inGame;
	LobbyChat *myChat;
	QString myAppDataPath;
	int keyUpCounter;
	QMessageBox *waitStartGameMsgBox;
	QTimer *waitStartGameMsgBoxTimer;
	

 protected:
         bool eventFilter(QObject *obj, QEvent *event);
	
};

#endif
