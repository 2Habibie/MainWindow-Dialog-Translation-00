#pragma once

#include <QMainWindow>
#include <QTranslator>

#include "definitions.h"
#include "dialogpreferences.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void languageChanged(int index);
    void switchTranslator(const QString& filename);
    void changeEvent(QEvent *event);

private slots:
    void on_exitButton_clicked();
    void on_actionPrefereces_triggered();

private:
    Ui::MainWindow *ui;
    QTranslator mTranslator;

    DialogPreferences *P;
};
