#include "crow.h"
#include <iostream>

int main() {

  crow::SimpleApp App;
  CROW_ROUTE(App, "/")
  ([]()
    {

      return "Archive History Server is running!";

    });

  cout << "Starting Archive History Server..." << endl;
  App.port(8080).multithread().run();

  return 0;



}
