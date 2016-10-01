#include "client.h"
#include "mainwindow.h"
#include "logmanager.h"

#ifdef QT5
#include <QCompleter>
#include <QCheckBox>
#include <QDialogButtonBox>
#include <QFileDialog>
#include <QSlider>
#include <QSplitter>
#endif

Client::Client(ClientManager *p, const QString &server, const quint16 port) : server(server), port(port), myrelay(new Analyzer()), clientManager(p)
{
    // God damn.
    logoutWarn = globals.value("Client/LogoutWarn").toBool(); // If true give logout warning if false do nothing.
    onNameSpoken = !globals.contains("Client/NameSpoken") ? true : globals.value("Client/NameSpoken").toBool();
    top = NULL;
    isConnected = true;
    loggedIn = false;
    pID = -1; // Default auth level.
    
    // Ok im too tired will continue tommorow please don't edit - Rainy Thunder
