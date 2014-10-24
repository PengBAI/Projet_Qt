#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <QWidget>

namespace Ui {
class Personnel;
}

class Personnel : public QWidget
{
    Q_OBJECT

public:
    explicit Personnel(QWidget *parent = 0);
    ~Personnel();

private:
    Ui::Personnel *ui;
};

#endif // PERSONNEL_H
