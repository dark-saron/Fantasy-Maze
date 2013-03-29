#include "src/App/Application.h"

#include "src/Graphics/Graphic.h"

using namespace std;

//Main Thread = QApplication = QT
//by Thread = CApplikation
int main(int argc, char *argv[])
{
    CApplication app = CApplication();
    
    app.Start();
    int ret = CGraphic::GetInstance().Run();

    while (app.IsAlive()) {}

    return ret;
}


/*

Actions... wohin, wie implementieren?
Auf Logikseite "Gelöschte Objekte"... warten bis sie auf Graphicseite entfernt werden?
CCharactereWorld nutzt CDungeon um sich zu registrieren
Einbinden der Config, und ImageNamen



*/