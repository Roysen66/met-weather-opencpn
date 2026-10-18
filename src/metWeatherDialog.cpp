#include "metWeatherDialog.h"

#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/stattext.h>

metWeatherDialog::metWeatherDialog(wxWindow* parent)
    : wxDialog(parent, wxID_ANY, "MET Weather",
               wxDefaultPosition, wxSize(380, 220),
               wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER)
{
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    mainSizer->Add(
        new wxStaticText(this, wxID_ANY, "MET Weather"),
        0, wxALL | wxALIGN_CENTER_HORIZONTAL, 15);

    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    buttonSizer->Add(
        new wxButton(this, wxID_ANY, "Weather"),
        1, wxALL, 5);

    buttonSizer->Add(
        new wxButton(this, wxID_ANY, "Current"),
        1, wxALL, 5);

    buttonSizer->Add(
        new wxButton(this, wxID_ANY, "Waves"),
        1, wxALL, 5);

    mainSizer->Add(buttonSizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);

    mainSizer->Add(
        new wxStaticText(this, wxID_ANY, "Weather data not connected yet"),
        0, wxALL | wxALIGN_CENTER_HORIZONTAL, 15);

    SetSizer(mainSizer);
    Layout();
}
