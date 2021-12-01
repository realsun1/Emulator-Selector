/***************************************************************************//**
 * @brief Header file for Main Window
 *
 * @authors Nicole Karas, Christopher Judkins, Sundin Nguyen, Junshen Xu, Ryan Howarth
 ******************************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QListWidget>
#include <QBoxLayout>
#include <QtMultimedia>
#include <QMediaPlayer>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <QComboBox>
#include "gameInfo.h"
#include <QListWidget>
#include <QPixmap>
#include <QElapsedTimer>
#include <QTime>
#include "statsinfo.h"



class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
private slots:
  void handleBackFromStartButton();
  void handleStartButton();
  void handleStatsButton();
  void handlestatsSelect(QListWidgetItem *item);
  void handleBackFromStatsButton();
  void handleBacktoStats();
  void handleSettingsButton();
  void handleQuitButton();
  void handleSaveButton();
  void handleCancelButton();
  void handleMusicButton();
  void handleExecuteGameButton();
  void handleBackToListButton();
  void redValue();
  void greenValue();
  void blueValue();
  void readGameInfo();
  void handleGameSelected(QListWidgetItem *item);
  void readstats();
  void writestatsNum(int line);

  private:
  GameInfo games[100];
  string romToLoad;
  string consoleToLoad;
  int numAvailableGames;
  StatsInfo stats[100];
  int gameselected;
  string mostplayed;
private:

  QLabel *title, *colorPreview, *gameDscrip, *gameImageLabel, *Stats, *favgame, *favgametitle, *highestscoreTitle, *highestscore, *timeplayedTitle, *timePlayed;
  QBoxLayout *layout;
  QPushButton *startButton, *statsButton, *settingsButton, *quitButton, *saveButton, *cancelButton, *musicButton, *backFromStartButton, *executeGameButton, *goBackToListButton, *SstatsButton, *goBackFromStatsButton, *gobackStats;
  QMediaPlayer *player;
  QComboBox *imageComboBox;
  QSlider *redSlider, *greenSlider, *blueSlider;
  QString r,g,b;
  QListWidget *gameTextList,*StatsList;
  QPixmap *gameImage;
  QElapsedTimer timer;

};


#endif // MAINWINDOW_H

