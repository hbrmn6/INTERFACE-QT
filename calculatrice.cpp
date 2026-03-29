#include "calculatrice.h"
#include <QLineEdit>
#include <QPushButton>
#include<QGridLayout>
#include <QVBoxLayout>
#include <QKeyEvent>

calculatrice::calculatrice(QWidget *parent)
: QWidget(parent)
{
    modell = new model();


    this->setWindowTitle("TP1_Calculatrice");

   //QLineEdit * champsasais;

    champsasais = new QLineEdit("0");
   champsasais->setReadOnly(true);
   champsasais->setAlignment(Qt::AlignRight);
  // QLineEdit * operatorsais;

   operatorsais = new QLineEdit("");
   operatorsais->setReadOnly(true);
   operatorsais->setAlignment(Qt::AlignRight);
   operatorsais->setFixedWidth(30);
   operatorsais->setMaxLength(15);
   QVBoxLayout * affichagelayout = new QVBoxLayout(this) ;
   affichagelayout->addWidget(champsasais);
   affichagelayout->addWidget(operatorsais,0,Qt::AlignRight);
   QGridLayout *Layout = new QGridLayout();
   QPushButton *digitButtons[10];
   for (int i = 0; i < 10; ++i){
        digitButtons[i]=new QPushButton(QString::number(i));
        connect(digitButtons[i], &QPushButton::clicked, this, &calculatrice::digitClicked);
   }

    QPushButton * point =new QPushButton(".");
    connect(point ,&QPushButton::clicked, this, &calculatrice::dotclicked);
    Layout->addWidget(digitButtons[7],0,0);
    Layout->addWidget(digitButtons[8],0,1);
    Layout->addWidget(digitButtons[9],0,2);
    Layout->addWidget(digitButtons[4],1,0);
    Layout->addWidget(digitButtons[5],1,1);
    Layout->addWidget(digitButtons[6],1,2);
    Layout->addWidget(digitButtons[1],2,0);
    Layout->addWidget(digitButtons[2],2,1);
    Layout->addWidget(digitButtons[3],2,2);

     Layout->addWidget(digitButtons[0],3,0,1,2);
     Layout->addWidget(point,3,2);

     QGridLayout * choisirop = new QGridLayout() ;

     QPushButton * add =new QPushButton("+");
     QPushButton * mult =new QPushButton("-");
     QPushButton * sous =new QPushButton("*");
     QPushButton * div =new QPushButton("/");
     QPushButton * carre =new QPushButton("^2");
     QPushButton * egale =new QPushButton("=");

     connect(add, &QPushButton::clicked, this, &calculatrice::opClicked);
     connect(mult, &QPushButton::clicked, this, &calculatrice::opClicked);
     connect(sous, &QPushButton::clicked, this, &calculatrice::opClicked);
     connect(div, &QPushButton::clicked, this, &calculatrice::opClicked);
     connect(carre, &QPushButton::clicked, this, &calculatrice::opClicked);
     connect(egale, &QPushButton::clicked, this, &calculatrice::equalClicked);

     choisirop->addWidget(add,0,0);
     choisirop->addWidget(sous,0,1);
     choisirop->addWidget(mult,1,1);
     choisirop->addWidget(div,1,0);
     choisirop->addWidget(carre,2,0);
     choisirop->addWidget(egale,2,1);

     QHBoxLayout * horizontal = new QHBoxLayout() ;
     horizontal->addLayout(Layout);
     horizontal->addLayout(choisirop);
      affichagelayout->addLayout(horizontal);



    //  mainLayout->addWidget(display, 0, 0, 1, 6);
  //QGridLayout * layout = new QGridLayout
}







calculatrice::~calculatrice()
{
    delete modell;
}

void calculatrice::digitClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    //sender permet de renvoyer quel objet a emis le signal
    if (clickedButton) {
        QString digit = clickedButton->text(); // on lit le texte du bouton
        modell->ajout(digit);
        // on ecrit le resultat dans le champ
        champsasais->setText(modell->getsaisie()); //met a jr laffichge
    }
}

void calculatrice::equalClicked()
{
    {
        modell->calculer(); // on fait le calcul
        champsasais->setText(modell->getsaisie());
        operatorsais->setText(modell->getoper());
        modell->effacer();// on reinitialise
    }
}

void calculatrice::opClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {
        QString op = clickedButton->text();
        modell->operateur(op);
        champsasais->setText(modell->getsaisie());
        operatorsais->setText(modell->getoper()); // afficher l operateur
    }}

//setText()  →  ÉCRIRE du texte (modifier)
  //  text()     →  LIRE du texte (récupérer)


void calculatrice::dotclicked()
{

    modell->ajout(".");
    champsasais->setText(modell->getsaisie());
}

void calculatrice::keyPressEvent(QKeyEvent *event)
{
    QString key = event->text(); // la touche pressee

                                       // Chiffres 0-9
    if (key >= "0" && key <= "9") {
        modell->ajout(key);
        champsasais->setText(modell->getsaisie());
    }
                                      // Point décimal . ou ,
    else if (key == "." || key == ",") {
        modell->ajout(".");
        champsasais->setText(modell->getsaisie());
    }
                                     // Opérateurs +, -, *, /
    else if (key == "+" || key == "-" || key == "*" || key == "/") {
        modell->operateur(key);
        champsasais->setText(modell->getsaisie());
        operatorsais->setText(modell->getoper());
    }
                                      // Touches Enter/Return pour =
    else if (event->key() == Qt::Key_Return ||event->key() == Qt::Key_Enter ||key == "=") {
        modell->calculer();
        champsasais->setText(modell->getsaisie());
        operatorsais->setText(modell->getoper());
        modell->effacer();
    }
    else if (event->key() == Qt::Key_Escape) { // espace
        modell->effacer();
        champsasais->setText(modell->getsaisie());
        operatorsais->setText(modell->getoper());
    }
    else {
        QWidget::keyPressEvent(event); // par defaut
    }
}
