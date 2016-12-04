#include "myThread.h"

MyThread::MyThread(std::function<void()> workToDo) : wxThread(wxTHREAD_DETACHED)
{
  work = workToDo;
  if(wxTHREAD_NO_ERROR == Create()) {
    Run();
  }
}

void* MyThread::Entry()
{
  // do something here that takes a long time
  // it's a good idea to periodically check TestDestroy()
  if(!TestDestroy()) {
    work();
  }
  //return static_cast<ExitCode>(NULL);
  return 0;
}
