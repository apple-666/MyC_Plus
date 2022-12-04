#include <iostream>
#include <unistd.h>
// #
using namespace std;

class Thread
{

public:
  void goTo(/*Thread * this */)
  {
    pthread_create(&apple_thread_id, NULL, appleFunc, this);
  }
  static void *appleFunc(void *arg)
  {
    Thread* t =(Thread*)arg;
    t->appleRun();
    // while (true)
    // {
    //   cout << "get---1" << endl;
    //   usleep(1000 * 500); // 0.5s
    // }
  }
  virtual void appleRun()
  {
  }

private:
  pthread_t apple_thread_id;
};

class MyThread : public Thread
{
public:
  void appleRun(){
   while (true)
    {
      cout << "get---1" << endl;
      usleep(1000 * 500); // 0.5s
    }
  }
};

int main()
{

  MyThread t1;
  MyThread t2;
  t1.goTo();
  t2.goTo();
  getchar(); // Óöµ½»»ÐÐ Í£Ö¹ÊäÈë
  return 0;
}