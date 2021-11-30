/***************************************************************************//**
 * @brief Class responsible for user interface, experience and GUI
 *
 * This class is responsible for handling all user interaction, experience and displaying the GUI.
 * The main window holds all buttons, the logic and execution of those buttons. It is responsible for 
 * all user interactions with the software minus the actual playing of the game.
 *
 * @authors Nicole Karas, Christopher Judkins, Sundin Nguyen, Junshen Xu
 ******************************************************************************/
#include "mainwindow.h"



/***************************************************************************//**
 * @brief Constructor for Main Window
 *
 * Constructor responsible for creating the initial main menu buttons and attaching them 
 * to the appropiate button functions
 * 
 * @param parent Pointer to the parent widget that holds the main application
 *
 * @authors Nicole Karas, Christopher Judkins, Sundin Nguyen, Junshen Xu
 ******************************************************************************/
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

  backFromStartButton = new QPushButton("Back", this);
  connect(backFromStartButton, &QPushButton::released, this, &MainWindow::handleBackFromStartButton);

  imageComboBox->setVisible(false);
  saveButton->setVisible(false);
  cancelButton->setVisible(false);
  redSlider->setVisible(false);
  greenSlider->setVisible(false);
  blueSlider->setVisible(false);
  colorPreview->setVisible(false);
  backFromStartButton->setVisible(false);

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


  // QList
  gameTextList = new QListWidget(this);
  gameTextList->setGeometry(QRect(QPoint(450, 300), QSize(400, 250)));
  connect(gameTextList, &QListWidget::itemClicked, this, &MainWindow::handleGameSelected);
  gameTextList->setStyleSheet("QListWidget {background-color: black; color:#00FFFF; font-weight:bold; border: 2px solid #9900FF; font-size:30px; border-radius: 25px;}  QListWidget:hover{ background-color: #9900FF;}");
  gameTextList->setVisible(false);

  // objects for screen when player selects game
  gameDscrip = new QLabel(this);
  gameDscrip->setVisible(false);

  //game image
  gameImageLabel = new QLabel(this);
  gameImageLabel->setVisible(false); 

  //PLAY GAME BUTTON
  executeGameButton = new QPushButton("PLAY", this);
  executeGameButton->setVisible(false);
  executeGameButton->setGeometry(QRect(QPoint(350, 600), QSize(300, 75)));
  executeGameButton->setStyleSheet("QPushButton {background-color: black; color:#00FFFF; font-weight:bold; border: 2px solid #9900FF; font-size:30px; border-radius: 25px;}  QPushButton:hover{ background-color: #9900FF;}");
  connect(executeGameButton, &QPushButton::released, this, &MainWindow::handleExecuteGameButton);

  //GO BACK FROM GAME SELECTION BUTTON
  goBackToListButton = new QPushButton("BACK", this);
  goBackToListButton->setVisible(false);
  goBackToListButton->setGeometry(QRect(QPoint(700, 600), QSize(300, 75)));
  goBackToListButton->setStyleSheet("QPushButton {background-color: black; color:#00FFFF; font-weight:bold; border: 2px solid #9900FF; font-size:30px; border-radius: 25px;}  QPushButton:hover{ background-color: #9900FF;}");
  connect(goBackToListButton, &QPushButton::released, this, &MainWindow::handleBackToListButton);

  StatsList = new QListWidget(this);
  StatsList->setGeometry(QRect(QPoint(450, 300), QSize(400, 250)));
  connect(StatsList, &QListWidget::itemClicked, this, &MainWindow::handlestatsSelect);
  StatsList->setStyleSheet("QListWidget {background-color: black; color:#00FFFF; font-weight:bold; border: 2px solid #9900FF; font-size:30px; border-radius: 25px;}  QListWidget:hover{ background-color: #9900FF;}");
  StatsList->setVisible(false);

  goBackFromStatsButton = new QPushButton("BACK", this);
  goBackFromStatsButton->setVisible(false);
  goBackFromStatsButton->setGeometry(QRect(QPoint(700, 600), QSize(300, 75)));
  goBackFromStatsButton->setStyleSheet("QPushButton {background-color: black; color:#00FFFF; font-weight:bold; border: 2px solid #9900FF; font-size:30px; border-radius: 25px;}  QPushButton:hover{ background-color: #9900FF;}");
  connect(goBackFromStatsButton, &QPushButton::released, this, &MainWindow::handleBackFromStatsButton);

  gobackStats = new QPushButton("BACK", this);
  gobackStats->setVisible(false);
  gobackStats->setGeometry(QRect(QPoint(700, 600), QSize(300, 75)));
  gobackStats->setStyleSheet("QPushButton {background-color: black; color:#00FFFF; font-weight:bold; border: 2px solid #9900FF; font-size:30px; border-radius: 25px;}  QPushButton:hover{ background-color: #9900FF;}");
  connect(gobackStats, &QPushButton::released, this, &MainWindow::handleBacktoStats);

  Stats = new QLabel(this);
  Stats->setVisible(false);
  
  favgametitle = new QLabel(this);
  favgametitle->setVisible(true);

  favgame = new QLabel(this);
  favgame->setVisible(false);

  highestscoreTitle = new QLabel(this);
  highestscoreTitle->setText("Highest Score:");
  highestscoreTitle->setVisible(true);

  highestscore = new QLabel(this);
  highestscore->setVisible(true);

  timeplayedTitle = new QLabel(this);
  timeplayedTitle->setText("Time Played:");
  timeplayedTitle->setVisible(true);
  
  timePlayed = new QLabel(this);
  timePlayed->setVisible(true);

}

