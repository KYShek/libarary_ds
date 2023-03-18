#pragma once

#include <QWidget>
#include "ui_bkstock.h"
#include "bookin.h"
#include "bookout.h"
#include "ds_lib1.h"

class bkstock : public QWidget
{
	Q_OBJECT

public:
	bkstock(QWidget *parent = nullptr);
	~bkstock();

private slots:
	void QueryButton();
	void BkinButton();
	void BkoutButton();
	void QuitloginButton();

private:
	Ui::bkstock ui;
};
