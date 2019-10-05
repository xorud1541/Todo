#include "DetailEdit.h"
#include "FileManager.h"

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
		QString storageName = startTime_;
		FileManager fileMgr;
		if (!fileMgr.CopyFileToStorage(filePath, storageName));
		{
			//½ÇÆÐ
		}
	}
}
