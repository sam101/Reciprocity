#ifndef GUI_CHOOSETOOLBAR_H
#define GUI_CHOOSETOOLBAR_H
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
        signals:
    };
}
#endif //GUI_CHOOSETOOLBAR_H
