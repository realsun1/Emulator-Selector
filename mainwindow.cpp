#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{

  layout = new QBoxLayout(QBoxLayout::TopToBottom);
  this->setStyleSheet("MainWindow {background-color: black;}");

  // Initialize all the Main Menu UI components and connect them to the appropiate signal function
  title = new QLabel(this);
  title->setTextFormat(Qt::RichText);
  title->setFrameStyle(QFrame::Panel);
  title->setText("ARCADES R US &#10070;");
  title->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
  title->setStyleSheet("QLabel { background-color: black; font-weight : bold; font-size: 75px; border:none; border-left:5px groove #9900FF; border-right:5px groove #9900FF; color:#00FFFF; }");
  title->setGeometry(QRect(QPoint(250, 100), QSize(800, 100)));

  startButton = new QPushButton("START ARCADE", this);
  startButton->setGeometry(QRect(QPoint(450, 300), QSize(400, 75)));
  startButton->setStyleSheet("QPushButton {background-color: black; color:#00FFFF; font-weight:bold; border: 2px solid #9900FF; font-size:30px; border-radius: 25px;} QPushButton:hover{ background-color: #9900FF;}");
  connect(startButton, &QPushButton::released, this, &MainWindow::handleStartButton);

  statsButton = new QPushButton("PLAYER STATISTICS", this);
  statsButton->setGeometry(QRect(QPoint(450, 400), QSize(400, 75)));
  statsButton->setStyleSheet("QPushButton {background-color: black; color:#00FFFF; font-weight:bold; border: 2px solid #9900FF; font-size:30px; border-radius: 25px;}  QPushButton:hover{ background-color: #9900FF;}");
  connect(statsButton, &QPushButton::released, this, &MainWindow::handleStatsButton);

  settingsButton = new QPushButton("ARCADE SETTINGS", this);
  settingsButton->setGeometry(QRect(QPoint(450, 500), QSize(400, 75)));
  settingsButton->setStyleSheet("QPushButton {background-color: black; color:#00FFFF; font-weight:bold; border: 2px solid #9900FF; font-size:30px; border-radius: 25px;}  QPushButton:hover{ background-color: #9900FF;}");
  connect(settingsButton, &QPushButton::released, this, &MainWindow::handleSettingsButton);

  quitButton = new QPushButton("QUIT ARCADE", this);
  quitButton->setGeometry(QRect(QPoint(450, 600), QSize(400, 75)));
  quitButton->setStyleSheet("QPushButton {background-color: black; color:#00FFFF; font-weight:bold; border: 2px solid #9900FF; font-size:30px; border-radius: 25px;}  QPushButton:hover{ background-color: #9900FF;}");
  connect(quitButton, &QPushButton::released, this, &MainWindow::handleQuitButton);

  imageComboBox = new QComboBox(this);
  redSlider = new QSlider(Qt::Horizontal,this);
  greenSlider = new QSlider(Qt::Horizontal,this);
  blueSlider = new QSlider(Qt::Horizontal,this);
  colorPreview = new QLabel(this);

  saveButton = new QPushButton("Save Changes", this);
  connect(saveButton, &QPushButton::released, this, &MainWindow::handleSaveButton);

  cancelButton = new QPushButton("Cancel", this);
  connect(cancelButton, &QPushButton::released, this, &MainWindow::handleCancelButton);

  imageComboBox->setVisible(false);
  saveButton->setVisible(false);
  cancelButton->setVisible(false);
  redSlider->setVisible(false);
  greenSlider->setVisible(false);
  blueSlider->setVisible(false);
  colorPreview->setVisible(false);

  musicButton = new QPushButton("MUTE MUSIC", this);
  musicButton->setGeometry(QRect(QPoint(1050, 650), QSize(200, 100)));
  musicButton->setStyleSheet("QPushButton {background-color: black; color:#00FFFF; font-weight:bold; font-size:20px;}  QPushButton:hover{ color: #9900FF;}");
  connect(musicButton, &QPushButton::released, this, &MainWindow::handleMusicButton);


  // Add components to layout
  layout->addWidget(title, Qt::AlignCenter);
  layout->addWidget(startButton, Qt::AlignCenter);
  layout->addWidget(statsButton, Qt::AlignCenter);
  layout->addWidget(settingsButton, Qt::AlignCenter);
  layout->addWidget(saveButton, Qt::AlignLeft);
  layout->addWidget(cancelButton, Qt::AlignRight);

  //Initialize Media Player and Change Settings
  player = new QMediaPlayer;
  
  player->setMedia(QUrl("https://www.fesliyanstudios.com/musicfiles/2019-12-11_-_Retro_Platforming_-_David_Fesliyan/2019-12-11_-_Retro_Platforming_-_David_Fesliyan.mp3"));
  player->setVolume(50);
  player->play();
}
void MainWindow::handleStartButton()
{

  title->setText("START");

}

