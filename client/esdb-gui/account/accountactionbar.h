#ifndef ACCOUNTACTIONBAR_H
#define ACCOUNTACTIONBAR_H

#include "esdbactionbar.h"

class LoggedInWidget;
class QPushButton;
class ButtonWaitDialog;
struct account;
class NewAccount;

#include <QVector>

extern "C" {
#include "signetdev/host/signetdev.h"
}

class AccountActionBar : public EsdbActionBar
{
	Q_OBJECT
	bool m_writeEnabled;
	bool m_typeEnabled;
	NewAccount *m_newAccountDlg;
	void selectEntry(esdbEntry *entry);
	void defaultAction(esdbEntry *entry);
	QPushButton *m_DeleteButton;
	QPushButton *m_openButton;
	QPushButton *m_loginButton;
	QPushButton *m_browseUrlButton;
	QPushButton *m_typeUsernameButton;
	QPushButton *m_typePasswordButton;
	ButtonWaitDialog *m_buttonWaitDialog;
	LoggedInWidget *m_parent;

	bool m_accessUsername;
	bool m_accessPassword;
	bool m_accessPending;

	void accessAccount(account *acct, bool username, bool password);
	void newInstanceUI(int id, const QString &name);
	void typeAccountData(account *acct);
	void copyAccountData(account *acct, bool username, bool password);
	void openAccount(account *acct);

	enum intent {
		COPY_DATA,
		TYPE_DATA,
		OPEN_ACCOUNT,
		NONE
	};
	int m_id;
	int m_signetdevCmdToken;
	enum quickTypeState {
		QUICKTYPE_STATE_INITIAL,
		QUICKTYPE_STATE_BROWSE,
		QUICKTYPE_STATE_LOGIN,
		QUICKTYPE_STATE_USERNAME,
		QUICKTYPE_STATE_PASSWORD
	} m_quickTypeState;

	bool m_quickTypeMode;
signals:
	void background();
	void abort();
public:
	AccountActionBar(LoggedInWidget *parent, bool writeEnabled = true, bool typeEnabled = true);
	void getEntryDone(esdbEntry *entry, int intent);
	void idTaskComplete(int id, int task, int intent);
public slots:
	void retryTypeData();
	void newAccountFinished(int);
	void accountCreated(account *acct);
	void openAccountUI();
	void deleteAccountUI();
	void typeAccountUserUI();
	void typeAccountUserPassUI();
	void typeAccountPassUI();
	void accessAccountUI(bool username, bool password);
	void browseUrlUI();
	void accessAccountFinished(int);
	void openAccountFinished(int);
	void deleteAccountFinished(int);
	void copyUsername();
	void copyPassword();
};

#endif // ACCOUNTACTIONBAR_H
