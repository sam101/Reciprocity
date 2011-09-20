#ifndef GUI_CHOOSETOOLBAR_H
#define GUI_CHOOSETOOLBAR_H
#include <Map/Building.h>
#include <QtGui/QAction>
#include <QtGui/QPushButton>
#include <QtGui/QToolBar>
namespace GUI
{
    /**
      * Deuxième barre d'outils, change en fonction des actions possibles actuellement
      * @brief Seconde barre d'outils
      * @author Sam101
      */
    class ChooseToolBar : public QToolBar
    {
        Q_OBJECT
        protected:
            /**
              * Bouton de retour
              */
            QAction *_back;
            /**
              * Tableau des séparateurs
              */
            QAction *_separators[6];
            //Boutons des actions possibles
            /**
              * Bouton de déplacement
              */
            QAction *_move;
            /**
              * Bouton de construction
              */
            QAction *_build;
            /**
              * Bouton mettant l'entité au travail
              */
            QAction *_work;
            //Boutons des batiments constructibles
            /**
              * Bouton lançant la construction d'une maison
              */
            QAction *_house;
            /**
              * Bouton lançant la construction d'un champ
              */
            QAction *_field;
            /**
              * Bouton lançant la construction d'une route
              */
            QAction *_road;
            /**
              * Bouton lançant la construction d'un mur
              */
            QAction *_wall;
            /**
              * Bouton lançant la construction d'une tour
              */
            QAction *_tower;
        public:
            /**
              * Constructeur
              */
            ChooseToolBar();
        public slots:
            /**
              * Desactive tout affichage
              */
            void showNothing();
            /**
              * Affiche les boutons d'action
              */
            void showActions();
            /**
              * Affiche les boutons de construction
              */
            void showBuildings();

        protected slots:
            /**
              * Appelé au clic sur le bouton "se déplacer"
              */
            void moveClicked();
            /**
              * Appelé au clic sur le bouton "travailler"
              */
            void workClicked();
            /**
              * Appelé au clic sur le bouton "Maison"
              */
            void houseClicked();
            /**
              * Appelé au clic sur le bouton "Champ"
              */
            void fieldClicked();
            /**
              * Appelé au clic sur le bouton "Route"
              */
            void roadClicked();
            /**
              * Appelé au clic sur le bouton "Mur"
              */
            void wallClicked();
            /**
              * Appelé au clic sur le bouton "Tour"
              */
            void towerClicked();
        signals:
            /**
              * Indique que l'utilisateur souhaite déplacer l'entité
              */
            void moveRequested();
            /**
              * Indique que l'utilisateur a demandé à construire un batiment
              */
            void buildRequested(Map::BuildingType type);
            /**
              * Indique que l'utilisateur à demandé à faire travailler l'entité
              */
            void workRequested();
    };
}
#endif //GUI_CHOOSETOOLBAR_H