/***************************************************************************//**
 * @brief Handler for Game Selection
 *
 * Handler responsible for event when game is selected, displays game picture and description
 * 
 * @param item List item that represents the game selected
 *
 * @authors  Christopher Judkins
 ******************************************************************************/
void MainWindow::handleGameSelected(QListWidgetItem *item) {

	string row = item->text().toStdString();
	cout << row << endl;

	//need row number to display relevant info
	string parseOn = ".";
	int lineNum = row.find(parseOn);
	
	string sGameNumberInList = row.substr(0, lineNum);
	cout << "number: " + sGameNumberInList << endl;
	int gameNumberInList = stoi(sGameNumberInList);
	
	goBackToListButton->setVisible(true);
	executeGameButton->setVisible(true);
	gameTextList->setVisible(false);

	QString qstrDisplay;
	string descriptionToLoad = games[gameNumberInList-1].getDescription();
	cout << descriptionToLoad << endl;
	qstrDisplay = QString::fromStdString(descriptionToLoad);
	gameDscrip->setVisible(true);	
  	gameDscrip->setGeometry(QRect(QPoint(700, 300), QSize(400, 250)));
  	gameDscrip->setStyleSheet("QLabel {background-color:rgb(0,0,0); border:2px solid red; font-size:16px; color:#FFFFFF;}");
	//gameDscrip->setSizePolicy(10);
	gameDscrip->setText(qstrDisplay);
	gameDscrip->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
	//gameDscrip->->setStyleSheet("QLabel { background-color: black; font-weight : bold; font-size: 5px; border:none; border-left:5px groove #9900FF; border-right:5px groove #9900FF; color:#00FFFF; }");	
	gameDscrip->setWordWrap(true);
	
	// load image here
	string imagePath = "images/" + games[gameNumberInList-1].getImage();
	cout << imagePath << endl;
	QString qstrGame;
	qstrGame = QString::fromStdString(imagePath);
	
    gameImageLabel->setGeometry(QRect(QPoint(400, 300), QSize(250, 250)));
  	gameImageLabel->setStyleSheet("QLabel {background-color:rgb(0,0,0); border:2px solid red; font-size:16px; color:#FFFFFF;}");
	gameImageLabel->setVisible(true);
	QPixmap* pGameImage = new QPixmap(qstrGame);
    QPixmap gameImage(":/home/chris/3307/sim/images/PE.jpg");
	//gameImageLabel->setPixmap(gameImage);
	//if(gameImage == NULL) {
	//	cout << "game image null" << endl;
	//}
	gameImageLabel->setPixmap(*pGameImage);
}

