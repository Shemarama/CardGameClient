#ifndef MY_THREAD_H
#define MY_THREAD_H
#include <wx/thread.h>
#include <wx/event.h>
#include <functional>

class MyThread
  : public wxThread
{
public:
  MyThread(std::function<void()> workToDo);
protected:
  std::function<void()> work;
  
  void* Entry();
};
#endif
