#pragma once

#include <QWidget>
#include "ui_bookout.h"

class bookout : public QWidget
{
	Q_OBJECT

public:
	bookout(QWidget *parent = nullptr);
	~bookout();

private slots:
	void BookOut();

private:
	Ui::bookout ui;
};
