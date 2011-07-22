#ifndef GUI_WAITINGWINDOW_H
#define GUI_WAITINGWINDOW_H
#include <QtGui/QWidget>
namespace GUI
{
    /**
      * Fenêtre affichée avant qu'une partie aie commencé.
      * Permet aux joueurs de discuter entre eux.
      * @brief Fenêtre affichée avant qu'une partie aie commencé
      * @author Sam101
      */
    class WaitingWindow : public QWidget
    {
        Q_OBJECT
    };
}
#endif //GUI_WAITINGWINDOW_H
