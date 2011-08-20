#ifndef GUI_SETTINGSWIDGET_H
#define GUI_SETTINGSWIDGET_H
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
namespace GUI
{
    /**
      * Fenêtre de gestion des paramètres de jeu
      * @brief Fenêtre de gestion des paramètres de jeu
      * @author Sam101
      */
    class SettingsWidget : public QDialog
    {
        Q_OBJECT
        protected:
            /**
              * CheckBox du support OpenGL
              */
            QCheckBox *_openGL;
            /**
              * CheckBox de l'antialiasing
              */
            QCheckBox *_antiAliasing;
        public:
            /**
              * Constructeur
              */
            SettingsWidget(QWidget *parent = 0);
        public slots:
            /**
              * Appelé à l'appui sur "Valider".
              * Change les options de configuration
              */
            void confirmSelected();

    };
}
#endif //GUI_SETTINGSWIDGET_H
