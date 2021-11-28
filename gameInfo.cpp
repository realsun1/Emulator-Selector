#include "gameInfo.h"
#include <iostream>
#include <fstream>
#include<string>

using namespace std;

		void GameInfo::setTitle(string name) {
			
			title = name;

		}

		void GameInfo::setRom(string name) {
			
			romName = name;
		}

		void GameInfo::setEmulator(string name) {
			
			emulator = name;
		}

		void GameInfo::setImage(string name) {

			image = name;
		}

		void GameInfo::setDescription(string name) {

			description = name;
		}

		string GameInfo::getTitle() {
			
			return title;
		}
		
		string GameInfo::getRom() {
			return romName;
		}

		string GameInfo::getEmulator() {
			return emulator;
		}

		string GameInfo::getImage() {

			return image;
		}

		string GameInfo::getDescription() {
			return description;
		}
		// Constructor
		GameInfo::GameInfo(string nTitle, string nRom, string nEmulator, string nImage, string nDescription) {

			title = nTitle;
			romName = nRom;
			emulator = nEmulator;
			image = nImage;
			description = nDescription;

		}
		
		// Empty Constructor
		GameInfo::GameInfo(){
		}

