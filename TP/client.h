#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QVector>

class Client
{
public:
    Client();
    void setNom(QString nom){
        this->nom=nom;
    }
    void setPrenom(QString prenom){
        this->prenom=prenom;
    }
    void setAdresse(QString adresse){
        this->adresse = adresse;
    }
    void setVille(QString ville){
        this->ville = ville;
    }
    void setCP(int cp){
        this->cp = cp;
    }
    void setCommentaire(QString commentaire){
        this->commentaire = commentaire;
    }
    void setTel(int tel){
        this->tel = tel;
    }
    void setDureeRDV(int dureeRDV){
        this->dureeRDV = dureeRDV;
    }
    void setPriorite(int priorite){
        this->priorite = priorite;
    }
    void setRessource(int idRessource){
        this->ressource.append(idRessource);
    }
    QString getNom(){ return nom; }
    QString getPrenom(){ return prenom; }
    QString getAdresse(){ return adresse; }
    QString getVille(){ return ville; }
    int getCP(){ return cp; }
    QString getCommentaire(){ return commentaire; }
    int getTel(){ return tel; }
    int getDureeRDV(){ return dureeRDV; }
    int getPriorite(){ return priorite; }
    QVector <int> * getRessource(){ return &ressource; }

private:
    QString nom;
    QString prenom;
    QString adresse;
    QString ville;
    int cp;
    QString commentaire;
    int tel;
    int dureeRDV;
    int priorite;
    QVector <int> ressource;
};

#endif // CLIENT_H
