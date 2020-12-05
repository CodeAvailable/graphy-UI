#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
// class QComboBox;
// class QLineEdit;
QT_END_NAMESPACE

class Window : public QWidget
{
	// Q_OBJECT

  public:
	Window();
	virtual ~Window() {};
};

#endif
