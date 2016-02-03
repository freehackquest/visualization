#ifndef INPUTTHREAD_H
#define INPUTTHREAD_H
#include <QThread>

class InputThread : public QThread {
	Q_OBJECT
	void run();
};

#endif // INPUTTHREAD_H
