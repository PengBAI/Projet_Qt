#include "mainwindow.h"
#include "logindialog.h"
#include "c_init_bd.h"
#include <QApplication>
#include <QStatusBar>
#include <QDebug>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    /* Créer la base de données */
    C_INIT_BD::Creation_BD();
    LoginDialog ld;
    if(ld.exec()==QDialog::Accepted){
        /* rappel le mainwindow */
        MainWindow w;
        w.statusBar()->showMessage("Vous venez de vous connecter");
        w.show();

        /* STL set */
        set<int>::iterator it;

        int a[]={89,85,74,23,86,95};
        set<int> sa(a,a+6);
        int b[]={0,6,12,18,22};
        set<int> sb(b,b+5);

        sb.insert(sa.begin(),sa.end());
        it=sb.begin();
        while(it!=sb.end()){
            qDebug()<<*it<< "  ";
            it++;
        }

        return app.exec();
    }
    else{
        return 0;
    }
}
