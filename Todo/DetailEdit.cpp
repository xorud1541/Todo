#include "DetailEdit.h"
#include <QDropEvent>
#include <QMimeData>

DetailEdit::DetailEdit(QWidget* parent)
	: QTextEdit(parent)
{
	setAcceptDrops(true);
}


DetailEdit::~DetailEdit()
{
}

void DetailEdit::dropEvent(QDropEvent* e)
{
	const QMimeData* mimeData = e->mimeData();
	if (mimeData->hasUrls())
	{
		QList<QUrl> paths = mimeData->urls();
		QString filePath = paths[0].toLocalFile();
	}
}
