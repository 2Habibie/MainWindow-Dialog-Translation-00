#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    P = new DialogPreferences(this);

    connect(ui->comboBoxLanguage, SIGNAL(currentIndexChanged(int)), this, SLOT(languageChanged(int)));
    connect(P, &DialogPreferences::comboBoxLanguageIndexChanged, this, &MainWindow::languageChanged);
    qApp->installTranslator(&mTranslator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }

    QMainWindow::changeEvent(event);
}

void MainWindow::switchTranslator(const QString& filename)
{
    qApp->removeTranslator(&mTranslator);
    if(mTranslator.load(filename))
    {
        qApp->installTranslator(&mTranslator);
    }
}

void MainWindow::languageChanged(int index)
{
    QString langName;

    switch(index)
    {
    case 0: //English
        switchTranslator("://resources/i18n/WidgetTranslationDemo_en_US.qm");
        langName = "English";
        break;
    case 1: //German
        switchTranslator("://resources/i18n/WidgetTranslationDemo_de_DE.qm");
        langName = "German";
        break;
    case 2: //Spanish
        switchTranslator("://resources/i18n/WidgetTranslationDemo_es_ES.qm");
        langName = "Spanish";
        break;
    }

    ui->statusbar->showMessage(tr("Language changed to: %1").arg(langName));
}

void MainWindow::on_exitButton_clicked()
{
    close();
}

void MainWindow::on_actionPrefereces_triggered()
{
    P->show();
}