/***************************************************************************//**
 * @brief Handler for Back Button from Game Selection
 * 
 * Handles event when back button is clicked from game selection menu, 
 * goes back from when a game is selected from list
 *
 * @authors  Christopher Judkins
 ******************************************************************************/
void MainWindow::handleBackToListButton() {

	gameTextList->setVisible(true);
	executeGameButton->setVisible(false);
	goBackToListButton->setVisible(false);
	gameDscrip->setVisible(false);
	gameImageLabel->setVisible(false);
}

/***************************************************************************//**
 * @brief Handler for Execute Button from Game Selection
 * 
 * Handles event when execute button is clicked from game selection menu, 
 * runs API to actually launch the game selected
 *
 * @authors Christopher Judkins
 ******************************************************************************/
void MainWindow::handleExecuteGameButton() {

}

/***************************************************************************//**
 * @brief Parser for Games
 * 
 * Parses file that stores all games and descriptions for those games to load them
 * onto the application and display the available games
 *
 * @authors  Christopher Judkins
 ******************************************************************************/
void MainWindow::readGameInfo() {

    string line;
    ifstream file;
    string delim = "|";
    int pos;
    int gameListPos = 0;
    file.open("games.txt");

    while (getline(file, line)) {

        // current line
        cout << "current line is: " + line << endl;
        pos = line.find(delim);

        string currWord = line.substr(0, pos);
        games[gameListPos].setTitle(currWord);
        cout << "Game Title: " + games[gameListPos].getTitle() << endl;

        // getting next set of game info (ROM)
        string nextSetOfline = line.substr(pos+1);
        pos = nextSetOfline.find(delim);
        currWord = nextSetOfline.substr(0, pos);
        cout << "Rom: " + currWord << endl;
        games[gameListPos].setRom(currWord);

        //next set of info (emulator)
        string finalSetOfLine = nextSetOfline.substr(pos+1);
        pos = finalSetOfLine.find(delim);
        currWord = finalSetOfLine.substr(0, pos);
        cout << "Emulator: " + currWord << endl;
        games[gameListPos].setEmulator(currWord);

        // getting next set of game info (image)
        string nextSetline = finalSetOfLine.substr(pos+1);
        pos = nextSetline.find(delim);
        currWord = nextSetline.substr(0, pos);
        cout << "Image: " + currWord << endl;
        games[gameListPos].setImage(currWord);

        // getting next set of game info (Description)
        string FnextSetOfline = nextSetline.substr(pos+1);
        pos = FnextSetOfline.find(delim);
        currWord = FnextSetOfline.substr(0, pos);
        cout << "description: " + currWord << endl;
        games[gameListPos].setDescription(currWord);

        cout << gameListPos << endl;

        // Done setting info for game, go to next slot in the game obj array
        gameListPos = gameListPos + 1;

    }
    // returns amount of games in list
    numAvailableGames = gameListPos;

}

/***************************************************************************//**
 * @brief Handler for Start Button
 * 
 * Handles event when start button is clicked from main menu, switches application screen
 * to list of games
 *
 * @authors Nicole Karas, Christopher Judkins
 ******************************************************************************/
void MainWindow::handleStartButton()
{

	readGameInfo();
  	title->setText("SELECT");
	
	// Hide other push buttons on click event
 	startButton->setVisible(false);
  	statsButton->setVisible(false);
  	settingsButton->setVisible(false);
  	quitButton->setVisible(false);
	
  	// set back button to be visible
	backFromStartButton->setVisible(true);
  	backFromStartButton->setGeometry(QRect(QPoint(700, 600), QSize(300, 75)));
  	backFromStartButton->setStyleSheet("QPushButton {background-color: black; color:#00FFFF; font-weight:bold; border: 2px solid #9900FF; font-size:30px; border-radius: 25px;}  QPushButton:hover{ background-color: #9900FF;}");
	
	// Game list made visible
	gameTextList->setVisible(true);

	string strToDisplay;
	QString qstrToDisplay;
	string listNum;

	// Load List with selectable games
	for(int i=0;i<numAvailableGames;i++) {
	
		listNum = to_string(i+1);
		strToDisplay = listNum + ". " + games[i].getTitle();	
		cout << strToDisplay << endl;

		qstrToDisplay = QString::fromStdString(strToDisplay);
		gameTextList->addItem(qstrToDisplay);

	}	
}

