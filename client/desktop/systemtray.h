#ifndef SYSTEMTRAY_H
#define SYSTEMTRAY_H

#include <QSystemTrayIcon>

class SystemTray : public QSystemTrayIcon
{
	Q_OBJECT
public:
	SystemTray();
	virtual ~SystemTray();
};

#endif // SYSTEMTRAY_H
