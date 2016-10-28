#include "gameScreen.h"

enum Suit {HEARTS, SPADES, CLUBS, DIAMONDS, UNDEFINED};
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

BEGIN_EVENT_TABLE(wxImagePanel, wxPanel)
// some useful events
/*
 EVT_MOTION(wxImagePanel::mouseMoved)
 EVT_LEFT_DOWN(wxImagePanel::mouseDown)
 EVT_LEFT_UP(wxImagePanel::mouseReleased)
 EVT_RIGHT_DOWN(wxImagePanel::rightClick)
 EVT_LEAVE_WINDOW(wxImagePanel::mouseLeftWindow)
 EVT_KEY_DOWN(wxImagePanel::keyPressed)
 EVT_KEY_UP(wxImagePanel::keyReleased)
 EVT_MOUSEWHEEL(wxImagePanel::mouseWheelMoved)
 */

// catch paint events
EVT_PAINT(wxImagePanel::paintEvent)
// Size event
EVT_SIZE(wxImagePanel::OnSize)
// catch left mouse release
EVT_LEFT_UP(wxImagePanel::mouseReleased)
END_EVENT_TABLE()

// some useful events
/*
 void wxImagePanel::mouseMoved(wxMouseEvent& event) {}
 void wxImagePanel::mouseDown(wxMouseEvent& event) {}
 void wxImagePanel::mouseWheelMoved(wxMouseEvent& event) {}
 void wxImagePanel::mouseReleased(wxMouseEvent& event) {}
 void wxImagePanel::rightClick(wxMouseEvent& event) {}
 void wxImagePanel::mouseLeftWindow(wxMouseEvent& event) {}
 void wxImagePanel::keyPressed(wxKeyEvent& event) {}
 void wxImagePanel::keyReleased(wxKeyEvent& event) {}
 */

wxImagePanel::wxImagePanel(wxPanel* parent, wxString file, wxBitmapType format, Direction dir)
  : wxPanel(parent)
{
  // load the file... ideally add a check to see if loading was successful
  image.LoadFile(file, format);
  
  switch(dir)
  {
    case UP:
        // don't rotate
        break;
    case DOWN:
        image = image.Rotate180();
        break;
    case LEFT:
        // counter clockwise
        image = image.Rotate90(false);
        break;
    case RIGHT:
        // clockwise
        image = image.Rotate90(true);
        break;
    default:
        // don't rotate
        break;
  }
  w = -1;
  h = -1;
}


void wxImagePanel::mouseReleased(wxMouseEvent& evt)
{
    std::cout << "clicked...\n";
}
/*
 * Called by the system of by wxWidgets when the panel needs
 * to be redrawn. You can also trigger this call by
 * calling Refresh()/Update().
 */

void
wxImagePanel::paintEvent(wxPaintEvent& evt)
{
  // depending on your system you may need to look at double-buffered dcs
  wxPaintDC dc(this);
  render(dc);
}

/*
 * Alternatively, you can use a clientDC to paint on the panel
 * at any time. Using this generally does not free you from
 * catching paint events, since it is possible that e.g. the window
 * manager throws away your drawing when the window comes to the
 * background, and expects you will redraw it when the window comes
 * back (by sending a paint event).
 */
void
wxImagePanel::paintNow()
{
  // depending on your system you may need to look at double-buffered dcs
  wxClientDC dc(this);
  render(dc);
}

/*
 * Here we do the actual rendering. I put it in a separate
 * method so that it can work no matter what type of DC
 * (e.g. wxPaintDC or wxClientDC) is used.
 */
void
wxImagePanel::render(wxDC& dc)
{
  int neww, newh;
  dc.GetSize(&neww, &newh);

  if (neww != w || newh != h) {
    resized = wxBitmap(image.Scale(neww, newh /*, wxIMAGE_QUALITY_HIGH*/));
    w = neww;
    h = newh;
    dc.DrawBitmap(resized, 0, 0, true);
  } else {
    dc.DrawBitmap(resized, 0, 0, true);
  }
}

/*
 * Here we call refresh to tell the panel to draw itself again.
 * So when the user resizes the image panel the image should be resized too.
 */
void
wxImagePanel::OnSize(wxSizeEvent& event)
{
  Refresh();
  // skip the event.
  event.Skip();
}


class Card : public wxImagePanel
{
  private:
    Suit suit;
    int rank;

  public:
    Card(wxPanel* parent, Suit suit, int rank, wxString file, wxBitmapType format, Direction dir, int width, int height);

    void mouseReleased(wxMouseEvent& evt);
};

