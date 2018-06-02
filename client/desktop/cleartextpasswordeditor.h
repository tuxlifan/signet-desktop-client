#ifndef CLEARTEXTPASSWORDEDITOR_H
#define CLEARTEXTPASSWORDEDITOR_H

#include <QObject>
#include <QWidget>
#include <QDialog>

class lineFieldEdit;
class QPushButton;
struct cleartext_pass;
class ButtonWaitDialog;
class PasswordEdit;
#include "signetapplication.h"

class cleartextPasswordEditor : public QDialog
{
	Q_OBJECT
	lineFieldEdit *m_nameEdit;
	PasswordEdit *m_passwordEdit;
	QPushButton *m_deleteButton;
	QPushButton *m_saveButton;
	int m_index;
	struct cleartext_pass *m_pass;
	int m_signetdevCmdToken;
	ButtonWaitDialog *m_buttonWaitDialog;
public:
	cleartextPasswordEditor(int index, struct cleartext_pass *p, QWidget *parent = NULL);
private slots:
	void edited();
	void savePressed();
	void deletePressed();
	void buttonWaitFinished(int);
	void signetdevCmdResp(struct signetdevCmdRespInfo info);
};

#endif // CLEARTEXTPASSWORDEDITOR_H