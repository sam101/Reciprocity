#ifndef GUI_CHOOSETOOLBAR_H
#define GUI_CHOOSETOOLBAR_H
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

        public:
            /**
              * Constructeur
              */
            ChooseToolBar();
    };
}
#endif //GUI_CHOOSETOOLBAR_H
