#ifndef MET_WEATHER_DIALOG_H
#define MET_WEATHER_DIALOG_H

#include <wx/dialog.h>
#include <functional>

class metWeatherDialog : public wxDialog
{
public:
    explicit metWeatherDialog(wxWindow* parent);

    void SetCloseCallback(std::function<void()> callback);

private:
    std::function<void()> m_closeCallback;
    void OnClose(wxCloseEvent& event);
};

#endif
