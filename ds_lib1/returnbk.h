#pragma once

#include <QWidget>
#include "ui_returnbk.h"

class returnbk : public QWidget
{
	Q_OBJECT

public:
	returnbk(QWidget *parent = nullptr);
	~returnbk();

private slots:
	void ReturnBook();

private:
	Ui::returnbkClass ui;
};