void MainWindow::handleStatsButton()
{

  title->setText("STATS");

}

void MainWindow::handleSettingsButton()
{
  // Display title SETTINGS on click event
  title->setText("SETTINGS");

  // Hide other push buttons on click event
  startButton->setVisible(false);
  statsButton->setVisible(false);
  settingsButton->setVisible(false);
  quitButton->setVisible(false);

  // if click on settings again, needs to be true
  imageComboBox->setVisible(true);
  saveButton->setVisible(true);
  cancelButton->setVisible(true);
  redSlider->setVisible(true);
  greenSlider->setVisible(true);
  blueSlider->setVisible(true);
  colorPreview->setVisible(true);

  // background image selector displayed
  imageComboBox->setGeometry(QRect(QPoint(450, 300), QSize(400, 35)));
  imageComboBox->setStyleSheet("QComboBox {background-color: white; color:#000000; font-weight:bold; border: 2px solid #9900FF; font-size:20px; border-radius: 25px;} QComboBox:hover{ background-color: #1900FF;}");

  // color sliders
  redSlider->setGeometry(QRect(QPoint(450, 400), QSize(400, 20)));
  redSlider->setStyleSheet("QSlider::handle {background-color:red};");
  redSlider->setRange(0,255);
  redSlider->setValue(0);
  greenSlider->setGeometry(QRect(QPoint(450, 425), QSize(400, 20)));
  greenSlider->setStyleSheet("QSlider::handle {background-color:green};");
  greenSlider->setRange(0,255);
  greenSlider->setValue(0);
  blueSlider->setGeometry(QRect(QPoint(450, 450), QSize(400, 20)));
  blueSlider->setStyleSheet("QSlider::handle {background-color:blue};");
  blueSlider->setRange(0,255);
  blueSlider->setValue(0);

  // color preview
  colorPreview->setGeometry(QRect(QPoint(950, 300), QSize(250, 250)));
  colorPreview->setStyleSheet("QLabel {background-color:rgb(0,0,0); border:2px solid red; font-size:30px; color:#FFFFFF;}");
  colorPreview->setText("Color Preview");
  colorPreview->setAlignment(Qt::AlignTop);

  // connect color sliders to target classes
  connect(redSlider,SIGNAL(valueChanged(int)),this,SLOT(redValue()));
  connect(greenSlider,SIGNAL(valueChanged(int)),this,SLOT(greenValue()));
  connect(blueSlider,SIGNAL(valueChanged(int)),this,SLOT(blueValue()));

  // after clicking, check that items don't duplicate
  if (imageComboBox->count() == 0) {
      imageComboBox->addItem("Select Background Image");
      imageComboBox->addItem("Arcade");
      imageComboBox->addItem("Indie");
      imageComboBox->addItem("Retro");
      imageComboBox->addItem("Neon");

      r = QString::number(redSlider->value());
      g = QString::number(greenSlider->value());
      b = QString::number(blueSlider->value());
  }
  // save changes button
  saveButton->setGeometry(QRect(QPoint(300, 600), QSize(300, 75)));
  saveButton->setStyleSheet("QPushButton {background-color: black; color:#00FFFF; font-weight:bold; border: 2px solid #9900FF; font-size:30px; border-radius: 25px;}  QPushButton:hover{ background-color: #9900FF;}");

  // cancel button
  cancelButton->setGeometry(QRect(QPoint(700, 600), QSize(300, 75)));
  cancelButton->setStyleSheet("QPushButton {background-color: black; color:#00FFFF; font-weight:bold; border: 2px solid #9900FF; font-size:30px; border-radius: 25px;}  QPushButton:hover{ background-color: #9900FF;}");
}
// store red value in QString and parse into QLabel for color preview
void MainWindow::redValue()
{
    r = QString::number(redSlider->value());
    colorPreview->setStyleSheet("QLabel{background-color:rgb("+r+","+g+","+b+");}");
}