Card::Card(wxPanel* parent, Suit suit, int rank, wxString file, wxBitmapType format, Direction dir, int width, int height)
    : wxImagePanel(parent, file, format, dir)
{
  this->suit = suit;
  this->rank = rank;
  // switches width and height depending on direction
  switch(dir)
  {
    case UP:
    case DOWN:
        this->SetMinSize(wxSize(width, height));
        this->SetMaxSize(wxSize(width, height));
        break;
    case LEFT:
    case RIGHT:
        this->SetMinSize(wxSize(height, width));
        this->SetMaxSize(wxSize(height, width));
        break;
    default:
        break;
  }
}

void Card::mouseReleased(wxMouseEvent& evt)
{
    std::cout << "Suit: ";

    switch(suit)
    {
        case Suit::HEARTS:
            std::cout << "Hearts\n";
            break;
        case Suit::SPADES:
            std::cout << "Spades\n";
            break;
        case Suit::CLUBS:
            std::cout << "Clubs\n";
            break;
        case Suit::DIAMONDS:
            std::cout << "Diamonds\n";
            break;
        case Suit::UNDEFINED:
        default:
            std::cout << "Undefined\n";
            break;
    }

    std::cout << "Rank: ";

    switch(rank)
    {
        case 2:
            std::cout << "2\n";
            break;
        case 3:
            std::cout << "3\n";
            break;
        case 4:
            std::cout << "4\n";
            break;
        case 5:
            std::cout << "5\n";
            break;
        case 6:
            std::cout << "6\n";
            break;
        case 7:
            std::cout << "7\n";
            break;
        case 8:
            std::cout << "8\n";
            break;
        case 9:
            std::cout << "9\n";
            break;
        case 10:
            std::cout << "10\n";
            break;
        case 11:
            std::cout << "Jack\n";
            break;
        case 12:
            std::cout << "Queen\n";
            break;
        case 13:
            std::cout << "King\n";
            break;
        case 14:
            std::cout << "Ace\n";
            break;
        default:
            std::cout << "Undefined\n";
            break;
        
    }
}


