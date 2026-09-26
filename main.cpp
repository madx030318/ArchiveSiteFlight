#include "crow.h"
#include <iostream>

int main() {

  crow::SimpleApp App;
  CROW_ROUTE(App, "/api/archive")
  ([]()
    {

      crow::json::wvalue Response;

        Response["status"] = "success";
        Response["message"] = "Archive data received";

        Response["records"] = crow::json::wvalue::list({
            {
                {"year", 2026},
                {"category", "Flight"},
                {"source", "Flight Dataset"},
                {"departureTime", "08:30"},
                {"arrivalTime", "11:45"}
            },
            {
                {"year", 2026},
                {"category", "Flight"},
                {"source", "Flight Dataset"},
                {"departureTime", "14:20"},
                {"arrivalTime", "17:10"}
            }

    });

  cout << "Starting Archive History Server..." << endl;
  App.port(8080).multithread().run();

  return 0;



}
