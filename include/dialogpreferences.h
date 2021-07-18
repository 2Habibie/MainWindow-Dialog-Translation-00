#pragma once
#include <QDialog>

namespace Ui {
class DialogPreferences;
}

class DialogPreferences : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPreferences(QWidget *parent = nullptr);
    ~DialogPreferences();

signals:
    void comboBoxLanguageIndexChanged(int index);

private slots:
    void on_okButton_clicked();
    void on_comboBoxLanguage_currentIndexChanged(int index);

private:
    Ui::DialogPreferences *ui;
};