/***************************************************************************//**
 * @brief Handler for gobackStats button
 * 
 * Handles event when Back button is clicked from stats page, switches application screen
 * to player usage statistics
 *
 * @authors Junshen Xu
 ******************************************************************************/
void MainWindow::handleBacktoStats(){
  StatsList->setVisible(true);
  goBackFromStatsButton->setVisible(true);
  title->setVisible(true);
  favgametitle->setVisible(true);

  gobackStats->setVisible(false);
  Stats->setVisible(false);
  timeplayedTitle->setVisible(false);
  highestscoreTitle->setVisible(false);
}
/***************************************************************************//**
 * @brief Handler for goBackFromStatsButton button
 * 
 * Handles event when Back button is clicked from statistics page, switches application screen
 * to main menu screen
 *
 * @authors Junshen Xu
 ******************************************************************************/
void MainWindow::handleBackFromStatsButton(){
  goBackFromStatsButton->setVisible(false);
  StatsList->setVisible(false);
  favgametitle->setVisible(false);
  startButton->setVisible(true);
  statsButton->setVisible(true);
  settingsButton->setVisible(true);
  quitButton->setVisible(true);
  title->setText("ARCADES R US &#10070;");

  StatsList->clear();
  StatsList->setStyleSheet("QListWidget {background-color: black; color:#00FFFF; font-weight:bold; border: 2px solid #9900FF; font-size:30px; border-radius: 25px;}  QListWidget:hover{ background-color: #9900FF;}");

}
/***************************************************************************//**
 * @brief Handler for goBackFromStatsButton button
 * 
 * Handles event when a game is selected from statistics page, switches application screen
 * to stats page, then display the stats for that game.
 *
 * @authors Junshen Xu
 ******************************************************************************/
void MainWindow::handlestatsSelect(){
  favgametitle->setVisible(false);

  StatsList->setVisible(false);
  goBackFromStatsButton->setVisible(false);
  title->setVisible(false);
  
  highestscoreTitle->setVisible(true);
  highestscoreTitle->setGeometry(QRect(QPoint(250, 200), QSize(700, 75)));
  highestscoreTitle->setStyleSheet("QLabel { background-color: black; font-weight : bold; font-size: 24px; border:none; color:#00FFFF; }");

  timeplayedTitle->setVisible(true);
  timeplayedTitle->setGeometry(QRect(QPoint(250, 350), QSize(700, 75)));
  timeplayedTitle->setStyleSheet("QLabel { background-color: black; font-weight : bold; font-size: 24px; border:none; color:#00FFFF; }");

  gobackStats->setVisible(true);

  Stats->setText("stats");
  Stats->setVisible(true);
  
}
/***************************************************************************//**
 * @brief Handler for Stats Button
 * 
 * Handles event when stat button is clicked from main menu, switches application screen
 * to player usage statistics
 *
 * @authors Nicole Karas, Junshen Xu
 ******************************************************************************/
void MainWindow::handleStatsButton()
{
  readGameInfo();

  title->setText("STATS");
  startButton->setVisible(false);
  statsButton->setVisible(false);
  settingsButton->setVisible(false);
  quitButton->setVisible(false);

  
  favgametitle->setVisible(true);
  favgametitle->setText("Favourite game:");
  favgametitle->setGeometry(QRect(QPoint(250, 200), QSize(700, 75)));
  favgametitle->setStyleSheet("QLabel { background-color: black; font-weight : bold; font-size: 24px; border:none; color:#00FFFF; }");
  
  StatsList->setVisible(true);
  goBackFromStatsButton->setVisible(true);

  string strToDisplay;
	QString qstrToDisplay;
	string listNum;

	// Load List with selectable games
	for(int i=0;i<numAvailableGames;i++) {
	
		listNum = to_string(i+1);
		strToDisplay = listNum + ". " + games[i].getTitle();	
		cout << strToDisplay << endl;

		qstrToDisplay = QString::fromStdString(strToDisplay);
		StatsList->addItem(qstrToDisplay);
  }
  

}

