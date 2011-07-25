#include <Viewer/ViewerWindow.h>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QMessageBox>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtOpenGL/QGLWidget>
#include <QtOpenGL/QGLFormat>
namespace Viewer
{
    /**
      * Constructeur
      */
    ViewerWindow::ViewerWindow()
    {
        setWindowTitle(tr("Reciprocity - Visualiseur de monde"));
        //On crée la vue et on la positionne comme widget principal
        _view = new ViewerView;
        _view->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
        _view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
        setCentralWidget(_view);
        //On ajoute le widget de zoom
        _zoom = new ViewerZoomWidget;
        addToolBar(_zoom);
        //On connecte le signal à la view
        connect(_zoom,SIGNAL(zoomChanged(qreal)),_view,SLOT(setZoom(qreal)));
        //On change la taille de la fenêtre.
        resize(_view->scene()->sceneRect().width() + 32,_view->scene()->sceneRect().height() + 32);
        //On construit le menu
        _buildMenu();
    }
    /**
      * Construit le menu de la fenêtre.
      */
    void ViewerWindow::_buildMenu()
    {
        QMenu *fileMenu = menuBar()->addMenu(tr("Fichier"));
            QAction *newAction = fileMenu->addAction(tr("Nouveau monde"));
            newAction->setShortcut(QKeySequence("Ctrl+N"));
            connect(newAction,SIGNAL(triggered()),_view,SLOT(newWorld()));
            fileMenu->addSeparator();


            QAction *loadAction = fileMenu->addAction(tr("Charger un monde"));
            loadAction->setShortcut(QKeySequence("Ctrl+O"));
            fileMenu->addSeparator();

            QAction *saveAction = fileMenu->addAction(tr("Sauvegarder le monde"));
            saveAction->setShortcut(QKeySequence("Ctrl+S"));
            fileMenu->addSeparator();

            QAction *quitAction = fileMenu->addAction(tr("Quitter"));
            quitAction->setShortcut(QKeySequence("Ctrl+Q"));
            connect(quitAction,SIGNAL(triggered()),qApp,SLOT(quit()));

       QMenu *helpMenu = menuBar()->addMenu(tr("Aide"));
            QAction *aboutAction = helpMenu->addAction(tr("A propos de"));
            connect(aboutAction,SIGNAL(triggered()),this,SLOT(about()));
    }
    /**
      * Affiche la fenêtre "a propos de"
      */
    void ViewerWindow::about()
    {
        QMessageBox::about(this,tr("A propos de"),tr("Visualiseur de monde pour Reciprocity. Par Sam101"));
    }
}
