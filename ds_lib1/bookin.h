#pragma once

#include <QWidget>
#include "ui_bookin.h"

class bookin : public QWidget
{
	Q_OBJECT

public:
	bookin(QWidget *parent = nullptr);
	~bookin();
private slots:
	void Bookin();

private:
	Ui::bookin ui;
};
