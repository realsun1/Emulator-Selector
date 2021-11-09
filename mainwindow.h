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

class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
private slots:
  void handleStartButton();
  void handleStatsButton();
  void handleSettingsButton();
  void handleQuitButton();
  void handleSaveButton();
  void handleCancelButton();
  void handleMusicButton();
  void redValue();
  void greenValue();
  void blueValue();

private:

  QLabel *title, *colorPreview;
  QBoxLayout *layout;
  QPushButton *startButton, *statsButton, *settingsButton, *quitButton, *saveButton, *cancelButton, *musicButton;
  QMediaPlayer *player;
  QComboBox *imageComboBox;
  QSlider *redSlider, *greenSlider, *blueSlider;
  QString r,g,b;

};
#endif // MAINWINDOW_H

