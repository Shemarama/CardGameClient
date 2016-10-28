#ifndef IMAGE_PANEL_H
#define IMAGE_PANEL_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

enum Direction {UP, DOWN, LEFT, RIGHT};

// the wxImagePanel class is taken from
// https://wiki.wxwidgets.org/An_image_panel
class wxImagePanel : public wxPanel
{
  wxImage image;
  wxBitmap resized;
  int w, h;

public:
  wxImagePanel(wxPanel* parent, wxString file, wxBitmapType format, Direction dir);

  virtual void mouseReleased(wxMouseEvent& evt);
  void paintEvent(wxPaintEvent& evt);
  void paintNow();
  void OnSize(wxSizeEvent& event);
  void render(wxDC& dc);

  // some useful events
  /*
   void mouseMoved(wxMouseEvent& event);
   void mouseDown(wxMouseEvent& event);
   void mouseWheelMoved(wxMouseEvent& event);
   void mouseReleased(wxMouseEvent& event);
   void rightClick(wxMouseEvent& event);
   void mouseLeftWindow(wxMouseEvent& event);
   void keyPressed(wxKeyEvent& event);
   void keyReleased(wxKeyEvent& event);
   */

  DECLARE_EVENT_TABLE()
};


#endif