// store green value in QString and parse into QLabel for color preview
void MainWindow::greenValue()
{
    g = QString::number(greenSlider->value());
    colorPreview->setStyleSheet("QLabel{background-color:rgb("+r+","+g+","+b+");}");
}

// store blue value in QString and parse into QLabel for color preview
void MainWindow::blueValue()
{
    b = QString::number(blueSlider->value());
    colorPreview->setStyleSheet("QLabel{background-color:rgb("+r+","+g+","+b+");}");
}

void MainWindow::handleSaveButton()
{
     setStyleSheet("MainWindow {background-color:rgb("+r+","+g+","+b+");}");

    // connect QComboBox items to images
    if (imageComboBox->currentText() == "Arcade") {setStyleSheet("MainWindow {border-image: url(images/test.jpg) 0 0 0 0 stretch stretch;}");}
    if (imageComboBox->currentText() == "Indie") {setStyleSheet("MainWindow {border-image: url(images/test2.jpg) 0 0 0 0 stretch stretch;}");}
    if (imageComboBox->currentText() == "Retro") {setStyleSheet("MainWindow {border-image: url(images/test3.jpg) 0 0 0 0 stretch stretch;}");}
    if (imageComboBox->currentText() == "Neon") {setStyleSheet("MainWindow {border-image: url(images/test4.jpg) 0 0 0 0 stretch stretch;}");}

    imageComboBox->setVisible(false);
    saveButton->setVisible(false);
    cancelButton->setVisible(false);
    redSlider->setVisible(false);
    greenSlider->setVisible(false);
    blueSlider->setVisible(false);
    colorPreview->setVisible(false);

    startButton->setVisible(true);
    statsButton->setVisible(true);
    settingsButton->setVisible(true);
    quitButton->setVisible(true);
    imageComboBox->setCurrentIndex(0);
    title->setText("ARCADES R US &#10070;");
}

void MainWindow::handleCancelButton()
{
    imageComboBox->setVisible(false);
    saveButton->setVisible(false);
    cancelButton->setVisible(false);
    redSlider->setVisible(false);
    greenSlider->setVisible(false);
    blueSlider->setVisible(false);
    colorPreview->setVisible(false);

    startButton->setVisible(true);
    statsButton->setVisible(true);
    settingsButton->setVisible(true);
    quitButton->setVisible(true);
    imageComboBox->setCurrentIndex(0);
    title->setText("ARCADES R US &#10070;");
}

void MainWindow::handleQuitButton()
{

  this->close();

}

void MainWindow::handleMusicButton()
{

  int static counter = 0;

  counter++;

  if(counter % 2 != 0){
     musicButton->setText("PLAY MUSIC");
     player->setVolume(0);
  }else{
    musicButton->setText("MUTE MUSIC");
    player->setVolume(50);
  }
 

}

// Destructor 
MainWindow::~MainWindow(){
  delete title;
}