/***************************************************************************//**
 * @brief Handler for Settings Button
 * 
 * Handles event when settings button is clicked from main menu, switches application screen
 * to list of all settings that can be changed by the user
 *
 * @authors Nicole Karas, Sundin Nguyen
 ******************************************************************************/
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

/***************************************************************************//**
 * @brief Stores red value
 * 
 * Stores red value in QString and parse into QLabel for color preview
 *
 * @authors  Sundin Nguyen
 ******************************************************************************/
void MainWindow::redValue()
{
    r = QString::number(redSlider->value());
    colorPreview->setStyleSheet("QLabel{background-color:rgb("+r+","+g+","+b+");}");
}

/***************************************************************************//**
 * @brief Stores green value
 * 
 * Stores green value in QString and parse into QLabel for color preview
 *
 * @authors  Sundin Nguyen
 ******************************************************************************/
void MainWindow::greenValue()
{
    g = QString::number(greenSlider->value());
    colorPreview->setStyleSheet("QLabel{background-color:rgb("+r+","+g+","+b+");}");
}

/***************************************************************************//**
 * @brief Stores blue value
 * 
 * Stores blue value in QString and parse into QLabel for color preview
 *
 * @authors  Sundin Nguyen
 ******************************************************************************/
void MainWindow::blueValue()
{
    b = QString::number(blueSlider->value());
    colorPreview->setStyleSheet("QLabel{background-color:rgb("+r+","+g+","+b+");}");
}

/***************************************************************************//**
 * @brief Handler for Back Button from Game Selection
 * 
 * Handles event when back button is clicked from game selection menu, 
 * goes back to main menu screen
 *
 * @authors Christopher Judkins
 ******************************************************************************/
void MainWindow::handleBackFromStartButton() {

	backFromStartButton->setVisible(false);
	gameTextList->setVisible(false);
    startButton->setVisible(true);
    statsButton->setVisible(true);
    settingsButton->setVisible(true);
    quitButton->setVisible(true);
    imageComboBox->setCurrentIndex(0);
    title->setText("ARCADES R US &#10070;");
	gameTextList->clear();
    gameTextList->setStyleSheet("QListWidget {background-color: black; color:#00FFFF; font-weight:bold; border: 2px solid #9900FF; font-size:30px; border-radius: 25px;}  QListWidget:hover{ background-color: #9900FF;}");

}

/***************************************************************************//**
 * @brief Handler for Save Button
 * 
 * Handles event when save button is clicked from settings menu, saves settings changes to application
 *
 * @authors Sundin Nguyen
 ******************************************************************************/
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

/***************************************************************************//**
 * @brief Handler for Cancel Button
 * 
 * Handles event when cancel button is clicked from settings menu, cancels all changes user made 
 * in settings
 *
 * @authors Sundin Nguyen
 ******************************************************************************/
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

/***************************************************************************//**
 * @brief Handler for Quit Button
 * 
 * Handles event when quit button is clicked from main menu, closes main application
 *
 * @authors Nicole Karas
 ******************************************************************************/
void MainWindow::handleQuitButton()
{

  this->close();

}

/***************************************************************************//**
 * @brief Handler for Music Button
 * 
 * Handles event when music button is clicked from main menu, switches music off and on
 *
 * @authors Nicole Karas, 
 ******************************************************************************/
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

/***************************************************************************//**
 * @brief Destructor for Main Window
 * 
 * Handles de-allocation of variables when application closed
 *
 * @authors Nicole Karas, 
 ******************************************************************************/
MainWindow::~MainWindow(){
  delete title;
  delete colorPreview;
  delete gameDscrip;
  delete gameImageLabel;
  delete layout;
  delete quitButton;
  delete saveButton;
  delete musicButton;
  delete startButton;
  delete statsButton;
  delete cancelButton;
  delete settingsButton;
  delete player;
  delete imageComboBox;
  delete redSlider;
  delete blueSlider;
  delete greenSlider;
  delete gameTextList;
  delete gameImage;
}

