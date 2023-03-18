#pragma once

#include <QWidget>
#include "ui_querybk.h"
#include "book.h"

class querybk : public QWidget
{
	Q_OBJECT

public:
	querybk(QWidget* parent = nullptr);
	~querybk();
	bool whether(QStringList str1, QStringList str2);

private slots:
	void TimesRank();
	void ScoreRank();
	void DateRank();
	void DefaltRank();
	void VagueQ();
	void PreciseQ();

private:
	Ui::querybk ui;
};

