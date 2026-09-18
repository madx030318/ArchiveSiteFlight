#ifndef ARCHIVE_SERVER_H
#define ARCHIVE_SERVER_H

using namespace std;
#include <string>
#include <vector>

class ArchiveSite_Data {
private:
int PortNumber;
string ServerIndex;

bool IsStatus;

int RequestsNumber;
int OverallRequests;

public:

ArchiveSite_Data();

ArchiveServer();

void StartServer();
void StopServer();

  
void SearchArchive(const string& Query);

  
void ShowStatistics();
bool GetServerStatus() const;

}

#endif
