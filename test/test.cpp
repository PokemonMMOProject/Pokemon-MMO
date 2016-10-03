// Using this for testing code without affecting Client or Server

#include <QtNetwork>

// A Qt Variable I found
mus = new QMediaPlayer;

while (mus) {
    // *cougb* SPACE *cough* windows parse error *cough cough*
    mus->setMedia(QUrl::fromLocalFile("/src/Client/soundLib/Title_Screen.mp3")); // remove space or the following will happen (read below)
    mus->setVolume(50);
    mus->play();
} else while (level == "someLevel") { // ???
    // do something like above or something else.
    mus->setMedia(QUrl::fromLocalFile("/src/Client/soundLib/LabFactory.mp3"));
    mus->setVolume(50);
    mus->play();
};

// Windows cant do:
// file name
// Instead it does
// "file name"
// when I do this with cpp to stop errors
mus->setMedia(QUrl::fromLocalFile("/src/Client/SoundLib/"Title Screen.mp3"")); // it breaks " "
// pls fix 
