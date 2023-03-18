#pragma once

#include <QMainWindow>
#include "ui_borrowbk.h"

class borrowbk : public QMainWindow
{
	Q_OBJECT

public:
	borrowbk(QWidget *parent = nullptr);
	~borrowbk();

private slots:
	void BorrowClicked();

private:
	Ui::borrowbk ui;
};
