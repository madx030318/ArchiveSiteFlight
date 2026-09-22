#include <iostream>
#include "BackendServer.h"
using namespace std; 
ArchiveServer::ArchiveServer() {
  PortNumber = 8000;
  ServerIdentification = "ArchiveDomain.com";
  bIsRunning = false;
  TotalRequests = 0;
  TotalRecords = 0;
}
void ArchiveServer::StartServer() {

  bIsRunning = true;
  cout << "The server's name -> " << ServerIdentification << " on port -> " << PortNumber << endl; 

}

void ArchiveServer::StopServer() {
    IsRunning = false;
    cout << "The server's name -> " << ServerIdentification << " on port -> " << PortNumber << " stopped" << endl; 

}

void ArchiveServer::SearchArchive(const std::string& Query)
{
    if (!bIsRunning)
    {
        cout << "Server is not running." << endl;
        return;
    }

  TotalRequests++;
  cout << "Searching archive for: " << Query << endl;

}


void ArchiveServer::ShowStatistics()
{
    std::cout << "===== ARCHIVE SERVER STATISTICS =====" << std::endl;

    cout << "Server: "
              << ServerName
              << std::endl;

    cout << "Port: "
              << Port
              << std::endl;

    cout << "Requests: "
              << TotalRequests
              << std::endl;

    cout << "Records: "
              << TotalRecords
              << std::endl;
}

bool ArchiveServer::GetServerStatus() const
{
    return bIsRunning;
}

string ArchiveServer::ReadArchiveFile() {

  ifstream file("../backend/cleaned_archive.json");

}
