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
              * Premier séparateur
              */
            QAction *_separator1;
            /**
              * Deuxième séparateur
              */
            QAction *_separator2;
            //Boutons des actions possibles
            /**
              * Bouton de construction
              */
            QAction *_build;
            /**
              * Bouton mettant l'entité au travail
              */
            QAction *_work;
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
    };
}
#endif //GUI_CHOOSETOOLBAR_H
