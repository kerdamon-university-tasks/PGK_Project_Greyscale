#include <wx/wx.h>
#include "inc/ControllerFrame.h"
#include "inc/Model.h"

class MyApp : public wxApp {

public:

    virtual bool OnInit();
    virtual int OnExit() { return 0; }

};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    Model model;
	auto mainFrame = new ControllerFrame(nullptr, model);
    mainFrame->Show(true);
    SetTopWindow(mainFrame);

    return true;
}