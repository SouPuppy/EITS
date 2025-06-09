// eits-repl/main.cpp

#include <logger.h>

using namespace std;
using namespace logger::log;

int main(int argc, char* argv[]) {
  logger::init("log/.eits-repl.log");

  return 0;
}
