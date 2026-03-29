#include "calculatrice.h"
#include <QApplication>
int main(int argc, char *argv[])
{
QApplication a(argc, argv);
calculatrice c; // On crée notre Widget
c.show(); // On l ’ affiche
return a.exec(); // On exécute l ’ application
}
