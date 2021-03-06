/***************************************************************************
 *   copyright       : (C) 2003-2009 by Pascal Brachet                     *
 *   http://www.xm1math.net/texmaker/                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef TEXMAKERAPP_H
#define TEXMAKERAPP_H

#include "singleapp/qtsingleapplication.h"
#include <QTranslator>
#include "texmaker.h"

class TexmakerApp : public QtSingleApplication {
public:
    TexmakerApp(const QString &id, int & argc, char ** argv );
    ~TexmakerApp();
    Texmaker *mw;
    void init( QStringList args );  // This function does all the initialization instead of the constructor.
    void makeTranslation(const QString &lang);
    QList<QTranslator*> translatorsList;
    static TexmakerApp *instance();
    void ReadSettings();
    void SaveSettings();
    QString language;
private:
    static TexmakerApp *theAppInstance;
#if defined( Q_WS_MACX )
    QString MacFile;
protected:
    bool event(QEvent *event);
#endif

};
inline TexmakerApp *TexmakerApp::instance() {
    return theAppInstance;
}
#endif
