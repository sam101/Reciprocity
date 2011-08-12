#ifndef GUI_ACTIONTOOLBAR_H
#define GUI_ACTIONTOOLBAR_H
#include <QtGui/QToolBar>
namespace GUI
{
    /**
      * DockWidget contenant les actions les plus courantes actuellement réalisables
      * @brief Contient les actions les plus courantes
      * @author Sam101
      */
    class ActionToolBar : public QToolBar
    {
        Q_OBJECT
        public:
            /**
              * Constructeur
              */
            ActionToolBar();
    };
}
#endif //GUI_ACTIONTOOLBAR_H
