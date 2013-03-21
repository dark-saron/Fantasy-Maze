#include "Application.h"

#include "Graphic.h"

using namespace std;

//Hauptthread= QApplication = QT
//Nebenthread= CApplikation
int main(int argc, char *argv[])
{
    CApplication app = CApplication();
    
    app.Start();
    int ret = CGraphic::GetInstance().Run();

    while (app.IsAlive()) {}

    return ret;
}
