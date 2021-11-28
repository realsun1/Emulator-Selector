#include <iostream>
#include <fstream>
#include<string>

using namespace std;

class GameInfo {

	private:
		string title;
		string romName;
		string emulator;
		string image;
		string description;

	public:
		
		void setTitle(string name);
		void setRom(string name);
		void setEmulator(string name);
		void setImage(string name);
		void setDescription(string name);
		string getTitle();
		string getRom();
		string getEmulator();
		string getImage();
		string getDescription();
		// Constructor
		GameInfo(string nTitle, string nRom, string nEmulator, string nImage, string nDescription);
		// Empty Constructor
		GameInfo();
};

