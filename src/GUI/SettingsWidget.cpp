#include <GUI/SettingsWidget.h>
#include <Tools/ClientSettings.h>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
using namespace Tools;
namespace GUI
{
    /**
      * Constructeur
      */
    SettingsWidget::SettingsWidget(QWidget *parent) :
    QDialog(parent)
    {
        //On construit le layout principal
        QVBoxLayout *layout = new QVBoxLayout;
        setLayout(layout);
        //On construit le GroupBox
        QGroupBox *groupBox = new QGroupBox(tr("Options Graphiques"));
        layout->addWidget(groupBox);
        //On ajoute le layout des boutons Annuler/Confirmer
        QHBoxLayout *h = new QHBoxLayout;
        layout->addLayout(h);
        //On construit le bouton annuler
        QPushButton *cancel = new QPushButton(tr("Annuler"));
        connect(cancel,SIGNAL(clicked()),this,SLOT(reject()));
        h->addWidget(cancel);
        //On construit le bouton valider
        QPushButton *confirm = new QPushButton(tr("Valider"));
        connect(confirm,SIGNAL(clicked()),this,SLOT(confirmSelected()));
        h->addWidget(confirm);

        //On construit le CheckBox pour le support OpenGL
        QVBoxLayout *groupBoxLayout = new QVBoxLayout;
        groupBox->setLayout(groupBoxLayout);
        //On ajoute le label indiquant qu'il faut redemarrer
        QLabel *reboot = new QLabel(tr("Veuillez redemarrer le jeu à chaque \n changement de paramètres"));
        groupBoxLayout->addWidget(reboot);
        //On ajoute le bouton OpenGL
        _openGL = new QCheckBox(tr("Support OpenGL"));
        _openGL->setChecked(ClientSettings::getValue("videoMode").toString() == "openGL");
        groupBoxLayout->addWidget(_openGL);
        //On construit la checkBox pour l'antialiasing
        _antiAliasing = new QCheckBox(tr("Antialiasing"));
        _antiAliasing->setChecked(ClientSettings::getValue("Antialiasing").toBool());
        groupBoxLayout->addWidget(_antiAliasing);
    }
    /**
      * Appelé à l'appui sur "Valider".
      * Change les options de configuration
      */
    void SettingsWidget::confirmSelected()
    {
        if (_openGL->checkState())
        {
            ClientSettings::setValue("videoMode","openGL");
        }
        else
        {
            ClientSettings::setValue("videoMode","software");
        }
        ClientSettings::setValue("Antialiasing",_antiAliasing->checkState());
        accept();
    }
}
