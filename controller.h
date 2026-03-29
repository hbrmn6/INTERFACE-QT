#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include "calculatrice.h"
#include "model.h"

class controler:public QObject
  {
 Q_OBJECT

private:
     calculatrice * calc;
     model * mod;
 public :
       controler(calculatrice * calc, model * mod,QObject *parent = nullptr);

private slots:

    void digitClicked(int t );
    void equalClicked();
    void  opClicked();
    void dotclicked();


};
#endif // CONTROLLER_H
