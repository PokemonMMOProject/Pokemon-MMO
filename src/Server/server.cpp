#include <QtNetwork> // QT Network variables
#include <ctime> // random number thing which im supposed to understand but needed anyways, oh well
#include <algorithm> // A thing to sacrifice bandwidth for latency (less PING requests)
#include "server.h" // Servers header
#include "player.h" // Player/User handler
#include "serverconfig.h" // Internal configuration
#include "scriptengine.h" // Script engine so we can run javascript along with the server (Now people who can do JS have a job!)
#include "sql.h" // Oh look SQL headers its just so damn fun!
#include "analyze.h" // Stops spammers from self DOS'ing the server (Won't stop DDoS attacks...Just the spammers...)
#include "networkutilities.h" // More helpful stuff im supposed to understand
#include "registrycommunicator.h" // A registry so we can have a server list and such.
#include "pluginmanager.h" // Needed for a few things but gets deleted internally anyways (dont ask...)

Server *Server::serverIns = NULL;

// Port things.
Server::Server(quint16 port) : registry(nullptr), serverPorts(), showLogMessages(true),
    lastDataId(0), playercounter(0),
    numberOfPlayersLoggedIn(0), myengine(nullptr)
{
    serverPorts << port;
}

Server::Server(QList<quint16> ports) : registry(nullptr), serverPorts(), showLogMessages(true),
    lastDataId(0), playercounter(0),
    numberOfPlayersLoggedIn(0), myengine(nullptr)
{
    foreach(quint16 port, ports)
        serverPorts << port;
}

Server::~Server()
{
#ifndef BOOST_SOCKETS
    foreach (QTcpServer* myserver, myservers)
        myserver->deleteLater();
#endif
    // Told you it just gets deleted.
    delete pluginManager;
}

extern bool skipChecksOnStartUp;

// Oh no here it begins
void Server::start(){
    serverIns = this;

#ifndef QT5
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
#endif

#ifndef BOOST_SOCKETS
    for (int i = 0; i < serverPorts.size(); ++i) {
        myservers.append(new QTcpServer());
    }
#else
    for (int i = 0; i < serverPorts.size(); ++i) {
        myservers.append(manager.createServerSocket());
    }
#endif
    srand(time(NULL));
  
#ifdef Q_OS_WIN
    // Do nothing for now unless you want to ban windows from hosting a server (like that will happen anytime soon)
#endif
    }   

    // Make settings.
    QSettings s("config", QSettings::IniFormat);

    auto setDefaultValue = [&s](const char* key, const QVariant &defaultValue) {
        if (!s.contains(key)) {
            s.setValue(key, defaultValue);
        }
    };

    // I need a break I will continue in a few hours - Dont edit.
