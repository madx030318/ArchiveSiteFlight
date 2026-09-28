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

void ArchiveServer::SearchArchive(const string& Query)
{
    if (!bIsRunning)
    {
        cout << "Server is not running." << endl;
        return;
    }

  TotalRequests++;

  string Data = ReadArchiveFile();
  if (Data.empty()) 
  {
    cout << "Archive is empty." << endl;
    return;

  }
  cout << "Searching archive for: " << Query << endl;
  cout << "Archive has been loaded successfully" << endl;

}


void ArchiveServer::ShowStatistics()
{
    cout << "===== ARCHIVE SERVER STATISTICS =====" << endl;

    cout << "Server: "
              << ServerName
              << std::endl;

    cout << "Port: " << Port << endl;

    cout << "Requests: " << TotalRequests << endl;

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

  if (!file.is_open())
  {
    cout << "Error : The file could not be found and therefore opened" << endl;
    return "";

  }

  stringstream buffer;

  buffer << file.rdbuf();

  file.close();

  return buffer.str();

}
