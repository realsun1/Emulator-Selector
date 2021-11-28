/***************************************************************************//**
 * @brief Main function
 *
 * Main function responsible for starting the C++ application and window
 * 
 * @param argc Arguement number
 * @param argv Array of arguement characters
 * @authors Nicole Karas
 ******************************************************************************/
#include "mainwindow.h"
#include <QApplication>
 
int main(int argc, char *argv[]) 
{
  QApplication app(argc, argv);
  MainWindow mainWindow;
  mainWindow.showMaximized();
  return app.exec();
}
