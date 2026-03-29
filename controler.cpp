#include "controller.h"


controler::controler(calculatrice *calculatrice, model *model, QObject *parent):
    QObject(parent),calc(calculatrice),mod(model)
{
      for (int i =0 ; i<10;++i ){
          connect(  &calc->digitButtons[i],  // émetteur du signal
          &QPushButton::clicked, // pointeur vers le signal
            [=]() { digitClicked(i); });

      }

}

void controler::digitClicked()
{

}

void controler::equalClicked()
{

}

void controler::opClicked()
{

}

void controler::dotclicked()
{

}
