#include <GUI/SettingsWidget.h>
#include <Tools/ClientSettings.h>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
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
        h->addWidget(confirm);

        //On construit le CheckBox pour le support OpenGL
        QVBoxLayout *groupBoxLayout = new QVBoxLayout;
        groupBox->setLayout(groupBoxLayout);
        _openGL = new QCheckBox(tr("Support OpenGL"));
        _openGL->setChecked(ClientSettings::getValue("openGL").toBool());
        groupBoxLayout->addWidget(_openGL);
        //On construit la checkBox pour l'antialiasing
        _antiAliasing = new QCheckBox(tr("Antialiasing"));
        groupBoxLayout->addWidget(_antiAliasing);

    }
}
