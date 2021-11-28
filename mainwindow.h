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

  private:
  GameInfo games[100];
  int numAvailableGames;

private:

  QLabel *title, *colorPreview, *gameDscrip, *gameImageLabel;
  QBoxLayout *layout;
  QPushButton *startButton, *statsButton, *settingsButton, *quitButton, *saveButton, *cancelButton, *musicButton, *backFromStartButton, *executeGameButton, *goBackToListButton;
  QMediaPlayer *player;
  QComboBox *imageComboBox;
  QSlider *redSlider, *greenSlider, *blueSlider;
  QString r,g,b;
  QListWidget *gameTextList;
  QPixmap *gameImage;

};
#endif // MAINWINDOW_H

