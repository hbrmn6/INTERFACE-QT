#ifndef MODEL_H
#define MODEL_H
#include <QString>
#include <QChar>
#include <QObject>
class model{
 public:
    model();
    void ajout(QString c);
    void effacer();
    void operateur( QString op);
    void calculer();
    double memoir() const ;
    QString getsaisie() const ;
    QString  getoper() const ;
 private:
    double memoire ;
    QString  oper;
    QString saisie;


};

#endif // MODEL_H
