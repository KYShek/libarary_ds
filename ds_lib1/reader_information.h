#pragma once

#include <QMainWindow>
#include "ui_reader_information.h"

#include "borrowbk.h"
#include "ds_lib1.h"



class reader_information : public QMainWindow
{
	Q_OBJECT

public:
	reader_information(QWidget *parent = nullptr);
	~reader_information();

private slots:
	void BorrowbkButton();
	void ReborrowbkButton();
	void QuitloginButton();
	void TableClicked(int, int);
	void RowSelected(int);

signals:
	void SendCurrentRow(int);

private:
	Ui::reader_information ui;
	int CurrentRow_value;
};