// constructor
GameScreen::GameScreen(const wxString& title, const wxPoint& pos,
                       const wxSize& size)
  : wxFrame(NULL, wxID_ANY, title, pos, size, wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
{

  // root panel
  wxPanel* panel = new wxPanel(this, -1);

  // root panel container
  wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

  // card table
  wxImagePanel* table = new wxImagePanel(
    panel, wxT("../resources/pictures/cardtableRect.png"), wxBITMAP_TYPE_PNG, Direction::UP);

  // card table horizontal container
  wxBoxSizer* tableHBox = new wxBoxSizer(wxHORIZONTAL);

  // card table vertical containers
  wxBoxSizer* tableVBoxLeft = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* tableVBoxMid = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* tableVBoxRight = new wxBoxSizer(wxVERTICAL);

  // card table containers for up, decks, and down
  wxBoxSizer* tableHBoxUp = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* tableHBoxDecks = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* tableHBoxDown = new wxBoxSizer(wxHORIZONTAL);
  
  
  // buttons for left side
  std::vector<Card*> leftPlayerHand;
  int s = 10;
  for(int i=0; i<s; i++)
  {
    Card *btn;
    if(i == s-1)
      btn = new Card(
        table, Suit::CLUBS, 2, wxT("../resources/pictures/cards/cardClub2.png"), wxBITMAP_TYPE_PNG, Direction::RIGHT, 60, 80);
    else
      btn = new Card(
        table, Suit::CLUBS, 2, wxT("../resources/pictures/cards/cardClub2Half.png"), wxBITMAP_TYPE_PNG, Direction::RIGHT, 20, 80);
      
    leftPlayerHand.push_back(btn);
  }

  for(int i=0; i<leftPlayerHand.size(); i++)
  {
    tableVBoxLeft->Add(leftPlayerHand[i], 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 10);
  }

  tableVBoxLeft->SetSizeHints(table);

  
  // up
  std::vector<Card*> topPlayerHand;
  s = 10;
  for(int i=0; i<s; i++)
  {
    Card *btn;
    if(i == s-1)
      btn = new Card(
        table, Suit::SPADES, 2, wxT("../resources/pictures/cards/cardSpade2.png"), wxBITMAP_TYPE_PNG, Direction::DOWN, 60, 80);
    else
      btn = new Card(
        table, Suit::SPADES, 2, wxT("../resources/pictures/cards/cardSpade2Half.png"), wxBITMAP_TYPE_PNG, Direction::DOWN, 20, 80);
      
    topPlayerHand.push_back(btn);
  }

  for(int i=0; i<topPlayerHand.size(); i++)
  {
    tableHBoxUp->Add(topPlayerHand[i], 1, wxEXPAND, 0);
  }
  

  tableHBoxUp->SetSizeHints(table);

  // decks
  
  Card *button9 = new Card(
    table, Suit::HEARTS, 2, wxT("../resources/pictures/cards/cardHeart2.png"), wxBITMAP_TYPE_PNG, Direction::UP, 60, 80);
  
  Connect(wxEVT_COMMAND_BUTTON_CLICKED,
         wxCommandEventHandler(GameScreen::OnExit));
  
  Card *button10 = new Card(
    table, Suit::HEARTS, 14, wxT("../resources/pictures/cards/cardHeartA.png"), wxBITMAP_TYPE_PNG, Direction::UP, 60, 80);
  Connect(wxEVT_LEFT_UP,
         wxMouseEventHandler(Card::mouseReleased));

  tableHBoxDecks->Add(button9, 1, wxALL|wxEXPAND, 50);
  tableHBoxDecks->Add(button10, 1, wxALL|wxEXPAND, 50);
  
  tableHBoxDecks->SetSizeHints(table);
  
  // down
  std::vector<Card*> bottomPlayerHand;
  s = 10;
  for(int i=0; i<s; i++)
  {
    Card *btn;
    if(i == s-1)
      btn = new Card(
        table, Suit::DIAMONDS, 2, wxT("../resources/pictures/cards/cardDiamond2.png"), wxBITMAP_TYPE_PNG, Direction::UP, 60, 80);
    else
      btn = new Card(
        table, Suit::DIAMONDS, 2, wxT("../resources/pictures/cards/cardDiamond2Half.png"), wxBITMAP_TYPE_PNG, Direction::UP, 20, 80);
    
    bottomPlayerHand.push_back(btn);
  }

  for(int i=0; i<bottomPlayerHand.size(); i++)
  {
    tableHBoxDown->Add(bottomPlayerHand[i], 1, wxEXPAND, 0);
  }
  
  tableHBoxDown->SetSizeHints(table);

  tableVBoxMid->Add(tableHBoxUp, 1, wxEXPAND|wxALL, 5);
  tableVBoxMid->Add(tableHBoxDecks, 2, wxEXPAND|wxALL, 5);
  tableVBoxMid->Add(tableHBoxDown, 1, wxEXPAND|wxALL, 5);

  tableVBoxMid->SetSizeHints(table);

  
  // buttons for right side
  std::vector<Card*> rightPlayerHand;
  s = 10;
  for(int i=0; i<s; i++)
  {
    Card *btn;
    if(i == s-1)
      btn = new Card(table, Suit::SPADES, 5, wxT("../resources/pictures/cards/cardSpade5.png"), wxBITMAP_TYPE_PNG, Direction::LEFT, 60, 80);
    else
      btn = new Card(table, Suit::HEARTS, 7, wxT("../resources/pictures/cards/cardHeart7Half.png"), wxBITMAP_TYPE_PNG, Direction::LEFT, 20, 80);
      
    rightPlayerHand.push_back(btn);
  }

  for(int i=0; i<rightPlayerHand.size(); i++)
  {
    tableVBoxRight->Add(rightPlayerHand[i], 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 10);
  }

  tableVBoxRight->SetSizeHints(table);

  tableHBox->Add(tableVBoxLeft, 1, wxEXPAND|wxALL, 0);
  tableHBox->Add(tableVBoxMid, 2, wxEXPAND|wxALL, 0);
  tableHBox->Add(tableVBoxRight, 1, wxEXPAND|wxALL, 0);

  tableHBox->SetSizeHints(table);

  table->SetSizer(tableHBox);

  hbox->Add(table, 1, wxALL | wxEXPAND, 50);
  hbox->SetSizeHints(panel);
  panel->SetSizer(hbox);
  
  Centre();
}

void
GameScreen::OnExit(wxMouseEvent& event)
{
  // true forces quit
  std::cout << "clicked exit\n";
  Close(true);
}

void
GameScreen::OnExit(wxCommandEvent& event)
{
  // true forces quit
  Close(true);
}

void
GameScreen::OnAbout(wxCommandEvent& event)
{
  // pop up window
  // body text, title, icons
  wxMessageBox("This is a wxWidgets' Hello world sample", "About Hello World",
               wxOK | wxICON_INFORMATION);
}

void
GameScreen::OnHello(wxCommandEvent& event)
{
  // pop up window with message
  wxLogMessage("Hello world from wxWidgets!");
}

// maps unique identifiers to event handlers
wxBEGIN_EVENT_TABLE(GameScreen, wxFrame) EVT_MENU(ID_Hello, GameScreen::OnHello)
  EVT_MENU(wxID_EXIT, GameScreen::OnExit)
    EVT_MENU(wxID_ABOUT, GameScreen::OnAbout) wxEND_EVENT_TABLE()
