#include "linefieldedit.h"

#include <QLineEdit>
#include <QString>

lineFieldEdit::lineFieldEdit(const QString &name, bool canRemove) :
	genericFieldEdit(name)
{
	m_lineEdit = new QLineEdit();
	connect(m_lineEdit, SIGNAL(textEdited(QString)),
		this, SIGNAL(edited()));
	connect(m_lineEdit, SIGNAL(editingFinished()),
		this, SIGNAL(editingFinished()));
	createWidget(canRemove, m_lineEdit);
}

QString lineFieldEdit::toString() const
{
	return m_lineEdit->text();
}

void lineFieldEdit::fromString(const QString &s)
{
	m_lineEdit->setText(s);
}
