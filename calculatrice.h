#ifndef CALCULATRICE_H
#define CALCULATRICE_H
#include "model.h"
#include <QLineEdit>
#include <QWidget>
class calculatrice :public QWidget
{
    Q_OBJECT
public:
    calculatrice(QWidget *parent = nullptr);
    ~calculatrice();
protected :
    void keyPressEvent(QKeyEvent *event) override;

private slots:

    void digitClicked();
    void equalClicked();
    void  opClicked();
    void dotclicked();
private :
    model * modell;
    QLineEdit *champsasais;
    QLineEdit *operatorsais;

};
#endif // CALCULATRICE_H
