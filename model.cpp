#include "model.h"
#include<QPushButton>
model::model()
{
 memoire=0.0;
 oper="";
 saisie="0";
}

void model::ajout(QString c)
{
    if (c=="." && saisie.contains('.')){return ;}
    if( saisie=="0" && c!="."){
         saisie=c;
    }else  saisie.append(c);//saisie+=c;

}

void model::effacer()
{
    saisie="0";
    oper="";
    memoire=0.0;
}

void model::operateur(QString op) {
    if (!oper.isEmpty() && saisie != "0" && saisie != "") {
        calculer();
    } else {
        memoire = saisie.toDouble();
    }

    oper = op;

    // Cas ^2
    if (op == "^2") {
        memoire = memoire * memoire;
        saisie = QString::number(memoire);
        oper = "";
        memoire = 0.0;
    } else {
        saisie = "0";
    }
}

void model::calculer()
{
         double value = saisie.toDouble();
        if (oper=="+"){    memoire+=value; }
        else  if (oper=="*"){     memoire*=value  ;}
        else  if (oper=="/"){     if(value!=0){ memoire/=value;} else return ; }
        else if (oper=="-"){    memoire-=value ; }
        // if (oper=="^2"){   memoire= memoire* memoire;  }


         saisie =QString::number(memoire);


}

double model::memoir() const
{
     return memoire;
}

QString model::getsaisie() const
{
 return saisie;
}

QString model::getoper() const
{
 return oper;
}




