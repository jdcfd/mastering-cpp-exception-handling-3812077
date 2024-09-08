#include <iostream>
#include <stdexcept>
#include <cstdio> // For the FILE handle
#include <memory>
#include <fstream>

class DatabaseConnection
{
private:
    std::unique_ptr<char[]> buffer; // unique_pointer for database connection data
    std::fstream logFile;           // Raw FILE handle for logging

public:
    DatabaseConnection() : buffer(std::make_unique<char[]>(1024)), logFile("dbLog.txt", std::fstream::app)
    {
        std::cout << "Attempting to open database connection." << std::endl;

        // If opening the log file fails, throw an exception
        if (!logFile.good())
        {
            throw std::runtime_error("Failed to open log file");
        }

        logFile << "blabla\n";

        // Simulate another potential issue after opening the file
        throw std::runtime_error("Failed to connect to database");
    }

    ~DatabaseConnection()
    {
        std::cout << "Closing database connection.\n";
    }
};

void simulateDatabaseOperation()
{
    try
    {
        DatabaseConnection dbConn;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

int main()
{
    simulateDatabaseOperation();
    return 0;
}