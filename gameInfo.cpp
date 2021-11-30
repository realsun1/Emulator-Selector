/***************************************************************************//**
 * @brief Class responsible for storing game information parsed from file into a class
 *
 * This class is responsible for taking game information from a text file, parsing
 * the game title, rom name, emulator that will be used, image for game and brief
 * description of the game. Text file describes games that will be able to be played
 * from the program.
 * This enables the ability to add or remove without the need to compile the program again.
 * This class holds all getters and setters too for easy ability to create game objects to retrieve
 * or store game info.
 * @authors Christopher Judkins
 ******************************************************************************/
#include "gameInfo.h"
#include <iostream>
#include <fstream>
#include <string>

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

