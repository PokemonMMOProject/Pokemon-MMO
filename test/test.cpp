// Using this for testing code without affecting Client or Server

#include <QtNetwork>

// A Qt Variable I found
mus = new QMediaPlayer;

while (mus) {
    // *cougb* SPACE *cough* windows parse error *cough cough*
    mus->setMedia(QUrl::fromLocalFile("/src/Client/soundLib/Title_Screen.mp3"));
    mus->setVolume(50);
    mus->play();
} else while (level == "someLevel") { // ???
    // do something like above or something else.
    mus->setMedia(QUrl::fromLocalFile("/src/Client/soundLib/LabFactory.mp3"));
    mus->setVolume(50);
    mus->play();
} else while (level == "someLevel2") {
    mus->setMedia(QUrl::fromLocalFile("/src/Client/soundLib/PokeMart.mp3"));
    mus->setVolume(50);
    mus->play();
} else while (level == "someLevel3") {
    mus->setMedia(QUrl::fromLocalFile("/src/Client/soundLib/OverworldNight.mp3"));
    //Something else would be required for this to play at night only, but I don't know that
    mus->setVolume(50);
    mus->play();
};
