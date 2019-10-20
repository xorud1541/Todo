#include "DetailEdit.h"
#include "FileManager.h"
#include "DateManager.h"

#include <QDropEvent>
#include <QMimeData>
#include <QMessageBox>
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
	bool isSaved = false;
	if (mimeData->hasUrls())
	{
		QList<QUrl> paths = mimeData->urls();
		for (auto path : paths)
		{
			QString filePath = path.toLocalFile();
			QString storageName = startTime_;
			FileManager fileMgr;
			if (!fileMgr.CopyFileToStorage(filePath, storageName))
			{
				QMessageBox msgBox;
				QString msg = QString("Failed to copy file : %0").arg(filePath);
				msgBox.setText(msg);
				msgBox.setStandardButtons(QMessageBox::Ok);
				msgBox.exec();
			}
			else
				isSaved = true;
		}
	}

	if (isSaved)
		emit sig_savedfile();
}
