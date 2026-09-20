#ifndef ARCHIVE_SERVER_H
#define ARCHIVE_SERVER_H

#include <string>
#include <vector>

using namespace std;
class ArchiveServer
{
private:
int PortNumber;
string ServerIdentification;

bool bIsRunning;
int TotalRequests;
int TotalRecords;

public:

ArchiveServer();
void StartServer();
void StopServer();

void SearchArchive(const std::string& Query);

void ShowStatistics();

bool GetServerStatus() const;
};

#endif
