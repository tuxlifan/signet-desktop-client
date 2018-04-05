#ifndef SIGNETDEVICEMANAGER_H
#define SIGNETDEVICEMANAGER_H

#include "signetapplication.h"
#include "esdb.h"

#include <QObject>
#include <QTimer>
#include <QQmlApplicationEngine>
#include <QSet>
#include <QStringList>

#include "esdb/account/esdbaccountmodule.h"
#include "esdb-gui/esdbmodel.h"
#include "esdb/esdb.h"

class EsdbEntryModel;
class EsdbGroupModel;

class KeyGeneratorThread;

class SignetDeviceManager : public QObject
{
	Q_OBJECT
	enum SignetApplication::device_state m_deviceState;
	int m_signetdevCmdToken;
	QTimer m_connectingTimer;
	QQmlApplicationEngine &m_qmlEngine;
	KeyGeneratorThread *m_keyGeneratorThread;
	void setLoaderSource(QString str);
	QObject *findQMLObject(QString name);
	QList<esdbEntry *> m_entries;
	esdbAccountModule m_acctTypeModule;
	EsdbEntryModel *m_model;
	EsdbGroupModel *m_groupModel;
	QSet<QString> m_groups;
	QStringList m_groupsSorted;
public:
	explicit SignetDeviceManager(QQmlApplicationEngine &engine, QObject *parent = nullptr);

signals:
	void abort();
public slots:
	void connectingTimer();
	void connectionError();
	void enterDeviceState(int);
	void deviceOpened();
	void deviceClosed();
	void signetdevCmdResp(signetdevCmdRespInfo info);
	void signetdevStartupResp(signetdevCmdRespInfo info, signetdev_startup_resp_data resp);
	void signetdevReadBlockResp(signetdevCmdRespInfo info, QByteArray block);
	void signetdevGetProgressResp(signetdevCmdRespInfo info, signetdev_get_progress_resp_data data);
	void signetdevReadAllUIdsResp(signetdevCmdRespInfo info, int id, QByteArray data, QByteArray mask);
private slots:
	void loaded();
	void loginSignal(QString password);
	void keyGenerationFinished();
};

#endif // SIGNETDEVICEMANAGER_H